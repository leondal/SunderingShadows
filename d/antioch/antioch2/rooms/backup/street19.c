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
	set_short("Cherry Street");
	set_long(
	"You are on Cherry street.\n"+
	"A strange musky odor hangs in the air here. It is coming"+
	" from the shop directly south. It is a little house with"+
	" a red roof and the sign of a mage's component shop out"+
	" front. On the sign is a picture of a lizard's tail. The"+
	" door is made of a dark walnut wood and looks sturdy."+
	" To the north there is a building that is marked as the"+
	" general store, it has a pine wood door, in fact, the entire"+
	" building seems to be made out of pine. There you can buy basic"+
	" things and any odds and ends you might need. A sign that hangs over"+
	" the doorway has a picture of a winged griffin on it. To the west Cherry"+
	" street joins with Pine and Apple street right outside the"+
	" stables. To the east is a very large fountain and the"+
	" intersection of Cherry and Oak street. All the way at the end"+
	" of the street there is an impressive stone church."
	);
	set("night long",
	"You are on Cherry street.\n"+
	"The street post here sheds light on the surrounding area."+
	" The shops seem closed right now, all the doors are shut"+
	" but a little light leaks out from underneath each doorway."+
	" The bank is still open, it appears. The component shop and"+
	" the general store, that are south and north of you respectively,"+
	" both have their doors shut and the owners have apparently"+
	" gone to sleep for the night. To the west Cherry street"+
	" intersects with Pine and Apple outside the stables. To the"+
	" east is a very large fountain, and at the end of the road"+
	" there is a big stone church."
	);
	set_smell("default","There is an odd musky scent coming from"+
	" the component shop on the south.");
	if(query_night() == 1) {
		set_listen("default","The gurgle of the fountain is very"+
		" relaxing.");
	}
	else {
		set_listen("default","The street is buzzing with the"+
		" shoppers and store owners haggling over prices.");
	}
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is Cherry street.",
	"fountain" : "There is a fountain to the east of here.",
	"shops" : "There are many shops along this street.",
	]));
	set_exits(([
	"west" : ROOMS+"street18",
	"east" : ROOMS+"fountain",
	"south" : ROOMS+"component",
	"north" : ROOMS+"general",
	]));
	set_door("walnut door",ROOMS+"component","south",0);
	set_door("pine door",ROOMS+"general","north",0);
	if(query_night() == 1) {
		set_open("walnut door",0);
		set_open("pine door",0);
            find_object_or_load("/d/antioch/antioch2/rooms/component.c")->set_open("walnut door",0);
		find_object_or_load("/d/antioch/antioch2/rooms/general.c")->set_open("pine door",0);
	}
	else if(query_night() != 1) {
		set_open("walnut door",1);
		set_open("pine door",1);
		find_object_or_load("/d/antioch/antioch2/rooms/component.c")->set_open("walnut door",1);
		find_object_or_load("/d/antioch/antioch2/rooms/general.c")->set_open("pine door",1);
	}
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

