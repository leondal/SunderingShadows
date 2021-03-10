#include <std.h>
#include "../ruins.h"
inherit ROOM;

int open;

void create()
{
	::create();
   set_terrain(RUINS);
   set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",1);
	set_short("%^BOLD%^%^BLACK%^Desolate Ruins%^RESET%^");
	set_long(
	"This was once the main street through town, now it is interrupted in"+
	" places by cracks. The shops that were on either side of the street"+
	" here have collapsed, it looks as though earthquakes shook the city to"+
	" pieces. The streets are charred in places and wood from the shops has"+
	" fallen across the road in places. There is an old grate in the"+
	" center of the street here. It probably leads to the sewer"+
	" system. In the northern distance is a crumbling tower."
	);
	set_smell("default","Dust hangs in the air.");
	set_listen("default","The ruins are eerily quiet.");
	set_items(([
	({"streets","street"}) : "The streets have large cracks running through"+
	" them, probably from earthquakes that appear to have shook the entire"+
	" area. Wood from the collapsed houses has fallen into the street in"+
	" places. There is a grate in the center of the street here that"+
	" probably leads to the sewer system. You can't imagine what kind"+
	" of a mess that must be in.",
	"grate" : "There is a grate in the center of the street here. It"+
	" looks like it leads to the old sewer system. It is hard to"+
	" see what is down there, the blackness is encompassing.",
	({"shop","shops"}) : "The shops on either side of the street have collapsed"+
	" into heaps of wood.",
	"tower" : "In the distance to the north is a large tower that has greatly"+
	" crumbled, now standing barely three stories tall.",
	]));
	set_exits(([
	"north" : ROOMS+"ruins14",
	"south" : ROOMS+"ruins9",
	]));
}

void reset()
{
	::reset();
	if(open) {
		open = 0;
		add_item("grate","There is a grate in the center of the street here. It"+
	" looks like it leads to the old sewer system. It is hard to"+
	" see what is down there, the blackness is encompassing.");
	}
}

void init()
{
	::init();
	add_action("lift_grate","lift");
}

int lift_grate(string str)
{
	if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed()
|| TP->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}

	if(!str) {
		notify_fail("Lift what?");
		return 0;
	}
	if(str != "grate") {
		notify_fail("You can't lift that!\n");
		return 0;
	}
   if(open == 1) {
      tell_object(TP,"The grate is already open!");
      return 1;
	}
	if(query_night() == 1) {
		tell_object(TP,"As you open the grate a tremendous force"+
		" knocks you aside!");
		tell_room(ETP,"As soon as "+TP->query_cap_name()+" opens"+
		" the grate a tremendous force erupts from the sewers.",TP);
         new(MONS+"sewer_mon.c")->move(TO);
		open = 1;
		add_item("grate","There is a grate in the center of the"+
		" street here. It looks like it leads to the old sewer"+
		" system. The grate is open, but it is still hard to see"+
		" what might be lurking down there.");
		return 1;
	}
	else {
		tell_object(TP,"%^BOLD%^%^BLUE%^A cold gust of air rushes"+
		" out from the sewer system as you open the grate, sending"+
		" a shiver down your spine.%^RESET%^\n"+
		"There doesn't seem to be anything down there, the walls"+
		" have collapsed in on themselves.");
		tell_room(ETP,"%^BOLD%^%^BLUE%^A cold gust of air rushes"+
		" up out of the sewer system as "+TP->query_cap_name()+""+
		" opens the grate.",TP);
		open = 1;
		add_item("grate","There is a grate in the center of the"+
		" street here. It looks like it leads to the old sewer"+
		" system. The grate is open, but it is still hard to see"+
		" what might be lurking down there.");
		return 1;
	}
}
