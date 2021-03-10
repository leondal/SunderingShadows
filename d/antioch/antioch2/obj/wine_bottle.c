#include <std.h>
#include "../antioch.h"
inherit OBJECT;

int drinks;

void create()
{
	::create();
	set_name("bottle");
	set_short("A bottle of wine");
	set_id(({"bottle","wine","drink","bottle of wine"}));
	set_long(
	"This is a bottle of a finely aged wine. It is dark red in color and has"+
	" a light, sweet fragrance. This is perfect for taking on a picnic, or"+
	" off to somewhere to be by yourself for a bit. You can %^BOLD%^drink"+
	" from bottle%^RESET%^ to take a gulp." 
	);
	set_weight(6);
	set_value(20);
	drinks = 4;
}

void init()
{
	::init();
	add_action("drink","drink");
}

void drink(string str)
{
	if(!living(ETO)) {
		notify_fail("You must be holding the wine bottle to be able to drink from it.\n");
		return 0;
	}
	if(!interactive(ETO)) {
		notify_fail("You must be holding the wine bottle to be able to drink from it.\n");
		return 0;
	}
	if(str == "from bottle" || str == "from wine bottle") {
		if(drinks < 1) {
			notify_fail("The wine bottle is empty.\n");
			return 0;
		}
		if(!ETO->add_intox(175)) {
			notify_fail("You can't stand to drink anymore!\n");
			return 0;
		}
		if(drinks > 1) {
			tell_object(ETO,"You take a long gulp from the wine bottle, the"+
			" warm, sweet liquid slides down your throat.");
			tell_room(environment(ETO),""+ETO->query_cap_name()+" takes a"+
			" long gulp from the wine bottle.",ETO);
//                    ETO->add_intox(175);
			drinks -= 1;
			return 1;
		}
		if(drinks == 1) {
			tell_object(ETO,"You take the last gulp from the bottle, the"+
			" warm, sweet liquid slides down your throat.");
			tell_room(environment(ETO),""+ETO->query_cap_name()+" drinks the"+
			" last of the wine from the bottle.",ETO);
//                    ETO->add_intox(175);
			drinks -= 1;
			TO->set_long("This is an empty bottle of wine.");
			TO->set_short("An empty bottle of wine");
			TO->set_id(({"empty bottle","bottle","empty bottle of wine","empty wine bottle"}));
			TO->set_weight(1);
			TO->set_value(1);
			return 1;
		}
	}
}
