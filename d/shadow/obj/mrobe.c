inherit "/std/armour";

void create() {
    ::create();
    set_name("robe");
    set("id", ({ "robe","cloak", "armor" }) );
set_short("Robe");
    set("long", 
"This is a simple looking robe. At Closer inspection "
" You notice it is made from a thin, lightweight material."
       );
    set_weight(10);
set("value",1000);
    set_type("clothing");
    set_limbs( ({ "torso" }) );
set_ac(5);
}
