#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/c/_create_undead";

void create()
{
    ::create();
    set_spell_name("create spawn");
    set_spell_level(([ "innate" : 8 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS create spawn");
    set_description("With this spell a vampire can use the recently deceased to raise a powerful undead vampire spawn to aid them in combat. This power behaves the same way similar spells of creating undead does, but it is unique to vampires." + ("/cmds/spells/a/_animate_dead"->extra_help()));
    evil_spell(1);
    set_helpful_spell(1);
    set_arg_needed();
}

string query_cast_string()
{
    return "%^BOLD%^%^BLACK%^A vampire knight forms itself out of the mist.%^RESET%^";
}

string undead_to_raise()
{
    if (caster->is_class("vampire_lord")) {
        return "vampire_knight";
    }

    return "vampire_spawn";
}

void setup_undead_scaling(object undead)
{
    undead->set_guild_level("fighter", clevel);
    undead->set_mlevel("fighter", clevel);
    undead->set_property("raised", 1);
    if (caster->is_class("vampire_lord")) {
        undead->set_guild_level("mage", clevel);
        undead->set_mlevel("mage", clevel);
        undead->set_weap_enchant(clevel / 10);
        tell_object(caster,"%^BOLD%^%^RED%^Vampire knight speaks to your mind: %^RESET%^%^RED%^I am yours to command, Master.");
    }

    undead->set_skill("perception", clevel);
    undead->set_level(clevel);
    undead->set_hd(clevel, 10);
    undead->set_max_hp(clevel * 12 + 200);
    undead->set_attacks_num(clevel / 5 + 1);
    undead->set_hp(undead->query_max_hp());
    undead->set_overall_ac(6 - clevel);
}
