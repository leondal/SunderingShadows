

#include <std.h>
#include <move.h>
#define DAY 24000
#include <daemons.h>
inherit "/d/common/obj/clothing/hat.c";

string owner;
string query_owner();
void set_owner(string str);
string help();

void create()
{
    ::create();
    set_obvious_short("%^BOLD%^%^GREEN%^pl%^RESET%^%^GREEN%^ume"
                      + "%^BLUE%^d h%^BOLD%^%^YELLOW%^ead%^RESET%^%^GREEN%^dre"
                      + "%^BOLD%^%^GREEN%^ss%^RESET%^");
    set_name("plumed headdress");
    set_short("%^CYAN%^Tec%^BOLD%^%^GREEN%^qumi%^RESET%^%^GREEN%^n"
              + " Emp%^BOLD%^%^YELLOW%^er%^RESET%^%^GREEN%^or's H%^BOLD%^"
              + "%^GREEN%^eaddr%^RESET%^%^CYAN%^ess");
    set_id(({ "headdress", "plumed headdress", "tecqumin headdress",
              "emporer's headdress" }));
    set_long("%^CYAN%^A plumed headdress, consisting of a startlingly"
             + " impressive spread of long %^BOLD%^%^GREEN%^green%^RESET%^"
             + "%^CYAN%^ and %^BOLD%^%^BLUE%^blue feathers%^RESET%^%^CYAN%^,"
             + " held in place by a broad %^ORANGE%^gi%^BOLD%^%^YELLOW%^l"
             + "%^RESET%^%^ORANGE%^t cl%^BOLD%^%^YELLOW%^o%^RESET%^"
             + "%^ORANGE%^th band%^CYAN%^. The band is studded with %^BOLD%^"
             + "%^YELLOW%^pu%^BOLD%^%^WHITE%^r%^BOLD%^%^YELLOW%^e g%^RESET%^"
             + "%^ORANGE%^o%^BOLD%^%^YELLOW%^ld s%^RESET%^%^ORANGE%^e%^BOLD%^"
             + "%^YELLOW%^qu%^BOLD%^%^WHITE%^i%^BOLD%^%^YELLOW%^ns%^RESET%^"
             + "%^CYAN%^ and decorated with subtle %^BLUE%^blue f%^CYAN%^e"
             + "%^BLUE%^ath%^CYAN%^e%^BLUE%^rs %^CYAN%^and %^BOLD%^%^RED%^r"
             + "%^RESET%^%^RED%^e%^BOLD%^%^RED%^d thr%^RESET%^%^RED%^ea"
             + "%^BOLD%^%^RED%^ds%^RESET%^%^CYAN%^.");
    set_lore("This is the headdress of the %^CYAN%^Tecqumin%^RESET%^"
             + " emperors. It was also the headdress worn by the%^MAGENTA%^"
             + " Empress Mehaq%^RESET%^ before she was displaced by her half"
             + " brother, %^BOLD%^%^BLUE%^Prince Epithon%^RESET%^. When"
             + " %^BOLD%^%^BLUE%^Epithon%^RESET%^ took up the headdress, he"
             + " found a way to curse it to prevent it being worn by women, as"
             + " a device to prevent his half sister returning to power. When"
             + " worn, the headdress imparts an aura of presence and"
             + " impressive authority upon the wearer.");
    set_property("lore difficulty", 35);
    set_weight(5);
    set_type("clothing");
    set_limbs(({ "head" }));
    set_ac(0);
    set_value(10000);
    set_wear((: TO, "wearme" :));
    set_remove((: TO, "removeme" :));
    set_size(-1);
    set_property("enchantment", 7);
    set_item_bonus("charisma", 6);
    set_item_bonus("influence", 6);
}

int wearme()
{
    if (!objectp(TO) || !objectp(ETO) || !objectp(EETO)) {
        return 0;
    }
    if (member_array("Fettered the %^MAGENTA%^U%^BLUE%^nf%^MAGENTA%^e%^BLUE%^tt%^MAGENTA%^e%^BLUE%^red", ETO->query_quests()) == -1 && member_array("Drove %^MAGENTA%^The %^BLUE%^U%^MAGENTA%^nf%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d %^RESET%^back into the %^BOLD%^%^BLACK%^vo%^RESET%^i%^BOLD%^%^BLACK%^d%^RESET%^!", ETO->query_quests()) == -1 && member_array("%^RED%^Defeated %^RESET%^%^BLUE%^The%^MAGENTA%^ U%^BLUE%^n%^MAGENTA%^f%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d", ETO->query_quests()) == -1) {
        tell_object(ETO, "%^BOLD%^%^WHITE%^You have not earned the right to use this item!%^RESET%^");
        return 0;
    }
    tell_object(ETO, "%^CYAN%^As you place the headdress on your head"
                + ", you feel your posture straighten slightly, and a sense of"
                + " %^BOLD%^%^RED%^power%^RESET%^%^CYAN%^ and%^BOLD%^%^BLUE%^"
                + " importance%^RESET%^%^CYAN%^ flows into you.");
    tell_room(EETO, ETO->QCN + "%^RESET%^%^CYAN%^ straightens as "
              + ETO->QS + " places the " + query_obvious_short() + "%^RESET%^%^CYAN%^"
              + " onto " + ETO->QP + " head. " + ETO->QS + " seems to take on"
              + " an air of impressive authority.", ETO);
    return 1;
}

int removeme()
{
    if (!objectp(TO) || !objectp(ETO) || !objectp(EETO)) {
        return 0;
    }
    tell_object(ETO, "" + query_short() + "You remove the headdress and"
                + " feel slightly less important.");
    tell_room(EETO, ETO->query_cap_name() + " slumps a little and looks"
              + " slightly less important after removing the " + query_obvious_short()
              + " from " + ETO->QP + " head.", ETO);
    return 1;
}

void init()
{
    ::init();
}
