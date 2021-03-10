inherit "/std/armour";

void create() {
    ::create();
    set_name("helm");
    set("id", ({ "helm", "chain", "coif", "helmet", "chain coif" }) );
    set("short", "a chain coif");
    set("long", "This is a decorative light chain coif.");
    set_weight(10);
    set("value", 30);
set_type("armour");
    set_limbs( ({ "head" }) );
    set_ac(1);
}
