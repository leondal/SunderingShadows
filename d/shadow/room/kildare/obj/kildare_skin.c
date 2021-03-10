#include <std.h>
inherit OBJECT;

int drinks;

void create()
{
	::create();
	set_name("waterskin");
	set_short("A waterskin");
	set_id(({"waterskin","skin","water skin","a waterskin","A waterskin"}));
	set_long(
	"This is a waterskin made from a treated sheep's bladder.  "+
    "It would provide an adventurer with water in the wilderness when "+
    "no streams are nearby.  However, you must %^BOLD%^refill waterskin"+
    "%^RESET%^ at ponds and streams when it runs out.  You can %^BOLD%^check"+
    " waterskin%^RESET%^ to find out how much water is left. %^BOLD%^Drink"+
    " from waterskin%^RESET%^ allows you to take a drink."
	);
	set_weight(10);
	set_value(50);
	drinks = 5;
}

void init()
{
	::init();
	add_action("drink","drink");
	add_action("refill_skin","refill");
	add_action("check_skin","check");
}

void drink(string str)
{
	if(!living(ETO)) {
		notify_fail("You must be holding the waterskin to be able to drink from it.\n");
		return 0;
	}
	if(!interactive(ETO)) {
		notify_fail("You must be holding the waterskin to be able to drink from it.\n");
		return 0;
	}
	if(str == "waterskin" || str == "from waterskin") {
		if(drinks < 1) {
			tell_object(ETO,"The waterskin is empty.");
			return 1;
		}
		if(!ETO->add_quenched(20)) {
			notify_fail("Your stomach is sloshing already!\n");
			return 0;
		}
		if(drinks == 1) {
			tell_object(ETO,"You drink the last of the water from the waterskin.");
			tell_room(environment(ETO),""+ETO->query_cap_name()+" takes a drink from"
			" "+ETO->query_possessive()+" waterskin.",ETO);
			ETO->add_quenched(20);
			drinks -= 1;
			return 1;
		}
		else {
			tell_object(ETO,"You take a long drink from the waterskin.");
			tell_room(environment(ETO),""+ETO->query_cap_name()+" takes a long drink from"+
			" "+ETO->query_possessive()+" waterskin.",ETO);
			ETO->add_quenched(20);
			drinks -= 1;
			return 1;
		}
	}
}

void refill_skin(string str)
{
string keeper;
	if(!living(ETO)) {
		notify_fail("You must be holding the waterskin to be able to refill it.\n");
                return 1;
	}
	if(!interactive(ETO)) {
		notify_fail("You must be holding the waterskin to be able to refill it.\n");
		return 0;
	}
	if(str != "waterskin" && str != "skin") {
		tell_object(ETO,"Try refill waterskin.\n");
		return 1;
	}
	if(drinks == 5) {
		tell_object(ETO,"The waterskin is already full!");
		return 1;
	}
	if(present("gstorekeeper",EETO)) {
      keeper = present("gstorekeeper",EETO)->QCN;
		if(!ETO->query_funds("silver",50)) {
			tell_object(ETO,"The price is 50 silver, you do not have enough money.\n");
			return 1;
		}
		else {
			tell_object(ETO,"You hand your waterskin to "+keeper+" and he"+
			" refills it for you for a nominal fee.");
			tell_room(environment(ETO),""+ETO->query_cap_name()+" hands "+ETO->QP+""+
			" waterskin over to "+keeper+", who refills it for a nominal fee"+
			" and hands it back.",ETO);
			ETO->use_funds("silver",50);
			drinks = 5;
			return 1;
		}
	}
	if(environment(ETO)->query_property("fill waterskin")) {
		tell_object(ETO,"You bend down and refill the waterskin.");
		tell_room(EETO,""+ETOQCN+" bends down and"+
		" refills "+ETO->QP+" waterskin.",ETO);
		drinks = 5;
		return 1;
	}
	else {
		tell_object(ETO,"You must be at a pond or in the rations shop to refill"+
		" this waterskin. If you believe you are at one and it is not working,"+
		" use the bug command and report it.\n");
                return 1;
	}
}

void check_skin(string str)
{
	if(!living(ETO)) {
		notify_fail("You must be holding the waterskin to be able to check it.\n");
		return 0;
	}
	if(!interactive(ETO)) {
		notify_fail("You must be holding the waterskin to be able to check it.\n");
		return 0;
	}
	if(str != "waterskin" && str != "skin") {
		notify_fail("Check what?\n");
		return 0;
	}
	switch(drinks) {
		case 5:
			tell_object(ETO,"The waterskin is full.");
			break;
		case 4:
			tell_object(ETO,"The waterskin is almost full.");
			break;
		case 3:
			tell_object(ETO,"The waterskin is about half full.");
			break;
		case 2:
			tell_object(ETO,"The waterskin is close to empty.");
			break;
		case 1:
			tell_object(ETO,"The waterskin is almost empty.");
			break;
		case 0:
			tell_object(ETO,"The waterskin is empty.");
			break;
		default:
			notify_fail("Something appears to be wrong here, you better"+
			" contact a wiz. Crystal's the best.");
			return 0;
	}
	return 1;
}
