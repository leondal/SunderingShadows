//templated from charm monster. not sure how well tested it has been?
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

int modifier,duration,agg,worked;

void set_modifier();
void charm(object target,object caster);
void still_charmed(object target,object caster);
void end_charmed(object target,object caster);

void create() {
    ::create();
    set_spell_name("enthrall");
    set_spell_level(([ "warlock" : 2 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS enthrall on TARGET");
    set_description("By means of this invocation, the warlock will attempt to assert a degree of mental control over the target. If successful, the target will follow the caster around and try to protect them from harm. If the warlock harms the enthralled creature, their control will be lost. Only one creature may be controlled in this way at a time, and it will not work on other players, although it may confuse them briefly.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_immunities( ({"charm"}) );
    set_save("will");
}

int preSpell() {
    if(caster->query_property("has charmed monster")) {
        tell_object(caster,"You already have a creature under your control, you can't have another");
        dest_effect();
        return 0;
    }
    return 1;
}

string query_cast_string() {
    tell_object(caster,"%^RESET%^%^CYAN%^You reach forward, fingers splayed as you send out tendrils of mental energy.%^RESET%^");
    tell_room(place,"%^RESET%^%^CYAN%^"+caster->QCN+" reaches forward with fingers splayed, "+caster->QP+" expression momentarily intent.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    string *myids;
    if(!present(target,environment(caster))) {
        tell_object(caster,"%^BOLD%^Your target is not in this area.");
        dest_effect();
        return;
    }
    if(caster == target) {
        tell_object(caster,"You shouldn't try to enthrall yourself!");
        dest_effect();
        return;
    }
    if(caster->query_property("has charmed monster")) {
        tell_object(caster,"You already have a creature under your control, you can't have another.");
        dest_effect();
        return;
    }
    if(target->query_property("is charmed")) {
        tell_object(caster,"That target has already been charmed.");
        dest_effect();
        return;
    }
    myids = target->query_id();
    if(member_array("summoned monster",myids) != -1) {
        tell_object(caster,"Someone else already controls that creature!");
        dest_effect();
        return;
    }
    if(target->query_property("no death")) {
        tell_object(caster,"That one is too strong to charm!");
        dest_effect();
        return;
    }
    if(target->query_property("no charm")) {
        tell_object(caster,"That target can't be charmed!");
        dest_effect();
        return;
    }
    if((string)target->query_race() == "undead") {
        tell_object(caster,"The undead cannot be charmed.");
        dest_effect();
        return;
    }
    if(!target->is_player()) { 
        // doesn't work on monsters with custom "aggressive" functions defined
        if(!intp(agg=target->query("aggressive")))  {
            tell_object(caster,"That one can't be charmed!");
            dest_effect();
            return;
        }
    }
    set_modifier();

    if(!do_save(target,modifier)) {
        if(target->is_player()) {
            tell_object(target,"%^RESET%^%^MAGENTA%^"+caster->QCN+" seems so delightful! You start to wonder if "+caster->QS+" will be your friend.%^RESET%^");
            tell_object(caster,"%^RESET%^%^MAGENTA%^Your invocation fails to ensnare "+target->QCN+" entirely, only distracting "+target->QO+" for a moment.%^RESET%^");
            tell_room(place,"%^RESET%^%^MAGENTA%^"+target->QCN+" gazes off into space, clearly distracted.%^RESET%^",({caster,target}));
            target->set_paralyzed(roll_dice(1,clevel),"%^BOLD%^%^WHITE%^You are daydreaming about all the fun you could have with your new friend.%^RESET%^");
            dest_effect();
        }
        else {
     	    tell_object(target,"%^RESET%^%^MAGENTA%^"+caster->QCN+" seems so delightful! You can't help the sudden urge to be near "+caster->QO+"!%^RESET%^");
     	    tell_object(caster,"%^RESET%^%^MAGENTA%^You smile inwardly as you feel your mental hooks sink into "+target->QCN+"'s psyche and take hold.%^RESET%^");
     	    tell_room(place,"%^RESET%^%^MAGENTA%^"+target->QCN+" moves a little closer to "+caster->QCN+", with a sudden look of adoration upon "+target->QP+" face.%^RESET%^",({caster, target}));
          charm(target,caster);
          worked = 1;
          addSpellToCaster();
        }
        return;
    }

    tell_object(target,"%^RED%^You feel "+caster->QCN+"'s gaze upon you, and shake off a sudden fogginess of mind. You realise "+caster->QS+" just tried to charm you!%^RESET%^");
    tell_object(caster,"%^RED%^"+target->QCN+" looks quite suddenly at you, and you realise your invocation has failed utterly!%^RESET%^");
    tell_room(place,"%^RED%^"+target->QCN+" suddenly turns to fix "+caster->QCN+" with a hostile stare.%^RESET%^",({caster, target}));
    spell_kill(target, caster);
}

void charm(object targ,object cast) {
    int i,duration,min,max;
    object *attacking=({}),room;

    if(!objectp(targ)) return;
    if(!objectp(cast)) return;

    if(targ->is_player() && cast->is_player()) return;
    
    min    = ROUND_LENGTH * 10;
    max    = ROUND_LENGTH * 50;
    room   = environment(cast);

    duration = (clevel * (10 * ROUND_LENGTH)) - ((int)targ->query_stats("wisdom") * 10);
    if(duration < min) duration = min;
    if(duration > max) duration = max;

    attacking = targ->query_attackers();

    tell_object(targ,"%^BOLD%^%^CYAN%^You suddenly worry about "+cast->QCN+"'s well-being. You decide to protect them!%^RESET%^");
    tell_object(cast,"%^BOLD%^%^CYAN%^"+targ->QCN+" falls under your sway and comes to your defense!%^RESET%^");
    tell_room(room,"%^BOLD%^%^CYAN%^"+targ->QCN+" comes to "+cast->QCN+"'s defense!%^RESET%^",({ cast, targ}) );		
    cast->set_property("has charmed monster",1);
    targ->set_property("is charmed",1);
    targ->cease_all_attacks();
    if(sizeof(attacking)) {
	  for(i=0;i<sizeof(attacking);i++) {
            attacking[i]->remove_attacker(targ);
        }
    }
    targ->set("aggressive",0);
    if((int)targ->query_property("swarm")) targ->remove_property("swarm"); //creatures were going back to aggressive soon as combat started. -N.
    cast->add_protector(targ);
    cast->add_follower(targ);
    tell_object(targ,"%^RED%^You boldly stand in protection of "+cast->QCN+"%^RESET%^");
    tell_object(cast,"%^RED%^"+targ->QCN+" stands boldly in protection of you.%^RESET%^");
    tell_room(room,"%^RED%^"+targ->QCN+" stands boldly in protection of "+cast->QCN+"!%^RESET%^",({ cast, targ}));
    call_out("still_charmed",duration,targ,cast);
}

void still_charmed(object targ,object cast) {
    if(do_save(targ,modifier)) {
        dest_effect();
        return; 
    }
    call_out("still_charmed",duration,targ,cast);
}

void end_charmed(object targ,object cast) {
    if(objectp(targ)) {
      if(targ->query_property("is charmed")) targ->remove_property("is charmed");
      tell_object(targ,"%^MAGENTA%^You shake your head to clear the fog from it, only realizing now that you have been charmed.%^RESET%^");
      tell_room(environment(targ),"%^MAGENTA%^"+targ->QCN+" shakes "+targ->QP+" head to clear it, looking momentarily confused.%^RESET%^",targ);    
      if(agg) targ->set("aggressive",agg);
    }
    if(objectp(cast)) cast->remove_property("has charmed monster");
    if(objectp(cast) && objectp(targ)) {
      if(member_array(targ,cast->query_followers()) != -1) cast->remove_follower(targ);
      cast->remove_protector(targ);
    
      if(!do_save(targ,4)) {
        if(environment(targ) == environment(cast)) {
            tell_object(targ,"%^RED%^Outraged, you attack "+cast->QCN+"!%^RESET%^");
            tell_object(cast,"%^RED%^"+targ->QCN+" attacks you in a fit of rage!%^RESET%^");
            tell_room(environment(targ),"%^RED%^"+targ->QCN+" attacks "+cast->QCN+" in a rage!%^RESET%^",({targ,cast}) );
            spell_kill(targ,cast);
        }
      }
    }
}

void dest_effect() {
    if(worked) end_charmed(target,caster); 
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}

void set_modifier() {
    switch((int)caster->query_stats("charisma")) {
      case 0..1:   modifier = 5;  break;
      case 2..3:   modifier = 4;  break;
      case 4..5:   modifier = 3;  break;
      case 6..7:   modifier = 2;  break;
      case 8..9:   modifier = 1;  break;
      case 10..11: modifier = 0;  break;
      case 12..13: modifier = -1; break;
      case 14..15: modifier = -2; break;
      case 16..17: modifier = -3; break;
      case 18..19: modifier = -4; break;
      case 20..21: modifier = -5; break;
      case 22..23: modifier = -6; break;
      default: modifier = -7; break;
    }
}
