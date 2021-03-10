#include <std.h>
#include "../shadow.h"

inherit ROOM;

void create(){
    ::create();
    set_property("light",2);
    set_name("Old wagon trail");
    set_short("%^GREEN%^Old wagon trail%^RESET%^");
    set_terrain(ROCKY);
    set_travel(RUTTED_TRACK);
    set_long(
"%^GREEN%^An old wagon trail%^RESET%^
%^ORANGE%^This old wagon %^WHITE%^trail%^ORANGE%^ leads north and east through the rocky terrain that makes up the foot hill area south and east of the joint between the Echoes Mountains and the Charu Mountains. This rocky rutted trail has seen little use. Obviously once a smugglers wagon trail blazed to bypass the tariffs found in Shadow City. Now those traveling here risk bandits and worse, for this is obviously not patrolled. You notice that the %^BOLD%^%^BLACK%^boulders%^RESET%^%^ORANGE%^ and %^GREEN%^scrub%^ORANGE%^ forest growth provide ample ambush opportunity.%^RESET%^
"
        );
    set_items(([
        "boulders": "These large rocks jut up from the ground. Some are quite large.",
        "scrub": "These smaller hardy trees have not achieved the size of those farther south but have managed to form thick copses.",
	"trail" : "That's about all it is now.  The ruts from the travel of many wagons remain among the rocks and make travel somewhat difficult.",	

               ]));
}

