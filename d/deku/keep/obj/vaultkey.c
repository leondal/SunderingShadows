#include <std.h>

inherit OBJECT;

void create()
{
    ::create();
	
    set_name("vault key");
    set_id(({"key","gray key","vault key"}));
    set_short("gray key");
    set_long("%^BOLD%^%^WHITE%^This solid iron key is "+
    "approximately three inches long and "+
    "remarkably simple.  The head is slightly "+
    "rounded and the teeth gradually decrease in "+
    "length as they approach the opposite end.%^RESET%^");
    set_value(10);
    set_weight(1);
}

