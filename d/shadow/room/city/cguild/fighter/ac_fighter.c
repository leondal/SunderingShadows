#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_light(2);
    set_indoors(1);
    set_name("Fighters antechamber");
    set_short("Fighters antechamber");
    set_long("%^BOLD%^WHITE%^"
        "Welcome to the Fighters' antechamber!%^RESET%^\n"
      "You are in a gallery filled with many trophies that have been won by "
      "the awesome fighters.  There are many chairs that have been smashed by "
      "fighters who have gone berserk.  "
      "There is a giant door leading to the fighters guild at the end of the room.");
    set_exits( ([ "enter" : "/d/shadow/room/city/cguild/fighter/fighter",
	"west":"/d/shadow/room/main/garrison5",
      ]) );
//    set_pre_exit_functions( ({"enter"}), ({"GoThroughDoor"}) );
}

int GoThroughDoor(){
    if(TP->is_class("fighter") || TP->is_class("bard") || avatarp(TP)) return 1;
    tell_object(TP, "You'll have to wait until Grendel is done to try to get in.");
    return 0;
}
