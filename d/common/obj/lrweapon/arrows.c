#include <std.h>

inherit "/std/ammo";

create()
{
    ::create();
    set_id(({ "arrows", "quiver", "missiles", "shortbow arrow", "shortbow arrows" }));
    set_name("arrows");
    set_short("A bundle of arrows");
    set_long("This bundle is bristling with arrows " +
             "sized for a short bow.  It looks like you could <count " +
             "arrows> to find out how many are in it.  You could also " +
             "<take # from arrows> to separate them or <combine arrows " +
             "with arrows> if you had another.");
    set_shots(20);
    set_wc(1, 6);
    set_large_wc(1, 6);
    set_ammo_type("shortbow arrow");
    set_property("repairtype", ({ "woodwork" }));
}
int is_arrows()
{
    return 1;
}
