#include "../shadow.h"
inherit "/d/shadow/room/forest/road1";

void create(){
    ::create();
    set_short("On The Quiet Forest Road");
    set_items(([
	"road":"A road through the village.",
	"village":"A small village with farmers working."
	]));
 
    set_exits(([
	"east" : VILLAGEDIR+"mainroad1",
//	"north" : VILLAGEDIR+"flugar",
	"west" : VILLAGEDIR+"mainroad3"

   	]));
    set_smell("default","You smell fresh air and the odor of baked goods mixed with manure.");
    set_listen("default","You can hear the sounds of busy farmers doing their chores.");
}






















































