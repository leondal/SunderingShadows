#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, small path.");

    set_long(""
"%^BOLD%^WHITE%^You are on a small path.\n%^RESET%^"
"To the north is a paved road that leads to many places in Sandy.  "
"To the west is some sort of ocean fishing spot, where you can fish till you "
"drop.  This path is very muddy and salty from the ocean.  There are many trees "
"that make it hard to travel fast through this path."
""
"");

     set_listen("default","You hear trees crack as you move through the area.");
     set_smell("default","You smell the salt from the ocean.");
    set_exits(([
       "north" : "/d/mine2/sandy/room/sandy",
       "south" : "/d/mine2/sandy/room/sandy",
       "east" : "/d/mine2/sandy/room/sandy",
       "west" : "/d/mine2/sandy/room/sandy",
    ] ));
    set_items(([
         "trees" : "The trees are palm trees that are swaying in the gentle breaze.",
         "people" : "The people are local Sandy residents that are just talking about every day things.",
         "signs" : "The signs are to blury to read, but they don't look important any way.",
         "roads" : "The roads lead to many different places of great improtance.",
    ] ));
}
