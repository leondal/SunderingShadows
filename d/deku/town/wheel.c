#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
  set_terrain(WOOD_BUILDING);
  set_travel(DIRT_ROAD);
    set_short("%^ORANGE%^%^BOLD%^W%^RESET%^%^ORANGE%^heelwright %^BOLD%^S%^RESET%^%^ORANGE%^hop");
    set_long(
"%^ORANGE%^%^BOLD%^W%^RESET%^%^ORANGE%^heelwright %^BOLD%^S%^RESET%^%^ORANGE%^hop
When you enter this building, you realize you have obviously stumbled upon a wheel and wagon making workshop. Wagon wheels on pivots line the walls. In one corner of the cottage lies the partially constructed base of a wagon chassis. The center of the work area contains a large forge, which is now cold.
"
    );
    set_exits(([
       "north" : "/d/deku/town/road6"
    ] ));
}
