#include <spell.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("gentle repose");
    set_spell_level(([ "cleric" : 2, "mage" : 3, "druid":2]));
    set_syntax("cast CLASS gentle repose");
    set_spell_sphere("necromancy");
    set_domains("repose");
    set_description("This spell preserves remains of the dead in the area, extending their decay time. Doing so effectively extends the time limit on raising that creature from the dead. Note, this spell accepts no targets.");
    set_helpful_spell(1);
}

void spell_effect()
{
    object *corpses=({}), corpse;

    corpses=all_inventory(ENV(caster));
    corpses=filter_array(corpses,(:(int)$1->is_corpse()==1:));

    if(!sizeof(corpses))
    {
        tell_object(caster,"%^BOLD%^%^BLUE%^There are no corpses.%^RESET%^");
        TO->remove();
        return;

    }
    tell_object(caster,"%^BOLD%^%^CYAN%^You gently touch corpses in the room, freezing them.%^RESET%^");
    tell_room(ENV(caster),"%^BOLD%^%^CYAN%^"+caster->QCN+" gently touches corpses in the room, freezing them.%^RESET%^",caster);
    spell_successful();
    map_array(corpses,(:$1->remove_decay():));
    dest_effect();
    return;

}
