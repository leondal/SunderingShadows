
#include <std.h>

inherit "/d/attaya/tower/spec/tower";

void create(){
	::create();
        set_travel(STAIRWAY);
	set_name("escape route");
	set_short("escape route");
	set_property("indoors",1);
	set_property("light",2);
set_long("
    This is the end of the ladder.  You dangle at the end of the metal shaft over an enormous sea of raging water.  The water rushes into black holes to the south.  You feel very insignificant amidst such power.  
    You wonder if taking the chance and jumping into the raging waters would allow you to escape greater dangers in the fortress...
    It would be quite a gamble.  It is quite likely that you will be rushed away to a watery grave against a debris grate where the sheer force of the water would tear the flesh from your bones as it makes more room to shove through.
");
    set_listen("default", "The raging water all around you is deafening.");
       set_exits(([
          "up":"/d/attaya/tower/floor26",
]));
	
	
}
void init() {
     ::init();
add_action("jump_off", "jump");
}
int jump_off(string str) {
write("%^BOLD%^%^BLUE%^You jump from the ladder into the raging surf!\n");
say((string)this_player()->query_cap_name()+" jumps from the ladder!\n");
this_player()->move_player("/d/attaya/tower/water");
say((string)this_player()->query_cap_name()+" lands in the waters and vanishes beneath them!\n");
this_player()->do_damage(random(75));
return 1;
}
