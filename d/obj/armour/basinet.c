inherit "/std/armour";

void create() {
    ::create();
    set_name("basinet");
    set("id", ({ "helm", "helmet", "basinet" }) );
    set("short", "Basinet helm");
    set("long", "This is a Basinet helm. Smaller and weaker then the great helm.");
    set_weight(5);
    set("value", 8);
    set_type("clothing");
    set_limbs( ({ "head" }) );
    set_ac(1);
}

