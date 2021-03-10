#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int duration;
object cloud,*blind=({});

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("breath of the night");
    set_spell_level(([ "warlock" : 1 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS breath of the night");
    set_description("This invocation draws mosture from the air to form a dense mist, blanketing the "
"nearby area and making it impossible for anyone, including the warlock, to see more than a few inches "
"ahead. The thick mist will only linger for a brief time before dissipating, and can only be cast out "
"of doors where the air is sufficiently open to be able to gather such a mist.");
    set_verbal_comp();
}

int preSpell() {
    if(place->query_property("fog cloud")) {
        tell_object(caster,"%^CYAN%^There's already too much fog and mist here!");
        return 0;
    }
    if(place->query_property("indoors")) {
        tell_object(caster,"%^CYAN%^This place is too enclosed to gather sufficient mists from the air.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    tell_object(caster,"%^BLUE%^You allow your power to filter gently out into the air.%^RESET%^");
    tell_room(place,"%^BLUE%^"+caster->QCN+" spreads "+caster->QP+" arms, as if in a silent entreaty.%^RESET%^",caster);

    duration = (ROUND_LENGTH + (ROUND_LENGTH * ((clevel+9)/10))) + time();
    
    cloud = new(OBJECT);
    cloud->set_name("a dark and ominous mist");
    cloud->set_short("%^CYAN%^a dark and ominous mist");
    cloud->set_long("%^CYAN%^The mist hangs in a lingering cloud over the area, seeping its moisture into every space. "
"The haze is so dark and thick, you can't see anything more than a few inches in front of your face!%^RESET%^");
    cloud->set_id(({"fog","fog bank","mist","dark mist","ominous mist"}));
    cloud->set_property("no animate",1);
    cloud->set_weight(1000000);
    call_out("cloud_blindness",5);
}

void cloud_blindness() {
    object *ppl,tp;
    int i;

    if((time() > duration) || !objectp(place)) {
        dest_effect();
        return;
    }

    if(!place->query_property("fog cloud")) {
        tell_room(place,"%^CYAN%^A ro%^RESET%^i%^CYAN%^ling mi%^RESET%^s%^CYAN%^t coalescs around you, darkening the area so that it becomes almost impossible to see!%^RESET%^");
        cloud->move(place);
        place->set_property("fog cloud",1);
    }

    if(sizeof(blind)) {
        for(i=0;i<sizeof(blind);i++) {
            if(!objectp(tp = blind[i])) { continue; }
            if(present(tp,place)) { continue; }
            tell_object(tp,"%^CYAN%^You escape the ominous mist and your sight returns!%^RESET%^");
            tp->set_blind(0);
        }
    }

    blind = ({});

    ppl = all_living(place);

    for(i=0;i<sizeof(ppl);i++) {
        if(!objectp( tp = ppl[i])) { continue; }
        if(avatarp(tp)) { continue; }

        if(!tp->query_blind()) { tell_object(tp,"%^CYAN%^The dense mist makes it impossible to see!%^RESET%^"); }
        tp->set_blind(1);
        blind += ({ tp });
    }

    call_out("cloud_blindness",1);
}

void dest_effect() {
    object tp;
    int i;

    if(objectp(place) && place->query_property("fog cloud")) {
        tell_room(place,"%^CYAN%^The ominous miasma slowly dissipates!%^RESET%^");
        place->remove_property("fog cloud");
    }
    if(objectp(cloud)) {
        cloud->move("/d/shadowgate/void");
        destruct(cloud);
    }

    if(sizeof(blind)) {
        for(i=0;i<sizeof(blind);i++) {
            if(!objectp( tp = blind[i])) { continue; }
            tell_object(tp,"%^CYAN%^As the mists clear, you can finally see again!%^RESET%^");
            tp->set_blind(0);
        }
    }

    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
