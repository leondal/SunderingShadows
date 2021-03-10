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
	set_short("%^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e%^RESET%^ Street");
	set_long(
	"You are on %^RED%^%^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e %^RED%^st%^GREEN%^r%^RED%^eet%^RESET%^%^RESET%^\n"+
	"To the northwest %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e %^RED%^st%^GREEN%^r%^RED%^eet%^RESET%^ continues and curves to the"+
	" east to intersect with %^WHITE%^O%^WHITE%^a%^WHITE%^k %^WHITE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^eet%^RESET%^ and %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^. There's a"+
	" shop on the western side at the bend with the sign of a"+
	" jeweler's. To the southwest %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e%^RESET%^ runs down to intersect"+
	" with %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ and %^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ next to the stables."
	);
	set("night long",
	"You are on %^RED%^%^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e %^RED%^st%^GREEN%^r%^RED%^eet%^RESET%^%^RESET%^\n"+
	"The street light sheds warm yellow light here, keeping the"+
	" darkness at bay. To the northeast the street makes a turn"+
	" to the east. On the western side there appears to be a"+
	" jeweler's shop. To the southwest %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e %^RED%^st%^GREEN%^r%^RED%^eet%^RESET%^ runs down to"+
	" intersect with %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ and %^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ outside the stables."
	);
	set_smell("default","A faint scent of horses hangs in the"+
	" air.");
	set_listen("default","The neighing of horses can be"+
	" heard.");
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is %^RED%^%^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e %^RED%^st%^GREEN%^r%^RED%^eet%^RESET%^%^RESET%^",
	"shop" : "It looks like there's a shop up ahead.",
	"sign" : "There's a wooden sign with the symbol of a jeweler"+
	" hanging over the doorway of the shop to the north.",
	]));
	set_exits(([
	"northeast" : ROOMS+"street9",
	"southwest" : ROOMS+"street7",
	]));
}

void reset()
{
	::reset();
	if(!present("street_light")) {
		new(OBJ+"street_light")->move(TO);
	}
}
