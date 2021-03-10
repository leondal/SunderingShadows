#include <std.h>
inherit "/d/common/obj/weapon/hhlance.c";

void create()
{
    ::create();
    set_name("bone lance");
    set_id(({ "lance", "bone lance", "Bone Lance" }));
    set_short("%^WHITE%^%^BOLD%^Bone Lance%^RESET%^");
    set_long("%^BOLD%^This lance has been crafted from a long, " +
             "thick bone of some beast.  It has been enchanted to keep " +
             "it from bending or breaking easily, although the thickness " +
             "of the bone would probably prevent that as well. The lance " +
             "is smooth and nicely balanced.");
    set_value(100);
    set_hit((: TO, "check" :));
    if (!random(6)) {
        set_property("enchantment", 1);
    }
}

int check(object targ)
{
    if (!objectp(ETO)) {
        return 0;
    }
    if (!ETO->query_in_vehicle() || !objectp(ETO->query_in_vehicle())) {
        ETO->force_me("drop lance");
    }
    return 0;

    if (!random(5)) {
        tell_object(ETO, "%^BOLD%^%^BLACK%^With a smug satisfaction, you drive " +
                    "your lance into " + targ->QCN + "!");
        tell_room(environment(ETO), "%^BOLD%^%^BLACK%^" + ETOQCN + " drives" +
                  " " + ETO->QP + " bone lance deeply into " + targ->QCN + ".", ({ ETO, targ }));
        tell_object(targ, "%^BOLD%^%^BLACK%^" + ETOQCN + " drives " + ETO->QP + "" +
                    " bone lance deeply into you!");
        targ->do_damage(random(4) + 4);
        return 1;
    }
}

int query_size()
{
    if (objectp(ETO) && living(ETO)) {
        return (int)ETO->query_size();
    }
    return ::query_size();
}
