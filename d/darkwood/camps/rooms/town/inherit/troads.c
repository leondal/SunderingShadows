#include <std.h>
#include "../../../elfisland1.h"
inherit "/std/room";

void create() {
   ::create();
   set_property("indoors", 0);
   set_property("light", 2);
   set("short", "%^BOLD%^%^YELLOW%^A village path%^RESET%^");
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
   set_smell("default", "%^RESET%^%^ORANGE%^You can smell the fresh scent of the forest.%^RESET%^");
   set_listen("default", "%^RESET%^%^CYAN%^You can hear the peaceful sounds of the village life.%^RESET%^");
   set_items( ([ 
      "trees":"The oak trees tower over you. You can see platforms sticking out of some of them.", 
      "paths":"There are several footworn paths around you, leading to different trees.",  
   ]) );
}
