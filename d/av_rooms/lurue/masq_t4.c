// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("masq_t4");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^A %^MAGENTA%^C%^RESET%^%^GREEN%^o%^MAGENTA%^l%^BOLD%^%^WHITE%^or%^RESET%^%^MAGENTA%^f%^GREEN%^u%^BOLD%^%^MAGENTA%^l %^WHITE%^Tent%^RESET%^");

    set_long("%^RESET%^%^GREEN%^You duck under a curtain flap and find yourself in a comfortably appointed dressing room. %^BOLD%^%^MAGENTA%^Pink%^RESET%^%^GREEN%^, %^MAGENTA%^purple%^GREEN%^, %^GREEN%^green %^GREE"
	"N%^and %^RESET%^white %^GREEN%^stripes line the walls in wide swaths, each with a suspended %^CYAN%^mirror %^GREEN%^that allows you to see all angles of your costume.  A small %^ORANGE%^wooden stand %"
	"^GREEN%^is tucked in one corner with a %^WHITE%^porcelain %^GREEN%^wash basin, while the corner opposite has a simple %^BOLD%^%^BLACK%^chair%^RESET%^%^GREEN%^.  The other two corners have hooks for ha"
	"nging things up on.  While there is a sense of fantasy in the delicate carving work on the %^ORANGE%^wood frames %^GREEN%^and %^BOLD%^%^BLACK%^furniture%^RESET%^%^GREEN%^, the illusion of a fair fanta"
	"sy world is not as noticeable except for in your elaborate costume.%^RESET%^"
	);

    set_smell("default","
%^RESET%^%^ORANGE%^A %^BOLD%^%^WHITE%^sweet%^RESET%^%^ORANGE%^, %^RESET%^%^MAGENTA%^delicate %^ORANGE%^fragrance graces the air.%^RESET%^");
    set_listen("default","Laughter and merriment echo through the tent.");

    
set_items(([ 
	({ "curtain", "curtain flap", "flap" }) : "%^RESET%^Made of heavy %^MAGENTA%^magenta%^RESET%^ tent canvas, it is sewn along the top and one side to the tent panels, allowing it to drop back down into place easily.  A little clever dowel and ring system along the open side of the flap allow the curtain to be secured while the occupant is changing.",
	({ "stripes", "walls", "tent", "panel", "panels" }) : "%^RESET%^%^GREEN%^The tent is colorful and created from large stripes of heavy tent canvas in several colors.  Protecting and providing a large space for such a gathering.%^RESET%^",
	({ "wash basin", "basin" }) : "%^RESET%^The basin is set atop a simple wooden stand with two shelves.  Fresh face towels are placed on the lower one and pitcher with fresh water sits on the upper one.  You could easily clean up with a bit of a spongbath before donning your costume.%^RESET%^",
	({ "hook", "hooks" }) : "%^RESET%^Two simple brass hooks have been affixed to the tent poles of the interior corners, allowing for you to hang a few things up while you change.%^RESET%^",
	"chair" : "%^BOLD%^%^BLACK%^A straight backed, fairly plain chair has been provided to assist you with donning your costume.  The legs and back of which have been carved with a %^MAGENTA%^fl%^WHITE%^o%^MAGENTA%^wer%^BLACK%^ motif.%^RESET%^",
	"mirror" : "%^RESET%^%^CYAN%^There are three mirrors placed in this room, one directly opposite the entrance and one to either side.  Free standing and oval in shape, they are surrounded by a thin wooden frame carved with floral decoration. %^RESET%^",
	]));

    set_exits(([ 
		"southwest" : "/d/av_rooms/lurue/masq_t2",
	]));

    set_door("magenta flap","/d/av_rooms/lurue/masq_t2","southwest");
    set_open("magenta flap",0);
    set_string("magenta flap","knock","knocks upon the wooden frame beside the");
    set_string("magenta flap","open","You lift the heavy canvas flap.");
    set_string("magenta flap","close","You lower the heavy canvas flap back into place.");
    set_door_description("magenta flap","%^RESET%^Made of heavy %^MAGENTA%^magenta %^RESET%^tent canvas, it is sewn along the top and one side to the tent panels, allowing it to drop back down into place easily.  A little clever dowel and ring system along the open side of the flap allow the curtain to be secured while the occupant is changing.%^RESET%^");
}