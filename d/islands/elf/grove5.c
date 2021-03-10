//grove
#include <std.h>
#include "elf.h"
inherit INH"grove";


void create(){
    ::create();

   set_exits(([
    "northwest": ROOMS"cliff4", 
   	"west" : ROOMS"cliff3",
	  "east" : ROOMS"grove4",
	  "southwest" : ROOMS"cliff2",
	  "north" : ROOMS"grove7",
    "south": ROOMS"grove2", ]));
}
void reset(){
::reset();
if (!present("stone"))
  new(OBJ"stone5")->move(TO);
}
