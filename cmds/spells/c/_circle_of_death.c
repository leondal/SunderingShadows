#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("circle of death");
    set_spell_level(([ "mage" : 6, "cleric" : 6, "inquisitor" : 6, ]));
    set_spell_sphere("necromancy");
    set_mystery(({ "bones", "apocalypse" }));
    set_syntax("cast CLASS circle of death");
    set_damage_desc("negative energy");
    set_description("The caster draws a circle around herself and channels negative energy outwards, destroying living creatures that are not able to withstand it, but not affecting at all those of the strong will. The spell won't affect targets stronger than your caster level.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("will");
    splash_spell(3);
}

string query_cast_string()
{
    return "%^BOLD%^%^BLUE%^" + caster->QCN + " draws a circle of darkness around " + caster->QP + "self.";
}

void spell_effect(int prof)
{
    object* foes, foe;
    int max;

    tell_object(caster, "%^BOLD%^%^BLUE%^As you finish drawing a circle of death, you channel energy out of it.");
    tell_room(place, "%^BOLD%^%^BLUE%^" + caster->QCN + " channels blinding energy out of the circle of darkness.", caster);

    foes = target_selector();
    foes = shuffle(foes);

    max = clevel * 2;

    foreach(foe in foes)
    {
        if (!foe->query_property("negative energy affinity")) {
            if (combat_death_save(foe, 0)) {
                tell_object(foe, "%^BLUE%^%^BOLD%^The darkness washes over you, but nothing happens!");
                continue;
            }

            tell_object(foe, "%^BLUE%^%^BOLD%^Your life ends, as negative energy destroys your very soul!");
            tell_room(place, "%^BLUE%^%^BOLD%^" + foe->QCN + " crumbles to dust!", foe);
            damage_targ(foe, foe->return_target_limb(), foe->query_max_hp() * 2, "negative energy");
            max -= foe->query_level();
        }        
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
