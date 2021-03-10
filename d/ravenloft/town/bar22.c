// Coded by Bane
// bar22.c
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_short("Village of Barovia");
    set_long(
	"%^RED%^"
	"You are on one of the villages main roads.  There "+
	"are houses on either side of you, most of them "+
	"are either abandoned or too dangerous to live in.  "+
	"There are a few peasants sitting in the gutter "+
	"begging for food or spare change.  The road "+
	"continues to the northeast and southwest."
	"%^RESET%^"
    );
    set_property("light",2);
    set_property("indoors",0);
    set_property("no teleport",1);
    set_listen("default","The sounds of wolves howling in the distance sends a shiver up your spine.");
    set_smell("default","You can smell smoke drifting towards you from the village.");
    set_exits( ([
	"northeast":"/d/ravenloft/town/bar21",
	"southwest":"/d/ravenloft/town/bar23",
	"northwest":"/d/ravenloft/town/bar81",
	"southeast":"/d/ravenloft/town/bar58",
    ]) );
}
