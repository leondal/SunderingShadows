// fixed wear/unwear to use ETO, added obvious short-last change was 11/98  *Styx* 8/2003

#include <std.h>
inherit "/d/common/obj/weapon/claw.c";
string owner;
int uses;
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
    set_name("hand of justice");
    set_id(({ "hand", "hand of justice" }));
    set_obvious_short("%^RESET%^%^BLUE%^Mummified hand%^RESET%^");
    set_short("%^RESET%^%^BLUE%^Hand of justice%^RESET%^");
    set_long("%^BLUE%^"
             "This petrified hand is surrounded by the steady light of justice. The hand is made of pure steel. "
             "and gives off a magical aura. Long steel spikes extend from the fingers of the hand. "
             "The inside of the hand is hollowed out so it may be wielded by allowing it to cover ones own "
             "hand.%^RESET%^"
             );
    set_value(1000);
    set_type("bludgeoning");
    set_property("enchantment", 3);
    set_wield((: TO, "extra_wield" :));
    set_unwield((: TO, "extra_unwield" :));
    set_hit((: TO, "extra_hit" :));
    uses = 4;
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
        (int)ETO->query_alignment() != 2 &&
        (int)ETO->query_alignment() != 3) {
        write("You lack the inner justice to utilize this item!");
        return 0;
    }
    write("%^BLUE%^Visions of law and justice fill your mind!%^RESET%^");
    tell_room(environment(ETO), "%^BLUE%^" + ETOQCN +
              "'s face transforms into the visage of justice!%^RESET%^", ETO);
    return 1;
}

int extra_unwield()
{
    write("%^BLUE%^"
          "You slowly peel the hand of justice off of your own apendage."
          "%^RESET%^"
          );
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
        (int)vic->query_alignment() == 8 ||
        (int)vic->query_alignment() == 7) {
        message("my_action", "%^BLUE%^"
                "The order of law of the hand of justice is delivered into "
                + vic->query_cap_name() +
                "!\n"
                + vic->query_cap_name() + " screams as the chaos within "
                + vic->query_possessive() + " soul is invaded by the lawful energy!%^RESET%^"
                , ETO);
        message("other_action", "%^BLUE%^"
                + ETO->query_cap_name() +
                " delivers the order of law of the hand of justice into "
                + vic->query_cap_name() +
                "'s soul!\n"
                + vic->query_cap_name() + " screams as the chaos within "
                + vic->query_possessive() + " soul is invaded by lawful energy!%^RESET%^"
                , environment(vic), (({ ETO, vic })));
        message("my_action", "%^BLUE%^"
                + ETO->query_cap_name() +
                " delivers the order of law of the hand of justice into your soul!\n"
                "You scream as the chaos within your "
                " soul is invaded by lawful energy!%^RESET%^"
                , vic);
        dam = (int)ETO->query_level();
        dam = random(dam) + (dam / 2);
        uses = uses - 1;
        if (uses < 1) {
            write("After delivering the lawful energy, the hand of justice vanishes!");
            TO->remove();
        }
    } else {
        dam = 0;
    }
    return dam;
}
