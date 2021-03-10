inherit "/std/armour";

void create() {
    ::create();
    set_name("small shield");
    set("id", ({ "shield","small shield", "small", "sshield" }) );
    set("short", "A small shield");
    set_long("This shield has been fashioned by bending a layer of metal around "
        "a wooden frame in a circular shape.  The frame has straps for the wearer "
        "to loop around the arm in the back.");
    set_weight(5);
    set("value", 3);
    set_type("shield");
    set_limbs(({"right hand"}));
    set_ac(1);
    set_armor_prof("shield");
    set_block_chance(20);
    set_item_bonus("shieldMiss",20); // setting these equal to the old block chance since it's a replacement
}

int is_metal() { return 1; }