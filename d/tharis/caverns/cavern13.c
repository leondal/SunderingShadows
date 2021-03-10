#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have reached a dead end. All but one of the torches in here "+
	"has burnt out. Alot of garbage is piled up in the room. This room "+
	"look like some sort of disposal area."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","The room reeks of garbage.");
    set_listen("default","Silence fills the air.");
    set_items( ([
	({"garbage"}):"A disgusting pile of garbage decaying in the room."
    ]) );
    set_exits( ([
	"west":"/d/tharis/caverns/cavern11"
    ]) );
}
void reset(){
    ::reset();
    if(!present("fungus")){
	new("/d/tharis/caverns/mon/fungus")->move(this_object());
    }
}
