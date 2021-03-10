#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("dismissal");
    set_spell_level(([ "mage" : 5, "cleric" : 4, "inquisitor" : 4, "psion" : 3, "magus" : 5 ]));
    set_spell_sphere("abjuration");
    set_discipline("nomad");
    set_syntax("cast CLASS dismissal");
    set_damage_desc("destroys spelled creatures");
    set_description("This spell forces the summoned creatures that are attacking you to be dismissed.");
}

void spell_effect(int prof)
{
    object *attackers, enemy_caster, spelled;
    
    attackers = caster->query_attackers();
    attackers = target_filter(attackers);

    tell_room(place,"%^BLUE%^"+caster->QCN+" releases waves of arcane energies.%^RESET%^",caster);
    tell_object(caster,"%^BLUE%^You release waves of arcane energies.");
    if(!sizeof(attackers))
    {
        tell_object(caster,"%^BOLD%^%^CYAN%^The waves fail to touch anything.%^RESET%^");
        dest_effect();
        return;
    }
    
    foreach(object ob in attackers)
    {
        spelled = ob->query_property("spell_creature");
        
        if(spelled &&
        (spelled || ob->is_undead()) &&
        ((clevel + roll_dice(1, 6)) > (spelled->query_caster_level())))
        {
            tell_room(place,"%^CYAN%^BOLD%^" + ob->QCN + " disappears in a flash.");
            ob->move("/d/shadowgate/void");
            ob->remove();
        }
    }
    
    spell_successful();
    dest_effect();
}
