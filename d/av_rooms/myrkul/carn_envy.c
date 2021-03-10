// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("carn_envy");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("village");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^RESET%^%^GREEN%^The %^YELLOW%^W%^RED%^i%^WHITE%^n%^GREEN%^n%^BLUE%^e%^MAGENTA%^r%^CYAN%^s%^RESET%^%^GREEN%^ Tent%^RESET%^");

    set_long("%^RESET%^%^GREEN%^The tent is %^CYAN%^exceedingly%^GREEN%^ opulent, made of the finest %^RED%^velvets%^GREEN%^ and %^CYAN%^silks%^GREEN%^. The light is %^WHITE%^soft%^GREEN%^, provided by beautiful ma"
	"gical %^WHITE%^baubles%^GREEN%^ floating near the canopied roof.  Beautiful white %^BOLD%^%^WHITE%^marble thrones%^RESET%^%^GREEN%^ have been erected for the %^YELLOW%^King%^RESET%^%^GREEN%^ and %^BOL"
	"D%^%^MAGENTA%^Queen%^RESET%^%^GREEN%^ of the Carnival. %^YELLOW%^Coins%^RESET%^%^GREEN%^ and %^BOLD%^%^RED%^G%^WHITE%^e%^GREEN%^m%^BLUE%^s%^RESET%^%^GREEN%^ of all shapes and sizes are piled in a %^YE"
	"LLOW%^horde%^RESET%^%^GREEN%^ next to the thrones on side with a stack of swords and armor, on the other. A small %^BOLD%^%^MAGENTA%^harem%^RESET%^%^GREEN%^ of scantily clad beautiful women (and an oc"
	"casional beef cake or two for the queen) are on hand to provide refreshments. A %^ORANGE%^keg of ale%^GREEN%^ and captured %^BOLD%^%^BLACK%^gladiator belts hang%^RESET%^%^GREEN%^ on the walls. A pair "
	"of magical %^BOLD%^%^WHITE%^statues%^RESET%^%^GREEN%^ sing the praises of the %^BOLD%^%^GREEN%^most-winningest man and woman%^RESET%^%^GREEN%^ of the carnival. %^RESET%^"
	);

    set_smell("default","
You smell a faint fragrance of expensive, floral perfume.");
    set_listen("default","You hear the rustle of silks.");


    set_exits(([ 
		"north" : "/d/av_rooms/myrkul/carn_main",
	]));

}