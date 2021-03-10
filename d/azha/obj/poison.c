/*poison.c*/

#include <std.h>

inherit OBJECT;

int strength = 10;

void create(){
	::create();
	
	set_name("poison");
	set_id(({"poisonStuff","poison","vial",}));
	
	set_short("Small vial of poison");
	set_long(
@OLI
	This is a small vial of poison. It is hard to tell how strong it
is. The brown liquid is obviously made from some concotion of vile stuff.
OLI
	);
	set_weight(2);
	set_value(strength);
}

void set_strength(int x){ strength = x;}

int query_strength() {return strength;}
