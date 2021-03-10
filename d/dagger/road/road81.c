#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Road through Dagger");
    set_long(
      "You have begun walking along the south edge of the great forest of Kilkean.  The trees in this forest start small, but they grow rapidly, and by the end of their growth period, they can grow to sizes of hundreds of feet and as large around as entire city blocks.  To the far south you can barely make out the sea in the distance."
    );

    set_smell("default", "The smell of the sweat of the horses that have used this road is strong.");
    set_listen("default", "You hear your own footfalls on the stones as well as the hooves of the animals on this road");

    set_items(([
        ({ "trees","forest" }) : "It looks as if the trees here are slightly disturbed as if someone has been entering or leaving the forest.",
	"sea" : "The great blue sea is to the south.",
      ]));

    set_exits(([
	"west" : RPATH "road40",
	"northeast" : RPATH "road82",
      ]));
}

void init() {
   ::init();
   add_action("forest_fun","enter");
}

int forest_fun(string str) {
   if(!str) return 0;
   if(str != "forest" && str != "the forest" && str != "trees" && str != "the trees") return 0;
   if(!TP->query_invis()) tell_room(ETP,"%^GREEN%^"+TP->QCN+" makes "+TP->QP+" way into the forest.%^RESET%^",TP);
   tell_object(TP,"%^GREEN%^You make your way into the forest.%^RESET%^");
   TP->move_player("/d/dagger/road/elfglade/elfglade4");
   return 1;
}
