//grove
#include <std.h>
#include "elf.h"
inherit INH"grove";


void create(){
    ::create();

   set_exits(([
    "north": ROOMS"grove8", 
   	"east" : ROOMS"cliff8",
	"west" : ROOMS"grove4",
	"south" : ROOMS"grove3",
    "southeast": ROOMS"cliff1", ]));
}
void reset(){
if (!present("stone"))
  new(OBJ"stone6")->move(TO);
}
