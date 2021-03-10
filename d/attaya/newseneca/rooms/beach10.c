//beach9.c - ~Circe~ 6/15/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE"beach";

void create(){
   ::create();
/*
   set_long(::query_long()+"The small %^ORANGE%^hut %^RESET%^stands "+
      "just north of here, with a narrow doorway leading inside.\n");
Return this description when the hut goes live
*/
   set_long(::query_long()+"The small %^ORANGE%^hut %^RESET%^stands "+
      "just north of here, with a narrow doorway leading inside.  It "+
      "seems to still be undergoing construction at the moment.\n");
   add_item("hut","The hut is crafted from weathered wood left in "+
      "its natural hue.  The roof is made from woven leaves, which "+
      "have aged to be the same color as the building now.  A "+
      "doorway to the north allows access to the interior of the hut.");
   set_exits(([
      "west" : ROOMS"beach9",
      "northwest" : ROOMS"beach4",
//      "north" : ROOMS"hut",
      "east" : ROOMS"beach11",
      "southwest" : ROOMS"shore5",
      "south" : ROOMS"shore6",
      "southeast" : ROOMS"shore7"
   ]));
/*
   set_door("door","/d/attaya/newseneca/rooms/hut","north",0);
   set_door_description("door","%^RESET%^%^ORANGE%^Weathered and "+
      "worn by the wind and sand, the door has clearly seen "+
      "better days.  It is made of roughly hewn planks and seems "+
      "to do its job, however.%^RESET%^");
*/
}