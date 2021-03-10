// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("x_smithy");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Drow%^RESET%^%^CYAN%^ S%^BOLD%^m%^RESET%^%^CYAN%^i%^BOLD%^t%^RESET%^%^CYAN%^h%^BOLD%^y%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^The %^RESET%^%^MAGENTA%^drow%^RED%^ smithy%^BOLD%^%^BLACK%^ is circular and reeks of %^GREEN%^coal,%^BLUE%^ metal,%^BLACK%^ and%^YELLOW%^ magic%^BLACK%^. Normally %^RED%^fires%^BLACK%"
	"^ underground are a tremendous threat -- it eats good air and can ignite coal dust and mysterious vapors. Here, this round domed room is alive with moving %^GREEN%^glyphs,%^BLUE%^ wards,%^BLACK%^ and "
	"protective %^CYAN%^sigils%^BLACK%^ filling the room with a glow from their green and blue light. The purpose of the spells is obvious -- in the center of the room is a giant firepit, fired by hot coal"
	"s, from which the smoke is sucked up in  a %^RESET%^%^CYAN%^v%^GREEN%^o%^BLUE%^r%^MAGENTA%^t%^CYAN%^e%^GREEN%^x%^BOLD%^%^BLACK%^ into a glowing orb which replaces the poisonous vapors with clean, cool"
	" air. Barrels of %^WHITE%^ore%^BLACK%^ line the walls alongside racks of %^WHITE%^tools. %^RESET%^"
	);

    set_smell("default","
You smell burning coal and hot metal.");
    set_listen("default","You can hear the clang of metal on metal");

    
set_items(([ 
	({ "glyphs", "wards", "sigils" }) : "The magic glyphs, wards, and sigils move like a kind of arcane writing. They circle around the orb and seem to keep it in place.",
	"tools" : "Hammer, tongs, file... what you need they got.",
	"webs" : "The webs have been made presumably by the oversized spiders used as mounts.",
	"silk" : "The webs have been made presumably by the oversized spiders used as mounts.",
	"vortex" : "All the soot and smoke from the forge and firepit is sucked up in a whirlwind vortex that leads into the orb and disappears.",
	"ore" : "Hot damn these drow are rich! That is mithril!",
	"blood" : "There is no blood on the ground despite the carnivorous nature of the spiders.",
	"cocoons" : "The cocoons have been made presumably by the oversized spiders used as mounts.",
	"orb" : "This is an orb of annhiliation, and it destroys all the smoke and bad air that is sucked up into it through the vortex. It must be some kind of drow humor as such an orb is truly perilous.",
	]));

    set_exits(([ 
		"southwest" : "/d/av_rooms/myrkul/x_ehall",
	]));

}