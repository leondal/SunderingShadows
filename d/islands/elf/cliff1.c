//cliff
#include <std.h>
#include "elf.h"
inherit INH"cliff";


void create(){
    ::create();

   set_exits(([ "northwest": ROOMS"grove6", 
   "north": ROOMS"cliff8", 
   "west": ROOMS"grove3",    ]));


}
reset(){
    ::reset();
    if(!present("celisse"))
    new(MON"celisse")->move(TO);
}