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
	set_short("%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ Street");
	set_long(
	"%^ORANGE%^You are on %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^\n"+
	"%^ORANGE%^A little further to the east is a very large and impressive stone %^YELLOW%^church%^RESET%^%^ORANGE%^. Right outside the church %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^  is joined by %^BOLD%^%^ORANGE%^C%^RESET%^%^ORANGE%^re%^BOLD%^%^ORANGE%^s%^RESET%^%^ORANGE%^c%^BOLD%^%^ORANGE%^e%^RESET%^%^ORANGE%^n%^BOLD%^%^ORANGE%^t%^RESET%^ %^ORANGE%^street%^WHITE%^ from the southwest and %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r %^ORANGE%^s%^BOLD%^%^BLACK%^tre%^RESET%^%^ORANGE%^e%^ORANGE%^t%^RESET%^ from the northwest. To the west are several shops, the weapons shop and armory are directly to the west and not far past them you can see a bank, near the large %^CYAN%^fountain%^BOLD%^%^CYAN%^.%^RESET%^
"
	);
	set_smell("default","The scent of polish hangs in the air"+
	" here.");
	if(query_night() == 1) {
		set_listen("default","You hear the faint gurgle of the"+
		" fountain.");
	}
	else {
		set_listen("default","The street is alive with shoppers"+
		" arguing over prices.");
	}
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^",
	"fountain" : "A large fountain is in the center of the %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^"+
	" street.",
	"church" : "There is a very impressive stone church to the"+
	" east.",
	]));
	set_exits(([
	"west" : ROOMS+"street20",
	"east" : ROOMS+"street14",
	]));
}
