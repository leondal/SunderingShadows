// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("teel1");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^CYAN%^Teel Street%^RESET%^");

    set_long("%^MAGENTA%^You stand just inside the gates for the city of %^BOLD%^%^WHITE%^Creen%^RESET%^%^MAGENTA%^.  In front of you lies the %^RED%^c%^WHITE%^o%^RED%^bbl%^WHITE%^e%^RED%^st%^WHITE%^o%^RED%^n%^WHIT"
	"E%^e%^MAGENTA%^ path that makes up the streets of the city.  Travellers venture in and out of the city at leisure bringing in goods for sell and barter.  The path narrows ahead as buildings start to s"
	"queeze in from both sides.  %^CYAN%^Teel Street %^MAGENTA%^continues to run north from here while the %^ORANGE%^Sou%^BOLD%^%^BLACK%^th G%^RESET%^%^ORANGE%^ate %^MAGENTA%^remains open to the south.%^RE"
	"SET%^"
	);

    set_smell("default","
%^CYAN%^The faint smell of food meets your nose.%^RESET%^");
    set_listen("default","%^ORANGE%^%^BOLD%^Sounds of laughter come from the north.%^RESET%^");


    set_exits(([ 
		"north" : "d/av_rooms/mystra/teel2",
		"south" : "d/av_rooms/mystra/southgate",
	]));

}