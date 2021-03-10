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
	"Straight north you can see the entrance to the palace. To the"+
	" south is the large fountain and the intersection with %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^"+
	" street and Oak. On either side of you are shops, but their"+
	" entrances are on %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^and you can't tell what they"+
	" are from here. A little further north is the intersection of"+
	" oak with %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e%^RESET%^ and %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^. You can also see that just passed the"+
	" intersection are two large buildings. The one on the eastern"+
	" side appears to be an inn, and you guess that the other is"+
	" probably the town tavern."
	);
	set("night long",
	"You are on %^WHITE%^O%^WHITE%^a%^WHITE%^k %^WHITE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^eet%^RESET%^.\n"+
	"The street light here helps to light the way. On either side of"+
	" you are two buildings, most likely shops but their entrances"+
	" must be on %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^ Just to the south is a large fountain"+
	" and the intersection of Oak with %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^. In the distance to the"+
	" north you can see the palace. Light spills forth from several"+
	" of the windows there. Before the palace are two buildings, the"+
	" one on the right appears to be an inn and you can see lights in"+
	" the windows of its second story. To the west is probably the"+
	" local bar, you can catch a bit of drunken laughter here, but the"+
	" gurgling of the fountain is the most prominent noise. The faint"+
	" scent of food is carried to you on the breeze, the inn would"+
	" probably be a good place to stop for a bite to eat. Just before"+
	" the inn is the intersection of Oak with %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e%^RESET%^ and %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^, that"+
	" branch off to the west and east respectively."
	);
	if(query_night() == 1) {
		set_smell("default","You smell a very faint scent of food"+
		" drifting in from the north.");
		set_listen("default","The reassuring gurgle of the fountain"+
		" can be heard from the south.");
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
	"fountain" : "A large fountain is just south of here.",
	"palace" : "At the northern part of this road is a large and"+
	" impressive palace.",
	"inn" : "There appears to be an inn to the north.",
	({"bar","tavern"}) : "Across from the inn looks like a bar.",
	({"building","buildings","shop","shops"}) : "There are two"+
	" buildings on either side of you, but their entrances must be"+
	" to the south on %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^",
	]));
	set_exits(([
	"south" : ROOMS+"fountain",
	"north" : ROOMS+"street23",
	]));
}

void reset()
{
	::reset();
	if(!present("street_light")) {
		new(OBJ+"street_light")->move(TO);
	}
}
