#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have entered a small cavern. The ceiling is very low and you "+
	"have to lean over to avoid bumping your head. The room is fairly "+
	"clean but poorly lit. Light from the adjacent room pours in to "+
	"keep you from being in total darkness."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","The air here smells stale.");
    set_listen("default","Running water can be heard from outside this cavern.");
    set_exits( ([
	"south":"/d/tharis/caverns/cavern7"
    ]) );
}
void init(){
    ::init();
    if(!present("worm")){
	new("/d/tharis/caverns/mon/gworm")->move(this_object());
    }
}
