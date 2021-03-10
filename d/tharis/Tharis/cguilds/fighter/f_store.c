//cguilds/fighter/f_store.c

#include <std.h>

inherit ROOM;

void create(){
	::create();
	
	set_properties((["indoors":1,"light":2]));
    set_property("no teleport", 1);
	
	set("short","Fighter guild store");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^Fighter Guild Store%^RESET%^
Here is where the rare and unique items collected by the fighters of 
the Tharis fighter's guild place their items for use by all who made 
make use of them. The guild provides what it can for its members. Here
is where they put them for sale. Although the guild feels that it must
make money to support itself, the prices are extremely reasonable 
considering what was needed to get these weapons at one point.
OLI
	);
	set_exits(([
		"south":"/d/tharis/Tharis/cguilds/fighter/fhall"
		]));
	set_items(([]));
	set_smell("default","The smell of the oils and salves used in cleaning weapons reaches your nose.");
	set_listen("default","You hear a wetstone gliding roughly over a blade.");
	
}

void reset(){
	::reset();
	
	if(!present("mockspur"))
		new("/d/tharis/Tharis/cguilds/fighter/mockspur")->move(TO);
	}
