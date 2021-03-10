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
    set_size(3);
    if(!i) i = 1+random(3);
    switch(i){
    case 1:
        set_long("This armor is made of a combination of cloth and furs of unidentifiable origin. It is hot, uncomfortable, and dirty. It offers only slight protection.");
        break;
    case 2:
        set_long("Many layers of cloth have been crudely sewn together to fashion this armor. It will soften the blows somewhat, but not much.");
        break;
    case 3:
        set_long("Once brightly colored scraps of cloth have been stiched together over a layer of padding, creating a primitive but serviceable suit of armor.");
        break;
    }
}

