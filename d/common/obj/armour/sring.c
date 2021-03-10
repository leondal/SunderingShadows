inherit "/d/common/obj/armour/ring";

void create() {
    ::create();
    //set_name("sringmail");
    //set("id", ({ "ring","armor", "ring mail","mail" }) );
    set_short("A small suit of ring mail armor");
    //set("long", 
    //  "This armor is an early, and less effective version of chain mail " 
    //  "in which metal rings are sewn directly to leather backing, instead "
    //  "of being interlaced. "
    //);
    set_size(1);
    //set_weight(30);
   // set("value", 100);
   // set_type("armour");
   // set_limbs( ({ "torso" }) );
   // set_ac(3);
}

int is_metal() { return 1; }