// fixed wear/unwear to use ETO & added obvious short - last change was 7/03  *Styx* 8/2003

#include <std.h>
inherit "/std/armour";
object owner;
void init() {
    ::init();
    if(interactive(TP) && !owner) owner = TPQN;
}
create() {
    ::create();
    set_name("tooth");
    set_id(({"tooth","fang","golden tooth","golden fang"}));
    set_obvious_short("gold tooth");
    set_short("%^YELLOW%^Golden fang%^RESET%^");
    set_long(
	"%^YELLOW%^This is small golden fang that can be attached over "
	"an existing tooth, most likely worn as a decoration or as a status "
	"symbol. It glows with a faint magical aura.%^RESET%^"
    );
   set_weight(1);
    set_value(300);
    set_type("clothing");
    set_limbs(({"head"}));
//    set_ac(1);
    set_wear((:TO,"wearit":));
}
int wearit() {
    if((int)ETO->query_lowest_level() < 21) {    
        write("The magic of the tooth rejects you as too weak!");
// changed notify_fail to write since notify_fails don't work in wear/unwear funcs *Styx*  7/26/03
	TO->remove();
        return 0;
    }
    if((string)ETOQN != owner) {
        write("The tooth fails to bond with you and vanishes!");
        TO->remove();
        return 0;
    }
    write("%^YELLOW%^You adorn the golden fang and feel safer!%^RESET%^");
    tell_room(environment(ETO), "%^YELLOW%^"+ETOQCN+" attaches a golden fang to one of "
	+ETO->query_possessive()+" teeth!%^RESET%^",ETO);	
    return 1;
}
