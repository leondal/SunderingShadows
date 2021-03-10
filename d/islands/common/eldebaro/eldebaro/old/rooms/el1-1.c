#include <std.h>
#include "/d/islands/common/eldebaro/inherits/eldebaro_in.h"

inherit EL_BEACH_ROOM_NE;

void create()
{
      ::create();
	 set_exits(([
       "northeast" : EL_ROOMS+"el2-2",
       "north" : EL_ROOMS+"el2-1", 
	 "east" : EL_ROOMS+"el1-2"
	 ]));

}

void init() {
  ::init();
}
