// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("paint_r2");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^MAGENTA%^Trapped within a painting %^WHITE%^- %^BOLD%^Birthday Party%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^Pink this and purple that. Frilly this and cuddly that. In a perfect world this would be a party fit for a princess. %^WHITE%^A large %^YELLOW%^cake %^WHITE%^sits at the head of a tab"
	"le that is absolutely full of gift wrapped %^GREEN%^presents. %^WHITE%^Seemingly out of place, two filthy %^RED%^boy children %^WHITE%^are playing swords %^WHITE%^with %^BLUE%^sticks %^WHITE%^close en"
	"ough to the table to knock off the cake. The room almost feels tainted by some unknown force.%^RESET%^"
	);

    set_smell("default","
%^BOLD%^%^MAGENTA%^The sweet scent of cake and other candied treats drifts by%^RESET%^ ");
    set_listen("default","%^MAGENTA%^A crowd from somewhere nearby sings Happy Birthday over and over%^RESET%^");

    set_search("boy","A note falls out of his pocket. It says turn %^YELLOW%^east %^RESET%^and walk a few paces. Don't stare at anything too long. It might come alive.");
    
set_items(([ 
	({ "boys", "boy", "boy children", "children" }) : "%^ORANGE%^They look familiar for some reason.",
	"sticks" : "%^MAGENTA%^One of the sticks looks like the wand that got you into this mess. Maybe if you searched the boy that holds it there would be some clue to getting out of here.",
	"presents" : "%^GREEN%^There must be at least a hundred presents or more just on the table alone.",
	"cake" : "%^BOLD%^%^MAGENTA%^The huge pink cake could easily feed a village. Whoever it is for must be really special to someone. %^YELLOW%^Candles %^MAGENTA%^burn away on top of the frosted wonder.",
	"candles" : "%^YELLOW%^They are hot! Don't forget to make a wish.",
	]));

    set_exits(([ 
		"east" : "/d/av_rooms/hlal/paint_r5",
		"e" : "/d/av_rooms/hlal/paint_r5",
	]));



    set_invis_exits(({ "e", "east" }));

}