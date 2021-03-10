inherit "/std/armour";

int i;

void create() {
    ::create();
    set_name("padded");
    set_id(({ "padded","padded armor", "armor"}));
    set_short("A suit of padded armor");
    set_weight(10);
    set_value(5);
    set_type("leather");
    set_limbs(({"torso"}));
    set_ac(2);
    set_size(2);
    if(!i) i = 1+random(3);
    switch(i){
    case 1:
        set_long("The random pieces of cloth and quick stitching indicates that this armor was probably made for a farmer or villager called into battle unexpectedly.");
        break;
    case 2:
        set_long("This armor was most likely used by commoners in the service of a lord, judging by the careful stitching, colorful design, and good quality cloth used.");
        break;
    case 3:
        set_long( "Worn and torn, repaired over and over, this armor has seen better days. Someone used it well, though, and it should provide some protection.");
        break;
    }
}

