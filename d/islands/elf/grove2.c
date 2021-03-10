//grove
#include <std.h>
#include "elf.h"
inherit INH"grove";


void create(){
    ::create();

   set_exits(([
    "southwest": ROOMS"guard1", 
   	"east" : ROOMS"grove1",
    "north": ROOMS"grove5", ]));


}
void reset(){
::reset();
if (!present("stone"))
  new(OBJ"stone2")->move(TO);
}
