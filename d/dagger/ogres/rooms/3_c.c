#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^%^BOLD%^%^BLUE%^An un%^RESET%^%^BLUE%^d"+
"%^RESET%^%^BOLD%^%^BLUE%^ergrou%^RESET%^%^BLUE%^n%^RESET%^%^BOLD%^%^BLUE%^d"+
" riv%^RESET%^%^BLUE%^e%^RESET%^%^BOLD%^%^BLUE%^r passes through this cavern."+
" The water rushes past quite quickly, and you can catch glimpes of %^RESET%^"+
"%^RED%^demon %^RESET%^%^BOLD%^%^BLUE%^and %^RESET%^%^ORANGE%^ogre %^RESET%^"+
"%^BOLD%^%^BLACK%^corpses %^RESET%^%^BOLD%^%^BLUE%^floating past you. %^RESET%^\n");
   set_exits(([
      "east" : ROOMS"3_8",
   ]));

}
