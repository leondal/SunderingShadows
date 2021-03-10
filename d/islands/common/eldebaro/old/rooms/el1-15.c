#include <std.h>
#include "/d/islands/common/eldebaro/inherits/eldebaro_in.h"

inherit EL_BEACH_ROOM_NW;

void create()
{
      ::create();
	 set_exits(([
       "north" : EL_ROOMS+"el2-15",
       "west" : EL_ROOMS+"el1-14", 
	 "northwest" : EL_ROOMS+"el2-14",
	 ]));

}

void init() {
  ::init();
}
