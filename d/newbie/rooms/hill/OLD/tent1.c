#include <std.h>
#include "../../newbie.h"

inherit ROOM;

//temp fix to keep them from unloading from disuse -
int clean_up() { return 0; }

void create(){
    ::create();
    set_light(2);
    set_indoors(1);
    set_short("A nice sturdy tent");
    set_terrain(HUT);
    set_travel(DIRT_ROAD);
    set_long(
      "This is a nice little tent with sturdy poles that has been made to be very quickly and easily set up.  The sturdy cloth for the walls and roof has been coated to be waterproof.  A lantern is hanging from a pole for light.  It's just large enough for the two small cots it holds to sit or sleep on and a large, leather-bound wooden storage chest.  You probably don't want to make your camp in here, however.  Not only is it already crowded, the occupants will probably take the tent down while you sleep and leave you out in the open."
    );
    set_smell("default", "The canvas smells a little musty.");
    set_listen("default", "Sometimes you hear voices from outside the tent.");
    set_exits( ([ "back":HILL"hill15",
    ]) );
/*Note:  Leave a default exit in case the room doesn't load at reboot from another one. */
    set_items(([
      "chest":"This is a large wooden chest with leather straps to provide handles and buckle it closed.  It is large enough to hold the tent and cot materials and other possessions.  The tent poles slip into pockets on the outside of it or can be run through straps on the side to make it easier for two people to carry or one person to pull along behind them.",
		({"cot", "cots"}):"These are cots with a wooden frame and sturdy material laced across to create a simple bed.",
		({"cloth","walls"}):"The cloth is a sturdy canvas-type material that is even stiffer and heavier because of the oils added to make it turn water.",
    ]) );
}

void init() {
	::init();
}
