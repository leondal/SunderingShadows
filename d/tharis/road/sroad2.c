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
	"As this road leads further away from Tharis it becomes more "+
	"secluded. A few wagon tracks mark the road. The little brush that is left "+
	"along the road is all brown and dried up. The mountains are "+
	"becoming very visible to the south now."
    );
    set_listen("default","Only the howling of the wind can be heard.");
    set_smell("default","You can smell nothing more than the air itself.");
    set_property("light",2);
    set_property("indoors",0);
    set_exits( ([ "north":"/d/tharis/road/sroad1","south":"/d/tharis/road/sroad3" ]) );
}
