//sstreet31 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VERDE;

void create(){
   ::create();
   set_long(::query_long()+"An aged %^BOLD%^%^BLACK%^iron picket "+
      "fence %^RESET%^borders the road on the northern and eastern "+
      "sides.  Just beyond it, you see a beautiful, quiet %^GREEN%^"+
      "garden%^RESET%^, but there is no gate in the fence here.\n");
   set_exits(([
      "southeast" : ROOMS"sstreet30",
      "west" : ROOMS"sstreet32"
   ]));
   add_item("fence","%^BOLD%^%^BLACK%^The picket fence is crafted from iron "+
      "and has slender bars topped with decorative fleurs-de-lis.  It "+
      "encloses the gardens to the north and east.%^RESET%^");
   add_item("garden","%^GREEN%^Lush gardens are enclosed by the %^BOLD%^"+
      "%^BLACK%^picket fence %^RESET%^%^GREEN%^to the north and east.  "+
      "Much of the garden is covered in %^BOLD%^grass %^RESET%^"+
      "%^GREEN%^that looks much softer and well-tended than the rest "+
      "of the grass in Seneca.  %^MAGENTA%^Tropical plants %^RESET%^"+
      "%^GREEN%^and %^BOLD%^palm trees %^RESET%^%^GREEN%^grow among "+
      "%^RESET%^stone benches %^GREEN%^that provide places for people "+
      "to relax.%^RESET%^");
}