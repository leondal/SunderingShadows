#include <std.h>
inherit OBJECT;

void create()
{
	::create();
	set_name("flower");
	set_id(({"flower","lovely flower","beautiful flower"}));
	set_short("A flower");
	set_long(
	"The flower is very beautiful, yet there is a solemn quality to it, a"+
	" feeling that seems to hang in the air. It is so lovely, but has been"+
	" picked in the prime of its life. Some sap still drips from the stem"+
	" like %^RED%^blood%^RESET%^ or %^BLUE%^tears%^RESET%^."
	);
	set_weight(3);
	set_value(20);
	set_cointype("copper");
}

void save_me(string file) { return 1; }
