// Shocking Grasp object
// Thorn@ShadowGate
// Simulates the action of a shocking grasp
// on a target
// 7/2/95

#include <std.h>
#include <rooms.h>

inherit WEAPON;

int attack_shock(object target);
int shock(string str);
int dismiss(string str);
void dispel();

create() {
	::create();
	set_id(({ "graspx" }));
	set_name("shocking grasp");
	set_weight(0);
	set_value(0);
	set_type("blade");
	set_wield_string("Your hands crackle with electric energy.\n");
	set_hit((:this_object(), "attack_shock":));
	set_unwield("Your charge disperses.");
}

init() {
	::init();
	add_action("shock", "shock");
	add_action("dismiss", "dismiss");
	environment(TO)->force_me("wield graspx");
}

int shock(string str) {
	object target;
	if(!str) {
		write("Shock who?\n");
		return 1;
	}
	target = present(str, environment(TP));
	if(!interactive(target)) {
		write("That is not living!\n");
		return 1;
	}
	TP->kill_ob(target);
	return 1;
}

int dismiss(string str) {
	if(!str) return 0;
	if(str == "shocking grasp") {
		TO->remove();
		tell_object(TP, "You dismiss your shocking grasp spell.\n");
		tell_room(environment(TP), "You see some electricity discharge from "+
		TP->query_cap_name()+" harmlessly.\n");
		dispel();
	}
	else return 0;
}

void dispel() {
        TO->move(ROOM_VOID);
	TO->remove();
}

int attack_shock(object target) {
	int formula, clevel;
	
	clevel = TP->query_guild_level("mage");
	formula = roll_dice(1,8) + clevel;
	tell_object(target, "A shock courses from the caster's hand through "+
	"your body!");
	tell_object(TP, "You discharge your shocking grasp on "+
	target->query_cap_name()+".\n");
	dispel();
	return formula;
}

		
	
