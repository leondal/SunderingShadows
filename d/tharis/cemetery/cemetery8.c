//Kelemvor's graveyard.  Circe 11/22/04
#include <std.h>
#include "../kelemvor.h"

inherit KCEMETERY;

void create(){
   ::create();
   set_exits(([
      "south" : KEXIT"cemetery5",
      "east" : KEXIT"cemetery9",
      "southeast" : KEXIT"cemetery6",
      "southwest" : KEXIT"cemetery4",
      "west" : KEXIT"cemetery7",
      "building" : "/d/magic/temples/kelemvor"
   ]));
}