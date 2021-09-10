// Protection from Scrying
// Protects from any scrying attempts on the
// target of the spell for a period dependant on
// the spell level of the caster
// Thorn@ShadowGate
// 4 January 2001

#include <spell.h>
#include <magic.h>
#include <daemons.h>
#define SCRY_D "/daemon/ic_scry_locate_d"
inherit SPELL;

object blocker;

void create() {
    ::create();
    set_spell_name("remote view trap");
    set_spell_level(([ "psion" : 6 ]));
    set_spell_sphere("clairsentience");
    set_syntax("cast CLASS remote view trap");
    set_description("When manifesting this power, the psion attunes his mind to the detection of magical and psionic "
"abilities that attempt to scry him in some form.  The power remains strong in the psion's mind, allowing him to move and "
"retain concentration on the power.\n\nShould someone attempt to scry a psion while he has this power manifested, a "
"battle of wills and strength ensues.  The psion's latent psychic energy will lash out at the one scrying him, causing "
"damage.  The struggle then continues, and if the psion wins, he immediately knows the description and general location "
"of the scryer.\n\nShould the psion's will prove more powerful than the scryer's, this power will likewise prevent the "
"viewer from observing the psion.");
    set_verbal_comp();
    set_somatic_comp();
    set_peace_needed(1);
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell() {
    if (!query_arg()) {
        target = caster;
        return 1;
    }
    target = present(query_arg(), query_place());
    return 1;
}

void spell_effect(int prof) {
    int num, int_bonus, power;
    int duration;
	object temp;

    ::spell_effect();

    if(!objectp(target)) {
        tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+" abruptly "
            "stops and looks around, confused.",caster);
        tell_object(caster,"%^BOLD%^%^RED%^The target of your power is not here!");
        TO->remove();
        return;
    }
	if(temp = target->query_property("block scrying")) {
		if(!objectp(temp)) {
			target->remove_property("block scrying");
		} else {
	        tell_object(caster,"%^BOLD%^%^RED%^There is already a blocking "
    	    	"power working for that target!");
        	TO->remove();
        	return;
        }
    }

    tell_room(place,"%^BOLD%^%^MAGENTA%^A sudden audible static "+
       "seems to surround "+caster->QCN+" before fading away!",caster);
    tell_object(caster,"%^BOLD%^%^MAGENTA%^You gather your psychic "+
       "energy, creating a static all around you!");
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
    blocker->set_psi_damager(CLEVEL);
    duration = 9 * (int)CLEVEL;
    call_out("dest_effect", duration);
    spell_successful();
    return;
}

void dest_effect() {

    if(objectp(target)) target->remove_property_value("spelled", ({TO}) );
    if(objectp(blocker)) blocker->self_destruct();
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
