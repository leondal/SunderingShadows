#include <std.h>

inherit "/d/common/obj/weapon/lance.c";

void create()
{
    ::create();
    set_name("light horse lance");
    set_id(({"lance","light horse lance", "light lance"}));
    set_short("light horse lance");
    set_long("This is a light horse lance. It is an effective weapon with which to charge an opponent.");
    set_weight(5);
    set("value",6);
    set_wc(1,6);
    set_large_wc(1,6);
    set_size(1);
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
