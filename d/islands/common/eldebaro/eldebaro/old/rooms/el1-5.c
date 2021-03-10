#include <std.h>
#include "/d/islands/common/eldebaro/inherits/eldebaro_in.h"

inherit EL_BEACH_ROOM_N;

void create()
{
      ::create();
	 set_exits(([
       "north" : EL_ROOMS+"el2-5",
       "west" : EL_ROOMS+"el1-4", 
	 "east" : EL_ROOMS+"el1-6",
	 "northeast" : EL_ROOMS+"el2-6", 
	 "northwest" : EL_ROOMS+"el2-4",
	 ]));

}

void init() {
  ::init();
}
