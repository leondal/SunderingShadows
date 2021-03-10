inherit "/std/armour";

void create() {
    ::create();
    set_name("hide");
    set("id", ({ "hide", "armor" }) );
    set("short", "Crude hide armor");
    set("long", 
   "This armor is simply large pieces of thick, roughly tanned hide from some creature that was skinned.  It has straps and a belt to hold them in place.  The pieces are generally arranged to provide some protection to the torso and shoulders."
       );
    set_weight(30);
    set("value", 15);
    set_type("leather");
    set_limbs( ({ "torso" }) );
    set_ac(2);
    set_size(3);
}
