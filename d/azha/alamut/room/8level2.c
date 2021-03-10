// Test room
// Thorn@ShadowGate
// 000911
// Alamut
// 8level2.c

#include <std.h>

inherit ROOM;

void create() {
  	room::create();
    set_light(2);
    set_short("Successful climb of Alamut");
  	set_long(
@DAI
%^BOLD%^Successful climb of Alamut%^RESET%^
You rock!

You can decsend now if you dare.
DAI
    );
  	set_listen("default","You hear the wind moaning around the high rock wall.");
    set_climb_exits((["descend":({ "forest8",4,6,500})]));
    set_fall_desc(
@FALL
You fall down about 100 feet. You land on some rocks, and other
debris. Pain racks your body.
FALL
    );

 }

void reset(){
	::reset();
}
