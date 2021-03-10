//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_terrain(HUT);
    set_travel(DIRT_ROAD);
    set_name("Wooden hut");
    set_short("A Wooden hut");
    set_long(
        "%^BOLD%^A Wooden hut%^RESET%^
You are standing in a large wooden hut.  The living space "+
	"is actually much smaller than it appears to be from "+
	"the outside.  The room reeks of sweat and urine.  "+
	"There are animal skins all over the floor covered "+
	"with flies.  A small pan sits in the corner of the "+
	"hut next to a fire pit."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The room smells so bad it makes your stomach churn.");
    set_listen("default","You can hear the buzzing of flies and other insects.");
    set_exits( ([
        "northwest":"/d/laerad/parnelli/systyquah/sys046"
    ]) );
}
void reset(){
    ::reset();
    if(!present("troll")){
	new("/d/laerad/mon/troll1")->move(this_object());
    }
}
