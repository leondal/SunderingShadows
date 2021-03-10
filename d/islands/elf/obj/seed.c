//seed of return, 
#include <std.h>
#include "../elf.h"
inherit OBJECT;

void create() {
    ::create();
    set_name("%^RESET%^%^GREEN%^Seed of return%^RESET%^");
    set_id(({"seed","seed of return","green seed"}));
    set_short("%^RESET%^%^GREEN%^Seed of return%^RESET%^");
    set_obvious_short("%^RESET%^%^GREEN%^green seed%^RESET%^");
    set_long("%^RESET%^%^GREEN%^This is a rather large "+
	"seed that is a vibrant green.  It is about the "+
	"size of a ball and has several sapphires stuck "+
	"to it that glisten magically.  Perhaps one can "+
	"sow it and see what happens.%^RESET%^");
    set_weight(1);
    set_value(1000);
}

void init() {
    ::init();
    add_action("plant_func","sow");
}
int plant_func(string str) {
    string tera;
    if( !str || str != "seed") {
           tell_object(ETO,"%^BOLD%^Sow what?%^RESET%^");
       return 0;
    }
    if(TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }
    if(TP->query_paralyzed()) {
           return notify_fail(TP->query_paralyze_message()+"\n");
        }
	tera = ETP->query_terrain();
    if(ETP->query_property("no teleport") 
	  || ETP->query_property("teleport proof") 
	  || tera == "stone building" 
	  || tera == "glacier"
      || tera == "boats" 
	  || tera == "deep water"
      || tera == "ice"
      || tera == "city"  	  ){
         tell_object(TP,"%^MAGENTA%^You plant the seed ...and...nothing happens.  "+
                  "%^RED%^Crap.%^RESET%^");
         tell_room(ETP,"%^BOLD%^"+TP->QCN+" plants a seed on the "+
                  "ground, and looks foolish as "+TP->QS+" remains standing "+
                  "looking at it expectantly",TP);        
       TO->move(ETP);				  
       return 1;
    }
         
    tell_object(TP,"%^GREEN%^You plant the seed and become "+
           "enveloped in vines that grow from the ground!\nAs the vines dissipate you "+
           "realize have been magically teleported elsewhere!%^RESET%^");
    tell_room(ETP,"%^BOLD%^"+TP->QCN+" plants a seed in the ground "+
           "and vines grow up enveloping "+TP->QO+".",TP);
    TP->move_player(ROOMS"gate1");
    remove();
    return 1;
}

int isMagic(){ return 1; }
