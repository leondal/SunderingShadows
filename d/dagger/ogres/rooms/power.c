#include <std.h>
#include "../ogres.h"

inherit STORAGE"1st.c";

int overall_power;

void init() {
    ::init();
    add_action("check_power_local", "check");
    add_action("remove_power", "black");
    add_action("add_power", "white");
}

void create(){
   ::create();
   set_exits(([
   ]));

}

int check_power(){ 
return overall_power; }

int check_power_local(){ tell_object(TP,"Power is "+overall_power+"..\n");
return 1;}

int add_power(){ 
    tell_room(ETP,"%^BOLD%^%^BLUE%^You hear water rush as %^RESET%^%^ORANGE%^wooden mechanisms fall into place%^RESET%^\n");
    overall_power=overall_power+1;
   return 1; 
}

int remove_power(){ 
    tell_object(ETP,"%^RESET%^%^ORANGE%^You hear a clunk and an ominous silence as something within the wooden mechanisms slips out of place%^RESET%^\n");
    overall_power=overall_power-1; 
    return 1;
}