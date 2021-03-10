//Kelemvor's graveyard.  Circe 11/22/04
#include <std.h>
#include "../kelemvor.h"

inherit KCEMETERY;

void create(){
   ::create();
   set_exits(([
      "north" : KEXIT"cemetery7",
      "northeast" : KEXIT"cemetery8",
      "east" : KEXIT"cemetery5",
      "south" : KEXIT"cemetery1",
      "southeast" : KEXIT"cemetery2"
   ]));
}