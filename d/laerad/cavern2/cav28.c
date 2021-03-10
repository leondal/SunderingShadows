//Coded by Bane//
#include <std.h>
inherit "/d/laerad/cavern2/special/cavern.c";
void create(){
    ::create();
    set_short("Laerad caverns");
    set_long(
	"You are in some kind of underground cavern system.  The air here is damp "+
	"and humid.  The area is much darker here below the first level of the caves.  "+
	"The ground is covered in a few inches of water, it trickles down from the "+
	"walls all around you.  Strange mosses and fungi grow on the walls."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air smells very musty and old.");
    set_listen("default","You can hear the trickling of water down the walls and passages.");
    set_exits( ([
	"northeast":"/d/laerad/cavern2/cav27",
	"southwest":"/d/laerad/cavern2/cav31",
	"southeast":"/d/laerad/cavern2/cav29",
	"south":"/d/laerad/cavern2/cav32"
    ]) );
    set_pre_exit_functions( ({"south"}),({"go_south"}) );
}
void reset(){
    ::reset();
    if(!present("wall")){
	new("/d/laerad/mon/lwall")->move(this_object());
    }
}
void go_south(){
    if(present("wall") && (string)TP->query_name() != "hansoth"){
	write("The wall prevents you from going that way!");
	return 0;
    }
    return 1;
}
