#include <spell.h>
#include <magic.h>

inherit SPELL;

#define INV_SPELL "/cmds/spells/i/_invisibility"

create()
{
    ::create();
    set_spell_name("mass invisibility");
    set_spell_level(([ "mage" : 7, "assassin" : 4,]));
    set_domains("trickery");
    set_spell_sphere("illusion");
    set_syntax("cast CLASS mass invisibility");
    set_description("This spell applies invisibility spell to all your followers and party members. Note that maintaining this spell is much harder than common invisibility.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^CYAN%^"+caster->QCN+" chants rhythmically, "+caster->QP+" voice getting slowly lower and harder to hear.";
}

int preSpell()
{
    object * party, dude;
    object nspell;

    party = ob_party(caster) + (caster->query_followers() - caster->query_attackers()) + ({caster});

    party = distinct_array(party);


    foreach(dude in party)
    {
        nspell = new(INV_SPELL);
        nspell->set_silent_casting(1);
        nspell->use_spell(TP, dude, clevel, 100, "mage");
    }

    spell_successful();
    return 1;
}
