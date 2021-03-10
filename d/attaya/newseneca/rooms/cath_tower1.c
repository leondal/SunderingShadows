//cath_tower1 - bell tower's base for new Seneca
//~Circe~ 1/14/08
#include <std.h>
#include "../seneca.h"

inherit STORAGE"cath_tower";

void create(){
   ::create();
   set_long(::query_long()+"\nThis small room is at the base of "+
      "the tower, and the %^ORANGE%^stairs %^RESET%^begin "+
      "here.  To the west, you see a %^ORANGE%^wooden doorway "+
      "%^RESET%^that leads into the %^BOLD%^vestry%^RESET%^.\n");
   set_exits(([
      "west" : ROOMS"cath_vestry",
      "up" : ROOMS"cath_tower2"
   ]));
   set_door("tower door","/d/attaya/newseneca/rooms/cath_vestry","west",0);
   set_door_description("tower door","%^ORANGE%^The simple oaken door "+
      "to the west is stained a deep brown.  It is set with "+
      "burnished %^BOLD%^brass hinges %^RESET%^%^ORANGE%^and "+
      "a matching %^BOLD%^handle%^RESET%^%^ORANGE%^.%^RESET%^");
}