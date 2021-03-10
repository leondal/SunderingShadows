#include <std.h>

inherit "/d/attaya/spec/cliff";

void create(){
	::create();
	set_name("Obsidian staircase.");
	set_property("indoors",0);
	set_property("light",2);
    set_exits(([
                   "up":"/d/attaya/cliff2",
                   "down":"/d/attaya/cliffdock",
                   ]));
    set_smell("default", "The air smells of smoke and ash");
    set_listen("default", "It is abnormally silent here");
}

void init() {
     ::init();
add_action("jump_off", "jump");
}
int jump_off(string str) {
write("You scream in agony as you jump from the staircase!\n");
say((string)this_player()->query_cap_name()+" screams in agony as they jump from the staircase!\n");
this_player()->move_player("/d/attaya/cliffdock.c");
write("%^BOLD%^%^RED%^You don't have far to fall, and land on your feet!\n");
say((string)this_player()->query_cap_name()+" lands on their feet on the dock!\n");
this_player()->do_damage((random(50)));
return 1;
}

