inherit "/std/armour";

void create() {
    ::create();
    set_name("mshield");
    set("id", ({ "shield","medium shield", "medium" }) );
    set("short", "A body shield.");
    set("long", 
	"This shield is made of leather, hardened in boiling oil and then "
	"shaped into an oval shield."
       );
    set_weight(10);
    set("value", 7);
    set_type("shield");
    set_limbs( ({ "right hand","left hand" }) );
    set_ac(1);
}
