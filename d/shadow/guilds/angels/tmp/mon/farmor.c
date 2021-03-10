//Coded by Bane//
#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Armor of The Fallen");
    set_id(({"armor","armor of the fallen","Armor"}));
    set_short("Armor of The Fallen");
    set_long(
	"Lord Nihilus's personal armor.  Centuries old "+
	"this armor was flawlessly crafted and is exceptionally strong."
       );
    set_weight(50);
    set_value(50);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    set_ac(8);
    set_property("enchantment",3);
    set_property("keep","Lord Nihilus");
    set_wear( (:TO,"wer":) );
}
void wer(string str){
    if((string)TP->query_name() != "Lord Nihilus"){
	write("You are too weak to wear this armor!");
	return 0;
    }
    return 1;
}
