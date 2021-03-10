//grove
#include <std.h>
#include "elf.h"
inherit INH"grove";


void create(){
    ::create();

   set_exits(([
    "north": ROOMS"grove6", 
   	"west" : ROOMS"grove1",
	"east" : ROOMS"cliff1",
     ]));
}
void reset(){
::reset();
if (!present("stone"))
  new(OBJ"stone3")->move(TO);
}
