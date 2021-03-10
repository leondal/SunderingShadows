inherit "/std/armour";

void create() {
    ::create();
    set_name("coif");
   set("id", ({ "coif", "chain coif", "helmet", "helm" }) );
   set("short", "A chain coif");
    set("long", "This is a helmet made from chain mail, which fits snugly around your head.");
    set_weight(10);
    set("value", 30);
    set_type("clothing");
    set_limbs( ({ "head" }) );
    set_ac(1);
}

