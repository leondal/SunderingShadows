#include <std.h>
#include "../defs.h"
inherit INH+"tower";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^Within the Black Spire%^RESET%^\n"
"%^BLUE%^You are standing on the fourth floor inside the massive %^RESET%^stone %^BLUE%^stalactite that serves as the "
"city's mage tower.  The walls, ceiling and floor are all formed of the same %^BOLD%^%^BLACK%^glo%^RESET%^ss%^BOLD%^"
"%^BLACK%^y black %^RESET%^%^BLUE%^obsidian that gives the Spire its name, as is the staircase that wraps around the "
"inner wall of the tower and leads to the floors above and below.  No decorations or ornaments can be seen, giving the "
"tower a very solemn and austere feeling.  Oddly, the walls and ceiling seem to emit a %^ORANGE%^m%^YELLOW%^u%^RESET%^"
"%^ORANGE%^t%^RESET%^e%^ORANGE%^d %^BLUE%^radiance of their own, providing the only light within the tower itself.  "
"Aside from the stairs, there are only two exits to this floor, the first being via a doorway set with a door of "
"polished %^RED%^zurk%^MAGENTA%^hw%^RED%^ood%^BLUE%^ that leads through to a room to the west.  The other is a "
"%^CYAN%^glo%^GREEN%^wi%^CYAN%^ng %^BLUE%^portal standing upon a raised ledge at the farthest point from the "
"staircase.%^RESET%^\n");

   add_item(({"stairs","staircase"}),"%^BLUE%^Much as the rest of the tower, the stairs are carved into the gleaming "
"%^BOLD%^%^BLACK%^obsi%^RESET%^di%^BOLD%^%^BLACK%^an%^RESET%^%^BLUE%^ stone, broad in length and concisely cut.  They "
"descend in a slow spiral around the inner wall of the tower, leading to the floors below.%^RESET%^");
   add_item(({"portal","glowing portal","ledge"}),"%^BLUE%^Upon a raised ledge directly opposite the stairs rests a "
"portal that emits a soft %^MAGENTA%^gl%^CYAN%^o%^MAGENTA%^w%^BLUE%^.  It is bordered by an archway carved with elaborate "
"%^CYAN%^a%^BOLD%^rc%^RESET%^%^CYAN%^ane ru%^BOLD%^n%^RESET%^%^CYAN%^es%^BLUE%^, perhaps wards of some kind.%^RESET%^");
   set_exits(([
     "down":ROOMS"tower6",
     "west":ROOMS"tower9", // laboratory
     "portal":ROOMS"tower10", // sparring chamber
   ]));
   set_door("door",ROOMS"tower9","west",0);
   set_door_description("door","%^BLUE%^This sturdy door is cut from %^RED%^zurk%^MAGENTA%^hw%^RED%^ood %^BLUE%^"
"that has been polished to a dark shine, and shaped with such precision as to fit within the wall seamlessly.  It offers "
"entry to a room to the south, but has no apparent handle with which to open or close it.%^RESET%^");
   set_pre_exit_functions(({"portal"}),({"GoThroughDoor"}));
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

void set_string(string id, string which, string str) {
   if(!id) return;
   if(!which) return;
   if(!doors) return;
   if(!doors[id]) return;
   if (which == "open") str = "%^BLUE%^A mere touch causes the zurkhwood door to swing open noiselessly.%^RESET%^";
   else str = "%^BLUE%^A mere touch causes the zurkhwood door to swing silently closed.%^RESET%^";
   doors[id][which+" string"] = str;
}

void set_open(string id, int open) {
    if(!id) return;
    if(!doors) return;
    if(!doors[id]) return;
    doors[id]["open"] = open;
    if (open == 1) { set_string(id,"open","stuff"); }
    else { set_string(id,"close","stuff"); }
}