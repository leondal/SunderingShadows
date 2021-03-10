inherit "/std/armour";

void create() {
    ::create();
    set_name("helm");
    set("id", ({ "helm", "chain", "coif", "helmet", "chain coif" }) );
    set("short", "a chain coif");
    set("long", "This is a decorative light chain coif.");
    set_weight(10);
    set("value", 30);
    set_type("leather");
    set_limbs( ({"neck"}) );
    set_ac(1);
}
