// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("carn_lust");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("village");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^BOLD%^%^MAGENTA%^Beautiful %^RESET%^%^MAGENTA%^Velvet%^BOLD%^ Tent%^RESET%^");

    set_long("%^BOLD%^%^MAGENTA%^This is a fabulous tent of %^RED%^rose%^MAGENTA%^ hued %^RED%^silks%^MAGENTA%^, %^RESET%^%^MAGENTA%^scented candles%^BOLD%^, %^CYAN%^chilled wine%^MAGENTA%^, and %^RESET%^%^ORANGE%^"
	"delicate chocolates%^BOLD%^%^MAGENTA%^. Pillows line the walls with low tables, where guests are entertained. A number of rustling curtains lead into further more %^BLUE%^private%^MAGENTA%^ rooms. An "
	"%^YELLOW%^elderly lady%^MAGENTA%^ greets visitors and occasionally leads them to one of the private rooms.%^RESET%^"
	);

    set_smell("default","
You smell a faint fragrance of expensive, floral perfume.");
    set_listen("default","You hear the rustle of silks.");


    set_exits(([ 
		"south" : "/d/av_rooms/myrkul/carn_main_w",
		"curtains" : "/d/av_rooms/myrkul/carn_lust_room",
	]));

    set_door("curtains","/d/av_rooms/myrkul/carn_lust_room","curtains","magic key","magic lock");
    add_lock("curtains","magic key","magic lock","This appears to be an enchanted sigil.");
    set_locked("curtains",1,"magic lock");
    set_open("curtains",0);
    set_string("curtains","knock","rings a bell near the");
    set_string("curtains","open","The curtains part with a rustle of silks");
    set_string("curtains","close","The curtains close with a rustle of silks");
    set_door_description("curtains","These are shimmering silk curtains that seem magically enchanted for privacy.");
}