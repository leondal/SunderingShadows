#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

string element;
void dest_effect();
void paralysis(mixed *arg2);

void create()
{
    ::create();
    set_spell_name("chain lightning");
    set_spell_level(([ "mage" : 6, "oracle" : 6, "magus" : 6 ]));
    set_domains("air");
    set_mystery("heavens");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS chain lightning on TARGET");
    set_damage_desc("electricity or versatile arcanist");
    set_description("Chain lightning causes a great bolt of electrical energy to attack your target.  After the bolt has "
        "attacked your target, the lightning bolt has enough energy to continue jumping around the room, damaging other people "
        "and anything else that happens to be in the room. A versatile arcanist can manipulate the base element of this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    set_components(([ "mage" : ([ "glass rod":1, "bat fur":1,"silver pin":1 ]), ]));
    set_save("reflex");
}


string query_cast_string()
{
    element = (string)caster->query("elementalist");
    switch(element)
    {
    case "acid":
        tell_object(caster,"%^BOLD%^%^GREEN%^You rub the fur onto your glass rod, charging it with power. You then touch a pin with the rod and begin chanting the spell, even as they begin to bubble and shift before your eyes!%^RESET%^");
        tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" rubs a piece of fur across a glass rod, charging it with power. "+capitalize(caster->QS)+" then touches a pin with the rod and begins chanting a spell, even as they begin to bubble and shift before your eyes!%^RESET%^",caster);
        break;
    case "cold":
        tell_object(caster,"%^BOLD%^%^CYAN%^You rub the fur onto your glass rod, charging it with power. You then touch a pin with the rod and begin chanting the spell, even as they begin to crackle with frost before your eyes!%^RESET%^");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" rubs a piece of fur across a glass rod, charging it with power. "+capitalize(caster->QS)+" then touches a pin with the rod and begins chanting a spell, even as they begin to crackle with frost before your eyes!%^RESET%^",caster);
        break;
    case "fire":
        tell_object(caster,"%^BOLD%^%^RED%^You rub the fur onto your glass rod, charging it with power. You then touch a pin with the rod and begin chanting the spell, even as they begin to steam before your eyes!%^RESET%^");
        tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+" rubs a piece of fur across a glass rod, charging it with power. "+capitalize(caster->QS)+" then touches a pin with the rod and begins chanting a spell, even as they begin to steam before your eyes!%^RESET%^",caster);
        break;
    case "sonic":
        tell_object(caster,"%^CYAN%^The clink of a %^BOLD%^%^WHITE%^p%^CYAN%^i%^WHITE%^n drop %^RESET%^%^CYAN%^rings out as you swipe a bit of cloth across a %^WHITE%^g%^BOLD%^l%^RESET%^a%^BOLD%^s%^RESET%^s r%^BOLD%^o%^RESET%^d%^CYAN%^, drawing out a r%^BOLD%^%^GREEN%^es%^CYAN%^onat%^GREEN%^in%^RESET%^%^CYAN%^g %^GREEN%^c%^BOLD%^h%^CYAN%^i%^GREEN%^m%^RESET%^%^GREEN%^e%^CYAN%^...");
        tell_room(place,"%^CYAN%^The clink of a %^BOLD%^%^WHITE%^p%^CYAN%^i%^WHITE%^n drop %^RESET%^%^CYAN%^rings out as "+caster->QCN+" swipes a bit of cloth across a %^WHITE%^g%^BOLD%^l%^RESET%^a%^BOLD%^s%^RESET%^s r%^BOLD%^o%^RESET%^d%^CYAN%^, drawing out a r%^BOLD%^%^GREEN%^es%^CYAN%^onat%^GREEN%^in%^RESET%^%^CYAN%^g %^GREEN%^c%^BOLD%^h%^CYAN%^i%^GREEN%^m%^RESET%^%^GREEN%^e%^CYAN%^...",caster);
        break;
    default:
        element = "electricity";
        tell_object(caster,"%^YELLOW%^You start to rub the fur to your cystal rod, to charge it. You then touch the pin with the rod and begin the spell!");
        tell_room(place,"%^YELLOW%^"+caster->QCN+" rubs a crystal rod with a cloth. "+caster->QS+" then touches it to a silvery pin and begins to chant!",caster);
        break;
    }
    return "display";
}


void spell_effect(int prof)
{
    object *inven, *hits;
    int damage, i,j, number, level, bonus;
    string cname, tname;

    bonus = prof/10-10;

    cname = caster->QCN;
    tname = target->QCN;

    level = clevel;
    number = level;

    if (!present(target,environment(caster)))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }

    number = clevel;

    hits = ({});
    inven = ({});
    // inven = all_inventory(environment(target));
    // time for this spell to work as advertised; living targets only.
    inven = target_selector();
    inven -= ({ target }); // target already gets hit with initial damage!
    inven -= ({ caster }); // caster chooses targets within 30ft, so cannot be hit


    switch(element)
    {
    case "acid":
        tell_object(target,"%^BOLD%^%^GREEN%^A %^BLACK%^hissing %^GREEN%^jet of %^RESET%^%^GREEN%^a%^RED%^c%^GREEN%^id %^BOLD%^%^GREEN%^leaps from the %^RESET%^%^RED%^co%^ORANGE%^r%^RED%^ro%^ORANGE%^d%^RED%^i%^ORANGE%^n%^RED%^g %^BOLD%^%^GREEN%^pin and surges toward you!%^RESET%^");
        tell_room(place,"%^BOLD%^%^GREEN%^A %^BLACK%^hissing %^GREEN%^jet of %^RESET%^%^GREEN%^a%^RED%^c%^GREEN%^id %^BOLD%^%^GREEN%^leaps from the %^RESET%^%^RED%^co%^ORANGE%^r%^RED%^ro%^ORANGE%^d%^RED%^i%^ORANGE%^n%^RED%^g %^BOLD%^%^GREEN%^pin and surges toward "+tname+"!%^RESET%^",target);
        break;
    case "cold":
        tell_object(target,"%^BOLD%^%^CYAN%^A %^BOLD%^%^WHITE%^brittle %^BOLD%^%^CYAN%^bolt of f%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^s%^BOLD%^%^CYAN%^t leaps from the pin and surges toward you!%^RESET%^");
        tell_room(place,"%^BOLD%^%^CYAN%^A %^BOLD%^%^WHITE%^brittle %^BOLD%^%^CYAN%^bolt of f%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^s%^BOLD%^%^CYAN%^t leaps from the pin and surges toward "+tname+"!%^RESET%^",target);
        break;
    case "fire":
        tell_object(target,"%^BOLD%^%^RED%^A %^BOLD%^%^WHITE%^blazing %^BOLD%^%^RED%^bolt of f%^RESET%^%^RED%^l%^BOLD%^%^RED%^a%^RESET%^%^RED%^m%^BOLD%^%^RED%^e leaps from the pin and surges toward you!%^RESET%^");
        tell_room(place,"%^BOLD%^%^RED%^A %^BOLD%^%^WHITE%^blazing %^BOLD%^%^RED%^bolt of f%^RESET%^%^RED%^l%^BOLD%^%^RED%^a%^RESET%^%^RED%^m%^BOLD%^%^RED%^e leaps from the pin and surges toward "+tname+"!%^RESET%^",target);
        break;
    case "sonic":
        tell_object(target,"%^CYAN%^The %^GREEN%^c%^BOLD%^h%^CYAN%^i%^GREEN%^m%^RESET%^%^GREEN%^e %^CYAN%^reaches a %^BOLD%^%^WHITE%^deafening %^RESET%^%^MAGENTA%^c%^RED%^r%^BOLD%^e%^WHITE%^s%^MAGENTA%^c%^WHITE%^e%^RED%^n%^RESET%^%^RED%^d%^MAGENTA%^o%^CYAN%^, jumping from the glass rod and surging toward you!");
        tell_room(place,"%^CYAN%^The %^GREEN%^c%^BOLD%^h%^CYAN%^i%^GREEN%^m%^RESET%^%^GREEN%^e %^CYAN%^reaches a %^BOLD%^%^WHITE%^deafening %^RESET%^%^MAGENTA%^c%^RED%^r%^BOLD%^e%^WHITE%^s%^MAGENTA%^c%^WHITE%^e%^RED%^n%^RESET%^%^RED%^d%^MAGENTA%^o%^CYAN%^, jumping from the glass rod and surging toward "+tname+"!",target);
        break;
    default:
        tell_object(target,"%^YELLOW%^After "+cname+" touches the pin a searing bolt of electricity leaps toward you!");
        tell_room(place,"%^YELLOW%^A searing bolt of electricity leaps from the pin toward "+tname+"!",target);
        break;
    }

    if(do_save(target,0))
    {
        damage_targ(target,target->return_target_limb(),sdamage/2,element);
    }
    else
    {
        damage_targ(target,target->return_target_limb(),sdamage,element);
    }

    spell_kill(target, caster);

    switch(element)
    {
    case "acid":
        tell_room(place,"%^RESET%^%^GREEN%^Having been set free, the %^BOLD%^%^GREEN%^a%^YELLOW%^c%^GREEN%^id %^RESET%^%^GREEN%^chooses its own path!");
        break;
    case "cold":
        tell_room(place,"%^BOLD%^%^CYAN%^The bolt having been freed chooses its own path!");
        break;
    case "fire":
        tell_room(place,"%^BOLD%^%^RED%^The bolt having been freed chooses its own path!");
        break;
    case "sonic":
        tell_room(place,"%^CYAN%^The high-pitched chime %^BOLD%^%^GREEN%^e%^BLACK%^c%^GREEN%^h%^CYAN%^o%^BLACK%^e%^GREEN%^s %^RESET%^%^CYAN%^wildly about the area!");
        break;
    default:
        tell_room(place,"%^BOLD%^%^WHITE%^The bolt having been freed chooses its own path!");
        break;
    }

    while (number > 0 &&  sizeof(inven) != 0)
    {
        number -= 1;
        i = random(sizeof(inven));

        if (!objectp(inven[i]))
        {
            inven -= ({inven[i]});
            continue;
        }

        if(inven[i]->is_invincible())
        {
            inven -= ({inven[i]});
            continue;
        }

        if(!userp(inven[i])) spell_kill(inven[i], caster);

        if(do_save(inven[i],0))
        {
            damage_targ(inven[i],inven[i]->return_target_limb(),sdamage/2,element);
        }
        else
        {
            damage_targ(inven[i],inven[i]->return_target_limb(),sdamage,element);
        }

        switch(element)
        {
        case "acid":
            tell_object(inven[i],"%^BOLD%^%^GREEN%^The bolt leaps toward you, burning you and doing a good deal of damage!");
            tell_room(place,"%^BOLD%^%^GREEN%^The arc of acid streams toward "+inven[i]->QCN+"!",inven[i]);
            break;
        case "cold":
            tell_object(inven[i],"%^BOLD%^%^CYAN%^The bolt leaps toward you, chilling you and doing a good deal of damage!");
            tell_room(place,"%^BOLD%^%^CYAN%^The arc of frost darts toward "+inven[i]->QCN+"!",inven[i]);
            break;
        case "fire":
            tell_object(inven[i],"%^BOLD%^%^RED%^The bolt leaps toward you, burning you and doing a good deal of damage!");
            tell_room(place,"%^BOLD%^%^RED%^The arc of flame surges toward "+inven[i]->QCN+"!",inven[i]);
            break;
        case "sonic":
            tell_object(inven[i],"%^CYAN%^The %^BOLD%^%^WHITE%^c%^GREEN%^h%^WHITE%^i%^GREEN%^m%^WHITE%^e %^RESET%^ec%^BOLD%^%^BLACK%^h%^RESET%^o%^BOLD%^%^BLACK%^es %^RESET%^%^CYAN%^toward you, %^BOLD%^%^WHITE%^s%^RESET%^l%^BOLD%^a%^RESET%^m%^BOLD%^mi%^RESET%^n%^BOLD%^g %^RESET%^%^CYAN%^harshly into you!");
            tell_room(place,"%^CYAN%^The %^BOLD%^%^WHITE%^c%^GREEN%^h%^WHITE%^i%^GREEN%^m%^WHITE%^e %^RESET%^ec%^BOLD%^%^BLACK%^h%^RESET%^o%^BOLD%^%^BLACK%^es %^RESET%^%^CYAN%^toward "+inven[i]->QCN+"!",inven[i]);
            break;
        default:
            tell_object(inven[i],"%^YELLOW%^The bolt leaps toward you, electrifying you and doing a good deal of damage!");
            tell_room(place,"%^BOLD%^%^RED%^The electricity leaps toward "+inven[i]->QCN+"!",inven[i]);
            break;
        }

        if (!objectp(caster))
        {
            dest_effect();
            return;
        }
        inven -= ({ inven[i] }); // each target can only be hit once!
    }

    switch(element)
    {
    case "acid":
        tell_room(place,"%^RESET%^%^GREEN%^The acid finally %^CYAN%^di%^GREEN%^s%^CYAN%^so%^BOLD%^%^BLUE%^l%^RESET%^%^GREEN%^v%^CYAN%^es %^GREEN%^away, the last of its energy spent!");
        break;
    case "cold":
        tell_room(place,"%^RESET%^%^CYAN%^The bolt of frost finally fragments into shards of ice, the last of its energy spent!");
        break;
    case "fire":
        tell_room(place,"%^RESET%^%^RED%^The blazing bolt finally fizzles out, the last of its energy spent!");
        break;
    case "sonic":
        tell_room(place,"%^CYAN%^The chime finally fades away, the last of its energy spent!");
        break;
    default:
        tell_room(place,"%^BOLD%^%^GREEN%^The electricity finally disperses itself, the last of its energy spent!");
        break;
    }

    dest_effect();
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
