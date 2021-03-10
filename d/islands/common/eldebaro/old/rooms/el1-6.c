#include <std.h>
#include "/d/islands/common/eldebaro/inherits/eldebaro_in.h"

inherit EL_BEACH_ROOM_N;

void create()
{
      ::create();
	 set_exits(([
       "north" : EL_ROOMS+"el2-6",
       "west" : EL_ROOMS+"el1-5", 
	 "east" : EL_ROOMS+"el1-7",
	 "northeast" : EL_ROOMS+"el2-7", 
	 "northwest" : EL_ROOMS+"el2-5",
	 ]));

}

void init() {
  ::init();
}
