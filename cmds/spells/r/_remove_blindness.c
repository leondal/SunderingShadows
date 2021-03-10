// Created by Grayhawk@Shadowgate
// Nov. 3, 1995
// Revised, updated and adapted by Pator@ShadowGate
// added temp blindness back in as a lot of blinds these days are on the temp setting only. N, 03/11.
#include <priest.h>

create() {
    ::create();
    set_author("pator");
    set_spell_name("remove blindness");
    set_spell_level(([ "cleric" : 3, "paladin" : 3,"druid" : 3, "inquisitor" : 2, "oracle":3 ]));
    set_mystery("life");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS remove blindness on TARGET");
    set_description("When you cast this spell you can bring more light into the eyes of the target. You can't cure "
"diseases, but will surely help the target to see more after they have been hit by magical darkness or some foul "
"creature.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
	set_helpful_spell(1);
}

void spell_effect(int prof) {
    if (!living(TARGET)) {
        tell_object(CASTER, "You can't cure something that is non-living!");
    } else {
        if (CASTER == TARGET) {
            tell_object(CASTER, "You touch your eyes and cure your blindness.");
            tell_room(PLACE, YOU+" touches "+CASTER->QP+" eyes and cures "+CASTER->QP+" blindness.",({CASTER}));
            CASTER->set_blind(0);
   // Fix temporary (static) blindness too.
            CASTER->set_temporary_blinded(0);
   // But make them remove their own damn blindfolds.
        } else {
            tell_object(CASTER,"You touch "+HIM+"'s eyes and cure "+TARGET->QP+" blindness.");
            tell_object(TARGET,YOU+" touches your eyes and cures your blindness.");
            tell_room(PLACE, YOU+" reaches for "+HIM+"'s eyes and cures "+TARGET->QP+" blindness.",({CASTER,TARGET}));
            TARGET->set_blind(0);
            TARGET->set_temporary_blinded(0);
        }
    }
    dest_effect();
}

query_cast_string() {
    if (interactive(CASTER)) {
        return YOU+" prays for a divine spell!\n";
    } else {
        return YOU+" calls for a divine spell!\n";
    }
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
