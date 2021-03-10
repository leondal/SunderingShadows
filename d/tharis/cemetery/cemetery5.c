//Kelemvor's graveyard.  Circe 11/22/04
#include <std.h>
#include "../kelemvor.h"

inherit KCEMETERY;

void create(){
   ::create();
   set_exits(([
      "north" : KEXIT"cemetery8",
      "northeast" : KEXIT"cemetery9",
      "east" : KEXIT"cemetery6",
      "south" : KEXIT"cemetery2",
      "southeast" : KEXIT"cemetery3",
      "southwest" : KEXIT"cemetery1",
      "west" : KEXIT"cemetery4",
      "northwest" : KEXIT"cemetery7"
   ]));
}