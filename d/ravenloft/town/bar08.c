// Coded by Bane
// bar08.c
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_short("Village of Barovia");
    set_long(
	"%^RED%^"
	"You are standing on the eastern side of the village "+
	"of Barovia.  There is an intersection here that leads "+
	"to the east, west, north and south.  There are houses "+
	"on both sides of the road, mostly worn and beaten from "+
	"age and weather."
	"%^RESET%^"
    );
    set_property("light",2);
    set_property("indoors",0);
    set_property("no teleport",1);
    set_listen("default","The sounds of wolves howling in the distance sends a shiver up your spine.");
    set_smell("default","You can smell smoke drifting towards you from the village.");
    set_exits( ([
	"west":"/d/ravenloft/town/bar87",
	"east":"/d/ravenloft/town/bar06",
	"north":"/d/ravenloft/town/bar09",
	"south":"/d/ravenloft/town/bar46",
    ]) );
}
void reset(){
    ::reset();
    if(!present("villager")){
	new("/d/ravenloft/mon/villager")->move(TO);
	new("/d/ravenloft/mon/villager")->move(TO);
    }
}
