
#include <std.h>

inherit "/d/attaya/spec/cliff";

void create(){
	::create();
	set_name("Obsidian staircase.");
	set_short("narrow groove in the cliff on the Obsidian staircase.");
	set_property("indoors",0);
	set_property("light",1);
set_long("
    This staircase has been cut directly into the cliff wall!  On either side of you is a smooth wall.  It is very dark in here.
    A dark cave swallows the staircase above you.  You can feel a great heat from within it.  You have strong second thoughts on entering there.
");
       set_exits(([
          "up":"/d/attaya/cliff50",
          "down":"/d/attaya/cliff48",
]));
	
      set_smell("default", "The air smells of smoke and ash");
      set_listen("default", "The wind whistles through this thin groove in the mountainside");
	
}
void init() {
     ::init();
add_action("jump_off", "jump");
}
int jump_off(string str) {
write("You scream in agony as you jump from the staircase!\n");
say((string)this_player()->query_cap_name()+" screams in agony as they fall down the stairs!\n");
write("You tumble down the stairs and fly over the ledge into the open air!\n");
this_player()->move_player("/d/attaya/cliffdock.c");
write("%^BOLD%^%^RED%^You bounce off the cliff face and slam into the dock!\n");
say((string)this_player()->query_cap_name()+" Slams into the ground after careening over the cliff face!\n");
this_player()->do_damage((random(250)));
return 1;
}
