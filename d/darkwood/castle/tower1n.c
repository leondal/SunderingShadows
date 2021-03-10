#include <std.h>

inherit ROOM;

void create()
{
  ::create();
  set_property("indoors",1);
  set_property("light",2);
  set_short("The Tower of Wizardry");
  set_long(
@CASTLE
%^BOLD%^First Floor of the Tower of Wizardry%^RESET%^
%^BLUE%^You are in the north room on the first floor, the 
residence of Merrang the Enchanter. There are shelves lining 
the walls, and you are sure they must be filled with many 
secrets of the magi.
CASTLE
  );
  set_items(([
    ]));
  set_exits( ([
    "south":"/d/darkwood/castle/tower1c"
    ]) );
}

void reset(){
  ::reset();
  if(!present("merrang"))
    new("/d/darkwood/castle/mon/merrang.c")->move(TO);
}
