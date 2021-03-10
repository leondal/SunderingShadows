#include "../kildare.h"

inherit HIDDENTUNNEL;

void create(){
   ::create();
   set_long(::query_long()+"\nDust thickens on the stone floor "+
      "of this narrow tunnel as it curves here.  The pathway "+
      "northeast seems to lead upward, while the one southeast "+
      "leads deeper into the %^RESET%^gloom%^BOLD%^%^BLACK%^.\n");
   set_listen("default","The faint sound of %^CYAN%^lapping water "+
      "%^GREEN%^echoes on the walls.");
   set_listen("water","%^CYAN%^It sounds almost as though water "+
      "is lapping on a shore.  Strangely, the sound seems to come from "+
      "deeper in the tunnel to the southeast.");
   set_exits(([
      "northeast" : ROOMS"hiddentunnel2",
      "southeast" : ROOMS"hiddentunnel4"
   ]));
}