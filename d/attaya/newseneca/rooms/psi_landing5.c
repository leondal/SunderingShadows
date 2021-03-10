//~Circe~ 12/1/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit LANDING;

void create(){
   ::create();
   add_item("painting","The rectangular painting on the eastern "+
      "wall has a simple %^ORANGE%^wooden frame %^RESET%^that "+
      "contrasts sharply with the fantastic image depicted.  "+
      "The scene is of an %^CYAN%^ocean %^RESET%^at %^RED%^"+
      "su%^ORANGE%^ns%^YELLOW%^et%^RESET%^, but the true focal "+
      "point is the half dozen %^ORANGE%^skyships %^RESET%^"+
      "rising into the air in the foreground.  Amazing creations, "+
      "the skyships seem to be traditional galleons and caravels "+
      "with billowing sails that are lifting from the water to "+
      "float on the air.  A plaque on the top of the frame reads, "+
      "'%^ORANGE%^Skyships over Porrenath%^RESET%^'");
   set_exits(([
      "down" : ROOMS"psi_landing4",
      "up" : ROOMS"psi_landing6",
      "west" : ROOMS"psi_workroom"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/wstreet34","west",0,0);
   set_door_description("door","The door in the western wall has a unique shape - "+
      "instead of being simply rounded, it has an onion-shaped top that perfectly "+
      "matches the archway around it.  It is crafted of thick %^ORANGE%^pale "+
      "wood %^RESET%^that perfectly matches the %^ORANGE%^tan bands %^RESET%^"+
      "of the tower.  A thick %^ORANGE%^brass ring %^RESET%^serves as the "+
      "door handle.");
   set_pre_exit_functions(({"up","down"}),({"do_banister","do_banister"}));
}