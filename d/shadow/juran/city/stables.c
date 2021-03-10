#include <std.h>
#include "../juran.h"
inherit STABLE;

void create(){
	object ob;
   ::create();
   set_terrain(HUT);
   set_travel(DIRT_ROAD);
   set_name("juran stables");
   set_short("Juran's Stables");
   set_long(
   	"%^RESET%^%^ORANGE%^This is a large barn in need of much "+
   	"repair which houses what passes for a stables in Juran.  "+
   	"The animal dung has not been cleaned from the floor for a "+
   	"long time and it is evident by the smell that the animals "+
   	"have not either.%^RESET%^\n%^BOLD%^There is a sign here.%^RESET%^\n"
   );
   set_property("indoors",1);
   set_property("light",-2);
   set_smell("default","The room smells so bad it makes your stomach churn.");
   set_listen("default","You can hear the buzzing of flies and other insects.");
   set_animal(({"wolf","spider","boar","donkey","worg"}),
    	({JMOUNTS+"wolf",JMOUNTS+"spider",JMOUNTS+"boar",JMOUNTS+"donkey",JMOUNTS+"worg"}));
   set_animal_price(({"wolf","spider","boar","donkey","worg"}),({1500,2200,1500,2000,2000}));
   set_stalls(30);
   ::fill_stalls();
   set_exits( ([
        "south" : JROOMS+"r8",
        "east" : JROOMS+"smithy"
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
	Wolf   : 1500 gold
	Spider : 2200 gold
	Boar   : 1500 gold
	Donkey : 2000 gold
	Worg   : 2000 gold
   ");
   return 1;
}

void reset(){
   object ob;
   ::reset();
   ob = present("stable hand");
   if(objectp(ob)) ob->set_race("hobgoblin");
}
