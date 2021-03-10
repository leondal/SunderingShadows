#include <std.h>
#include "../dragon.h";

inherit BTOWER;

void create() {
   ::create();
   set_long(
      "%^RESET%^%^ORANGE%^The dominating object in this room is a"+
      " massive oak conference table that is surrounded"+
      " by ten leather chairs. Tapestries line the walls"+
      " around the room and a soft magical light dimly"+
      " lights this room. One chair in particular at the"+
      " end of the table looks to be larger than the others"+
      " most likely belonging to the head of this place. A"+
      " statue sits in the corner of the room, looking over"+
      " the table and the rest of the conferance room."
   );
   set_items( ([
      "table" : "This massive oak table is finely crafted and has a smooth surface.",
      "tapestries" : "The tapestries depict various scenes in them. Most of them show what look to be mage battles of epic proportions.",
      "statue" : "The statue is of a precarious looking human male wearing long flowing robes.",
   ]) );
   set_exits( ([
      "east" : TOWER+"lobby",
   ]) );
}

void reset() {
   ::reset();
   if(!present("apprentice")) {
      new(MON+"apprentice")->move(TO);
      new(MON+"apprentice")->move(TO);
   }
}
