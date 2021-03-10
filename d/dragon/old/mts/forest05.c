#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Northern pines");
    set_long("%^BLUE%^%^BOLD%^
The trail has reached a three-way intersection in a small clearing
among the towering pines.  One trail heads off to the east while the
main path runs north and southwest.  It is very peaceful here, although
it's become somewhat chilly.  Through the clearing in the trees, you 
notice that the cold, gray sky threatens more snow.
    ");
    set_exits(([
       "north" : "/d/dragon/mts/forest07",
      "east" : "/d/dragon/mts/forest06",
       "southwest" : "/d/dragon/mts/forest04"
    ] ));
     set_listen("default","It is still and quiet here among the trees.");
    set_items(([
       "path":"A small path through the huge trees of the northern pine.",
       "forest":"The northern pines.  It is not a very well traveled place."
    ] ));
}
