//Kelemvor's graveyard.  Circe 11/22/04
#include <std.h>
#include "../kelemvor.h"

inherit KCEMETERY;

void create(){
   ::create();
   set_exits(([
      "north" : KEXIT"cemetery9",
      "south" : KEXIT"cemetery3",
      "southwest" : KEXIT"cemetery2",
      "west" : KEXIT"cemetery5",
      "northwest" : KEXIT"cemetery8"
   ]));
}