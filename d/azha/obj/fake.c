// A Cheap Imitation of Something
// Thorn@ShadowGate
// 970304
// Azha Area
// fake.c

#include <std.h>

inherit OBJECT;

string type = " ";

void create() {
    ::create();
    set_name("fake");
    set("id", ({ "fake", "fake object", "fakex" }) );
    set("short", "A fake");	
		set_long(
@AZHA
	In your hands is a cheap imitation object that someone just
tricked you into buying.  You get the feeling that there's a
"no return" policy at the shop you bought this from.
AZHA
	);
    set_weight(10);
    set("value", 0);
}

init()
{
	::init();
	//added to make sure these actions only work if the holder of the object is living - Saide
	//11/22/03
	if(living(ETO)) {																								
	add_action("fake", "wear");
	add_action("fake", "wield");
	add_action("fake", "check");
	add_action("fake", "drink");
	add_action("fake", "sell");
	add_action("fake", "view"); //added so the fake gems will do this as well Circe 6/4/07
	}
}

int fake()
{
	write("The imitation disintegrates like the cheap piece of garbage it is.\n");
	if(!TO->remove()) destruct(TO);
	return 1;
}

int set_type(string str)
{
	type = str;
}

string query_type() { return type; }
int is_armour() { return 1; }

