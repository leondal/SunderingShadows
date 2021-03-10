#include <std.h>
#include <arena.h>
inherit ARENA;
void create(){
    ::create();
set_name("%^BOLD%^%^RED%^The arena floor.%^RESET%^");
 set_short("The Arena at Seneca");
  set_long("
    This is the southern wall of the Seneca Colleseum.  Just above you is the royal spectator's box.  A few Seneca nobles look down upon you and sneer.  The wall here shows damage caused by some sort of heavy spiked weapon.
 
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
"north" : "/d/attaya/seneca/arena/arena14.c",
"northwest" : "/d/attaya/seneca/arena/arena13.c",
"northeast" : "/d/attaya/seneca/arena/arena15.c",
    ]) );
}
