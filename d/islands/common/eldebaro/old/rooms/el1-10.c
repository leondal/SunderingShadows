#include <std.h>
#include "/d/islands/common/eldebaro/inherits/eldebaro_in.h"

inherit EL_BEACH_ROOM_N;

void create()
{
      ::create();
	 set_exits(([
       "north" : EL_ROOMS+"el2-10",
       "west" : EL_ROOMS+"el1-9", 
	 "east" : EL_ROOMS+"el1-11",
	 "northeast" : EL_ROOMS+"el2-11", 
	 "northwest" : EL_ROOMS+"el2-9",
	 ]));

}

void init() {
  ::init();
}
