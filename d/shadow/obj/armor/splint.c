inherit "/std/armour";

void create() {
    ::create();
    set_name("splint");
    set("id", ({ "splint","armor", "splint mail","mail" }) );
    set("short", "A suit of splint mail armor");
    set("long", 
	"This armor is made of narrow verticle strips, riveted to a " 
	"backing of leather and cloth padding. The joints are protected "
	"by chainmail."
       );
    set_weight(40);
    set("value", 80);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    set_ac(6);
}
