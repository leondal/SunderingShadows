#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have entered a large cavern. The room is very well lit. Stone "+
	"statues decorate the northern wall of the room. A large brazier "+
	"burns in the middle of the room. Smoke from the brazier rises to "+
	"the ceiling and exits through a small opening."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","Smoke fills the air making you choke and cough.");
    set_listen("default","Just the crackling of the fire disrupts the silence.");
    set_items( ([
	({"brazier"}):"A large brazier that is lit in the middle of the cave. It burns very brightly illuminating the room and pouring smoke into the air.",
	({"statues"}):"A couple stone statues of hideous creatures."
    ]) );
    set_exits( ([
	"south":"/d/tharis/caverns/cavern19"
    ]) );
}
void reset(){
    ::reset();
    if(!present("gargoyle")){
	new("/d/tharis/caverns/mon/gargoyle")->move(this_object());
    }
}
