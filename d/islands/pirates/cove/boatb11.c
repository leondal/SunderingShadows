#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

void create(){
   set_monsters(({MON"bowyer"}),({1}));
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_name("Crow's nest");
   set_short("Crow's nest");
   set_long("%^BOLD%^Crow's nest%^RESET%^\n"
"From this vantage point you can see for miles in any direction, as well as every deck of the boat below.  "
"The crow's nest is a little basket-like top to the central mast, up above the ship's%^WHITE%^%^BOLD%^ "
"billowing sails%^RESET%^.  A railing runs the circuit of the %^ORANGE%^wooden boards%^RESET%^ beneath your "
"feet, to prevent any accidental falls from this height.  The only way out of here seems to be by climbing "
"down the ratlines, back onto the main deck below.\n");
   set_smell("default","You smell the clean, fresh ocean air.");
   set_listen("default","The waves of the ocean lap at the boat's sides.");
   set_items(([
     ({"boards","wooden boards","railing"}):"Wooden boards form the floor beneath your feet, which is "
"bordered around the edge by a railing, to prevent falls from this height.",
     ({"sails","mast","masts"}):"Three great %^WHITE%^%^BOLD%^sails %^RESET%^billow in the winds beneath "
"you, each supported by a thick mast that rises from the deck below.",
     "ratlines":"These ladders of rope run from the deck below up to the small crow's nest you're in.  They "
"seem to be the only way up or down."
   ]));
   set_climb_exits(([
      "descend":({COVE"boatb03",15,8,100})
   ]));
}
