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
    set_size(1);
    if(!i) i = 1+random(3);
    switch(i){
    case 1:
        set_long("This armor is little more than cloth sewn over a layer of quilted material. Its protection will be slight, but better than nothing.");
        break;
    case 2:
        set_long("Pieces of cloth and small animal furs have been stitched together to form this armor. It will provide some protection, though will wear out quickly.");
        break;
    case 3:
        set_long("Showing little wear and dirt, this is a rare find as far as used padded armor goes. A single gash through the fabric and a dark stain seem to be the only signs of use...");
        break;
    }
}
