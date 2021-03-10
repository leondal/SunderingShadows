#include <std.h>
#include "../theater.h"
inherit PROP;
int FLAG;
	void create(){
	::create();
	add_item(({"crates"}),"%^YELLOW%^Numerous wooden crates have been "+
	"nailed shut and stacked on top of each other on the outer edges of"+
	" this room.  The crates are marked with a colored stripe, seeming "+
	"to suggest some kind of inventory system. One crate seems to have "+
	"fallen onto the floor.");
	add_item(({"crate","lid"}),"%^YELLOW%^A large crate seems to have "+
	"fallen from one of the stacks.  The crate rests in the middle of"+
	" the floor.  The lid to the crate is off center, looking as if "+
	"somone tried to move it.");
	set_exits(([ "west" : ROOMDIR"prop1",
			 "north" : ROOMDIR"prop4",
			]));
}
void init(){
::init();
	add_action("move","move");
	add_action("move","shove");
}
int move(string str){
 	if(str != "crate" &&
       str != "crates" &&
       str != "lid")
      return notify_fail("Move what?\n");

   	tell_object(TP,"%^YELLOW%^You shove the lid of the crate away,"+
	" revealing an opening inside of it.");
	tell_room(ETP,"%^YELLOW%^"+TPQCN+" shoves the lid of the crate"+
	" away, revealing an opening inside of it.",TP);
      remove_item("crate");
	add_item(({"crate"}),"%^YELLOW%^The lid to the crate has been "+
	"removed, revealing a hollowed out interior.  The back of the "+
	"crate has been removed, connecting to an opening inside on the"+
	" other side.");
   	add_exit(ROOMDIR"prop3","crate");
		FLAG = 1;
		return 1;
}
void reset() {
	::reset();
		FLAG=0;
	return;
}
