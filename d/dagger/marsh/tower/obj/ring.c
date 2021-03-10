// fixed wear/unwear to use ETO & added obvious short - last change was 6/01  *Styx* 8/2003
// fixed notify_fail in wear and changed from level 21 to 20 *Styx*  11/9/03

#include <std.h>
inherit "/std/armour";
string owner;
int uses;
void init() {
    ::init();
    if(!objectp(ETO)) { return; }
    if(interactive(ETO) && !owner) owner = ETO->query_true_name();
    uses = 5;
}
create() {
    ::create();
    set_name("ring");
    set_id(({"ring","gold ring","golden ring","ring of flying"}));
    set_short("%^YELLOW%^Golden ring%^RESET%^");
    set_long(
	"%^YELLOW%^This is small golden ring that is very light in weight. "
	"Traced around the outer band of the ring are small %^MAGENTA%^"
	"purple runes%^YELLOW%^.  There is no indication if the ring is "
	"magical in nature or just a decorative piece of jewelry.%^RESET%^"
    );
    set_weight(1);
    set_value(500);
    set_type("ring");
    set_limbs(({"right hand"}));
    set_ac(0);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}

int wearit() {
    if((int)ETO->query_level() < 20) {
        write("The magic of the ring rejects you!");
	TO->remove();
        return 0;
    }
    if((string)ETO->query_true_name() != owner) {
        write("The ring fails to bond with you and vanishes!");
        TO->remove();
        return 0;
    }
    write("%^YELLOW%^A strange energy begins to flow through your body!%^RESET%^");
    tell_room(environment(ETO), "%^YELLOW%^"+TPQCN+" slips on a golden ring.%^RESET%^"
    ,ETO);
    ETO->set_property("demongate flying",1);
    uses = uses - 1;
    return 1;
}

int removeit() {
    if(uses < 1) {
	write("%^YELLOW%^As you remove the golden ring it vanishes!%^RESET%^");
	say("%^YELLOW%^As "+ETOQCN+" removes a golden ring, it vanishes!%^RESET%^",ETO);
	TO->remove();
    }
    ETO->remove_property("demongate flying",1);
    return 1;
}
