#include <std.h>
#include "/d/islands/common/eldebaro/inherits/eldebaro_in.h"

inherit EL_BEACH_ROOM_N;

void create()
{
      ::create();
	 set_exits(([
       "north" : EL_ROOMS+"el2-11",
       "west" : EL_ROOMS+"el1-10", 
	 "east" : EL_ROOMS+"el1-12",
	 "northeast" : EL_ROOMS+"el2-12", 
	 "northwest" : EL_ROOMS+"el2-10",
	 ]));

}

void init() {
  ::init();
}
