/*
  _vampiric_weapon.c

  AKA Vampiric Blade from PF SRD.
  Adds a life drain effect to your weapon.

  -- Tlaloc --
*/

#include <std.h>

inherit SPELL;

object weapon;

void create()
{
    ::create();
    set_author("tlaloc");
    set_spell_name("vampiric weapon");
    set_spell_level( ([ "psywarrior" : 3 ]) );
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS vampiric weapon on WEAPON");
    set_damage_desc("Negative energy damage on enemy and heals wielder.");
    set_description("With this power, the caster imbues their weapon with an ominous glimmer. When striking, the weapon has a chance to pull on the victim's life force, harming them with necrotic energy and healing the wielder.");
    set_arg_needed(1);
}

void spell_effect()
{
    mapping info;
    string pname, wname, pposs;

    if(!caster || !arg)
        return;
    
    weapon = present(arg, caster);

    if(!objectp(weapon))
    {
        tell_object(caster, "There is no " + arg + " in your possession.");
        this_object()->remove();
        return;
    }

    if(!weapon->is_weapon())
    {
        tell_object(caster, "That is not a weapon!");
        this_object()->remove();
        return;
    }

    if(weapon->query_property("temp_hit_bonus"))
    {
        tell_object(caster, "That weapon is already magically enhanced.");
        this_object()->remove();
        return;
    }

    info = ([  ]);
    info["file"] = "/d/magic/obj/weap_effects/vampiric";
    info["func name"] = "vampiric_func";
    info["spell"] = this_object();

    weapon->set_property("temp_hit_bonus", info);
    pname = caster->query_cap_name();
    wname = weapon->query_name();
    pposs = caster->query_possessive();

    tell_object(caster, "%^CYAN%^BOLD%^You focus your psychic energies onto your " + wname + " and it begins to glow with an ominous glimmer.%^RESET%^");
    place && tell_room(place, "%^CYAN%^BOLD%^" + pname + " focuses " + pposs + " psychic energies onto " + pposs + " weapon and it begins to glow with an ominous glimmer.%^RESET%^", ({ caster }));
    caster->set_property("spelled", ({ this_object() }));
    weapon->set_property("added short", ({ "%^MAGENTA%^ {vampiric}%^RESET%^" }) );
    addSpellToCaster();
}

void dest_effect()
{
    if(objectp(weapon))
        load_object("/d/magic/obj/weap_effects/vampiric")->remove_prop(weapon);
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
