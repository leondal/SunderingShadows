inherit "/std/armour";

void create() {
    ::create();
    set_name("body shield");
    set("id", ({ "shield","body shield", "body" }) );
    set("short", "A body shield");
    set("long", 
	"This shield is over half the height of an adult human.  It is made of a single "
    "piece of thin metal shaped into an oval.  A metal arm bar and straps have been "
    "riveted to the back"
       );
    set_weight(14);
    set("value", 10);
    set_type("shield");
    set_limbs( ({ "right hand" }) );
    set_ac(1);
    set_armor_prof("shield");
    set_block_chance(30);
    set_item_bonus("shieldMiss",30); // setting these equal to the old block chance since it's a replacement
}

int is_metal() { return 1; }
