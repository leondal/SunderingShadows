// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("orogcave_h9");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("mountain");

    set_short("%^RESET%^%^BLUE%^a %^BOLD%^%^BLACK%^gr%^BLUE%^a%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te%^RESET%^%^BLUE%^ cave%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^The stairs end abruptly here, opening into a small anteroom complete with large %^RESET%^%^ORANGE%^wooden chairs %^BOLD%^%^BLACK%^organized around an oval stone table.  Carved into th"
	"e table is a large regional map over which several wooden markers have been set.  The %^RESET%^%^CYAN%^symbols %^BOLD%^%^BLACK%^on the markers are not very clear but you can see several of the marks a"
	"re repeated throughout.  Hung from the ceiling is a %^RESET%^%^CYAN%^dark lantern%^BOLD%^%^BLACK%^, casting the room into darkness, concealing the %^RESET%^%^BLUE%^alcove %^BOLD%^%^BLACK%^that leads a"
	"way to the south.  Little else adorns the room.  Unlike the level below, the ornate decorations appear to have vanished and left the clean, natural coloration of the dark granite alone.%^RESET%^"
	);

    set_smell("default","
The deep scent of earth, metal and bodies permeates the air.");
    set_listen("default","The sounds of Orog can be heard echoing through the halls.");


    set_exits(([ 
		"south" : "/d/av_rooms/lurue/orogcave_r8",
		"northwest" : "/d/av_rooms/lurue/orogcave_h8",
	]));

}