//Coded by Bane//
//Updated by Ergo 28 Dec 2012, changed spawn method to prevent more than one lich existing
#include <std.h>
inherit "/d/laerad/cavern2/special/cavern.c";
object lich;
void create(){
    ::create();
   set_terrain(BUILT_CAVE);
   set_travel(DIRT_ROAD);
    set_short("Liches lair");
    set_long(
	"You are standing in a complex lair of some sort.  Horrible torture "+
	"devices line the walls, skeletons hanging from most of them.  Large wooden "+
	"tables covered in test tubes and glass vials sit to the south.  There are "+
	"what looks like bags of flesh in the southeast corner, a terrible moaning "+
	"emits from one of them."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air smells very musty and old.");
    set_listen("default","You can hear the trickling of water down the walls and passages.");
    set_exits( ([
	"up":"/d/laerad/cavern2/cav32"
    ]) );
}
void reset(){
	//holding object
    object obj;
	::reset();
	//find or create a lich
	obj = find_object_or_load("/d/laerad/mon/lich");
	//is the lich in a valid environment?  if not, move to his lair.
	if(!objectp(environment(obj))){
		obj->move(TO);
	}
	
	//this is essential, or the lich will enter a die->heal infinite loop.
    if(!present("phylactery")){
	new("/d/laerad/cavern2/special/phylactery")->move(this_object());
    }
}
