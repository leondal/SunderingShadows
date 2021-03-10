#include <std.h>
#include <daemons.h>
#include <party.h>
#include <spell.h>
#include <teleport.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("planar bacon");
    set_spell_level(([ "mage" : 1, "bard":1,]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS planar bacon");
    set_description("Get some extradimensional swine.");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string()
{
    return "%^BOLD%^%^BLUE%^" + caster->QCN + " snarls the first syllables of a summoning.";
}

void spell_effect(int prof)
{
    object monster;

    /* if (caster->query_race() == "halfling") { */
    /*     monster = new("/d/magic/mon/swinelord"); */
    /* } else { */
    monster = new("/d/magic/mon/pig");
    /* } */

    if (!objectp(monster)) {
        return;
    }

    tell_room(place, "%^BOLD%^%^MAGENTA%^Suddenly, a pig materializes out of nothing.");

    monster->set_property("spelled", ({ TO }));
    monster->set_property("spell_creature", TO);
    monster->set_property("spell", TO);
    monster->add_id(caster->query_true_name() + "_monster");
    monster->set_property("minion", caster);
    monster->set_new_exp(1, "low");
    monster->move(environment(caster));
    caster->add_follower(monster);
    caster->add_protector(monster);

    addSpellToCaster();
    spell_successful();
}
