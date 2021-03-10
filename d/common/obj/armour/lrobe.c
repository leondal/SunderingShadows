//changed to inherit /armour/robe.c 
//after the update to that file - Cythera 4/05
inherit "/d/common/obj/armour/robe.c";

void create() {
    ::create();
    set_id(({"robe","large robe","lrobe"}));
    set_size(3);
}

int is_metal() { return 0; }