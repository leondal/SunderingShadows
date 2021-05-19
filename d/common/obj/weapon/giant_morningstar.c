//giant weapon by Circe 6/14/05
#include <std.h>
inherit WEAPON;

void create() {
    ::create();
    set_id(({"morningstar","morning star","star","giant morning star"}));
    set_name("giant morning star");
    set_short("A giant morning star");
    set_long(
        "Like its much smaller cousin, this morning star features a "+
        "spiked ball attached to a chain.  The oak shaft of the star "+
        "is a four and a half feet in length, making it impractical for any "+
        "but the giant races, although some might be able to wield it in "+
        "two hands.  It looks to be quite a vicious weapon."
    );
    set_weight(18);
    set_size(3);
    set_value(25);
    set_wc(2,6);
    set_large_wc(2,6);
    set_type("bludgeoning");
    set_prof_type("mace");
    set_weapon_speed(7);
    set_weapon_prof("simple");
    set_critical_threat_range(1);
    set_critical_hit_multiplier(2);
    set_damage_type("bludgeoning");
    set_property("repairtype",({"weaponsmith"}));
}