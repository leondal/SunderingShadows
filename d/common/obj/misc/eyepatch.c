//created by Styx for all the poor souls who are losing eyes to torture  2/02.

inherit "/std/armour";

void create() {
    ::create();
    set_name("eye patch");
    set("id", ({ "eye patch", "patch", "eyepatch" }) );
    set("short", "An eye patch");
    set("long", "This is a simple cloth eye patch that protects injured eyes "
        "or can simply cover a missing one." );
    set_weight(1);
    set("value", 4);
    set_type("ring");
    set_limbs( ({ "head" }) );
    set_ac(0);
    set_property("repairtype",({ "tailor" }));
}
