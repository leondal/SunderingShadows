#include <std.h>
#include "../witchlair.h"
inherit CROOM;

void create(){
   ::create();
   set_property("light",-2);
   set_property("no sticks",0);
   set_property("no teleport",0);
   set_property("no starve",0);
   set_property("no magic",0);
   set_property("no steal",0);
   set_short("%^BOLD%^%^BLACK%^With%^RESET%^%^BLUE%^i"
"%^BOLD%^%^BLACK%^n a d%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^rk "
"t%^RESET%^%^ORANGE%^u%^GREEN%^n%^BOLD%^%^BLACK%^n"
"%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^l%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^You've descended deeper into the "
"roots of the tree, much to the dismay of your common sense. "
"Darkness envelopes all here, leaving even those with natural "
"darkvision blind as a bat. All the rest of your senses tell "
"you that you are deep below the surface, within an earthen "
"tunnel. The air is cool here, stirred by a slight "
"%^RESET%^%^CYAN%^breeze %^BOLD%^%^BLACK%^blowing toward the "
"direction you came from. An uneasy feeling settles over you"
" here. It may be wise to just turn around...");
   set_smell("default","The scents of dirt and plant decay "
"tickle your nose.");
   set_listen("default","It is quiet in here, unsettlingly so.");
}
