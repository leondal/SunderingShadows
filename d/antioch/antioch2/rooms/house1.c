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
	set_short("A quaint little house");
	set_long(
	"This small little house is divided up to allow for the maximum"+
	" space. In the northwestern corner is the kitchen with the dining"+
	" room right next to it. On the west side is the living room with"+
	" a couch and two chairs. The bedroom is in a little room in the"+
	" eastern corner. You can see a fair sized bed, a little dresser"+
	" and a closet. This house could best be described as cozy."
	);
	set_smell("default","You can still smell the clean mountain air.");
	set_listen("default","The house is quiet.");
	set_items(([
	({"chair","chairs"}) : "Two chairs sit next to the couch in the"+
	" living room. They are a matching beige and look rather drab.",
	"kitchen" : "A small kitchen is tucked into the northwestern"+
	" corner of the house. There is a little stove and oven there,"+
	" along with cabinets that and a counter with a cutting board on"+
	" it. A few pots and pans are hanging from the wall there.",
	"dining room" : "The tiny dining room is on the northeastern"+
	" side of the house. It contains an oval dining room table and"+
	" four matching chairs. It is small, but not much else could fit"+
	" in this house.",
	"couch" : "A beige couch rests on the west side of the room,"+
	" creating a living room area. It looks like it would be comfortable,"+
	" but appears to be rather old and worn.",
	"bedroom" : "A little bedroom is tucked into the eastern corner"+
	" of the house. It does have walls around it to provide privacy,"+
	" but you can see through the doorway. It contains a fair sized"+
	" bed, and a small dresser and closet. Not much else could fit"+
	" in there.",
	"bed" : "A fair sized bed takes up most of the bedroom, it could"+
	" comfortably fit two people. Judging from the rest of the house,"+
	" however, and the fact that the bed isn't made, it probably"+
	" belongs to a hopeful bachelor.",
	"dresser" : "A little dresser is crammed into the tiny bedroom."+
	" It could fit a fair number of clothes in it, but looks to be"+
	" used more as a storage space for various things.",
	"closet" : "The closet in the bedroom is rather small, but it"+
	" looks like it could hold a small ward robe for one person.",
	"door" : "%^YELLOW%^A yellow door leads out of the house.",
	"floor" : "The floor is made of wood, there is no carpet or rug"+
	" on top of it, but it looks very clean.",
	"ceiling" : "The ceiling is rather dull, simply plain wood.",
	({"wall","walls"}) : "%^YELLOW%^The walls are a sunny shade of"+
	" yellow. Oil lamps are attached to them to give off light.",
	({"lamps","lamp","oil lamp","oil lamps"}) : "Oil lamps are"+
	" attached to the walls to give light to the little house.",
	]));
	set_exits(([
	"south" : ROOMS+"yard1",
	]));
// I'd have sworn we made these like a bolt from inside so people couldn't get locked in by a reboot or forgetting and logging out there.  Either way, I'm removing the key "antioch house key" setting from this side for that reason now per bug reports.  *Styx*  10/31/04
	set_door("door",ROOMS+"yard1","south",0);
	new(MONS+"citizena")->move(TO);
	if(query_night() == 1) {
		set_locked("door",1);
	}
}
