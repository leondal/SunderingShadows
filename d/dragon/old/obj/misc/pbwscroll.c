#include <std.h>

inherit OBJECT;


void create() {
	::create();

	set_id(({"scroll"}));
	set_name("scroll");
	set("short","a scroll");
	set("long","This scroll is covered with little signs of wards. 
Both ends have images of dragons breathing fire on a man.");
	set_weight(2);
	set_value(100);
}

int __Read(string str) {

	if(!str) return 0;
	if(str != "scroll") return 0;
	write("%^GREEN%^ You read the scroll and the images of dragons 
glow and change.\n\n The dragons have stopped breathing.");
	tell_room(environment(TP),TPQCN+" reads the scroll.",TP);
    set("long","This scroll is glowing, you cannot make out the symbols.");
	remove_action("read","read");
	call_out("dest",(roll_dice(2,40)+1),TP);
	TP->set_property("strength","breath weapon");
 	return 1;
}

void dest(object person) {
	person->remove_property("strength");
	tell_object(person,"%^BOLD%^%^YELLOW%^The scroll suddenly stops glowing and 
crumbles.");
	TO->remove();
}
