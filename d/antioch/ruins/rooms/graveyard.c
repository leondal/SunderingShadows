#include <std.h>
#include "../ruins.h"
inherit ROOM;

int picked;
int FLAG;

void create()
{
	::create();
   set_travel(DIRT_ROAD);
   set_terrain(CEMETERY);
	set_property("indoors",0);
	set_property("light",1);
	set_long(
	"The graveyard here seems to be untouched by the battle that took place"+
	" in the rest of the city. It is completely filled with tombstones of"+
	" the deceased that are in orderly rows. In the very center of the"+
	" graveyard is a small hill with a beautiful flower growing on top of"+
	" it. There is a sorrow that seems to hang in the air, but also the sense"+
	" of peace at long last."
	);
	set("night long",
	"%^BLUE%^Rows of orderly tombstones seem to have gone untouched by the"+
	" battle and earthquakes that raged throughout the rest of the now"+
	" desolate city. There is an unquiet feeling here, however, as though"+
	" the souls of the deceased are still tormented. The shadows seem to"+
	" be moving about here, slowly creeping closer to you. For a moment it"+
	" feels like someone's breathing down the back of your neck. Some"+
	" unpleasant odor hangs in the air, it almost smells like rotting flesh."+
	" There is a withered flower that sits slumped on a small hill."
	);
	if(query_night() == 1) {
		set_short("%^BOLD%^%^BLUE%^A dark graveyard");
		set_smell("default","An unpleasant odor tickles your nose.");
		set_listen("default","The shadows seem to be moving about");
		set_search("default","Shadows seem to fill this graveyard, if there"+
		" is anything here, it lurks within them.");
		set_items(([
		"graves" : "Rows of graves are here, they disappear into the distance"+
		" beneath the impossibly black shadows.",
		"tombstones" : "Tombstones are at each grave, they show a large"+
		" number of deaths all at once. Some tragedy obviously befell the town.",
		"flower" : "There is a withered flower in the center of the small hill.",
		"hill" : "A small hill is in the center of the graveyard, it just"+
		" slopes gently upwards.",
		]));
	}
	else {
		set_short("A quiet graveyard");
		set_smell("default","Fresh earth fills the air.");
		set_listen("default","There is a quiet peace here.");
		set_search("default","All that seems to be here are quiet graves and"+
		" a flower on top of the hill.");
		set_items(([
		"graves" : "There are numerous rows of carefully ordered graves here."+
		" Grass is growing over them, and there are no weeds about. Each grave"+
		" has a stone tombstone.",
		"tombstones" : "Tombstones have been placed on each grave. Many of"+
		" them have deaths in the same year, some great tragedy must have"+
		" befallen the poor town.",
		"tombstone" : "%^BOLD%^One tombstone stands out among the rest, it is"+
		" of white marble. The name on the tombstone is simply: Astella. She"+
		" died very young, it doesn't say how.", 
		"flower" : "A flower sits on top of the small hill, it is very beautiful.",
		"hill" : "A small hill is in the middle of the graveyard, it has a"+
		" flower on it.",
		]));
	}
	set_exits(([
	"out" : ROOMS+"ruins12",
	]));
	picked = 0;
}

void reset()
{
	::reset();
	FLAG = 0;
}

void init()
{
	::init();
	add_action("pick_flower","pick");
	add_action("search_shadows","search");
}

void search_shadows(string str)
{
	if(query_night() == 1) {
		if(present("crypt thing") || present("zombie lord") || present("spectre")) {
			tell_object(TP,"The monsters don't seem to want to let you search anything.");
			return 1;
		}
		if(str == "shadows" && str == "shadows" && str == "darkness") {
			if(FLAG) {
				tell_object(TP,"You find nothing in the swirling darkness.");
				return 1;
			}
			else {
				tell_object(TP,"%^BOLD%^%^BLACK%^The shadows coalesce into a"+
				" fearsome shape and attack you!");
				tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->query_cap_name()+" searches"+
				" the shadows, they seem to coalesce into a solid form and attack!",TP);
				new(MONS+"shadow")->move(TO);
				new(MONS+"shadow")->move(TO);
				FLAG = 1;
				return 1;
			}
		}
	}
	return;
}

void pick_flower(string str)
{
	if(!str) {
		return 0;
	}
	if(str != "flower") {
		tell_object(TP,"Pick what?\n");
		return 1;
	}
	if(picked) {
		tell_object(TP,"The flower has already been picked.\n");
		return 1;
	}
	if(query_night() == 1) {
		if(present("crypt thing") || present("zombie lord") || present("spectre")) {
			tell_object(TP,"The monsters block your way.");
			return 1;
		}
		tell_object(TP,"You reach out and pick the withered flower.");
		tell_room(ETP,""+TP->query_cap_name()+" reaches out and picks the"+
		" withered flower.",TP);
		new(OBJ+"wflower")->move(TP);
		add_item("flower","All that is left of the flower on the hill is a"+
		" withered stalk.");
		tell_room(ETP,"Suddenly the dead begin to arise from their graves, angry at your intrusion!");
		new(MONS+"zombie_lord")->move(TO);
		new(MONS+"crypt_thing")->move(TO);
		new(MONS+"crypt_thing")->move(TO);
		new(MONS+"crypt_thing")->move(TO);
		picked = 1;
		return 1;
	}
	else {
		tell_object(TP,"You bend down and pick the lovely flower. A twinge"+
		" of sorrow hits you as you see the sap spill forth from the stem,"+
		" almost as if it is bleeding.");
		tell_room(ETP,""+TP->query_cap_name()+" bends down and picks a flower.",TP);
		new(OBJ+"flower")->move(TP);
		set_search("default","There is nothing here but quiet graves.");
		add_item("flower","The flower on the hill has already been picked,"+
		" leaving only a stalk.");
		picked = 1;
		return 1;
	}
}
