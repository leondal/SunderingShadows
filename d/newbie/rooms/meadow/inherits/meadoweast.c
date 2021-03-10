//meadow.c - inherited room for meadow with rats, snakes, wild dogs 
#include <std.h>
#include "../meadow.h"
inherit MEADOWI"meadow";

void create()
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^GREEN%^  A thick and forboding %^RESET%^%^GREEN%^forest%^BOLD%^ "+
    "encroaches upon the meadow from the east.%^RESET%^");
    add_item(({"forest", "thick forest"}),"%^RESET%^%^GREEN%^This thick and forboding forest looks "+
    "completely impassable from here.%^RESET%^");
}
