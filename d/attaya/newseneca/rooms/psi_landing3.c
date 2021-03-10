//~Circe~ 12/1/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit LANDING;

void create(){
   ::create();
   add_item("painting","Framed in %^BOLD%^%^BLACK%^mahogany"+
      "%^RESET%^, this painting depicts a group of young psions "+
      "in class.  Wearing robes of %^ORANGE%^soft natural cotton"+
      "%^RESET%^, the pupils are seated cross-legged on %^BOLD%^"+
      "marble steps %^RESET%^in some sort of outdoor amphitheater.  "+
      "They are listening with interest to a teacher, who stands "+
      "before them gesturing grandly in his %^CYAN%^azure robes%^RESET%^.  "+
      "The small plaque at the picture's base reads simply, '%^ORANGE%^"+
      "Initiates%^RESET%^'.");
   set_exits(([
      "down" : ROOMS"psi_landing2",
      "up" : ROOMS"psi_landing4",
      "west" : ROOMS"psi_store"
   ]));
   set_pre_exit_functions(({"up","down"}),({"do_banister","do_banister"}));
}