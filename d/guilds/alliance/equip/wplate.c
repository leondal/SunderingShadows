#include <std.h>
inherit ARMOUR;

string OWNER;
void init() {
    ::init();
    if(interactive(TP) && TP==environment(TO) && !OWNER) OWNER = TPQN;
}

void create() {
    ::create();
    set_name("white plate mail");
    set("id", ({ "white plate mail", "plate mail", "plate",
	"armor","white plate", "defender plate" }) );
    set("short", "%^BOLD%^WHITE%^White plate mail%^RESET%^");
    set_long(
@ALLIANCE
On close inspection, it is obvious that this white plate mail is the
armor of a Defender of the Light, the elite garrison forces of the Alliance
of Light.  The quality of this armor is remarkable, and a vague glow seems
to surround it.
ALLIANCE
	);
	set_weight(40);
	set("value", 0);
	set_type("armour");
	set_size(random(2) + 1);
	set_limbs( ({ "torso" }) );
	set_ac(9);
	set_property("enchantment",2);
	set_wear((:this_object(), "extra_wear":));
	set_remove("%^BOLD%^%^WHITE%^You slip out of the white armor.");
}

int extra_wear() {
	if((string)TP->query_name() != OWNER) {
	write("%^WHITE%^BOLD%^The armor disintegrates as you try to wear it.");
	TO->remove();
	return 0;
	}
	if((int)TP->query_level() < 27) {
	    notify_fail("You are not ready for this armor.");
	    return 0;
    }
    write("%^BOLD%^%^WHITE%^There is a muted clanking of metal plates as you wear the armor.");
    return 1;
}
