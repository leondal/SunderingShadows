#include <std.h>
#include "../antioch.h"
inherit VAULT;

int picked;

void create()
{
	::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
       set_property("indoors",0);
	set_property("light",2);
	set_short("A back yard");
	set_long(
	"This is the back yard of a pretty little house. It is very spacious"+
	" and has a few trees. There is even an apple tree with a few"+
	" delicious looking apples on it. Not far from the apple tree is"+
	" a large cedar tree with a rope swing attached to a thick branch."+
	" The lawn is kept well manicured and a little herb garden is"+
	" well maintained near the eastern side of the house."
	);
	set_smell("default","You smell mouth watering apples.");
	set_listen("default","The wind rustles through the trees.");
	set_items(([
	"back door" : "%^BOLD%^The back door leads into the house.",
	"house" : "The house is pretty, one story tall. The outside is"+
	" painted %^BOLD%^white%^RESET%^ and it has a %^BOLD%^%^CYAN%^sky"+
	" blue%^RESET%^ trim. A back door leads into the house.",
	({"ground","grass","lawn"}) : "%^BOLD%^%^GREEN%^Lush green grass"+
	" grows vibrantly throughout the yard, but it is kept well manicured.",
	"trees" : "A couple of trees are scattered across the yard.",
	"apple tree" : "A large apple tree is growing at the southern end"+
	" of the yard. It has several large %^BOLD%^%^RED%^red%^RESET%^"+
	" apples on it.",
	"cedar tree" : "A big cedar tree stands near the center of the"+
	" yard. Tied to its thickest branch is a little rope swing with a"+
	" wooden seat.",
	({"swing","rope swing"}) : "A rope swing is tied to a thick branch"+
	" of a cedar tree. It has a wooden seat and looks fairly sturdy.",
	({"seat","wooden seat"}) : "%^BOLD%^%^BLUE%^The wooden seat has"+
	" been painted a bright blue shade, but is rather worn from the"+
	" elements.",
	({"herb garden","garden"}) : "On the eastern side of the house,"+
	" just below the kitchen window, is a little herb garden. It doesn't"+
	" have anything too rare or fancy in it, but it's nice to have"+
	" fresh herbs for cooking.",
	]));
	set_exits(([
	"north" : ROOMS+"house2",
	]));
	set_door("back door",ROOMS+"house2","north",0);
	picked = 3;
}

void init()
{
	::init();
	add_action("pick","pick");
	add_action("swing","swing");
	add_action("sit","sit");
}

void reset()
{
	::reset();
	picked = 3;
}

int pick(string str)
{
	if(str != "apple") {
		tell_object(TP,"Pick what?");
		return 1;
	}
	if(picked < 1) {
		tell_object(TP,"There are no more apples within reach and the"+
		" tree is not sturdy enough to climb.");
		return 1;
	}
	else {
		tell_object(TP,"You reach up and pick a big %^BOLD%^%^RED%^red%^RESET%^"+
		" apple off the tree.");
		tell_room(ETP,""+TP->query_cap_name()+" picks an apple off the"+
		" tree.",TP);
		new(OBJ+"apple")->move(TP);
		picked -= 1;
		if(picked < 1) {
			add_item("apple tree","A large apple tree is growing at the"+
			" southern end of the yard. All the apples within reach"+
			" have been picked, however.");
		}
		return 1;
	}
}

int swing(string str)
{
	if(str != "swing") {
		tell_object(TP,"Swing what?");
		return 1;
	}
	else {
		tell_object(TP,"%^BOLD%^You swing happily on the rope swing,"+
		" feeling like a kid again.");
		tell_room(ETP,"%^BOLD%^"+TP->query_cap_name()+" swings happily"+
		" on the rope swing.",TP);
		return 1;
	}
}

int sit(string str)
{
	if(str == "seat" || str == "swing") {
		tell_object(TP,"%^BOLD%^%^BLUE%^You sit down carefully on the"+
		" rope swing.");
		tell_room(ETP,"%^BOLD%^%^BLUE%^"+TP->query_cap_name()+" sits"+
		" down carefully on the rope swing.",TP);
		return 1;
	}
}
