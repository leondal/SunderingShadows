//beach_lamp.c - by ~Circe~ for new Seneca 6/8/08
#include <std.h>
#include <daemons.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("beach lamp");
    set_id(({"beach lamp","lantern","beach lantern","wrought iron lantern"}));
    set_weight(1000000);
    set_short("%^BOLD%^%^BLACK%^A wrought iron lantern%^MAGENTA%^");
    set_long("%^BOLD%^%^BLACK%^Attached near the top of a %^RESET%^"+
       "%^ORANGE%^wooden post%^BOLD%^%^BLACK%^, this wrought iron "+
       "lantern is rather ornate in design.  It is made completely "+
       "of scrollwork and is left %^CYAN%^glassless%^BLACK%^, "+
       "likely a consideration for its position near a sometimes "+
       "stormy beach.%^RESET%^");
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
       set_short("%^BOLD%^%^BLACK%^A %^CYAN%^brightly lit %^BLACK%^wrought iron lantern%^MAGENTA%^");
    }
    if((tod != "night") && query_property("light")){
       remove_property("light");
       set_short("%^BOLD%^%^BLACK%^A wrought iron lantern%^MAGENTA%^");
    }
}