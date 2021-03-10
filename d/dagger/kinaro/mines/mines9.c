#include <std.h>
#include "../defs.h"
inherit INH+"tunnel";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A broad mining tunnel%^RESET%^\n"
+ ::query_long() +"  The tunnel continues toward the west, but comes to "
"an abrupt halt to the east where a massive, closed %^BOLD%^%^WHITE%^steel "
"door %^RESET%^blocks all access further into the mining tunnel.\n");
   set_exits(([
     "west":MINES"mines8",
   ]));
   add_item("door","A massive %^BOLD%^%^WHITE%^steel door %^RESET%^has been "
"inset into the walls of the tunnel itself, so seamlessly crafted that it is "
"hard to tell exactly how it would open, or how thick it might be.  It is "
"securely %^BLUE%^closed%^RESET%^, preventing any access further into the "
"tunnel.");
}
