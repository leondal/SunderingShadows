#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("%^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^ Street");
	set_long(
	"You are on %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r %^ORANGE%^s%^BOLD%^%^BLACK%^tre%^RESET%^%^ORANGE%^e%^ORANGE%^t%^RESET%^.\n"+
	"Directly to the north is the side of house that the tailor"+
	" lives in. The street continues to the northwest and splits"+
	" west just outside the tailor's shop, intersecting with"+
	" Oak and %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e%^RESET%^. %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^ continues to the southeast, shortly"+
	" turning to the south to meet up with %^ORANGE%^Crescent%^RESET%^ and %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^"+
	" street outside the church."
	);
	set("night long",
	"You are on %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r %^ORANGE%^s%^BOLD%^%^BLACK%^tre%^RESET%^%^ORANGE%^e%^ORANGE%^t%^RESET%^.\n"+
	"The street light here sheds light on the surrounding area."+
	" To the northwest you can see light spilling from the door"+
	" of the tailor's house. The street splits off to the west"+
	" there, joining with Oak and %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e %^RED%^st%^GREEN%^r%^RED%^eet%^RESET%^ at a crossroads."+
	" %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r %^ORANGE%^s%^BOLD%^%^BLACK%^tre%^RESET%^%^ORANGE%^e%^ORANGE%^t%^RESET%^ runs southeast, quickly turning to the south"+
	" up ahead to intersect with %^ORANGE%^Crescent%^RESET%^ and %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^right"+
	" in front of the church."
	);
	set_smell("default","A faint smell of food is in the air.");
	if(query_night() == 1) {
		set_listen("default","The night is peacefully quiet.");
	}
	else {
		set_listen("default","There is the sound of a woman"+
		" humming a tune in the tailor's shop.");
	}
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r %^ORANGE%^s%^BOLD%^%^BLACK%^tre%^RESET%^%^ORANGE%^e%^ORANGE%^t%^RESET%^.",
	]));
	set_exits(([
	"northwest" : ROOMS+"street11",
	"southeast" : ROOMS+"street13",
	]));
}

void reset()
{
	::reset();
	if(!present("street_light")) {
		new(OBJ+"street_light")->move(TO);
	}
}
