//Updated due to the addition of a jail in Antioch. Kismet.
//Ready to be installed: Proper path is: /d/antioch/antioch2/rooms/street1 Remove this line. Kismet.

#include <std.h>
#include "../antioch.h"
#include <daemons.h>

inherit CVAULT;

void create()
{
   set_monsters( ({ "/d/antioch/antioch2/mons/patrol_guard", }), ({ roll_dice(1, 4) + 1 }));
   ::create();
	set_terrain(CITY);
	set_travel(PAVED_ROAD);
	set_property("outdoors",0);
	set_property("light",2);
	set_short("A cobbled street");
	set_long("A cobbled street.\n"+
"%^WHITE%^You are standing just inside the impressive %^BOLD%^%^ORANGE%^gates%^RESET%^%^WHITE%^ of the %^BOLD%^%^ORANGE%^New %^WHITE%^C%^ORANGE%^i%^WHITE%^t%^WHITE%^y %^ORANGE%^of %^ORANGE%^An%^WHITE%^t%^ORANGE%^i%^WHITE%^o%^ORANGE%^ch.%^RESET%^%^WHITE%^ The city is bustling with life, yet the thoroughfare is kept neat and relatively clean. To the west, there is a %^BOLD%^%^BLACK%^s%^BLACK%^q%^BLACK%^u%^BLACK%^a%^BLACK%^r%^BLACK%^e%^RESET%^%^WHITE%^ with a large tree in its center, behind which looms the city jail. The %^BOLD%^%^BLACK%^c%^BLACK%^obble%^BLACK%^s%^BLACK%^tone%^RESET%^%^WHITE%^ street leads you further north, towards a busy intersection, where you can see an entrance to the %^BOLD%^%^BLACK%^guard %^BLACK%^to%^BLACK%^w%^BLACK%^er.%^RESET%^%^WHITE%^ Opposite the tower, you can barely make out a %^BOLD%^%^WHITE%^p%^WHITE%^l%^WHITE%^a%^ORANGE%^que%^RESET%^%^WHITE%^ with the symbol of a Healer engraved onto it.
");
    set_smell("default","There is a faint herbal scent in the air.");
    if(query_night() == 1) {
        set_listen("default","You hear the sounds of a bustling city all around.");
        }
    else {
        set_listen("default","The streets are quiet, but you think you hear the low sound of snoring coming from the west.");
        }
	set_items(([
        ({"guard tower","tower"}) : "There's a guard tower on the"+
        " right, it looks like there's an entrance to it to the north.",
        ({"gate","gates","gates of antioch","Gates of Antioch","gates of Antioch"}) : "The enormouse iron gates are behind you and"+
        " they are still quite impressive, they look like they would"+
        " keep just about anything out.",
        "plaque" : "It's a wooden plaque with the symbol of a healer"+
        " engraved into it.",
        "street light" : "There's a street light up ahead.",
        "square" : "There is a square to the west.",
        ({"street","cobblestones","cobbles","road","path"}) : "The"+
        " street is paved with cobblestones.",
        ]));
	set_exits(([
        "east" : ROOMS+"gates",
        "west" : ROOMS+"square",
        "north" : ROOMS+"street2",
        ]));
    set_pre_exit_functions(({"east"}),({"go_east"}));
		"/d/antioch/antioch2/obj/sign"->move(TO);
}

int go_east()
{
	object obj;

    find_object_or_load("/d/antioch/antioch2/rooms/gates");
		"/d/antioch/antioch2/rooms/gates"->set_dir("east");
        return 1;
}
