//Coded by Bane//
#include <std.h>
inherit STABLE;
void create(){
    object ob;
    ::create();
    set_terrain(HUT);
    set_travel(DIRT_ROAD);
    set_name("Wooden hut");
    set_short("Systyquah stables");
    set_long(
        "%^BOLD%^A Wooden hut%^RESET%^
You are standing in a large wooden hut used as a stable.  The "+
	"room is fairly large with rows of pens for the exotic "+
	"mounts that are housed here.  There is a small troll "+
	"running around cleaning up all of the pens and feeding "+
	"the animals while a stable hand waits at the front for "+
	"any customers."
	"\n%^BOLD%^There is a sign here.%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The room smells so bad it makes your stomach churn.");
    set_listen("default","You can hear the buzzing of flies and other insects.");
    set_animal(({"wolf","bear","boar","tyrg","cheetah"}),({"/d/laerad/parnelli/systyquah/mounts/wolf","/d/laerad/parnelli/systyquah/mounts/bear","/d/laerad/parnelli/systyquah/mounts/boar","/d/laerad/parnelli/systyquah/mounts/tyrg","/d/laerad/parnelli/systyquah/mounts/cheetah"}));
    set_animal_price(({"wolf","bear","boar","tyrg","cheetah"}),({1500,2200,1500,2000,2000}));
   set_stalls(30);
   ::fill_stalls();
    set_exits( ([
        "west":"/d/laerad/parnelli/systyquah/sys032"
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
	Wolf : 1500 gold
	Bear : 2200 gold
	Boar : 1500 gold
	Tyrg : 2000 gold
	Cheetah : 2000 gold
    ");
    return 1;
}

void reset(){
     object ob;
     ::reset();
     ob = present("stable hand");
     if(objectp(ob)) ob->set_race("troll");
}
