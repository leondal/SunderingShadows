//treasure chest for use with /d/common/daemon/randstuff_d.c
//Do not remove ~Circe~ 5/2/08
#include <std.h>

inherit BAG;

void create() {
  ::create();
    set_id(({"chest","large chest","lockable chest","large lockable chest"}));
    set_name("large chest");
    set_short("A large lockable chest");
    set_long("This is a large wooden chest bound with slender iron "+
        "bands and set with a thick iron lock.");
    set_open_long("This is a large wooden chest bound with slender iron "+
        "bands and set with a thick iron lock.\nIt is open.");
    set_closed_long("This is a large wooden chest bound with slender iron "+
        "bands and set with a thick iron lock.\nIt is closed.");
    set_weight(25);
    set_value(10);
    set_max_internal_encumbrance(50);
   set_possible_to_close(1);
}

int is_light_opaque() { return 1;}
