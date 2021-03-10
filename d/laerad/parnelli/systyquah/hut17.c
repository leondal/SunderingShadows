//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_terrain(HUT);
    set_travel(DIRT_ROAD);
    set_name("Systyquah's magic shop");
    set_short("Systyquah's magic shop");
    set_long(
        "%^BOLD%^Systyquah's magic shop%^RESET%^
You are standing in Systyquah's shop of magic.  There is a  "+
	"massive bookcase covering each of the walls in this "+
	"room all filled with books and scrolls.  A few candles "+
	"are lit around a small round table near the center of "+
	"the room.  A very old troll sits here studying."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The room smells of scented candles.");
    set_listen("default","You can hear the quiet shuffling of turning pages.");
    set_property("no attack",1);
    set_exits( ([
    ]) );
}
void reset(){
    ::reset();
    if(!present("fargastipius")){
	new("/d/laerad/mon/farg")->move(this_object());
    }
}
