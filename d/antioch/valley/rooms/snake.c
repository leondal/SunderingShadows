#include <std.h>
#include "../valley.h"
inherit ROOM;

int found = 0;

void create()
{
	::create();
   set_terrain(GRASSLANDS);
   set_travel(FRESH_BLAZE);
	set_property("outdoors",3);
	set_property("light",3);
	set_short("%^GREEN%^Tall grass");
	set_long(
	"%^GREEN%^There are several tall trees scattered throughout"+
	" the valley and the wind blows through their"+
	" branches, making them sway. No animals are"+
	" scampering about in the grass here, however."+
	" Everything in this part of the valley seems"+
 " strangely still. The %^BOLD%^grass%^RESET%^%^GREEN%^ is taller here,"+
	" reaching all the way up to your waist. It"+
	" appears to move slightly, almost as though"+
	" there's %^YELLOW%^something%^RESET%^%^GREEN%^ underneath the grass.\n"
	);
	set("night long",
	"%^GREEN%^The %^BOLD%^%^GREEN%^grass%^RESET%^%^GREEN%^ here is taller, reaching up past your"+
	" waist. The wind is blowing across it, making"+
	" it move slightly with the breeze, reflecting"+
	" the %^BOLD%^%^WHITE%^starlight%^RESET%^%^GREEN%^"+
        " back with a %^BOLD%^%^WHITE%^silver%^RESET%^%^GREEN%^ sheen."+
	" Everything else in this section seems oddly"+
	" still. Looking more closely at the grass, you"+
	" aren't sure if the wind is completely"+
	" responsible for its movement. It almost seems"+
	" as though there might be %^YELLOW%^something %^RESET%^%^GREEN%^else in it.\n"
	);
	set_smell("default",
	"You smell a strange odor that you can't quite"+
	" place."
	);
	set_listen("default",
	"The grass rustles softly."
	);
	set_items( ([
	"grass" : "%^BOLD%^%^GREEN%^The grass here is quite vibrant and"+
	" grows to a great height. It seems as though"+
	" there's something in the grass...",
	]) );
	set_exits( ([
	"west" : ROOMS+"g117",
	"east" : ROOMS+"g116",
	"north" : ROOMS+"g99",
	"south" : ROOMS+"g27",
	]) );
	set_search("grass",(:TO,"search_grass":));
}

int search_grass()
{
   object obj;
	if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
	if(found) {
	write("You search through the grass but much of"+
	" it has been stomped down as though previously"+
	" searched by someone.");
	return 1;
	}
	else {
	write("You search through the tall grass and find...");
	write("\n");
	write("\n");
	write("an %^RED%^angry snake!");
	say(""+TP->query_cap_name()+" searches through"+
	"the grass and discovers an angry snake!");
   obj = new(MONS+"snake");
   obj->move(TO);
   obj->force_me("kill "+TP->query_name()+"");
	found = 1;
	add_item(
	"grass","The grass is rather trampled, as though it has been"+
	" searched by someone.");
	return 1;
	}
}

void reset()
{
	::reset();
	if(found) {
	found = 0;
	return 1;
	}
}
