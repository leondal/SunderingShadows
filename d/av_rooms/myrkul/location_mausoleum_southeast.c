// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("location_mausoleum_southeast");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("foot path");
    set_climate("temperate");

    set_short("Stone Mausoleum");

    set_long("This mausoleum is stacked to the rafters with loot. Gems cover a fancy sarcophagus. A devotional chest is open on the floor, full of gold and silver coins. A sword stands upright in front of the sarco"
	"phagus, tip embedded in the stone. The place still appears regal, despite it being a place of burial. "
	);

    set_smell("default","
It smells like old stone.");
    set_listen("default","You smell nothing here.");

    set_search("gems","They could be pried out if you wanted to do it.");
    set_search("sword","It is stuck pretty well in the stone, but could be removed. Oddly the blade still looks kinda sharp.");
    set_search("chest","It is loaded with gold and silver coins of an ancient denomination.");
    set_search("grave","%^RESET%^%^ORANGE%^The dirt feels loose in your hands, and many %^BLUE%^personal effects%^RESET%^%^ORANGE%^ scatter the ground. Who knows what you might find? You find yourself weighing the voices of your %^BOLD%^%^RED%^inner demons%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^better angels%^RESET%^%^ORANGE%^ of your nature.%^RESET%^ ");
    set_search("graves","%^RESET%^%^ORANGE%^The dirt feels loose in your hands, and many %^BLUE%^personal effects%^RESET%^%^ORANGE%^ scatter the ground. Who knows what you might find? You find yourself weighing the voices of your %^BOLD%^%^RED%^inner demons%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^better angels%^RESET%^%^ORANGE%^ of your nature.%^RESET%^ ");
    
set_items(([ 
	"gems" : "They are diamonds and other precious gems. They could be pried out if you wanted.",
	({ "restless dead", "dead" }) : "%^BOLD%^%^GREEN%^The %^BLACK%^dead%^GREEN%^ walk. Villagers, soldiers, farmers, young, old. The %^BLACK%^h%^YELLOW%^orror%^GREEN%^ of this place is %^RESET%^%^MAGENTA%^unspeakable.%^RESET%^",
	({ "grave", "graves" }) : "%^BOLD%^%^BLACK%^Hmmm. This now empty grave looks to be, oh, %^MAGENTA%^about your size!%^RESET%^",
	"sword" : "It is a longsword, and it looks like a noble's blade of excellent quality.",
	"chest" : "The chest is full of coins.",
	"evil" : "%^RED%^The presence of evil in this place is undeniable.%^RESET%^",
	"sarcophagus" : "Its just a stone box, but it has many gems on it and it is titled, Duke Sarcosta.",
	]));

    set_exits(([ 
		"northwest" : "/d/av_rooms/myrkul/boneyard_southeast_mausoleum",
	]));

    set_door("marble door","/d/av_rooms/myrkul/boneyard_southeast_mausoleum","northwest","skeleton key","brass lock");
    add_lock("marble door","skeleton key","brass lock","brass lock");
    set_locked("marble door",1,"brass lock");
    lock_difficulty("marble door",-5,"brass lock");
    set_open("marble door",0);
    set_string("marble door","knock","pounds on the");
    set_string("marble door","open","With a hard shove, the marble door rumbles open.");
    set_string("marble door","close","The door closes with a crash.");
    set_door_description("marble door","The door is part of the mausoleum and is made out of the same kind of marble. It is enormously heavy and has many scratches on the outside.");
}