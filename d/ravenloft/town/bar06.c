// Coded by Bane
// bar06.c
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_short("Village of Barovia");
    set_long(
	"%^RED%^"
	"You stand on a small dirt path.  To the west you "+
	"see a few buildings standing at the edge of the "+
	"village.  To the east the path continues into a "+
	"dark forest.  On either side of the path lies fields "+
	"of dead grass and crops."
	"%^RESET%^"
    );
    set_property("light",2);
    set_property("indoors",0);
    set_property("no teleport",1);
    set_listen("default","The sounds of wolves howling in the distance sends a shiver up your spine.");
    set_smell("default","You can smell smoke drifting towards you from the village.");
    set_exits( ([
	"west":"/d/ravenloft/town/bar08",
	"east":"/d/ravenloft/town/bar05",
    ]) );
}
