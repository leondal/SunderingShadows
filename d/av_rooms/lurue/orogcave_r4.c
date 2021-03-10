// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("orogcave_r4");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("mountain");

    set_short("%^RESET%^%^BLUE%^a %^BOLD%^%^BLACK%^gr%^BLUE%^a%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te%^RESET%^%^BLUE%^ cave%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^Tables made from thick slabs of smoothed %^RESET%^%^ORANGE%^wood %^BOLD%^%^BLACK%^have been set in rows extending out from a raised head table.  Beside each, several %^RESET%^%^ORANGE"
	"%^wooden benches %^BOLD%^%^BLACK%^are arranged, giving seating for the giants that call this place their home.  To one side of the room a large shaft opens over a dark pit through which a faint %^RESE"
	"T%^%^RED%^reddish gleam %^BOLD%^%^BLACK%^can be seen.  A spit extends across the opening, hanging from a set of thick %^RESET%^metal chains %^BOLD%^%^BLACK%^that are designed to lower and raise the sp"
	"it as needed.   Plate and drink ware, consisting of large disks of steal, wooden bowls and other less refined materials are stacked up on a nearby table, where a couple of %^RESET%^%^CYAN%^cauldrons %"
	"^BOLD%^%^BLACK%^are also set out with some sort of frothing liquid inside.  Ladles can be seen nearby for dishing out the soup as needed, though with no sign of heat it is a mystery why the liquid con"
	"tinues to boil and froth.%^RESET%^"
	);

    set_smell("default","
The deep scent of earth, metal and bodies permeates the air.");
    set_listen("default","The sounds of Orog can be heard echoing through the halls.");


    set_exits(([ 
		"south" : "/d/av_rooms/lurue/orogcave_h4",
	]));

}