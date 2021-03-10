// Coded by Bane
// bar01.c
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_short("Village of Barovia");
    set_long(
	"%^RED%^"
	"You stand on a small dirt path.  To the west lies "+
	"the village of Barovia and to the northeast are "+
	"a pair of iron gates that reach far into the "+
	"sky.  The gates are connected to a stone wall on either "+
	"side.  The walls reach as high as the gates and follow "+
	"the countryside for as far as your eye can see.  "+
	"On either side of the path is a dark forest, the trees "+
	"are bare and sway lifelessly in the wind."
	"%^RESET%^"
    );
    set_property("light",2);
    set_property("indoors",0);
    set_property("no teleport",1);
    set_listen("default","The sounds of wolves howling in the distance sends a shiver up your spine.");
    set_smell("default","You can smell smoke drifting towards you from the village.");
    set_items( ([
	({"gates"}):"The gates are made of a strong iron and "+
	"are closed right now.  They appear to reach far into "+
	"the sky, almost into the clouds.",
    ]) );
    set_exits( ([
	"west":"/d/ravenloft/town/bar02",
    ]) );
}
