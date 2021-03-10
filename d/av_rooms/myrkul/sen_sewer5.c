// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sen_sewer5");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^%^BOLD%^%^BLUE%^S%^CYAN%^e%^BLUE%^neca%^GREEN%^ S%^RESET%^%^ORANGE%^e%^BOLD%^%^GREEN%^wers%^RESET%^");

    set_long("You stand in an %^RESET%^%^ORANGE%^underground sewer%^RESET%^. The sewer is essentially an %^BOLD%^%^BLUE%^un%^CYAN%^d%^BLUE%^erground r%^CYAN%^i%^BLUE%^ver%^RESET%^, with %^RESET%^%^ORANGE%^cobblesto"
	"nes walkways%^RESET%^ on either side of the %^BOLD%^%^GREEN%^canal%^RESET%^. The canal itself is about four feet deep with a flat stone bottom, which is quite walkable for most adult humans, but more "
	"than %^BOLD%^%^MAGENTA%^deep enough to drown a halfling or gnome%^RESET%^. The walls and ceiling are solid stone, and a %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^i%^RESET%^t%^BOLD%^%^BLACK%^t%^RESE"
	"T%^y %^YELLOW%^light%^RESET%^ from above shines in from street drains that open up in the ceiling above the river. Between the street level openings, intermittently space magical orbs provide enough l"
	"ight to get around. The sewer here extends east and west. You can hear more street noise coming from the east."
	);

    set_smell("default","
It smells pretty nasty. At least the river moves fast enough to keep the stench from killing anyone.");
    set_listen("default","%^RESET%^You can hear the scurrying of %^BOLD%^%^RED%^rats%^RESET%^ scurrying hither and thither.");

    set_search("bottom","%^BOLD%^%^CYAN%^You screw up your courage and dip your %^GREEN%^hand%^CYAN%^ into the %^BLACK%^filth.%^CYAN%^ You come back with the knowledge that you are %^RED%^really brave!%^CYAN%^ But no hidden treasures lie in all that nastiness!%^RESET%^");
    set_search("sewer","%^BOLD%^%^CYAN%^You screw up your courage and dip your %^GREEN%^hand%^CYAN%^ into the %^BLACK%^filth.%^CYAN%^ You come back with the knowledge that you are %^RED%^really brave!%^CYAN%^ But no hidden treasures lie in all that nastiness!%^RESET%^");
    set_search("river","%^BOLD%^%^CYAN%^You screw up your courage and dip your %^GREEN%^hand%^CYAN%^ into the %^BLACK%^filth.%^CYAN%^ You come back with the knowledge that you are %^RED%^really brave!%^CYAN%^ But no hidden treasures lie in all that nastiness!%^RESET%^");
    set_search("ladder","The manhole looks like its seem some use.");
    set_search("canal","%^BOLD%^%^CYAN%^You screw up your courage and dip your %^GREEN%^hand%^CYAN%^ into the %^BLACK%^filth.%^CYAN%^ You come back with the knowledge that you are %^RED%^really brave!%^CYAN%^ But no hidden treasures lie in all that nastiness!%^RESET%^");
    set_search("walkways","The walkway is too clean. Clearly others have used this tunnel before you, and recently too.");
    
set_items(([ 
	"ceiling" : "The ceiling is arched, with drains that open up from the street above. Also sewage spills in from building drains as well. Magical orbs provide light, and ladders lead up to the occasional entrances from the street for maintenance.",
	"river" : "The river is full of nasty %^GREEN%^s%^ORANGE%^e%^GREEN%^w%^ORANGE%^a%^GREEN%^g%^ORANGE%^e%^RESET%^, but hey who said skulking was for the faint of heart?",
	"ladder" : "The latter is rusted and has seen a lot of use. ",
	"walls" : "The walls were made by artisans, and there looks to be the mark of magic on them too. The craftsmanship is excellent.",
	"walkways" : "Thank goodness there are walkways. No need to get filthier than you have to be.",
	"canal" : "The river is full of nasty %^GREEN%^s%^ORANGE%^e%^GREEN%^w%^ORANGE%^a%^GREEN%^g%^ORANGE%^e%^RESET%^, but hey who said skulking was for the faint of heart?",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/myrkul/sen_sewer7",
		"north" : "/d/av_rooms/myrkul/sen_sewer3",
	]));

    set_door("manhole cover","/d/attaya/newseneca/rooms/estreet15","up","sewer key","lock");
    add_lock("manhole cover","sewer key","lock","This is a standard lock.");
    set_locked("manhole cover",1,"lock");
    lock_difficulty("manhole cover",-20,"lock");
    set_open("manhole cover",0);
    set_string("manhole cover","knock","pounds on the");
    set_string("manhole cover","open","You pry open the manhole cover.");
    set_string("manhole cover","close","You pull the manhole cover closed.");
    set_door_description("manhole cover","This is a heavy metal plate that keeps people from falling into the sewer from the street above. ");
}