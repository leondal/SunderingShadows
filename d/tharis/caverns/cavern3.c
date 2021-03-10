//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"This cave gives you a bad feeling. The torch on the wall burns "+
	"low. Shadows flicker across the room. You feel very uneasy."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","The air smells old and stale.");
    set_listen("default","A few noises can be heard in the next few caves.");
    set_exits( ([
	"south":"/d/tharis/caverns/cavern2",
	"north":"/d/tharis/caverns/cavern5",
	"east":"/d/tharis/caverns/cavern6",
	"west":"/d/tharis/caverns/cavern7"
    ]) );
}
void reset(){
    ::reset();
    if(!present("hook horror")){
	new("/d/tharis/caverns/mon/hook_horror")->move(this_object());
    }
}
