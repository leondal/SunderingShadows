#include <std.h>
#include "short.h"

inherit CITYIN;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_short("Street in Seneca");
   set_long(
@DESC
This is a street leading through Seneca. Several shops back to
this street on the west, and there is a large %^CYAN%^Restaurant%^RESET%^ to the
east. Made from cobblestone, the stone surface of the street has 
stood up to a lot of wear. The street continues to the south, 
leading to a great %^CYAN%^Coliseum%^RESET%^. 
DESC
   );
   set_items( ([
      "cobblestones" : "These are cobblestones.",
   ]) );
   set_exits( ([
      "south" : "/d/attaya/seneca/street13",
      "north" : "/d/attaya/seneca/road3",
      "east" : "/d/attaya/seneca/rest1"
   ]) );
   set_door("oaken door","/d/attaya/seneca/rest1","east",0);
   set_open("oaken door",0);
   set_door_description("oaken door", "This door is made of fine-grained "
      "golden oak.");
   "/d/attaya/seneca/rest1"->set_open("oaken door",0);
}
