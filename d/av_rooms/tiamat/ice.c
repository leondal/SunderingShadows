// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("ice");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("ice");
    set_travel("rubble");
    set_climate("mountain");

    set_short("%^BOLD%^%^WHITE%^An icy prison%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^The cave is somewhat dark here, the ice is not as thick and the stone of the mountain is more apparent.  Huge %^BLACK%^stalagmites %^WHITE%^and %^BLACK%^stalactites%^WHITE%^ burst fro"
	"m the rock, forming a kind of %^CYAN%^icy %^WHITE%^prison.  It looks as though there has been recent traffic here, evidenced by some %^YELLOW%^treasure%^WHITE%^.  Above, a huge %^BLUE%^hole%^WHITE%^ l"
	"eads up through the mountain and into the sky!%^RESET%^"
	);

    set_smell("default","
%^ORANGE%^The scent of water and ice mix in the air.");
    set_listen("default","%^GREEN%^Echoing splashes of water can be heard throughout the cave.");

    
set_items(([ 
	"hole" : "%^BLUE%^A large hole cuts into the mountain.  It is at least 100 feet above you and quite useless to a humanoid.  Conveniently, its about big enough for a large dragon to fit through.",
	"treasue" : "Uhm, its on the ground unless you <offer>ed it.",
	]));

    set_exits(([ 
		"north" : "/d/dagger/arctic/rooms/cave/cave53",
	]));

}