// ffobj.c
// feather_fall invisible spell obj
// Thorn@ShadowGate
// 6/13/95

#include <std.h>

inherit OBJECT;

create() {
        ::create();
	set_name("ff object");
    set_id( ({ "climbexclusionx", "ffobjx" }) );
	set_weight(0);
	set_value(0);
}

init() {
	::init();
	add_action("feather_fall", "descend");
}

int feather_fall(string str) {
	object room;
	string dir, dest;
	string *dirs;
	
	room = environment(this_player());
	dirs = room->query_exits();
	if(member_array("descend", dirs) == -1) {
		notify_fail("There is nowhere to descend to here!");
		return 0;
	}
	dest = room->query_exit("descend");
	write("You are a light as a feather as you descend to the ground below!");
	this_player()->move(dest);
	this_player()->force_me("look");
}
