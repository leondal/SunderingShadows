// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("carn_main");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("village");
    set_travel("rutted track");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Path to a %^YELLOW%^C%^RED%^a%^YELLOW%^r%^BLUE%^n%^CYAN%^i%^RED%^v%^YELLOW%^al%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^You stand at the eastern edge of the great %^YELLOW%^C%^RED%^a%^YELLOW%^r%^BLUE%^n%^CYAN%^i%^RED%^v%^YELLOW%^al%^WHITE%^. Crowds of visitor stampede through the grounds, hooting and h"
	"ollaring. For the most part the visitors are human, with the occasional %^GREEN%^elf%^WHITE%^, %^RESET%^%^ORANGE%^dwarf%^BOLD%^%^WHITE%^, or %^RESET%^%^RED%^beast%^BOLD%^%^WHITE%^. Heavily armed %^BLA"
	"CK%^mercenaries%^WHITE%^ keep the %^GREEN%^peace%^WHITE%^.  %^MAGENTA%^Brightly colored tents%^WHITE%^ rise up all around the grounds. The %^RED%^big-top tent%^WHITE%^ is here where the main attractio"
	"ns are shown. To the north, a hall of mirrors has been set up and the king and queen of the carnival is celebrated to the south.%^RESET%^"
	);

    set_smell("default","
It smells like fried food, stale beer, and garbage.");
    set_listen("default","Crowds are roaring in the distance at the Carnival.");


    set_exits(([ 
		"west" : "/d/av_rooms/myrkul/carn_main_w",
		"south" : "/d/av_rooms/myrkul/carn_envy",
		"north" : "/d/av_rooms/myrkul/carn_pride",
		"east" : "/d/av_rooms/myrkul/carn_main_e",
		"bigtop" : "/d/av_rooms/myrkul/carn_bigtop",
	]));

}