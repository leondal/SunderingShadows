#include <std.h>
inherit ROOM;

void create(){
    ::create();
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_light(2);
    set_indoors(1);
    set_name("The foyer of a marble rotunda");
    set_short("%^BOLD%^%^WHITE%^The foyer of a marble rotunda%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^The foyer of a marble rotunda%^RESET%^\n"
"This large room serves as a foyer for the large rotunda that forms most of "
"this building.  Its walls are of %^BOLD%^smooth white marble%^RESET%^, with "
"the walls set into blocks so carefully that no holes or gaps are visible.  "
"Part of the room has been partitioned off to serve as a small store, "
"complete with brightly colored %^BOLD%^%^WHITE%^cryst%^CYAN%^a%^WHITE%^ls "
"%^RESET%^that have been hung from the ceiling.  The rest of the room serves "
"as a hallway allowing access to the south, where the main circular chamber "
"of the building opens up through a broad doorway.  A smaller opening leads "
"out onto the street to the north.\n\n"
"<help shop> will give you help on how to use the shop.\n");
    set_listen("default","The soft murmur of chanting voices drifts around you.");
    set_smell("default","The dry marble offers only a mild dry scent to the air.");
    set_items( ([
         ({"crystals"}) : "Beautiful %^BOLD%^cryst%^CYAN%^a%^WHITE%^ls %^RESET%^are strewn in a small, yet tasteful display, hanging from the ceiling of the room itself."
    ]) );
    set_exits(([
        "south" : "/d/attaya/seneca/portal",
        "out" : "/d/attaya/seneca/road37"
    ]) );
}

void reset(){
   ::reset();
   if(!present("mohsen")) {
      find_object_or_load("/d/attaya/seneca/mon/mohsen")->move(TO);
   }
}
