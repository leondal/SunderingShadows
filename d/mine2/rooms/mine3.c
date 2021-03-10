#include <std.h>
#include <objects.h>



inherit ROOM;
inherit "/realms/zeek/mine.c";

void create() {
    room::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("mine shaft");
    set_long(""
"%^BOLD%^YELLOW%^ "
"The cavern is covered with all kinds of little sparkle like rock.  "
"There is water driping from all over the mine.  There are small "
"areas where people have made marks with there picks.  A large piece "
"of rock sits in the middle of the room.");

     set_listen("default","You hear the echos of peoples screams.");
      set_smell("default","You smell something odd, but can't put your finger on it!");
    set_exits(([
        "east" : "/d/mine2/rooms/mine4",
       "west" : "/d/mine2/rooms/mine2",
    ] ));
    set_items(([
         "cavern" : "It is very dark and stuffy in this cavern.",
         "stream" : "There is a small stream running down the center of the room.",
         "marks" : "The marks are from picks  from earlier tried to get gold.",
         "darkness" : "The darkness is caused by the enterance being somewher blocked.",
         "gold" : "You do not see any gold right off, only rock.",
         "rock" : "A large rock is sitting in the middle of the mine shaft",
         "ground" : "it is covered with chiped rock.",
    ] ));
set_max_mining(1);
set_chance(0);
}
