#include <std.h>
inherit ROOM;

void create()
{
	::create();
   set_terrain(LIGHT_FOREST);
   set_travel(FOOT_PATH);
	set_property("indoors",0);
	set_property("light",2);
	set_short("A hidden trail");
	set_long(
	"You are standing before the entrance of a large pine grove, the little"+
	" trail continues through it but it is very narrow. The rest of the pine"+
	" grove is thick and it would be almost impossible to get through the"+
	" trees. This path seems almost natural, however, the trees simply part"+
	" in front of it to let you through."
	);
	set_smell("default","The scent of pine floats in the air.");
	set_listen("default","The wind rustles through the trees.");
	set_items(([
	"pine grove" : "An ancient pine grove stands before you, stretching out"+
	" to the east and west. The trees are large and have grown together so"+
	" tightly that it would be impossible for anyone to pass between them"+
	" other than by this path.",
	({"trail","path"}) : "This little dirt path winds through the only"+
	" section of the pine grove possible to squeeze through. It seems as"+
	" though the trees have moved over to let the path through, but they"+
	" didn't give very much room that's for sure.",
	]));
	set_exits(([
	"south" : "/d/guilds/kindred/rooms/trail1",
	"north" : "/d/guilds/kindred/rooms/trail3",
	]));
}
