//seija weapon
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
    ::create();
    set_name("%^BOLD%^%^BLUE%^Flail of the El%^RED%^e%^BLUE%^m%^YELLOW%^e%^BLUE%^nts%^RESET%^");
    set_short("%^BOLD%^%^WHITE%^cryst%^RESET%^a%^BOLD%^ll%^RESET%^i%^BOLD%^ne fl%^RESET%^a%^BOLD%^il%^RESET%^");
    set_id(({ "flail", "flail of the elements", "weapon" }));
    set_long("%^RESET%^The entirety of this weapon - the handle, chain, and head - are crafted from fine %^BOLD%^%^WHITE%^crystal%^RESET%^.  Within that crystal the four primordial elements - %^ORANGE%^earth%^RESET%^, %^BOLD%^air%^RESET%^, %^BOLD%^%^RED%^fire%^RESET%^, and %^BOLD%^%^BLUE%^water %^RESET%^- dance and entertwine in perfect harmony.");
   set_damage_type("bludgeoning");
    set_value(0);
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
        tell_room(room, "%^BOLD%^%^BLUE%^A blast of primordial %^RED%^e%^BLUE%^l%^YELLOW%^e%^BLUE%^m%^WHITE%^e%^BLUE%^nt%^RESET%^%^ORANGE%^a%^BLUE%^l energy %^BOLD%^%^BLUE%^from " + player->query_name() + "'s flail leaps forth and strikes " + targ->QCN + "!%^RESET%^", ({ ETO, targ }));
        tell_object(player, "%^BOLD%^%^BLUE%^A blast of primordial %^RED%^e%^BLUE%^l%^YELLOW%^e%^BLUE%^m%^WHITE%^e%^BLUE%^nt%^RESET%^%^ORANGE%^a%^BLUE%^l energy %^BOLD%^%^BLUE%^from your flail leaps forth and strikes " + targ->QCN + "!%^RESET%^");
        tell_object(targ, "%^BOLD%^%^BLUE%^A blast of primordial %^RED%^e%^BLUE%^l%^YELLOW%^e%^BLUE%^m%^WHITE%^e%^BLUE%^nt%^RESET%^%^ORANGE%^a%^BLUE%^l energy %^BOLD%^%^BLUE%^from " + player->query_name() + "'s flail leaps forth and strikes you!%^RESET%^");

        return random(4)+8;
    }
}
