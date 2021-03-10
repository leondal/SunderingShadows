// inherit for brewed items. N, 11/11.
// lifted per specific files in /std/brewing.
#include <std.h>
inherit OBJECT;

int dc, strength, reversed;
string myname, attribute;

void create() {
    ::create();
    dc = 1;
    strength = 1;
    reversed = 0;
    myname = "potion";
    attribute = "";
}

void set_dc(int pot_dc) { dc = pot_dc; remove_property("lore difficulty"); set_property("lore difficulty",dc); }
int query_dc() { return dc; }

void set_strength(int pot_strength) { strength = pot_strength; }
int query_strength() { return strength; }

void set_reversed(int mystatus) { reversed = mystatus; }
int is_reversed() { return reversed; }

void set_myname(string thename) {
    set_lore("This potion is one crafted by many alchemists of the land.  Because of the ingredients used, "+
"such potions often have similar qualities, such as color and smell.  You're familiar enough with the "+attribute+" of "+
"this potion, to believe it is probably a "+thename+".");
    myname = thename;
}

string query_myname() { return myname; }
string query_attribute() { return attribute; }

int isMagic(){ return 1; }
int is_brewed(){ return 1; }