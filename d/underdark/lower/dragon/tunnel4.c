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
"%^BLACK%^darkness%^RESET%^%^BLUE%^.  An odd few %^YELLOW%^c%^WHITE%^oi%^YELLOW%^n%^WHITE%^s %^RESET%^%^BLUE%^are "
"scattered across the stone floor underfoot.\n%^RESET%^");
   set_exits(([
     "east":ROOMS"tunnel3",
     "west":ROOMS"tunnel5",
   ]));
   set_pre_exit_functions(({"east"}),({"GoThroughDoor"}));
}

int GoThroughDoor() {
   if(TP->query_true_invis()) return 1;
   if((int)TP->query_level() < 35) tell_object(TP,"%^BOLD%^%^BLACK%^A shadow flickers past in the darkness ahead, too "
"well concealed to make out any details. A %^CYAN%^chill %^BLACK%^runs down your spine, as you realise your progress is "
"being watched.  You get the feeling you shouldn't be here.%^RESET%^");
   else tell_object(TP,"%^BOLD%^%^BLACK%^A shadow flickers past in the darkness ahead, too well concealed to make out any "
"details. A %^CYAN%^chill %^BLACK%^runs down your spine, as you realise your progress is being watched.%^RESET%^");
   return 1;
}