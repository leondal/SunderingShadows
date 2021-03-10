// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("carn_lust_room");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("village");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^BOLD%^%^MAGENTA%^A %^RESET%^%^MAGENTA%^Private%^BOLD%^ Chamber%^RESET%^");

    set_long("%^BOLD%^%^MAGENTA%^This is a place for %^RED%^affairs%^MAGENTA%^ of the heart. A %^WHITE%^circular%^MAGENTA%^ %^CYAN%^h%^WHITE%^e%^CYAN%^avenly%^MAGENTA%^ bed is bracketed by %^YELLOW%^luxurious%^MAGE"
	"NTA%^ %^RESET%^%^ORANGE%^oak %^BOLD%^%^MAGENTA%^nightstands. Candles %^BLUE%^s%^RESET%^%^BLUE%^i%^BOLD%^zz%^RESET%^%^BLUE%^l%^BLUE%^ue%^MAGENTA%^ and %^YELLOW%^spark%^MAGENTA%^ on each stand, and a %^"
	"RESET%^%^MAGENTA%^bottle of fine wine%^BOLD%^%^MAGENTA%^ sits on a sideboard with a pair %^WHITE%^crystal glasses%^MAGENTA%^ near the entrance. Mellow light comes from artistic patterns of glowing %^C"
	"YAN%^g%^WHITE%^e%^RED%^m%^BLUE%^s%^WHITE%^t%^CYAN%^o%^RED%^n%^BLUE%^e%^CYAN%^s%^MAGENTA%^ arrayed on the ceiling of the chamber. A feeling of %^RESET%^%^CYAN%^relaxation%^BOLD%^%^MAGENTA%^ and %^GREEN"
	"%^peacefulness%^MAGENTA%^ sweeps over you like a cascading waterfall in a gentle glen.%^RESET%^"
	);

    set_smell("default","
You smell the gentle fragrance of floral perfume.");
    set_listen("default","It is peacefully quiet here.");

    
set_items(([ 
	"nightstands" : "These are made of a nice oak. Very tasteful.",
	"bed" : "This looks very clean, the bed is made, and it has nothing but finest weaves of silken sheets.",
	"glasses" : "Crystal wine glasses. Nice touch.",
	"gemstones" : "Glowing gemstones don't come cheap, and neither do artists. They give off a pleasant glow without glaring or being too dark.",
	"wine" : "Doubtless this bottle is quite expensive feywine of good vintage.",
	]));

    set_exits(([ 
		"curtains" : "/d/av_rooms/myrkul/carn_lust",
	]));

    set_door("curtains","/d/av_rooms/myrkul/carn_lust","curtains","magic key","magic lock");
    add_lock("curtains","magic key","magic lock","This appears to be an enchanted sigil.");
    set_locked("curtains",1,"magic lock");
    set_open("curtains",0);
    set_string("curtains","knock","rings a bell near the");
    set_string("curtains","open","The curtains part with a rustle of silks");
    set_string("curtains","close","The curtains close with a rustle of silks");
    set_door_description("curtains","These are shimmering silk curtains that seem magically enchanted for privacy.");
}