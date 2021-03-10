// fixed wear/unwear to use ETO & added obvious short - last change was 11/98  *Styx* 8/2003

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
    set_name("hand of tranquility");
    set_id(({ "hand", "hand of tranquility" }));
    set_obvious_short("%^RESET%^%^GREEN%^mummified hand%^RESET%^");
    set_short("%^RESET%^%^GREEN%^Hand of tranquility%^RESET%^");
    set_long("%^GREEN%^"
             "This petrified hand is covered in a green moss. It is very soothing to look upon "
             "and the hand gives off a magical aura. Long wooden spikes extend from the hand. "
             "The inside of the hand is hollowed out so it may be wielded by allowing it to cover ones own "
             "hand."
             "%^RESET%^"
             );
    set_value(1000);
    set_property("enchantment", 3);
    set_wield((: TO, "extra_wield" :));
    set_unwield((: TO, "extra_unwield" :));
    set_hit((: TO, "extra_hit" :));
    uses = 10;
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
    if ((int)ETO->query_alignment() != 2 &&
        (int)ETO->query_alignment() != 4 &&
        (int)ETO->query_alignment() != 5 &&
        (int)ETO->query_alignment() != 6 &&
        (int)ETO->query_alignment() != 8) {
        write("You lack the inner tranquility to utilize this item!");
        return 0;
    }
    write("%^GREEN%^Visions of nature and traquility fill your mind!%^RESET%^");
    tell_room(environment(ETO), "%^GREEN%^" + ETOQCN +
              "'s face transforms into the visage of tranquility!"
              "%^RESET%^", ETO);
    return 1;
}

int extra_unwield()
{
    write("%^GREEN%^"
          "You slowly peel the hand of tranquility off of your own apendage."
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
    if ((int)vic->query_alignment() == 1 ||
        (int)vic->query_alignment() == 3 ||
        (int)vic->query_alignment() == 7 ||
        (int)vic->query_alignment() == 9) {
        message("my_action", "%^GREEN%^"
                "The tranquility of the hand is delivered into "
                + vic->query_cap_name() +
                "!\n"
                + vic->query_cap_name() + " stops moving as the traquility seizes "
                + vic->query_possessive() + " soul!%^RESET%^"
                , ETO);
        message("other_action", "%^GREEN%^"
                + ETO->query_cap_name() +
                " delivers the tranquility of the hand into "
                + vic->query_cap_name() +
                "'s soul!\n"
                + vic->query_cap_name() + " stops moving as the tranquility seizes "
                + vic->query_possessive() + " soul!%^RESET%^"
                , environment(vic), (({ ETO, vic })));
        message("my_action", "%^GREEN%^"
                + ETO->query_cap_name() +
                " delivers the tranquility of the hand into your soul!\n"
                "You stop moving as the tranquility seizes your "
                " soul!%^RESET%^"
                , vic);
        dam = (int)ETO->query_level();
        dam = random(dam) + (dam / 2);
        dam = dam + 10;
        vic->set_paralyzed(dam, "%^GREEN%^Your body is seized with inner tranquility!");
        uses = uses - 1;
        dam = 1;
        if (uses < 1) {
            write("After delivering the last blow, the hand of tranquility vanishes!");
            TO->remove();
        }
    } else {
        dam = 0;
    }
    return dam;
}
