// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("barb_hall");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("paved road");
    set_climate("arctic");

    set_short("%^YELLOW%^F%^GREEN%^e%^YELLOW%^st%^GREEN%^i%^YELLOW%^ve %^RESET%^%^ORANGE%^H%^CYAN%^a%^ORANGE%^ll %^CYAN%^of%^ORANGE%^ M%^CYAN%^i%^ORANGE%^ghty T%^CYAN%^i%^ORANGE%^mb%^CYAN%^e%^ORANGE%^r%^RESET%^");

    set_long("%^BOLD%^%^GREEN%^Mighty %^RESET%^%^ORANGE%^timbers%^BOLD%^%^GREEN%^ from the %^WHITE%^Charu Mountains%^GREEN%^ must have been felled to build this Hall. The heavy beams form a high ceiling, and the %^"
	"RESET%^%^ORANGE%^logs%^BOLD%^%^GREEN%^ that make the walls are as big as %^RED%^ogres%^GREEN%^ around and as tall as %^YELLOW%^firbolgs%^GREEN%^. A mighty stone hearth stands at one side of the hall, "
	"and mighty feasting tables with many chairs line the center of the room. At the head of the table is a huge %^BOLD%^%^BLACK%^chair%^GREEN%^ of %^WHITE%^bone%^GREEN%^, lined with many %^RESET%^%^ORANGE"
	"%^furs%^BOLD%^%^GREEN%^. The room is well lighted by many %^YELLOW%^t%^RED%^o%^YELLOW%^rch%^RED%^e%^YELLOW%^s%^GREEN%^ and candles, and the air is %^BLACK%^smoky%^GREEN%^ from the constant cooking and"
	" firelight. The decor is %^MAGENTA%^merry%^GREEN%^ with many ribbons tied to chairs and many bouquets of %^BLUE%^f%^WHITE%^l%^MAGENTA%^ow%^BLUE%^e%^WHITE%^r%^MAGENTA%^s%^GREEN%^ arranged on the tables"
	".%^RESET%^"
	);

    set_smell("default","
The air is heavy with smoke, cooking food, and sturdy ale.");
    set_listen("default","The room is noisy with boisterous laughing and clanking of pots and pans.");

    
set_items(([ 
	"chair" : "The bone chair must have come from phenomenally large creature.",
	"logs" : "These logs are old, and the hall itself must be at least a century old. ",
	"flowers" : "The flowers are wildflowers native to these mountains. Oddly enough some of them are probably out of season. ",
	"timbers" : "These appear to be some kinds of pine.",
	"furs" : "The furs appear to be bearskin.",
	"ribbons" : "The ribbons are of many colors and some woven with great care.",
	]));

    set_exits(([ 
		"out" : "/d/antioch/wild/mount/pass_4",
	]));

}