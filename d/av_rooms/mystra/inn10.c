// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("inn10");
    set_property("indoors",1);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Castwater Bedroom%^RESET%^");

    set_long("%^RED%^This is a very exquisite bedroom for town visitors to get some needed rest in.  A %^BOLD%^%^WHITE%^king-sized bed %^RESET%^%^RED%^dominates the western wall of the room and reaches deep into th"
	"e room itself.  On top of the bed rest a very cozy comforter and eight of the largest, softest %^BOLD%^%^WHITE%^pillows %^RESET%^%^RED%^many will ever see.  They take up half the bed as they weave ove"
	"r top of one another in an organized manner.  The comforter flows down the sides of the bed and almost kisses the floor with it's %^BOLD%^%^YELLOW%^fr%^WHITE%^i%^YELLOW%^ll%^WHITE%^y %^RESET%^%^RED%^e"
	"dges.  Beside the bed on the opposite side of the room, an %^ORANGE%^ornate desk %^RED%^sits waiting for use.  Stationary provided by the inn rests on top of the desk, again neatly arranged and organi"
	"zed.  A %^YELLOW%^%^BOLD%^golden lamp %^RESET%^%^RED%^on the left side of the desk provides a bit of light for one to scribe down their notes with.  A %^BOLD%^%^BLUE%^blue-dyed, wool rug %^RESET%^%^RE"
	"D%^on the floor covers a small section of the freshly waxed %^ORANGE%^wooden planks %^RED%^and is designed with the name %^BOLD%^%^WHITE%^'Castwater' %^RESET%^%^RED%^embroidered into it in large, whit"
	"e lettering.  On the east wall an %^ORANGE%^oaken armoire %^RED%^stands nearby for storage.%^RESET%^"
	);

    set_smell("default","
%^CYAN%^The smell of fresh linens hangs in the air%^RESET%^");
    set_listen("default","%^BOLD%^%^YELLOW%^It is very quiet in this room%^RESET%^");


    set_exits(([ 
		"north" : "/d/av_rooms/mystra/inn7",
	]));

}