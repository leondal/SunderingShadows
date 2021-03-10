#include <std.h>

inherit "/d/koenig/fields/fields_inherit.c";

void create() {
    	::create();
    	set_exits(([
       	"north" : "/d/koenig/fields/room/field14",
       	"east" : "/d/koenig/fields/room/field20",
       	"west" : "/d/koenig/fields/room/field10"
    	] ));
}

void init() {
  ::init();
}

void reset() {
  ::reset();
}