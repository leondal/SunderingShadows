//grove
#include <std.h>
#include "elf.h"
inherit INH"grove";


void create(){
    ::create();

   set_exits(([
    "northeast": ROOMS"grove8", 
	"north": ROOMS"water", 
   	"south" : ROOMS"grove1",
	"east" : ROOMS"grove6",
	"west" : ROOMS"grove5",
    "northwest": ROOMS"grove7", ]));

}
void reset(){
::reset();
if (!present("stone"))
  new(OBJ"stone4")->move(TO);
}
