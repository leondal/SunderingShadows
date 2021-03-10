// Coded by Bane
// bspear.c
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"spear","bone","bone spear"}));
    set_name("bone spear");
    set_short("A bone spear");
    set_long(
	"This is a long bone-bladed spear.  The shaft is made "+
	"from some gnarled wood and the tip is sharp chipped bone."
    );
    set_weight(10);
    set_size(3);
    set_value(0);
    set_wc(1,12);
    set_large_wc(1,12);
    set_type("pierce");
    set_prof_type("large spear");
}
