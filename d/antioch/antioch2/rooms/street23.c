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
	set_short("Oak Street");
	set_long(
	"You are on %^WHITE%^O%^WHITE%^a%^WHITE%^k %^WHITE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^eet%^RESET%^.\n"+
	"Just north of here is the intersection of Oak with %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e%^RESET%^ and"+
	" %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r %^ORANGE%^s%^BOLD%^%^BLACK%^tre%^RESET%^%^ORANGE%^e%^ORANGE%^t%^RESET%^. %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e %^RED%^st%^GREEN%^r%^RED%^eet%^RESET%^ runs to the west and there is a shop"+
	" at the corner where it turns curves to the south. %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r %^ORANGE%^s%^BOLD%^%^BLACK%^tre%^RESET%^%^ORANGE%^e%^ORANGE%^t%^RESET%^"+
	" travels east, and there is also a shop at the corner where it"+
	" turns towards the south. A little ways passed the intersection"+
	" there are two buildings. The one on the west looks like the"+
	" local tavern. On the opposite side of the street is a large and"+
	" respectable looking inn. It reaches up two stories in height"+
	" and looks clean. At the very end of %^WHITE%^O%^WHITE%^a%^WHITE%^k %^WHITE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^eet%^RESET%^ is the palace."+
	" Straight south of here Oak joins with %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^at a large"+
	" fountain."
	);
	set("night long",
	"You are on %^WHITE%^O%^WHITE%^a%^WHITE%^k %^WHITE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^eet%^RESET%^.\n"+
	"It is a little darker here, but street lights to the north and"+
	" south help to shed light on the area. At the very end of this"+
	" street is a large palace with many windows spilling forth warm"+
	" yellow light. Closer to you is an inn, it is two stories and"+
	" appears to be clean, warm light also spills forth from its"+
	" windows on the second floor. It would be a nice place to rest"+
	" and you can smell some delicious foods pouring forth from it."+
	" Across the street from the inn looks like the local tavern. The"+
	" sounds of drunken laughter confirm that, it sounds like everyone's"+
	" having a good time in there. To the south is a large fountain"+
	" at the point where Oak and %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^join."
	);
	if(query_night() == 1) {
		set_smell("default","You smell the aroma of some delicious"+
		" foods.");
		set_listen("default","The gurgling of the fountain is mixed"+
		" with the sounds of drunken laughter.");
	}
	else {
		set_smell("default","The scent of a hot street isn't the"+
		" most pleasant of odors.");
		set_listen("default","The streets are noisy with shoppers"+
		" trying to get the best prices.");
	}
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is %^WHITE%^O%^WHITE%^a%^WHITE%^k %^WHITE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^eet%^RESET%^.",
	"fountain" : "A large fountain is to the south of here.",
	"palace" : "At the northern part of this road is a large and"+
	" impressive palace.",
	"inn" : "There appears to be an inn to the north.",
	({"bar","tavern"}) : "Across from the inn looks like a bar.",
	]));
	set_exits(([
	"north" : ROOMS+"street10",
	"south" : ROOMS+"street22",
	]));
}
