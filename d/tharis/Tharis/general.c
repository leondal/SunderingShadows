#include <std.h>
#include "../tharis.h"
      
inherit VAULT;
      
void create() {
   ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
   set_light(2);
   set_indoors(1);
   set_short("This is one of the general stores in Tharis");
   set_long(
@OLI
	This is a general store, basically you may buy all your 
essentials here.  The shelves are lined with the stuff to fill the
backpacks of all adventurers.  The store clerk, Cath, is prepared 
to take your orders to send you on your way.
OLI
     );
   set_smell("default","The room is filled with mingled smells of leather and other goods.");
   set_listen("default","The sounds of stocking shelves and friendly chatter prevail here. ");
   set_exits(([
	      "door":ROOMS"side1",
      ]));
   set_items(([
	      "shelves":"These shelves are stocked with the goods of adventure.",
	      "door":"This is a door that can be opened and closed.",
      ] ));

   set_door("door",ROOMS"side1","door","blah");

}



void reset(){
   ::reset();
   if(!present("Cath"))
     find_object_or_load("/d/tharis/monsters/Cath")->move(TO);
}
