//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have entered a large dark cavern. Most of the cave has "+
	"collapsed, leaving rubble everywhere. Smoke pours in from "+
	"behind some of the rocks, coming from a blocked passage. "+
	"A small shaft has been dug into the ground leading down into "+
	"another cave."
    );
    set_property("light",2);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_smell("default","The smoke from the tunnel fills you lungs.");
    set_listen("default","Only the background sound of thunder can be heard.");
    set_exits( ([ "out":"/d/tharis/road/sroad6","down":"/d/tharis/caverns/cavern2" ]) );
}
