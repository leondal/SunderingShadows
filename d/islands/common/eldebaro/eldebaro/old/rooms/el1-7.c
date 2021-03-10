#include <std.h>
#include "/d/islands/common/eldebaro/inherits/eldebaro_in.h"

inherit EL_BEACH_ROOM_N;

void create()
{
      ::create();
	 set_exits(([
       "north" : EL_ROOMS+"el2-7",
       "west" : EL_ROOMS+"el1-6", 
	 "east" : EL_ROOMS+"el1-8",
	 "northeast" : EL_ROOMS+"el2-8", 
	 "northwest" : EL_ROOMS+"el2-6",
	 ]));

}

void init() {
  ::init();
}
