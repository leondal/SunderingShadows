#include <std.h>
inherit OBJECT;

void create()
{
	::create();
	set_name("withered flower");
	set_id(({"flower","withered flower"}));
	set_short("A withered flower");
	set_long(
	"This is a pitiful looking withered flower. Its petals are droopy and it"+
	" is bruised in several places, the stem is even beginning to blacken. It"+
	" has been withered to a stalk."
	);
	set_weight(2);
	set_value(0);
}

void save_me(string file) { return 1; }
