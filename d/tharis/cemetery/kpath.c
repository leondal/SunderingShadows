//path for Kelemvor's graveyard.  Circe 11/22/04
#include <std.h>
#include "../kelemvor.h"

inherit ROOM;

void create(){
   ::create();
   set_name("A narrow pathway");
   set_short("%^ORANGE%^A narrow pathway%^RESET%^");
   set_terrain(CEMETERY);
   set_travel(FOOT_PATH);
   set_long((:TO,"long_desc":));
   set_smell("default","The strong earthy scent of the cemetery "+
      "pervades the air.");
   set_listen("default","A serene silence rises on the wind.");
   set_items(([
      ({"grasses","grass"}) : "%^BOLD%^%^GREEN%^The grass on the rise "+
         "is kept cut low, neatly covering the final resting "+
         "place of so many people.  It is soft and a verdant "+
         "green, even in the midst of winter.",
      ({"wall","stone wall","ivy"}) : "The low stone wall is "+
         "clearly meant to mark the boundary of the hallowed "+
         "ground, rather than serve as a barrier.  The plentiful "+
         "ivy gives the wall a quaint appearance.",
      ({"headstones","headstones"}) : "The carved headstones are "+
         "made of many materials - the wealthy seem to favor "+
         "marble, while some are even carved on blocks of wood.",
      ({"path","pathway","road"}) : "This dirt "+
         "pathway is lined with large river stones and it moves toward "+
         "the busier road.  There, travelers to and from the cities "+
         "of Tharis, Azha, and Tabor can be seen."
   ]));
   set_exits(([
      "north" : KEXIT"cemetery2",
      "south" : "/d/tharis/road/wroad25"
   ]));
}

string long_desc(){
   return("This narrow %^ORANGE%^pathway %^RESET%^is simply made "+
      "of dirt that has been lined with well-worn %^BOLD%^river "+
      "stones%^RESET%^.  The path leads over a small %^GREEN%^"+
      "rise %^RESET%^to a flat area just above.  There, you can "+
      "see many %^BOLD%^tombstones %^RESET%^within a well-tended "+
      "%^GREEN%^field %^RESET%^bordered by a low %^BOLD%^stone "+
      "wall %^RESET%^covered with ancient %^GREEN%^ivy%^RESET%^.  "+
      "To the south, the pathway stretches back to the main road "+
      "between Tharis and the Azha empire.\n");
}