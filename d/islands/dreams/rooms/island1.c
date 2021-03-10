#include <std.h>
#include "../defs.h"
inherit ISLAND;

void create()
{
  ::create();
  set_exits( 
    ([
    "east" : ROOMS+"island5",
    "northeast" : ROOMS+"island2",
    "southeast" : ROOMS+"island4",
    "west": "/d/shadow/virtual/sea/ovadexel.dock"
    ]) );
}
void reset(){
   ::reset();
    if(!present("sign"))
      new(OBJ"sign")->move(this_object());
}
