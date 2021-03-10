#include <std.h>
#include "graveyard.h"
inherit GRAVEYARD"tomb";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^Musty tomb%^RESET%^\n%^BLUE%^This small building appears to be a tomb of sorts.  "
"It seems to be very old, and has been untended for quite some time.  The crumbling stone%^BOLD%^%^BLACK%^ "
"walls %^RESET%^%^BLUE%^are coated in patches of %^GREEN%^moss %^BLUE%^and grime.  Off to the side are a few "
"%^ORANGE%^coffins %^BLUE%^that have been carelessly left on the floor.%^RESET%^\n");
   set_exits(([
     "east":GRAVEYARD"cemetery8",
     "west":GRAVEYARD"tomb2",
     "south":GRAVEYARD"tomb3",
   ]));
}
