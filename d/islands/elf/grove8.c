//grove
#include <std.h>
#include "elf.h"
inherit INH"grove";


void create(){
    ::create();

   set_exits(([
    "north": ROOMS"cliff6", 
  	"west" : ROOMS"water", 
    "east" : ROOMS"cliff7",
	"southwest" : ROOMS"grove4",
    "south": ROOMS"grove6", ]));
}
void reset(){
::reset();
if (!present("stone"))
  new(OBJ"stone8")->move(TO);
}
