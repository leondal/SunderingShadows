inherit "/std/armour";

void create() {
    ::create();
    set_name("helm");
    set("id", ({ "helm", "helmet", "great helm" }) );
    set("short", "Great helm");
    set("long", "This is a Great helm. ");
    set_weight(10);
    set("value", 30);
set_type("armour");
    set_limbs( ({ "head" }) );
    set_ac(1);
    set_remove("The helm slips off your head, easily.");
    set("read", "a nice helmut");
}

