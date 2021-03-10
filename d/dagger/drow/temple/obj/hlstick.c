#include <std.h>
inherit OBJECT;
void init() {
    ::init();
    add_action("snap_func","snap");
}
void create() {
    ::create();
    set_id(({"stick","heal stick","stick of healing",
	"healing stick","heal_stick"}));
    set_short("%^RED%^Stick of healing%^RESET%^");
    set_long(
	"%^RED%^This is a stick of healing used by Drow and "
	"Driders. It may be used "
	"by <snap stick>."
	"%^RESET%^"
);
     set_weight(2);
    set_value(50);
}
int snap_func(string str) {
    if(!str) {
	notify_fail("Snap what?\n");
	return 0;
    }
    if(str != "stick") {
	notify_fail("Snap what?\n");
	return 0;
    }
    if(TP->query_paralyzed() || TP->query_disable()) return 0;
    write(
	"%^RED%^You snap the stick and spread the substance within "
	"it upon your wounds. Your wounds heal a bit.%^RESET%^"
    );
    say(
	"%^RED%^"+TPQCN+" snaps a glass tube and spreads a substance "
	"onto "
	+TP->query_possessive()+
	" wounds."
    ,TP);
     TP->add_hp(20+random(20));
    TP->set_paralyzed(2,"%^RED%^You are spreading the substance onto your wounds!%^RESET%^");
    TO->remove();
    return 1;
}
