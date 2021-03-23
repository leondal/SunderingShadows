#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

object *targets;

void create() {
    ::create();
    set_spell_name("dust of twilight");
    set_spell_level(([ "mage" : 2, "oracle" : 2, "cleric" : 2 ]));
    set_domains("moon");
    set_spell_sphere("conjuration_summoning");
    set_mystery( ({ "darkness", "lunar" }) );
    set_syntax("cast CLASS dust of twilight");
    set_description("A shower of iridescent black particles clings to and extinguishes all light sources in the room. Creatures in the area must make a save or become fatigued for 1d20 rounds.");
    set_save("fort");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string() {
    tell_object(caster,"%^BOLD%^%^BLACK%^You fling a hand upwards to cast forth a spray of dark dust, and hum a single clear note.");
    tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" flings a hand upwards to cast forth a spray of dark dust, and hums a single clear note.",caster);
    return "display";
}

void spell_effect(int prof)
{
    object *attackers,attacker;
    attackers = all_living(place);
    attackers = filter_array(attackers, "is_non_immortal",FILTERS_D);
    attackers = target_filter(attackers);

    tell_room(place,"%^BOLD%^%^BLACK%^It becomes dark as the dust settles over everything.%^RESET%^");
    foreach(attackers in attackers)
    {
        if(!objectp(attacker))
            continue;

        if(!do_save(attacker,0))
            "/std/effect/status/fatigued"->apply_effect(attacker,roll_dice(1,20));

    }
    place->set_light(0);
}
