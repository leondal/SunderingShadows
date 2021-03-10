#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_travel(DIRT_ROAD);
   set_terrain(WOOD_BUILDING);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^BOLD%^White Dragon Inn");
	set_long(
	"This is a very warm and friendly inn. On the north wall is a"+
	" desk with someone behind it to check customers in and escort"+
	" them to their rooms. A grand stairway with a large railing"+
	" spirals up to the second floor and rests in the center of the room."+
	" The floor is covered in a thick %^GREEN%^green carpet%^RESET%^"+
	" that stretches into the eastern room. On the southern wall is"+
	" a large and impressive mural of a %^BOLD%^white dragon%^RESET%^. It's so big"+
	" that it stretches into the next room. The %^BOLD%^%^RED%^eyes%^RESET%^ of the great"+
	" wyrm glitter and seem to follow you as you move and %^BOLD%^%^BLACK%^smoke%^RESET%^ is"+
	" slowly blown out of its nose. As you meet its eyes you can"+
	" hear a low rumble issuing forth from its deep throat. You can"+
	" see how this inn got its name, the mural must be magical in"+
	" nature and the image of the dragon is emblazoned on your mind."+
	" You can still feel its %^RED%^%^BOLD%^eyes%^RESET%^ on you even after you've looked"+
	" away."
	);
	set_smell("default","Delicious scents waft in from the kitchen.");
	set_listen("default","The clank and clatter of dishes can be heard.");
	set_items(([
	"floor" : "The floor is covered in a thick %^GREEN%^green carpet%^RESET%^"+
	" that looks very clean.",
	"desk" : "A large wooden desk is positioned in the northwestern"+
	" corner of the room. A log book sits on top of it with the"+
	" names and room numbers of each guest that stays here.",
	({"book","log book"}) : "The large log book sits on top of the"+
	" desk, containing the names of the guests and which room they"+
	" are staying in.",
	({"stairs","stair way","stairway"}) : "A grand set of spiralling"+
	" stairs extends from the center of the room up to the second"+
	" floor. It has a large railing to hold onto for safety.",
	({"carpet","thick carpet","green carpet"}) : "%^GREEN%^This is"+
	" a thick green carpet that muffles your footsteps.",
	({"lamp","lamps"}) : "A few lamps are hung on the walls on the"+
	" edges of the room to keep things well lit.",
	({"wall","south wall","southern wall"}) : "On the southern wall"+
	" is a mural of a large white dragon that stretches into the"+
	" next room.",
	({"mural","dragon","white dragon","white wyrm","great dragon","great wyrm"}) : "%^BOLD%^The"+
	" mural is quite impressive, the image of the dragon is very"+
	" life like. Its %^RED%^eyes%^WHITE%^ seem to stare at you"+
	" hungrily and a low growl issues from its throat. The wyrm is"+
	" so large that the end of its body reaches well into the next"+
	" room. %^BLACK%^Smoke%^WHITE%^ spills forth from its nose slowly."+
	" You know the image must be magically created, but it is still"+
	" just a bit unnerving and you don't want to turn your back on"+
	" it.",
	]));
	set_exits(([
	"west" : ROOMS+"street24",
	"east" : ROOMS+"inn2",
	"up" : ROOMS+"inn4",
	]));
	set_door("door",ROOMS+"street24","west",0);
	set_pre_exit_functions(({"stairs"}),({"go_stairs"}));

}

int go_stairs()
{
	write("You carefully ascend the large spiral stair case.");
	say(""+TP->query_cap_name()+" carefully ascends the large spiral"+
	" stair case.");
	return 1;
}
