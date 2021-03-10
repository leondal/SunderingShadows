#include <std.h>
inherit "/std/food";

void init(){
	::init();
		add_action("eat_me","eat");
}

void create() {
	::create();
		set_name("clam meat");
		set_id(({"food","clam meat","meat"}));
		set_short("a bit of clam meat");
		set_long("%^RESET%^This looks like the fleshy bit of a "+
			"clam. A little slimy and gooey to handle, it would "+
			"probably slide right down if you ate it.");
		set_strength(30);
}

int eat_me(string str){
	object eatfood;
	tell_object(TP,"%^BOLD%^%^BLACK%^The clam's flesh slides "+
		"right down your gullet, leaving a faint briney taste "+
		"behind.");
	tell_room(ETP,"%^BOLD%^%^WHITE%^"+TP->QCN+" slurps the "+
		"clam meat down.",TP);
	remove();
	return 1;
}