#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("undeath is death");
    set_spell_level(([ "mage" : 6, "cleric" : 6, "inquisitor" : 6, ]));
    set_spell_sphere("necromancy");
    set_mystery("reaper");
    set_domains("repose");
    set_syntax("cast CLASS undeath is death");
    set_damage_desc("positive energy to undead");
    set_description("A caster draws a circle around herself and channels positive energy ourwards, destroying undead creatures that are not able to withstand it, but not affecting at all those of the strong will.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("will");
    splash_spell(3);
}

string query_cast_string()
{
    return "%^BOLD%^%^ORANGE%^" + caster->QCN + " draws a circle of light around " + caster->QP + "self.";
}

void spell_effect(int prof)
{
    object* foes, foe;
    int max;

    tell_object(caster, "%^BOLD%^%^ORANGE%^As you finish drawing a circle of life, you channel energy out of it.");
    tell_room(place, "%^BOLD%^%^ORANGE%^" + caster->QCN + " channels blinding energy out of the light circle.", caster);

    foes = target_selector();
    foes = shuffle(foes);

    max = clevel * 2;

    foreach(foe in foes)
    {
        if (!foe->is_undead()) {
            continue;
        }

        if (do_save(foe, 0) ||
            foe->query_level() > caster->query_level() + 10) {
            tell_object(foe, "%^ORANGE%^%^BOLD%^The light washes over you, but nothing happens!");
            continue;
        }

        max -= foe->query_level();

        tell_object(foe, "%^ORANGE%^%^BOLD%^Your unlife ends, as positive energy destroys your essence!");
        tell_room(place, "%^ORANGE%^%^BOLD%^" + foe->QCN + " crumbles to dust!", foe);
        damage_targ(foe, foe->return_target_limb(), foe->query_max_hp() * 2, "positive energy");
    }

    spell_successful();
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
