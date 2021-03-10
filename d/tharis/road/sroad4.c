#include <std.h>
inherit ROOM;
void create(){
    ::create();
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);
   set_property("no teleport",1);
    set_name("Nevermore road");
    set_short("Nevermore road");
    set_long(
    "After a slight turn off, the road once again continues "+
	"on its straight path. The terrain has become a problem now, "+
	"the area is very rocky and hazardous. The sky has begun to darken, "+
     "black clouds gather above. An enormous mountain stands not too far "+
	"away."
    );
    set_property("light",2);
    set_property("indoors",0);
    set_listen("default","The crack of thunder breaks the silence, a storm is brewing.");
    set_smell("default","The wind carries an odd odor.");
    set_exits( ([ "west":"/d/tharis/road/sroad3","south":"/d/tharis/road/sroad5" ]) );
}
