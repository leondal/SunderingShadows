#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    
    set_property("indoors", 0);
    set_property("light", 1);
    set_short("On a narrow jungle path.");
    set_long("\
You are walking on a narrow path through the jungle. The air is thick with
humidity and you find yourself covered with sweat and mosquitoes. All around
you is thick vegetation, with long, leafy shoots and large palm trees. You
hear the din of combat further up the path. Is there a battle going on?\n");
    set_items( ([
                 ({ "shoots" }) : "These shoots seem to sprout from everywhere.",
                 ({ "trees"  }) : "Palm trees press closely in on the path.",
               ]) );
               
    set_exits( ([
                 "east" : "/d/islands/tonerra/expedition/room/jungle2",
               ]) );
}
