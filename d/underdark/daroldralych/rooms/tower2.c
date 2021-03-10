#include <std.h>
#include "../defs.h"
inherit INH+"tower";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^Within the Black Spire%^RESET%^\n"
"%^BLUE%^You are standing on the bottom floor inside the massive %^RESET%^stone %^BLUE%^stalactite that serves as the "
"city's mage tower.  The walls, ceiling and floor are all formed of the same %^BOLD%^%^BLACK%^glo%^RESET%^ss%^BOLD%^"
"%^BLACK%^y black %^RESET%^%^BLUE%^obsidian that gives the Spire its name, as is the staircase that wraps around the "
"inner wall of the tower and leads up to the higher floors above.  No decorations or ornaments can be seen, giving the "
"tower a very solemn and austere feeling.  Oddly, the walls and ceiling seem to emit a %^ORANGE%^m%^YELLOW%^u%^RESET%^"
"%^ORANGE%^t%^RESET%^e%^ORANGE%^d %^BLUE%^radiance of their own, providing the only light within the tower itself.  Aside "
"from the stairs, there are two exits to this floor, a %^CYAN%^glo%^GREEN%^wi%^CYAN%^ng %^BLUE%^portal set against the "
"north-western wall, and a high archway that leads through to a room to the south.%^RESET%^\n");

   add_item(({"stairs","staircase"}),"%^BLUE%^Much as the rest of the tower, the stairs are carved into the gleaming "
"%^BOLD%^%^BLACK%^obsi%^RESET%^di%^BOLD%^%^BLACK%^an%^RESET%^%^BLUE%^ stone, broad in length and concisely cut.  They "
"rise in a slow spiral around the inner wall of the tower, leading to the floors above.%^RESET%^");
   add_item(({"archway","high archway"}),"%^BLUE%^A broad archway of matching mirror-smooth %^BOLD%^%^BLACK%^obsi"
"%^RESET%^di%^BOLD%^%^BLACK%^an %^RESET%^%^BLUE%^leads through to what appears to be a particularly large room to the "
"south.  Odd %^MAGENTA%^a%^CYAN%^r%^MAGENTA%^o%^RED%^ma%^MAGENTA%^s%^BLUE%^, some pleasant and more not as much, drift "
"back into the tower from the room beyond.%^RESET%^");
   add_item(({"portal","glowing portal"}),"%^BLUE%^Within the tower wall is a portal limned in %^CYAN%^pa%^GREEN%^l"
"%^CYAN%^e li%^GREEN%^gh%^CYAN%^t%^BLUE%^.  It is bordered by an archway carved with elaborate %^CYAN%^a%^BOLD%^rc"
"%^RESET%^%^CYAN%^ane ru%^BOLD%^n%^RESET%^%^CYAN%^es%^BLUE%^, perhaps wards of some kind.%^RESET%^");
   set_exits(([
     "out":ROOMS"tower1",
     "south":ROOMS"tower3", // comp shop
     "up":ROOMS"tower4",
   ]));
   set_pre_exit_functions(({"out"}),({"GoThroughDoor"}));
}

int GoThroughDoor() {
   if(TP->query_true_invis()) return 1;
   tell_object(TP,"%^RESET%^%^BLUE%^You step into the %^CYAN%^glo%^GREEN%^wi%^CYAN%^ng %^BLUE%^portal, and find yourself "
"elsewhere.%^RESET%^");
   if(!TP->query_invis()) tell_room(TO,"%^RESET%^%^BLUE%^"+TP->QCN+" steps into the %^CYAN%^glo%^GREEN%^wi%^CYAN%^ng "
"%^BLUE%^portal %^BLUE%^and vanishes in a flash of light!%^RESET%^",TP);
   else tell_room(TO,"%^RESET%^%^BLUE%^The %^CYAN%^glo%^GREEN%^wi%^CYAN%^ng %^BLUE%^portal emits a sudden flash of light"
".%^RESET%^",TP);
   return 1;
}