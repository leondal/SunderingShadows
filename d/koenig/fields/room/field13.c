#include <std.h>

inherit "/d/koenig/fields/fields_inherit.c";

void create() {
    	::create();
    	set_exits(([
       	"south" : "/d/koenig/fields/room/field14",
       	"north" : "/d/koenig/fields/room/field12",
       	"east" : "/d/koenig/fields/room/field18",
       	"west" : "/d/koenig/fields/room/field8"
    	] ));
}

void init() {
  ::init();
}

void reset() {
  ::reset();
}
