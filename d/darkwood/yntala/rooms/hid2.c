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
   set_name("%^RESET%^%^CYAN%^An underground spring%^RESET%^");
   set_short("%^RESET%^%^CYAN%^An underground spring%^RESET%^");
   set_long("%^RESET%^%^CYAN%^The water here is cold and dark, though you can tell you're near a surface of some"
" sort from the little amount of light that does manage to make its way into these depths.  The walls are riddled"
" with cracks, and a few bubbles dance lazily around.%^RESET%^\n");
   set_smell("default","%^BOLD%^%^CYAN%^You can't smell anything.%^RESET%^");
   set_listen("default","%^RESET%^%^BLUE%^All you can hear is the sound of moving water.%^RESET%^");
   set_items(([
      "bubbles":"%^RESET%^%^CYAN%^A few %^BOLD%^%^CYAN%^b%^RESET%^u%^CYAN%^b%^RESET%^b%^CYAN%^l%^RESET%^e%^BOLD%^%^CYAN%^s %^RESET%^%^CYAN%^come up from the cracks in the cave walls.%^RESET%^",
      ({"cave walls","walls"}):"%^RESET%^%^ORANGE%^The natural rock formations of the caves make very narrow passageways that are difficult to manuever, and it looks like from here you can either go to the surface, or north.%^RESET%^",
      "cracks":"%^BOLD%^%^BLACK%^The cave walls are riddled with cracks.",
]));
   set_exits(([
        "surface":INRMS+"hid3",
        "north":INRMS+"hid1"
]));
}