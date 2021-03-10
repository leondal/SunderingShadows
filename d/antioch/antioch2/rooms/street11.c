#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
	set_property("indoors",0);
	set_property("light",2);
	set_short("%^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^ Street");
	set_long(
	"You are on %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r %^ORANGE%^s%^BOLD%^%^BLACK%^tre%^RESET%^%^ORANGE%^e%^ORANGE%^t%^RESET%^.\n"+
	"A wooden sign hanging over the doorway of the house on"+
	" the east marks it as the shop of a tailor. The door is"+
	" open for all and you can see many types of fabric and"+
	" measuring instruments scattered about inside. To the north"+
	" is the side of the inn. You can see a few windows on the"+
	" second floor that overlook the city. To the west is the"+
	" intersection of %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^, Oak, and %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e%^RESET%^. At the end of the"+
	" street there appears to be a jeweler's shop. %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r %^ORANGE%^s%^BOLD%^%^BLACK%^tre%^RESET%^%^ORANGE%^e%^ORANGE%^t%^RESET%^"+
	" runs to the southeast and turns south to intersect with"+
	" %^ORANGE%^Crescent%^RESET%^ and %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^."
	);
	set("night long",
	"You are on %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r %^ORANGE%^s%^BOLD%^%^BLACK%^tre%^RESET%^%^ORANGE%^e%^ORANGE%^t%^RESET%^.\n"+
	"The street lights to the west and southeast shed light"+
	" on the area. The windows on the second floor of the"+
	" building to the north are also brightly lit, and spill"+
	" their light out onto this street. There is also a light"+
	" coming from the house on the east. Above the doorway of"+
	" the house is a wooden sign with the symbol of a tailor."+
	" To the west %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^ intersects with %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e%^RESET%^ and Oak in a"+
	" crossroads. At the end of the street to the west you can"+
	" see a jeweler's shop. %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r %^ORANGE%^s%^BOLD%^%^BLACK%^tre%^RESET%^%^ORANGE%^e%^ORANGE%^t%^RESET%^ runs to the southeast"+
	" and turns south to intersect with %^ORANGE%^Crescent%^RESET%^ and %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^."
	);
	set_smell("default","The scents of various foods drift to"+
	" you on the breeze.");
	if(query_night() == 1) {
		set_listen("default","You can hear the faint sounds of"+
		" drunken laughter.");
	}
	else {
		set_listen("default","A woman is humming a merry tune"+
		" in the tailor's shop.");
	}
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r %^ORANGE%^s%^BOLD%^%^BLACK%^tre%^RESET%^%^ORANGE%^e%^ORANGE%^t%^RESET%^.",
	"sign" : "This wooden sign is hung above the doorway to the"+
	" house on the east and has the symbol of a tailor on it. It also"+
   " has a picture of a golden sewing needle, proclaiming it as The Golden Needle.",
	"house" : "This is a sturdy wooden house.",
	"shop" : "This is a tailor's shop.",
	]));
	set_exits(([
	"west" : ROOMS+"street10",
	"east" : ROOMS+"tailor",
	"southeast" : ROOMS+"street12",
	]));
	set_door("door",ROOMS+"tailor","east",0);
	if(query_night() == 1) {
		set_open("door",0);
		"/d/antioch/antioch2/rooms/tailor"->set_open("door",0);
	}
	else if(query_night() != 1) {
		set_open("door",1);
		"/d/antioch/antioch2/rooms/tailor"->set_open("door",1);
	}
}
