/*
   _dissipating_touch.c

   Does teleportation damage to the target. Touch attack.

   -- Tlaloc -- 3.20.20
 */

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_author("tlaloc");
    set_spell_name("dissipating touch");
    set_spell_level(([ "psion" : 1 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS dissipating touch on TARGET");
    set_description("With this power, the psion's mere touch can disperse the surface material of their foe, teleporting a portion of it away and disrupting their very structure.");
    set_target_required(1);
}

string query_cast_string()
{
    return sprintf("%s extends %s hand and it begins to glow with psychic energy.", caster->QCN, caster->QP);
}

void spell_effect(int prof)
{
    string my_name, your_name;


    if (!present(target, environment(caster))) {
        tell_object(caster, "Your target is not in this area.\n");
        this_object()->remove();
        return;
    }

    my_name = caster->query_cap_name();
    your_name = target->query_cap_name();

    if (!thaco(target, 0) && target && caster) {
        tell_object(caster, sprintf("You reach out to touch %s but miss!", your_name));
        tell_object(target, sprintf("%s reaches out to touch you, but misses!", my_name));
        tell_room(place, sprintf("%s reaches out to touch %s, but misses!", my_name, your_name), ({ target, caster }));
        TO->remove();
        return;
    }

    spell_successful();

    tell_object(caster, "%^CYAN%^" + sprintf("You reach out with a glowing hand and touch %s, causing a blast of vapor to erupt!", your_name) + "%^RESET%^");
    tell_object(target, "%^CYAN%^" + sprintf("%s reaches out with a glowing hand and touches you, causing a blast of vapor to erupt!", my_name) + "%^RESET%^");
    tell_room(place, sprintf("%s reaches out with a glowing hand and touches %s, causing a blast of vapor to erupt!", my_name, your_name) + "%^RESET%^", ({ target, caster }));

    damage_targ(target, "chest", sdamage, "untyped");
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
