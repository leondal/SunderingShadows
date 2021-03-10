//      Chill Touch
// updated to include versatile arcanist stuff and make it cosmetically a ray
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

string target_limb, element;


create()
{
    ::create();
    set_spell_name("polar ray");
    set_spell_level(([ "mage" : 8 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS polar ray on TARGET");
    set_damage_desc("cold");
    set_description("A blue-white ray of freezing air and ice springs from the casters hand aimed at her target, freezing them.  A versatile arcanist can manipulate the base element of this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}


string query_cast_string() { return caster->QCN+" utters a deathly chant."; }

spell_effect(int prof)
{
    string mycolor, myhue, myhue2, myfeeling, damtype;
    int bonus, roll;

    if(!objectp(caster) || !objectp(target))
    {
        target = 0;
        dest_effect();
        return;
    }

    target_limb = target->return_target_limb();

    bonus = 0;

    if (!present(target,environment(caster)))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        target = 0;
        dest_effect();
        return;
    }

    element = (string)caster->query("elementalist");

    switch(element)
    {
    case "acid":
        mycolor = "%^GREEN%^";
        myhue = "sickly green";
        myhue2 = "sickly green glow";
        myfeeling = "burning pain";
        damtype = "acid";
        break;
    case "electricity":
        mycolor = "%^ORANGE%^";
        myhue = "static-charged";
        myhue2 = "charge of static";
        myfeeling = "sudden jolt";
        damtype = "electricity";
        break;
    case "fire":
        mycolor = "%^RED%^";
        myhue = "radiantly glowing";
        myhue2 = "radiant glow";
        myfeeling = "blazing pain";
        damtype = "fire";
        break;
    case "sonic":
        mycolor = "%^MAGENTA%^";
        myhue = "pulsing";
        myhue2 = "pulsing aura";
        myfeeling = "horrible throbbing";
        damtype = "sonic";
        break;
    default:
        element = "cold";
        mycolor = "%^CYAN%^";
        myhue = "bluish glowing";
        myhue2 = "bluish glow";
        myfeeling = "ghastly chill";
        damtype = "cold";
        break;
    }

    tell_object(caster,"%^BOLD%^"+mycolor+"Your hand starts to develop a "+myhue2+".");
    tell_room(place,"%^BOLD%^"+mycolor+caster->QCN+"'s hand starts to develop a "+myhue2+".",caster );

    roll = BONUS_D->process_hit(caster, target, 1, bonus, 0, 1);

    if(!roll || roll == -1 && ! caster->query_property("spectral_hand"))
    {
        tell_object(caster,""+mycolor+"You aim a ray at "+target->QCN+"'s "+target_limb+" from a "+myhue+" hand, but miss!");
        tell_object(target,""+mycolor+caster->QCN+"'s "+myhue+" ray shoots toward your "+target_limb+" unsuccessfully.");
        tell_room(place,""+mycolor+caster->QCN+" aims a ray at "+target->QCN+"'s "+target_limb+" from a "+myhue+" hand and misses!", ({ caster, target}) );
        target = 0;
        dest_effect();
        return;
    }

    if(!"/daemon/combat_d.c"->extra_hit_calcs(caster, target))
    {
        target = 0;
        dest_effect();
        return;
    }

    tell_object(caster,"%^BOLD%^"+mycolor+"You connect with a ray aimed at "+target->QCN+"'s "+target_limb+" from your "+myhue+" hand.");
    tell_object(target,"%^BOLD%^"+mycolor+caster->QCN+" aims a ray that strikes your "+target_limb+" from a "+myhue+" hand.\n%^WHITE%^A "+myfeeling+" runs through you, sapping your strength!");
    tell_room(place,"%^BOLD%^"+mycolor+caster->QCN+" aims a ray that hits "+target->QCN+"'s "+target_limb+" from a "+myhue+" hand!",({ caster, target}) );
    spell_successful();

    damage_targ(target, target_limb, sdamage , damtype );
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
