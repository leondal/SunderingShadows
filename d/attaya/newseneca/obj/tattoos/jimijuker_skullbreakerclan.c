#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_weight(0);
	set_ac(0);
	set_type("ring");
	set_property("death keep",1);
	set_property("no animate",1);
	set_name("tattoo");
	set_value(15000);
	set_id(({ "tattoo" }));
	set_short("A small magenta colored tattoo of a cracked skull with the word "SKULLBREAKERS GLAN" written under it on his neck");
