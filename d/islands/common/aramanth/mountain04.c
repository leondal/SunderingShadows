#include <std.h>
#include "mountain.h";

inherit BASE;

void create(){
   ::create();
   set_long(
      "%^RESET%^%^ORANGE%^The path spirals up along the side of the mountain."+
      " You are now very far from the beach as you survey over"+
      " the landscape beneath you. The land is quite ugly and barren"+
      ", much like the mountain you are on."
   );
   set_exits(([
      "southeast" : MOUNTAIN+"mountain03",
      "northeast" : MOUNTAIN+"mountain05",
   ]));
    set_pre_exit_functions(({"northeast"}),({"exit_fun"}));
}

int exit_fun() {
    write("%^BOLD%^%^BLACK%^A large shadow pass over head and the smell of sulfur fills the air!");
    return 1;
} 