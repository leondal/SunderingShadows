#include <spell.h>
#include <magic.h>
#include <daemons.h>

#define SCRY_D "/daemon/ic_scry_locate_d"

inherit SPELL;

object detector;

void create() {
    ::create();
    set_spell_name("detect remote viewing");
    set_spell_level(([ "psion" : 4, "psywarrior" : 3 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS detect remote viewing");
    set_description("When manifesting this power, the psion attunes his mind to the detection of magical and psionic "
"abilities that attempt to scry him in some form.  The power remains strong in the psion's mind, allowing him to move and "
"retain concentration on the power.\n\nShould someone attempt to scry a psion while he has this power manifested, a "
"battle of wills and strength ensues.  If the psion wins, he immediately knows the description and general location of "
"the scryer.\n\nManifesting this power will not offer any protection from scrying at all, so the psion will have to use "
"another power or item to block the scrying that is taking place.");
    set_verbal_comp();
    set_somatic_comp();
    set_peace_needed(1);
	set_helpful_spell(1);
}

string query_cast_string() {
   return "%^GREEN%^"+caster->QCN+" balances a spherical reflective "+
      "hematite atop a thin sliver of lapiz lazuli.%^RESET%^";
}

void spell_effect(int prof) {
    int num, bonus, power;
    int duration;
    object temp;

    ::spell_effect();

	if(temp = caster->query_property("detect scrying")) {
		if(!objectp(temp)) {
			caster->remove_property("detect scrying");
		} else {
	        tell_object(caster,"%^BOLD%^RED%^You are already detecting "
    	    	"viewing attempts!");
            if(objectp(TO)) TO->remove();
        	return;
        }
    }
    tell_room(place,"%^BOLD%^GREEN%^The hematite melts away as the "+
       "air around "+caster->QCN+" seems to shiver!",caster);
    tell_object(caster,"%^GREEN%^You balance a sphere of "+
       "reflective hematite atop a thin sliver of lapiz lazuli and "+
       "concentrate carefully.");
    tell_object(caster,"%^BOLD%^%^GREEN%^The hematite melts away "+
       "as the air around you thickens and shivers!");
    spell_successful();
    caster->set_property("spelled",({TO}));
    bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
    power = clevel + bonus + random(6);
    detector = SCRY_D->add_detect_scrying(caster);
    if(!objectp(detector)) {
        tell_object(caster,"%^BOLD%^RED%^Something is wrong that "
                "a wiz might want to look at!");
        dest_effect();
        return;
    }
    detector->set_detect_power(power);
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 8;
    set_end_time();
    call_out("dest_effect",spell_duration);
    return;
}

void dest_effect() {

    if(objectp(caster)) caster->remove_property_value("spelled", ({TO}) );
    if(objectp(detector)) detector->self_destruct();
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
