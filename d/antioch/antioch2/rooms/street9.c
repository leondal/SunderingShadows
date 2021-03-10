#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("%^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e%^RESET%^ Street");
	set_long(
	"You are on %^RED%^%^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e %^RED%^st%^GREEN%^r%^RED%^eet%^RESET%^%^RESET%^\n"+
	"A jeweler's shop is nestled here at the western corner."+
	" A wooden sign hangs over the entrance way, proclaiming"+
	" it a jeweler's shop. To the north there is the side of"+
	" a building, and you can hear loud laughter and slurred"+
	" toasts coming from it. To the east %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e %^RED%^st%^GREEN%^r%^RED%^eet%^RESET%^ continues"+
	" to intersect with Oak and %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^, and there is a tailor's"+
	" shop across the way. %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e %^RED%^st%^GREEN%^r%^RED%^eet%^RESET%^ continues to the"+
	" southwest to intersect with %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ and %^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ outside the"+
	" stables."
	);
	set("night long",
	"You are on %^RED%^%^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e %^RED%^st%^GREEN%^r%^RED%^eet%^RESET%^%^RESET%^\n"+
	"To the east is a crossroads where Oak, %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e%^RESET%^, and %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^"+
	" intersect. A street light there sheds light onto the"+
	" surrounding areas. To the west is a house with the symbol"+
	" of a jeweler's over the entrance. Inviting yellow light"+
	" spills forth from beneath the door. Directly north is the"+
	" side of a large building. You can hear chatter and drunken"+
	" laughter from within, but there is no entrance to it on"+
	" this street. To the southwest %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e %^RED%^st%^GREEN%^r%^RED%^eet%^RESET%^ continues on"+
	" to meet with %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ and %^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ by the stables."
	);
	set_smell("default","There is the faint scent of oil hanging"+
	" in the air.");
	if(query_night() == 1) {
		set_listen("default","You can hear the sound of rowdy men"+
		" to the north.");
	}
	else {
		set_listen("default","The hustle and bustle of a busy"+
		" city surrounds you.");
	}
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is %^RED%^%^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e %^RED%^st%^GREEN%^r%^RED%^eet%^RESET%^%^RESET%^",
	"sign" : "There's a wooden sign with the symbol of a jeweler"+
	" hanging over the doorway of the shop on the west. It also has"+
	" the image of falling star sapphires on it, declaring it the"+
	" Falling Stars Jewelry.",
	]));
	set_exits(([
	"east" : ROOMS+"street10",
	"west" : ROOMS+"jeweler",
	"southwest" : ROOMS+"street8",
	]));
	set_door("door",ROOMS+"jeweler","west",0);
	if(query_night() == 1) {
		set_open("door",0);
		"/d/antioch/antioch2/rooms/jeweler"->set_open("door",0);
	}
	else if(query_night() != 1) {
		set_open("door",1);
		"/d/antioch/antioch2/rooms/jeweler"->set_open("door",1);
	}
}
