// Coded by Bane
// bar92.c
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_short("Village of Barovia");
    set_long(
	"%^RED%^"
	"You are now in the village square.  The road here is "+
	"actually paved with stone.  There is a large open area "+
	"surrounded with shops, houses, and benches.  Some of "+
	"the benches are occupied with homeless covered in "+
	"rags.  The road continues to the north, south, east and west."
	"%^RESET%^"
    );
    set_property("light",2);
    set_property("indoors",0);
    set_property("no teleport",1);
    set_listen("default","The sounds of wolves howling in the distance sends a shiver up your spine.");
    set_smell("default","You can smell smoke drifting towards you from the village.");
    set_exits( ([
	"north":"/d/ravenloft/town/bar29",
	"south":"/d/ravenloft/town/bar35",
	"east":"/d/ravenloft/town/bar91",
	"west":"/d/ravenloft/town/bar93",
	"northeast":"/d/ravenloft/town/bar48",
	"southeast":"/d/ravenloft/town/bar47",
    ]) );
}
void reset(){
    ::reset();
    if(!present("villager")){
	new("/d/ravenloft/mon/villager")->move(TO);
	new("/d/ravenloft/mon/villager")->move(TO);
	new("/d/ravenloft/mon/villager")->move(TO);
    }
    if(!present("gypsy")){
	new("/d/ravenloft/mon/gypsy2")->move(TO);
	new("/d/ravenloft/mon/gypsy2")->move(TO);
    }
}
