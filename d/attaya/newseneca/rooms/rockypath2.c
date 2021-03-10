//rockypath2.c - ~Circe~ 6/8/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit RPATH;

void create(){
   ::create();
   set_long(::query_long()+"The wall of %^ORANGE%^bedrock %^RESET%^"+
      "rises to the north here, blocking off most of the view of "+
      "the city.  This short pathway leads downward to the east "+
      "toward a %^BOLD%^stucco building%^RESET%^ and the slope "+
      "moves upwards to the west, back into the city.\n");
   set_exits(([
      "east" : ROOMS"rockypath3",
      "west" : ROOMS"rockypath1"
   ]));
   add_item(({"building","stucco building"}),"%^BOLD%^%^WHITE%^"+
      "You are looking downward upon a white stucco building "+
      "with a brilliant %^RED%^red tile roof%^WHITE%^.  The path "+
      "eastward leads directly to it.%^RESET%^");
}