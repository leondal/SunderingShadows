#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
   set_property("no iron key",1);
	set_short("%^YELLOW%^Palace of Antioch");
	set_long(
	"You are in a hallway outside of the throne room. To the north are the"+
	" large double doors that lead to the chambers of the king. The doors"+
	" are impressive, made of incredibly thick steel. They are gilded with"+
	" with sparkling multi-hued gems. You notice that the carpet here is now"+
	" %^RED%^crimson%^RESET%^ with %^YELLOW%^gold%^RESET%^ stripes on the"+
	" edges. The walls here have been painted a pale tan color and they are"+
	" decorated with pictures. Oil lamps made of crystal are hung at intervals"+
	" along the walls, the light from them seems to dance and sparkle about"+
	" the room. To the south is the top of the grand stair case that leads"+
	" back down to the first floor. The hallway continues to the east and west."
	);
	set_smell("default","The soothing scent of vanilla floats in the air.");
	set_listen("default","A respectful silence cloaks the room.");
	set_items(([
	"rug" : "A large rug covers the entire floor, stretching off to east"+
	" and west. It is finely woven and quite thick and sturdy. %^RED%^Crimson%^RESET%^"+
	" is the primary color of the rug, and a few slender %^YELLOW%^crimson%^RESET%^"+
	" stripes line the edges.",
	({"lamp","lamps","oil lamp","oil lamps","crystal lamps","crystal oil lamps"}) : "%^BOLD%^Crystal"+
	" oil lamps are hung at intervals along the walls. The light shines"+
	" through the crystal, expanding and sparkling about the room. They give"+
	" off a pleasant vanilla scent.",
	"pictures" : "Down either hallway you can see pictures hung on the walls.",
	"ceiling" : "The ceiling is rather unremarkable, but it is fun to stare"+
	" at the dancing lamp light.",
	"floor" : "The floor is covered in a large rug.",
	({"wall","walls"}) : "The walls have been covered in plaster to help keep"+
	" the heat in and the cold out. They have been painted over in a pale tan"+
	" color. Paintings are hung on the walls and oil lamps are fastened at"+
	" fixed intervals.",
	({"stairs","grand stair case","stair case"}) : "Behind you is the top of"+
	" the grand stair case that leads back down to the first floor of the"+
	" palace.",
	({"door","doors","double doors","steel doors"}) : "The double doors to"+
	" the north are made out of solid steel and are at least an inch thick."+
	" Platinum, electrum, gold, and silver are overlaid into patterns on the"+
	" door. Multi-hued stones have also been gilded into the door in"+
	" spectacular style. Although the patterns are quite beautiful, they are"+
	" also undoubtedly enchanted with magic to keep out intruders.",
	]));
	set_exits(([
	"north" : ROOMS+"throne",
	"stairs" : ROOMS+"pal7",
	"west" : ROOMS+"pal9",
	"east" : ROOMS+"pal10",
	]));
	set_door("double doors",ROOMS+"throne","north","antioch palace key");
	set_string("double doors","open","The double doors open slowly, revealing"+
	" the magnificent throne room beyond them.");
	set_pre_exit_functions(({"stairs"}),({"go_stairs"}));
	if(query_night() == 1) {
		set_open("double doors",0);
		set_locked("double doors",1);
		find_object_or_load("/d/antioch/antioch2/rooms/throne");
		"/d/antioch/antioch2/rooms/throne"->set_open("double doors",0);
		"/d/antioch/antioch2/rooms/throne"->set_locked("double doors",1);
	}
}

void reset()
{
   ::reset();
   if(!present("palace guard 2")) {
   new(MONS+"palace_guard")->move(TO);
   }
   if(!present("palace guard 2")) {
      new(MONS+"palace_guard")->move(TO);
   }
   return;
}

int go_stairs()
{
	write("You slowly descend the grand stair case.");
	return 1;
}
