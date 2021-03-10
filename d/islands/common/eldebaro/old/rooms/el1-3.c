#include <std.h>
#include "/d/islands/common/eldebaro/inherits/eldebaro_in.h"

inherit EL_BEACH_ROOM_N;

void create()
{
      ::create();
	 set_exits(([
       "north" : EL_ROOMS+"el2-3",
       "west" : EL_ROOMS+"el1-2", 
	 "east" : EL_ROOMS+"el1-4",
	 "northeast" : EL_ROOMS+"el2-4", 
	 "northwest" : EL_ROOMS+"el2-2",
	 ]));

}

void init() {
  ::init();
}
