//~Circe~ 12/1/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit LANDING;

void create(){
   ::create();
   set_long(::query_long()+"\nBy clever design, the northern "+
      "staircase rising from the floor below is placed to "+
      "the right of the staircase leading up.\n");
   add_item("painting","The painting here has been edged in "+
      "%^YELLOW%^burnished gold %^RESET%^and shows a strange "+
      "land filled with %^CYAN%^blue-green trees %^RESET%^"+
      "surrounding a magnificent city with tall %^BOLD%^"+
      "spires%^RESET%^ with onion-shaped domes in vibrant "+
      "colors.  Birds dance upon a breeze as clouds float "+
      "lazily by.  A plaque set at the bottom of the "+
      "frame reads '%^ORANGE%^Lirremar in Spring%^RESET%^'.");
   set_exits(([
      "down" : ROOMS"psi_entry",
      "up" : ROOMS"psi_landing2",
      "west" : ROOMS"psi_meeting"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/psi_meeting","west",0,0);
   set_door_description("door","The door in the western wall has a unique shape - "+
      "instead of being simply rounded, it has an onion-shaped top that perfectly "+
      "matches the archway around it.  It is crafted of thick%^ORANGE%^pale "+
      "wood %^RESET%^that perfectly matches the %^ORANGE%^tan bands %^RESET%^"+
      "of the tower.  A thick %^ORANGE%^brass ring %^RESET%^serves as the "+
      "door handle.");
   set_pre_exit_functions(({"up","down"}),({"do_banister","do_banister"}));
}