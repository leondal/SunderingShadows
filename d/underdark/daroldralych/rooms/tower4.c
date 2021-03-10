#include <std.h>
#include "../defs.h"
inherit INH+"tower";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^Within the Black Spire%^RESET%^\n"
"%^BLUE%^You are standing on the second floor inside the massive %^RESET%^stone %^BLUE%^stalactite that serves as the "
"city's mage tower.  The walls, ceiling and floor are all formed of the same %^BOLD%^%^BLACK%^glo%^RESET%^ss%^BOLD%^"
"%^BLACK%^y black %^RESET%^%^BLUE%^obsidian that gives the Spire its name, as is the staircase that wraps around the "
"inner wall of the tower and leads to the floors above and below.  No decorations or ornaments can be seen, giving the "
"tower a very solemn and austere feeling.  Oddly, the walls and ceiling seem to emit a %^ORANGE%^m%^YELLOW%^u%^RESET%^"
"%^ORANGE%^t%^RESET%^e%^ORANGE%^d %^BLUE%^radiance of their own, providing the only light within the tower itself.  "
"Aside from the stairs, there is only one exit to this floor, a single high archway that leads through to a small room "
"to the east.%^RESET%^\n");

   add_item(({"stairs","staircase"}),"%^BLUE%^Much as the rest of the tower, the stairs are carved into the gleaming "
"%^BOLD%^%^BLACK%^obsi%^RESET%^di%^BOLD%^%^BLACK%^an%^RESET%^%^BLUE%^ stone, broad in length and concisely cut.  They "
"rise in a slow spiral around the inner wall of the tower, leading to the floors above and below.%^RESET%^");
   add_item(({"archway","high archway"}),"%^BLUE%^An archway of matching mirror-smooth %^BOLD%^%^BLACK%^obsi%^RESET%^di"
"%^BOLD%^%^BLACK%^an %^RESET%^%^BLUE%^leads through to a small room to the east.%^RESET%^");
   set_exits(([
     "down":ROOMS"tower2",
     "east":ROOMS"tower5", // scroll shop
     "up":ROOMS"tower6",
   ]));
}
