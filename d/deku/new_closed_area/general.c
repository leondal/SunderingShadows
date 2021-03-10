#include <std.h>
#include <objects.h>
      
inherit ROOM;
      
void create() {
  room::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
  set_light(2);
   set_property("training",1);
   set_property("indoors",1);
   set_short("Orsabbas' Fine Imports");
  set_long(
@GRAY
          %^YELLOW%^Welcome to Orsabbas' Fine Imports%^RESET%^
This is the general store of Solace.  Basically you may buy all your
essentials here.  The shelves along the western wall are lined with
the stuff to fill the backpacks of all adventurers.  The store clerk
Orsabbas is prepared to take your orders to see you on your way.
GRAY
     );
     set_exits((["west":"/d/deku/new/town2"]));
      set_items(([
"shelves":"These shelves are stocked with the goods of adventure."
        ] ));
  }
void reset(){
  ::reset();
  if(!present("orsabbas")) {
    new("/d/deku/monster/orsabbas")->move(this_object());
  }
}
