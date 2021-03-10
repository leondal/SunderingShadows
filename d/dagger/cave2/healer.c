#include <std.h>

inherit HEALER;

void create() 
{
    ::create();
    set_light(3);
    set_property("training",1);
    set_property("no teleport", 1);
    set_indoors(1);
    set_short("The witch's enclave");
    set_long(
      "You have stumbled into the enclave of the Ogre Witch.  All around you candles burn on the walls, keeping the walls lit as she brews her potions and works her magic."
    );
    set_smell("default", "The strong odor of herbs and balms turns your "
      "stomach.");
    set_listen("default", "You can hear water dripping in the back of the cave somwhere.");
    set_items( ([
	"wall" : "It is a wall.",
      ]) );
    set_exits( ([
    //"out" : "/d/dagger/cave2/cave121",
      ] ));
}

