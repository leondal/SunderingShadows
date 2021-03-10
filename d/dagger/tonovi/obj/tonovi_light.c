//tonovi_light.c - by ~Circe~
#include <std.h>
#include <daemons.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("torches");
    set_id(({"torches","brace of torches","post","lamp post","tonovi_light"}));
    set_weight(1000000);
    set_short("%^RESET%^%^ORANGE%^A brace of torches%^MAGENTA%^");
    set_long("A roughly hewn wooden post supports a brace of "+
       "torches that may be lit at night to help brighten "+
       "this square.");
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
       set_short("%^RESET%^%^ORANGE%^A %^YELLOW%^brightly lit %^RESET%^%^ORANGE%^brace of torches%^BOLD%^%^MAGENTA%^");
    }
    if((tod != "night") && query_property("light")){
       remove_property("light");
       set_short("%^RESET%^%^ORANGE%^A brace of torches%^BOLD%^%^MAGENTA%^");
    }
}