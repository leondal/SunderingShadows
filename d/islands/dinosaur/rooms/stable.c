#include <std.h>
#include "/d/islands/dinosaur/short.h"
inherit STABLE;
void create(){
    object ob;
    ::create();
    set_terrain(HUT);
    set_travel(DIRT_ROAD);
    set_name("Wooden hut");
    set_short("dino trainer stables");
    set_long(
        "%^BOLD%^A dino ranch%^RESET%^ \n"+
        "You are standing in a huge wooden hut used as a stable.  The "+
        "room is fairly large with rows of cages for the exotic "+
        "lizards that are housed here.  There is a small mongrelman "+
        "running around cleaning up all of the pens and feeding "+
        "the dinos while a stable hand waits at the front for "+
        "any customers.  Outside the shop are huge aviaries used for training. "
        "\n%^BOLD%^There is a sign here.%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The room smells so bad it makes your stomach churn.");
    set_listen("default","You can hear the buzzing of flies and other insects.");
   
set_animal(({"pterodactyl"}),({MPATH"pmnt"}));
   
set_animal_price(({"pterodactyl"}),({10000}));
   set_stalls(30);
   ::fill_stalls();
    set_exits( ([
        "west":RPATH"cliff4"
    ]) );
    ob = present("stable hand");
}
void init(){
    ::init();
    add_action("read","read");
}
void read(string str){
    if(!str) return notify_fail("Read what?\n");
    if(str != "sign") return 0;
    write("The following mounts are for sale:\n
        pterodactyl : 10000 gold");
    return 1;
}

void reset(){
     object ob;
     ::reset();
     ob = present("stable hand");
     if(objectp(ob)) ob->set_race("mongrelman");
}
