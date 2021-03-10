#include <std.h>

inherit "/d/common/obj/weapon/lance.c";

void create()
{
    ::create();
    set_name("medium horse lance");
    set_id(({"lance","medium horse lance", "medium lance"}));
    set_short("medium horse lance");
    set_long("This is a medium horse lance. It is an effective weapon with which to charge an opponent.");
    set_weight(10);
    set("value",10);
    set_wc(1,8);
    set_large_wc(1,8);
    set_size(2);
    set_type("piercing");
    set_prof_type("lance");
    set_property("lance",1);
    set_hit((:TO,"check":));
    set_weapon_prof("martial");
    set_property("repairtype",({"woodwork"}));
   set_critical_threat_range(1);
   set_critical_hit_multiplier(3);
   set_damage_type("piercing");
}
