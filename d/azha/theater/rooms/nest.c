#include <std.h>
#include "../theater.h"
inherit ROOM;
int FLAG;
	void create(){
   	::create();
   	set_property("indoors",1);
   	set_property("light",1);
	set_property("no sticks",1);
	set_property("no teleport",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^RED%^Desert Sun Theater - Platform");
   	set_short("%^RED%^Desert Sun Theater - Platform");
   	set_long("%^ORANGE%^A set of wooden steps lead "+
		"down to the large platform that is built over the "+
		"support beams of the theater.  The ceiling above is ridden"+
		" with holes, allowing a stale breeze to blow through.  "+
		"Shredded canvas backdrops hang at odd angles, the shredded"+
		" fabric blowing in the winds.  The %^RESET%^dust%^ORANGE%^"+
		" in here is so thick,"+
		" covering the floor with large clumps.  The western edge "+
		"of the platform is shattered and broken, creating an impenetrable"+
		" wall of %^RESET%^stone%^ORANGE%^, %^YELLOW%^timber%^RESET%^%^ORANGE%^"+
		" and debris.  The beams that crisscross the upper parts of this room "+
		"have been left in tact mostly.  \n");
   	set_smell("default","%^RED%^A musty stale scent hangs in the air.");
   	set_listen("default","%^BOLD%^%^BLUE%^The backdrops ruffle in the stale breeze.");
  	set_items(([
      	({"backdrops","backdrop","canvas"}) : "%^YELLOW%^The shredded "+
	"remains of once elaborate backdrops hang at odd angles around the"+
	" room.  Most of them hang diagonally with the torn and ripped fabric allowed"+
	" to blow in the breeze, making it difficult to make out much detail"+
	" of this room.",
      	({"holes","beams","ceiling"}) : "%^BOLD%^%^BLUE%^The ceiling"+
	" is ridden with multiple holes, as if something was trying to escape"+
	" through them.  The skeletal wooden frame of the ceiling is mostly "+
	"intact, though a number of the beams have been shattered, and hang "+
	"limp.  The holes in the ceiling alone for a stale dead breeze to blow"+
	" through the room.",
		({"debris","wall","stone","timber"}) : "%^BOLD%^%^WHITE%^The impenetrable"+
	" wall of stone, timber and debris has ripped through the wooden floor "+
	"to the west.  The western area, you can surmise, must be where the stage"+
	" and backstage area of the theater would have been.  If this thick wall"+
	" was not here, you might have been able to even access the backstage, "+
	"but there is no moving that amount of rubble.",
	]));
	set_exits(([ "east" : ROOMDIR"cat8",
	]));
}
void init(){
::init();
        add_action("tear","tear");
        add_action("tear","rip");
}
int tear(string str){
     	if(str != "backdrop" && str != "backdrops") 
      	return notify_fail("Tear what?\n");
	tell_object(TP,"%^BOLD%^%^BLUE%^You rip through the tangled "+
		"mass of backdrops and find a ladder that leads down.");
	tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" rips through the"+
		" tangled mass of backdrops and finds a ladder that leads"+
		" down.",TP);
			add_exit(ROOMDIR"under1","down");
                	FLAG = 1;
    	return 1;
}
void reset()
{
    	::reset();
    	if(!present("ivashka")) 
{
	new(MOB"ivashka_harpy")->move(TO) ;
    	return;
}
	FLAG=0;
}