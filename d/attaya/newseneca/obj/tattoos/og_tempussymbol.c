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
	set_value(30000);
	set_id(({ "tattoo", " tempus symbol", " flaming sword", " red shield", " flame shield", " huge tattoo", " tempus symbol tattoo", " back tattoo" }));
	set_short("huge back tattoo of Tempus symbol");
