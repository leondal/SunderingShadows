//Cleaned up the code a bit with the wear unwear and gave a new desc - Shar originally made - Cythera 3/05
#include <std.h>

inherit "/d/common/obj/armour/chain.c";


void create()
{
    ::create();
    set_name("crystal mail");
    set_id(({ "crystal mail", "mail", "mail shirt", "crystal shirt", "mesh shirt", "mesh mail", "crystal mesh", " pristmatic mail" }));

    set_short("%^RESET%^%^RED%^P%^BOLD%^r%^RESET%^%^ORANGE%^" +
              "i%^YELLOW%^s%^GREEN%^m%^CYAN%^a%^BLUE%^t%^MAGENTA%^" +
              "i%^RESET%^%^MAGENTA%^c%^BOLD%^%^WHITE%^ Mail%^RESET%^");

    set_obvious_short("%^BOLD%^%^WHITE%^A crystal mail shirt");

    set_long("%^BOLD%^Woven from c%^CYAN%^r%^WHITE%^y%^CYAN%^" +
             "s%^WHITE%^t%^CYAN%^a%^WHITE%^l, these mesh links " +
             "create a form fitting shirt of mail.  The elegant " +
             "crystal mail shirt protects the torso from attacks." +
             "  The crystal links are woven in a manner that they" +
             " almost seem to flow together, until the lights within" +
             " the links begin to dance.  A swirling mass of " +
             "%^RESET%^%^RED%^p%^BOLD%^r%^RESET%^%^ORANGE%^i" +
             "%^YELLOW%^s%^GREEN%^m%^RESET%^%^CYAN%^a%^BLUE%^t" +
             "%^MAGENTA%^i%^BOLD%^c%^WHITE%^ hues dance within each" +
             " link, adding a mystical quality to this already " +
             "fascinating mail shirt.  With short sleeve, the " +
             "lightweight mail looks as if it would be comfortable" +
             " to wear.  This flawless crystal mesh mail shirt is " +
             "free from any flaws.%^RESET%^\n");

    set_lore("Stories tell of a human priest of Lathander by " +
             "the name of Orleand Bloom who was dedicated in " +
             "bringing the light of the dawn to the darkness of" +
             " the lands.  Morninglord Bloom traveled across the" +
             " lands with four of his closest friends.  Yasmen, " +
             "the Tsvarian bardess, Sir Liam Garnet, Holy Knight " +
             "of Lathander, the ranger Phenris, the young wizard " +
             "Thalim, and the warrior maiden Valarika.  The group " +
             "of five had a very successful campaign that took them" +
             " from the forests of Tharis to the Cities of the Drow," +
             " and even as far away as Attaya.  On one mystical " +
             "adventure the Sun's Rays, as they named their company," +
             " was enlisted to aid the Sehdi court of fey against the " +
             "forces of the Unseelie.  The battles and trails lasted " +
             "many months, but in the end the Sun's Rays were able to" +
             " return the Faerie Queen Ahgavashla to her throne.  To" +
             " repay each of them for their heroism, she used her fey" +
             " magic to create gifts for them.  Morninglord Bloom was" +
             " blessed with a crystal mail shirt that was 'woven from" +
             " raindrops, a summer zephyr breeze, and rays of sunshine'" +
             " as he would tell anyone.  Morninglord Bloom's fantastic" +
             " crystal mail shined with prismatic hues that he claimed" +
             " put him more in tune with the ways of Lathander.  The " +
             "Sun's Rays had many more successful adventures until they" +
             " heart news of a great dragon that was terrorizing the lands." +
             "  Sadly, the Sun's Rays were never heard from again after they" +
             " set sail to track down this great beast. - The Glory of the Sun:" +
             " The Life and Adventures of the Sun's Rays - Astrid Bloom");

    set_value(155000);

    set_property("lore difficulty", 19);

    set_property("no curse", 1);
    set_property("enchantment", 7);

    set_item_bonus("bonus_spell_slots", 3);
    set_item_bonus("damage resistance", 10);

    set_wear((: TO, "wear_func" :));
    set_remove((: TO, "remove_func" :));
    set_struck((: TO, "strike_func" :));

    set_heart_beat(1);
    set_size(-1);

    set_property("quest required", "%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required", 35);
}

int wear_func()
{
    tell_room(EETO, "%^BOLD%^Pulling the armor on" +
              ", " + ETO->QCN + " stops to admire the %^RESET%^%^RED%^p" +
              "%^BOLD%^r%^ORANGE%^i%^YELLOW%^s%^GREEN%^m%^RESET%^" +
              "%^CYAN%^a%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^" +
              "%^MAGENTA%^c%^BOLD%^%^WHITE%^ colors " +
              "that dance across the surface.", ETO);
    tell_object(ETO, "%^BOLD%^You slide on the " + query_short() + "" +
                " %^BOLD%^over your head and admire the dazzling " +
                "%^RED%^c%^YELLOW%^o%^GREEN%^l%^CYAN%^o%^BLUE%^r" +
                "%^MAGENTA%^s%^WHITE%^ that dance across the mesh");
    return 1;
}

int remove_func()
{
    tell_room(EETO, "%^BOLD%^Pulling off the mail shirt" +
              "," + ETO->QCN + " stares in a daze at the mail and the " +
              "swirling %^RED%^c%^YELLOW%^o%^GREEN%^l%^CYAN%^o%^BLUE%^" +
              "r%^MAGENTA%^s%^WHITE%^.", ETO);
    tell_object(ETO, "%^BOLD%^You slip the " + query_short() + "%^BOLD%^ off over" +
                " your head, but still pause to admire the beauty of the" +
                " %^RED%^c%^YELLOW%^o%^GREEN%^l%^CYAN%^o%^BLUE%^r%^MAGENTA%^" +
                "s%^WHITE%^.");
    return 1;
}

int strike_func(int damage, object what, object who)
{
    if (!random(2)) {
        tell_room(environment(query_worn()), "%^BOLD%^A bright " +
                  "%^RED%^p%^BOLD%^r%^RESET%^%^ORANGE%^i%^YELLOW%^s%^GREEN%^" +
                  "m%^CYAN%^a%^BLUE%^t%^MAGENTA%^i%^RESET%^%^MAGENTA%^c%^RESET%^" +
                  "%^BOLD%^ light flashes to life as, " + who->QCN + " strikes " +
                  "" + ETO->QCN + "", ({ ETO, who }));
        tell_object(ETO, "%^BOLD%^A bright %^RED%^p%^BOLD%^r%^RESET%^" +
                    "%^ORANGE%^i%^YELLOW%^s%^GREEN%^m%^CYAN%^a%^BLUE%^t" +
                    "%^MAGENTA%^i%^RESET%^%^MAGENTA%^c%^RESET%^%^BOLD%^ " +
                    "light flashes to life as, " + ETO->QCN + " strikes you");
        tell_object(who, "%^BOLD%^A bright %^RED%^p%^BOLD%^r%^RESET%^" +
                    "%^ORANGE%^i%^YELLOW%^s%^GREEN%^m%^CYAN%^a%^BLUE%^t" +
                    "%^MAGENTA%^i%^RESET%^%^MAGENTA%^c%^RESET%^%^BOLD%^ " +
                    "light flashes to life as you strike " + ETO->QCN + ".");
        who->set_paralyzed(roll_dice(1, 4) + 1);
        return 0;
    }
    return damage;
}

void heart_beat()
{
    object owner, env;
    int i, xx, yy;

    if (!objectp(ETO)) {
        return;
    }

    env = ETO;

    if (objectp(env) && ETO->is_player()) {
        owner = env;
        env = environment(owner);
    }

    if ((!(TO->query_worn())) || (ETO->query_invis())) {
        return;
    }else {
        xx = random(500);
        yy = random(7);

        if ((xx > 495)) {
            tell_object(owner, "\n%^BOLD%^The crystal links %^RED%^s%^RESET%^" +
                        "%^ORANGE%^h%^YELLOW%^i%^GREEN%^m%^RESET%^%^CYAN%^m" +
                        "%^BLUE%^e%^RESET%^%^MAGENTA%^r%^BOLD%^%^WHITE%^ for a moment" +
                        " before they settle.\n");

            switch (yy) {
            case 0:

                tell_room(env, "%^BOLD%^%^RED%^" + owner->QCN + "'s crystal mail shifts in hue" +
                          " and fades into shades of %^RESET%^%^RED%^r%^BOLD%^e" +
                          "%^RESET%^%^RED%^d%^BOLD%^ color.", owner);
                break;


            case 1:

                tell_room(env, "%^BOLD%^%^BLUE%^" + owner->QCN + "'s crystal mail shifts in " +
                          "hue and fades into shades of %^RESET%^%^BLUE%^b%^BOLD%^" +
                          "l%^RESET%^%^BLUE%^u%^BOLD%^e.", owner);
                break;

            case 2:

                tell_room(env, "%^BOLD%^%^CYAN%^" + owner->QCN + "'s crystal mail shifts in " +
                          "hue and fades into shades of %^RESET%^%^CYAN%^t%^BOLD%^" +
                          "u%^RESET%^%^CYAN%^r%^BOLD%^q%^RESET%^%^CYAN%^u%^%^BOLD%^" +
                          "o%^RESET%^%^CYAN%^i%^BOLD%^s%^RESET%^%^CYAN%^e%^BOLD%^.", owner);
                break;

            case 3:

                tell_room(env, "%^BOLD%^%^GREEN%^" + owner->QCN + "'s crystal mail " +
                          "shifts in hue and fades into shades of %^RESET%^%^GREEN%^" +
                          "g%^BOLD%^r%^RESET%^%^GREEN%^e%^BOLD%^e%^RESET%^%^GREEN%^" +
                          "n%^BOLD%^.", owner);
                break;

            case 4:

                tell_room(env, "%^BOLD%^%^MAGENTA%^" + owner->QCN + "'s crystal mail" +
                          " shifts in hue and fades shades of pink and %^RESET%^" +
                          "%^MAGENTA%^purple%^RESET%^.", owner);
                break;

            case 5:

                tell_room(env, "%^BOLD%^%^WHITE%^" + owner->QCN + "'s crystal mail" +
                          " shifts in hue and fades into shades of %^RESET%^s" +
                          "%^BOLD%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r" +
                          "%^BOLD%^.", owner);
                break;

            default:

                tell_room(env, "%^BOLD%^%^YELLOW%^" + owner->QCN + "'s crystal mail" +
                          " shifts in hue and fades into shades of %^RESET%^" +
                          "%^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^l%^RESET%^" +
                          "%^ORANGE%^d%^BOLD%^.", owner);
                break;
            }
        }
    }
    return;
}
