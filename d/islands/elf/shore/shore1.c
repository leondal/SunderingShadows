#include <std.h>
#include "../elf.h"
inherit INH"shore";

void create(){
   ::create();
   set_exits(([ "northeast": ROOMS"shore/shore2", 
   "south": "/d/shadow/virtual/sea/ice.dock",
     ]));

}