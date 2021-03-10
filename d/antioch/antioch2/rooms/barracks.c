//Updated due to the addition of a jail in Antioch. Kismet. 
//Ready to be installed. Proper path is: /d/antioch/antioch2/rooms/barracks Kismet.

#include <std.h>
#include "../antioch.h" 
inherit CVAULT;

void create()
{
    set_monsters( ({ "/d/antioch/antioch2/mons/patrol_guard", }), ({ roll_dice(1, 6) + 2, }) );
	::create();
	set_terrain(WOOD_BUILDING);
	set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_short("Antioch Guard Barracks");
    set_long("Antioch guard barracks\n"
 "This is a standard, if surprinslgy tidy, guard barracks. Clearly, the guards track in a lot of dirt every day, but they must put the broom to good use. There are several well-made bunk beds, all lined up against the back walls. A chest sits in front of each bunk bed, filled with extra clothing and personal items. Several soldiers could sleep in here at a time. Lamps have been fixed at intervals along the walls of the room. There is a round wooden table in the right corner near the door with several chairs around it, probably for playing games. A few bottles of beer and a pack of tobacco are left on the table. A modest fireplace is set into the western wall, providing warmth on cold days."
    );
	set_smell("default","It smells of sweaty soldiers, with a hint of tobacco.");
    if(query_night() == 1) {
        set_listen("default","You hear the obnoxious snoring of the guards.");
		}
    else {
        set_listen("default","The chatter of the guards fills the room.");
        }
	set_items(([
        ({"beds","bunk beds","bunk bed","bed"}) : "There are many sets of bunk beds, all lined up against the back of the room.",
        ({"trunk","chest"}) : "A chest rests in front of each bunk bed, holding clothing and personal items.",
        ({"laundry","clothing"}) : "There is a lot of clothing in the chests, some of it still looks dirty.",
        "table" : "There is a round wooden table tucked into the right corner near the door. It is probably used for playing games.",
        "chairs" : "Several wooden chairs are placed around the table.",
        "floor" : "Despite someone's best effort with the broom, the floor is still a bit dirty.",
    ]));
    set_exits(([
        "southeast" : ROOMS+"square",
    ]));
    set_door("door",ROOMS+"square","southeast",0);
}
