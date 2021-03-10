
#include <std.h>

inherit "/d/attaya/spec/cliff";

void create(){
	::create();
	set_name("Obsidian staircase.");
    set_long(::query_long()+"You are very high up, and the air is getting somewhat thin. All around you is a white haze, blurring the ocean in the distance.");
       set_exits(([
          "up":"/d/attaya/cliff68",
          "down":"/d/attaya/cliff66",
]));
}

void init() {
     ::init();
add_action("jump_off", "jump");
}
int jump_off(string str) {
    write("You scream in agony as you jump from the staircase!\n");
    say((string)this_player()->query_cap_name()+" screams in agony as they jump from the staircase!\n");
    this_player()->move_player("/d/attaya/cliffdock.c");
    write("%^BOLD%^%^RED%^You bounce off the cliff face and slam into the dock!\n");
    say((string)this_player()->query_cap_name()+" Slams into the ground after careening over the cliff face!\n");
    this_player()->do_damage((random(500)));
    return 1;
}

