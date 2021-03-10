#include <std.h>
inherit "/d/common/obj/clothing/belt";
int is_clean;
string myOwner, myClass;
void create()
{
    ::create();
    set_name("dingy sash");
    set_id(({ "sash", "dirty sash", "dingy sash",
    "hhousedingysaidesash", "green sash", "dingy green sash"}));

    set_short("%^RESET%^%^ORANGE%^A dingy sash%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This piece of %^BOLD%^%^CYAN%^cotton"+
    "%^RESET%^%^ORANGE%^ fabric is quite dingy. It is quite long and can "+
    "be tied in such a way that it would fit just about anyone. "+
    "However, it is not likely that many would willingly choose "+
    "to wear it in its current state. Despite this, you can tell that it "+
    "was once a %^BOLD%^%^GREEN%^brilliant green%^RESET%^%^ORANGE%^ color "+
    "with numerous strands of %^BOLD%^%^BLUE%^deep blues%^RESET%^%^ORANGE%^, "+
    "%^BOLD%^%^BLACK%^brilliant blacks%^RESET%^%^ORANGE%^, %^BOLD%^%^MAGENTA%^"+
    "flamboyant purples%^RESET%^%^ORANGE%^, and %^BOLD%^%^RED%^bright reds%^RESET%^"+
    "%^ORANGE%^ sewn throughout it. They have lost most of their luster but are "+
    "still quite magnificient. There seems to be a slight magic %^BOLD%^"+
    "%^CYAN%^aura%^RESET%^%^ORANGE%^ given off from it but it is mostly "+
    "held at bay by the dirt and filth that has built up. If there "+
    "was some place that you could %^BOLD%^%^CYAN%^wash%^RESET%^%^ORANGE%^ "+
    "it, perhaps the magic would again function.%^RESET%^");

    set_weight(1);
    set_value(1000);
    set_size(-1);
    set_lore("It is rumored that these sashes were "+
    "tailored by Ao'rus Devar himself many ages ago. "+
    "The few rumors that still survive suggest that he "+
    "imbued them with a magic potent enough to respond to "+
    "whichever servant he gifted one to, taking on a "+
    "power that would augment that servant. Most of them "+
    "were thought lost when Ao'rus Devar shed his mortal "+
    "shell but apparently a few have survived.");

    set_property("lore difficulty",18+random(3));

    set_property("no curse", 1);
    set_property("enchantment",2);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    is_clean = 0;
}


int clean_me_up()
{
    if(is_clean) return 0;
    is_clean = 1;

    set_id(({ "sash", "augmentation sash", "brilliant sash", "green sash",
    "brilliant green sash", "sash of augmentation", "cohesion sash",
    "cohesive sash of augmentation"}));

    set_obvious_short("%^BOLD%^%^GREEN%^A br%^RESET%^%^GREEN%^i%^BOLD%^"+
    "%^GREEN%^ll%^RESET%^%^GREEN%^ia%^BOLD%^%^GREEN%^nt %^RESET%^%^GREEN%^"+
    "e%^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^r%^RESET%^"+
    "%^GREEN%^a%^BOLD%^%^GREEN%^ld s%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^"+
    "sh%^RESET%^");

    set_short("%^BOLD%^%^GREEN%^C%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^h"+
    "%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^"+
    "v%^RESET%^%^GREEN%^e %^BOLD%^%^GREEN%^S%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^"+
    "sh of %^RESET%^%^GREEN%^Au%^BOLD%^%^GREEN%^gm%^RESET%^%^GREEN%^e%^BOLD%^"+
    "%^GREEN%^nt%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^t%^RESET%^%^GREEN%^io%^BOLD%^"+
    "%^GREEN%^n%^RESET%^");

    set_long("%^BOLD%^%^GREEN%^This brilliant green sash is truly an amazing "+
    "piece of work, a living testament to the skill of the tailor who stitched it. "+
    "The center band of it is a soft, thick cotton with numerous strands of "+
    "other materials sewn throughout it in a d%^BOLD%^%^WHITE%^a%^BOLD%^"+
    "%^GREEN%^zzl%^BOLD%^%^WHITE%^i%^BOLD%^%^GREEN%^ng array of colors. "+
    "There are %^BOLD%^%^BLUE%^deep, magnificent blue %^BOLD%^%^GREEN%^threads, "+
    "%^BOLD%^%^BLACK%^shiny, brilliant black%^BOLD%^%^GREEN%^ threads, "+
    "%^BOLD%^%^MAGENTA%^rich, flamboyant purple%^BOLD%^%^GREEN%^ threads, "+
    "and %^BOLD%^%^RED%^bright, alluring red%^BOLD%^%^GREEN%^ threads. "+
    "They are sewn in such a way to be seamless, as if the materials "+
    "were themselves combined in one long continuous strand of fabric "+
    "which must have taken an enormous amount of time to weave together. "+
    "You can almost see the colors moving in a neverending circle, "+
    "all united and held together, you are unsure if this is just "+
    "a trick of light or perhaps a fraction of the magic contained "+
    "within the sash. It is long enough so that it could be tied "+
    "in such a way to fit almost anyone.%^RESET%^");
    TO->adjust_sash(ETO);
    if((int)TO->query_property("enchantment") < 4) TO->set_property("enchantment", 2);
}

string find_highest_level_class(object who)
{
    string *myClasses, highclass;
    int lev = 0, x, clev;
    if(!objectp(who)) return "fail";
    myClasses = who->query_classes();
    for(x = 0;x < sizeof(myClasses);x++)
    {
        clev = (int)who->query_class_level(myClasses[x]);
        if(lev > clev) continue;
        else
        {
            lev = clev;
            highclass = myClasses[x];
            continue;
        }
    }
    if(!stringp(highclass)) return "fail";
    return highclass;

}

void adjust_sash(object who)
{
    if (!objectp(who)) {
        return;
    }

    myOwner = who->query_true_name();
    clear_item_bonus();
    myClass = find_highest_level_class(who);
    if (myClass == "fail") {
        tell_object(who, "Something went wrong when cleaning your sash. Notify saide of this message.");
        return;
    }
    switch (myClass) {
    case "druid": case "cleric":
        set_item_bonus("wisdom", 2);
        set_item_bonus("caster level", 1);
        break;
    case "mage": case "psion": case "psywarrior":
        set_item_bonus("intelligence", 2);
        set_item_bonus("caster level", 1);
        break;
    case "sorcerer": case "paladin": case "cavalier": case "bard": case "warlock": case "oracle":
        set_item_bonus("charisma", 2);
        set_item_bonus("caster level", 1);
        break;
    case "fighter":
        set_item_bonus("strength", 2);
        set_item_bonus("perception", 2);
        break;
    case "barbarian":
        set_item_bonus("constitution", 2);
        //set_item_bonus("strength", 2);
        set_item_bonus("endurance", 2);
        break;
    case "ranger":
        set_item_bonus("wisdom", 2);
        set_item_bonus("survival", 2);
        break;
    case "thief":
        set_item_bonus("dexterity", 2);
        set_item_bonus("dungeoneering", 2);
        break;
    }
}

int wear_func()
{
    if(!objectp(ETO)) return 0;
    //if(!objectp(EETO)) return 0;
    if(!is_clean)
    {
        tell_object(ETO, "%^RESET%^%^ORANGE%^You quickly "+
        "tie the dingy sash around your waist.%^RESET%^");
        if(objectp(EETO))
        {
            tell_room(EETO, ETOQCN+"%^RESET%^%^ORANGE%^ ties "+
            "a dingy sash around "+ETO->QP+" waist.%^RESET%^", ETO);
        }
        return 1;
    }
    if(is_clean)
    {
        if(myOwner != (string)ETO->query_true_name() ||
        myClass != (string)ETO->query("active_class"))
        {
            adjust_sash(ETO);
            tell_object(ETO, "%^BOLD%^%^GREEN%^You quickly "+
            "tie the brilliant sash around your waist and "+
            "feel its power augment your own as it somehow changes!%^RESET%^");
        }
        else
        {
            tell_object(ETO, "%^BOLD%^%^GREEN%^You quickly "+
            "tie the brilliant sash around your waist and "+
            "feel its power augment your own!%^RESET%^");
        }
        if(objectp(EETO))
        {
            tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^ quickly "+
            "ties a brilliant sash around "+ETO->QP+" waist!%^RESET%^", ETO);
        }
	}
    return 1;
}

int remove_func()
{
    if(!is_clean)
    {
        tell_object(ETO, "%^RESET%^%^ORANGE%^You untie the "+
        "dingy sash.%^RESET%^");
        tell_room(EETO, ETOQCN+"%^RESET%^%^ORANGE%^ unties the "+
        "dingy sash.%^RESET%^", ETO);
        return 1;
    }
    if(is_clean)
    {
        tell_object(ETO, "%^BOLD%^%^GREEN%^You untie the sash "+
        "and feel the augmentation granted by it fade away.%^RESET%^");

        tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^ unties the "+
        "brilliant sash.%^RESET%^", ETO);
        return 1;
    }
}
