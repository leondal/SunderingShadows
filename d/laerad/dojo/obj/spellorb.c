#include <std.h>
#include <magic.h>
inherit "/d/common/obj/weapon/club"; //closest simple option

void set_element(string myelement);
string mysetting, thecolor, theshort;

int bonus;

void create()
{
    ::create();
    set_name("orb");
    set_id(({ "orb", "glass orb", "glossy glass orb", "glossy orb", "sphere", "sphere of elemental wrath", "Sphere of Elemental Wrath" }));
    set_element("fire");
    set_lore("%^WHITE%^%^BOLD%^The series of creations known as the Spheres of Elemental Wrath were devised by the "
             "shamans of the Jin Chao Kingdom, several centuries before their demise.  To their people, the balance of the five "
             "elements was a key aspect of their religious and philosophical attitudes, so it was seen as high accomplishment to "
             "create such a magical item that captured the essence of each of these.  Yet while fire, water, earth and air were able "
             "to be harnessed within the orb, the precious fifth element of spirit seemed to elude even their skills.  It was said "
             "that one with enough presence of will could %^YELLOW%^alter %^WHITE%^the orb to embody any one of these four elements at "
             "a given time.%^RESET%^\n");
    set("no curse", 1);
    set_property("lore difficulty", 27);
    set_property("able to cast", 1);
    set_property("enchantment", 4);
    set_item_bonus("attack bonus", -2);
    set_item_bonus("damage bonus", -2);
    set_item_bonus("spell penetration", 2);
    set_property("repairtype", ({ "jewel" }));
    set_cointype("gold");
    set_value(9550);
    set_wield((: TO, "wield_fun" :));
    set_unwield((: TO, "unwield_fun" :));
}

void init()
{
    ::init();
    add_action("shift_fun", "alter");
    if (!userp(ETO)) {
        return;
    }
    //if(query_size() != (int)ETO->query_size()) set_size((int)ETO->query_size());  This should be a small weapon.
}

int wield_fun()
{
    int toenchant;
    if (userp(ETO) && member_array("%^RESET%^%^MAGENTA%^%^Defeated the masters of the Vasati Aadhyaatmika.%^RESET%^", ETO->query_mini_quests()) == -1) {
        tell_object(ETO, "%^BOLD%^You have not earned the right to make use of this item.%^RESET%^");
        return 0;
    }
    if (userp(ETO) && (int)ETO->query_level() < 25) {
        tell_object(ETO, "%^BOLD%^You must train further before you can attempt to use a weapon of this calibre.%^RESET%^");
        return 0;
    }

    if (objectp(ETO)) {
        ETO->set_property("empowered", 1);
        ETO->set_property("bonus_spell_slots", 1);
    }

    tell_room(EETO, "%^RESET%^" + thecolor + "The smoky haze of the orb comes to life, roiling angr%^BOLD%^i%^RESET%^" + thecolor +
              "ly within its glassy prison.%^RESET%^");
    if (TP->is_class("mage") || TP->is_class("psion") || TP->is_class("alchemist")) {
        set_item_bonus("intelligence", 4);
        set_item_bonus("charisma", 0);
        set_item_bonus("wisdom", 0);
        return 1;
    }
    if (TP->is_class("sorcerer") || TP->is_class("bard") || TP->is_class("oracle") || TP->is_class("warlock")) {
        set_item_bonus("intelligence", 0);
        set_item_bonus("charisma", 4);
        set_item_bonus("wisdom", 0);
        return 1;
    }
    if (TP->is_class("cleric") || TP->is_class("druid") || TP->is_class("inquisitor")) {
        set_item_bonus("intelligence", 0);
        set_item_bonus("charisma", 0);
        set_item_bonus("wisdom", 4);
        return 1;
    }


    tell_object(ETO, "%^BOLD%^The orb doesn't seem to respond to you, its inner mists remaining almost motionless.%^RESET%^");
    return 0;
}

int unwield_fun()
{
    tell_room(EETO, "%^RESET%^" + thecolor + "The orb calms again, its inner mists becoming still.%^RESET%^");

    if (objectp(ETO)) {
        ETO->set_property("bonus_spell_slots", -1);
        ETO->set_property("empowered", -1);
    }
    return 1;
}

int shift_fun(string str)
{
    if (!str) {
        return 0;
    }
    if (str != "fire" && str != "water" && str != "air" && str != "earth") {
        return notify_fail("The orb won't shift to that element!");
    }
    if (!TO->query_wielded()) {
        return notify_fail("You must wield the orb to impose your will upon it!");
    }
    set_element(str);
    tell_room(EETO, "%^BOLD%^%^WHITE%^A violent storm of colors whirls through the misty depths of the "
              "orb, before it finally settles on " + theshort + "%^BOLD%^%^WHITE%^.%^RESET%^");
    return 1;
}

void set_element(string myelement)
{
    mysetting = myelement;
    switch (mysetting) {
    case "fire":
        theshort = "%^RESET%^%^RED%^r%^MAGENTA%^u%^BOLD%^b%^RESET%^%^RED%^y-r%^BOLD%^e%^RESET%^%^RED%^d";
        thecolor = "%^RED%^";
        break;

    case "water":
        theshort = "%^RESET%^%^BLUE%^co%^BOLD%^b%^CYAN%^a%^RESET%^%^BLUE%^lt-bl%^CYAN%^u%^BLUE%^e";
        thecolor = "%^BLUE%^";
        break;

    case "air":
        theshort = "%^RESET%^%^ORANGE%^go%^YELLOW%^ld%^RESET%^%^ORANGE%^en-ye%^YELLOW%^ll%^RESET%^%^ORANGE%^ow";
        thecolor = "%^ORANGE%^";
        break;

    case "earth":
        theshort = "%^RESET%^%^GREEN%^f%^BOLD%^o%^RESET%^%^GREEN%^r%^ORANGE%^e%^GREEN%^st-gr%^BOLD%^e%^YELLOW%^e%^RESET%^%^GREEN%^n";
        thecolor = "%^GREEN%^";
        break;
    }
    set_short("%^RESET%^" + thecolor + "Sph%^BOLD%^e%^RESET%^" + thecolor + "re of El%^BOLD%^e%^RESET%^" + thecolor + "mental Wr%^BOLD%^a%^RESET%^" + thecolor + "th%^RESET%^");
    set_obvious_short("%^RESET%^" + thecolor + "glo%^BOLD%^s%^RESET%^" + thecolor + "sy glass orb%^RESET%^");
    set_long("%^WHITE%^%^BOLD%^This orb seems just large enough to fit comfortably in one hand, if you so "
             "desired.  It appears to be made of %^RESET%^%^CYAN%^g%^BOLD%^l%^RESET%^%^CYAN%^ass%^BOLD%^%^WHITE%^, though surprisingly "
             "it is far more resilient to damage than such a material would usually afford.  The glass itself is perfectly smooth, "
             "without crack or scratch to mar its gleaming surface, and is tinted a soft shade of " + theshort + "%^BOLD%^%^WHITE%^.  "
             "Fairly light in weight, as though hollow inside, a closer inspection reveals that it is filled with some kind of "
             "%^RESET%^c%^BOLD%^%^BLACK%^l%^RESET%^ou%^BOLD%^%^BLACK%^d%^RESET%^y %^BOLD%^%^WHITE%^substance that drifts lazily within "
             "the confines of its transparent prison.  A pretty trinket, perhaps, or something more?%^RESET%^\n");
}
