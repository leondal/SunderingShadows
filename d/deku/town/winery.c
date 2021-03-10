#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
  set_terrain(WOOD_BUILDING);
  set_travel(DIRT_ROAD);
    set_short("%^BLUE%^BOLD%^W%^RESET%^%^BLUE%^inery %^BOLD%^S%^RESET%^%^BLUE%^torehouse");
    set_long(
"%^BLUE%^BOLD%^W%^RESET%^%^BLUE%^inery %^BOLD%^S%^RESET%^%^BLUE%^torehouse
%^ORANGE%^This abandoned building used to be a winery. Number of ancient empty kegs and barrels are packed in rows alongside the walls. There is a counter, now dusty and dry, in the middle A %^BOLD%^sign%^RESET%^%^ORANGE%^ hangs on the western wall."
    );
    set_exits(([
       "east" : "/d/deku/town/road9"
    ] ));
    set_items(([
        "sign":"Opening soon, on Springstime 1st, 664! Verbobone Winery, the only place that you can buy different types of kegs."
    ] ));
}
