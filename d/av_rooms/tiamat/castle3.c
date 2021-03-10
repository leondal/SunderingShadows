// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("castle3");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("back alley");
    set_climate("temperate");

    set_short("Castle Great Hall");

    set_long("%^RESET%^This large room probably once served as the main audience chamber for the castle stewards or grand feasting hall.  The ceiling is quite high here, and some of the long %^ORANGE%^hangings%^RES"
	"ET%^ seem to have escaped decay near the top.  %^BOLD%^%^BLACK%^Oily grime%^RESET%^ and dust have settled over the husk of a once grand banquet %^ORANGE%^table%^RESET%^, now cleanly split in two and r"
	"otting.  Beyond the table, a series of wide steps caved into stone lead up to a platform.  One could guess that regal thrones once proudly observed festivities from this vantage, but they are no more."
	"  Instead, the platform has been cleared of finery and in its place, a gloomy %^RED%^altar%^RESET%^ has been erected."
	);

    set_smell("default","
%^GREEN%^It smells like age and mildew.%^RESET%^");
    set_listen("default","%^ORANGE%^You hear distant dripping.%^RESET%^");

    
set_items(([ 
	"table" : "%^ORANGE%^A long banquet table once stood here.  It was clearly an elegant affair and made from local hardwood.  It appears that the banquet table was cleaved in two with purpose, rather than the result of natural decay.  Now that it sits buckled in the grime, rot has taken hold of it.%^RESET%^",
	({ "webs", "cobwebs" }) : "Cobwebs riddle the castle ruins, everywhere they can.  The webbing is just a little too thick, suggesting very big spiders.",
	({ "hanging", "hangings" }) : "%^ORANGE%^The walls look like they once proudly displayed a variety of hangings, tapestries and banners.  They have long since decayed so as to be unrecognizable.%^RESET%^",
	({ "sconce", "sconces" }) : "Rusting sconces probably once held torches.  Very little light penetrates here now.",
	"altar" : "%^RESET%^%^RED%^The altar is both crude and ominous.  It is composed mainly of an irregular, flat-topped stone stained with blood.  A tattered satin covering lays over the top and two mismatched black candles wait for relighting.%^RESET%^",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/tiamat/castle2",
	]));

    set_door("door","/d/av_rooms/tiamat/castle2","south","key castle","castle lock");
    add_lock("door","key castle","castle lock","A mechanical lock built into the dor.");
    set_locked("door",1,"castle lock");
    lock_difficulty("door",-85,"castle lock");
    set_open("door",0);
    set_string("door","knock","knocks on the");
    set_string("door","open","The door opens with a loud creak.");
    set_string("door","close","The door closes with a loud creak.");
    set_door_description("door","A large, wooden double door reinforced with iron.");
}