#include <std.h>

inherit "/std/ammo";

create()
{
    ::create();
    set_id(({ "arrows", "larrows", "longbow arrows", "longbow arrow", "quiver", "missiles" }));
    set_name("arrows");
    set_short("A bundle of flight arrows");
    set_long("This bundle of flight arrows are" +
             "sized for a longbow.  It looks like you could <count " +
             "arrows> to find out how many are in it.  You could also " +
             "<take # from arrows> to separate them or <combine arrows " +
             "with arrows> if you had another.");
    set_shots(20);
    set_wc(1, 8);
    set_large_wc(1, 8);
    set_ammo_type("longbow arrow");
    set_property("repairtype", ({ "woodwork" }));
}
int is_arrows()
{
    return 1;
}
