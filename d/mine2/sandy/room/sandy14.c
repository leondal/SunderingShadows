#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, main square.");
    set_long(""
"%^BOLD%^WHITE%^You are in the center of the town Sandy.\n%^RESET%^"
"There are many roads leading to many shops, and guilds around this town.  "
"To the north is the great castle, which towns people say it is some sort "
"of illusion.  To the west is the great sea of death.  "
"There are many signs pointing to many different places, but they are to"
" blury to read because of the recent rain.  There are many towns people"
" talking about important things that have been posted on the town board.");

     set_listen("default","You hear the soft wind blow through the trees.");
     set_smell("default","You smell the many things.");
    set_exits(([
       "north" : "/d/mine2/sandy/room/sandy13",
       "south" : "/d/mine2/sandy/room/sandy15",
       "east" : "/d/mine2/sandy/room/sandy6",
       "west" : "/d/mine2/sandy/room/sandy19",
    ] ));
    set_items(([
         "trees" : "The trees are palm trees that are swaying in the gentle breaze.",
         "people" : "The people are local Sandy residents that are just talking about every day things.",
         "signs" : "The signs are to blury to read, but they don't look important any way.",
         "roads" : "The roads lead to many different places of great improtance.",
    ] ));
}
