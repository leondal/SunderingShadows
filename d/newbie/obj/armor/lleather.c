inherit "/std/armour";

int i;

void create() {
    ::create();
    set_name("leather");
    set_id(({ "leather","leather armor", "armor"}));
    set_short("A suit of leather armor");
    set_weight(15);
    set_value(8);
    set_type("leather");
    set_limbs(({"torso"}));
    set_ac(2);
    set_size(3);
    if(!i) i = 1+random(3);
    switch(i){
    case 1:
        set_long("This armor is made of a hardened piece of black leather. It is stiff but leaves your joints free for movement.");
        break;
    case 2:
        set_long("Brown and black pieces of leather are mixed together with cloth holding them together around the joints. Pieces of the boiled hide cover arms, shoulders, and chest.");
        break;
    case 3:
        set_long("A large piece of tan-colored leather has been formed to make this armor.");
        break;
    }
}

