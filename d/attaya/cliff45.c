
#include <std.h>

inherit "/d/attaya/spec/cliff";

void create(){
	::create();
	set_name("Top of the obsidian staircase.");
	set_short("Top of the obsidian staircase.");
	set_property("indoors",0);
	set_property("light",2);
set_long("
    You stand atop the cliff face!  The Obsidian Staircase starts here and journeys nearly a mile down the cliff to a dock on the flaming river.  Before you lie the enormous gates to the Crystalline Tower of the Black Dawn, a mystical structure that few have witnessed first hand.  
    It is difficult to breathe here as the air is much thinner than you are used to.  It is also very cold.  
    You feel proud to have made it this far...  Looking at the walls to the Tower, you realize how much farther you have yet to go.  You begin to wonder whether or not you are truely ready for what lies within.

");
       set_exits(([
          "north":"/d/attaya/base/enter",
          "down":"/d/attaya/cliff44",
]));
	
      set_smell("default", "The air is much thinner than you are accustomed to at this altitude.");
      set_listen("default", "The winds whip past this cliff chilling you to the bone.");
	
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
