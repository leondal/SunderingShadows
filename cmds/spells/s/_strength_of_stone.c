// strength of stone
//swapped with earth reaver for L3 and made self-cast only - as we all figured it was a better balance. Nienne, 11/07
#include <std.h>
#include <magic.h>

inherit SPELL;

int bonus;

void create() {
    ::create();
    set_author("ares");
    set_spell_name("strength of stone");
    set_spell_level(([ "druid" : 3, "cleric" : 3 ]));
    set_spell_sphere("alteration");
    set_domains("earth");
    set_bonus_type("sacred");
    set_syntax("cast CLASS strength of stone [ON TARGET]");
    set_description("This spell will imbue the caster with the strength of the earth, slightly empowering both their melee and spell abilities. The spell does not stack with other bless-type spells.");
    set_verbal_comp();
    set_helpful_spell(1);
}

string query_cast_string() {
      tell_object(caster,"%^BOLD%^Planting both feet solid on the ground, you begin"+
		" to chant in a solid voice.");
	tell_room(place,"%^BOLD%^"+caster->QCN+" plants both of "+
		""+caster->QP+" feet on the ground, as "+caster->QS+" begins"+
		" to chant in a solid voice.",caster);
	return "display";
}

int preSpell(){ //converting this over to the bless category of spells, to allow for bull's strength. -N, 8/10.
    if(!target) { target = caster; }
    if(target->query_property("blessed") || target->query_property("blighted")){
        tell_object(caster,"%^BOLD%^%^BLUE%^Your target is already "+
           "gifted with a similar spell.%^RESET%^");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    int duration;

    duration = (ROUND_LENGTH * 20) * clevel;
        bonus = clevel/18+1;
    bonus = bonus>3?3:bonus;

    tell_room(place,"%^ORANGE%^The ground rumbles beneath"+
            " "+caster->QCN+"'s for a moment.",target);
    tell_object(target,"%^ORANGE%^The ground rumbles underneath your feet"+
            " for a moment, as you can feel the earth lending you a small"+
            " portion of its strength.");

    target->add_damage_bonus(bonus);
    target->add_attack_bonus(bonus);
    addSpellToCaster();
    target->set_property("spelled",({TO}));
    target->set_property("blessed",1); //using this property so it won't stack with similar spells
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
}

void dest_effect() {
    if(objectp(target)) {
      tell_object(target,"%^BOLD%^You can feel the strength of stone leave you.");
      target->add_damage_bonus(-1*bonus);
      target->add_attack_bonus(-1*bonus);
      target->set_property("blessed",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
