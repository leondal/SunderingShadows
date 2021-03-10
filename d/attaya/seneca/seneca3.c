#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(CITY);
    set_travel(FOOT_PATH);
    set_name("Intersection on the island");
    set_short("Intersection on the island");
    set_long(
      "A tall building that seems to belong to a time long before "+
      "the others stands to the north.  Its ancient granite walls "+
      "and towers still give a feeling of majesty even in this "+
      "rundown state.  Wicked looking gargoyles peer down at you "+
      "from far above.\n\n"+
      "A bridge to the south rises up over the beach and leads to "+
      "the boardwalk and on to the city of Seneca.\n"
    );
    set_listen("default","The nearby ocean waves cast a rhythmic roar that seems almost soothing at this distance.");
    set_smell("default","The clean scent of the ocean rises on the breeze.");
    set_exits(([
	"north" : "/d/attaya/seneca7",
//	"bridge" : "/d/attaya/seneca/boardwalk1",
//altered 1/10/09 by ~Circe~ for new Seneca
      "south" : "/d/attaya/newseneca/rooms/boardwalk1",
	"west" : "/d/attaya/seneca2",
	"east" : "/d/attaya/seneca4"
      ] ));
set_items(([
    "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
    "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
    "fence" : "It is a worn wooden fence with chipping white paint.",
    "building" : "It appears to be an ancient library.",
    "gargoyles" : "They are in much better condition than much of the building.  They give you the creeps.",
    "dunes" : "They are about five feet high, and covered with sea oats.",
    "buildings" : "They appear well kept.",
    "street" : "It is coated by sand",
  ] ));
}
