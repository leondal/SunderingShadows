//Kelemvor's graveyard.  Circe 11/22/04
#include <std.h>
#include "../kelemvor.h"

inherit KCEMETERY;

void create(){
   ::create();
   set_exits(([
      "north" : KEXIT"cemetery5",
      "northeast" : KEXIT"cemetery6",
      "east" : KEXIT"cemetery3",
      "northwest" : KEXIT"cemetery4",
      "west" : KEXIT"cemetery1",
      "south" : KEXIT"kpath"
   ]));
}