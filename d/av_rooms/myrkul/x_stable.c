// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("x_stable");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLUE%^S%^RESET%^%^BLUE%^p%^BOLD%^i%^RESET%^%^BLUE%^d%^BOLD%^e%^RESET%^%^BLUE%^r %^BOLD%^%^BLACK%^Stable%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This cave is used to house the many %^BOLD%^%^BLUE%^s%^RESET%^%^BLUE%^p%^BOLD%^i%^RESET%^%^BLUE%^d%^BOLD%^e%^RESET%^%^BLUE%^r%^BOLD%^%^BLACK%^ that the %^RESET%^%^MAGENTA%^drow%^BOLD%"
	"^%^BLACK%^ use as mounts. Siderooms split off from the main cave to house individual spiders. Saddles and riding tack are kept in racks next to each entrance. The room seems covered in webs with %^WHI"
	"TE%^spider silk%^BLACK%^ as thick as ropes. There are no signs of %^RED%^blood%^BLACK%^ as the spiders seem to be tidy eaters, but there can be no doubt as to the meaning of the humanoid sized %^WHITE"
	"%^cocoons%^BLACK%^ that hang from the stable ceiling.%^RESET%^"
	);

    set_smell("default","
The aroma of manure is the hallmark of any stable, even one found here in the Underdark.");
    set_listen("default","The shuffling of spiders in the stalls echos throughout the stable.");

    set_search("webs","The webs hold nothing special.");
    set_search("silk","The silk holds nothing special.");
    set_search("tack","You find saddles and all manner of riding seats for the spiders.");
    set_search("cocoons","The cocoons hold corpses of humans and elves, well preserved.");
    
set_items(([ 
	"webs" : "The webs have been made presumably by the oversized spiders used as mounts.",
	"blood" : "There is no blood on the ground despite the carnivorous nature of the spiders.",
	"silk" : "The webs have been made presumably by the oversized spiders used as mounts.",
	"cocoons" : "The cocoons have been made presumably by the oversized spiders used as mounts.",
	]));

    set_exits(([ 
		"northwest" : "/d/av_rooms/myrkul/x_ehall",
	]));

}