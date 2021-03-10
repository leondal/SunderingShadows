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
	set_short("A cobbled street");
	set_long(
	"You are standing just inside the gates of Antioch. To the"+
	" west are the barracks with the guards, who are making a"+
	" lot of noise. The street leads up north and you can see"+
	" an intersection. It also looks like there's an entrance"+
   " to the guard tower and you can barely make out a plaque"+
	" with the symbol of a Healer engraved onto it."
	);
	set("night long",
	"Warm light spills forth from many doorways to help light"+
	" the way, and a street light is posted at the intersection"+
	" up ahead. To the west are the guard barracks, it sounds"+
	" like they're having a lot of fun in there. On the east"+
	" is the guard tower, it looks like there's an entrance to"+
	" it a bit further north. Across from the guard tower appears"+
    " to be a Healer. You can make out the proprietary symbol"+
   " engraved into a plaque outside the door."
	);
	set_smell("default","There is a faint herbal scent in the"+
	" air.");
	if(query_night() == 1) {
		set_listen("default","The snoring of the barrack guards"+
		" is incredibly loud.");
	}
	else {
		set_listen("default","The guards in the barracks are"+
		" being rowdy, as usual.");
	}
	set_items(([
	({"guard tower","tower"}) : "There's a guard tower on the"+
	" right, it looks like there's an entrance to it to the north.",
	({"gate","gates","gates of antioch","Gates of Antioch","gates of Antioch"}) : "The enormouse iron gates are behind you and"+
	" they are still quite impressive, they look like they would"+
	" keep just about anything out.",
   "plaque" : "It's a wooden plaque with the symbol of a healer"+
	" engraved into it.",
	"street light" : "There's a street light up ahead.",
	"barracks" : "The barracks are to the west",
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	]));
	set_exits(([
	"east" : ROOMS+"gates",
	"west" : ROOMS+"barracks",
	"north" : ROOMS+"street2",
	]));
	set_door("door",ROOMS+"barracks","west",0);
	set_pre_exit_functions(({"east"}),({"go_east"}));
   "/d/antioch/antioch2/obj/sign"->move(TO);
}

int go_east()
{
	object obj;

	find_object_or_load("/d/antioch/antioch2/rooms/gates");
	"/d/antioch/antioch2/rooms/gates"->set_dir("east");
	return 1;
}
