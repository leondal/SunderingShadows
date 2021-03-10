#include <std.h>
inherit "/d/common/obj/clothing/magerobe.c";

string FLAG;


void create()
{
    ::create();
    set_name("robes");
    set_obvious_short("A set of dark red robes");

    set_short("%^BOLD%^%^RED%^Robes of the Archmagi%^RESET%^");

    set_id(({"robes","robes of the archmagi","Robes of the Archmagi","mage robes","magi robes","robe"}));

    set_long(
        "%^BOLD%^%^RED%^These robes are a dark red in color, representing a mage"+
        " who upholds the balance of power between good and evil. They are very"+
        " strong, as they appear to be made out of a very strong cotton"+
        ". A pair of wide flowing sleeves are trimmed with rune encrusted electrum fabric."+
        " The runes are hard to make out as they are always morphing and changing,"+
        " never giving one enough time to read them. The electrum colored sash serves as a"+
        " way to close the robes. These are extremely"+
        " elegant, flowing to the ground. There are probably numerous pockets to"+
        " conceal spell components and the like in them.%^RESET%^ ");
	set_lore("%^RESET%^%^CYAN%^The apex of the enchanters art, this robe required the combined efforts of the noted mages"
			 " Vecna, Nicodemus, and Batlin to bring to fruition, but the story of its creation is also a story of betrayal"
			 " and corruption. Many years before the founding of the city of Shadow, the still-mortal Vecna, and his contem"
			 " poraries of the orders of neutral and good magic, gathered. They created a temporary peace for the sake of the"
			 " stability of the regions. The symbol of that peace, this robe, was the central tool of the compact. This robe"
			 " grants its wearer tremendous power based upon the nature of the caster. The compact lasted for many years, and"
			 " every year the robe was passed to the next holder, who held the deciding vote in the triad. Vecna, hungry for power,"
			 " went through the dangerous and difficult process that guided him to lichdom, and through that transformation gained the"
			 " vital might to break the compact. He corrupted Nicodemus to his cause with offers of power and knowledge, and the two mighty"
			 " mages attacked Batlin. The war raged on for countless months, some even say it lasted for years with neither side managing to"
			 " best the other. The robe is said to have vanished from history at this time, and although it has been sought for ages, nobody"
			 " was able to locate this priceless magical artifact.");

    set_weight(5);
    set_type("clothing");

    set_property("no curse",1);
    set_property("enchantment",7);

    set_item_bonus("magic resistance",4);
    set_item_bonus("bonus_spell_slots",3);

    set_max_internal_encumbrance(21);

    set_value(350000);

    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));

    FLAG = "neutral";

    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
}


int wearme()
{
    string MASTER;

    if((string)ETO->query_gender() == "female") MASTER = "mistress";
    if((string)ETO->query_gender() == "male")   MASTER = "master";

    if(ALIGN->is_evil(ETO))
    {
        if(FLAG != "evil")
        {
            tell_object(ETO,"%^BOLD%^%^BLACK%^The robes turn the darkest"+
                " black as you slip them on.");
            tell_room(EETO,"%^BOLD%^%^BLACK%^The robes"+
                " turn pitch black as "+ETO->QCN+" puts them on,"+
                " reflecting their new "+MASTER+".",ETO);
            set_obvious_short("A set of pitch black robes");
            set_short("%^BOLD%^%^BLACK%^Robes of the Archmagi%^RESET%^");
            set_long("%^BOLD%^%^BLACK%^These robes are pitch black in color,"+
                " representing a mage who will stop at nothing to gain ultimate"+
                " power, even if it means using darker forces. They are very"+
                " strong, as they appear to be made out of a very strong cotton"+
                ". A pair of wide flowing sleeves are trimmed with rune encrusted electrum fabric."+
                " The runes are hard to make out as they are always morphing and changing,"+
                " never giving one enough time to read them. The electrum colored sash serves as a"+
                " way to close the robes. These are extremely"+
                " elegant, flowing to the ground. There are probably numerous"+
                " pockets to conceal spell components and the like in"+
                " them.%^RESET%^ ");
            FLAG = "evil";
        }
        else
        {
            tell_object(ETO,"%^BOLD%^%^BLACK%^The robes feel like a part of"+
                " you as you slip the trusted garment on.");
            tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+""+
                " seems more powerful after slipping on "+ETO->QP+" robes.",ETO);
        }
    }

    if(ALIGN->is_good(ETO))
    {
        if(FLAG != "good")
        {
            tell_object(ETO,"%^BOLD%^The robes turn a sparkling white as"+
                " you slip them on.");
            tell_room(EETO,"%^BOLD%^%^WHITE%^The robes"+
                " a bright shade of white as "+ETO->QCN+" puts them"+
                " on, reflecting their new "+MASTER+".",ETO);
            set_obvious_short("A set of bright white robes");
            set_short("%^BOLD%^%^WHITE%^Robes of the Archmagi%^RESET%^");
            set_long("%^BOLD%^%^WHITE%^These robes are bright white in color,"+
                " representing a mage whose intentions are pure and who strives"+
                " for good to maintain control of a power as strong and dangerous"+
                " as that of magic. They are very"+
                " strong, as they appear to be made out of a very strong cotton"+
                ". A pair of wide flowing sleeves are trimmed with rune encrusted electrum fabric."+
                " The runes are hard to make out as they are always morphing and changing,"+
                " never giving one enough time to read them. The electrum colored sash serves as a"+
                " way to close the robes. These are extremely"+
                " elegant, flowing to the ground."+
                " There are probably numerous pockets to conceal spell components"+
                " and the like in them.%^RESET%^ ");
            FLAG = "good";
        }

        else
        {
            tell_object(ETO,"%^BOLD%^The robes feel like a part of you"+
                " as you slip the trusted garment on.");
            tell_room(EETO,"%^BOLD%^"+ETO->QCN+""+
                " seems more powerful after slipping on "+ETO->QP+" robes.",ETO);
        }
    }
    if(ALIGN->is_neutral(ETO))
    {
        if(FLAG != "neutral")
        {
            tell_object(ETO,"%^BOLD%^%^RED%^The robes turn a splendid dark"+
                " red as you slip them on.");
            tell_room(EETO,"%^BOLD%^%^RED%^The robes"+
                " change to a dark red as "+ETO->QCN+" slips them"+
                " on, reflecting their new "+MASTER+".",ETO);
            set_obvious_short("A set of dark red robes");
            set_short("%^BOLD%^%^RED%^Robes of the Archmagi%^RESET%^");
            set_long("%^BOLD%^%^RED%^These robes are a dark red in color,"+
                " representing a mage who upholds the balance of power between"+
                " good and evil. They are very"+
                " strong, as they appear to be made out of a very strong cotton"+
                ". A pair of wide flowing sleeves are trimmed with rune encrusted electrum fabric."+
                " The runes are hard to make out as they are always morphing and changing,"+
                " never giving one enough time to read them. The electrum colored sash serves as a"+
                " way to close the robes. These are extremely"+
                " elegant, flowing to the ground."+
                " There are probably numerous pockets to conceal spell components"+
                " and the like in them.%^RESET%^ ");
            FLAG = "neutral";
        }
        else
        {
            tell_object(ETO,"%^BOLD%^%^RED%^The robes feel like a part of you"+
                " as you slip the trusted garment on.");
            tell_room(EETO,"%^BOLD%^%^RED%^"+ETO->QCN+""+
                " seems more powerful after slipping on "+ETO->QP+" robes.",ETO);
        }
    }

    if(ETO->is_class("mage"))
    {
        TO->set_item_bonus("intelligence",6);
        TO->set_item_bonus("charisma",0);
    }
    else
    {
        TO->set_item_bonus("intelligence",0);
        TO->set_item_bonus("charisma",6);
    }
    return 1;
}


int removeme()
{
    if(FLAG == "neutral")
    {
        tell_object(ETO,"%^BOLD%^%^RED%^You feel power slip from you as you"+
            " remove your wonderful robes.");
    }
    if(FLAG == "good")
    {
        tell_object(ETO,"%^BOLD%^You feel power slip from you as you"+
            " remove your wonderful robes.");
    }
    if(FLAG == "evil")
    {
        tell_object(ETO,"%^BOLD%^%^BLACK%^You feel power slip from you as you"+
            " remove your wonderful robes.");
    }
    return 1;
}


void init()
{
    ::init();
    add_action("check_put","put");
}


int check_put(string str)
{
    if(!query_worn())
    {
        notify_fail("You must be wearing the robes to place something in its"+
            " pockets.\n");
        return 0;
    }

    if(query_worn()) return ::put_into();
}
