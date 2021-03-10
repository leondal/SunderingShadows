#include <std.h>
#include "../eroad.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(LIGHT_FOREST);
   set_travel(FOOT_PATH);
	set_property("indoors",0);
	set_property("light",2);
	set_short("Outside an Old Mill");
	set_long(
	"The little path dead ends next to an old lumber mill. This small lumber"+
	" mill supplies Tharis and the surrounding cities with lumber when they"+
	" need it. It has not had business in quite some time, however. Ivy and"+
	" moss have begun to creep up the walls, and the roof looks as though"+
	" it could use a little patching. The large water wheel is still slowly"+
	" churning, though, hoping to be used once again."
	);
	set_smell("default","The faint scent of pine hangs in the air.");
	set_listen("default","The water wheel splashes into the stream as it turns.");
	set_listen("birds","You can hear the pleasant trill of bird song in the"+
	" distance.");
	set_listen("brush","You hear the rustling of the brush.");
	set_listen("animals","Animals scurry about in the trees and under the"+
	" forest brush.");
	set_items(([
   ({"mill","lumber mill","old mill","old lumber mill"}) : "To the east is"+
	" an old run down mill. At one point this tiny thing helped to supply"+
	" Tharis and the surrounding cities with lumber, but now that the cities"+
	" are finished there is little use for this old mill. It has since"+
	" become rather worn down, though someone must obviously still take"+
	" care of it on occassion.",
	({"pine","pines","pine trees"}) : "You look around for the source of the"+
	" pine scent and spot a large pine grove to the north.",
	"pine grove" : "A large pine grove surrounds a fair sized area a bit north"+
	" of here. There might be a faint trail that could lead to it heading"+
	" northeast from here.",
	"stream" : "%^BOLD%^%^BLUE%^A tiny stream meanders through the forest,"+
	" curving near the old mill for the water wheel to splash into it, slowly"+
	" turning. The stream disappears out of sight, lost in the trees to the"+
	" east.",
	"roof" : "The roof on the mill is very old and has started to droop a"+
	" little. It could use some patching in more than one place.",
	({"walls","ivy","moss"}) : "The walls of the old mill have ivy and moss"+
	" creeping up along them.",
	"door" : "An old door barely hangs from its hinges, leading into the mill.",
	({"wheel","water wheel"}) : "A large water wheel is attached to the old"+
	" mill on the eastern most wall. It slowly turns thanks to the stream"+
	" trickling by. If the mill were in use the water wheel would be generating"+
	" power for the saw blades, but there is no need for it now.",
	"path" : "The small dirt path that you are walking on winds its way around"+
	" the large trees. It looks as though it hasn't been used in a while for"+
	" grass is starting to grow up in the center of the path and a few weeds"+
	" have stretched themselves across it.",
	"grass" : "%^BOLD%^%^GREEN%^Tufts of grass have begun growing in the"+
	" center of the path.",
	"weeds" : "%^GREEN%^Several spindly weeds have stretched themselves out"+
	" along sections of the path.",
	"trees" : "Large trees tower over you, stretching up to incredibly heights."+
	" They are obviously very old, but they are in quite good health. You"+
	" can hear squirrels and other animals scurrying about in their branches.",
	"brush" : "Brush grows thick along the forest floor, you can see it"+
	" moving in places and hear the animals that are rustling about.",
	"forest" : "This is part of the legendary Tharis Forest. The trees are"+
	" old and tall, towering above you, and the entire place is alive with"+
	" signs of life. It is hard to believe this is still part of the same"+
	" forest back to the east, it doesn't feel dangerous at all.",
	]));
	set_exits(([
	"south" : ROOMS+"path3",
	"enter" : ROOMS+"mill",
	"northeast" : "/d/guilds/kindred/rooms/trail1",
	]));
	set_invis_exits(({"northeast"}));
    //set_pre_exit_functions(({"northeast"}), ({"GoThroughDoor"}));
	set_door("door",ROOMS+"mill","enter",0);
}

void init()
{
	::init();
	add_action("peer","peer");
}

int GoThroughDoor()
{
	if(query_verb() != "northeast") return ::GoThroughDoor();
	if(query_verb() == "northeast") {
		if(avatarp(TP)) {
			tell_object(TP,"You discover a hidden path to the northeast.");
			return 1;
		}
		if(member_array("The Kindred",TP->query_guild()) != -1) {
			tell_object(TP,"You take the hidden northeast path.");
			return 1;
		}
		else {
			tell_object(TP,"You cannot go that way.\n");
			return 0;
		}
	}
}

void peer(string str)
{
	if(!str) return 0;
	if(str == "enter") {
		tell_object(TP,"You cannot see through indoor rooms.");
		return 1;
	}
	if(str != "south" && str != "s") {
		tell_object(TP,"You can see nothing in that direction.");
		return 1;
	}
}
