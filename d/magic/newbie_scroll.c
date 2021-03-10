//newbie scrolls - single-use scrolls for Offestry to help mages
//~Circe~ 6/6/07
// created by Tristan to help new mages test out spells
// changes to pass argument to set_desc where needed so it will properly show they can't be transcribed *Styx*  2/13/03

#include <std.h>
inherit "/d/magic/scroll";

void create(){
    ::create();
     set_weight(2);
     set_is_newbie(1);
}

int query_value(){
    return 25;
}

int is_newbie_scroll(){ return 1;}

int transcribe(string str){
    return notify_fail("This scroll doesn't seem to be able to be transcribed.\n");
}


int do_back_fire(object myuser) { return 0; }
