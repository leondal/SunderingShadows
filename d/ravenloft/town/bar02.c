// Coded by Bane
// bar02.c
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_short("Village of Barovia");
    set_long(
	"%^RED%^"
	"You stand on a small dirt path.  To the west lies "+
	"the village of Barovia and to the east the small path "+
	"continues to a bend.  On either side of the path is "+
	"a dark forest, the trees are bare and sway lifelessly "+
	"in the wind."
	"%^RESET%^"
    );
    set_property("light",2);
    set_property("indoors",0);
    set_property("no teleport",1);
    set_listen("default","The sounds of wolves howling in the distance sends a shiver up your spine.");
    set_smell("default","You can smell smoke drifting towards you from the village.");
    set_exits( ([
	"west":"/d/ravenloft/town/bar03",
	"east":"/d/ravenloft/town/bar01",
    ]) );
}
