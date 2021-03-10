//~Circe~ 12/1/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit LANDING;

void create(){
   ::create();
   set_long(::query_long()+"\nThe archway to the west features a "+
      "%^BOLD%^cream colored curtain %^RESET%^rather than a door, "+
      "likely to allow people to enter the room quietly while "+
      "still giving some measure of solitude.\n");
   add_item("painting","Unlike the other paintings in the tower, "+
      "this one seems to have little to do with psionics.  It is "+
      "framed in unpainted wood and shows a serene image of a wide "+
      "%^CYAN%^river %^RESET%^flowing through dense %^GREEN%^jungle"+
      "%^RESET%^.  Just above center, the river cascades over a "+
      "series of %^ORANGE%^rocks%^RESET%^, creating a stunning "+
      "%^BOLD%^%^BLUE%^waterfall%^RESET%^.  The artist has captured "+
      "the myriad %^BOLD%^%^RED%^r%^RESET%^%^ORANGE%^a%^YELLOW%^i"+
      "%^GREEN%^n%^CYAN%^b%^BLUE%^o%^RESET%^%^BLUE%^w%^MAGENTA%^s "+
      "%^RESET%^created in the %^CYAN%^mist%^RESET%^.  The plaque "+
      "at the base of the portait reads, '%^ORANGE%^Attaya "+
      "Unblemished%^RESET%^'.");
   set_exits(([
      "down" : ROOMS"psi_landing5",
      "up" : ROOMS"psi_roof",
      "west" : ROOMS"psi_meditation"
   ]));
   set_door("curtain","/d/attaya/newseneca/rooms/psi_meditation","west",0,"tie");
   set_door_description("curtain","The curtain is soft and cream "+
      "colored, offering only a small amount of privacy to the room beyond.");
   set_lock_description("curtain","tie","This is a simple tie to help hold the curtain closed.");
   set_pre_exit_functions(({"down"}),({"do_banister"}));
   set_door("trapdoor","/d/attaya/newseneca/rooms/psi_roof","up",0,0);
   set_door_description("trapdoor","At the top of the staircase is a small "+
      "trapdoor, which may be raised to access the roof.");
}