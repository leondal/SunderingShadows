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
	"The road continues towards the mighty mountains south of here. "+
	"Tumbleweed is carried past you by the furious wind. A single "+
	"dead tree stands off to the side of the road, vultures cover "+
	"the branches. The birds seem to watch you omninously, following "+
	"your every move."
    );
    set_items( ([ ({"tree"}):"This tree leans in towards the road. Striped of all its precious leaves, it waits here, rotting, waiting for its certain death.",({"vultures"}):"These large scavengers keep a close eye on you. Watching you patiently, as if they expect you to be their next meal." ]) );
    set_listen("default","The crying of the vultures puts you on the edge of your nerves.");
    set_smell("default","The smell of decaying flesh carries through the air.");
    set_property("light",2);
    set_property("indoors",0);
    set_exits( ([ "north":"/d/tharis/road/sroad2","east":"/d/tharis/road/sroad4" ]) );
}
