#include <std.h>
#include <daemons.h>
#include "lair.h"
inherit ROOMS"tunnel";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^The entry to a narrow, winding tunnel%^RESET%^\n"
"%^BLUE%^This ledge seems to be the entry to a narrow tunnel, opening in from the %^CYAN%^vast c%^RESET%^ha%^CYAN%^sm "
"%^BLUE%^beyond and leading distinctly downwards.  The small, round chamber would be barely large enough to fit three "
"human-sized figures, and it only grows more narrow as it winds away deeper into the stony wall.  The walls and floor are "
"%^ORANGE%^rou%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^h%^BLUE%^, with an occasional outcropping that forces you to duck or "
"walk sideways for a few paces.  It is difficult to see more than a few feet down the corridor in the complete %^BOLD%^"
"%^BLACK%^darkness%^RESET%^%^BLUE%^.  Strangely, a few %^YELLOW%^c%^WHITE%^oi%^YELLOW%^n%^WHITE%^s %^RESET%^%^BLUE%^are "
"scattered across the stone floor underfoot.  If you were unwilling to travel further inside, you could probably try to "
"climb back up the chasm wall to the narrow path far above you.\n%^RESET%^");
   set_items( ([ 
     ({"walls","tunnel","floor","roof","stalagmites"}):"%^BLUE%^This tunnel is seemingly naturally-formed, so %^BOLD%^"
"%^CYAN%^na%^RESET%^%^CYAN%^rr%^BOLD%^ow %^RESET%^%^BLUE%^that only a small group of human-sized creatures could move "
"through it at a time.  The occasional glitter of a %^YELLOW%^spa%^WHITE%^r%^YELLOW%^kling coin %^RESET%^%^BLUE%^can be "
"spotted in the darkness, strewn across the rocky floor.  Where the wall opens onto the chasm itself, there are markings "
"and notches within the stone, suggesting that someone has climbed here before.%^RESET%^",
     "coins":"%^BLUE%^The occasional sparkle of a %^YELLOW%^c%^WHITE%^o%^YELLOW%^in %^RESET%^%^BLUE%^catches your eye, "
"lying upon the stone floor.  Some are damaged, and others appear to be almost eaten entirely through by... something"
".%^RESET%^",
   ]) );
   set_exits(([
     "south":ROOMS"tunnel5",
   ]));
   set_climb_exits(([
     "climb":({"/d/underdark/mid/chasm29",35,roll_dice(4,10),100}),
   ]));
   set_pre_exit_functions(({"south"}),({"GoThroughDoor"}));
}

int GoThroughDoor() {
   if(TP->query_true_invis()) return 1;
   if((int)TP->query_level() < 35) tell_object(TP,"%^BOLD%^%^BLACK%^A distinct feeling of unease settles over you as you "
"make your way into the darkened depths of the tunnel.  You get the feeling you shouldn't be here.%^RESET%^");
   else tell_object(TP,"%^BOLD%^%^BLACK%^A distinct feeling of unease settles over you as you make your way into the "
"darkened depths of the tunnel.%^RESET%^");
   return 1;
}