//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_terrain(HUT);
    set_travel(DIRT_ROAD);
    set_short("A small straw hut");
    set_long(
	"You are standing in a small straw hut.  A straw mat rests along the wall, and "+
	"a tiny wooden table sits in the middle of the room.  The hut is terribly "+
	"small but strangely comfortable."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The hut smells like someone just cooked a tasty meal.");
    set_listen("default","You can hear the sounds of the forest animals outside.");
    set_exits( ([
    ]) );
}
void reset(){
    ::reset();
    if(!present("sage")){
	new("/d/laerad/mon/sage")->move(this_object());
    }
}
