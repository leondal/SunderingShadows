#include <std.h>

inherit ROOM;

void create() {
  ::create();
    set_property("light", 3);
    set_property("night light", 2);
    set_property("no castle", 1);
    set("short", "Centre Path just south of Krasna Square");
    set("long",
      "A small alley crosses Centre Path here just south of Krasna Square.  "
      "As it winds on south, Centre Path travels through the business "
      "center of South Praxis up to the Port of Praxis.");
    set_exits( 
	      (["north" : "/d/standard/s_centre1",
		"south" : "/d/standard/s_centre3",
		"east" : "/d/standard/yard",
		"west" : "/d/standard/alley1"]) );
    set_items(
      ([({ "path", "road", "centre path" }) : "Centre Path leads to "
	  "Monument Square north and to the port south.",
	"alley" : "It opens up to a yard of houses east, and a post "
	  "and bank west."]) );
}

