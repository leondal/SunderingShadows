#include <spell.h>
#include <daemons.h>
inherit SPELL;

int rnds,total;


void create(){
    ::create();
    set_author("nienne");
    set_spell_name("voice of madness");
    set_spell_level(([ "warlock" : 1 ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS voice of madness on TARGET");
    set_description("This invocation will call upon beings beyond, unfathomable and terrifying, to whisper in the ears "
        "of the target. A weak-willed target will become overwhelmed by the maddening voices, and may babble incoherently, attack "
        "the closest thing to them, or simply wander away.  When used on a player, it simply causes them to stand and stare blankly.");
    mental_spell();
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}


string query_cast_string(){
    tell_object(caster,"%^GREEN%^You whisper the words of the invocation under your breath.%^RESET%^");
    tell_room(place,"%^GREEN%^"+caster->QCN+" whispers under "+caster->QP+" breath.%^RESET%^",caster);
    return "display";
}

spell_effect(int prof){
    int bonus;
    bonus = clevel/6;
    bonus = -1*bonus;
    total = clevel/5;
    if(total < 0) total = 0;
    total += 3;

    tell_object(target,"%^GREEN%^"+caster->QCN+" fixes you with an u%^CYAN%^n%^GREEN%^set%^CYAN%^tl%^GREEN%^ing gaze, and your ears are suddenly filled with whispers and unearthly snarls!%^RESET%^");
    tell_object(caster,"%^GREEN%^Fixing "+target->QCN+" with an i%^CYAN%^n%^GREEN%^t%^CYAN%^en%^GREEN%^t gaze, you give voice to whispers and unearthly snarls that only "+target->QS+" can hear!%^RESET%^");
    tell_room(place,"%^GREEN%^"+caster->QCN+" fixes "+target->QCN+" with an u%^CYAN%^n%^GREEN%^set%^CYAN%^tl%^GREEN%^ing gaze.%^RESET%^",({caster,target}));

    if(do_save(target,bonus)) {
        tell_object(caster,"%^BOLD%^%^GREEN%^"+target->QCN+" is able to resist the supernatural voices!%^RESET%^");
        tell_object(target,"%^BOLD%^%^GREEN%^With an effort, you shake off the supernatural voices and resist "+caster->QCN+"'s invocation!%^RESET%^");
        tell_room(place,"%^BOLD%^%^GREEN%^"+target->QCN+" struggles momentarily, as if suffering from some mental struggle.%^RESET%^",({caster,target}));
        if(!target->is_player()) spell_kill(target, caster);
        TO->dest_effect();
        return;
    }
    else{

        if(mind_immunity_damage(target, "default"))
        {
            spell_successful();
            dest_effect();
            return;
        }

        if(target->is_player()){
            tell_object(target,"%^BOLD%^%^CYAN%^Your mind becomes overwhelmed with jumbled thoughts and images, and you stand confused!%^RESET%^");
            tell_object(caster,"%^BOLD%^%^CYAN%^"+target->QCN+" is overcome with confusion, and stands staring into space!%^RESET%^");
            tell_room(place,"%^BOLD%^%^CYAN%^"+target->QCN+" suddenly stares off into space!%^RESET%^",({target,caster}));
            target->set_paralyzed(roll_dice(1,clevel),"You are too confused to do anything!");
            dest_effect();
            return;
        }
        else{
            tell_object(caster,"%^BOLD%^%^CYAN%^"+target->QCN+"'s mind is muddled by the power of your invocation!");
            tell_room(place,"%^BOLD%^%^CYAN%^"+target->QCN+" gets a strange look on "+target->QP+" face!",({caster,target}));
            rnds = 0;
            target->set_property("spelled", ({TO}) );
            call_out("confuse_em",3,target);
            spell_kill(target, caster);
            spell_successful();
        }
    }
}

void confuse_em(object mytarg){
    int i;
    object *targs;
    object chosen;
    if(!objectp(mytarg)){
        TO->dest_effect();
        return;
    }
    if(!objectp(caster) || !present(caster,environment(mytarg))){
        TO->dest_effect();
        return;
    }

    if(rnds < total){
        switch(random(100)){
        case 0..10:   if(!present(caster,environment(mytarg))) TO->dest_effect();
                      mytarg->force_me("kill "+caster->query_name()+"");
                      tell_object(mytarg,"%^BOLD%^%^RED%^Outraged, "+
                          "you attack "+caster->QCN+"!");
                      tell_object(caster,"%^BOLD%^%^RED%^Outraged, "+
                          ""+mytarg->QCN+" attacks you!");
                      tell_room(environment(mytarg),"%^BOLD%^"+mytarg->QCN+" "+
                          "attacks "+caster->QCN+" in a violent rage!",({mytarg,caster}));
                      break;
        case 11..20:  break;
        case 21..50:  if(!present(caster,environment(mytarg))) TO->dest_effect();
                      tell_object(mytarg,"%^YELLOW%^A strange thought "+
                          "enters your mind, but you cannot grasp it!");
                      tell_room(environment(mytarg),"%^YELLOW%^"+
                          ""+mytarg->QCN+" stares at a point in space, "+
                          "babbling incoherently!",mytarg);
                      mytarg->set_paralyzed(roll_dice(3,6),"You are trying to recall that thought!"); //was just 4
                      break;
        case 51..70:  if(!present(caster,environment(mytarg))) TO->dest_effect();
                      tell_object(mytarg,"%^BOLD%^%^CYAN%^A sudden, "+
                          "overwhelming sense of drowsiness comes "+
                          "over you, and you fall asleep!%^RESET%^");
                      tell_room(environment(mytarg),"%^BOLD%^%^CYAN%^"+
                           ""+mytarg->QCN+" suddenly falls asleep on "+
                           ""+mytarg->QP+" feet!%^RESET%^",mytarg);
                      mytarg->set_asleep((clevel/4), "You are asleep!");
                      break;
        default:      if(!present(caster,environment(mytarg))) TO->dest_effect();
                      targs = all_living(environment(mytarg));
                      filter_array(targs, "is_non_immortal", FILTERS_D);
                      targs -= ({mytarg});
                      i = random(sizeof(targs));
                      chosen = targs[i];
                      tell_object(mytarg,"%^BOLD%^%^RED%^In a blind "+
                          "rage, you attack the thing closest to you!");
                      tell_object(chosen,"%^BOLD%^%^RED%^"+mytarg->QCN+" "+
                          "suddenly turns and swings wildly at you!");
                      tell_room(environment(mytarg),"%^BOLD%^%^RED%^"+
                          ""+mytarg->QCN+" suddenly turns and swings wildly, "+
                          "attacking "+chosen->QCN+"!",({mytarg, chosen}));
                      mytarg->force_me("kill "+chosen->query_name()+"");
                      break;
        }
        rnds++;
        call_out("confuse_em",5,mytarg);
        return;
    }
    TO->dest_effect();
}

void dest_effect(){
    if(objectp(target)){
        if(target->is_player()){
            ::dest_effect();
            if(objectp(TO)) TO->remove();
            return;
        }
    }
    if(find_call_out("confuse_em")) remove_call_out("confuse_em");
    //added the below check for objectp after environment bugs when the
    //target had died.  Circe 9/19/05
    if(objectp(target)){
        tell_object(target,"%^CYAN%^Suddenly, your mind clears and you feel in control again!");
        tell_room(environment(target),"%^CYAN%^"+target->QCN+"'s eyes suddenly look much more focused.",target);
    }
    ::dest_effect();
    if(objectp(TO)) { TO->remove(); }

}
