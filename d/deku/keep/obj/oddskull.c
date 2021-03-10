#include <std.h>

inherit OBJECT;

void create()
{
    ::create();
	
    set_name("odd skull");
    set_id(({"skull","odd"}));
    set_short("%^BOLD%^%^WHITE%^oddly shaped skull%^RESET%^");
    set_long("This is an average humanoid sized skull, "+
    "though it is obviously not the skull of a "+
    "common humanoid.  It is almost completely rounded "+
    "and closer to %^BOLD%^%^WHITE%^silver"+
    "%^RESET%^ in color than to white.");
    set_value(50);
    set_weight(5);
}

