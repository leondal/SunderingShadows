// by Styx 5/2003

#include <std.h>
#define FERRYOBJ1 "/d/shadow/virtual/river/obj/riverferry2"
#define FERRYOBJ2 "/d/shadow/virtual/river/obj/riverferry3"
inherit "/d/shadow/virtual/river/river_dock";


void create() {
 object ob;
 ::create();
  set_indoors(0);
  set_terrain(BARREN);
  set_travel(FOOT_PATH);
  set_light(2);
  set_property("night light", 2);
  set_name("Ferry dock at Tabor");
  set_short("Ferry dock at Tabor");
  set_long("%^YELLOW%^Tabor's Ferry Dock%^RESET%^\n"
	"This is a short pier that leads from the river bank to "
	"where the ferries dock and allow passengers to board.  "
	"Local citizens come and go as they use the ferries to "
	"travel north or to the ocean or to ship and receive goods.  "
	"The water flows lazily past on this section of the river, "
	"although it is murky from the disturbance of the ferries "
	"coming and going.\n"
  );
   set("night long", TO->query_long()+"\n%^YELLOW%^Lanterns hang along the pier lighting it well for the travelers.");
   set_exits(([ "east":"/d/darkwood/tabor/road/road2"  ]));
   set_smell("default","You occasionally catch a whiff of smoke from cooking or heating in the city.");
   set_listen("default","You hear the other travelers in various discussions.");
   find_object_or_load("/d/shadow/virtual/river/shadow.dock");
   if(!objectp(FERRYOBJ1)) {
      ob = find_object_or_load(FERRYOBJ1);
      ob->set_dir("shadow");
      ob->move(TO);
   }
   if(!objectp(FERRYOBJ2)) {
      ob = find_object_or_load(FERRYOBJ2);
      ob->set_dir("tharis");
      ob->move(TO);
   }
}
