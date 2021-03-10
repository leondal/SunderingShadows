#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_name("Vexia's lair");
    set_short("Vexia's Lair");
    set_items(([
    ({"brackets", "torches"}): "Vexia and her minions must not like much light.  "
      "Although there are several torches hanging on the walls, only one of them "
      "is usually burning at a time."    
    ] ));
    set_smell("default","You catch a faint scent of something musty or maybe "
       "even rancid.");
    set_listen("default","Muffled, foreboding sounds echo through the chambers.");
}

void reset() {
  ::reset();
}
