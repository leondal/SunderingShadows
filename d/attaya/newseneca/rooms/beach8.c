//beach8.c - ~Circe~ 6/15/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE "beach";

void create()
{
    ::create();
    set_long(::query_long() + "The small %^ORANGE%^hut %^RESET%^stands " +
             "just northeast of here, though there does not seem to be any " +
             "entrance from the western side.  You do, however, see an " +
             "open window there along with a %^BOLD%^sign%^RESET%^.\n");
    set_exits(([
                   "west" : ROOMS "beach7",
                   "northwest" : ROOMS "beach2",
                   "north" : ROOMS "beach3",
                   "northeast" : ROOMS "beach4",
                   "east" : ROOMS "beach9",
                   "southwest" : ROOMS "shore3",
                   "south" : ROOMS "shore4",
                   "southeast" : ROOMS "shore5"
               ]));
    add_item("sign", "You cannot read the sign from here.");
}
