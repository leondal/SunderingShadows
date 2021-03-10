#include <std.h>

inherit ROOM;

void create() {
   ::create();
   set_property("indoors", 1);
   set_property("light",0);
   set_property("no sticks",1);
   set_terrain(NAT_TUNNEL);
   set_travel(RUBBLE);
   set("short", "%^RESET%^%^ORANGE%^A tunnel between caverns%^RESET%^");
   set("long",
      "%^RESET%^%^ORANGE%^The cave walls are jagged and dangerous here.  One slip"+
      " and you could easily be badly hurt by falling on a protruding rock. "+
      " This tunnel appears to have been crudely dug or expanded to be passable"
      " for humanoids and is clearly not dwarven work."
   );
   set_listen("default", "%^RESET%^%^GREEN%^It is silent, except for the occasional screech in the nearby caves.");
   set_smell("default", "%^RESET%^%^CYAN%^The smell of rocks and dust fills your nostrils.");
   set_search("default", "There is nothing other than loose rocks scattered about the area.");
   set_items( ([
      ({"walls","ceiling","ground"}):"The cave is filled with jagged rocks that protrude from all angles of the cave"
   ]) );
}

