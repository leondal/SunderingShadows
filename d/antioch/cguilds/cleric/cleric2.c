#include <std.h>
#include "../cleric.h"
inherit ROOM;

void create()
{
	object obj;
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("no teleport",1);
	set_property("indoors",1);
	set_property("light",3);
	set_short("%^BOLD%^Cleric hall posting board");
	set_long(
	"The room has a large board on the west side for people to post"+
	" their ideas on. People in here are either posting something or"+
	" reading over new posts, so it is best to be respectfully quiet."+
	" There isn't much else in this room, anyway. The floors are cold"+
	" stone, but kept fairly clean. To the south is the entrance of"+
	" the cleric hall, to the north is the sitting room for clerics"+
	" to discuss their ideas and argue over religious issues. Directly"+
	" east is a room with a pool of water in it."
	);
	obj = new("std/bboard");
	obj->set_name("board");
	obj->set_id(({"board","bulletin board","cleric board"}));
	obj->set_board_id("cleric");
	obj->set_short("Cleric Posting Board");
	obj->set_long("This is a plain board that is fixed to the western"+
	" wall and is for people to post their ideas and suggestions on.");
	obj->set_max_posts(50);
	obj->set_location(ROOMS+"cleric2");
	obj->set_property("no animate",1);
	set_smell("default","The scent of lemons tingles your nose.");
	set_listen("default","You can hear the faint ripples of water.");
	set_items(([
	"floor" : "The cold stone floor looks as though it has been swept"+
	" recently.",
	"ceiling" : "The ceiling is made of flat gray stones.",
	]));
	set_exits(([
	"south" : ROOMS+"cleric1",
	"north" : ROOMS+"cleric3",
	"east" : ROOMS+"cleric5",
	]));
}
