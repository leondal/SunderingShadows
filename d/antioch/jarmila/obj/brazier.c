//Brazier
//Adapted from /d/attaya/newseneca/street.c 
//LoKi - 6/4/2017

#include <std.h>
#include <daemons.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("heavy iron brazier");
    set_id(({"brazier","heavy iron brazier",}));
    set_weight(1000000);
    set_short("%^BLACK%^%^BOLD%^A heavy iron brazier%^RESET%^");
    set_long("%^BLACK%^%^BOLD%^Formed from heavy black iron into a "+
	"half cage, this brazier is filled with oil soaked wood. It is "+
	"large enough that it would take a team of horses to budge it.%^RESET%^");
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
       set_short("%^BLACK%^%^BOLD%^A %^BOLD%^%^RED%^l%^YELLOW%^i%^RESET%^%^RED%^t"+
	   "%^RESET%^%^BLACK%^%^BOLD%^ heavy iron brazier%^RESET%^");
	   set_long("%^BLACK%^%^BOLD%^Formed from heavy black iron into a "+
	"half cage, this brazier is filled a %^RED%^roar%^YELLOW%^i%^RED%^ng "+
	"f%^RESET%^%^RED%^i%^BOLD%^re%^BLACK%^. It is "+
	"large enough that it would take a team of horses to budge it.%^RESET%^");
	   
    }
    if((tod != "night") && query_property("light")){
       remove_property("light");
       set_short("%^BLACK%^%^BOLD%^A heavy iron brzier%^RESET%^");
	   set_long("%^BLACK%^%^BOLD%^Formed from heavy black iron into a "+
	"half cage, this brazier is filled with oil soaked wood. It is "+
	"large enough that it would take a team of horses to budge it.%^RESET%^");
    }
}
