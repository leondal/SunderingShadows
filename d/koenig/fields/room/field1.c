#include <std.h>

inherit "/d/koenig/fields/fields_inherit.c";

void create() {
    	::create();
      set_long( ::query_long()+"To the northwest, you can see a narrow "+
         "pathway that leads around a bend.");
    	set_exits(([
       	"south" : "/d/koenig/fields/room/field2",
       	"east" : "/d/koenig/fields/room/field6",
            "northwest" : "/d/koenig/fields/room/house1"
    	] ));
}

void init() {
  	::init();
}

void reset() {
  	::reset();
}