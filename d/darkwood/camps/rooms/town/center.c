#include <std.h>
#include "../../elfisland1.h"
inherit "/std/room";

void create() {
   ::create();
   set_property("indoors", 0);
   set_property("light", 2);
   set_property("night light",1);
   set("short", "%^BOLD%^%^YELLOW%^Central Square%^RESET%^");
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
   set("long",
      "%^RESET%^%^GREEN%^You are standing in a large clearing in the midst of a lush forest."+
      " Buildings surround you on a number of different levels."+
      " The clearing extends to the west and leads into a seating area before a large pond."+
      " A range of shops open out onto this square. To the north you can see the sign of an"+
      " apothecary near a path that leads up to a tree.%^RESET%^"
   );
   set_smell("default", "%^RESET%^%^ORANGE%^You can smell the fresh scent of the forest.%^RESET%^");
   set_listen("default", "%^RESET%^%^CYAN%^You can hear the peaceful sounds of the village life.%^RESET%^");
   set_items( ([ 
      "clearing": "This clearing acts as a central square of the village.", 
      "sign":"The sign reads: %^RESET%^%^ORANGE%^Town healer.%^RESET%^", 
      "trees":"The tall standing oak trees here serve as buildings grown to serve the elves. You can see platforms sticking out of many of the oaks." 
   ]) );
   set_exits( ([
      "east" : TOWN+"road03",
      "south" : TOWN+"road05",
      "north" : TOWN+"road04",
      "west" : TOWN+"road07",
      "northwest" : TOWN+"road08",
      "southwest" : TOWN+"road10",
   ]) );
}
