#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

string YOU, HIM, element;


void create()
{
    ::create();
    set_spell_name("cone of cold");
    set_spell_level(([ "mage" : 5, "monk" : 15, "oracle" : 5, "magus" : 5, "cleric" : 5, "druid" : 5]));
    set_mystery("winter");
    set_spell_sphere("invocation_evocation");
    set_monk_way("way of the elements");
    set_domains("water");
    set_syntax("cast CLASS cone of cold on TARGET");
    set_damage_desc("delayed cold");
    set_description("By casting this spell, you form a massive white cone of icy cold towards your target.  Not only does "
        "this spell increase damagewise as the caster increases in level, but also, the chance of hitting an unintended target in "
        "addition to the intentional one increases too.  The mage will try to aim the spell at only hostile targets, but this is "
        "not always possible.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    set_components(([ "mage" : ([ "crystal" : 1, ]), ]));
    set_save("reflex");
}


string query_cast_string()
{
    if(spell_type == "monk")
    {
        return "%^BLUE%^"+caster->QCN+" exhales deeply!";
    }
    return "%^BLUE%^"+caster->QCN+" mutters some words while raising a crystal, cupping it gently in "+caster->QP+" hands.";
}


void spell_effect(int prof)
{
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    YOU = caster->QCN;
    HIM = target->QCN;

    element = (string)caster->query("elementalist");

    if(interactive(caster))
    {
        switch(element)
        {
        case "acid":
            tell_object(caster, "%^GREEN%^The crystal pulses with a short-lived, s%^YELLOW%^i%^RESET%^%^ORANGE%^c%^GREEN%^kly green light that slightly burns your hands.%^RESET%^");
            tell_room(place, "%^GREEN%^"+YOU+"'s hands tremble violently as "+caster->QS+" grasps the crystal.", ({caster}) );
            break;
        case "electricity":
            tell_object(caster, "%^ORANGE%^The crystal develops a static charge, making your hands tremble.%^RESET%^");
            tell_room(place, "%^ORANGE%^"+YOU+"'s hands tremble violently as "+caster->QS+" grasps the crystal.", ({caster}) );
            break;
        case "fire":
            tell_object(caster, "%^RED%^The crystal takes on a sudden heat, making your hands tremble.%^RESET%^");
            tell_room(place, "%^RED%^"+YOU+"'s hands tremble violently as "+caster->QS+" grasps the crystal.", ({caster}) );
            break;
        case "sonic":
            tell_object(caster, "%^CYAN%^A powerful, low-pitched %^BOLD%^%^BLACK%^d%^RESET%^r%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^i%^RESET%^n%^BOLD%^%^BLACK%^g %^RESET%^%^CYAN%^emanates from the crystal, making your hands tremble.%^RESET%^");
            tell_room(place, "%^CYAN%^"+YOU+"'s hands tremble violently as "+caster->QS+" grasps the crystal.", ({caster}) );
            break;
        default:
            element = "cold";
            if(spell_type == "monk")
            {
                tell_object(caster, "%^CYAN%^Your body shivers violently as you exhale the arctic air!%^RESET%^");
                tell_room(place, "%^CYAN%^"+YOU+"'s body trembles violently as "+caster->QS+" exhales the arctic air!%^RESET%^", ({caster}));
            }
            else
            {
                tell_object(caster, "%^CYAN%^Slowly your crystal chills to an icy cold, making your hands tremble.%^RESET%^");
                tell_room(place, "%^CYAN%^"+YOU+"'s hands tremble violently as "+caster->QS+" grasps the crystal.", ({caster}) );
            }
            break;
        }
        call_out("zapper",4);
    }
    else zapper();
}


void zapper()
{
    string before, after, size;
    object *inven, *hits = ({});
    int i;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if(!objectp(target) || !objectp(place) || !present(target, place))
    {
        if(spell_type == "monk")
        {
            tell_object(caster, "%^BLUE%^The arctic air turns to a harmless steam!");
            tell_room(place, "%^BLUE%^"+YOU+"'s arctic air turns into a harmless steam!", caster);
            dest_effect();
            return;
        }
        tell_object(caster, "%^BLUE%^Your crystal sublimes into steam.");
        tell_room(place, "%^BLUE%^"+YOU+"'s crystal sublimes into steam.", caster);
        dest_effect();
        return;
    }

    if(spell_type == "monk") { MAGIC_D->elemental_opportunist(caster, target); }

    spell_successful();

    size = "avalanche";
    if (clevel < 15) size = "gush";
    if (clevel < 20) size = "flood";

    switch(element)
    {
    case "acid":
        tell_room(place,"%^BOLD%^%^BLACK%^A cyclone of deadly %^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^ci%^RESET%^%^GREEN%^d %^BOLD%^%^BLACK%^bursts forth from the crystal, directly toward "+HIM+"!%^RESET%^",target);
        tell_object(target,"%^BOLD%^%^BLACK%^A cyclone of deadly %^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^ci%^RESET%^%^GREEN%^d %^BOLD%^%^BLACK%^bursts forth from "+YOU+"'s crystal, directly toward you!%^RESET%^%^RESET%^");
        break;
    case "electricity":
        tell_room(place,"%^BOLD%^%^WHITE%^A wave of brilliant %^YELLOW%^li%^BOLD%^%^WHITE%^g%^YELLOW%^htning %^BOLD%^%^WHITE%^surges forth from the crystal toward "+HIM+"!%^RESET%^",target);
        tell_object(target,"%^BOLD%^%^WHITE%^A wave of brilliant %^YELLOW%^li%^BOLD%^%^WHITE%^g%^YELLOW%^htning %^BOLD%^%^WHITE%^surges forth from "+YOU+"'s crystal toward you!%^RESET%^");
        break;
    case "fire":
        tell_room(place,"%^BOLD%^%^RED%^A blazing maelstrom of %^RESET%^%^RED%^flame %^BOLD%^%^RED%^bursts forth from the crystal toward "+HIM+"!%^RESET%^",target);
        tell_object(target,"%^BOLD%^%^RED%^A blazing maelstrom of %^RESET%^%^RED%^flame %^BOLD%^%^RED%^bursts forth from "+YOU+"'s crystal toward you!%^RESET%^");
        break;
    case "sonic":
        tell_room(place,"%^CYAN%^The crystal %^BOLD%^s%^WHITE%^h%^CYAN%^a%^WHITE%^t%^CYAN%^t%^WHITE%^e%^CYAN%^rs%^RESET%^%^CYAN%^, and a massive s%^BOLD%^h%^WHITE%^o%^GREEN%^c%^CYAN%^k%^GREEN%^w%^WHITE%^a%^CYAN%^v%^RESET%^%^CYAN%^e assaults "+HIM+"!%^RESET%^",target);
        tell_object(target,"%^CYAN%^The crystal %^BOLD%^s%^WHITE%^h%^CYAN%^a%^WHITE%^t%^CYAN%^t%^WHITE%^e%^CYAN%^rs%^RESET%^%^CYAN%^, and a massive s%^BOLD%^h%^WHITE%^o%^GREEN%^c%^CYAN%^k%^GREEN%^w%^WHITE%^a%^CYAN%^v%^RESET%^%^CYAN%^e assaults you!%^RESET%^");
        break;
    default:
        if(spell_type == "monk")
        {
            tell_object(caster, "%^BOLD%^%^WHITE%^You unleash a massive white "+size+" of frost toward "+HIM+"!%^RESET%^");
            tell_room(place, "%^BOLD%^%^WHITE%^A massive white "+size+" of frost thrusts forth from "+caster->QCN+"%^BOLD%^%^WHITE%^ toward "+HIM+"!%^RESET%^", ({target, caster}));
            tell_object(target, "%^BOLD%^%^WHITE%^A massive white "+size+" of frost thursts forth from "+YOU+" toward you!%^RESET%^");
        }
        else
        {
            tell_room(place,"%^BOLD%^%^WHITE%^A massive white "+size+" of frost thrusts forth from the crystal toward "+HIM+"!%^RESET%^",target);
            tell_object(target,"%^BOLD%^%^WHITE%^A massive white "+size+" of frost thrusts forth from "+YOU+"'s crystal toward you!%^RESET%^");
        }
        break;
    }

    inven = target_selector();


    if(sizeof(inven))
    {
        for(i=0;i<sizeof(inven);i++)
        {
            if(!objectp(inven[i])) { continue; }
            if(inven[i] == caster) { continue; }
            if(inven[i] == target) { continue; }
            if(random(100) < clevel)
            {
                hits += ({ inven[i] });
                continue;
            }
            if(random(500) < clevel)
            {
                hits += ({ inven[i] });
                continue;
            }
        }
    }

    if(sizeof(hits))
    {
        for (i = 0;i < sizeof(hits);i++)
        {
            if(!objectp(hits[i])) { continue; }

            switch(element)
            {
            case "acid":
                tell_object(hits[i],"%^BOLD%^%^GREEN%^The corrosive vapor washes over you.\n%^BLUE%^The flesh-eating acid drains your vitality and sears your flesh!");
                tell_room(place,"%^BOLD%^%^GREEN%^The corrosive vapor washes over "+hits[i]->QCN+" as it surges past!%^RESET%^",hits[i]);
                break;
            case "electricity":
                tell_object(hits[i],"%^YELLOW%^You are jolted by a stray bolt of lightning!%^RESET%^");
                tell_room(place,"%^YELLOW%^"+hits[i]->QCN+" is jolted by a stray bolt of lightning!%^RESET%^",hits[i]);
                break;
            case "fire":
                tell_object(hits[i],"%^CYAN%^You are singed by the edge of the fiery maelstrom!%^RESET%^");
                tell_room(place,"%^CYAN%^"+hits[i]->QCN+" is singed by the edge of the fiery maelstrom!%^RESET%^",hits[i]);
                break;
            case "sonic":
                tell_object(hits[i],"%^CYAN%^You are caught within the shockwave!%^RESET%^");
                tell_room(place,"%^CYAN%^"+hits[i]->QCN+" is caught within the shockwave!%^RESET%^",hits[i]);
                break;
            default:
                tell_object(caster,"%^CYAN%^The icy cold overwhelms "+ hits[i]->QCN+", who stands in its path.");
                tell_object(hits[i],"%^BOLD%^%^CYAN%^The icy cold overwhelms you as you are unable to move from its path.\n%^BLUE%^The cone's cold pulls the heat and strength from your body!");
                tell_room(place,"%^BOLD%^%^CYAN%^The icy cold clears "+hits[i]->QCN+" from its path, wreaking damage as it goes!",({caster,hits[i]}));
                break;
            }

            if(do_save(hits[i]))
            {
                damage_targ(hits[i],"torso",sdamage/2,element);
            }
            else
            {
                damage_targ(hits[i],"torso",sdamage,element);
            }
        }
    }

    switch(element)
    {
    case "acid":
        tell_object(target,"%^BOLD%^%^GREEN%^The %^RESET%^%^ORANGE%^f%^WHITE%^l%^ORANGE%^e%^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^h%^BOLD%^%^GREEN%^-%^RESET%^%^GREEN%^e%^MAGENTA%^a%^GREEN%^ti%^RED%^n%^GREEN%^g %^BOLD%^%^GREEN%^vapor all but %^CYAN%^drowns %^GREEN%^everything in its path.\nIt slams mercilessly into you, draining "+target->QP+" vitality and leaving "+target->QO+" %^RED%^screaming %^BOLD%^%^GREEN%^in pain!%^RESET%^");
        tell_room(place,"%^BOLD%^%^GREEN%^The %^RESET%^%^ORANGE%^f%^WHITE%^l%^ORANGE%^e%^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^h%^BOLD%^%^GREEN%^-%^RESET%^%^GREEN%^e%^MAGENTA%^a%^GREEN%^ti%^RED%^n%^GREEN%^g %^BOLD%^%^GREEN%^vapor all but %^CYAN%^drowns %^GREEN%^"+HIM+" as it slams into "+target->QO+", draining "+target->QP+" vitality and leaving "+target->QO+" %^RED%^screaming %^BOLD%^%^GREEN%^in pain!%^RESET%^",target);
        break;
    case "electricity":
        tell_object(target,"%^YELLOW%^The wave of lightning hits you directly, its energy searing into your skin!%^RESET%^");
        tell_room(place,"%^YELLOW%^"+HIM+" is %^BOLD%^%^WHITE%^blasted %^YELLOW%^painfully by the wave of lightning!%^RESET%^",target);
        break;
    case "fire":
        tell_object(target,"%^BOLD%^%^RED%^The maelstrom of fire hits you directly, its unbearable heat searing into your skin!%^RESET%^");
        tell_room(place,"%^BOLD%^%^RED%^"+HIM+" is %^BOLD%^%^WHITE%^blasted %^BOLD%^%^RED%^with the full force of the fiery maelstrom!%^RESET%^",target);
        break;
    case "sonic":
        tell_object(target,"%^CYAN%^You are %^BOLD%^blasted %^RESET%^%^CYAN%^squarely by the brunt of the s%^BOLD%^h%^WHITE%^o%^GREEN%^c%^CYAN%^k%^GREEN%^w%^WHITE%^a%^CYAN%^v%^RESET%^%^CYAN%^e!%^RESET%^");
        tell_room(place,"%^CYAN%^"+HIM+" is %^BOLD%^blasted %^RESET%^%^CYAN%^squarely by the brunt of the s%^BOLD%^h%^WHITE%^o%^GREEN%^c%^CYAN%^k%^GREEN%^w%^WHITE%^a%^CYAN%^v%^RESET%^%^CYAN%^e!%^RESET%^",target);
        break;
    default:
        tell_object(caster,"%^BOLD%^%^CYAN%^The frosty vapor slams into "+HIM+" draining "+target->QP+" heat, strength and life!");
        tell_object(target,"%^BOLD%^%^CYAN%^The frosty vapor thrusts forward dealing equal damage to all that are in its path.\nIt slams mercilessly into you, draining your strength, your heat, and LIFE!!");
        tell_room(place,"%^BOLD%^%^CYAN%^"+YOU+"'s fearful frost slams into "+HIM+"!!", ({caster, target}) );
      break;
    }

    if(do_save(target)) { sdamage = sdamage/2; }
    damage_targ(target, "torso", sdamage, element);
    dest_effect();
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
