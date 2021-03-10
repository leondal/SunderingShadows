#include <std.h>
#include <arena.h>
inherit ARENA;
void create(){
    ::create();
set_name("%^BOLD%^%^RED%^The arena floor.%^RESET%^");
 set_short("The Arena at Seneca");
  set_long("
    This is the center of the arena's southern arc.  The sand beneath you shows the sign of a recent struggle ending in the crushing of the loser's skull.  You decide to not only watch your opponent but watch where you step as well.
 
%^RED%^Death hangs heavy in the air.
");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_property("arena",1);
set_property("deathmove","/d/attaya/seneca/arena/defeat.c");


set_listen("default","Bravery folk songs are played by a band and people cheer and shout around you!");
set_smell("default","The smoke from torches burns your nose.");
    set_exits( ([
"north" : "/d/attaya/seneca/arena/arena11.c",
"south" : "/d/attaya/seneca/arena/arena16.c",
"west" : "/d/attaya/seneca/arena/arena13.c",
"east" : "/d/attaya/seneca/arena/arena15.c",
    ]) );
}
