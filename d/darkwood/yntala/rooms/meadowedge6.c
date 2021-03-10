//meadowedge6
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"meadowedge.c";

void create(){
::create();
   set_exits(([
"south":INRMS+"meadow2",
"west":INRMS+"meadow1",
"northwest":INRMS+"meadowedge7",
"southeast":INRMS+"meadowedge5",
"northeast":INRMS+"spring",
"southwest":INRMS+"centermed"
]));
   set_invis_exits( ({"northeast"}) );
   set_items(([
      "thornbushes":"%^RESET%^%^ORANGE%^The thornbushes here look thinner than the rest.",
      ({"tree","trees"}):"%^BOLD%^%^GREEN%^The trees here stop at the edge of the meadow and seem to be very well taken care of.%^RESET%^",
      ({"flowers","wildflowers"}):"%^BOLD%^%^GREEN%^Various types of %^YELLOW%^w%^MAGENTA%^i%^RED%^l%^BLUE%^d%^GREEN%^f%^WHITE%^l%^YELLOW%^o%^MAGENTA%^w%^BLUE%^e%^RED%^r%^YELLOW%^s %^GREEN%^grown wildly on the grasslands of the meadow.%^RESET%^",
      "berries":"%^RED%^The berries look like they are well taken care of, and there are several ripe ones on the vines, perhaps you can pick them?%^RESET%^",
      "forest":"%^RESET%^%^GREEN%^The forest comes to an edge here and looks as though the trees lining the edge might even actually be pruned.%^RESET%^",
      "smoke":"%^BOLD%^%^BLACK%^Smoke rises up from somewhere in the center of the meadow.%^RESET%^"
]));
   set_search("thornbushes","You notice that there is a hidden path leading northeast through the thornbushes.");
}