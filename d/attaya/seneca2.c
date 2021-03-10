#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(CITY);
    set_travel(FOOT_PATH);
    set_short("Small wooden plank road.");
    set_long("You are walking along the %^ORANGE%^wooden plank road%^RESET%^ in the village of Seneca, between a fence to the south and a building to the north. Walls of The City of Seneca can be seen to the south, behind the village, with spires peering from behind them.
A %^YELLOW%^sign%^RESET%^ hangs on a post in front of the building.
");

     set_listen("default","The nearby ocean waves cast a rhythmic roar that seems almost soothing at this distance.  Sounds of activity come from the tavern to the north.");
 
    set_exits(([

       "north" : "/d/attaya/pub",
       "west" : "/d/attaya/seneca1",

       "east" : "/d/attaya/seneca3",
    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "sign" : "%^BOLD%^%^GREEN%^The Attaya Tavern",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
          "fence" : "It is a worn wooden fence with chipping white paint.",
          "dunes" : "They are about five feet high, and covered with sea oats.",
          "buildings" : "They appear well kept.",
        "road" : "It is coated by sand",
    ] ));
}
