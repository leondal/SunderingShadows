//vil9.c
#include <std.h>
#include "../../kildare.h"

inherit ROOM;

void create()
{
   ::create();
   set_indoors(1);
   set_property("no sticks",1);
   set_property("light",1);
   set_terrain(BUILT_TUNNEL);
   set_travel(DIRT_ROAD);
   set_short("A Cavern");
   set_long(
@CIRCE
%^BOLD%^%^BLACK%^A Storage Cavern
%^RESET%^%^ORANGE%^The narrow tunnel leads into a fairly large cavern.  The 
air seems much cooler within the mountain here.  Hanging from 
wooden pegs in the wall are large slabs of meat, presumably 
kept longer from being in this cold air.  On one part of the 
wall, strips of dried and cured meat are kept in baskets on 
the floor.  This cavern was apparently hollowed out to keep 
the village's stores of meat year round.
CIRCE
   );
   set_items(([
      (({"stone","cavern","room","cave"})) : "The dark gray stone "+
      "of the surrounding mountainside has been hollowed "+
      "out for this round cavern.  The walls are relatively "+
      "smooth and seem well-formed.",
      (({"meat","meats","pegs"})) : "Large slabs of meat hang "+
      "from the pegs on the wall here.  Dried red streaks can "+
      "be seen beneath many of them, though they all seem fairly "+
      "dry now.",
      (({"dried meat","cured meat","baskets"})) :  "The strips of "+
      "meat in the baskets are rather thin and seem tough.  They "+
      "smell strongly of salt and spices, and it seems they would "+
      "keep for quite a long time out in the wilderness."
      ]));
   set_smell("default","You smell a strong scent of herbs and spices.");
   set_listen("default","You hear muffled sounds of movement from "+
      "the building.");

   set_exits(([
      "north" : TROOMS"vil8"
      ]));
}
