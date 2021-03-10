#include <std.h>

#define TYPES ({"garter snake","ribbon snake","king snake","black snake",\
				"milk snake","pig snake","grass snake","water snake",\
				"sand snake","green snake","brown snake","tree snake",\
				"rat snake","bull snake"})
				

inherit WEAPONLESS;

void make_me();

void create(){
	::create();
	make_me();
	set_long(
@OLI
	This is a small common place snake. One of the many kinds 
you find in a garden or under a rock. Usually known to run 
whenever possible, it will, however, often give a nasty bite.
OLI
	);
	set_body_type("snake");
	set_hd(4,4);
	set_hp(20);
	set_exp(50);
	set_attack_limbs(({"mouth"}));
	set_damage(2,4);
	set_attacks_num(1);
	set_race("snake");
}

void make_me(){
	string my_id;
	int num;
	
	my_id = ({"snake"});
	num = random(sizeof(TYPES));
	my_id += ({TYPES[num]});
	set_id(my_id);
	set_name(TYPES[num]);
	set_short("A "+TYPES[num]);
	set_gender("male");
}
