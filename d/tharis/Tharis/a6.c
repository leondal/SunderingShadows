//a6.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
   set_long(::query_long()+"\n%^BOLD%^%^BLUE%^A small shop stands to "+
      "the south with a simple %^RESET%^%^ORANGE%^wooden nameplate "+
      "%^BOLD%^%^BLUE%^above its door.%^RESET%^\n");
   add_item(({"nameplate","plate","wooden nameplate"}),"%^ORANGE%^"+
      "The wooden nameplate is thin and bears a fading etching naming "+
      "this shop %^RED%^'%^YELLOW%^Winter's Emperor%^RESET%^%^RED%^'");
   set_exits(([
      "south":ROOMS"magic",
      "north":ROOMS"a5"
   ]));
}
