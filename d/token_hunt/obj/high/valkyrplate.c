//Octothorpe (12/8/09)
//Plate of the Valkyries

#include <std.h>
inherit "/d/common/obj/armour/fullplate";
#define WAIT_TIME 43200

int used_time;

void create()
{
    ::create();
    set_name("plate of the valkyries");
    set_id(({ "plate of the valkyries",
              "fullplate",
              "full plate",
              "valkyries",
              "runic plate",
              "plate armour",
              "runic plate armour",
              "plate" }));
    set_obvious_short("%^BOLD%^%^BLACK%^a %^BOLD%^%^WHITE%^s%^BOLD%^" +
                      "%^BLACK%^ui%^RESET%^t %^BOLD%^%^BLACK%^o%^RESET%^f %^BOLD%^" +
                      "%^WHITE%^r%^BOLD%^%^BLACK%^u%^RESET%^n%^BOLD%^%^BLACK%^i" +
                      "%^RESET%^c pl%^BOLD%^%^BLACK%^a%^RESET%^t%^BOLD%^%^BLACK%^e " +
                      "a%^RESET%^r%^BOLD%^%^WHITE%^m%^BOLD%^%^BLACK%^ou%^RESET%^r");
    set_short("%^RESET%^P%^BOLD%^%^WHITE%^l%^BOLD%^%^BLACK%^a%^RESET%^" +
              "t%^BOLD%^%^BLACK%^e o%^RESET%^f t%^BOLD%^%^WHITE%^h%^BOLD%^" +
              "%^BLACK%^e %^RESET%^V%^BOLD%^%^BLACK%^a%^RESET%^lk%^BOLD%^" +
              "%^WHITE%^y%^RESET%^r%^BOLD%^%^BLACK%^ie%^RESET%^s");
    set_long("%^BOLD%^%^BLACK%^Crafted from rugged, dark grey steel, " +
             "this suit of plate armour seems to hail from an era immemorial.  " +
             "The steel is incapable of any shine and has a well-worn quality " +
             "that increases the character of the armour. Structurally, the " +
             "armour is in perfect condition, with the rugged exterior being " +
             "nothing more than a facade.  Lines of runic letters wrap around " +
             "the spaulders and greaves, and appear to be apart of a prayer " +
             "or epic.  The cuirass is inlaid with depictions of women " +
             "wielding spears and armored in mail on a field of battle.  " +
             "A few of the women are mounted on pegasi, while others are " +
             "shown tending to the dead.%^RESET%^");
    set_lore("According to legend, roughly twenty suits of plate " +
             "resembling this design were manufactured for the Knights of " +
             "the Valkyries.  The Knights were an adventuring, pseudo-" +
             "crusading company that frequented the Dagger Reaches and Charu " +
             "mountains during the third century SG.  The company was composed " +
             "of adherents to an obscure Kelemvorite cult centered around the " +
             "mythic maidens known as valkyries.  According to the cult, " +
             "valkyries would bear the bodies of those who had died honorably " +
             "on the field of battle, to Kelemvor.  The plate armor that was " +
             "forged for the Knights of the Valkyries was supposedly blessed " +
             "by Kelemvor himself, and it is said that valkyries would aid " +
             "the wearer in their time of greatest need.  When found near " +
             "death, the wearer of the armor would use the magical command " +
             "word %^BOLD%^valkyrja%^RESET%^, and a valkyrie would bear away " +
             "the dying person to safety.");
    set_value(0);
    set_size(-1);
    while ((int)TO->query_property("enchantment") != 5) {
        TO->remove_property("enchantment");
        TO->set_property("enchantment", 5);
    }
    set_item_bonus("bonus_spell_slots", 1);
    set_item_bonus("spell penetration", 2);
    set_item_bonus("magic resistance", 1);
    set_property("lore difficulty", 24);
    set_wear((: TO, "wear_fun" :));
    set_remove((: TO, "remove_fun" :));
    set_overallStatus(220);
    set_property("no disenchant",1);
}

void init()
{
    ::init();
    set_size(TP->query_size());
    if ((int)TO->query_property("enchantment") < 5) {
        TO->remove_property("enchantment");
        TO->set_property("enchantment", 5);
    }
    if (living(ETO)) {
        add_action("valkyrja_fun", "valkyrja");
    }
}

int wear_fun()
{
    if ((int)ETO->query_lowest_level() < 25) {
        tell_room(EETO, "%^BOLD%^The runes on the plate begin to glow an " +
                  "angry %^RESET%^%^RED%^red%^BOLD%^%^WHITE%^, as " + ETOQCN + " " +
                  "attempts to don the armour.%^RESET%^", ETO);
        tell_object(ETO, "%^BOLD%^The plate seems to conspire against " +
                    "you as you attempt to don the armour.%^RESET%^");
        return 0;
    }
    tell_room(EETO, "%^BOLD%^As " + ETOQCN + " dons the plate, the runes " +
              "on " + ETO->QP + " armour become illuminated by a soft, %^BOLD%^" +
              "%^BLUE%^b%^RESET%^%^BLUE%^lu%^BOLD%^%^BLUE%^e %^BOLD%^%^WHITE%^" +
              "glow.%^RESET%^", ETO);
    tell_object(ETO, "%^BOLD%^As you don the plate, the runes on the " +
                "armour become illuminated by a soft, %^BOLD%^%^BLUE%^b%^RESET%^" +
                "%^BLUE%^lu%^BOLD%^%^BLUE%^e %^BOLD%^%^WHITE%^glow.%^RESET%^");
    return 1;
}

int remove_fun()
{
    tell_room(EETO, "%^BOLD%^The %^BOLD%^%^BLUE%^gl%^RESET%^%^BLUE%^o" +
              "%^BOLD%^%^BLUE%^w%^RESET%^%^BLUE%^i%^BOLD%^%^BLUE%^ng %^BOLD%^" +
              "%^WHITE%^runes on " + ETOQCN + "'s plate dull to the color of steel, " +
              "as " + ETOQCN + " removes the armour.%^RESET%^", ETO);
    tell_object(ETO, "%^BOLD%^The %^BOLD%^%^BLUE%^gl%^RESET%^%^BLUE%^o" +
                "%^BOLD%^%^BLUE%^w%^RESET%^%^BLUE%^i%^BOLD%^%^BLUE%^ng %^BOLD%^" +
                "%^WHITE%^runes on your plate dull to the color of steel, " +
                "as you remove the armour.%^RESET%^");
    return 1;
}

int valkyrja_fun()
{
    if (!objectp(ETO)) {
        return 0;
    }
    if (!(query_worn())) {
        tell_object(ETO, "%^BOLD%^You need to wear the plate to be able " +
                    "to invoke the aid of the valkyries.%^RESET%^");
        return 1;
    }
    if (WAIT_TIME > (time() - used_time)) {
        tell_object(ETO, "%^BOLD%^You need to wait longer to be able " +
                    "to invoke the aid of the valkyries.%^RESET%^");
        return 1;
    }
    if (EETO->query_property("no teleport")) {
        tell_object(ETO, "%^BOLD%^You realize that the valkyries cannot " +
                    "even reach you here!%^RESET%^");
        return 1;
    }

    tell_room(EETO, "%^YELLOW%^A valkyrie mounted on a pegasus swoops in " +
              "out of nowhere and snatches " + ETOQCN + ", placing " + ETO->QO + " " +
              "across the saddle, and then disappears suddenly!%^RESET%^", ETO);
    tell_object(ETO, "%^BOLD%^The command word %^RESET%^'%^BOLD%^valkyrja" +
                "%^RESET%^' %^BOLD%^leaps from your mind as a halcyon call across " +
                "the Astral Plane...\n%^YELLOW%^Suddenly, a valkyrie mounted on " +
                "a pegasus emerges out of nowhere!  The valkyrie effortlessly " +
                "grabs you, and places you across her saddle.\nYou open your " +
                "eyes and find yourself far from your previous fray, no worse " +
                "for wear!%^RESET%^");
    ETO->cause_typed_damage(ETO, "torso", (int)ETO->query_hp() - (int)ETO->query_max_hp(), "untyped");
    used_time = time();
    ETO->set_condition(0);
    switch (random(7)) {
    case 0:
        ETO->move("/d/magic/temples/eldath");
        break;

    case 1:
        ETO->move("/d/guilds/order/hall/main");
        break;

    case 2:
        ETO->move("/d/guilds/alliance/hall/gate");
        break;

    case 3:
        ETO->move("/d/guilds/kindred/rooms/campfire");
        break;

    case 4:
        ETO->move("/d/dagger/exchange/rooms/trading");
        break;

    case 5:
        ETO->move("/d/shadowgate/adv_main");
        break;

    case 6:
        ETO->move("/d/attaya/newseneca/rooms/gazebo");
        break;

    default:
        ETO->move("/d/shadowgate/adv_main");
        break;
    }
    if (ETO->query_bound()) {
        tell_object(ETO, "%^BOLD%^Your bonds fall loosely to the " +
                    "ground.%^RESET%^");
        tell_room(EETO, "%^BOLD%^" + ETO->QCN + "'s bonds fall loosely " +
                  "around " + ETO->QO + ".%^RESET%^", ETO);
        ETO->set_bound(0);
    }
    ETO->force_me("look");
    return 1;
}
