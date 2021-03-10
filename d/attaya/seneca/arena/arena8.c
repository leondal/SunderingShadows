#include <std.h>
#include <arena.h>
inherit ARENA;
void create(){
    ::create();
set_name("%^BOLD%^%^RED%^The arena floor.%^RESET%^");
 set_short("The Arena at Seneca");
  set_long("
    You are standing against the western wall of the Seneca Colleseum.  People above you scream at you and cry out for blood.
    The floor beneath you is stained with blood and littered with decaying limbs.
    A large circle of stakes draped with scorched skeletal remains lies to the east at the center of the arena floor.
 
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
"south" : "/d/attaya/seneca/arena/arena10.c",
"north" : "/d/attaya/seneca/arena/arena5.c",
    ]) );
}
