#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

int modifier;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("umbral sight");
    set_spell_level(([ "innate" : 2 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS umbral sight");
    set_description("This spell will imbue the caster's vision with the stuff of darkness, allowing them to see easily "
"even in deep shadow. It will similarly protect their vision from extremes of light.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string() {
    tell_object(caster,"%^MAGENTA%^Passing a hand over your eyes, you draw upon the shadowweave to shroud your vision.%^RESET%^");
    tell_room(place,"%^MAGENTA%^"+caster->QCN+" passes a hand over "+caster->QP+" eyes and focusses intently.%^RESET%^",caster);
    return "display";
}

int preSpell() {
    if(caster->query_property("darkvision")) {
        tell_object(caster,"Your senses are already heightened.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    int duration;
    duration = (ROUND_LENGTH * 20) * (clevel + roll_dice(1, 20));

    if(member_array((string)caster->query_race(),PLAYER_D->night_races()) != -1) modifier = -10;
    else modifier = 8;
    tell_room(place,"%^MAGENTA%^"+caster->QCN+"'s pupils dilate, their blackness overwhelming all color in the irises.%^RESET%^",caster);
    tell_object(caster,"%^MAGENTA%^The world around you drains of color and snaps into crystalline clarity.%^RESET%^");
    addSpellToCaster();
    spell_successful();
    caster->add_sight_bonus(modifier);
    caster->set_property("spelled",({TO}));
    caster->set_property("darkvision",1);
}

void dest_effect() {
    if(objectp(caster)) {
        tell_object(caster,"%^MAGENTA%^You blink, and the color drains back into your vision as it loses its clarity.");
        tell_room(environment(caster),"%^MAGENTA%^"+caster->QCN+" blinks, and suddenly "+caster->QP+" eyes look normal again.%^RESET%^",caster);
        caster->add_sight_bonus(-1*modifier);
        caster->remove_property("darkvision");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
