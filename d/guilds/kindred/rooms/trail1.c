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
	"You are on a hidden trail that leads north to a large pine grove. Directly"+
	" south is the Old Mill, you can hear the water wheel still splashing"+
	" in the stream. This path has been very carefully hidden from the one"+
	" that leads to the mill, it would be almost impossible for someone to"+
	" spot you from there. Yet the trail you're on, though small, is well"+
	" defined. Only someone wise in the ways of the forest could have created"+
	" this path."
	);
	set_smell("default","The scent of pine floats in the air.");
	set_listen("default","The wind rustles through the trees.");
	set_items(([
	"pine grove" : "Straight north of you is a large pine grove.",
	({"path","trail"}) : "A carefully hidden but well defined path leads"+
	" north, straight to the pine grove.",
	]));
	set_exits(([
	"southwest" : "/d/tharis/road/path4",
	"north" : "/d/guilds/kindred/rooms/trail2",
	]));
}
