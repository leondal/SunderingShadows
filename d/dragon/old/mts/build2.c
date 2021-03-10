//   /d/dragon/mts/build2.c

#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Northern Mountains");
    set_long("%^BLUE%^%^BOLD%^
Blood spatters the wall, floor, furniture and ceiling of this large and well    
lit room.  Much of the furniture is wrecked and broken, as if attacked by 
some mad and raving beast.
    ");
    set_exits(([
      "south" : "/d/dragon/mts/build1"
    ] ));
   set_items(([                     
    ] ));
}

void reset() {
  ::reset();
  if(!present("gorger")) {
    new("/d/dragon/mon/gorger")->move(this_object());
    new("/d/dragon/mon/gorger")->move(this_object());
  }
}
