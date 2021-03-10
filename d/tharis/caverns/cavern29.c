//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have entered a massive cavern. The ceiling of the cave, "+
	"if there is one, is beyond your vision, perhaps hundred of feet "+
	"up. Bats screech and flap around the cave constantly. A small "+
	"stream of water runs through the massive room, flowing north. "+
	"Many tunnels run from this cave."
    );
    set_smell("default","A fresh breeze blows through the cavern.");
    set_listen("default","The rushing of water can be heard.");
    set_property("light",2);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_exits( ([
	"southwest":"/d/tharis/caverns/cavern27",
	"southeast":"/d/tharis/caverns/cavern35",
	"west":"/d/tharis/caverns/cavern33",
	"northwest":"/d/tharis/caverns/cavern32",
	"north":"/d/tharis/caverns/cavern31",
	"northeast":"/d/tharis/caverns/cavern34"
    ]) );
}
