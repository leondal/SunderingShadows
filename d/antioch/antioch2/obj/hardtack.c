#include <std.h>
inherit "/std/food.c";

void create()
{
	::create();
	set_name("hard tack");
	set_short("A loaf of hard tack");
	set_id(({"loaf","bread","hard tack","hardtack","loaf of hard tack","food"}));
	set_long(
	"This is a loaf of hard tack.  It was aptly named, being very hard.  It"+
	" will keep a long time as it almost never goes bad.  It is also quite"+
	" filling if you can stand to eat it."
	);
	set_weight(5);
	set_value(15);
	set_poison(0);
	set_destroy();
	set_canSave(1);
   set_strength(50);
	set_my_mess("Hard tack has to be some of the nastiest bread you've ever"+
	" eaten, but it is filling.");
	set_your_mess("bolts down a loaf of hard tack.");
}
