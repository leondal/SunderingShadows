// charm monster
// still needs to go through some testing.
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
    set_spell_name("charm monster");
    set_spell_level(([ "bard" : 3, "mage" : 1, "ranger" : 2, "psion" : 2, "oracle" : 3 ]));
    set_spell_sphere("enchantment_charm");
    set_discipline("telepath");
    set_mystery("nature");
    set_domains(({"animal", "charm"}));
    set_syntax("cast CLASS charm monster on TARGET");
    set_description("Casting this divine prayer will allow a priest to attempt to charm a mob.  If the mob falls prey to "
"the charm, they will stand in defense of the caster, and follow them around.  Caution should be exercised, for if you "
"take any offensive actions against the charmed monster, the charm will end.   A caster may have only one charmed "
"creature under their sway at one time.");
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

string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^BLUE%^%^Blowing on your twirling hands,"+
        " a howling gale begins to form behind you.");
    tell_room(place,"%^BOLD%^%^BLUE%^Blowing on "+caster->QP+" twirling "+
        "hands, a howling gale begins to form behind "+caster->QCN+"",caster);
    return "display";
}

void spell_effect(int prof)
{
    string *myids;
    if(!present(target,environment(caster)))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.");
        dest_effect();
        return;
    }
    if(caster->query_property("has charmed monster"))
    {
        tell_object(caster,"You already have a charmed monster, you can't have another.");
        dest_effect();
        return;
    }
    if(target->query_property("is charmed"))
    {
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
    if(target->query_property("no death"))
    {
        tell_object(caster,"That one is too strong to charm!");
        dest_effect();
        return;
    }
    if(target->query_property("no charm"))
    {
        tell_object(caster,"That target can't be charmed!");
        dest_effect();
        return;
    }
    if((string)target->query_race() == "undead")
    {
        tell_object(caster,"The undead cannot be charmed.");
        dest_effect();
        return;
    }
    if(!target->is_player())
    {
        // doesn't work on monsters with custom "aggressive" functions defined
        if(!intp(agg=target->query("aggressive")))
        {
            tell_object(caster,"That one can't be charmed!");
            dest_effect();
            return;
        }
    }

    set_modifier();

    if(!do_save(target,modifier))
    //if(!SAVING_D->saving_throw(target,"spell",modifier))
    {
        if(target->is_player())
        {
            tell_object(target,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" seems so charming, "
                "you wonder if "+caster->QS+" will be your friend.");
            tell_object(caster,"%^BOLD%^%^MAGENTA%^"+target->QCN+" gazes off into space, "
                "day dreaming.");
            tell_room(place,"%^BOLD%^%^MAGENTA%^"+target->QCN+" gazes off into space, "
                "day dreaming after "+caster->QCN+" completes "+caster->QP+" spell!",({caster,target}));
            target->set_paralyzed(roll_dice(1,clevel),"%^MAGENTA%^You are dreaming about "
                "all the fun you could have with your new friend.");
        }
        else
        {
     	    tell_object(target,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" smiles a friendly"+
		        " grin to you.  You can't help but feel they are your best friend.");
     	    tell_object(caster,"%^RED%^You give "+target->QCN+" a friendly grin,"+
		        " feeling your charm take hold.");
     	    tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" smiles a friendly grin to "+
		        ""+target->QCN+", who returns the grins.",({ caster, target}) );
            charm(target,caster);
            worked = 1;
            addSpellToCaster();
        }
        return;
    }

 	tell_object(target,"%^RED%^"+caster->QCN+" smiles a friendly grin to you, but"+
	    " something doesn't seem sincere.");
	tell_object(caster,"%^RED%^You give "+target->QCN+" a friendly grin but notice"+
	    " that your charm has no effect!");
	tell_room(place,"%^RED%^"+caster->QCN+" gives a friendly grin to "+
	    ""+target->QCN+", who only returns a cold stare.",({ caster, target}) );
    spell_kill(target, caster);
    return;
}

void charm(object targ,object cast)
{
    int i,duration,min,max;
    object *attacking=({}),room;

    if(!objectp(targ)) return;
    if(!objectp(cast)) return;

    min    = ROUND_LENGTH * 10;
    max    = ROUND_LENGTH * 50;
    room   = environment(cast);

    duration = (clevel * (10 * ROUND_LENGTH)) - ((int)targ->query_stats("wisdom") * 10);
    if(duration < min) { duration = min; }
    if(duration > max) { duration = max; }

    attacking = targ->query_attackers();

    if(targ->is_player() && cast->is_player())
    {
        return;
    }
    else
    {
        tell_object(targ,"%^BOLD%^%^MAGENTA%^"+cast->QCN+" is so charming, "+
		    "you should protect them!");
        tell_object(cast,"%^BOLD%^%^MAGENTA%^"+targ->QCN+" falls under your"+
		    " charm and comes to your defence!");
        tell_room(room,"%^BOLD%^%^MAGENTA%^"+targ->QCN+"  and comes to "+
		    ""+cast->QCN+" defence.",({ cast, targ}) );
        cast->set_property("has charmed monster",1);
        targ->set_property("is charmed",1);
        targ->cease_all_attacks();
        if(sizeof(attacking))
        {
	        for(i=0;i<sizeof(attacking);i++)
            {
			    attacking[i]->remove_attacker(targ);
            }
		}
        targ->set("aggressive",0);
        if((int)targ->query_property("swarm")) targ->remove_property("swarm"); //creatures were going back to aggressive soon as combat started. -N.
        cast->add_protector(targ);
        cast->add_follower(targ);
        tell_object(targ,"%^RED%^You boldly stand in protection of "+cast->QCN+"%^RESET%^");
        tell_object(cast,"%^RED%^"+targ->QCN+" stands boldly in protection of you.%^RESET%^");
        tell_room(room,"%^RED%^"+targ->QCN+" stands boldly in protection of "+cast->QCN+"!%^RESET%^",({ cast, targ}) );
    }
    call_out("still_charmed",duration,targ,cast);
}

void still_charmed(object targ,object cast)
{
    if(do_save(targ,modifier))
    //if(SAVING_D->saving_throw(targ, "spell", modifier))
    {
        end_charmed(targ,cast);
        return;
    }
    call_out("still_charmed",duration,targ,cast);
    return;
}

void end_charmed(object targ,object cast)
{
    if(!objectp(targ)) { dest_effect(); return; }
    tell_object(targ,"%^MAGENTA%^You blink and look around, "+
		"realizing you are no longer charmed.");
    tell_room(environment(targ),"%^MAGENTA%^"+targ->QCN+" blinks and "+
		"looks around strangely.",targ);
    if(!objectp(cast)) { dest_effect(); return; }
    cast->remove_property("has charmed monster");
    if(agg) { targ->set("aggressive",agg); }
    if(member_array(targ,cast->query_followers()) != -1) { cast->remove_follower(targ); }
    cast->remove_protector(targ);

    if(!do_save(targ,4))
    //if(!SAVING_D->saving_throw(targ,"spell",4))
    {
        if(environment(targ) == environment(cast))
        {
            tell_object(targ,"%^RED%^Outraged, you attack "+cast->QCN+"!");
            tell_object(cast,"%^RED%^"+targ->QCN+" attacks you in a fit of rage!");
            tell_room(environment(targ),"%^RED%^"+targ->QCN+" attacks "+
			""+cast->QCN+" in a rage!",({targ,cast}) );
            spell_kill(targ,cast);
        }
    }

    dest_effect();
}

void dest_effect()
{

    if(objectp(target) && target->query_property("is charmed"))
    {
        target->remove_property("is charmed");

    }
    if(objectp(caster) && worked)
    {
        caster->remove_property("has charmed monster");
    }
    if(objectp(caster) &&
       objectp(target))
    {
        caster->remove_follower(target);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
    return;
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
