//Set to inherit from tlininherit.c - Octothorpe 1/7/10
//Coded by the one and only master of monsters...BANE//
// adding id of laeradmon *Styx* 12/20/03, last change 10/31/98

#include <std.h>
inherit "/d/laerad/mon/tlininherit.c";

void create(){
    ::create();
    set_hd(22,36);
    set_overall_ac(-13);
    set("aggressive",21);
    set_property("swarm",1);
   set_exp(12500);
    set_stats("strength",21);
    set_stats("dexterity",21);
}
