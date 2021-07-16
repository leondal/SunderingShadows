#include <std.h>
#include "../valley.h"
inherit OBJECT;

void create()
{
	::create();
	set_name("spider eggs");
	set_id(({"spider eggs","eggs","egg sack","egg sacks","spider egg sacks","sacks"}));
	set_short("spider egg sacks");
	set_long(
	"There are several large sacks filled with spider eggs."+
	" Eventually they will hatch out into giant spiders and they"+
	" will hunt down and kill anything they can find. These evil"+
	" creatures are a plague on the world and should be destroyed."
	);
	set_weight(5);
	set_value(0);
   set_property("no offer",1);
}

void init()
{
	::init();
	add_action("destroy_sack","destroy");
}

int destroy_sack(string str)
{
	object obj;
	if(str == "sacks" || str == "egg sacks" || str == "egg sack" || str == "spider egg sacks" || str == "spider eggs" || str == "eggs") {
		tell_object(ETO,"%^BOLD%^You throw the horrible spider eggs"+
		" onto the ground and stomp on them, completely destroying"+
		" them!");
		tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+" throws the"+
		" spider eggs onto the ground and stomps on them, completely"+
		" destroying them.",ETO);
		TP->set_mini_quest("Spider Eggs", 500000, "%^BOLD%^Destroyed Spider Eggs\n");
		TO->remove();
		return 1;
	}
	else {
		write("What are you trying to destroy?");
		return 1;
	}
}
