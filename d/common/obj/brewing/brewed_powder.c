// inherit for brewed powders. N, 10/15.
#include "./brew.h"
inherit BREWINH;

void create() {
    ::create();
    myname = "powder";
}

void set_myname(string thename) {
    set_lore("This powder is one crafted by many alchemists of the land.  Because of the ingredients used, "+
"such powders often have similar qualities, such as color and smell.  You're familiar enough with this "+
"particular variety, to believe it is probably a "+thename+".");
    myname = thename;
}