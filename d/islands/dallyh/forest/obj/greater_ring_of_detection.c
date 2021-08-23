#include <std.h>
#define SCRY_D "/daemon/ic_scry_locate_d"
inherit "/d/common/obj/jewelry/ring";


int SetLevel = 0, isActive = 0, ActiveAs = 0;
int usedGold = 0, usedLife = 0, tracker = 0;
//isActive = 1 - using life
//isActive = 2 - using gold

//ActiveAs = 1 - detecting magic
//ActiveAs = 2 - detecting traps
//ActiveAs = 3 - detecting invisibility
//ActiveAs = 4 - detecting scrying

object detector;

void create()
{
    ::create();

    set_name("greater ring of detection");
    set_id(({"ring", "greater ring of detection", "ring of detection",
    "band of energy", "energy ring", "energy band", "band"}));

    set_obvious_short("A band of energy");

    set_short("%^BOLD%^%^YELLOW%^Gr%^BOLD%^%^WHITE%^ea%^BOLD%^%^YELLOW%^t"+
    "%^BOLD%^%^WHITE%^e%^BOLD%^%^YELLOW%^r B%^BOLD%^%^WHITE%^a%^BOLD%^%^YELLOW%^"+
    "nd %^BOLD%^%^WHITE%^o%^BOLD%^%^YELLOW%^f D%^BOLD%^%^WHITE%^e%^BOLD%^%^YELLOW%^"+
    "t%^BOLD%^%^WHITE%^e%^BOLD%^%^YELLOW%^ct%^BOLD%^%^WHITE%^io%^BOLD%^%^YELLOW%^n"+
    "%^RESET%^");


    set_long("%^BOLD%^%^YELLOW%^This bizarre band %^BOLD%^%^WHITE%^wavers%^BOLD%^%^YELLOW%^ "+
    "and changes as you gaze upon it. It is constructed from %^BOLD%^%^WHITE%^raw%^BOLD%^%^YELLOW%^ "+
    "energy and whatever force holds it together is %^BOLD%^%^BLACK%^unknown%^BOLD%^%^YELLOW%^. "+
    "The band of energy is frequently a brilliant sun hue but %^BOLD%^%^BLACK%^darkens%^BOLD%^%^YELLOW%^ "+
    "and then explodes to an almost pure %^BOLD%^%^WHITE%^white%^BOLD%^%^YELLOW%^ continuously. "+
    "There are no markings, no writing, and nothing to make it seem more than a mundane item aside from "+
    "the substance from which it has been made.%^RESET%^");

    set_lore("%^BOLD%^%^WHITE%^The very existence of this band has been "+
    "debated by scholars for years. It was said to have been forged by a man "+
    "known as '%^BOLD%^%^CYAN%^Aygar - Master of Illusion%^BOLD%^%^WHITE%^' "+
    "though the very existence of Aygar has also been debated by the same scholars. "+
    "Perhaps this speaks to the power of the man?\n\n"+
    "Some whispered legends talk about a power beyond the normal weave being "+
    "used to forge the band and then infused into it. A power that allowed the "+
    "band to work for all time as long as it was powered by something of substance. "+
    "Most of these legends are far from complete.\n\n"+
    "Somehow a knowledge of the band stirs within you... and you realize "+
    "that you are able to command it to %^BOLD%^%^GREEN%^detect%^BOLD%^%^WHITE%^ "+
    "but you recognize that there will be a price to pay... in either life or gold. "+
    "Are you willing to pay such a price?%^RESET%^");

    set_property("lore difficulty",25);
    set_ac(0);
    set_weight(1);
	set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}

void init()
{
    ::init();
    add_action("detect_func", "detect");
    if(SetLevel) return;
    else
    {
        if(!objectp(ETO)) return;
        if(!ETO->is_player()) return;
        SetLevel = ETO->query_base_character_level();
        set_value(SetLevel * (random(300) + 200));
        return;
    }
}

void silence_band()
{
    string dType;
    if(!objectp(TO) || !objectp(ETO)) return;
    dType = convert_to_type("detect");
    //check stuff
    if(dType == "magic")
    {
        if(ETO->get_static("detecting magic"))
        {
            ETO->set_detecting_magic(0);
            tell_object(ETO, "%^BOLD%^%^GREEN%^With a sudden %^BOLD%^%^YELLOW%^JOLT%^BOLD%^%^GREEN%^ "+
            "your view of the world goes back to normal as you cease detecting magic!%^RESET%^");
        }
    }

    if(dType == "traps")
    {
        if(ETO->query_property("detecting_snares"))
        {
            ETO->remove_property("detecting_snares");
            tell_object(ETO, "%^BOLD%^%^BLUE%^Suddenly your senses dull as your ability to detect traps "+
            "returns to normal!%^RESET%^");
            if(ETO->query("is_auto_detecting_traps") && (int)ETO->query_skill("dungeoneering") < 15)
            {
                ETO->delete("is_auto_detecting_traps");
            }
        }
    }

    if(dType == "invisibility")
    {
        if(ETO->detecting_invis())
        {
            ETO->set_detecting_invis(0);
            tell_object(ETO, "%^BOLD%^%^WHITE%^With a sudden %^BOLD%^%^YELLOW%^JOLT%^BOLD%^%^WHITE%^ "+
            "your mind goes back to normal as your ability to see unseen objects fades!%^RESET%^");
        }
    }

    if(dType == "scrying")
    {
        if(objectp(ETO->query_property("detect scrying") || objectp(detector)))
        {
            ETO->remove_property("detect scrying");
            if(objectp(detector)) detector->self_destruct();
            tell_object(ETO, "%^BOLD%^%^BLACK%^Suddenly your body tenses before your mind seems to "+
            "almost collapse as your view of the world settles back into the old... your ability to "+
            "detect scrying attempts faded!");
        }
    }
    set_heart_beat(0);
    isActive = 0;
    ActiveAs = 0;
    usedGold = 0;
    usedLife = 0;
    return;
}

int spend_resource(int flag)
{
    int myCost;
    if(!objectp(TO) || !objectp(ETO) || !TO->query_worn()) return 0;
    if(!isActive || !ActiveAs) return 0;
    //health
    if(isActive == 1)
    {
        tracker=time();
        myCost = SetLevel / 10;
        if(myCost < 2) myCost = 2;
        myCost *= ActiveAs;
        if(!random(20)) myCost *= 2;
        usedLife += myCost;
        if(ETO->query_hp() < usedLife)
        {
            if(flag)
            {
                tell_object(ETO, "%^BOLD%^%^CYAN%^Your lifeforce is no longer strong enough to "+
                "power the insatiable band!%^RESET%^");
            }
            return 0;
        }
        if(!flag) return 1;
        if(!random(2))
        {
            tell_object(ETO, "%^BOLD%^%^CYAN%^The insatiable band continues to draw on your "+
            "lifeforce for its power!%^RESET%^");
        }
        ETO->set_hp(ETO->query_hp() - usedLife);
        ETO->heal(0);
        return 1;
    }
    if(isActive == 2)
    {
        tracker=time();
        myCost = SetLevel * 2;
        myCost *= ActiveAs;
        if(!random(20)) myCost *= 2;
        usedGold += myCost;
        if(ETO->query_money("gold") < usedGold)
        {
            if(flag)
            {
                tell_object(ETO, "%^BOLD%^%^YELLOW%^You no longer have enough gold to "+
                "power the insatiable band!%^RESET%^");
            }
            return 0;
        }
        if(!flag) return 1;
        ETO->add_money("gold", -usedGold);
        if(!random(2))
        {
            tell_object(ETO, "%^BOLD%^%^YELLOW%^The insatiable band continues to harvest "+
            "your gold coins to draw power!%^RESET%^");
        }
        return 1;
    }
    return 0;
}

int query_used_gold() { return usedGold; }
int query_used_life() { return usedLife; }

void heart_beat()
{
    if(!objectp(TO) || !objectp(ETO) || !TO->query_worn())
    {
        //set_heart_beat(0); //moved this to silence_band()
        silence_band();
        return;
    }
    if(!random(3))
    {
        if(!spend_resource(1))
        {
            //set_heart_beat(0); //moved this to silence_band()
            silence_band();
            return;
        }
    }
    return;

}

int wearme()
{
    tell_object(ETO, "%^BOLD%^%^WHITE%^A fleeting feeling of warmth encompasses your "+
    "body as you slip on the band.%^RESET%^");
    //set_heart_beat(1); //moved this to detect_func()
	return 1;
}

int removeme()
{
    tell_object(ETO, "%^BOLD%^%^WHITE%^A chill runs down your spine as the band slips from "+
    "your finger.%^RESET%^");
    silence_band();
    return 1;
}

int isMagic() { return 5; }

string convert_to_type(string what)
{
    if(!stringp(what)) return "ERROR";
    if(what == "detect")
    {
        switch(ActiveAs)
        {
            case 1:
                return "magic";
            case 2:
                return "traps";
            case 3:
                return "invisibility";
            case 4:
                return "scrying";
        }
    }
    if(what == "resource")
    {
        if(isActive == 1) return "life force";
        if(isActive == 2) return "gold";
    }
    return "ERROR";
}

int check_can_spend()
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(spend_resource(0)) return 1;
    tell_object(ETO, "%^BOLD%^%^RED%^You do not have enough "+convert_to_type("resource") +
    "to detect "+convert_to_type("detect")+"!%^RESET%^");
    ActiveAs = 0;
    isActive = 0;
    return 0;
}

int check_already_doing()
{
    int canDo = 1;
    string msg;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;

    switch(ActiveAs)
    {
        case 1:
            if(ETO->get_static("detecting magic"))
            {
                canDo = 0;
                msg = "%^BOLD%^%^RED%^You are already detecting magic!%^RESET%^";
            }
            break;
        case 2:
            if(ETO->query_property("detecting_snares"))
            {
                canDo = 0;
                msg = "%^BOLD%^%^RED%^Your ability to detect traps is already heightened!%^RESET%^";
            }
            break;
        case 3:
            if(ETO->detecting_invis())
            {
                canDo = 0;
                msg = "%^BOLD%^%^RED%^You are already detecting invisibility!%^RESET%^";
            }
            break;
        case 4:
            if(objectp(ETO->query_property("detect scrying")))
            {
                canDo = 0;
                msg = "%^BOLD%^%^RED%^You are already attempting to detect scrying attempts!%^RESET%^";
            }
            break;
    }
    if(!canDo)
    {
        tell_object(ETO, msg);
        ActiveAs = 0;
        isActive = 0;
    }
    return canDo;
}

int detect_func(string what)
{
    string dType, pType;
    if(!objectp(TO) || !objectp(ETO) || !TO->query_worn()) return 0;

    if(what == "off")
    {
        if(!isActive && !ActiveAs)
        {
            tell_object(ETO, "%^BOLD%^%^WHITE%^The band is not currently powered.%^RESET%^");
            return 1;
        }
        silence_band();
        return 1;
    }

    if(!stringp(what) || sscanf(what, "%s with %s", dType, pType) != 2)
    {
        tell_object(ETO, "%^BOLD%^%^GREEN%^You may <%^BOLD%^%^WHITE%^"+
        "detect magic, traps, scrying, or invisibility %^BOLD%^%^WHITE%^with %^BOLD%^%^CYAN%^life "+
        "%^BOLD%^%^WHITE%^or %^BOLD%^%^YELLOW%^gold%^BOLD%^%^GREEN%^> \n\nYou sense that "+
        "whichever you detect will impact the cost and you realize that "+
        "the cost will be ongoing, until you turn off the band. By using <"+
        "%^BOLD%^%^WHITE%^detect off%^BOLD%^%^GREEN%^> or deplete whichever source you "+
        "power it with.%^RESET%^");
        return 1;
    }

    if(dType != "magic" && dType != "traps" && dType != "scrying" && dType != "invisibility" && pType != "gold" && pType != "life")
    {
        tell_object(ETO, "%^BOLD%^%^GREEN%^You may <%^BOLD%^%^WHITE%^"+
        "detect magic, traps, scrying, or invisibility %^BOLD%^%^WHITE%^with %^BOLD%^%^CYAN%^life "+
        "%^BOLD%^%^WHITE%^or %^BOLD%^%^YELLOW%^gold%^BOLD%^%^GREEN%^> \n\nYou sense that "+
        "whichever you detect will impact the cost and you realize that "+
        "the cost will be ongoing, until you turn off the band. By using <"+
        "%^BOLD%^%^WHITE%^detect off%^BOLD%^%^GREEN%^> or deplete whichever source you "+
        "power it with.%^RESET%^");
        return 1;
    }

    if(isActive != 0 || ActiveAs != 0)
    {
        tell_object(ETO, "%^BOLD%^%^YELLOW%^The insatiable band is already detecting "+
        convert_to_type("detect")+ " using your "+convert_to_type("resource")+". Turn it off first either by "+
        "removing it or using <%^BOLD%^%^WHITE%^detect off%^BOLD%^%^YELLOW%^>%^RESET%^!%^RESET%^");
        return 1;
    }

    if(tracker + 60 > time()) { // 60 second cooldown
        tell_object(ETO, "%^BOLD%^%^YELLOW%^The insatiable band is still devouring your previous resources!%^RESET%^");
        return 1;
    }

    if(pType == "gold") isActive = 2;
    if(pType == "life") isActive = 1;

    if(dType == "magic")
    {
        ActiveAs = 1;
        if(!check_can_spend()) return 1;
        if(!check_already_doing()) return 1;

        ETO->set_detecting_magic(1);
        tell_object(ETO, "%^BOLD%^%^GREEN%^With a sudden %^BOLD%^%^YELLOW%^JOLT%^BOLD%^%^GREEN%^ "+
        "your view of the world changes as you begin detecting magic!%^RESET%^");
        spend_resource(1);
        set_heart_beat(1);
        return 1;
    }

    if(dType == "traps")
    {
        ActiveAs = 2;
        if(!check_can_spend()) return 1;
        if(!check_already_doing()) return 1;
        ETO->set_property("detecting_snares", 1);

        tell_object(ETO, "%^BOLD%^%^BLUE%^Suddenly your senses are heightened as your ability to "+
        "detect traps expands!%^RESET%^");
        spend_resource(1);
        set_heart_beat(1);
        return 1;
    }

    if(dType == "invisibility")
    {
        ActiveAs = 3;
        if(!check_can_spend()) return 1;
        if(!check_already_doing()) return 1;

        ETO->set_detecting_invis(1);
        tell_object(ETO, "%^BOLD%^%^WHITE%^With a sudden %^BOLD%^%^YELLOW%^JOLT%^BOLD%^%^WHITE%^ "+
        "your mind is expanded as you are able to see the unseen objects of the world!%^RESET%^");
        spend_resource(1);
        set_heart_beat(1);
        return 1;
    }

    if(dType == "scrying")
    {
        ActiveAs = 4;
        if(!check_can_spend()) return 1;
        if(!check_already_doing()) return 1;

        ETO->remove_property("detect scrying");

        detector = SCRY_D->add_detect_scrying(ETO);
        if(!objectp(detector))
        {
            tell_object(ETO, "Something went wrong with the band attempting to "+
            "detect scrying.");
            ActiveAs = 0;
            isActive = 0;
            return 1;
        }
        detector->set_detect_power(SetLevel + random(SetLevel));

        tell_object(ETO, "%^BOLD%^%^BLACK%^Suddenly your body tenses before your mind seems to "+
        "expand and your view of the world shifts slightly as you begin detecting scrying "+
        "attempts against you!%^RESET%^");
        spend_resource(1);
        set_heart_beat(1);
        return 1;
    }

    return 0;
}
