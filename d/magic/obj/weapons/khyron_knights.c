//khyron weapon for knights, scimitar
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
    ::create();
    set_name("%^BOLD%^%^BLACK%^Stormreaver's Scimitar%^RESET%^");
    set_short("%^BOLD%^%^BLACK%^blackened scimitar bathed in %^YELLOW%^l%^WHITE%^i%^YELLOW%^ghtn%^WHITE%^i%^YELLOW%^ng%^RESET%^");
    set_id(({ "godweapon", "divine weapon", "scimitar", "lightning scimitar", "stormreavers scimitar", "weapon" }));
    set_long("%^BOLD%^%^BLACK%^This scimitar has been fashioned from blackened adamantium.  The weapon, approximately three feet long, curves inward before coming to a %^RESET%^%^RED%^wicked point%^BOLD%^%^BLACK%^.  The blade itself is %^BOLD%^%^WHITE%^razor sharp%^BOLD%^%^BLACK%^, and is wreathed in living %^YELLOW%^el%^WHITE%^e%^YELLOW%^ctr%^WHITE%^i%^YELLOW%^c%^WHITE%^i%^YELLOW%^ty %^BOLD%^%^BLACK%^that %^BOLD%^%^RED%^pops %^BLACK%^and %^WHITE%^crackles %^BLACK%^its way along the weapon.%^RESET%^");
    set_value(0);
        set_damage_type("slashing");
    set_hit((: this_object(), "hit_func" :));
}

int hit_func(object targ)
{
    object player, room;

    player = environment(this_object());
    player && room = environment(player);

    if(!player || !room)
        return;

    targ = player->query_current_attacker();

    if (!objectp(targ))
        return 1;

    if (!random(10)) {
        tell_room(room, "%^BOLD%^%^BLACK%^A blast of %^YELLOW%^l%^WHITE%^i%^YELLOW%^ghtn%^WHITE%^i%^YELLOW%^ng %^BOLD%^%^BLACK%^from " + player->query_name() + "'s scimitar shoots forth and scorches " + targ->QCN + "!%^RESET%^", ({ player, targ }));
        tell_object(player, "%^BOLD%^%^BLACK%^A blast of %^YELLOW%^l%^WHITE%^i%^YELLOW%^ghtn%^WHITE%^i%^YELLOW%^ng %^BOLD%^%^BLACK%^from your scimitar shoots forth and scorches " + targ->QCN + "!%^RESET%^");
        tell_object(targ, "%^BOLD%^%^BLACK%^A blast of %^YELLOW%^l%^WHITE%^i%^YELLOW%^ghtn%^WHITE%^i%^YELLOW%^ng %^BOLD%^%^BLACK%^from " + player->query_name() + "'s scimitar shoots forth and scorches you!%^RESET%^");

        return random(4)+8;
    }
}
