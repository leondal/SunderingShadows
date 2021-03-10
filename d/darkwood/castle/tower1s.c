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
%^BLUE%^You are in the south room on the first floor. This room
curves around, with the inner wall of this room making the 
outer wall of the central room. This room serves as the common
library for the magi.

CASTLE
  );
  set_smell("default","");
  set_listen("default","");
  set_items(([
    ]));
  set_exits( ([
    "north":"/d/darkwood/castle/tower1c"
    ]) );
}
