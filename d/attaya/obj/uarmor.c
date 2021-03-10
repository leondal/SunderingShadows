#include <std.h>
inherit "/std/armour";

void create() {
    ::create();
    set_name("ancient armor");
    set("id", ({ "ancient armor", "armour", "armor","rusty armor",
	"rusty","ancient",
	"rusty ancient armor" }) );
    set("short", "Rusty armor of the ancients");
    set_long(
      "This ancient armor is now rusty and tarnished.  Beneath layers of neglect, a glint of gold can still be seen.  For years, this suit of armor has been buried in the jungles of attaya, on the skeletal remains of a dead warrior.  Now it has resurfaced again."
    );
    set_weight(50);
    set("value", 1000);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    set_ac(4);
    set_wear("You slip into the rusty armor and find it very uncomfortable as the leather inside has rotted away.");
    set_remove("You are happy to climb out of this uncomfortable heavy suit of rusty armor.");
}
