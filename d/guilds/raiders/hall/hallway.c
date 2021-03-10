#include <std.h>

inherit VAULT;

void reset() {
     	::reset();
//  	if(!present("tavares"))new("/d/guilds/raiders/mons/tavares")->move(TO);
}
void create(){
   	::create();
   set_terrain(BUILT_CAVE);
   set_travel(PAVED_ROAD);
   	set_indoors(1);
   	set_light(1);
//   	set_property("no teleport",1);
   	set_short("Short Hallway");
   	set_long(
@DESC
The room is very short and ends in a door to the north.  To the south is the members area.  There is a small plaque on the wall here.
DESC
   	);
   	set_smell("default","The smell of damp mildew can be detected in the air.");
   	set_listen("default","Your footsteps echo around the room as your feet "+
   		"hit the cold hard floor.");

    	set_items(([
        	"plaque" : "This is a small black plaque with words engraved on it, "+
        		"maybe you should read it.\n"
	]));

    	set_door("iron door","/d/guilds/raiders/hall/main.c","north","guild earring");
    	set_locked("iron door",1,"lock");
    		("/d/guilds/raiders/hall/main.c")->set_locked("iron door",1,"lock");
	lock_difficulty("iron door",-30,"lock");
	set_lock_description("iron door","lock","This lock looks complicated and "+
		"its inner workings are hard to determine");
    	set_door_description("iron door","This is a heavy iron door barring passage into "+
    		"the northern exit.  The door looks relatively new, the whole thing is "+
    		"nice and shiny, but the hinges are nowhere to be seen.  There is one "+
    		"lock visible.");
    	set_string("iron door","open","The door swings open to the next room.");

    	set_trap_functions(({"iron door"}),({"poison_me"}),({"pick"}));

   	set_exits(([
      	"north":"/d/guilds/raiders/hall/main.c",
      	"south":"/d/guilds/raiders/hall/members.c"
      	]));
}
void init() {
  ::init();
  add_action("read","read");
}
int read(string str) {
  if(!str) {
        tell_object(TP,"Read what?");
        return 1;
    }
  if(str == "plaque"){
     write("%^BOLD%^%^BLUE%^"+
		"This room is one of the marks left by Vethor, \n"+
		"Last of the Crimson Daggers and leader of the \n"+
		"Tempered Blades.  It was designed to deter \n"+
		"unwanted entrance to the guild hall.%^RESET%^");
     return 1;
     }
}
int poison_me(string str){
	int poison;
	poison = roll_dice(30,10);
	TP->add_poisoning(poison);
	TP->setPoisoner(TO);
	tell_object(TP,"%^BOLD%^%^GREEN%^You feel a sharp prick in your hand as you work "+
		"the lock.");
	TP->force_me("emote pulls his hand back in pain and shakes it slightly");
    	return 1;
}
