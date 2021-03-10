//~Circe~ 12/1/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit LANDING;

void create(){
   ::create();
   add_item("painting","The painting on the eastern wall here "+
      "is oval and set within a %^ORANGE%^gilded frame%^RESET%^.  "+
      "It is a portrait of an aging woman with long %^BOLD%^"+
      "silver hair %^RESET%^falling in soft waves past her "+
      "shoulders.  She has piercing %^MAGENTA%^violet eyes "+
      "%^RESET%^set within a rather plain face, and she "+
      "wears a simple %^GREEN%^green velvet gown %^RESET%^"+
      "edged in %^BOLD%^%^BLACK%^black%^RESET%^.  A scrolling "+
      "plaque at the base of the frame reads, '%^ORANGE%^"+
      "Lady Calliope Valchon, Arch Psion%^RESET%^'");
   set_exits(([
      "down" : ROOMS"psi_landing3",
      "up" : ROOMS"psi_landing5",
      "west" : ROOMS"psi_comps"
   ]));
   set_pre_exit_functions(({"up","down"}),({"do_banister","do_banister"}));
}