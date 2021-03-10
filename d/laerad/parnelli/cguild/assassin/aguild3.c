//Assassins guild hall coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(DIRT_ROAD);
    set_name("Assassins guild");
    set_short("Assassins guild");
    set_long(
	"You have walked into the local suppliers office.  People come "+
	"here for things they can't get on the streets.  The business is "+
	"run out of this closet of a room so as to not attract any unwanted "+
	"attention."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_listen("default","The room is deathly silent.");
    set_smell("default","The room smells strangely fresh and untainted.");
    set_items( ([
    ]) );
    set_exits( ([
	"west":"/d/laerad/parnelli/cguild/assassin/aguild1"
    ]) );
}
void reset(){
    ::reset();
    if(!present("hynth")){
	new("/d/laerad/parnelli/cguild/assassin/hynth")->move(this_object());
    }
}
