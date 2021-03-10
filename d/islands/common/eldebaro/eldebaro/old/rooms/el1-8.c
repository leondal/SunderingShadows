#include <std.h>
#include "/d/islands/common/eldebaro/inherits/eldebaro_in.h"

inherit EL_BEACH_ROOM_N;

void create()
{
      ::create();
	 set_exits(([
       "north" : EL_ROOMS+"el2-8",
       "west" : EL_ROOMS+"el1-7", 
	 "east" : EL_ROOMS+"el1-9",
	 "northeast" : EL_ROOMS+"el2-9", 
	 "northwest" : EL_ROOMS+"el2-7",
	 ]));

}

void init() {
  ::init();
}
