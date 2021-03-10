#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
	set_short("%^YELLOW%^Palace of Antioch");
	set_long(
	"You are at the bottom of a grand stair case that leads up to the royal"+
	" throne room. The stairs are all covered in a %^YELLOW%^gold%^RESET%^"+
   " and %^RED%^crimson%^RESET%^ rug. The grand stair way starts at the top"+
	" of the second floor and splits into two branches, curving out to the"+
	" edges of the room. The railings are made out of highly polished"+
	" chestnut wood that has a golden sheen in the lamp light. Different"+
	" crests are positioned about the room, all from visiting cities and"+
	" nations that have made peaceful alliances with Antioch. Hanging down"+
	" from the center of the stair case is a %^BOLD%^white%^RESET%^ banner"+
	" with a %^BOLD%^unicorn%^RESET%^ on it, holding a %^MAGENTA%^%^BOLD%^pink"+
	" rose%^RESET%^ in his mouth, a symbol of peace."
	);
	set_smell("default","The faint scent of oranges is in the air.");
	set_listen("default","A respectful silence cloaks the room.");
	set_items(([
	"rug" : "A large rug covers the entire floor, stretching off to the north"+
	" and south. It fits perfectly to each set of stairs as it climbs up them."+
	" It is finely woven and quite thick and sturdy. %^YELLOW%^Gold%^RESET%^"+
	" is the primary color of the rug, and a few slender %^RED%^crimson%^RESET%^"+
	" stripes line the edges.",
	({"wall","walls"}) : "The walls have been covered in plaster to help keep"+
	" the heat in and the cold out. They have been painted over in a %^BOLD%^%^RED%^light"+
	" red%^RESET%^ shade. Crests of foreign nations hang from the walls"+
	" with oil lamps positioned inbetween them.",
	"floor" : "The floor is covered in a large rug.",
	"ceiling" : "The ceiling is smooth and rather unremarkable.",
	({"lamp","lamps","oil lamp","oil lamps","gold tinted oil lamps","gold tinted lamp"}) : "%^YELLOW%^Golden tinted oil"+
	" lamps are fixed to the walls at intervals between the crests. The"+
	" lamps shed light to the room, but as they burn they also give off the"+
	" pleasant smell of oranges.",
	({"stairs","stair case","grand stair case","railing","railings"}) : "%^YELLOW%^The grand"+
	" stair case leads up to the throne room on the second floor. It starts"+
	" on either side of the room, slowly curving inwards to join together"+
	" in front of an large archway on the second level. The railing are made"+
	" out of highly polished chestnut wood. It glows with a deep golden"+
	" sheen in the lamp light.",
	({"crests","banners"}) : "Different crests and banners from various"+
	" cities and nations are hung about the hall. You recognize the banners"+
	" of Shadow and Azha, there is Seneca and Daggerdale, along with many"+
	" others, some of which you don't recognize.",
	({"crest","banner","white banner"}) : "%^BOLD%^A white banner hangs down"+
	" from the top of the stair case. It has on it a unicorn with %^MAGENTA%^pink"+
	" rose%^WHITE%^ in his mouth, a symbol of peace and good intentions.",
	]));
	set_exits(([
	"south" : ROOMS+"pal6",
	"stairs" : ROOMS+"pal8",
	]));
	set_pre_exit_functions(({"stairs"}),({"go_stairs"}));
}

int go_stairs()
{
	write("You slowly walk up the grand stair case.");
	return 1;
}
