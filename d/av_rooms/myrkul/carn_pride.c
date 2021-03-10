// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("carn_pride");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("village");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^BOLD%^%^CYAN%^H%^WHITE%^all of M%^CYAN%^i%^WHITE%^rr%^CYAN%^o%^WHITE%^rs%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This is a funny room full of bright shining %^CYAN%^mirrors%^WHITE%^. The %^YELLOW%^reflections%^WHITE%^ are distorted sometimes looking %^BLUE%^fat%^WHITE%^ and othertimes %^GREEN%^s"
	"kinny%^WHITE%^. Many %^MAGENTA%^fashionable%^WHITE%^ men and women admire themselves in the mirrors. Some %^RESET%^%^CYAN%^panes%^BOLD%^%^WHITE%^ of mirrors seem magical, which enhance the reflection "
	"making the %^BLACK%^elderly%^WHITE%^ seem %^YELLOW%^youthful%^WHITE%^. Others look to make the %^RESET%^%^ORANGE%^poor%^BOLD%^%^WHITE%^ seem %^GREEN%^wealthy%^BOLD%^%^WHITE%^. In the center of the roo"
	"m, an elderly man in white robes chats with visitors and occasionally polishes mirrors.%^RESET%^"
	);

    set_smell("default","
It smells of polish.");
    set_listen("default","Laughter and quibbling echos throughout from visitors admiring each other's reflections.");

    
set_items(([ 
	"reflection" : "Your reflection at times seems fat and thin. It dances along from poor to rich, young to old, as your fancy changes.",
	"panes" : "Some seem quite magical, others merely bent glass.",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/myrkul/carn_main",
	]));

}