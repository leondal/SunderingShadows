//seija weapon
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
    ::create();
    set_name("%^BOLD%^%^BLUE%^El%^RED%^e%^BLUE%^m%^YELLOW%^e%^BLUE%^nt%^RESET%^%^ORANGE%^a%^BOLD%^%^BLUE%^l%^WHITE%^i%^BLUE%^st's Sh%^CYAN%^o%^BLUE%^rtst%^RED%^a%^BLUE%^ff%^RESET%^");
    set_short("%^BOLD%^%^BLUE%^shortstaff topped with a tear-drop shaped %^BOLD%^%^WHITE%^c%^RESET%^r%^BOLD%^y%^RESET%^s%^BOLD%^t%^RESET%^a%^BOLD%^l%^RESET%^");
    set_id(({ "staff", "shortstaff", "elementalist's shortstaff", "weapon" }));
    set_long("%^RESET%^This shortstaff is just under four feet in length and is made fron fine, lightly stained %^RESET%^ORANGE%^ash%^RESET%^.  It is relatively unadorned aside from the tear-drop shaped %^BOLD%^%^WHITE%^c%^RESET%^r%^BOLD%^y%^RESET%^s%^BOLD%^t%^RESET%^a%^BOLD%^l %^RESET%^mounted atop it.  Within that crystal the four primordial elements - %^ORANGE%^earth%^RESET%^, %^BOLD%^air%^RESET%^, %^BOLD%^%^RED%^fire%^RESET%^, and %^BOLD%^%^BLUE%^water %^RESET%^- dance and entertwine in perfect harmony.");
    set_value(0);
    set_damage_type("bludgeoning");
    set_hit((: TO, "hit_func" :));
}

int hit_func(object targ)
{
    object room, player;

    player = environment(this_object());
    player && room = environment(player);

    if(!player || !room || !targ)
        return 1;

    if (!random(10)) {
        tell_room(room, "%^BOLD%^%^BLUE%^A blast of primordial %^RED%^e%^BLUE%^l%^YELLOW%^e%^BLUE%^m%^WHITE%^e%^BLUE%^nt%^RESET%^%^ORANGE%^a%^BLUE%^l energy %^BOLD%^%^BLUE%^from " + player->query_name() + "'s staff leaps forth and strikes " + targ->QCN + "!%^RESET%^", ({ player, targ }));
        tell_object(player, "%^BOLD%^%^BLUE%^A blast of primordial %^RED%^e%^BLUE%^l%^YELLOW%^e%^BLUE%^m%^WHITE%^e%^BLUE%^nt%^RESET%^%^ORANGE%^a%^BLUE%^l energy %^BOLD%^%^BLUE%^from your staff leaps forth and strikes " + targ->QCN + "!%^RESET%^");
        tell_object(targ, "%^BOLD%^%^BLUE%^A blast of primordial %^RED%^e%^BLUE%^l%^YELLOW%^e%^BLUE%^m%^WHITE%^e%^BLUE%^nt%^RESET%^%^ORANGE%^a%^BLUE%^l energy %^BOLD%^%^BLUE%^from " + player->query_name() + "'s staff leaps forth and strikes you!%^RESET%^");

        return random(4)+8;
    }
}
