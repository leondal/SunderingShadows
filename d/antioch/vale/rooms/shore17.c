#include <std.h>
#include "../vale.h"
inherit SHORE_INH;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",1);
   set_short("%^BOLD%^Beside a Waterfall%^RESET%^");
   set_long(
   "%^CYAN%^You are standing next to the %^BOLD%^waterfall%^RESET%^%^CYAN%^ that pours into the lake."+
   " You are less than a foot away from the cascading %^BOLD%^%^BLUE%^waters%^RESET%^%^CYAN%^, and"+
   " you can feel the cool spray splash you. The waterfall is falling"+
   " over a large %^ORANGE%^stone cliff%^CYAN%^ that juts out at the top, causing the"+
   " water to splash freely down instead of running close to the"+
   " cliff face. The stone around the waterfall has never the less"+
   " been worn smooth from time, although behind the waterfall it"+
   " falls away into %^BOLD%^%^BLACK%^darkness%^RESET%^%^CYAN%^\n."
   );
   set("night long",
   "%^CYAN%^You're standing next to the %^BOLD%^waterfall%^RESET%^%^CYAN%^ that crashes down into the"+
   " lake. It looks as though the top part of the cliff juts out, and"+
   " then recedes back into %^BOLD%^%^BLACK%^darkness%^RESET%^%^CYAN%^, causing the waterfall to fall"+
   " freely into the %^BOLD%^%^BLUE%^lake%^RESET%^%^CYAN%^ instead of tumbling down the cliff face. The"+
   " spray from the water is %^BLUE%^cold%^CYAN%^ at night, and the %^RESET%^mist%^CYAN%^ from the"+
   " waterfall obscures most everything.\n"
   );
   set_smell("default","The spray from the waterfall is cold and clean.");
   set_listen("default","The roar of the waterfall is almost deafening.");
   set_items(([
   "waterfall" : "%^BOLD%^%^CYAN%^The waterfall crashes from the top of a high cliff,"+
   " pouring down into the lake. This close you can see that it doesn't"+
   " touch the side of the cliff much, for the cliff seems to recede"+
   " back into darkness.",
   "cliff" : "%^ORANGE%^The cliff juts out at the top, but then slowly recedes"+
   " back into darkness. The stone around the waterfall has been worn"+
   " smooth.",
   "darkness" : "%^BOLD%^%^BLACK%^The darkness behind the waterfall is deep...almost as"+
   " though there is a %^BOLD%^%^BLUE%^cave%^BLACK%^ behind it.",
   "cave" : "%^BOLD%^%^BLUE%^There is definitely a cave here that can be entered from"+
   " this side by carefully moving underneath the waterfall and deeper"+
   " into the cliff.",
   "lake" : "%^BOLD%^%^BLUE%^The waters of the lake are clear and seem almost depthless.",
   "sand" : "%^ORANGE%^The sand is pale and very fine.",
   ]));
   set_exits(([
   "north" : ROOMS+"shore16",
   "cave" : "waterfall1",
   ]));
   set_invis_exits(({"cave"}));
   set_pre_exit_functions(({"cave"}),({"GoThroughDoor"}));
}

int GoThroughDoor()
{
   tell_object(TP,"%^BOLD%^%^CYAN%^You carefully move along the"+
   " slippery stones and make your way behind the waterfall.");
   if(TP->query_invis()) return 1;
   tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" disappears behind the waterfall.");
   return 1;
}
