#include <std.h>
#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("remove paralysis");
    set_spell_level(([ "cleric" : 3, "paladin" : 2, "inquisitor" : 2 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS remove paralysis on TARGET");
    set_description("This spell will remove any paralysis from its target. Negates hold spells, and paralysis spells.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
	set_helpful_spell(1);
}

spell_effect(int prof) {
    int duration,level;
    ::spell_effect();
    level = CASTER->query_level();
    tell_object(CASTER, "You cast remove paralysis on "+TARGET->QCN+".");
    tell_room(environment(CASTER), CASTER->QCN+" casts a spell on "+TARGET->QCN+".", CASTER);
    if (!TARGET->query_paralyzed()){
        dest_effect();
        return;
    }
    TARGET->set_paralyzed(0);
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
