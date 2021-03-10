#include <std.h>

inherit OBJECT;

void create()
{
    ::create();
	
    set_name("ancient chapel key");
    set_id(({"cylinder","key","ancient chapel key","ancient cylinder","metal cylinder"}));
    set_short("A small metal cylinder");
    set_long("%^BOLD%^%^BLACK%^This small cylinder is made from a fragment of metal.  It extends only some three inches in length and is strangely dull.%^RESET%^");
    set_value(50);
    set_weight(4);
}

