// fixed wear/unwear to use ETO, added obvious short-last change was 7/98  *Styx* 

#include <std.h>

inherit ARMOUR;
void create(){
    ::create();
    set_name("amulet");
    set_id(({"amulet","amulet of warding"}));
    set_obvious_short("%^BOLD%^%^CYAN%^wooden amulet%^RESET%^");
    set_short("%^BOLD%^%^CYAN%^Amulet of warding%^RESET%^");
    set_long("%^BOLD%^%^CYAN%^"
	"This strange amulet depicts a crescent moon surrounded by flames. "
	"The picture has been carved upon the wooden disc surface of the amulet and "
	"the disc hangs from a plain straw like necklace. A faint glow "
	"surrounds the disc.%^RESET%^"
    );
    set_weight(5);
    set_value(200);
    set_wear((: this_object(),"wearit" :));
    set_remove((:this_object(),"removeit" :));
    set_type("clothing");
    set_item_bonus("magic resistance",2);
    set_limbs(({"neck"}));
}
 
int wearit(){
    if((int)ETO->query_level() < 25) {
	write("As you wear the amulet it vanishes!");
        TO->remove();
	return 0;
    }
    write("%^BOLD%^%^CYAN%^You feel your body surrounded by a strange "
	"force!%^RESET%^");
    tell_room(environment(ETO), "%^BOLD%^%^CYAN%^A strange glow surrounds "
	+ETOQCN+"!%^RESET%^" ,ETO);	
    return 1;
}

int removeit(){
    write("%^BOLD%^%^CYAN%^The strange force that surrounded your body "
	"suddenly fades away!%^RESET%^" );
    tell_room(environment(ETO),
	"%^BOLD%^%^CYAN%^Slowly a faint glow surrounding "+ETOQCN+" shimmers "
	"briefly and vanishes!%^RESET%^",ETO);
    return 1;
}
