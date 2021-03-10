// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("crater");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^MAGENTA%^In a deep crater%^RESET%^");

    set_long("%^RESET%^%^MAGENTA%^You are standing in a deep crater.  It is approximately six feet from the surface, requiring a tremendous impact to drive the earth down so far.  The tunnel above is sheer and sugg"
	"ests it was melted, but the cavern you stand in now is with.  In the center of the cavern is what looks on the outside to be a giant %^BOLD%^%^BLACK%^rock split into two halves%^RESET%^%^MAGENTA%^.  I"
	"nside, the rock is hollow like a geode.  Rather than quartz stone inside, you see a frail looking mineral %^YELLOW%^still glowing the color %^BOLD%^%^RED%^of hot iron%^RESET%^%^YELLOW%^ and giving off"
	" a warm glow%^RESET%^%^MAGENTA%^.  The contents seem brittle, but far too hot to salvage, and probably worthless.%^RESET%^"
	);

    set_smell("default","%^ORANGE%^It smells sulfuric%^RESET%^");
    set_listen("default","%^RED%^A low crackle emanates from the geode%^RESET%^");

}