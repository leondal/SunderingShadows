#include <std.h>
#include "../witchlair.h"
inherit "/d/common/obj/weapon/sstaff";

void create()
{
    ::create();
    set_name("shaman's staff");
    set_id(({ "staff", "small staff", "shaman staff",
              "bone staff", "small bone staff" }));
    set_obvious_short("%^WHITE%^a %^BOLD%^s%^RESET%^ma%^BOLD%^"
                      "ll %^RESET%^st%^BOLD%^a%^RESET%^f%^BOLD%^f %^RESET%^of b"
                      "%^BOLD%^o%^RESET%^ne");
    set_short("%^BOLD%^%^WHITE%^S%^BLACK%^t%^WHITE%^aff"
              " %^BLACK%^o%^WHITE%^f T%^BLACK%^h%^WHITE%^e "
              "%^BOLD%^%^WHITE%^Sha%^BLACK%^m%^WHITE%^an%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Formed from the tibia of"
             " a large humanoid, this meter-long staff would easily fit "
             "into the hands of a gnome-size person. Lashed to the bone is "
             "an intact spinal cord, held together by fetid sinew. "
             "Surprisingly, it appears to be very sturdy. A small jawless "
             "skull, likely some sort of feline's, is affixed to one end of "
             "the bone, twin orbs of %^RESET%^%^ORANGE%^a%^YELLOW%^mb"
             "%^RESET%^%^ORANGE%^er %^BOLD%^%^WHITE%^wedged into the eye "
             "sockets. Most of the teeth are still attached, and when "
             "combined with the jagged shards of %^BOLD%^%^BLACK%^ob"
             "%^WHITE%^s%^BLACK%^id%^BLUE%^i%^WHITE%^a%^BLACK%^n "
             "%^WHITE%^attached to the jaw, would leave quite"
             " the nasty wound.%^RESET%^");
    set_lore("%^BOLD%^%^WHITE%^It is common knowledge that "
             "goblinoids and kobolds are all repulsive species, easily capable"
             " of decimating an entire region's resources. What is known to "
             "few outside of these crude cultures is the nature of their "
             "magics, and the enchantment of their unholy artifacts. This is"
             " one such item, passed on to the shamanic leaders of a tribe by "
             "the %^BLACK%^B%^GREEN%^l%^BLACK%^a%^RED%^c%^BLACK%^k"
             " Ha%^GREEN%^n%^BLACK%^d %^WHITE%^himself. The two races"
             ", however, are in violent opposition as to its true origin. "
             "The former believe it is a gift from their patron god "
             "%^RESET%^%^RED%^Maglubiyet%^BOLD%^%^WHITE%^, as reward for"
             " laying waste to the human realms,"
             " while the latter insist it to be granted to the strongest of "
             "kobold chiefs by mighty %^BOLD%^%^RED%^Kurtulmak"
             "%^BOLD%^%^WHITE%^, the first of their kind. Gods only know "
             "how terrible a threat their kind would be to the civilized "
             "world if not for millenia of mutual hatred.%^RESET%^");
    set_value(250);
    set_size(1);
    set_property("lore difficulty", 25);
    set_property("id difficulty", 18);
    set_property("enchantment", 3);
    set_wield((: TO, "wield_func" :));
    set_unwield((: TO, "unwield_func" :));
    set_hit((: TO, "hit_func" :));
}

int wield_func(string str)
{
    if ((int)ETO->query_lowest_level() < 15) {
        tell_object(ETO, "%^BOLD%^%^WHITE%^A brief glow from the"
                    " skull's eye sockets and a ghostly felid %^RESET%^%^GREEN%^h"
                    "%^CYAN%^i%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^s "
                    "%^BOLD%^%^WHITE%^are all it takes to change your mind about "
                    "doing that!");
        tell_room(EETO, "%^BOLD%^%^BLACK%^" + ETO->QCN + " gives their"
                  " staff a wary look before setting it aside.");
        return 0;
    }
    if ((string)ETO->query_race() != "goblin" &&
        (string)ETO->query_race() != "hobgoblin" &&
        (string)ETO->query_race() != "bugbear" &&
        (string)ETO->query_race() != "kobold") {
        tell_room(EETO, "%^BOLD%^%^BLACK%^The staff refuses"
                  " " + ETO->QCN + "'s hand!");
        return 0;
    }
    if ((string)ETO->query_race() == "goblin" ||
        (string)ETO->query_race() == "hobgoblin" ||
        (string)ETO->query_race() == "bugbear") {
        tell_object(ETO, "%^BOLD%^%^GREEN%^You feel the "
                    "%^RESET%^%^RED%^High Chieftain's %^BOLD%^%^GREEN%^approval"
                    " as your hand wraps around the grisly staff.%^RESET%^");
        tell_room(EETO, "%^RESET%^%^GREEN%^A wicked grin crosses "
                  "" + ETO->QCN + "'s face as " + ETO->QS + " takes up the bone staff.",
                  ETO);
        clear_item_bonus();
        set_item_bonus("attack bonus", 1);
        set_item_bonus("fortitude", 1);
        return 1;
    }else {
        if ((string)ETO->query_race() == "kobold") {
            tell_object(ETO, "%^BOLD%^%^RED%^Pride and power "
                        "flow through you. You feel as if %^RESET%^%^ORANGE%^Kurtulmak"
                        " %^BOLD%^%^RED%^himself is smiling upon your prescience!");
            tell_room(EETO, "%^RESET%^%^RED%^A low growl escapes "
                      "" + ETO->QCN + "'s grinning jaws as " + ETO->QS + " takes a grip "
                      "on the staff.", ETO);
            clear_item_bonus();
            set_item_bonus("will", 1);
            set_item_bonus("spell penetration", 1);
            return 1;
        }
    }
}

void unwield_func(string str)
{
    tell_object(ETO, "%^BOLD%^%^BLACK%^You feel as though your"
                " lord's favor is turned elsewhere as you loosen your hold"
                " of the staff...%^RESET%^");
    tell_room(EETO, "%^BOLD%^%^WHITE%^" + ETO->QCN + " looks just"
              " a little deflated as " + ETO->QS + " lets go of the macabre"
              " staff.%^RESET%^", ETO);
    return 1;
}

void hit_func(object vict)
{
    object obj2;
    vict = ETO->query_current_attacker();
    if (!objectp(vict)) {
        return 0;
    }
    if (!random(1000) < 200) {
        switch (random(20)) {
        case 0..12:
            tell_room(EETO, "%^RESET%^%^RED%^" + ETO->QCN + " snarls"
                      " and pulls the staff back, then swings it forward and "
                      "%^BOLD%^%^RED%^rakes %^RESET%^%^RED%^it viciously across"
                      " " + vict->QCN + "'s flesh! You can't help but wince, that "
                      "looked painful!", ({ vict, ETO }));
            tell_object(ETO, "%^RESET%^%^RED%^A sudden "
                        "%^BOLD%^%^RED%^RAGE %^RESET%^%^RED%^overcomes you as you"
                        " bring the staff back with a snarl, then %^BOLD%^%^RED%^r"
                        "ake %^RESET%^%^RED%^the sharp %^BOLD%^%^BLACK%^f"
                        "%^RESET%^%^BLUE%^a%^BOLD%^%^WHITE%^n%^BLACK%^gs "
                        "%^RESET%^%^RED%^of the skull across " + vict->QCN + "'s "
                        "flesh!%^RESET%^");
            tell_object(vict, "%^RESET%^%^RED%^" + ETO->QCN + " snarls"
                        " and pulls the staff back, then swings it forward and "
                        "%^BOLD%^%^RED%^rakes %^RESET%^%^RED%^it viciously across"
                        " your flesh! Oh, the pain!");
            set_property("magic", 1);
            vict->cause_typed_damage(vict, vict->return_target_limb(),
                                     random(5) + 12, "slashing");
            remove_property("magic");
            return 1; break;

        case 13..16:
            tell_room(EETO, "%^RESET%^%^CYAN%^" + ETO->QCN + "'s eyes "
                      "and the eyes of " + ETO->QP + " staff flash bright "
                      "%^ORANGE%^a%^YELLOW%^m%^BLACK%^b%^YELLOW%^e"
                      "%^RESET%^%^ORANGE%^r %^CYAN%^in unison as " + ETO->QS + " "
                      "swings the staff in a quick arc, sending a "
                      "%^BOLD%^%^GREEN%^sp%^BLACK%^h%^WHITE%^e%^GREEN%^re "
                      "%^RESET%^%^CYAN%^of %^BOLD%^%^BLACK%^un%^RED%^h"
                      "%^BLACK%^oly p%^GREEN%^o%^BLUE%^w%^BLACK%^er "
                      "%^RESET%^%^CYAN%^slamming into " + vict->QCN + "!",
                      ({ ETO, vict }));
            tell_object(ETO, "%^RESET%^%^CYAN%^A sudden insight "
                        "jumps to the fore of your mind! The %^ORANGE%^e"
                        "%^YELLOW%^y%^RESET%^%^ORANGE%^es %^CYAN%^of the staff "
                        "flash and your vision turns %^ORANGE%^go%^YELLOW%^l"
                        "%^WHITE%^d%^RESET%^%^ORANGE%^en %^CYAN%^as you swing the"
                        " staff in a quick arc, sending a %^BOLD%^%^GREEN%^sp"
                        "%^BLACK%^h%^WHITE%^e%^GREEN%^re %^RESET%^%^CYAN%^of "
                        "%^BOLD%^%^BLACK%^un%^RED%^h%^BLACK%^oly p%^GREEN%^o"
                        "%^BLUE%^w%^BLACK%^er %^RESET%^%^CYAN%^slamming into "
                        "" + vict->QCN + "!");
            tell_object(vict, "%^RESET%^%^CYAN%^" + ETO->QCN + "'s"
                        " eyes and the eyes of " + ETO->QP + " staff flash bright "
                        "%^ORANGE%^a%^YELLOW%^m%^BLACK%^b%^YELLOW%^e"
                        "%^RESET%^%^ORANGE%^r %^CYAN%^in unison as " + ETO->QO + " "
                        "swings the staff in a quick arc, sending a "
                        "%^BOLD%^%^GREEN%^sp%^BLACK%^h%^WHITE%^e%^GREEN%^re "
                        "%^RESET%^%^CYAN%^of %^BOLD%^%^BLACK%^un%^RED%^h"
                        "%^BLACK%^oly p%^GREEN%^o%^BLUE%^w%^BLACK%^er "
                        "%^RESET%^%^CYAN%^slamming into you!");
            set_property("magic", 1);
            vict->cause_typed_damage(vict, 0, roll_dice(2, 6) + 2,
                                     "negative energy");
            remove_property("magic");
            return 1; break;

        case 17..19:
            tell_room(EETO, "%^BOLD%^%^WHITE%^" + ETO->QCN + " "
                      "raises " + ETO->QP + " staff parallel with " + vict->QCN + ""
                      "'s face. A brief pause, and then - a spectral "
                      "%^BLACK%^displacer beast %^WHITE%^fades into sight, "
                      "leaping forth from the staff with a pantherlike roar!"
                      , ({ ETO, vict }));
            tell_object(ETO, "%^BOLD%^%^WHITE%^As if of its own"
                        " accord, the staff pulls itself and your arm upward "
                        "until parallel with " + vict->QCN + "'s face. A brief "
                        "pause, and then - a spectral %^BLACK%^displacer "
                        "beast %^WHITE%^fades into sight, leaping forth from "
                        "the staff with a pantherlike roar!");
            tell_object(vict, "%^BOLD%^%^WHITE%^" + ETO->QCN + " "
                        "raises " + ETO->QP + " staff parallel with your face. A "
                        "brief pause, and then - a spectral %^BLACK%^displacer"
                        " beast %^WHITE%^fades into sight, leaping forth from "
                        "the staff with a pantherlike roar!");
            obj2 = new(MON "disbeast");
            obj2->move(EETO);
            obj2->force_me("protect " + ETO->query_name());
            ETO->add_follower(obj2);
            break;

        default:
            break;
        }
        return 1;
    }
}
