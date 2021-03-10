#include <std.h>
#include "/d/islands/common/eldebaro/inherits/eldebaro_in.h"

inherit EL_BEACH_ROOM_N;

void create()
{
      ::create();
	 set_exits(([
       "north" : EL_ROOMS+"el2-13",
       "west" : EL_ROOMS+"el1-12", 
	 "east" : EL_ROOMS+"el1-14",
	 "northeast" : EL_ROOMS+"el2-14", 
	 "northwest" : EL_ROOMS+"el2-12",
	 ]));

}

void init() {
  ::init();
}
