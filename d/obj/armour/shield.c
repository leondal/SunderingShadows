inherit "/std/armour";

void create() {
    ::create();
    set_name("shield");
    set("id", ({ "shield","body shield", "body" }) );
    set("short", "A body shield");
    set("long", 
	"This shield is made of leather, hardened in boiling oil and then "
	"shaped into an oval shield."
       );
    set_weight(15);
    set("value", 10);
    set_type("shield");
    set_limbs( ({ "right hand","left hand" }) );
    set_ac(1);
}
