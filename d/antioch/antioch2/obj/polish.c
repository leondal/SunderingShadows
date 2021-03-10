#include <std.h>
#include "../antioch.h"
inherit OBJECT;

int empty;

void create()
{
	::create();
	set_name("bottle of polish");
	set_id(({"polish","bottle of polish","a bottle of polish","armor polish"}));
	set_short("%^RESET%^a bottle of polish");
	set_long(
	"This is a bottle full of polish. It appears to be the type for"+
	" armor, but you aren't quite sure. The bottle itself is a metal"+
	" container with a stopper. From the smell it is quite strong."
	);
	set_weight(2);
	set_value(10);
}

void init()
{
	::init();
	add_action("polish","polish");
}

int polish(string str)
{
	object obj;

	if(empty) {
		tell_object(ETO,"The bottle of polish is empty!");
		return 1;
	}
	if(!str) {
		tell_object(ETO,"Polish what?");
		return 1;
	}
	if(str == "rusty armor") {
		if(present("rusty armor",environment(ETO))) {
			obj = present("rusty armor",environment(ETO)); 
			ETO->set_paralyzed(4,"You are polishing the armor.");
			tell_object(ETO,"%^BOLD%^You apply the polish to the armor"+
			" and begin to scrub. The rust comes away and the armor"+
			" is clean again, you can hardly believe it's the same"+
			" armor the change is so remarkable!");
			tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+""+
			" carefully polishes some rusty armor and it becomes clean"+
			" again.",ETO);
			obj->remove();
			new("/d/antioch/valley/obj/eagle_plate")->move(environment(ETO));
			set_value(0);
			set_short("%^RESET%^an empty bottle of polish");
			set_long("This bottle of polish is empty.");
			set_weight(1);
			empty = 1;
			return 1;
		}
		if(!present("rusty armor",environment(ETO)) && present("rusty armor",ETO)) {
         tell_object(ETO,"You can't polish the armor while you hold it,"+
			" try setting it down first.");
			return 1;
		}
		if(!present("rusty armor",environment(ETO)) && !present("rusty armor",ETO)) {
			tell_object(ETO,"There is no rusty armor here.");
			return 1;
		}
		if(!present("rusty armor",ETO) && !present("rusty armor",environment(ETO))) {
			tell_object(ETO,"You don't appear to have that.");
			return 1;
		}
	}			
	else {
      tell_object(ETO,"The only thing this polish is good for is %^YELLOW%^rusty armor%^RESET%^.");
		return 1;
	}
}
