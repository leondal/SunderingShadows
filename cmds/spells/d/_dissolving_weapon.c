/*
  _dissolving_weapon.c

  Dissolving Weapon from PF SRD.
  Adds acid damage to your weapon.

  -- Tlaloc --
*/

#include <std.h>

inherit SPELL;

object weapon;

void create()
{
    ::create();
    set_author("tlaloc");
    set_spell_name("dissolving weapon");
    set_spell_level( ([ "psywarrior" : 2 ]) );
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS dissolving weapon on WEAPON");
    set_damage_desc("4d6 Acid damage on enemy on hit.");
    set_description("With this power, the caster imbues their weapon with acid. The weapon has a chance on hit to do 4d6 acid damage on the victim.");
    set_arg_needed(1);
}

void spell_effect()
{
    mapping info;
    string pname, wname, pposs;

    if(!arg)
    {
        tell_object(caster, "You need a target for dissolving weapon.");
        return;
    }
    
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
    info["file"] = "/d/magic/obj/weap_effects/acidic";
    info["func name"] = "acid_func";
    info["spell"] = this_object();

    weapon->set_property("temp_hit_bonus", info);
    pname = caster->query_cap_name();
    wname = weapon->query_name();
    pposs = caster->query_possessive();

    tell_object(caster, "%^GREEN%^BOLD%^You focus your psychic energies onto your " + wname + " and it takes on a coat of acid.%^RESET%^");
    place && tell_room(place, "%^GREEN%^BOLD%^" + pname + " focuses " + pposs + " psychic energies onto " + pposs + " weapon and it is soon coated with acid.%^RESET%^", ({ caster }));
    caster->set_property("spelled", ({ this_object() }));
    weapon->set_property("added short", ({ "%^GREEN%^BOLD%^ {acidic}%^RESET%^" }) );
    addSpellToCaster();
}

void dest_effect()
{
    if(weapon && objectp(weapon))
        load_object("/d/magic/obj/weap_effects/acidic.c")->remove_prop(weapon);
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
