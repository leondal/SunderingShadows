inherit "/std/armour";

void create() {
    ::create();
    set_name("plate");
    set("id", ({ "plate","armor", "plate mail","mail" }) );
    set("short", "A suit of plate mail armor");
    set("long", 
	"This armor is a combination of chain or brigadine with metal " 
	"platescovering the vital areas. Theweight is distributed over "
	"the whole body and the whole thing is held together by buckles "
	"and straps. This is the most common frorm of heavy armor."
       );
    set_weight(50);
    set("value", 600);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    set_ac(7);
}
