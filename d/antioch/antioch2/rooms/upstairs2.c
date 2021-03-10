#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
	set_short("An elegant house");
	set_long(
	"You are on the second floor of an elegant house. On the left hand side"+
	" is the entrance to a bathroom. You can see a shower, lavatory, and a"+
	" sink with a mirror. Towels are hanging against the far wall and there"+
	" is a %^BOLD%^%^MAGENTA%^pink%^RESET%^ rug that covers part of the floor."+
	" The walls have been painted %^BOLD%^white%^RESET%^ and the floor looks"+
	" recently swept. To the north is a large bedroom. The floor has been"+
	" covered in a thick %^MAGENTA%^amethyst%^RESET%^ carpet. On the other"+
	" side of the bathroom wall is a large closet that could hold a lot of"+
	" clothing. Against the western wall is a shadowtop dresser. In the"+
	" northeastern corner is a large bed made out of shadowtop. Next to it"+
	" is an ebony nightstand with a tiny lamp on it. A large window takes up"+
	" most of the northern wall, overlooking the front yard."
	);
	set_smell("default","You can smell the fresh mountain air.");
	set_listen("default","The house is quiet.");
	set_items(([
	({"floor","carpet","amethyst carpet"}) : "%^MAGENTA%^The floor is covered"+
	" in a thick amethyst carpet.",
	({"rug","pink rug"}) : "%^BOLD%^%^MAGENTA%^There is a small pink carpet"+
	" on the floor of the bathroom, it absorbs the water when you step out"+
	" of the shower.",
	({"wall","walls"}) : "%^BOLD%^The walls have been painted a pretty"+
	" lavender shade.",
	({"lamp","tiny lamp"}) : "There is a tiny oil lamp on top of the"+
	" nightstand that is lit.",
	({"nightstand","night stand","ebony nightstand"}) : "%^BOLD%^%^BLACK%^A"+
	" dainty ebony night stand sits next to the bed. A tiny lamp sits on top"+
	" of it.",
	"bed" : "A large bed is tucked into the northeastern corner of the room."+
	" A thick %^MAGENTA%^purple%^RESET%^ bedspread covers it and there are"+
	" several thick feather pillows for comfort.",
	({"pillows","feather pillows"}) : "%^BOLD%^Several thick feather pillows"+
	" are on the bed.",
	({"bedspread","purple bedspread"}) : "%^MAGENTA%^A thick purple bedspread"+
	" covers the bed. It looks quite warm, and it perfectly matches the carpet.",
	"dresser" : "A large shadowtop dresser takes up most of the western wall."+
	" It is approximately five feet high and two feet deep. It can store a"+
	" lot of clothing.",
	"closet" : "A large closet is placed against the adjoining bathroom and"+
	" bedroom wall.",
	"sink" : "%^BOLD%^There is a small porcelain sink set into a cabinet. It"+
	" has a spicket pump that can be used to fill the sink with water.",
	"shower" : "There is a shower in the bathroom that uses some of the latest"+
	" technology, allowing a continuous stream of water that is magically"+
	" heated to pour over someone.",
	"lavatory" : "A simple lavatory is tucked into the far corner of the"+
	" bathroom. Pipes lead down and out of the house, carrying the refuse"+
	" away.",
	"towels" : "Several towels are hung up on the far wall of the bathroom.",
	]));
	set_exits(([
	"down" : ROOMS+"house6",
	]));
}
