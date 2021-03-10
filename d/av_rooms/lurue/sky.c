// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sky");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("glacier");
    set_travel("ledge");
    set_climate("arctic");

    set_short("%^BOLD%^%^WHITE%^High in the Air%^RESET%^");

    set_long("%^BOLD%^%^CYAN%^Below, the whole of the Shadowgate Realm extends.  From Moonstone to Azha, from Argentrock to Offestry, you can see the world you know looming below you.  All around, %^WHITE%^clouds%^"
	"CYAN%^ pass, born by %^BLUE%^freezing%^CYAN%^ air currents.  The air here is %^RESET%^%^CYAN%^thin%^BOLD%^ and difficult to breathe and you're certain you would %^WHITE%^freeze%^CYAN%^ but for the war"
	"mth of the large %^RED%^fire breathing dragon%^CYAN%^ above you.  Not even in your wildest of dreams could you fly this high born on your own magic.  Truly it is a wonderous glory to behold.%^RESET%^"
	);

    set_smell("default","
The air is too thin to smell anything");
    set_listen("default","Wind howls by your ears.");

    
set_items(([ 
	({ "shadowgate", "realm", "land", "moonstone", "azha", "argentrock", "offestry", "tabor", "torm", "shadow", "world", "tonovi", "tharis", "sea", "sakkrune", "sakkrune sea", "ocean", "aramanth", "attaya", "seneca", "dallyh", "deku", "verbobone", "dino island", "eldebaro", "laerad", "ovadexel", "pirates", "pirate cove", "cove", "islands", "island", "tonerra", "graez", "sangri", "laerad", "asgard" }) : "%^BOLD%^%^WHITE%^The whole world stretches below, everything you have ever set foot upon you can see as the world passes below you.%^RESET%^",
	({ "dragon", "klauth" }) : "%^RED%^Clutched in the mighty claw of the dragon, all you can see is its arm, claws and a bit of its under belly.  Craning your neck, you can make out the wing tips now and again as the beast flaps its wings to guide it through the air.  If your arms were free, you might be able to stab him, of course then you'd fall and die, but at least you wouldn't be held by the dragon...%^RESET%^",
	({ "air currents", "air" }) : "%^BOLD%^%^CYAN%^You can't see those but you can feel them biting against you and you're thankful that the dragon's body is so warm, otherwise you would freeze to death in a heartbeat.%^RESET%^",
	({ "clouds", "cloud" }) : "%^BOLD%^%^WHITE%^Thick ribbons and small puffs dot the air, born along by the swiftly moving air currents.  Many look thick with water, as though ready to spill rain or snow upon the lands below.%^RESET%^",
	]));

    set_exits(([ 
		"wizonly" : "/d/darkwood/yntala/rooms/sec5",
	]));



    set_invis_exits(({ "wizonly" }));

}