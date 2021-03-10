#include <std.h>
#include "../yntala.h"
inherit WATER;

void create()
{
::create();
   set_property("indoors",1);
   set_property("light",2);
   set_property("no_teleport",1);
   set_property("no_sticks",1);
   set_name("%^RESET%^%^CYAN%^An underwater labyrinth%^RESET%^");
   set_short("%^RESET%^%^CYAN%^An underwater labyrinth%^RESET%^");
   set_long("%^RESET%^%^CYAN%^It is very dark down here as you"
" swim around, and everything seems to close in around you."
" %^BOLD%^%^BLACK%^Cave walls %^RESET%^%^CYAN%^form small passages"
" that you can swim through, but the narrow passage ways difficult"
" to manuever. %^BOLD%^%^CYAN%^B%^RESET%^u%^CYAN%^b%^RESET%^"
"b%^CYAN%^l%^RESET%^e%^BOLD%^%^CYAN%^s %^RESET%^"
"%^CYAN%^occassionally come up from small %^BOLD%^%^BLACK%^cracks"
" %^RESET%^%^CYAN%^in the floor of this system, and you cannot"
" help but to think perhaps you should make your way back to"
" the surface. The water looks %^BOLD%^%^CYAN%^lighter %^RESET%^"
"%^CYAN%^above you.%^RESET%^\n");
   set_smell("default","%^BOLD%^%^CYAN%^You can't smell anything.%^RESET%^");
   set_listen("default","%^RESET%^%^BLUE%^All you can hear is the sound of moving water.%^RESET%^");
   set_items(([
      "bubbles":"%^RESET%^%^CYAN%^A few %^BOLD%^%^CYAN%^b%^RESET%^u%^CYAN%^b%^RESET%^b%^CYAN%^l%^RESET%^e%^BOLD%^%^CYAN%^s %^RESET%^%^CYAN%^come up from the cracks in the cave walls.%^RESET%^",
      ({"cave walls","walls"}):"%^RESET%^%^ORANGE%^The natural rock formations of the caves make very narrow passageways that are difficult to manuever.%^RESET%^",
      "cracks":"%^BOLD%^%^BLACK%^The cave walls are riddled with cracks.",
]));
   set_exits(([
        "up":INRMS+"spring",
        "down":INRMS+"uw2"
]));
}
