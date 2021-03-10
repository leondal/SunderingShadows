inherit "/std/armour";

void create() {
    ::create();
    set_name("helm");
    set("id", ({ "helm", "helmet", "great helm" }) );
    set("short", "Great helm");
    set("long", "This is a Great helm. ");
    set_weight(10);
    set("value", 30);
    set_type("clothing");
    set_limbs( ({ "head" }) );
    set_ac(0);
}

