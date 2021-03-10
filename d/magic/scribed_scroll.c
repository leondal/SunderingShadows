// created by Tristan to help new mages test out spells
// changes to pass argument to set_desc where needed so it will properly show they can't be transcribed *Styx*  2/13/03

#include <std.h>
inherit "/d/magic/scroll";

void create(){
    ::create();
     set_weight(2);
}

int query_value(){
    return 1;
}
