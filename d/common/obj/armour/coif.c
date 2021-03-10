inherit "/std/armour";

void create() {
    ::create();
    set_name("helm");
    set("id", ({ "helm", "chain", "coif", "helmet", "chain coif" }) );
    set("short", "a chain coif");
    set("long", "This is a decorative light chain coif.");
    set_weight(6);
    set("value", 30);
    set_type("chain");
    set_limbs( ({ "head" }) );
    set_ac(1);
    set_armor_prof("medium");
}

int is_metal() { return 1; }
