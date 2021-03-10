#include <std.h>
inherit "/std/food";

void create()
{
	::create();
	set_name("berries");
	set_id(({"berries","handful of berries"}));
	set_short("A handful of berries");
	set_long(
	"This is a handful of juicy berries. They have a fruity smell to them"+
	" and look like they'll dissolve in your mouth."
	);
	set_weight(1);
	set_value(0);
	set_destroy();
	set_poison(0);
	set_strength(20);
	set_my_mess("You eat the handful of tastey berries and are somehow"+
	" quite filled by them.");
	set_your_mess("eats a handful of berries.");
}
