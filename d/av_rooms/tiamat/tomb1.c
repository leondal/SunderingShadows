// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tomb1");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("mountain");

    set_short("%^RESET%^%^CYAN%^Tomb of the Long Winter%^RESET%^");

    set_long("%^RESET%^%^CYAN%^You have entered a place forgotten by time.  The decor suggests this is a tomb of some kind, but glacial ice has invaded, locking the old architecture in a frozen state.  Rough stones"
	" compose the floor and walls, but their surfaces are decorated with remarkable m%^BOLD%^o%^MAGENTA%^s%^RED%^a%^RESET%^%^CYAN%^i%^WHITE%^c%^BLUE%^s%^CYAN%^ in various stages of disrepair.  This is a wi"
	"de entry hall with a vaulted ceiling supported by thick pillars.  Sconces and candlesticks suggest this place was once used with some regularity by the living, but that time is lost to history. To eit"
	"her side of you, extension tunnels have been blocked off by an avalanche of solid %^BOLD%^ice%^RESET%^%^CYAN%^.  An arched doorway lies ahead, its cornerstone inscribed in a foreign %^ORANGE%^script%^"
	"CYAN%^.%^RESET%^ "
	);

    set_smell("default","
%^GREEN%^You smell the sterile ice.");
    set_listen("default","%^ORANGE%^You hear little.");

    
set_items(([ 
	({ "mosaic", "mosaics" }) : "There is more than one mosaic.  They have been made from small tiles of various colors and, while stylistically dated, are simply breathtaking to behold.  As you scan the walls, there seems to be a chronology to them.  Best look at mosaic 1, 2, 3, or 4.",
	"mosaic 2" : "%^BOLD%^%^WHITE%^This image shows the nobleman grown.  His lands are cloaked in a long winter and his people are being led in the direction of theSakrune sea.  An aspect of Auril can is resting her hands on his shoulders and he has an impressive sword resting on his upraised palms.",
	"ice" : "%^BOLD%^%^CYAN%^The larger portion of the tomb's halls have been blocked by glacial ice.  It likely fills the entire hallways, presenting a formidable obstacle.%^RESET%^",
	"mosaic 1" : "%^BOLD%^%^MAGENTA%^This mosaic depicts a young nobleman sitting on a throne.  His holdings and keep lie behind him.  In the foreground, a battle rages on.  His people seem to be victorious of the other army while Tsarvens are seen suffering on the ground and impaled on stakes. ",
	"mosaic 4" : "%^BLUE%^This mosaic depicts nobleman being lain to rest.  Supporting him along on his journey to Auril's arms is an army of northern tribes and undead warriors.  Many drow lie dispatched in the foreground.",
	"script" : "%^ORANGE%^The inscription is written in a different alphabet which looks somehow familiar but not understandable.",
	"mosaic 3" : "This mosaic depicts the nobleman, his age and visage masked in an aura of ice and blood.  He is wielding his sword in battle against dark elves.  MountKrakus is visible in the background.",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/tiamat/tomb2",
		"south" : "/d/av_rooms/tiamat/tombroad2",
	]));

    set_door("door","/d/av_rooms/tiamat/tombroad2","south");
    set_open("door",0);
    set_string("door","knock","knocks");
    set_string("door","open","You open the door.");
    set_string("door","close","You close the door.");
    set_door_description("door","%^ORANGE%^A feeble wooden door hangs off of primitive hinges carved into the archway.%^RESET%^");
}