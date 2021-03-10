//Kelemvor's graveyard.  Circe 11/22/04
#include <std.h>
#include "../kelemvor.h"

inherit KCEMETERY;

void create(){
   ::create();
   set_exits(([
      "north" : KEXIT"cemetery6",
      "northwest" : KEXIT"cemetery5",
      "west" : KEXIT"cemetery2"
   ]));
}