#include <std.h>
#include <magic.h> // for ROUND_LENGTH

inherit "std/weapon";

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

int check(object targ)
{
    string myname = (string)TO->query_name();
    if(!objectp(ETO)) return 0;
    if(sizeof(ETO->query_wielded()) > 1) { // prevention of dual-wielding lances, since it's stupid!
        ETO->force_me("unwield "+myname);
        ETO->remove_property("disarm time");
        ETO->set_property("disarm time",time() + ROUND_LENGTH); // one round disarm
    }
    /*
    if(!ETO->query_in_vehicle() || !objectp(ETO->query_in_vehicle())) {
        ETO->force_me("unwield "+myname);
        ETO->remove_property("disarm time");
        ETO->set_property("disarm time",time() + ROUND_LENGTH); // one round disarm
    }*/
    return 0;
}

int query_size()
{
    if(objectp(ETO)&&living(ETO))
    {
        return (int)ETO->query_size();
    }
    return ::query_size();
}
