inherit "/std/armour";

void create() {
    ::create();
    set_name("bronze mesh");
    set("id", ({ "bronze mesh", "armor", "bronze mesh armor","armour" }) );
    set("short", "A suit of bronze mesh armor");
    set_long(
      "This armor is comprised of a sturdy metal breastplate and backplate and several thin bronze bands wrapped in a fine bronze mesh.  It provides adequate protection in the upper body."
    );
    set_weight(40);
    set("value", 240);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    set_ac(7);
    set_property("magic item",({"illuminate","extra_armor"}) );
}
int extra_armor(string str){
    if(!str) return 0;
    write("passed");
    return 1;
}
