
#include <std.h>

inherit "/d/attaya/spec/cliff";

void create(){
	::create();
	set_name("Obsidian staircase.");
	set_property("indoors",0);
	set_property("light",1);
       set_exits(([
          "up":"/d/attaya/cliff5",
          "down":"/d/attaya/cliff3",
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
write("%^BOLD%^%^RED%^You bounce off the cliff face and slam into the dock!\n");
say((string)this_player()->query_cap_name()+" Slams into the ground after careening over the cliff face!\n");
this_player()->do_damage((random(250)));
return 1;
}
