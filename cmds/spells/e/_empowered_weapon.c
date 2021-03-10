/*
  _empowered_weapon.c

  Uses your power points to empower the weapon with more damage.

  -- Tlaloc --
*/

#include <std.h>

inherit SPELL;

object weapon;

void create()
{
    ::create();
    set_author("tlaloc");
    set_spell_name("empowered weapon");
    set_spell_level( ([ "psywarrior" : 5 ]) );
    set_damage_desc("Chance on hit to do mental damage to enemy.");
    set_syntax("cast CLASS empowered weapon on WEAPON");
    set_description("With this power, the caster infuses their weapon with their own psychic essence. A strike with the weapon has a chance to cause additional damage at the cost of power points.");
    set_arg_needed(1);
}

void spell_effect()
{
    mapping info;
    string pname, wname, pposs;

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
    info["file"] = "/d/magic/obj/weap_effects/empowered";
    info["func name"] = "empower_func";
    info["spell"] = this_object();

    weapon->set_property("temp_hit_bonus", info);
    pname = caster->query_cap_name();
    wname = weapon->query_name();
    pposs = caster->query_possessive();

    tell_object(caster, "%^CYAN%^BOLD%^You focus your psychic energies onto your " + wname + " and is becomes infused with mental energy.%^RESET%^");
    place && tell_room(place, "%^CYAN%^BOLD%^" + pname + " focuses " + pposs + " psychic energies onto " + pposs + " weapon and it becomes infused with mental energy.%^RESET%^", ({ caster }));
    caster->set_property("spelled", ({ this_object() }));
    weapon->set_property("added short", ({ "%^CYAN%^BOLD%^ {empowered}%^RESET%^" }) );
    addSpellToCaster();
}

void dest_effect()
{
    if(weapon && objectp(weapon))
        load_object("/d/magic/obj/weap_effects/empowered.c")->remove_prop(weapon);
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
