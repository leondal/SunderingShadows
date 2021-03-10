//changed to inherit /armour/robe.c 
//after the update to that file - Cythera 4/05
inherit "/d/common/obj/armour/robe.c";

void create() {
    ::create();
    set_id(({"robe","small robe","srobe"}));
    set_size(1);
}

int is_metal() { return 0; }