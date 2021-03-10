// stone body
#include <std.h>
#include <priest.h>

inherit SPELL;

void create() {
    ::create();
    set_author("ares");
    set_spell_name("stone body");
    set_spell_level(([ "cleric" : 8,
                       "druid"  : 8]));
    set_spell_sphere("combat");
    set_domains("earth");
    set_mystery("stone");
    set_syntax("cast CLASS stone body");
    set_description("This spell will cover the caster's skin in a layer of granite, reducing the damage he takes with "
"each hit.  The higher the level the caster, the more damage will be resisted.  The spell also renders the caster immune "
"to poison."); //This covers premonition from srds for druids
    set_verbal_comp();
	set_helpful_spell(1);
}

string query_cast_string() {
    tell_object(caster,"%^BOLD%^You begin to chant in a strong and solid voice.");
	tell_room(place,"%^BOLD%^"+caster->QCN+" begins to chant in a strong and"+
		" solid voice.",caster);
	return "display";
}

int preSpell() {
    if(caster->query_stoneSkinned() || caster->query_property("iron body")){
        tell_object(caster,"You are already protected by a similar effect.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    int duration;
    duration = (clevel+roll_dice(1,20)) * ROUND_LENGTH * 10;
    tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+"'s skin is transformed into granite "
        "as "+caster->QS+" completes "+caster->QP+" spell!",caster);
    tell_object(caster,"%^BOLD%^As your prayer finishes, you can feel your skin "
        "hardening and turning into unyielding granite!");
    caster->set_property("iron body",1);
    caster->set_property("poison immunity",1);
    caster->set_property("spelled", ({TO}) );
    caster->add_ac_bonus(2);
//    caster->set_property("damage resistance",(clevel/4));
// giving parity with equivalent iron body spell; this kinda sucks at low-end. N, 8/15
    caster->set_property("damage resistance",15);
    addSpellToCaster();
    spell_successful();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    if(objectp(caster)) {
        tell_object(caster,"%^ORANGE%^The granite skin protecting you cracks and breaks "
            "away, leaving you vulnerable once again.");
        tell_room(environment(caster),"%^ORANGE%^The granite skin surrounding "+caster->QCN+" cracks "
            "and breaks away, leaving "+caster->QP+" normal skin in its place.",caster);
        caster->set_property("iron body",-1);
        caster->set_property("poison immunity",-1);
//        caster->set_property("damage resistance",-1*(clevel/4));
        caster->set_property("damage resistance",-15);
        caster->add_ac_bonus(-2);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
