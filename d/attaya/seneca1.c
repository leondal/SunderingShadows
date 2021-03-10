#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(CITY);
    set_travel(FOOT_PATH);
    set_short("Small wooden plank road.");
    set_long("You are on a small road made of %^ORANGE%^wooden planks%^RESET%^. It is covered by %^ORANGE%^blowing sands%^RESET%^. The beach lies directly south of here. A fence at the dune line separates the tiny village of Seneca from the sea. Four buildings stand against this road. The one directly north of here looks like a healers shop. It carries a medical banner.
");

     set_listen("default","The nearby ocean waves cast a rhythmic roar that seems almost soothing at this distance.");
 
    set_exits(([

       "north" : "/d/attaya/healer",
       "south" : "/d/attaya/beach17",

       "east" : "/d/attaya/seneca2",
    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "banner" : "It is the familiar banner of the cleric's profession.  It is hung in the windows and on the roofs of places where the wounded can be healed.",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
          "fence" : "It is a worn wooden fence with chipping white paint.",
          "dunes" : "They are about five feet high, and covered with sea oats.",
          "buildings" : "They appear well kept.",
        "road" : "It is coated with sand",
    ] ));
}
