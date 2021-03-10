// fixed wear/unwear to use ETO, added obvious short-last change was 11/98  *Styx* 8/2003

#include <std.h>
inherit "/d/common/obj/weapon/claw.c";
string owner;
void init()
{
    ::init();
    if (interactive(TP) && !owner) {
        owner = TPQN;
    }
}

create()
{
    ::create();
    set_name("hand of god");
    set_id(({ "hand", "hand of god", "hand of goodness" }));
    set_obvious_short("%^YELLOW%^Mummified hand%^RESET%^");
    set_short("%^RESET%^%^YELLOW%^Hand of goodness%^RESET%^");
    set_long("%^YELLOW%^"
             "This petrified hand is surrounded by a holy light and "
             "gives off a magical aura. As you look upon it you can hear angels singing. "
             "The inside of the hand is hollowed out so it may be wielded by "
             "allowing it to cover ones own hand.%^RESET%^"
             );
    set_value(1000);
    set_property("enchantment", 3);
    set_wield((: TO, "extra_wield" :));
    set_unwield((: TO, "extra_unwield" :));
    set_hit((: TO, "extra_hit" :));
}
int extra_wield()
{
    if ((int)ETO->query_level() < 30) {
        write("You cannot control the inner power of the hand and it vanishes!");
        TO->remove();
        return 0;
    }
    if ((string)ETOQN != owner) {
        write("The hand fails to bond with you and vanishes!");
        TO->remove();
        return 0;
    }
    if ((int)ETO->query_alignment() != 1 &&
        (int)ETO->query_alignment() != 4 &&
        (int)ETO->query_alignment() != 7) {
        write("You lack the inner good to utilize this item!");
        return 0;
    }
    write("%^YELLOW%^Visions of holy deeds and angelic power fill your mind!"
          "%^RESET%^");
    tell_room(environment(ETO), "%^YELLOW%^" + ETOQCN +
              "'s face transforms into a visage of pure angelical power!%^RESET%^", ETO);
    return 1;
}

int extra_unwield()
{
    write("%^YELLOW%^You slowly peel the hand of goodness off of your own appendage."
          "%^RESET%^");
    return 1;
}

int extra_hit(object ob)
{
    object vic;
    int dam;
    vic = ETO->query_current_attacker();
    if (random(10) > 1) {
        return 1;
    }
    if ((int)vic->query_alignment() == 9 ||
        (int)vic->query_alignment() == 6 ||
        (int)vic->query_alignment() == 3) {
        message("my_action", "%^YELLOW%^"
                "The angelic power of the hand of goodness is delivered into "
                + vic->query_cap_name() +
                "!\n"
                + vic->query_cap_name() + " screams as the evil within "
                + vic->query_possessive() + " soul is invaded by angelic power!%^RESET%^"
                , ETO);
        message("other_action", "%^YELLOW%^"
                + ETO->query_cap_name() +
                " delivers the angelic power of the hand of goodness into "
                + vic->query_cap_name() +
                "'s soul!\n"
                + vic->query_cap_name() + " screams as the evil within "
                + vic->query_possessive() + " soul is invaded by the angels!%^RESET%^"
                , environment(vic), (({ ETO, vic })));
        message("my_action", "%^YELLOW%^"
                + ETO->query_cap_name() +
                " delivers the angelic power of the hand of goodness into your soul!\n"
                "You scream as the evil within your "
                " soul is invaded by the angels!%^RESET%^"
                , vic);
        dam = (int)ETO->query_stats("strength") +
              (int)ETO->query_stats("wisdom") +
              (int)ETO->query_stats("constitution") +
              (int)ETO->query_level();
        dam = random(dam) + (dam / 2);
        write("After delivering the angelic power, the hand of goodness vanishes!");
        TO->remove();
    } else {
        dam = 0;
    }
    return dam;
}
