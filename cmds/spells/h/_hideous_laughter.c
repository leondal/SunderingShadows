// Hideous Laughter
/* Completely re-hashed the spell, to make its duration more reliable and
  avoid the random infinite_length bug that seemed to be caused by relying
  on set_tripped for the duration.
  New function set_length added, and length variable changed to global, to
  keep it constant between different functions.
  All changed noted where they are made.
  Old version saved as _hideous_laughter.lujke

  Lujke September 25 2005
*/
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;


int str, length;
void check(int a,int b);
void set_length();


void create()
{
    ::create();
    set_spell_name("hideous laughter");
    set_spell_level(([ "mage" : 2, "oracle" :2 ]));
    set_mystery("whimsy");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS hideous laughter on TARGET");
    set_description("Hideous Laughter, when cast, will force the target to laugh at anything that comes to mind.  The "
        "victim will fall to the ground cracking up and then, eventually, will barely stand up again.  The victim will still see "
        "humor in many things and will still be slightly weakened due to the laughing, until the spell finally wears off.");
    mental_spell();
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_components(([
      "mage" : ([ "minute tarts" : 5, "feather" : 1, ]),
//      "bard" : ([ "limerick" : 1, "joke", 1 ]),
    ]));
    set_save("will");
}


string query_cast_string() { return caster->QCN+" hurls some mini tarts at "+target->QCN+" while waving a feather around."; }


void spell_effect(int prof)
{
    int roundspassed, intelligence, modifier;
    modifier = 0;
    intelligence = target->query_stats("intelligence");

    if(checkMagicResistance(target))
    {
        sendDisbursedMessage(target);
        dest_effect();
        return;
    }

    if (!spell_kill(target,caster))
    {
        dest_effect();
        return;
    }

    if ((intelligence >= 5) && (intelligence <= 7))   modifier = -4;
    if ((intelligence >= 8) && (intelligence <= 12))  modifier = -3;
    if ((intelligence >= 13) && (intelligence <= 14)) modifier = -2;
    if ((intelligence >= 15) && (intelligence <= 16)) modifier = -1;

    if ((target->query_stats("intelligence") < 4) || (do_save(target,modifier)))
    {
        // Some additional code put in for the result of the target making its save. Now set so that
        // The target will attack if it makes its save. Lujke September 25 1005
        tell_object(target,"%^ORANGE%^You see " + caster->QCN + " capering around and throwing minute tarts"
            " at you, but nothing about it strikes you as funny.");
        tell_object(caster,"%^ORANGE%^You caper around in what should be an amusing manner and throw"
            " minute tarts at " + target->QCN + " but " + target->QS + " doesn't look amused.");
        tell_room(environment(target),"%^ORANGE%^"+caster->QCN+" capers around and throws some minute tarts at "
            +target->QCN + ", who looks distinctly unamused." , ({target, caster}));
        if(!interactive(target))
        {
            target->force_me("emotat " + caster->QCN + " reacts badly to $P attempt at magic and launches "
                +target->QO+ "self at $O!");
            target->force_me("kill " + caster->QCN);
        }
        // End of additional 'target reaction' code
        dest_effect();
    }
    else
    {
        if(mind_immunity_damage(target))
        {
            spell_successful();
            dest_effect();
            return;
        }

        spell_successful();
        set_length();
        target->set_property("spelled", ({TO}) );
        check(0,prof );
    }
    addSpellToCaster();
}


void set_length()
{
    /*new function added by Lujke Septmber 25 2005, to set the duration of the spell, based on a comparison of
    caster level and target intelligence and target level. Should give generally reasonable durations, hopefully*/
    int int_adjust, baselength;
    if (!objectp(target)||!objectp(caster))
    {
        length = 0;
        return;
    }

    switch (clevel)
    {
    case 0..6:
        baselength = clevel/2;
        if (baselength <1 ) { baselength = 1; }
        break;
    case 7..15:
        baselength = clevel/3;
        if (baselength <3 ) { baselength = 3; }
        break;
    default:
        baselength = clevel/4;
        if (baselength <5 ) { baselength = 5; }
    }

    switch(target->query_stats("intelligence"))
    {
    case 0..4:   int_adjust = -3;  break;
    case 5..6:   int_adjust = -2;  break;
    case 7..8:   int_adjust = -1;  break;
    case 9..14:  int_adjust = 0;   break;
    case 15..16: int_adjust = 1;   break;
    case 17:     int_adjust = 2;   break;
    case 18:     int_adjust = 3;   break;
    case 19:     int_adjust = 4;   break;
    default:     int_adjust = 4 + ((int)target->query_stats("intelligence")-19)/2;
    }

    length = random(baselength) + baselength/2;
    switch(length)
    {
    case 0..4: length -= int_adjust/2; break;
    default:   length -= int_adjust;
    }

    if (target->query_level() > clevel) {
        length -= (clevel - (int)target->query_level()) / 4;
    }
    if (length < 1) {
        length = 1;
    }
}


void check(int roundspassed, int prof)
{
    int strength;
    int  num, roundstowait;

    if (!objectp(target))
    {
        dest_effect();
        return;
    }
    roundstowait = length;
    //  if (objectp(caster)){
    //    caster->force_me("say rounds to wait: " + roundstowait);
    //    caster->force_me("say rounds passed: " + roundspassed);
    //  }
    death_check(target);

    if(roundspassed == 0)
    {
        tell_object(target,"%^BOLD%^%^YELLOW%^You collapse into an uncontrollable laughter!");
        tell_room(environment(target),"%^BOLD%^%^YELLOW%^"+target->QCN+" collapses into a seemingly uncontrollable laughter!", target);

        //  The previous tripped setting seemed to be giving unfeasibly long 'tripped' durations for the spell.
        //  I have noticed 'tripped' being a bit uncontrollable in other settings, so I have now made it
        //  so the spell sets a long tripped duration on each 'check', then clears it by using set_tripped(0)
        //  when the target should stand up. This should make the spell much more controllable, but does
        //  have the side effect of clearing any pre-existing 'trip' effects.
        //  Lujke September 25 2005
        //    target->set_tripped(length/3 +1,"You are on the floor rolling in laughter!");

        target->set_tripped(4,"You are on the floor rolling in laughter!");

        if(!target->query_property("laughter"))
        {
            stat_change(target,"strength",-2);
            str = 1;
            target->set_property("laughter",1);
        }
        call_out("check", ROUND_LENGTH, ++roundspassed, prof);
        return;
    }

    target->set_tripped(4,"You are on the floor rolling in laughter!");

    if(roundspassed < roundstowait)
    {
        tell_object(target,"%^ORANGE%^The laughter lessens as you attempt to regain your footing.");
        tell_room(environment(target),"%^ORANGE%^"+target->QCN+" begins to control "+target->QP+" laughter and tries to struggle to "+target->QP+" feet.", target);
        target->set_tripped(4,"You are on the floor rolling in laughter!");
        call_out("check", ROUND_LENGTH, ++roundspassed, prof);
        return;
    }
    else
    {
        tell_object(target,"%^ORANGE%^You manage to stand, yet you still can't resist giggling and snickering.");
        tell_room(environment(target),"%^ORANGE%^"+target->QCN+" manages to stand up.", target);
        target->set_tripped(0); // added this in to make sure the tripped status ends at the right time.
                                // It will mean that any other tripped effects will clear, but I don't have another
                                // good solution without re-doing how tripped works completely. Lujke September 2005

                                // This call out was failing to pass the 'prof' int to check2, so I am replacing it with one that does. in case we
                                // use profs in the future.
                                // I am also changing the formula for how long is left before the victim fully recovers, essentially
                                // so that the person will remain weakened for twice as long as they spent on the floor. Lujke September 2005
                                //    call_out("check2",ROUND_LENGTH, roundstowait-roundspassed);
        call_out("check2",ROUND_LENGTH, (roundstowait*3)-roundspassed, prof);
    }
}


void check2(int roundsleft, int prof)
{
    if (!objectp(target))
    {
        dest_effect();
        return;
    }
    if (!objectp(environment(target)))
    {
        dest_effect();
        return;
    }

    if (--roundsleft > 0)
    {
        switch (random(6))
        {
        case(0):
            tell_object(target,"You giggle.");
            tell_room(environment(target), target->QCN+" giggles.",target);
            break;
        case(1):
            tell_object(target,"You chuckle.");
            tell_room(environment(target), target->QCN+" chuckles.",target);
            break;
        case(2):
            tell_object(target,"You snicker.");
            tell_room(environment(target), target->QCN+" snickers.",target);
            break;
        case(3):
            tell_object(target,"You laugh.");
            tell_room(environment(target), target->QCN+" laughs.",target);
            break;
        // adding the missing cases which might have been causing the random bugs *Styx* 11/17/04
        case 4..5:
            break;
        }
        //   caster->force_me ("say Rounds Left: "+roundsleft);
        call_out("check2",ROUND_LENGTH,roundsleft, prof);
        return;
    }
    dest_effect();
}


void dest_effect()
{

    // not sure the finds are working so trying just removing without the check *Styx* 11/17/04
    //  if(find_call_out("check") != -1)
    remove_call_out("check");
    //  if(find_call_out("check2") != -1)
    remove_call_out("check2");
    if((objectp(target)))
    {
        //      && (member_array(TO,(object *)target->query_property("spelled")!= -1))) {
        //    tell_object(target,"You still exist..");
        if(str) { stat_change(target,"strength",2); }
        target->remove_property_value("spelled", ({TO}) );
        target->remove_property("laughter");
        target->set_tripped(0); // added by Lujke September 25 2005, to let the target get up if
                                // the spell is dispelled

        /*  The tripped setting probably needs removed too in the case of a dispel
        (one of the bug reports showed the tripped message still going after the dispel).
        However, I'm not sure offhand how to best do that and not kill other valid
        tripped settings so I'll just leave this as a reminder for now.  *Styx*
        - from above that *might* to be removed)
        target->set_tripped(length/3 +1,"You are on the floor rolling in laughter!");
        */
        tell_object(target, "%^ORANGE%^You feel much more serious.");
        tell_room(environment(target), "%^ORANGE%^"+target->QCN+" stops smiling.", target);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
