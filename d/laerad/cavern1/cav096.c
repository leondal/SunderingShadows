//Coded by Bane//
#include <std.h>
inherit "/d/laerad/cavern1/special/croom_cavern.c";

void create(){
    set_monsters( ({"/d/laerad/mon/hook_horror", "/d/laerad/mon/umber_hulk"}), ({2, 1}) );
    ::create();
    set_repop(80);
    set_short("Laerad caverns");
    set_long(
	"You are standing in some underground slave pen.  Wooden stockade "+
	"fencing winds its way around the cave leaving only a few exits into "+
	"other pens.  The ceiling is low, only about 9 feet from the ground.  "+
	"A small stream of water is running along one of the walls.  Atop some "+
	"of the fence poles are small globes of light, keeping the area fully "+
	"illuminated."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is surprisingly clean and refreshing.");
    set_listen("default","You can hear the trickling of the stream.");
    set_exits( ([
	"east":"/d/laerad/cavern1/cav092",
	"north":"/d/laerad/cavern1/cav114",
	"south":"/d/laerad/cavern1/cav097"
    ]) );
}
void reset(){
    ::reset();
/* changing to use CROOM
    if(!present("horror")){
	new("/d/laerad/mon/hook_horror")->move(this_object());
	new("/d/laerad/mon/hook_horror")->move(this_object());
    }
    if(!present("hulk")){
	new("/d/laerad/mon/umber_hulk")->move(this_object());
    }
*/
}
