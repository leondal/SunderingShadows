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
	"The area here has become a dreary sight indeed. Lightning lights "+
	"up the sky, black clouds thicken and swirl directly above you now. "+
	"The road has narrowed a bit, wagon tracks still evident on its "+
	"surface. The mountains lie to the immediate south."
    );
    set_items( ([ ({"tracks"}):"Plain old wagon tracks. This road might be used more than you thought..." ]) );
    set_property("light",2);
    set_property("indoors",0);
    set_smell("default","The wind is clean from any odors here.");
    set_listen("default","Thunder continues to roll through the sky sending a vibration through your body.");
    set_exits( ([ "north":"/d/tharis/road/sroad4",/*"south":"/d/tharis/road/sroad6"*/ ]) );
}
