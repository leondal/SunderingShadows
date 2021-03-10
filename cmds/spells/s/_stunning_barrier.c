#include <std.h>
#include <priest.h>
inherit SPELL;

int flag;
int lastattack;

void create()
{
    ::create();
    set_spell_name("stunning barrier");
    set_spell_level(([ "cleric" : 1, "inquisitor" : 1, "paladin" : 1, "mage":1 , "psywarrior" : 1]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS stunning barrier");
    set_damage_desc("briefly stuns first enemy");
    set_description("You are closely surrounded by a barely visible magical field. It provides impact bonus to your armor and minor ability to deflect all kinds of incoming power. When struck it will discharge at first enemy, briefly stunning them.");
    set_save("will");
    set_helpful_spell(1);
}

int preSpell()
{
    if(caster->query_property("stunning barrier"))
    {
        tell_object(caster,"You are already protected by this spell.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    tell_room(place,"%^BLUE%^A field of force around "+caster->QCN+" briefly becomes visible.",caster);
    tell_object(caster,"%^BLUE%^A field of force raises around you.");
    caster->set_property("stunning barrier",1);
    caster->set_property("spelled", ({TO}) );
    addSpellToCaster();
    spell_successful();
    execute_attack();
}

void execute_attack()
{
    object *attackers,room;
    int i;

    ::execute_attack();
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    room      = environment(caster);
    attackers = caster->query_attackers();
    attackers = filter_array(attackers,"is_non_immortal",FILTERS_D);
    attackers = target_filter(attackers);
    if(lastattack == time())
        return;
    room->addObjectToCombatCycle(TO,1);
    lastattack = time();
    if(!sizeof(attackers))
        return;
    attackers = filter_array(attackers,(:!$1->query("not living"):));
    attackers = filter_array(attackers,(:!do_save($1,0):));
    if(sizeof(attackers))
    {
        tell_object(attackers[0],"%^CYAN%^A field of force disperses at you as you assault "+caster->QCN+".%^RESET%^");
        tell_object(caster,"%^CYAN%^The force field discharges at "+attackers[0]->QCN+".%^RESET%^");
        tell_room(room,"%^CYAN%^"+attackers[0]->QCN+" seems stunned as "+attackers[0]->QS+" strike "+caster->QCN+".%^RESET%^.",({caster,attackers[0]}));
        attackers[0]->set_paralyzed(roll_dice(1,2)*8,"%^CYAN%^You're stunned by the stike of force!%^RESET%^");
        dest_effect();
    }
}

void dest_effect(){
    if(objectp(caster)){
        tell_object(caster,"%^BLUE%^A field of force surrounding you disperses.");
        caster->remove_property("stunning barrier");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
