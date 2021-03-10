#include <std.h>
inherit ROOM;
void create(){
    ::create();
   set_terrain(BARREN);
   set_travel(DIRT_ROAD);
   set_property("no teleport",1);
    set_name("Nevermore road");
    set_short("Nevermore road");
    set_long(
	"This road leads to the south of Tharis towards the mountains. It "+
	"is said that those who follow this trail and return, return with "+
	"great wealth. But then again this road doesn't look like it is "+
	"used much. The forest seems to clear up a bit, leaving a small "+
	"dirt road leading onward."
    );
    set_listen("default","The screeching wind bites your ears.");
    set_smell("default","The smell of the fresh air comforts you.");
    set_property("light",2);
    set_property("indoors",0);
    set_exits( ([ "south":"/d/tharis/road/sroad2" ]) );
}
