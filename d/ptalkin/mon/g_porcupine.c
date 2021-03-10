
//monsters by the House of Svaha

#include <std.h>

inherit WEAPONLESS;

void create(){
::create();

set_name("giant porcupine");
set_id(({"giant porcupine", "porcupine"}));
set_short("giant porcupine");
set_long(
@DESC
The giant porcupine is rather stupid and non-aggressive, but will defend 
itself when the need arises.  It's main defense is that is has three
inch long barbed quills.   They could hurt.
DESC
);
set_race("porcupine");
set_body_type("quadruped");
set_gender("female");
set_class("fighter");
set_level(5);
set("aggressive", 1);
set_size(2);

set_stats("strength", 10);
set_stats("intelligence", 5);
set_stats("wisdom", 5);
set_stats("dexterity", 11);
set_stats("charisma", 5);

set_overall_ac(5);

set_hd(6,6);
set_hp(75);

set_attacks_num(5);
set_attack_limbs(({"quills"}));
set_hit_funcs((["quills":(:TO,"poison":)]));
set_base_damage_type("piercing");

}

int poison(object targ) {
	tell_object(targ,"The quills sting as they strike your body!\n");
	if("daemon/saving_d"->saving_throw(targ, "paralyzation_poison_death",2))
	return 0;
	tell_player(targ,"You feel a little weak from the poison on the barbed quills.");
	targ->add_poisoning(5);
	return 10;

set("aggressive","attack_run");
set_emotes(20, ({
"%^RED%^The quills fly off of the giant porcupine and stick into you, painfully"}), 1);
}
