// Acid Arrow
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

string target_limb, element;
int num;

void create()
{
    ::create();
    set_spell_name("acid arrow");
    set_spell_level(([ "mage" : 2, "cleric" : 2, "magus" : 2 ]));
    set_domains(({"water"}));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS acid arrow on TARGET");
    set_damage_desc("acid, versatile arcanist");
    set_description("When throwing a dart at a victim and casting the acid arrow spell, the dart will turn into an "
        "acidic arrow with the aim and speed as if fired by a fighter of the caster's spell level.  Damage will be inflicted "
        "immediately upon hitting the target, then the acid will seep through the victim's veins, doing more damage per combat "
        "round until the acid wears off or the target is dead. A versatile arcanist can manipulate the base element of this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    set_components(([ "mage" : ([ "dart" : 1, ]), ]));
    set_immunities( ({ "acid"}) );
}


string query_cast_string()
{
    element = (string)caster->query("elementalist");

    switch(element)
    {
    case "cold":        set_immunities( ({ "cold"}) );          break;
    case "electricity": set_immunities( ({ "electricity"}) );   break;
    case "fire":        set_immunities( ({ "fire"}) );          break;
    case "sonic":       set_immunities( ({ "sonic"}) );         break;
    default:            element = "acid";                       break;
    }

    return caster->QCN+" shouts out magical words in a powerful voice while holding a dart in "+caster->QP+" grasp.";
}


void spell_effect(int prof)
{
    string coloring, arrowtype, shortmsg;
    int need, roll;

    if(!objectp(caster) || !objectp(place))
    {
        dest_effect();
        return;
    }

    if(!objectp(target) || !present(target,place))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }

    if(!caster->ok_to_kill(target))
    {
        dest_effect();
        return 1;
    }

    target_limb = target->return_target_limb();
    need = "/daemon/bonus_d.c"->thaco(clevel,"fighter") - ((int)target->query_ac());
    roll = random(20) + 1;

    switch(element)
    {
    case "cold":        coloring = "%^CYAN%^";      arrowtype = "an icy";       shortmsg = "Ice sears";             break;
    case "electricity": coloring = "%^ORANGE%^";    arrowtype = "a charged";    shortmsg = "Static jolts";          break;
    case "fire":        coloring = "%^RED%^";       arrowtype = "a flaming";    shortmsg = "Flame sears";           break;
    case "sonic":       coloring = "%^MAGENTA%^";   arrowtype = "a buzzing";    shortmsg = "Reverberations echo";   break;
    default:            coloring = "%^GREEN%^";     arrowtype = "an acidic";    shortmsg = "Acid burns";            break;
    }

    if (interactive(caster))
    {
        tell_object(caster,"%^BOLD%^"+coloring+"You launch a dart out of your hand, aiming it at "+target->QCN+"!");
        tell_object(target,"%^BOLD%^"+coloring+""+caster->QCN+" launches a dart out of "+caster->QP+" hand, aiming it at you!");
        tell_room(environment(target),"%^BOLD%^"+coloring+""+caster->QCN+" launches a dart out of "+caster->QP+" hand, aiming it at "+target->QCN+"!",({ caster,target}) );

        if ( roll < need && roll != 20 )
        {
            tell_object(caster,""+coloring+"Your dart explodes into "+arrowtype+" arrow and zips past "+target->QP+" "+target_limb+".");
            tell_object(target,""+coloring+""+caster->QCN+"'s dart explodes into "+arrowtype+" arrow and zips past you.");
            tell_room(environment(target),""+coloring+""+caster->QCN+"'s dart explodes into "+arrowtype+" arrow and zips past "+target->QCN+".",({ caster,target}) );
            dest_effect();
            return 1;
        }

        tell_object(caster,"%^BOLD%^"+coloring+"Your dart explodes into "+arrowtype+" arrow and pierces "+target->QP+" "+target_limb+"!");
        tell_object(target,"%^BOLD%^"+coloring+""+caster->QCN+"'s dart explodes into "+arrowtype+" arrow and pierces your "+target_limb+"!\n%^RESET%^"+coloring+shortmsg+" through your veins.");
        tell_room(environment(target),"%^BOLD%^"+coloring+""+caster->QCN+"'s dart explodes into "+arrowtype+" arrow and pierces "+target->QCN+"'s "+target_limb+"!",({ caster,target}) );
        spell_successful();
    }
    else
    {
        tell_object(target,"%^BOLD%^"+coloring+"A dart flies from "+caster->QCN+", aiming directly at you!");
        tell_room(place,"%^BOLD%^"+coloring+"A dart flies from "+caster->QCN+", aiming directly at "+target->QCN+"!",({ target}) );

        if ( roll < need && roll != 20 )
        {
            tell_object(target,""+coloring+"The dart explodes into "+arrowtype+" arrow and zips past you.");
            tell_room(place,""+coloring+"The dart explodes into "+arrowtype+" arrow and zips past "+target->QCN+".", ({ target}) );
            dest_effect();
            return 1;
        }

        tell_object(target,"%^BOLD%^"+coloring+"The dart explodes into "+arrowtype+" arrow and pierces your "+target_limb+"!\n%^RESET%^"+coloring+shortmsg+" through your veins.");
        tell_room(place,"%^BOLD%^"+coloring+"The dart explodes into "+arrowtype+" arrow and pierces "+target->QCN+"'s "+target_limb+"!",({ target}) );
        spell_successful();
    }

    damage_targ(target, target_limb, sdamage, element);
    spell_kill(target,caster);

    if(!objectp(target))
    {
        dest_effect();
    }

    num = (clevel / 3);
    if(num) { call_out("more_acid", ROUND_LENGTH); }
    else { dest_effect(); }
}


void more_acid()
{
    if(!objectp(target))
    {
        dest_effect();
        return;
    }

    death_check(target);

    if(target->query_hp()<0)
    {
        dest_effect();
        return;
    }

    switch(element)
    {
    case "cold":        tell_object(target,"%^CYAN%^Pain floods through your "+target_limb+" as the icy chill continues to burn.");         break;
    case "electricity": tell_object(target,"%^ORANGE%^Pain floods through your "+target_limb+" as the charged dart jolts you again.");      break;
    case "fire":        tell_object(target,"%^RED%^Pain floods through your "+target_limb+" as the searing flame continues to burn.");      break;
    case "sonic":       tell_object(target,"%^MAGENTA%^Pain floods through your "+target_limb+" as the resonations thrum back and forth."); break;
    default:            tell_object(target,"%^GREEN%^Pain floods through your "+target_limb+" as the acid continues to burn.");             break;
    }
    define_base_damage(0);//lazy re-roll
    damage_targ(target, target_limb, sdamage/6,element);

    if (!target && objectp(TO))
    {
        dest_effect();
        return;
    }

    if (num-- > 0) { call_out("more_acid", ROUND_LENGTH); }
    else
    {
        dest_effect();
        return;
    }
    if(target->query_hp()<0)
    {
        dest_effect();
        return;
    }
}


void dest_effect()
{
    if (find_call_out("more_acid") != -1) remove_call_out("more_acid");

    if(objectp(target))
    {
        switch(element)
        {
        case "cold":        tell_object(target,"%^CYAN%^The icy chill finally recedes.");                   break;
        case "electricity": tell_object(target,"%^ORANGE%^The static jolts finally recede.");               break;
        case "fire":        tell_object(target,"%^RED%^The searing pain finally recedes.");                 break;
        case "sonic":       tell_object(target,"%^MAGENTA%^The echo of the resonations finally recedes.");  break;
        default:            tell_object(target,"%^GREEN%^The burning of the acid finally recedes.");        break;
        }
    }

    ::dest_effect();
    if(objectp(TO)) { TO->remove(); }

}
