#include <std.h>
inherit OBJECT;

void create()
{
	::create();
	set_name("wildflowers");
	set_id( ({"wildflowers","flowers","boquet"}) );
	set_short("%^MAGENTA%^Wildflowers%^RESET%^");
	set_long(
	"%^MAGENTA%^This is a boquet of beautiful wildflowers."+
	" There are many different types of flowers in this"+
	" boquet. They are quite colorful, ranging from white"+
	" to a deep crimson rose. Their scent mingles together"+
	" to create a wonderful perfume.%^RESET%^"
	);
	set_weight(1);
	set_value(20);
	set_cointype("silver");
}

void init()
{
	::init();
	add_action("smell", "smell");
}

int smell(string str)
{
	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed() || ETO->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
	if(!str) {
	write("Smell what?\n");
	return 1;
	}
	if(str != "flowers" && str != "boquet" && str!= "wildflowers") {
	write("You don't want to smell that!\n");
	return 1;
	}
	else {
	write("%^BOLD%^%^YELLOW%^You smell the lovely aroma"+
	" of wildflowers.");
	say(""+TP->query_cap_name()+" sniffs a boquet of wildflowers.");
	return 1;
	}
}
