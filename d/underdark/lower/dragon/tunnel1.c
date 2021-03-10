#include <std.h>
#include <daemons.h>
#include "lair.h"
inherit ROOMS"tunnel";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^A narrow tunnel%^RESET%^\n"
"%^BLUE%^The formerly narrow tunnel has broadened here somewhat, with enough space now to fit perhaps a few humanoids "
"abreast.  The walls and floor are %^ORANGE%^rou%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^h%^BLUE%^, and roof lies a short "
"way above your head, dotted with tiny stalactites.  It is difficult to see more than a few feet down the corridor in the "
"complete %^BOLD%^%^BLACK%^darkness%^RESET%^%^BLUE%^, but ahead of you the tunnel opens into a massive, shadow-shrouded "
"cavern.  You're quite sure no more than two or three people could fit through the opening at once, however.  An odd few "
"%^YELLOW%^c%^WHITE%^oi%^YELLOW%^n%^WHITE%^s %^RESET%^%^BLUE%^are scattered across the stone floor underfoot.\n%^RESET%^");
   set_exits(([
     "cavern":ROOMS"lair",
     "southeast":ROOMS"tunnel2",
   ]));
   set_pre_exit_functions(({"cavern"}),({"GoThroughDoor"}));
}

int GoThroughDoor() {
   object nextroom, *ppl;
   if(TP->query_true_invis()) return 1;
   if(!userp(TP)) return 1;
   nextroom = find_object_or_load(ROOMS"lair");
   if(!present("Arkhon Bloodscale",nextroom) && !nextroom->is_running()) return 1;
   ppl = all_living(nextroom);
   ppl = filter_array(ppl,"is_non_immortal_player",FILTERS_D);
   if(sizeof(ppl) > 2) { // stop more than 3 players entering the next room
     tell_object(TP,"%^BOLD%^%^BLACK%^The cavern opening ahead of you is too crowded.  You can't go any further right "
"now.%^RESET%^");
     return 0;
   }
   return 1;
}