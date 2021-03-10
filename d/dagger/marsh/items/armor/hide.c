inherit "/std/armour";

void create() {
    ::create();
    set_name("hide");
    set("id", ({ "hide", "armor" }) );
    set("short", "A suit of hide armor");
    set("long", 
	"This is armor prepared from extremely thick hides of a creature, "
	"(such as an elephant), or from multiple layers of regular "
	"leather. It is stiff and hard to move in."
       );
    set_weight(30);
    set("value", 15);
    set_type("leather");
    set_limbs( ({ "torso" }) );
    set_ac(4);
}
