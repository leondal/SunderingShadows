// Continual light
// Pator@Shadowgate
// 11/06/95

#include <priest.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("daylight");
    set_spell_level(([ "cleric" : 3, "bard" : 3, "paladin" : 3, "inquisitor" : 3, "oracle" : 3, "mage" : 3, "magus" : 3 ]));
    set_spell_sphere("invocation_evocation");
    set_domains("sun");
    set_mystery(({"heavens","solar"}));
    set_syntax("cast CLASS daylight");
    set_description("Will add semi-permanent light to a room up to daylight levels.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

string query_cast_string() {
   return ""+YOU+" focuses on "+MINE+" holy symbol and chants softly.\n";
}

void spell_effect(int prof) {
    int light;

    light = environment(CASTER)->query_light();
    if (light < 3) {  // was only < 2
        if (interactive(CASTER)) {
            tell_object(CASTER, "%^YELLOW%^You put a light in this room.%^RESET%^");
            tell_room(PLACE,YOU+" puts a %^YELLOW%^light %^RESET%^in this room.\n",({ CASTER}));
        } else {
            tell_room(PLACE,YOU+" makes this room lighter!\n",({ CASTER}));
        }
        environment(CASTER)->set_light(2);
    } else if(light == 3) {
        environment(CASTER)->set_light(1);
        if (interactive(CASTER)) {
            tell_object(CASTER, "%^YELLOW%^You put a light in this room.%^RESET%^");
            tell_room(PLACE,YOU+" puts a %^YELLOW%^light %^RESET%^in this room.\n",({ CASTER}));
        } else {
            tell_room(PLACE,YOU+" makes this room lighter!\n",({ CASTER}));
        }
    } else {
        if (interactive(CASTER)) {
            tell_object(CASTER, "The room is not dark enough to benefit from more light.");
            tell_room(PLACE,YOU+" fails to put a light in this room.",({ CASTER}));
        } else {
            tell_room(PLACE,YOU+" fails to make this room light !",({ CASTER}));
        }
    }
    dest_effect();
}

void dest_effect() {
     ::dest_effect();
     if(objectp(TO)) TO->remove();
}
