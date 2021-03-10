#include <std.h>
#include "short.h"

inherit CITYIN;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_short("front yard.");
    set_property("indoors",0);
    set_property("light",3);
    set_long(
      "   You stand before a modest house. It appears very old and well used. Although seemingly in a state of disrepair, you sense it is a home that was once vibrant with life. Thin ivy grows upon its facade and green grass grows underfoot. There are strange markings above the door."
    );
    set_exits(([
	"enter" : THIEF "thief2",
	"east" : "/d/attaya/seneca/street8",
      ]));
    set_door("door", "/d/attaya/seneca/cguilds/thief/thief2", "enter", 0);
    set_open("door", 0);
    set_items(([
	"path" : "It is a small cobblestone path.",
	"grass" : "Curiously the green grass looks like it has been recently cut.",
	"markings" : "The markings above the door are in colours of %^MAGENTA%^purple%^RESET%^ and %^BLUE%^blue%^RESET%^. They seen to create some sort of pattern but what the patterns symbolize is beyond your understanding.",
      ]));


}
