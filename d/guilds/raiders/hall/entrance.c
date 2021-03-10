// /d/guilds/raiders/hall/entrance.c

#include <std.h>

inherit VAULT;

void create(){
   	::create();
   set_terrain(BUILT_CAVE);
   set_travel(PAVED_ROAD);
   	set_indoors(1);
   	set_light(2);
   	set_short("Mountain entrance");
   	set_long(
@DESC
You are inside the rock of the mountains. There is stone stairwell
here, leading down towards darkness. One torch is hanging on the wall
unlit. The stone ceiling is low, hanging just above a tall human's head. In the northwest you see a door.
DESC
   	);
   	set_smell("default","The smell of damp mildew can be detected in the "+
   		"air towards the steps.");
   	set_listen("default","Your own soft breathing can be heard echoing around.");

     	set_door("door","/d/guilds/raiders/hall/cave1","northwest","lock");
	set_door_description("door","This is a simple wooden door with an ornate "+
    			"looking doorknob.  There are no locks you can see on this door.");
	set_lock_description("door","lock","There is no lock present.");

   	set_exits(([
      	"down":"/d/guilds/raiders/hall/members",
      	"northwest" : "/d/guilds/raiders/hall/cave1"
   	]));

	restore_room();

}
void init() {
  	::init();
  	add_action("replace","replace");
  	add_action("open_em","open");
  	add_action("push_em","push");
}
int open_em(string str) {
  	if(!str) {
        	tell_object(TP,"Open what?");
        	return 1;
    	}
  	if(str == "door"){
		tell_room(TO,""+TPQCN+" tries to open the door and fails.\n",TP);
		tell_object(TP,"You try to open the door and fail.\n");
     		return 1;
     }
}
int push_em(string str) {
  	if(!str) {
        	tell_object(TP,"Push what?");
        	return 1;
    	}
  	if(str == "door"){
		tell_room(TO,""+TPQCN+" pushes open the door.\n",TP);
		tell_object(TP,"You push open the door and see the next room.\n");
    		set_door_description("door","This is a simple wooden door with an ornate "+
    			"looking doorknob.  There are no locks you can see on this door.");
    		("/d/guilds/raiders/hall/cave1")->set_door_description("door","This is "+
    			"a simple wooden door with an ornate looking doorknob.  There are "+
    			"no locks you can see on this door.");
    	    	set_open("door",1);
     			("/d/guilds/raiders/hall/cave1")->set_open("door",1);
     		save_room_shallow();
     		return 1;
     }
}
int replace(string str) {
  	if(!str) {
        	tell_object(TP,"Replace what?");
        	return 1;
    	}
  	if(str == "thread"){
		tell_room(TO,""+TPQCN+" picks up something from the floor then "+
			"closes the door carefully.\n",TP);
		tell_object(TP,"You pick the thread up from the floor then "+
			"carefully replace the thread as you close the door.\n");
    		set_door_description("door","This is a simple wooden door with an ornate "+
    			"looking doorknob.  There are no locks you can see on this door, "+
    			"however a small thread can be see sticking through the side of "+
    			"the door.");
    		("/d/guilds/raiders/hall/cave1")->set_door_description("door","This "+
    			"is a simple wooden door with an ornate looking doorknob.  There "+
    			"are no locks you can see on this door, however a small thread can "+
    			"be see sticking through the side of the door.");
    	    	set_open("door",0);
     			("/d/guilds/raiders/hall/cave1")->set_open("door",0);
    		save_room_shallow();
    		return 1;
     }
}