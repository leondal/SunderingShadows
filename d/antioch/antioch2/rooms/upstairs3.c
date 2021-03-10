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
	set_short("A lovely house");
	set_long(
	"This is the second floor of a lovely, if rather old-fashioned, house."+
   " The floor has been left bare and has a tendency to creak in certain"+
	" places. Directly in front of you is a large bathroom. There is a bath"+
	" tub in one corner with a latrine across from it. Against the back wall"+
	" are several shelves full of large and fluffy towels. A %^BOLD%^%^BLUE%^blue%^RESET%^"+
	" rug is laid out over the tiled floor. On the east is a spacious bedroom."+
	" There is a window that overlooks the front yard, it is slightly cracked"+
	" to let a breeze blow through. %^YELLOW%^Sunny%^RESET%^ curtains frame"+
	" the window. There is a bed in the northeastern corner, a mahogany"+
	" night stand is next to it. There is a dresser against the wall adjoining"+
	" the bathroom, on top of it is a large lamp with a %^BOLD%^white%^RESET%^"+
	" shade. In the southeastern corner of the room there is a rocking chair."
	);
	set_smell("default","The house smells faintly lemony.");
	set_listen("default","The house is quiet.");
	set_items(([
	"floor" : "The floor is very clean, but it does have a tendency to creak"+
	" in certain places.",
	"ceiling" : "The ceiling is flat, plain, and boring.",
	({"wall","walls"}) : "%^BOLD%^The walls have been painted a bold white"+
	" color that has slightly faded with time.",
	({"rug","blue rug"}) : "%^BOLD%^%^BLUE%^A blue rug has been laid out"+
	" in front of the bath tub to help absorb any water that may splash out.",
	({"bathroom floor","tiles","tiled floor"}) : "%^BOLD%^%^CYAN%^The bathroom"+
	" floor has been covered in baby blue tiles to preserve the hardwood"+
	" floor from water.",
	"latine" : "A latrine is in the bathroom across from the bath tub. There"+
	" is a small bucket next to it that needs to be filled with water from"+
	" the tub and poured into the latrine in order to flush the contents"+
	" down the drain that leads to a septic tank somewhere outside.",
	"shelves" : "Against the far wall of the bathroom are several shelves that"+
	" have lots of towels stacked on top of them.",
	({"towels","fluffly towels","large fluffy towels"}) : "%^BOLD%^Lots of"+
	" large, fluffy towels are stacked on the shelves in the bathroom.",
	"bed" : "An average sized mahogany bed is against the northeastern corner."+
	" It is covered in a %^BOLD%^white%^RESET%^ quilt with lillies embroidered"+
	" onto it.",
	({"quilt","white quilt"}) : "%^BOLD%^A white quilt covers the bed. It"+
	" has been embroidered with designs of lillies. It looks warm and cozy.",
	"window" : "A window on the eastern wall overlooks the front porch. It"+
	" has been left slightly open to allow a breeze to pass through.",
	({"curtains","yellow curtains","sunny curtains"}) : "%^YELLOW%^Sunny"+
	" yellow curtains frame the window. They flutter slightly in the breeze.",
	({"night stand","nightstand","mahogany night stand"}) : "A mahogany night"+
	" stand is next to the bed. A glass of water sits on top of it.",
	({"water","glass","glass of water"}) : "A glass of water is on the night"+
	" stand next to the bed, probably for sipping at night.",
	"dresser" : "A mahogany dresser is against the wall adjoining the bathroom."+
	" It is quite large, about five feet in height and two feet wide. It"+
	" could hold a lot of clothes. On top of it is a lamp that lights the"+
	" room.",
	({"lamp","oil lamp","large lamp"}) : "An oil lamp sits on top of the"+
	" dresser, shedding light to the rest of the room. A %^BOLD%^white%^RESET%^"+
	" lamp shade covers it.",
	({"white shade","shade","lamp shade"}) : "%^BOLD%^A white lamp shade"+
	" covers the lamp, making the light coming from it seem softer and a bit"+
	" more dim.",
	({"chair","rocking chair"}) : "A large wooden rocking chair is on the"+
	" southeastern side of the room. It looks like it has gotten a lot of"+
	" use. From its vantage one could see out the window there, watching"+
	" all that goes on outside.",
	"stairs" : "A set of stairs leads down to the first floor.",
	]));
	set_exits(([
	"down" : ROOMS+"house9",
	]));
}
