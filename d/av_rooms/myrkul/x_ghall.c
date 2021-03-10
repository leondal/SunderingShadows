// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("x_ghall");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("fresh blaze");
    set_climate("temperate");

    set_short("%^BOLD%^%^MAGENTA%^G%^RESET%^%^MAGENTA%^r%^BOLD%^and H%^RESET%^%^MAGENTA%^a%^BOLD%^ll%^BLACK%^ of House %^YELLOW%^X%^RESET%^%^ORANGE%^o%^YELLOW%^r%^RESET%^%^ORANGE%^l%^YELLOW%^o%^RESET%^%^ORANGE%^r%^YELLOW%^r%^RESET%^%^ORANGE%^i%^YELLOW%^n%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^A massive dining table runs the length of this massive hall. The ceiling arches far above the table with %^WHITE%^chandeliers%^BLACK%^ of %^MAGENTA%^g%^RESET%^%^MAGENTA%^l%^BOLD%^o%^R"
	"ESET%^%^MAGENTA%^w%^BOLD%^i%^RESET%^%^MAGENTA%^n%^BOLD%^g%^BLUE%^ black%^YELLOW%^ candles%^BLACK%^ casting an eerie black glow. %^RESET%^%^CYAN%^F%^BOLD%^r%^RESET%^%^CYAN%^e%^BOLD%^s%^RESET%^%^CYAN%^c"
	"%^BOLD%^o%^RESET%^%^CYAN%^e%^BOLD%^s%^BLACK%^ lining the walls depicting the many great battles of the %^YELLOW%^H%^RESET%^%^ORANGE%^o%^YELLOW%^u%^RESET%^%^ORANGE%^s%^YELLOW%^e%^BOLD%^%^BLACK%^. Visit"
	"ors may join the the table or freely wander the hallway to admire the many great works of art. This must be the place where the %^MAGENTA%^Matron%^BLACK%^ holds court.%^RESET%^"
	);

    set_smell("default","
The aroma of fine wine floats in the air.");
    set_listen("default","The murmur of voices echos throughout the grand hall.");

    
set_items(([ 
	"frescoes" : "The frescoes show many battles over millenia on behalf of Lloth.",
	"chandeliers" : "The chandeliers are elegant reminders of a grand past.",
	"candles" : "The candles do not burn, they are magical artifacts to add to the ambience of this place.",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/myrkul/x_nhall",
	]));

}