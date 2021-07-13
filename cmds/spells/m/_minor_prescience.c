//minor prescience
//~Circe~ 7/20/05
#include <spell.h>
#include <magic.h>
inherit SPELL;

object targ;
int bonus;

void create() {
    ::create();
    set_spell_name("minor prescience");
    set_spell_level(([ "psion" : 1 ]));
    set_spell_sphere("clairsentience");
    set_bonus_type("insight");
    set_syntax("cast CLASS minor prescience");
    set_description("This power will allow the psion foreknowledge, granting him additional prowess in battle.  The power "
"gives the psion a minor bonus to hit and damage his opponents for a time.");
    set_verbal_comp();
    set_property("keywords", ({ "targeted", "personal" }));
	set_helpful_spell(1);
}

string query_cast_string() {
    return "%^ORANGE%^"+caster->QCN+"'s eyes take on a calculating look.";
}

int preSpell() {
    if (caster->query_property("prescienced")) {
        tell_object(caster,"You are already under the effects "+
           "of a prescience power.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof){
    int mylevel;
    mylevel = clevel;
    target = caster;
    tell_room(place,"%^YELLOW%^Knowledge shimmers in "+caster->QCN+"'s "+
              "eyes as "+caster->QS+" grows more confident.",target);
    tell_object(target, "%^YELLOW%^You feel the calm assurance of "+
                "foreknowledge fill your mind, making you deadly in battle.");
    bonus = clevel/12;
    bonus = bonus>4?4:bonus;
    target->add_attack_bonus(bonus);
    target->add_damage_bonus(bonus);
    spell_duration = (clevel / 2 + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
    target->set_property("prescienced",1);
    target->set_property("spelled", ({TO}) );
    addSpellToCaster();
    spell_successful();
}

void dest_effect() {
    if (objectp(target)) {
        tell_object(target,"%^ORANGE%^You feel the foreknowledge "+
           "drain from you.");
        tell_room(environment(target),"%^ORANGE%^"+target->QCN+"'s "+
           "eyes seem to grow dull.",target);
        target->add_attack_bonus(-bonus);
        target->add_damage_bonus(-bonus);
        target->remove_property("prescienced");
        target->remove_property_value("spelled", ({TO}) );
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
