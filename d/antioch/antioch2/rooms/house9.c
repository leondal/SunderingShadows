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
	set_short("A lovely house");
	set_long(
	"This is a pleasant, old-fashioned, two story house. The hardwood floors"+
	" are a little creaky, but they're clean. On the north side of the room"+
	" is the dining room. A large couch faces the eastern window, with a"+
	" love seat on one side and a padded chair on the other. West of the"+
	" living room is the kitchen. The kitchen looks very large and old fashioned, a"+
	" %^BOLD%^white%^RESET%^ door leads into it. On the southern side of the"+
	" house is the dining room. The dining set is made out of mahogany, it"+
	" has six matching chairs around it. In the center of the table is a"+
	" crystal vase filled with lillies. To the west of the dining room is"+
	" a polished banister and set of stairs that lead up to the second floor."
	);
	set_smell("default","The house smells faintly lemony.");
	set_listen("default","The house is quiet.");
	set_items(([
	({"floor","hardwood floor"}) : "The hardwood floors are a bit creaky"+
	" but they are clean.",
	({"wall","walls"}) : "%^BOLD%^The walls have been painted a bright white"+
	" color that has dulled a little over time. A few oil lamps are scattered"+
	" about the walls.",
	({"lamps","lamp","oil lamp","oil lamps"}) : "Oil lamps are hung at"+
	" intervals along the walls, they give light to the room.",
	"ceiling" : "The ceiling is rather plain.",
	({"banister","stairs","stair case","polished banister"}) : "A polished"+
	" mahogany banister is on the southwestern side of the room. The stairs"+
	" lead up to the second floor.",
	({"dining table","table","mahogany table"}) : "The dining set is made"+
	" of mahogany wood. It has a lovely finish and is surrounded by six"+
	" matching chairs. A crystal vase full of lillies sits in the center of"+
	" the table.",
	({"chairs","dining chairs","mahogany chairs"}) : "Six matching chairs"+
	" surround the dining room table.",
	({"vase","crystal vase"}) : "%^BOLD%^A large crystal vase sits in the"+
	" center of the dining room table. It is filled with about half a dozen"+
	" lillies.",
	"lillies" : "%^BOLD%^Half a dozen beautiful lillies fill the crystal vase."+
	" They look very delicate and lovely...but on a closer inspection you"+
	" realize that they are made of silk, they aren't real!",
	"window" : "There is a glass window on the northeastern side of the house."+
	" It overlooks the front porch and can be opened to let a light breeze in.",
	"couch" : "%^ORANGE%^A slightly shabby old beige couch is in the living"+
	" room, facing the eastern window. It could probably fit four people"+
	" comfortably.",
	"love seat" : "%^YELLOW%^A cream colored love seat sits next to the old"+
	" couch. It is definitely much newer and looks relatively unused.",
	({"chair","padded chair"}) : "A chair with %^YELLOW%^cream%^RESET%^"+
	" colored cushions sits not far from the couch.",
	"kitchen door" : "%^BOLD%^A white door on the northwestern side of the"+
	" house leads to the kitchen.",
	"door" : "%^BOLD%^A pretty white door leads out to the front porch.",
	]));
	set_exits(([
	"east" : ROOMS+"yard9",
	"up" : ROOMS+"upstairs3",
	"kitchen" : ROOMS+"kitchen3",
	]));
// I'd have sworn we made these like a bolt from inside so people couldn't get locked in by a reboot or forgetting and logging out there.  Either way, I'm removing the key "antioch house key" setting from this side for that reason now per bug reports.  *Styx*  10/31/04
	set_door("door",ROOMS+"yard9","east",0);
	set_door("kitchen door",ROOMS+"kitchen3","kitchen",0);
	new(MONS+"citizenm")->move(TO);
	if(query_night() == 1) {
		set_locked("door",1);
	}
}
