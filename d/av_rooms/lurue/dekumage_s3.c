// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_s3");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("decayed floor");
    set_climate("tropical");

    set_short("%^BOLD%^%^BLACK%^A small stall%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^The stall is home to an %^RESET%^old gray mare %^ORANGE%^well past her prime.  The wooden walls were once beautiful and well tended, now they are warped and broken, revealing splint"
	"ers and nails here and there.  The ground is covered in a thin nest of %^YELLOW%^dried para grass %^RESET%^%^ORANGE%^that looks to have been freshly added today.  A bowl for %^BLUE%^water %^ORANGE%^an"
	"d another for %^RESET%^food %^ORANGE%^are attached to the wall under a window that looks out over the swamp.%^RESET%^"
	);

    set_smell("default","
You can smell the musk of horse flesh and fresh ground cover.");
    set_listen("default","An occasional whinny breaks the insect's drone.");

    
set_items(([ 
	({ "mare", "horse" }) : "%^RESET%^%^ORANGE%^The old horse looks like she's on her last legs.  The sway back and dull gaze along with the tack lines make you think she spends her days plowing the soil of the nearby fields.%^RESET%^",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/dekumage_s1",
	]));

}