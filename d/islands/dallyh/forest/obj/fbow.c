#include <std.h>

inherit "/d/common/obj/lrweapon/longbow";

void create(){
    ::create();

    set_lore("%^BOLD%^%^GREEN%^This weapon is made by amazons from islands losts in Saakurine sea. Although being made with no magic, wood used to craft these bows long has been exposed to the wild magic of the islands.");
    set_property("enchantment", 4);
    set_property("lore difficulty", 30);
    set_value(1000);
    set_item_bonus("damage bonus", 2);
    set_item_bonus("attack bonus", 2);
    set_item_bonus("athletics", 2);
    set_id(({"emerald longbow", "longbow", "Living Bow","living bow", "bow", "emerald bow"}) );

    set_obvious_short("%^GREEN%^em%^BOLD%^er%^RESET%^%^GREEN%^a%^BOLD%^ld %^BLACK%^l%^GREEN%^on%^WHITE%^g%^GREEN%^b%^RESET%^%^GREEN%^o%^BOLD%^%^BLACK%^w%^RESET%^");
    set_short("%^BOLD%^%^BLACK%^L%^RESET%^%^GREEN%^i%^BOLD%^v%^RESET%^%^GREEN%^i%^BOLD%^n%^WHITE%^g %^GREEN%^B%^RESET%^%^GREEN%^o%^BOLD%^w%^RESET%^");
    set_long("%^BOLD%^%^GREEN%^This long bow is made out of several pieces of wood, all in bright green color. It appears moist on the touch, as if it was a living plant. Instead of a string thin vine connects its ends. Hard to draw, it is apparent this particular weapon is either for war of for a big game.");

    set_wield((:TO, "wield_func":));
    set_lrhit((:TO, "extra_lrhit":));
}

int wield_func()
{
    tell_object(ETO,"%^BOLD%^%^GREEN%^As you grip the bow you feel the bow is a living plant.");
    return 1;
}

int extra_lrhit(object targ)
{
    if (!objectp(ETO)) {
        return 0;
    }

    targ = ETO->query_current_attacker();

    if (!objectp(targ)) {
        return 0;
    }

    if (!random(3)) {
        switch(random(10))
        {
        case 0..7:
            tell_room(EETO, "%^BOLD%^%^GREEN%^" + ETO->QCN + " %^GREEN%^o%^BOLD%^v%^RESET%^%^GREEN%^e%^BOLD%^r%^WHITE%^d%^GREEN%^r%^RESET%^%^GREEN%^a%^BOLD%^ws the %^BLACK%^b%^GREEN%^ow, launching a l%^WHITE%^i%^GREEN%^ght%^RESET%^%^GREEN%^n%^BOLD%^i%^RESET%^%^GREEN%^n%^BOLD%^%^BLACK%^g %^GREEN%^fast arrow!%^RESET%^");
            targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(1, 12), "piercing");
            break;
        case 8..9:
            tell_room(EETO, "%^BOLD%^%^GREEN%^" + ETO->QCN + " %^BOLD%^%^GREEN%^launches several pr%^RESET%^%^GREEN%^e%^BOLD%^c%^RESET%^%^GREEN%^i%^BOLD%^s%^RESET%^%^GREEN%^e %^BOLD%^hits, st%^WHITE%^u%^GREEN%^nn%^WHITE%^i%^GREEN%^n%^BLACK%^g%^BOLD%^%^GREEN%^ " + ETO->QP + " enemy!");
            targ->set_paralyzed(roll_dice(1, 3) * 4, "%^BOLD%^%^GREEN%^You're trying to compose yourself after being hit with a volley!");
            break;
        }
    }
}
