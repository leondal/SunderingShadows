// inner cathedral default

#include <std.h>
#include "../inherit/ruins.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","The faint scent of incense still lingers here.");
    set_listen("default","Thick silence hangs in the air around you.");
    set_items(([
      "floor" : "%^CYAN%^The perfectly-formed floor beneath your feet consists of %^WHITE%^milky marble "
"stone%^CYAN%^, lined with tiny veins of sparkling %^ORANGE%^gold%^CYAN%^.%^RESET%^",
      "walls" : "%^CYAN%^The walls around you are a slightly-darker shade, slightly contrasting to the "
"floor.  They are made of similar marble, again with tiny veins of %^ORANGE%^gold%^CYAN%^ "
"throughout.%^RESET%^",
      ({"lights","candles"}) : "%^CYAN%^Lining the walls are small holsters, each containing a single "
"burning candle to light the inner sanctum.  Strangely enough, no matter how long you watch the candles, "
"they never burn low.%^RESET%^",
      "roof" : "%^CYAN%^High gothic arches cross the roof above you, which is patterened in elaborate "
"mosaic tiles.  They look almost untouched by age.%^RESET%^",
    ]));
}
