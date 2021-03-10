inherit "/std/armour";

void create() {
    ::create();
    set_name("field");
    set("id", ({ "field", "armor", "filed plate","plate" }) );
    set("short", "A suit of Filed plate armor");
    set("long", 
	"This is the most common version of full plate armor, consisting "
	"of shaped and fitted metal plates rivited and interlocked to cover "
	"the entire body. It includes gauntlets, boots and a visored helm. "
	"A thick layer of padding must be worn underneath. However, the "
	"weight of the suit is well distributed over the whole body. Such "
	"armor hampers movement only slightly."
       );
    set_weight(60);
    set("value", 2000);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    set_ac(8);
}
