#include <std.h>
#include "../elf.h"
inherit INH"house";

void create(){
   ::create();
   set_exits(([ 
   "north": ROOMS"shore/ruin6",

     ]));

}