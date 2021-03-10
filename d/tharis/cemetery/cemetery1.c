//Kelemvor's graveyard.  Circe 11/14/04
#include <std.h>
#include "../kelemvor.h"

inherit KCEMETERY;

void create(){
   ::create();
   set_exits(([
      "north" : KEXIT"cemetery4",
      "northeast" : KEXIT"cemetery5",
      "east" : KEXIT"cemetery2"
   ]));
}