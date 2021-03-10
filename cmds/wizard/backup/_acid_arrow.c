// Acid Arrow

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

int clevel, num, need, roll;
string target_limb;
object caster, target, place;

create()
{
    ::create();
    set_spell_name("acid arrow");
    set_spell_level(3);
    set_spell_type("wizard");
    set_spell_sphere("conjuration");
    set_components(([        
//        "dart" : 1,
//        "rhubarb leaf" : 1,
    ]));
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_immunities( ({ "acid" }) );
}

spell_effect()
{
    caster = CASTER;
    target = TARGET;
    place = PLACE;
    clevel = CLEVEL;
    target_limb = target->return_target_limb();
    need="/daemon/bonus_d.c"->thaco(clevel,"fighter") -
        target->query_ac();
    roll=random(20) + 1;
    if(interactive(caster))
    {
        tell_object(caster,"%^GREEN%^%^BOLD%^You launch a dart "+
            "out of your hand, aiming it at "+target->query_cap_name()+
            "!");
        tell_object(target,"%^GREEN%^%^BOLD%^"+caster->query_cap_name()+
            " launches a dart out of "+caster->query_possessive()+
            " hand, aiming it at you!");
        tell_room(environment(target),"%^GREEN%^%^BOLD%^"+
            caster->query_cap_name()+" launches a dart out of "+
            caster->query_possessive()+" hand, aiming it at "+
            target->query_cap_name()+"!",({ caster,target }) );
        if( !((roll >= need) || (roll == 20)) )
        {
            tell_object(caster,"%^GREEN%^Your dart explodes into an "+
                "acidic arrow and zips past "+target->query_possessive()+
                " "+target_limb+".");
            tell_object(target,"%^GREEN%^"+caster->query_cap_name()+
                "'s dart explodes into an acidic arrow and zips past "+
                "you.");
            tell_room(environment(target),"%^GREEN%^"+
                caster->query_cap_name()+"'s dart explodes into an "+
                "acidic arrow and zips past "+target->query_cap_name()+
                ".",({ caster,target }) );
            destruct(TO);
            return 1;
        }
        tell_object(caster,"%^GREEN%^%^BOLD%^Your dart explodes into an "+
            "acidic arrow and pierces "+target->query_possessive()+" "+
            target_limb+"!");
        tell_object(target,"%^GREEN%^%^BOLD%^"+caster->query_cap_name()+
            "'s dart explodes into an acidic arrow and pierces your "+
            target_limb+"!\n%^RESET%^%^GREEN%^Acid burns through your "+
            "veins.");
        tell_room(environment(target),"%^GREEN%^%^BOLD%^"+
            caster->query_cap_name()+"'s dart explodes into an acidic "+
            "arrow and pierces "+target->query_cap_name()+"'s "+
            target_limb+"!",({ caster,target }) );
        spell_successful();
    }
    else
    {
        tell_object(target,"%^GREEN%^%^BOLD%^A dart flies from "+
            caster->query_short()+", aiming directly at you!");
        tell_room(place,"%^GREEN%^%^BOLD%^A dart flies from "+
            caster->query_short()+", aiming directly at "+
            target->query_cap_name()+"!",({ target }) );
        if( !((roll >= need) || (roll == 20)) )
        {
            tell_object(target,"%^GREEN%^The dart explodes into an "+
                "acidic arrow and zips past you.");
            tell_room(place,"%^GREEN%^The dart explodes into an "+
                "acidic arrow and zips past "+
                target->query_cap_name()+".", ({ target }) );
            destruct(TO);
            return 1;
        }
        tell_object(target,"%^GREEN%^%^BOLD%^The dart explodes into "+
            "an acidic arrow and pierces your "+target_limb+
            "!\n%^RESET%^%^GREEN%^Acid burns through your veins.");
        tell_room(place,"%^GREEN%^%^BOLD%^The dart explodes into "+
            "an acidic arrow and pierces "+target->query_cap_name()+
            "'s "+target_limb+"!",({ target }) );
        spell_successful();
    }
    damage_targ(target, target_limb, (random(7) + 2) );
    num=1 + to_int(clevel / 3);
    call_out("more_acid", ROUND_LENGTH);
}

more_acid()
{
    tell_object(target,"%^GREEN%^Pain floods through your "+
        target_limb+" as the acid continues to burn.");
    damage_targ(target, target_limb, (random(7) + 2) );
    if(!target) destruct(TO);
    if(num-- > 0)
        call_out("more_acid", ROUND_LENGTH);
    else
        dest_effect();
}

dest_effect()
{
    ::dest_effect();
    if(find_call_out("more_acid") != -1)
        remove_call_out("more_acid");
    tell_object(target,"%^CYAN%^The burning of the acid finally "+
        "recedes.");
    destruct(TO);
}

string query_cast_string()
{
    return caster->query_cap_name()+" shouts out "+
        "magical words in a powerful voice while holding a "+
        "dart in "+caster->query_possessive()+" grasp.";
}
