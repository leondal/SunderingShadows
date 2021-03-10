#include <std.h>
#include "../antioch.h"
inherit "/std/food.c";

void create()
{
	::create();
   set_name("jerky");
   set_short("Strips of jerky");
   set_id(({"jerky","strips of jerky","jerky strips","food"}));
	set_long(
   "%^ORANGE%^Strips of some kind of meat have been cured beneath the sun, making them hard"+
   " and well preserved, as well as salty.  They have been seasoned with a few"+
   " spices that make it more flavorful but almost impossible to tell what kind of"+
   " meat this originally was.  It still has lots of protein and would last for a long journey."
	);
	set_weight(4);
   set_strength(25);
	set_destroy();
	set_poison(0);
	set_value(15);
	set_canSave(1);
   set_my_mess("You chew through the tough strips of salty meat.");
   set_your_mess("slowly chews through the tough strips of meat.");
}
