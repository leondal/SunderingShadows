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
	set_short("A large kitchen");
	set_long(
	"This is a rather luxurious kitchen. The hardwood floor is swept clean"+
	" and the counters have been wiped off. The walls here are painted"+
	" %^BOLD%^white%^RESET%^ and the counters and cabinets are a %^BOLD%^%^CYAN%^pale"+
	" blue%^RESET%^ shade. A lamp hangs down from the ceiling, lighting the"+
	" room. In the center of the southern counter is a large sink with a"+
	" spicket pump. On the western wall is a large oven and stove. There is"+
	" a spice rack filled with bottles of various spices. There is a window"+
	" on the southern wall that lets fresh air into the room."
	);
	set_smell("default","You can smell the herbs and spices.");
	set_listen("default","The kitchen is quiet.");
	set_items(([
	"floor" : "This hardwood floor looks well swept.",
	"ceiling" : "An oil lamp hangs down from the ceiling.",
	({"lamp","oil lamp"}) : "An oil lamp with a %^BOLD%^%^CYAN%^pale blue%^RESET%^"+
	" cover hangs down from the ceiling, shedding light on the room.",
	({"wall","walls"}) : "%^BOLD%^The walls have been painted white.",
	({"cabinets","drawers","cabinet"}) : "%^BOLD%^%^CYAN%^All the cabinets"+
	" and drawers are a pale blue shade. They hold the dishes and silver"+
   " ware.",
	"sink" : "In the middle of the southern wall is a large porcelain sink."+
	" It has a metal spicket pump that can be used to fill the sink with water.",
	({"stove","oven"}) : "Against the western wall is the oven. It is made"+
	" of metal and stone bricks. On top of it is a stove that can be used"+
	" for cooking.",
	({"spice rack","bottles","spices"}) : "There is a wooden spice rack on"+
	" top of the counter, it holds a few dozen small bottels of herbs and"+
	" spices that are used in cooking.",
	"window" : "There is a window on the southern wall that is open to let"+
	" the fresh air in.",
	({"counter","counters"}) : "%^BOLD%^%^CYAN%^The counters stretch around"+
	" the room, allowing a large space for cutting and preparing meals. They"+
	" have been painted a pale blue color.",
	]));
	set_exits(([
	"house" : ROOMS+"house6",
	]));
}
