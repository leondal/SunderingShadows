// Protection from Scrying
// Protects from any scrying attempts on the
// target of the spell for a period dependant on
// the spell level of the caster
// Thorn@ShadowGate
// 4 January 2001
// Updated by ~Circe~ with slightly different block power
// to match the scry power added to scrying spells 6/20/08

#include <spell.h>
#include <magic.h>
#include <daemons.h>

#define SCRY_D "/daemon/ic_scry_locate_d"

inherit SPELL;

object blocker;

void create() {
    ::create();
    set_spell_name("protection from scrying");
    set_spell_level(([ "mage" : 3, "assassin" : 3, "inquisitor" : 3, "magus" : 3, "cleric" : 3 ]));
    set_spell_sphere("abjuration");
    set_domains("protection");
    set_syntax("cast CLASS protection from scrying [on TARGET]");
    set_description("The target of this spell can be a room or a person.  If cast on a person, the spell effect moves "
"with them, sweeping the areas they pass though.  If cast without a target, the effect is centered on the room and "
"remains there.\n\nBy means of this spell, the wizard blocks all scrying attempts on him/her by means of scrying spells "
"like magic mirror, or scrying objects like a crystal ball.  The spell protects against scrying attempts based on the "
"level of the person attempting the scrying as opposed to the level of the caster with an intelligence adjustment. If the "
"level of the person scrying is high enough, the scryer 'burns through' the spell and the scry is successful.  A "
"successful 'burn through' does not end this spell, and it does not alert the protected person that it has been thwarted"
".  If the protection is successful, magical feedback interferes with the scrying magic and dispels it.\n\nA scry "
"detection spell, such as 'detect scrying' or certain magical items will detect a successful scrying attempt and thus, "
"can be used in addition to this spell to see if the scry protection has been thwarted. This spell can only be cast while "
"at peace.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_peace_needed(1);
    set_components(([
      "mage" : ([ "aluminum chaff":1, "powdered chalk":1, ]),
    ]));
    set_helpful_spell(1);
}

int preSpell() {
    if (!query_arg()) {
        target = caster;
        return 1;
    }
    else
    {
        target = present(query_arg(), query_place());
    }
    return 1;
}


string query_cast_string() {
    if(target == caster && query_arg())
        return "%^BOLD%^CYAN%^"+caster->QCN+" tosses a handful of "+
            "aluminum chaff and chalk powder into the air around "+
            caster->QP+" head!";
    else if(target == (object)PLACE)
        return "%^BOLD%^CYAN%^"+caster->QCN+" tosses a handful of "+
            "aluminum chaff and chalk powder into the air!";
    else
        return "%^BOLD%^CYAN%^"+caster->QCN+" tosses a handful of "+
            "aluminum chaff and chalk powder into the air.";
}

void spell_effect(int prof) {
    int num, int_bonus,power;
    int duration;
	object temp;

    ::spell_effect();

    if(!objectp(target)) {
        tell_room(place,"%^BOLD%^RED%^"+caster->QCN+" abruptly "
            "stops casting and gets a confused look.",caster);

        tell_object(caster,"%^BOLD%^RED%^The target of your spell is not here!");
        TO->remove();
        return;
    }
	if(temp = target->query_property("block scrying")) {
		if(!objectp(temp)) {
			target->remove_property("block scrying");
		} else {
	        tell_object(caster,"%^BOLD%^RED%^There is already blocking "
    	    	"magic working for that target!");
        	TO->remove();
        	return;
        }
    }
    if(target == place)
        tell_room(place,"%^BOLD%^GREEN%^For a brief moment, the air around "+
            "you shimmers with magical static.");
    else
        tell_room(place,"%^BOLD%^GREEN%^For a brief moment, the air around "+
            target->query_short()+" shimmers with magical static.");

    target->set_property("spelled",({TO}));
    blocker = SCRY_D->add_block_scrying(target);
    if(!objectp(blocker)) {
        tell_object(caster,"%^BOLD%^RED%^Something is wrong that "
            "a wiz might want to look at!");
        dest_effect();
        return;
    }

    int_bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
    power = CLEVEL + int_bonus + random(6);
    blocker->set_block_power(power);

    duration = 6 * (int)CLEVEL * ROUND_LENGTH;
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    return;
}

void dest_effect() {
    if(objectp(target)) target->remove_property_value("spelled", ({TO}) );
    if(objectp(blocker)) blocker->self_destruct();
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
