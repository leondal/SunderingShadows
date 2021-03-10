#include <std.h>

inherit OBJECT;

void create()
{
    ::create();
	
    set_name("siere key");
    set_id(({"Key","key","silver key","siere key"}));
    set_short("silver key");
    set_long("This key is approximately two inches long "+
    "and made from pure silver.  There is a "+
    "single word engraved into the head of it.%^RESET%^");
    set_read("Siere");
    set_language("elven");
    set_value(50);
    set_weight(1);
}

