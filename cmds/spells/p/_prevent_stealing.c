// --==** /cmds/priest/_create_food.c **==--
// Created by Pator@ShadowGate
// October 30 1996

#include <priest.h>

int value;
object where;

create() {
    ::create();
    set_author("pator");
    set_spell_name("prevent stealing");
    set_spell_level(([ "cleric" : 4, "paladin" : 3 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS prevent stealing");
    set_description("This spell prevents stealing in the room where the caster has cast the spell for an amount of time "
"dependent on the level of the caster.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

void spell_effect(int prof) {
    int duration, amount,clevel;

    where = PLACE;

    // Is there some magic protection already ?
    value = (int)where->query_property("no steal");
    if (value) {
        tell_object(CASTER, "%^CYAN%^This room is already protected against stealing!");
        destruct(this_object() );
        return 1;
    } else {
        tell_object(CASTER,"%^CYAN%^This room is now protected against stealing!");
      tell_room(PLACE,""+YOU+" focuses on "+MINE+" holy symbol and chants softly.", ({CASTER}) );
    }
    if (clevel > 20) clevel = 20;
    amount = clevel/2;
    amount++;
    where->set_property("no steal", 1);
    where->set_property("spelled", ({TO}) );
    // The time the room will be steal protected
    duration = ( clevel * 45);
    if (duration < 250) duration = 250;
    spell_successful();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    if (objectp(PLACE)){
        PLACE->remove_property("no steal");
        PLACE->remove_property_value("spelled", ({TO}) );
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
