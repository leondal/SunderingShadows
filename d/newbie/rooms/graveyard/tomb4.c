#include <std.h>
#include "graveyard.h"
inherit GRAVEYARD"tomb";

void create(){
   set_monsters(({GRAVEYARD"mon/rashan",}),({1,}));
   ::create();
   set_long("%^BOLD%^%^BLACK%^Musty tomb%^RESET%^\n%^BLUE%^This small building appears to be a tomb of sorts.  "
"It seems to be very old, and has been untended for quite some time.  The crumbling stone%^BOLD%^%^BLACK%^ "
"walls %^RESET%^%^BLUE%^are coated in patches of %^GREEN%^moss %^BLUE%^and grime.  Off to the side are a few "
"%^ORANGE%^coffins %^BLUE%^that have been carelessly left on the floor.%^RESET%^\n");
   set_smell("default","The air is musty and thick, and carries a foul smell.");
   set_listen("default","It is eerily quiet in here... a little too quiet.");
   set_exits(([
     "east":GRAVEYARD"tomb3",
     "north":GRAVEYARD"tomb2",
   ]));
}
