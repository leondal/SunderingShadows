#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have entered a dark dreary cavern. Water drips down from the "+
	"ceiling of the cave. A faint light makes its way into the room, "+
	"casting shadows all around you."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","The air remains stale and hard to breath.");
    set_listen("default","The sound of dripping water echoes around the cavern.");
    set_exits( ([
	"north":"/d/tharis/caverns/cavern21"
    ]) );
}
void reset(){
    ::reset();
    if(!present("hook horror")){
	new("/d/tharis/caverns/mon/hook_horror")->move(this_object());
	new("/d/tharis/caverns/mon/hook_horror")->move(this_object());
	new("/d/tharis/caverns/mon/hook_horror")->move(this_object());
    }
}
