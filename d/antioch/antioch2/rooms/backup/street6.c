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
	set_short("An intersection");
	set_long(
	"You are standing at the intersection of Pine, Cherry, and"+
	" Apple. To the west is a large building with the sign of"+
	" a stable over the doorway. You can hear animals moving"+
	" about within it and the smell of horses is strong in the"+
	" air here. Apple street moves up to the northwest and it"+
	" turns to the east at what is probably another intersection."+
	" Cherry street heads east through the main part of town and"+
	" you can see many shops along the way. There is also a large"+
	" fountain in the center of the street up ahead. It crosses"+
	" over to connect with Crescent, and there appears to be"+
	" a church at the opposite end of the street. Pine runs"+
	" to the southeast and meets with Crescent not far from the"+
	" city gates."
	);
	set("night long",
	"The street light here sheds a warm yellow light on the"+
	" intersection. Pine, Cherry, and Apple street meet here."+
	" Pine runs to the southeast and meets with Crescent, close"+
	" to the Antioch gates. Cherry seems to be the main street"+
	" through town and runs to the east, intersecting with"+
	" Crescent outside of what appears to be a church. There are"+
	" many shops along the road and a large fountain in the"+
	" very center of the street. Apple street runs up to the"+
	" northeast. To the west is a large building with a sign"+
	" engraved with the symbol of a stables over it. The stomping"+
	" of horses can be heard from within and the smell of animals"+
	" is strong here."
	);
	set_smell("default","There is a smell of horses coming from"+
	" the west.");
	set_listen("default","You can hear horses neighing and stomping"+
	" in their stalls.");
	set_items(([
	"street sign" : "You are at the intersection of Apple, Cherry"+
	" and Pine.",
	"sign" : "There is a wooden sign with the symbol of a stables"+
	" hanging over the doorway of the building on the west.",
	({"stables","building"}) : "This large building appears to be a stables.",
	"fountain" : "There is a large fountain in the middle of"+
	" Cherry street.",
	"church" : "At the end of Cherry street there appears to be"+
	" a large church.",
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	]));
	set_exits(([
	"west" : ROOMS+"stables",
	"east" : ROOMS+"street18",
	"north" : ROOMS+"street7",
	"south" : ROOMS+"street5",
	]));
}	

void reset()
{
	::reset();
	if(!present("street_light")) {
		new(OBJ+"street_light")->move(TO);
	}
	if(query_night() == 1) return;
	else if(!present("citizen")) {
             switch(random(4)) {
			case 0:
				new(MONS+"citizen1")->move(TO);
				break;
			case 1:
				new(MONS+"citizen2")->move(TO);
				break;
			case 2:
				new(MONS+"citizen3")->move(TO);
				break;
			case 3:
				new(MONS+"citizen4")->move(TO);
				break;
		}
	}
}
