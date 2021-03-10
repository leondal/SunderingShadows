inherit "/std/armour";

void create() {
    ::create();
set_name("body shield");
    set("id", ({ "shield","body shield", "body" }) );
    set("short", "A body shield");
    set("long", 
	"This shield is made of leather, hardened in boiling oil and then "
	"shaped into an oval shield."
       );
    set_weight(15);
    set("value", 10);
    set_type("shield");
set_limbs( ({ "right hand" }) );
    set_ac(1);
}
