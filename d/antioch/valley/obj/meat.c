#include <std.h>
#include "../valley.h"
inherit "/std/food.c";

void create()
{
	::create();
	set_name("meat");
	set_id( ({"meat", "food"}) );
	set_short("Meat");
	set_weight(1);
	set_poison(0);
	set_strength(15);
	set_value(0);
	set_destroy();
	set_long(
	"This is a big chunk of some type of meat."
	);
	set_my_mess("You devour the meat.");
	set_your_mess("devours the meat.");
}

int eat(string str)
{
	if((string)TP->query_race() != "ogre") {
	write("Only ogres would eat something so disgusting!");
	return 1;
	}
	::eat(str);
	return 1;
}
