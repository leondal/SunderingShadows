// shieldcrude.c  crude shield for newbieland

inherit "/d/common/obj/armour/shield.c";

void create() {
    ::create();
	set_name("crude shield");
    set("id", ({ "shield","crude shield" }) );
    set("short", "A crude shield");
    set("long", 
        "This crude shield is made of leather wrapped over wood.  The wood has been crudely carved out into an oval shape about two foot at it's widest and two inches thick.  Leather straps are attached on the inside for the user to lash it to their arm."
       );
    set_weight(20);
    set("value", 5);
    set_type("shield");
	set_limbs( ({ "right hand" }) );
    set_ac(1);
}
