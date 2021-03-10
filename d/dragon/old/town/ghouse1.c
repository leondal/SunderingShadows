//  /d/dragon/town/ghouse1.c
#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Crumbled Guardhouse");
    set_long("%^BOLD%^%^RED%^
%^YELLOW%^Crumbled Guardhouse%^RED%^
Most of the walls in the city lay in ruins, and the thick walls that
once repelled invasions have been reduced to piles of rubble by the
passage of time.  A broken door lies amidst the crumbled stonework,
while the collapsed remains of an upper level can be seen above.
    ");
    set_exits(([
       "west" : "/d/deku/plains/road35"
    ] ));
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("sfighter")) {
    new("/d/dragon/mon/guard")->move(this_object());
    new("/d/dragon/mon/guard")->move(this_object());
  }
  if(!present("smage")) {
    new("/d/dragon/mon/mage")->move(this_object());
  }
}
