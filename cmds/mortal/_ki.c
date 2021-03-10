#include <std.h>
#include <daemons.h>

#define DEDICATIONS (["way of the shadow" : "%^BOLD%^%^BLACK%^Way of The Sh%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^d%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^w%^RESET%^",\
                      "way of the fist" : "%^BOLD%^%^WHITE%^Way of The F%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^st%^RESET%^",\
                      "way of the elements" : "%^BOLD%^%^RED%^Way of The %^BOLD%^%^WHITE%^E%^BOLD%^%^RED%^l%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^m%^BOLD%^%^RED%^e%^BOLD%^%^CYAN%^n%^BOLD%^%^WHITE%^t%^BOLD%^%^RED%^s%^RESET%^",\
                      "grandmaster of the way" : "%^BOLD%^%^BLUE%^Grandmaster of the Way" ])

#define ELE_FOCUS (["fire" : "%^BOLD%^%^RED%^Fire", "cold" : "%^BOLD%^%^WHITE%^Cold", "electricity" : "%^BOLD%^%^BLUE%^Electricity", "acid" : "%^BOLD%^%^GREEN%^Acid"])

inherit DAEMON;

int cmd_ki(string str)
{
    int ki, max_ki, *kiLevels, myLev, x;
    string *kiSpells, myWay, YOU, *tmp = ({}), lvl, MyType;
    object ob;
    if(stringp(str)) str = lower_case(str);
    if(stringp(str) && avatarp(TP) && strsrch(str, "focus") == -1)
    {
        if(!objectp(ob = find_player(str)))
        {
            tell_object(TP, "There is no such player online!");
            return 1;
        }
    }
    else if(stringp(str) && TP->is_class("monk") && ((string)TP->query("monk way") == "way of the elements" || FEATS_D->usable_feat(TP,"grandmaster of the way")))
    {
        if(str == "focus")
        {
            tell_object(TP, "You must use ki focus <elemental type>. Valid types are fire, cold, acid, and "+
            "electricity.");
            return 1;
        }
        if(str == "init")
        {
            USER_D->init_pool(TP, "ki");
            tell_object(TP, "Your ki has been re-initialized.");
            return 1;
        }
        if(sscanf(str, "focus %s", MyType) == 1)
        {
            if(member_array(MyType, keys(ELE_FOCUS)) == -1)
            {
                tell_object(TP, "Valid focus types are currently "+
                "fire, cold, acid, and electricity. Please choose one of "+
                "those.");
                return 1;
            }
            else
            {
                if((string)TP->query_true_name() == "kaide")
                {
                    tell_object(TP, "Saide put this here, just to tell you that you "+
                    "are NOT focusing on "+MyType+" EVER, even if there is A FIRE!");
                }
                tell_object(TP, "%^BOLD%^%^CYAN%^You are now focusing on "+ELE_FOCUS[MyType]+
                "%^BOLD%^%^CYAN%^ as your elemental type. This will impact the type of "+
                "guardians that may appear, if you have the elemental opportunist feat, "+
                "and the damage type of flurry of blows.%^RESET%^");
                TP->set("monk_ele_focus", MyType);
                return 1;
            }
        }
    }
    else ob = TP;
    if(ob == TP) YOU = "You";
    else YOU = "They";
    if(!objectp(ob))
    {
       tell_object(TP, "Something went wrong.");
       return 1;
    }
    if(!ob->is_class("monk"))
    {
        tell_object(TP, YOU +" are not a monk.");
        return 1;
    }

    myWay = ob->query("monk way");
    if(FEATS_D->usable_feat(ob, "grandmaster of the way")) { myWay = "grandmaster of the way"; }
    myLev = ob->query_prestige_level("monk");

    if(stringp(myWay)) tmp += ({"%^BOLD%^%^GREEN%^Dedication%^RESET%^: %^BOLD%^%^WHITE%^"+DEDICATIONS[myWay]+"\n"});
    else tmp += ({"%^BOLD%^%^GREEN%^Dedication%^RESET%^: %^BOLD%^%^WHITE%^None %^RESET%^(%^BOLD%^%^CYAN%^Available at level 3%^RESET%^)\n"});
    if(myWay == "way of the elements")
    {
        if(!stringp(ob->query("monk_ele_focus")))
        {
            tmp += ({"%^BOLD%^%^GREEN%^Elemental Focus%^RESET%^ : "+ELE_FOCUS["fire"]});
        }
        else tmp += ({"%^BOLD%^%^GREEN%^Elemental Focus%^RESET%^ : "+ELE_FOCUS[(string)ob->query("monk_ele_focus")]});
        tmp += ({""});
    }
    if (myWay == "way of the elements" || myWay == "way of the shadow" || myWay == "grandmaster of the way") {
        mapping kiindex = MAGIC_D->index_ki_spells_by_level(TP);
        kiLevels = filter_array(keys(kiindex), "sort_ki_spells", "/daemon/user_d.c", myLev);
        kiLevels = sort_array(kiLevels, "numerical_sort", FILTERS_D);
        if (sizeof(kiLevels)) {
            tmp += ({ "%^BOLD%^%^GREEN%^Available Spells \n%^RESET%^" });
        }
        for (x = 0; x < sizeof(kiLevels); x++) {
            int cost;
            lvl = "Level " + kiLevels[x];
            lvl = arrange_string(lvl, 9);
            cost = kiLevels[x] / 3;
            cost = cost > 6 ? 6 : cost;
            tmp += ({ "%^BOLD%^%^GREEN%^" + lvl + "%^RESET%^: %^BOLD%^%^WHITE%^" + implode(kiindex[kiLevels[x]], ", ") + ". %^RESET%^( %^BOLD%^%^CYAN%^Ki Cost: " + cost + " %^RESET%^)%^RESET%^" });
            continue;
        }
        tmp += ({ "" });
    }
    ki = ob->query("available ki");
    max_ki = ob->query("maximum ki");
    if(max_ki)
    {
        tmp += ({"%^BOLD%^%^GREEN%^Ki%^RESET%^: %^CYAN%^"+ki+"%^RESET%^/%^BOLD%^%^CYAN%^"+max_ki});
        if(ki < max_ki)
        {
            tmp += ({"%^BOLD%^%^GREEN%^Next Passive Ki Regeneration%^RESET%^: %^BOLD%^%^WHITE%^"+((int)ob->query("last ki regen") - time())+" seconds.%^RESET%^"});
        }
    }
    TP->more(tmp);
    return 1;
}

int help(){
   write(
"
%^CYAN%^NAME%^RESET%^

ki - monks spells

%^CYAN%^SYNOPSIS%^RESET%^

ki
ki focus %^ORANGE%^%^ULINE%^ELEMENT%^RESET%^
ki init

%^CYAN%^DESCRIPTION%^RESET%^

This command display your dedication if you have chosen one, your spells if your dedication grants any for your current level (and the ki cost per casting), your available, and maximum ki, and how long it will be until you passively regenerate more ki.

Ki is not available to you until you reach at least level 2 in the monk class.

You may visit your diety's temple to pick the dedication that you wouldplike, however, you must be at least level 3 in order to do so.

%^ORANGE%^<ki focus %^ORANGE%^%^ULINE%^ELEMENT%^RESET%^%^ORANGE%^>%^RESET%^ will allow a monk dedicated to the way of the elements to pick an elemental type to focus on for now. This dictates the type of damage that flurry of blows will be, as well as the type of guardians that may show up with the elemental opportunist feat. It does not change spell damage types. The default is fire. Valid options are fire, cold, electricity, and acid.

%^CYAN%^SEE ALSO%^RESET%^

monk, way of the fist, way of the elements, way of the shadow, prompt, hp
"
   );
   return 1;
}
