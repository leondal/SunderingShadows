// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("pen");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("desert");
    set_travel("foot path");
    set_climate("desert");

    set_short("%^RESET%^%^CYAN%^Before a massive animal pen%^RESET%^");

    set_long("%^BOLD%^%^CYAN%^A long foot path leads out from the Temple of Anhur to a large pen housing an enormous animal. The pen walls are about five feet tall, made of wood slats, and inscribed with wonderous "
	"runes of %^BOLD%^%^GREEN%^p%^YELLOW%^e%^GREEN%^a%^YELLOW%^c%^GREEN%^e, %^WHITE%^se%^BLUE%^r%^WHITE%^eni%^BLUE%^t%^WHITE%^y%^CYAN%^, and %^MAGENTA%^st%^RED%^r%^MAGENTA%^ength%^CYAN%^. Towering over the"
	" pitifully small pen walls, is a gigantic %^GREEN%^Forest %^RED%^B%^YELLOW%^a%^RED%^t%^YELLOW%^t%^RED%^l%^YELLOW%^e%^GREEN%^ Mammoth%^CYAN%^. The titanic creature is resting sedately before an enormou"
	"s %^RESET%^%^ORANGE%^trough%^BOLD%^%^CYAN%^ which refills itself miraculously with food and water.%^RESET%^"
	);

    set_smell("default","
It smells like mammoth crap.");
    set_listen("default","You here the steady rumble of the mammoth's breathing.");

    
set_items(([ 
	"trough" : "The trough is clearly magical, most likely a divine blessing.",
	"mammoth" : "It looks to be about fifty feet tall, furry, a long trunk, and has enormous tusks.",
	"runes" : "The runes probably have sedated the mammoth inside the pen.",
	]));

    set_exits(([ 
		"out" : "/d/shadow/virtual/desert/38,15.desert",
		"pen" : "/d/av_rooms/myrkul/pen_inside",
	]));

    set_door("massive gate","/d/av_rooms/myrkul/pen_inside","pen","anhurs key","lock");
    add_lock("massive gate","anhurs key","lock","This is a heavy iron lock.");
    set_locked("massive gate",1,"lock");
    lock_difficulty("massive gate",-5,"lock");
    set_open("massive gate",0);
    set_string("massive gate","knock","pounds on the");
    set_string("massive gate","open","The gate rumbles open.");
    set_string("massive gate","close","The gate rumbles closed.");
    set_door_description("massive gate","This is a massive gate designed as much to keep things out as to keep this mammoth in.");
}