//Coded by Bane//
// changed to use CROOM to control the knight re-spawning *Styx* 12/11/02
#include <std.h>

// inherit "/d/laerad/cavern1/special/cavern.c";
inherit CROOM;

void create() {
    ::create();
   set_repop(50);
   set_monsters( ({"/d/laerad/mon/knight"}), ({1}) );
   set_terrain(NAT_TUNNEL);
   set_travel(FOOT_PATH);
    set_property("no teleport",1);
    set_short("Laerad caverns");
    set_long(
	"%^BOLD%^%^BLACK%^You are standing in an underground cavern system. %^BLUE%^A small stream "+
	"is running along one of the walls winding its way through the room.%^BLACK%^ "+
	"The ceiling is fairly low, only about 9 feet from the ground. %^GREEN%^Lichen "+
	"and other assorted mosses cover about 90 percent of the walls, %^ORANGE%^glowing "+
    "a strange fluorescent yellow and lighting up the area.%^BLACK%^ Stalactites "+
	"and stalagmites litter the ceilings and floor."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is surprisingly clean and refreshing.");
    set_listen("default","You can hear the trickling of the stream.");
    set_exits( ([
	"up":"/d/laerad/cavern1/cave",
	"northeast":"/d/laerad/cavern1/cav002",
	"northwest":"/d/laerad/cavern1/cav003",
	"southeast":"/d/laerad/cavern1/cav005",
	"southwest":"/d/laerad/cavern1/cav004"
    ]) );
    set_pre_exit_functions( ({"up"}), ({"no_mon"}) );
}
void reset(){
    ::reset();
    if(!present("note")) new("/d/laerad/cavern1/special/note")->move(this_object());
/* changed to be controlled by CROOM
    if(!random(5)){
	if(!present("knight")) new("/d/laerad/mon/knight")->move(TO);
    }
*/
}

int no_mon(){
    if(TP->query_property("wandermon")) return 0;
    else return 1;
}
