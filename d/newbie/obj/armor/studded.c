inherit "/d/common/obj/armour/studded.c";

int i;

void create() {
    ::create();
    set_name("studded");
    set_id(({ "leather","leather armor", "studded", "studded leather", "studded leather armor", "armor"}));
    set_short("A suit of studded leather armor");
    set_weight(20);
    set_value(25);
    set_type("leather");
    set_limbs(({"torso"}));
    set_ac(3);
    set_size(2);
    if(!i) i = 1+random(3);
    switch(i){
    case 1:
        set_long("Rounded and smoothed pieces of metal have been attached to a soft leather backing to form this armor.");
        break;
    case 2:
        set_long("A sturdy piece of heavy cloth has had rivets driven through it, forming a flexible barrier to oncoming blows.");
        break;
    case 3:
        set_long("Small pieces of metal are closely sewn onto smooth leather, providing increased protection and maneuverability from plain leather armor.");
        break;
    }
}

