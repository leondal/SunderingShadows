#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You are standing on a sandy underground beach. Waves lap up onto "+
	"the shore, a strong current carries them from the wall at the far "+
	"side of the lake."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","A salty breeze drifts through the air.");
    set_listen("default","The sound of waves crashing onto the shore can be heard.");
    set_items( ([
	({"lake"}):"The lake is very large. A green glow radiates from its depths. A strong current carries waves from the wall across the cavern...how strange that a current is coming from the wall..."
    ]) );
    set_exits( ([
	"north":"/d/tharis/caverns/cavern18"
    ]) );
}
void reset(){
    ::reset();
    if(!present("dragon turtle")){
	new("/d/tharis/caverns/mon/dragturtle")->move(this_object());
    }
}
