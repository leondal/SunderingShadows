//bpath1.c - path for barrow downs new location.  Circe 11/22/04
#include <std.h>
#include "/d/tharis/barrow/short1.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(CEMETERY);
    set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",0);
    set_name("A path through the scrublands");
    set_short("A path through the scrublands");
    set_long("%^BLUE%^This narrow pathway meanders through the scrublands "+
       "at the edge of the oppressive %^BOLD%^%^BLACK%^marsh %^RESET%^"+
       "%^BLUE%^to the west.  A %^BOLD%^%^BLACK%^black cloud "+
       "%^RESET%^%^BLUE%^perpetually hangs over the marsh and the "+
       "eerie barrow downs just west of here.  Little grows here, "+
       "a stark contrast to the vibrant Kilkean Forest to the east."+
       "%^RESET%^\n");
    set_listen("default","You hear a low, distant howl.");
    set_smell("default","There is a distasteful odour in the air.");
    set_items(([
	"mound":"The mound in the distance is of the barrow type used to "
	"house the dead bodies of long lost warriors.",
	"grass":"All the brush grass is dead and withered as though it was "
	"slowly strangled.",
	"trees":"%^ORANGE%^The dead trees creak in the blowing wind "
	"and probably are "
	"responsible for the eerie moaning sounds you hear.%^RESET%^",
    ]));
    set_exits(([
       "west" : RPATH"bd1",
       "southeast" : RPATH"bpath2"
    ]));
}
