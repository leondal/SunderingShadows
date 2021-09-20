//Chunk of Sunstone - LoKi - 2021 

#include <std.h>
#include <daemons.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("chunk of sunstone");
    set_id(({"sunstone","chunk of sunstone",}));
    set_weight(1000000);
    set_short("%^C196%^c%^C088%^h%^C196%^u%^C184%^n%^C196%^k "+
	"of su%^C184%^n%^C196%^sto%^C088%^n%^C196%^e%^%^CRST%^");
    set_long("%^C196%^This massive chunk of sunstone sticks "+
	"out of the ground. Instead of being naturally here it "+
	"seems like it fell at great speed to the earth and has "+
	"jutted out. Instead of damage, it is almost as if the "+
	"foliage has flourished around it.%^CRST%^");
    set_value(0);
    set_property("no animate",1);
}

void init(){
   string tod;
   ::init();
    if(!interactive(TP)) return;
    tod = EVENTS_D->query_time_of_day();
    if((tod == "night") && !query_property("light")){
       set_property("light",3);
       set_short("%^C226%^gl%^C196%^o%^C226%^wi%^C088%^"+
	   "n%^C226%^g %^C196%^c%^C088%^h%^C196%^u%^C184%^"+
	   "n%^C196%^k of su%^C184%^n%^C196%^sto%^C088%^"+
	   "n%^C196%^e%^%^CRST%^");
    set_long("%^C196%^This massive chunk of sunstone sticks "+
	"out of the ground. Instead of being naturally here it "+
	"seems like it fell at great speed to the earth and has "+
	"jutted out. Instead of damage, it is almost as if the "+
	"foliage has flourished around it.%^CRST%^");

    }
    if((tod != "night") && query_property("light")){
       remove_property("light");
       set_short("%^C196%^c%^C088%^h%^C196%^u%^C184%^"+
	   "n%^C196%^k of su%^C184%^n%^C196%^sto%^C088%^"+
	   "n%^C196%^e%^%^CRST%^");
    set_long("%^C196%^This massive chunk of sunstone sticks "+
	"out of the ground. Instead of being naturally here it "+
	"seems like it fell at great speed to the earth and has "+
	"jutted out. Instead of damage, it is almost as if the "+
	"foliage has flourished around it.%^CRST%^");
}
}
