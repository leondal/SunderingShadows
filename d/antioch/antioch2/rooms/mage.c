#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
	set_short("Orflack's Component Shop");
	set_long(
	"Carefully lined up along the walls are shelves full of all sorts of"+
	" components. They appear to be carefully arranged, sorted by type. There"+
	" are shelves full of glass jars, dried herbs, minerals, and other odd"+
	" things. Each item has been placed in a particular spot, there are even"+
	" labels on the shelves to make sorting easier. There are some gaps on"+
	" the shelves, probably missing components. Towards the front of the"+
	" room is a long walnut counter. There is a set of scales, along with"+
	" some small bags, vials, and glass jars for sorting components with."+
	" The floor here is carpeted in a rich %^RED%^wine%^RESET%^ colored rug"+
	" that is surprisingly clean considering all the dusty components."
	);
	set_smell("default","The musty odor of odd components tickles your nose.");
	set_listen("default","The room is completely silent.");
	set_items(([
	({"wall","walls"}) : "The walls have been covered in plaster to help keep"+
	" the heat in and the cold out. They have been painted over in a %^BOLD%^%^RED%^light"+
	" red%^RESET%^ shade. Oil lamps are positioned at intervals around the room.",
	"ceiling" : "The ceiling is smooth and rather unremarkable.",
	({"lamp","lamps","oil lamp","oil lamps","gold tinted oil lamps","gold tinted lamp"}) : "%^YELLOW%^Golden tinted oil"+
	" lamps are fixed to the walls at intervals. The lamps shed light to the"+
	" room, but as they burn they also give off the pleasant smell of oranges.",
	({"floor","rug","carpet","wine carpet"}) : "%^RED%^A rich wine colored"+
	" carpet stretches across the room here. It is kept remarkably clean"+
	" considering all the dusty components around the room. The owner of this"+
	" shop probably placed some sort of spell on it.",
	({"counter","walnut counter","long counter"}) : "Towards the front of"+
	" the room is a long walnut counter. It has a set of scales for weighing"+
	" components with, along with some small bags, vials, and glass jars for"+
	" sorting things into.",
	({"shelf","shelves","components"}) : "All around the room are carefully"+
	" organized shelves of the miscellaneous components. They have been"+
	" organized according to type. There are shelves full of nothing but"+
	" glass jars with various items in them. Some have dried herbs, exotic"+
	" plants and flowers, while others are filled with minerals in different"+
	" shapes and forms. There are labels on all of the shelves, with gaps"+
	" inbetween some positions, probably signifying a missing component.",
	({"scales","bags","vials","glass jars"}) : "On top of the counter are"+
	" various items that are useful in the sorting of components.",
	]));
	set_exits(([
	"south" : ROOMS+"pal5",
	]));
	set_door("door",ROOMS+"pal5","south",0);
	set_string("door","open","The walnut door opens without a squeak.");
}

void reset()
{
	::reset();
	if(!present("orflack")) {
		new(MONS+"orflack")->move(TO);
	}
}
