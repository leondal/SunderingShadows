//skyline46
#include <std.h>
#include "../seneca.h"

inherit SKYLINE;

void create(){
   ::create();
   set_long(::query_long()+"To the west stands the entrance "+
      "to a %^BOLD%^"+
      "majestic cathedral %^RESET%^with a single soaring "+
      "bell tower.  To the east is an impressive %^ORANGE%^shop "+
      "%^RESET%^made of %^YELLOW%^yellow sandstone %^RESET%^"+
      "and set with twin arched %^BOLD%^"+
      "%^GREEN%^s%^RESET%^%^CYAN%^t%^BOLD%^%^BLUE%^"+
      "a%^CYAN%^i%^YELLOW%^n%^RED%^e%^MAGENTA%^d %^CYAN%^g%^YELLOW%^l%^BLUE%^a"+
      "%^GREEN%^s%^MAGENTA%^s %^RED%^w%^YELLOW%^i%^CYAN%^n%^GREEN%^d%^WHITE%^o"+
      "%^BLUE%^w%^RESET%^%^CYAN%^s%^RESET%^.\n");
   set_exits(([
      "west" : ROOMS"cath_yard",
      "east" : ROOMS"healer",
      "north" : ROOMS"skyline45",
      "south" : ROOMS"skyline47"
   ]));
   add_item("cathedral","The cathedral to the west boasts towering "+
      "arches and vaulted ceilings, resplendent with %^BOLD%^"+
      "%^GREEN%^s%^RESET%^%^CYAN%^t%^BOLD%^%^BLUE%^"+
      "a%^CYAN%^i%^YELLOW%^n%^RED%^e%^MAGENTA%^d %^CYAN%^g%^YELLOW%^l%^BLUE%^a"+
      "%^GREEN%^s%^MAGENTA%^s %^RED%^w%^YELLOW%^i%^CYAN%^n%^GREEN%^d%^WHITE%^o"+
      "%^BLUE%^w%^RESET%^%^CYAN%^s %^RESET%^and a bell tower that "+
      "soars over all.  A path paved with %^BOLD%^pure white "+
      "cobblestones %^RESET%^leads to the cathedral's entrance.");
   add_item("shop","%^ORANGE%^The shop to the east is crafted from "+
      "%^YELLOW%^yellow sandstone %^RESET%^%^ORANGE%^enhanced by "+
      "two %^BOLD%^"+
      "%^GREEN%^s%^RESET%^%^CYAN%^t%^BOLD%^%^BLUE%^"+
      "a%^CYAN%^i%^YELLOW%^n%^RED%^e%^MAGENTA%^d %^CYAN%^g%^YELLOW%^l%^BLUE%^a"+
      "%^GREEN%^s%^MAGENTA%^s %^RED%^w%^YELLOW%^i%^CYAN%^n%^GREEN%^d%^WHITE%^o"+
      "%^BLUE%^w%^RESET%^%^CYAN%^s %^RESET%^%^ORANGE%^with pointed "+
      "arches.  There is no sign proclaiming the nature of this "+
      "place, though it must be a shop with all the people coming and "+
      "going.%^RESET%^");
}