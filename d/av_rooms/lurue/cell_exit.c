// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("cell_exit");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("A small stone room");

    set_long("%^RESET%^%^CYAN%^This small room seems to serve as a holding room for the jail below.  The most noticeable feature of this room are the set of %^BOLD%^%^BLACK%^stairs %^RESET%^%^CYAN%^leads down into "
	"a stone hallway and presumably toward the jail cells.  A %^ORANGE%^wood counter %^CYAN%^is off to the side where prisoners can be check in and out, and a narrow window in the wall with a %^BLACK%^%^BO"
	"LD%^metal door%^RESET%^%^CYAN%^, allows for items or possessions to be passed back and forth.%^RESET%^"
	);

    set_smell("default","The faint scent of wood polish lingers here.");
    set_listen("default","You hear the occasional cry of one of the prisoners.");

    
set_items(([ 
	({ "counter", "wood counter" }) : "The counter is a simple affair that allows the jailor to gather equipment from those being processed as well as holding the paper work for jailing the individual. ",
	({ "window", "door", "metal door" }) : "This small, narrow window, allows items taken from the prisoners to be passed through to another room for safe keeping.",
	]));

    set_exits(([ 
		"stairs" : "/d/av_rooms/lurue/cell_hall",
		"out" : "/d/azha/town/jail",
	]));

}