#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
	set_short("A nice house");
	set_long(
	"This is a nice, cozy house. It has been decorated in a country theme."+
	" The walls have been painted %^BOLD%^white%^RESET%^ with a %^BOLD%^%^RED%^red%^RESET%^"+
	" trim. Pictures of farm animals are hung on the walls. The hardwood floor"+
	" has been recently swept, and the entire house smells of apples. On the"+
	" west is a cozy living room with a large %^YELLOW%^cream%^RESET%^ couch"+
	" and two wooden chairs with matching %^YELLOW%^cream%^RESET%^ cushions."+
	" An oak coffee table sits in the center of the living room. An oil lamp"+
	" hangs down from the ceiling, bringing light to the room. Across from"+
	" the living room is the dining room. An oak dining table is surrounded"+
	" by six matching chairs. A bowl of tasty looking %^BOLD%^%^RED%^red%^RESET%^"+
	" apples sits in the center of the table. In the southeast corner of the"+
	" room is the kitchen. The cabinets and drawers have been painted %^BOLD%^white%^RESET%^"+
	" with %^BOLD%^%^BLACK%^black%^RESET%^ cow spots on it, giving it a rather"+
	" amusing look. The kitchen is well organized, bottles of herbs are placed"+
   " against a back wall and all the dishes and silver ware have been stored"+
	" in the drawers and cabinets. In the northwest corner there is a door"+
	" that leads to the bedroom."
	);
	set_smell("default","The house smells of spiced apples.");
	set_listen("default","The house is quiet.");
	set_items(([
	"floor" : "The hardwood floor has been recently swept clean.",
	"ceiling" : "An oil lamp hangs down from the ceiling.",
	({"wall","walls"}) : "%^BOLD%^The walls have been painted white and"+
	" paintings of farm animals hang on them.",
	({"painting","paintings"}) : "There are several paintings of farm animals"+
	" along the walls.\n\n"+
	"One is of a young %^YELLOW%^duckling%^RESET%^ swimming on a lake.\n\n"+
	"There is one of several %^BOLD%^%^BLACK%^colts%^RESET%^ running through a field.\n\n"+
	"An especially cute painting is of a %^BOLD%^lamb%^RESET%^ with a butterfly on its nose.\n\n"+
	"The last painting is of several baby %^BOLD%^%^MAGENTA%^pigs%^RESET%^ competing for their mother's milk.\n",
	({"lamp","oil lamp","hanging lamp","ceiling lamp"}) : "An oil lamp hangs"+
	" from the ceiling over the living room. It has a %^BOLD%^white%^RESET%^"+
	" cover and sheds light to the room.",
	({"couch","cream couch"}) : "%^YELLOW%^A large cream couch is in the"+
	" living room on the west side of the room. It faces the north wall and"+
	" looks as though it could comfortably fit four people.",
	({"chair","chairs","wooden chairs","cream chairs"}) : "Two large chairs"+
	" sit in the living room, facing the couch. They have matching %^YELLOW%^cream%^RESET%^"+
	" cushions and are made of oak.",
	({"oak chairs","oak chair","matching chair","dining chair"}) : "Six oak"+
	" chairs surround the dining room table.",
	({"table","dining table","oak table","oak dining table"}) : "A large oak"+
	" dining room table is on the east side of the room. It is surrounded"+
	" by six matching chairs and has a bowl of %^BOLD%^%^RED%^apples%^RESET%^"+
	" on top of it.",
	"coffee table" : "An oak coffee table is in the middle of the living room."+
	" People can set things down on it while they're relaxing there.",
	"bowl" : "%^BOLD%^A white ceramic bowl sits in the center of the dining"+
	" room table. It contains several large %^RED%^red%^WHITE%^ apples.",
	({"apples","bowl of apples"}) : "%^BOLD%^%^RED%^A bowl full of tasty"+
	" looking red apples sits on top of the dining room table.",
	({"cabinet","cabinets","drawers","drawer"}) : "%^BOLD%^The cabinets and"+
	" drawers have been painted white and have %^BLACK%^black%^WHITE%^ cow"+
	" spots painted on them. It is a rather amusing look.",
	({"counter","counters"}) : "The counters in the kitchen are kept clean.",
	({"bottles","herbs","spices","bottles of herbs"}) : "Bottles of herbs and"+
	" spices are stacked neatly against the back wall of the kitchen.",
	"door" : "%^BOLD%^A pretty white door leads out the front of the house.",
	"bedroom door" : "A wooden door leads into the bedroom.",
	]));
	set_exits(([
	"north" : ROOMS+"yard7",
	"bedroom" : ROOMS+"bedroom2",
	]));
// I'd have sworn we made these like a bolt from inside so people couldn't get locked in by a reboot or forgetting and logging out there.  Either way, I'm removing the key "antioch house key" setting from this side for that reason now per bug reports.  *Styx*  10/31/04
	set_door("door",ROOMS+"yard7","north",0);
	set_door("bedroom door",ROOMS+"bedroom2","bedroom",0);
	if(query_night() == 1) {
		set_locked("door",1);
		new(MONS+"citizenj")->move(TO);
		new(MONS+"citizenk")->move(TO);
	}
}
