#include <std.h>
#include "../antioch.h"
inherit VAULT;

int count;

void create() {
	::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
	set_property("indoors",0);
	set_property("light",2);
   //set_property("no teleport",1);
	set_short("A back yard");
	set_long(
	"This is the back yard of a nice house. A screen door to the south leads"+
	" back into the house itself. The lawn here has been kept carefully"+
	" manicured. In the northern part of the lawn is a little wooden gazebo."+
	" Its roof is painted %^GREEN%^green%^RESET%^ and the lattice work on"+
	" the sides and walls are %^BOLD%^white%^RESET%^. Several small steps"+
	" lead up to the main platform, it is nice and airy. A gentle breeze is"+
	" blowing, rustling the leaves. A small plum tree is growing on the west"+
	" side of the lawn. Closer to the house several rose bushes have been"+
	" planted."
	);
	set_smell("default","You smell the sweet fragrance of roses.");
	set_listen("default","The wind rustling through the leaves.");
	set_items(([
	"gazebo" : "The little gazebo is in the northern part of the lawn. %^BOLD%^White%^RESET%^"+
	" lattice work covers the walls and sides of the gazebo. A few steps"+
	" lead up into it. The roof has been painted a %^GREEN%^dark green%^RESET%^"+
	" shade, and it comes to a conical point on top, letting the rain water"+
	" run off of it. There are a few benches within the gazebo for sitting"+
	" down on and relaxing. A gentle breeze is constantly blowing through"+
	" the lattice walls it seems.",
	"plum tree" : "%^GREEN%^A rather small plum tree has been planted on the western"+
	" side of the lawn. Several %^MAGENTA%^plums%^GREEN%^ hang in easy reach.",
	"plums" : "%^MAGENTA%^Ripe plums hang tantalizingly from the plum tree.",
	"roses" : "%^YELLOW%^Yellow%^WHITE%^ and %^RED%^red%^WHITE%^ roses are"+
	" blooming on the rose bushes near the house. They smell lovely.",
	({"rose bush","rose bushes"}) : "Close to the house are four large"+
	" rose bushes, they alternate between %^BOLD%^%^RED%^red%^RESET%^ and"+
	" %^YELLOW%^yellow%^RESET%^ roses. The roses are quite large, they must"+
	" be well cared for.",
	({"lawn","grass"}) : "%^BOLD%^%^GREEN%^The lawn has been kept carefully"+
	" manicured and the grass is growing well.",
	"house" : "The house is pretty, one story in height. The"+
	" outside is painted %^GREEN%^dark green%^RESET%^ and it has a"+
	" %^BOLD%^white%^RESET%^ trim. A screen door leads back into the house.",
	"back door" : "A screen door leads back into the house.",
	]));
	set_exits(([
	"south" : ROOMS+"house8",
	]));
	set_door("back door",ROOMS+"house8","south",0);
	count = 3;
}

void reset() {
	::reset();
	if(count < 3) {
		count = 3;
		add_item("plums","%^MAGENTA%^Ripe plums hang tantalizingly from the plum tree.");
		add_item("plum tree","%^GREEN%^A rather small plum tree has been"+
		" planted on the western side of the lawn. Several"+
		" %^MAGENTA%^plums%^GREEN%^ hang in easy reach.");
	}
}

void init()
{
	::init();
	add_action("pick_plum","pick");
}

int pick_plum(string str)
{
	if(str != "plum") {
		tell_object(TP,"Pick what?");
		return 1;
	}
	if(count < 1) {
		tell_object(TP,"There are no more plums left, they have all been picked.");
		return 1;
	}
	else {
		tell_object(TP,"You pick a ripe plum.");
		tell_room(ETP,""+TP->query_cap_name()+" picks a ripe plum.",TP);
		new(OBJ+"plum.c")->move(TP);
		count -= 1;
		if(count < 1) {
			add_item("plums","There don't seem to be any ripe ones left.");
			add_item("plum tree","%^GREEN%^A rather small plum tree has been"+
			" planted on the western side of the lawn. There are no plums on"+
			" it right now, however, they've all been picked.");
		}
		return 1;
	}
}
