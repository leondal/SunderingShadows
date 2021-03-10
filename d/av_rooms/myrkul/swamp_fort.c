// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("swamp_fort");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^YELLOW%^Inside a %^BLACK%^S%^RESET%^w%^BOLD%^%^BLACK%^mp%^YELLOW%^ Fort%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^You find yourself in a %^RED%^crude%^ORANGE%^ camp. Low slung wooden %^YELLOW%^shacks%^RESET%^%^ORANGE%^ dot the encampment. In the center of the %^WHITE%^fort%^ORANGE%^, is a gathe"
	"ring space with an %^YELLOW%^Altar%^RESET%^%^ORANGE%^ dedicated to %^BOLD%^%^BLACK%^T%^WHITE%^a%^YELLOW%^l%^BLUE%^o%^BLACK%^s%^RESET%^%^ORANGE%^. There does not seem to be much in the way of luxury he"
	"re. %^RESET%^"
	);

    set_smell("default","
You can smell the sickly sweet scent of burning %^YELLOW%^swamp%^RESET%^ meat.");
    set_listen("default","The swamp is alive with mosquitos and other vermin that never quiets.");

    
set_items(([ 
	"fort" : "The fort has outer walls and a gate for defenses. Its not much but does keep the unintelligent mosters out.",
	"shacks" : "These are small shacks with only one room. Some don't even have windows, with nothing more than a hide for a door.",
	"altar" : "This altar is made out of wood, and apparently had deep %^BOLD%^%^RED%^bloodstains%^RESET%^ from sacrifices. The wood has been etched from the many times creatures (people?) have been hacked to death on that altar.",
	"walls" : "The walls are sturdy enough, and you could tear them down but you don't have a day or five.",
	"camp" : "This is a dirty camp for the people that live in the undead infested swamp. They are all cultists and incredibly inbred.",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/myrkul/swamp_entrance",
	]));

    set_door("gate","/d/av_rooms/myrkul/swamp_entrance","north","gate key","lock");
    add_lock("gate","gate key","lock","This is a standard lock.");
    set_locked("gate",1,"lock");
    lock_difficulty("gate",-20,"lock");
    set_open("gate",0);
    set_string("gate","knock","pounds on the");
    set_string("gate","open","The gate swings open silently.");
    set_string("gate","close","The gate swings closed silently.");
    set_door_description("gate","This is a sturdy gate made of wooden logs. It has iron hinges and is very heavy.");
}