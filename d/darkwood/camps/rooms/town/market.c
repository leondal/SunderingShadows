#include <std.h>
#include "../../elfisland1.h"
inherit "/std/room";

void create() {
   ::create();
   set_property("indoors", 1);
   set_property("light", 2);
   set("short", "%^BOLD%^%^YELLOW%^Market%^RESET%^");
   set_terrain(VILLAGE);
set_travel(PAVED_ROAD);
   set("long",
      "%^RESET%^%^GREEN%^This large open plan building has been built from a mixture of stone and wood."+
      " The feel is very spacious here as tables and shelves are set widely apart"+
      " in between the large doorways."+
      " A range of goods are displayed in artistic arrangements on the"+
      " shelves and tables, which are made of sandal wood, around the store and"+
      " visitors are able to examine and consider their purchases at a leisurely pace.%^RESET%^"
   );
   set_smell("default", "%^RESET%^%^ORANGE%^You can smell sandalwood in the air here.%^RESET%^");
   set_listen("default", "%^RESET%^%^CYAN%^You can hear the peaceful sounds of village life outside.%^RESET%^");
   set_items( ([ 
      "tables": "The tables are spaciously set about the room with different items on them.", 
      "floor":"The floor is clean and well kept.", 
      "walls":"The walls are crafted from the tree itself.",
      "shelves":"The shelves are well stocked and placed around the room with plenty of space to observe."
   ]) );
   set_exits( ([
      "out" : TOWN+"road09",
   ]) );
}

void reset() {
string clerk;
   ::reset();
   clerk = MON+"caldur";
   if(!present("clerk")) {
   find_object_or_load(MON+"caldur")->move(TO);
   }
}
