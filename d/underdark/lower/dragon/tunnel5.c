#include <std.h>
#include <daemons.h>
#include "lair.h"
inherit ROOMS"tunnel";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^A narrow, winding tunnel%^RESET%^\n"
"%^BLUE%^This tunnel is particularly narrow, barely large enough for a human-sized figure to move through.  The walls and "
"floor are %^ORANGE%^rou%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^h%^BLUE%^, and the occasional outcropping forces you to duck "
"or walk sideways for a few paces.  It is difficult to see more than a few feet down the corridor in the complete %^BOLD%^"
"%^BLACK%^darkness%^RESET%^%^BLUE%^, though to the south it seems to reach an opening.  An odd few %^YELLOW%^c%^WHITE%^oi"
"%^YELLOW%^n%^WHITE%^s %^RESET%^%^BLUE%^are scattered across the stone floor underfoot.\n%^RESET%^");
   set_exits(([
     "east":ROOMS"tunnel4",
     "north":ROOMS"tunnel6",
   ]));
}
