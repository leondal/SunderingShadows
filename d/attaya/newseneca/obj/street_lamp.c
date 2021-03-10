//Adapted from /d/common/obj/misc/street_light.c 
//~Circe~ 11/8/07 for new Seneca - the day and night
//shorts didn't seem to be working from the original.
#include <std.h>
#include <daemons.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("street lamp");
    set_id(({"street lamp","street_lamp","street light","street_light"}));
    set_weight(1000000);
    set_short("%^BOLD%^%^BLACK%^An ornate street lamp%^MAGENTA%^");
    set_long("%^BOLD%^%^BLACK%^This tall wrought iron street lamp "+
       "features a fluted column base that narrows as it leads to "+
       "a fleur-de-lis capital.  A crossbar just below the capital "+
       "supports a %^CYAN%^crystal %^BLACK%^lantern at either end.%^RESET%^");
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
       set_short("%^BOLD%^%^BLACK%^A %^CYAN%^brightly lit %^BLACK%^street lamp%^MAGENTA%^");
    }
    if((tod != "night") && query_property("light")){
       remove_property("light");
       set_short("%^BOLD%^%^BLACK%^An ornate street lamp%^MAGENTA%^");
    }
}