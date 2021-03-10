#include <std.h>
#include "mountain.h";

inherit BASE;

void create(){
   ::create();
   set_long(
      "%^BOLD%^%^BLACK%^The bridge itself seems stable as it is formed"+
      " from the mountain itself. You would hate to fall over, because it"+
      " is a long drop to the bottom and all the rocks are jagged."
   );
   set_exits(([
      "east" : MOUNTAIN+"mountain09",
      "west" : MOUNTAIN+"mountain07",
   ]));
    set_pre_exit_functions(({"east"}),({"exit_fun"}));
}

int exit_fun() {
    write("%^RESET%^%^MAGENTA%^A voice thunders from above%^RESET%^: %^BOLD%^%^RED%^YOU WILL ONLY FIND DEATH UP HERE!!!%^RESET%^");
    return 1;
}   