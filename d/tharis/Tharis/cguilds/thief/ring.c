//Quest ring for assassins by Bane//
#include <std.h>
inherit ARMOUR;
string owner;
void create(){
    ::create();
    set_id(({"ring","guild ring","Xring"}));
    set_name("guild ring");
    set_short("A guild ring");
    set_long(
	"A rather ornate emerald ring.  It is inscribed with some name that is "+
	"too small to read.  It must belong to a wealthy person."
    );
    set_property("no animate",1);
    set_type("clothing");
    set_ac(0);
    set_limbs(({"left hand"}));
    set_weight(0);
    set_value(10);
}
//void save_me(string file){return 1;}
void init() {
    ::init();
    if(interactive(TP) && TP == environment(TO) && !owner)
    owner = TPQN;
    if( interactive(TP) && (string)TPQN != owner ) {
        tell_object(ETO,"You are not the legitimate owner of this ring!");
        remove();
    }
}
