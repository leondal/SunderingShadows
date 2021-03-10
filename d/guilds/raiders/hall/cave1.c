//changed by Circe 12/14/03 to allow for new location near Juran.
#include <std.h>
//#include "../hills.h"

inherit VAULT;

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
	set_short("A hidden cave");
	set_long(
		"You have discovered a cave hidden in the side of the mountain. It is"+
		" relatively small, and there isn't much here. This cave might once"+
		" have been used as a place where adventurers stored extra supplies"+
		" in case their own were broken or lost. It could have been a refuge"+
		" against the snow and ice during a harsh storm. Or it could simply"+
		" have remained hidden all this time until you stumbled upon it. "+
		" The way the cliff side juts further out to prevent the cave from"+
		" easily being spotted also blocks most of the wind from coming inside,"+
		" keeping this place relatively warm. There is a door in the southeast "+
		"corner of the room.\n"
	);
	set_search("default","A small, cramped, empty cave.");
	set_smell("default","The air of the cave is stale and dry.");
	set_listen("default","The wind whips against the cliff face outside.");
	set_items(([
		"floor" : "The floor is dusty and scattered with rocks. The only"+
		" footprints here seem to be your own.",
		"ceiling" : "The ceiling is really just where the outer wall meets with"+
		" the inner side of the mountain, coming together in a sudden point.",
		({"wall","walls"}) : "The back walls are riddled with several cracks,"+
			" some of them are rather large."
	]));

	set_door("door","/d/guilds/raiders/hall/entrance.c","southeast","lock");
    	set_locked("door",0,"lock");
     		("/d/guilds/raiders/hall/entrance.c")->set_locked("door",0,"lock");
    	set_door_description("door","This is a simple wooden door with an ornate "+
    		"looking doorknob.  There are no working locks you can see on this door, "+
    		"however a small thread can be see sticking through the side of the door.");
	set_lock_description("door","lock","There is no lock present.");

	
	set_exits(([
		"out" : "/d/shadow/room/forest/owagon21",
		"southeast" : "/d/guilds/raiders/hall/entrance.c"
	]));

	restore_room();
}
//add query for open and closed doors to prevent extra actions//
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
		tell_room(ETO,""+TPQCN+" tries to open the door and fails.\n",TP);
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
		tell_room(ETO,""+TPQCN+" pushes open the door.\n",TP);
		tell_object(TP,"You push open the door and see the next room.\n");
    		set_door_description("door","This is a simple wooden door with an ornate "+
    			"looking doorknob.  There are no locks you can see on this door.");
    		("/d/guilds/raiders/hall/entrance.c")->set_door_description("door","This is "+
    			"a simple wooden door with an ornate "+
    			"looking doorknob.  There are no locks you can see on this door.");
    	    	set_open("door",1);
     			("/d/guilds/raiders/hall/entrance.c")->set_open("door",1);
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
		tell_room(ETO,""+TPQCN+" picks up something from the floor then "+
			"closes the door carefully.\n",TP);
		tell_object(TP,"You pick the thread up from the floor then "+
			"carefully replace the thread as you close the door.\n");
    		set_door_description("door","This is a simple wooden door with an ornate "+
    			"looking doorknob.  There are no locks you can see on this door, "+
    			"however a small thread can be see sticking through the side of "+
    			"the door.");
    		("/d/guilds/raiders/hall/entrance.c")->set_door_description("door","This "+
    			"is a simple wooden door with an ornate looking doorknob.  There "+
    			"are no locks you can see on this door, however a small thread can "+
    			"be see sticking through the side of the door.");
    	    	set_open("door",0);
    			("/d/guilds/raiders/hall/entrance.c")->set_open("door",0);
     		save_room_shallow();
     		return 1;
     }
}