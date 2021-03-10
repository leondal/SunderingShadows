//Adapted from /d/common/obj/misc/street_light.c 
//~Circe~ 11/8/07 for new Seneca - the day and night
//shorts didn't seem to be working from the original.
#include <std.h>
#include <daemons.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("ring of lights");
    set_id(({"lights","ring of lights","street lights","street light","street lamp","globes","ring of globes","small globes","ring of small globes"}));
    set_weight(1000000);
    set_short("%^RESET%^%^CYAN%^A ring of small globes%^BOLD%^%^MAGENTA%^");
    set_long("%^RESET%^%^CYAN%^Small %^BOLD%^globes %^RESET%^%^CYAN%^"+
       "are spread evenly around the %^ORANGE%^r%^RED%^i%^RESET%^v%^ORANGE%^"+
       "er %^RED%^s%^RESET%^to%^ORANGE%^n%^RED%^e%^ORANGE%^ ledge%^CYAN%^.  "+
       "Each globe lights up brightly at night, shedding light on the "+
       "fountain and square.%^RESET%^");
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
       set_short("%^RESET%^%^CYAN%^A %^BOLD%^brightly lit "+
          "%^RESET%^%^CYAN%^ring of small globes%^BOLD%^%^MAGENTA%^");
    }
    if((tod != "night") && query_property("light")){
       remove_property("light");
       set_short("%^RESET%^%^CYAN%^A ring of small globes%^BOLD%^%^MAGENTA%^");
    }
}