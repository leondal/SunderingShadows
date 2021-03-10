#include <std.h>
#include "short.h"

inherit CITYIN;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_short("North Road in Seneca");
   set_long(
@DESC
This is the North Road that leads around the edge of the 
city of Seneca. Made from cobblestone, the stone surface 
of the street has stood up to a lot of wear. The entrance
to a large %^CYAN%^Restaurant%^RESET%^ is to the south.  A sign on
the heavy panel door welcomes you.
DESC
   );
   set_items( ([
      "door" : "This door is made of fine-grained golden oak and has "
      "eight inset carved panels.  The top four panels "
      "depict various scenes of the jungle and the lower four of the beach "
      "and cliffs.",
      "sign" : "The sign reads '%^CYAN%^W E L C O M E%^RESET%^'."
   ]) );
   set_exits( ([
      "west" : "/d/attaya/seneca/road3",
      "east" : "/d/attaya/seneca/road5",
      "south" : "/d/attaya/seneca/rest1"
   ]) );
   set_door("panel door","/d/attaya/seneca/rest1","south",0);
   set_open("panel door",0);
   set_door_description("panel door", "This door is made of fine-grained "
      "golden oak and has eight inset carved panels.  The top four panels "
      "depict various scenes of the jungle and the lower four of the beach "
      "and cliffs.");
   "/d/attaya/seneca/rest1"->set_open("panel door",0);

}
