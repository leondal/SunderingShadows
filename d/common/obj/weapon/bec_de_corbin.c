#include <std.h>
inherit "/d/common/obj/weapon/polearm_piercing.c";

void create()
{
    ::create();
    set_id(({ "bec de corbin", "pole arm", "polearm", "corbin", }));
    set_name("bec de corbin");
    set_short("Bec de corbin");
    set_long("This long pole arm has a spear tip with a spike in the shape of a crows beak jutting out from the base of the point.  On the reverse side of the beak a clawed hammer gives extra weight to the weapon for the crushing blows it would need to drive it through plate armor.");
}
