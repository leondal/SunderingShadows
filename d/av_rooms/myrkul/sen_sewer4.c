// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sen_sewer4");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^%^BOLD%^%^BLUE%^S%^CYAN%^e%^BLUE%^neca%^GREEN%^ S%^RESET%^%^ORANGE%^e%^BOLD%^%^GREEN%^wers%^RESET%^");

    set_long("You stand in an %^RESET%^%^ORANGE%^underground sewer%^RESET%^. The sewer is essentially an %^BOLD%^%^BLUE%^un%^CYAN%^d%^BLUE%^erground r%^CYAN%^i%^BLUE%^ver%^RESET%^, with %^ORANGE%^cobblestones walkw"
	"ays%^RESET%^ on either side of the %^BOLD%^%^GREEN%^canal%^RESET%^. The canal itself is about four feet deep with a flat stone bottom, which is quite walkable for most adult humans, but more than %^BO"
	"LD%^%^MAGENTA%^deep enough to drown a halfling or gnome%^RESET%^. The walls and ceiling are solid stone, and a %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^i%^RESET%^t%^BOLD%^%^BLACK%^t%^RESET%^y%^YEL"
	"LOW%^ light%^RESET%^ from above shines in from street drains that open up in the ceiling above the river. Between the street level openings, intermittently space magical orbs provide enough light to g"
	"et around. The sewer extends off to the south. To the west is what looks like a dead end. You can't hear much noise anymore from the street and you must be under some buildings. "
	);

    set_smell("default","
It smells pretty nasty. At least the river moves fast enough to keep the stench from killing anyone.");
    set_listen("default","%^RESET%^You can hear the scurrying of %^BOLD%^%^RED%^rats%^RESET%^ scurrying hither and thither.");

    set_search("bottom","%^BOLD%^%^CYAN%^You screw up your courage and dip your %^GREEN%^hand%^CYAN%^ into the %^BLACK%^filth.%^CYAN%^ You come back with the knowledge that you are %^RED%^really brave!%^CYAN%^ But no hidden treasures lie in all that nastiness!%^RESET%^");
    set_search("sewer","%^BOLD%^%^CYAN%^You screw up your courage and dip your %^GREEN%^hand%^CYAN%^ into the %^BLACK%^filth.%^CYAN%^ You come back with the knowledge that you are %^RED%^really brave!%^CYAN%^ But no hidden treasures lie in all that nastiness!%^RESET%^");
    set_search("ladder","The manhole looks like its seem some use.");
    set_search("river","%^BOLD%^%^CYAN%^You screw up your courage and dip your %^GREEN%^hand%^CYAN%^ into the %^BLACK%^filth.%^CYAN%^ You come back with the knowledge that you are %^RED%^really brave!%^CYAN%^ But no hidden treasures lie in all that nastiness!%^RESET%^");
    set_search("walkways","The walkway is too clean. Clearly others have used this tunnel before you, and recently too.");
    set_search("canal","%^BOLD%^%^CYAN%^You screw up your courage and dip your %^GREEN%^hand%^CYAN%^ into the %^BLACK%^filth.%^CYAN%^ You come back with the knowledge that you are %^RED%^really brave!%^CYAN%^ But no hidden treasures lie in all that nastiness!%^RESET%^");
    
set_items(([ 
	"ceiling" : "The ceiling is arched, with drains that open up from the street above. Also sewage spills in from building drains as well. Magical orbs provide light, and ladders lead up to the occasional entrances from the street for maintenance.",
	"ladder" : "The latter is rusted and has seen a lot of use. ",
	"river" : "The river is full of nasty %^GREEN%^s%^ORANGE%^e%^GREEN%^w%^ORANGE%^a%^GREEN%^g%^ORANGE%^e%^RESET%^, but hey who said skulking was for the faint of heart?",
	"canal" : "The river is full of nasty %^GREEN%^s%^ORANGE%^e%^GREEN%^w%^ORANGE%^a%^GREEN%^g%^ORANGE%^e%^RESET%^, but hey who said skulking was for the faint of heart?",
	"walkways" : "Thank goodness there are walkways. No need to get filthier than you have to be.",
	"walls" : "The walls were made by artisans, and there looks to be the mark of magic on them too. The craftsmanship is excellent.",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/myrkul/sen_kitchen",
		"west" : "/d/av_rooms/myrkul/sen_sewer6",
		"south" : "/d/av_rooms/myrkul/sen_sewer3",
	]));

    set_door("lid","/d/av_rooms/myrkul/sen_kitchen","up");
    set_open("lid",0);
    set_string("lid","knock","knocks on the");
    set_string("lid","open","The lid clanks open.");
    set_string("lid","close","The lid clanks closed.");
    set_door_description("lid","This lid is the cover of a floor drain.");
}