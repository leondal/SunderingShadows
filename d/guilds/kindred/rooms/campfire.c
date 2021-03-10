#include <std.h>
inherit ROOM;

int lit;

void create()
{
	::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
	set_property("indoors",0);
	set_property("light",2);
	set_short("%^BOLD%^%^GREEN%^The Garden");
	set_long(
	"A large camp fire is off to the side of the path here, not far from the"+
	" stream should things get out of hand. A few fallen logs have been moved"+
	" near the camp fire for people to sit on as they gather around. At night"+
	" you can frequently find the Kindred here, gathered around a roaring"+
	" fire and talking and laughing as they roast their dinner. During the"+
	" day the camp fire is rarely used, unless people are trying to warm"+
	" up after taking a cold bath in the stream."
	);
	set("night long",
	"A blazing camp fire lights up the night. It sheds warmth to the"+
	" surrounding area. Old fallen logs have been placed near the camp fire"+
	" for people to sit on while they warm up. It is common to find the"+
	" Kindred gathered around the camp fire at nights, softly chatting while"+
	" their dinner's slowly roast. The nearby spring provides refreshment"+
	" and the water from the stream can be used to douse the fire if it gets"+
	" out of control."
	);
	if(query_night() == 1) {
		set_listen("default","The fire crackles and pops.");
		set_smell("default","Smoke from the fire tickles your nose.");
	}
	else {
		set_listen("default","The stream softly gurgled by.");
		set_smell("default","The faint smell of wood smoke from last night's"+
		" camp fire hangs in the air.");
	}
	set_items(([
	"camp fire" : "The camp fire is properly stacked and merely waiting to"+
	" be lit.",
	"stream" : "A little stream makes its way along an old river bed to the"+
	" north.",
	({"logs","fallen logs","old logs"}) : "There are three logs from trees"+
	" that fell over due to natural causes. They have obviously been moved"+
	" here to be used as fire side seats.",
	]));
	if(query_night() == 1) {
		add_item("camp fire","The camp fire is burning brightly, shedding a"+
		" warm glow on the surrounding area.");
		lit = 1;
		set_property("light",3);
	}
	set_exits(([
	"west" : "/d/guilds/kindred/rooms/stream",
	"east" : "/d/guilds/kindred/rooms/pond",
	]));
}

void init()
{
	::init();
	add_action("light_fire","light");
	add_action("drink","drink");
	add_action("sit","sit");
}

void reset()
{
	::reset();
	if(query_night() != 1) {
		if(lit) {
			tell_room(TO,"The camp fire goes out.");
			add_item("camp fire","This camp fire was lit but has burned itself"+
			" out.");
			lit = 0;
			set_property("light",2);
			return 1;
		}
	}
}

int light_fire(string str)
{
	if(str != "fire" && str != "camp fire") {
		tell_object(TP,"Try light camp fire.");
		return 1;
	}
	if(!present("flint and steel",TP)) {
		tell_object(TP,"You don't have anything to start the fire with.");
		return 1;
	}
	if(lit) {
		tell_object(TP,"The fire is already lit!");
		return 1;
	}
	else {
		tell_object(TP,"You strike your flint and steel together, creating"+
		" a spark.\nYou carefully cultivate the spark into a burning fire.");
		tell_room(ETP,""+TP->query_cap_name()+" strikes "+TP->query_possessive()+""+
		" flint and steel together, creating a spark.\n"+TP->query_subjective()+""+
		" carefully cultivates the spark into a burning camp fire.",TP);
		lit = 1;
		add_item("camp fire","The camp fire is burning brightly, shedding a"+
		" warm glow on the surrounding area.");
		set_property("light",3);
		return 1;
	}
}

int drink(string str)
{
	if(str == "stream" || str == "brook" || str == "river") {
		tell_object(TP,"You wouldn't want to drink from this water, it is"+
		" best to drink from the fresh spring.");
		return 1;
	}
}

int sit(string str)
{
	if(str == "log" || str == "logs" || str == "fallen log") {
		tell_object(TP,"%^ORANGE%^You sit down at one of the logs near the"+
		" camp fire.");
		tell_room(ETP,"%^ORANGE%^"+TP->query_cap_name()+" sits down at one"+
		" of the logs near the camp fire.",TP);
		return 1;
	}
	if(str == "ground" || str == "floor") {
		tell_object(TP,"%^GREEN%^You sit down cross-legged on the ground"+
		" in front of the camp fire.");
		tell_room(ETP,"%^GREEN%^"+TP->query_cap_name()+" sits down cross-legged"+
		" on the ground in front of the camp fire.",TP);
		return 1;
	}
}
