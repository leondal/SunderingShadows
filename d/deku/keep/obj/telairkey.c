#include <std.h>

inherit OBJECT;

void create()
{
    ::create();
    set_name("telair key");
    set_id(({"Key","key","gold key","telair key"}));
    set_short("gold key");
    set_long("%^BOLD%^%^YELLOW%^This key is approximately three "+
    "inches long and made from solid "+
    "gold.  There is a single word engraved into the head of it.%^RESET%^");
    set_read("Telair");
    set_language("giant");
    set_value(100);
    set_weight(1);
}

