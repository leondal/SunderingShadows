//grove
#include <std.h>
#include "elf.h"
inherit INH"grove";


void create(){
    ::create();

   set_exits(([
    "north": ROOMS"cliff5", 
   	"west" : ROOMS"cliff4",
	"east" : ROOMS"water",
	"south": ROOMS"grove5",
    "southeast": ROOMS"grove4", ]));
}

void reset(){
::reset();
if (!present("stone"))
  new(OBJ"stone7")->move(TO);
}
