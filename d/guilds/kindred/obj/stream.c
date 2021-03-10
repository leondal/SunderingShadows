#include <std.h>
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",0);
	set_property("no teleport",1);
	set_property("light",2);
	set_short("%^BOLD%^%^GREEN%^The Garden");
	set_long(
	"
	);
	set_smell("default","A fruity scent faintly clings to the air.");
	set_listen("default","The bubbling of the stream is almost melodic.");
	set_items(([

	]));
	set_exits(([
	"southwest" : "/d/guilds/kindred/rooms/bushes",
	"east" : "/d/guilds/kindred/rooms/campfire",
	]));
}

void init()
{
	::init();
	add_action("drink","drink");
}

int drink(string str)
{
	if(str != "stream" && str != "drink from stream" && str != "water") {
		tell_object(TP,"Try drink from stream.");
		return 1;
	}
	if(!TP->add_quenched(50)) {
		tell_object(TP,"You are no longer thirsty and have no reason to drink"+
		" from the stream.");
		return 1;
	}
	tell_object(TP,"%^BOLD%^You lean over and take a refreshing drink"+
	" from the cool stream.");
	tell_room(ETP,"%^BOLD%^"+TP->query_cap_name()+" leans over and takes"+
	" a refreshing drink from the cool stream.",TP);
	return 1;
}
