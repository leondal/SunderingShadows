// hooded cloak by *Styx* to shade eyes for light sensitivity

inherit "/d/common/obj/armour/cloak_hooded";

void create() {
    ::create();
    set_size(3);
}

int is_metal() { return 0; }
