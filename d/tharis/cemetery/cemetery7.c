//Kelemvor's graveyard.  Circe 11/22/04
#include <std.h>
#include "../kelemvor.h"

inherit KCEMETERY;

void create(){
   ::create();
   set_exits(([
      "south" : KEXIT"cemetery4",
      "east" : KEXIT"cemetery8",
      "southeast" : KEXIT"cemetery5"
   ]));
}