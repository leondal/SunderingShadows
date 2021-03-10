inherit "/std/armour";

void create() {
    ::create();
    set_name("chain");
    set("id", ({ "chain", "armor", "chain mail","mail" }) );
    set("short", "A suit of chain mail");
    set("long", 
	"This armor is made of interlocking metal rings. It is always "
	"worn with a layer of quilted fabric underneath, to prevent "
	"painful chafing and to cushion the impact of blows. Several "
	"layers of mail are normally hung over vital areas. The links "
        "yield easily to blows, absorbing some of the shock. Most of "
	"the weight is carried on the shoulders, and it is uncomfortable "
	"to wear for long periods of time."
       );
    set_weight(40);
    set("value", 75);
    set_type("chain");
    set_limbs( ({ "torso" }) );
    set_ac(5);
}
int extra_armor(string str){
	if(!str) return 0;
	write("passed");
	return 1;
}
