#include <std.h>
#include "elf.h"
inherit STABLE;
void create(){
    object ob;
    ::create();
    set_terrain(HUT);
    set_travel(DIRT_ROAD);
    set_name("Wooden hut");
    set_short("Ashata Rathai stables");
    set_long(
        "%^BOLD%^An animal ranch%^RESET%^ \n"+
        "%^GREEN%^You are standing in a strange grove used as a stable%^CYAN%^.%^GREEN%^  The "+
        "room is fairly large with rows of formed trees for the exotic "+
        "animals that are housed here%^CYAN%^.%^GREEN%^  There is a small elf "+
        "running around cleaning up all of the pens and feeding "+
        "the animals while a stable hand waits at the front for "+
        "any customers%^CYAN%^.%^GREEN%^  Outside the shop are huge aviaries used"+
		" for training%^CYAN%^.%^GREEN%^   The cliff face surrounds this "+
		"place both above and below. \n  %^CYAN%^Most of the ground around the edges of the ranch is rocky."
        "\n%^BOLD%^There is a sign here.%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The room smells of animals and grass.");
    set_listen("default","You can hear the strange sounds of exotic animals.");
   
  set_animal(({"elk","snow leopard","dire owl","snow griffin"}),({MON"elk",MON"sleopard",MON"owl",MON"griffin"}));
  set_animal_price(({"elk","snow leopard","dire owl","snow griffin"}),({20000,20000,30000,40000}));
  set_stalls(30);
  ::fill_stalls();
   set_exits( ([
        "down":ROOMS"cliff2",
		"west":ROOMS"arch",
        "north": ROOMS"quest",
        "southwest": ROOMS"forge",
    ]) );
}



void reset(){
     object ob;
     ::reset();
     ob = present("stable hand");
     if(objectp(ob)) ob->set_race("elf");
}
