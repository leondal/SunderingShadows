#include <std.h>

inherit OBJECT;

void create()
{
    ::create();

    set_name("shaltul key");
    set_id(({"Key","key","platinum key","shaltul key"}));
    set_short("platinum key");
    set_long("%^BOLD%^%^WHITE%^This key is approximately four "+
    "inches long and made from solid "+
    "platinum.  There is a single word engraved into the head of it.%^RESET%^");
    set_read("Shaltul");
    set_language("drow");
    set_value(300);
    set_weight(1);
}

