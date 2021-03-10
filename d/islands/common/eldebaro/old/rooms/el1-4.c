#include <std.h>
#include "/d/islands/common/eldebaro/inherits/eldebaro_in.h"

inherit EL_BEACH_ROOM_N;

void create()
{
      ::create();
	 set_exits(([
       "north" : EL_ROOMS+"el2-4",
       "west" : EL_ROOMS+"el1-3", 
	 "east" : EL_ROOMS+"el1-5",
	 "northeast" : EL_ROOMS+"el2-5", 
	 "northwest" : EL_ROOMS+"el2-3",
	 ]));

}

void init() {
  ::init();
}
