
#include <std.h>

inherit "/d/attaya/spec/cliff";

void create(){
	::create();
	set_name("Obsidian staircase.");
	set_short("Obsidian staircase.");
	set_property("indoors",0);
	set_property("light",2);
set_long("
    You are upon the Obsidian Staircase of the Kinnesaruda, a series of steps and mountain ledges that winds its way from the River of Flame to the Crystalline Tower of the Black Dawn.  
    It is terribly cold here and you rub your arms together to keep warm.  The Tower stands not far above you.  You are in it's shadow now!

");
       set_exits(([
          "up":"/d/attaya/cliff45",
          "down":"/d/attaya/cliff43",
]));
	
      set_smell("default", "The air is getting thinner at this altitude.");
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
