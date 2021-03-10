#include <std.h>
inherit ROOM;

void create()
{
	::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
	set_property("indoors",0);
   set_property("fill waterskin",1);
	set_property("light",2);
	set_short("%^BOLD%^%^GREEN%^The Garden");
	set_long(
	"A fresh spring bubbles up out of the ground here. It fills a pool made"+
	" of stone and turns into a bubbling brook as it winds its way to the"+
	" east. Wildflowers surround the area around the spring, coming in a"+
	" multitude of colors. Close to the spring there is a little clear"+
	" space. A %^BOLD%^%^BLACK%^black rose%^RESET%^ bush grows in that"+
	" opening. This spring somehow brings to you a calm, tranquil"+
	" feeling. It is very relaxing here, listening to the bubbling of the"+
	" spring."
	);
	set_smell("default","A fruity scent faintly clings to the air.");
	set_smell("rose","The black rose smells lovely, but its fragarance"+
	" somehow leaves you a little sad.");
	set_smell("flowers","The flowers smell simply divine.");
	set_listen("default","The bubbling of the stream is almost melodic.");
	set_items(([
	"spring" : "A stream bubbles up from beneath the ground into a pool of"+
	" solid gray rocks. It overflows and makes its way eastward where there"+
	" is already a little path laid out for it. It looks as though it used"+
	" to be a much larger spring at one time and has since diwndled down to"+
	" this little stream.",
	({"brook","stream"}) : "%^BOLD%^%^BLUE%^A bubbling brook runs off to the east.",
	"wildflowers" : "Wildflowers grow along the the bank of the spring."+
	" They range in color from %^MAGENTA%^purple%^RESET%^ to %^BOLD%^%^RED%^red%^RESET%^"+
	" to %^YELLOW%^gold%^RESET%^ and %^BOLD%^white%^RESET%^ and all the"+
	" colors in between. They are very lovely, some are small and others are"+
	" larger, they are all very delicate.",
	({"rose bush","black rose bush"}) : "A solitairy black rose bush grows"+
	" in the small clearing near the spring. Only a single %^BOLD%^%^BLACK%^black"+
	" rose%^RESET%^ is in bloom.",
	({"rose","black rose"}) : "%^BOLD%^%^BLACK%^A single black rose grows"+
	" up from the center of the rose bush. It boldly stands by itself, its"+
	" petals unmarred by the touch of man, yet it seems somehow lonely...",
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
	if(str != "spring" && str != "from spring" && str != "water") {
		tell_object(TP,"Try drink from spring.");
		return 1;
	}
	if(!TP->add_quenched(50)) {
		tell_object(TP,"You are no longer thirsty and have no reason to drink"+
		" from the spring.");
		return 1;
	}
	tell_object(TP,"%^BOLD%^You lean over and take a refreshing drink"+
	" from the cool spring.");
	tell_room(ETP,"%^BOLD%^"+TP->query_cap_name()+" leans over and takes"+
	" a refreshing drink from the cool spring.",TP);
	return 1;
}
