#include <std.h>
inherit "/d/common/obj/weapon/club.c";

#define HATEDRACE ({"drow","elf","werewolf","ogre","ogre-mage","undead","kobold",\
"goblin","orc","half-elf","half-orc","wemic","voadkyn","gnoll","giant","dwarf","titan",\
"hobgoblin","half-drow","beastman","bugbear","firbolg","troll","halfling","gnoll"})

string hrace;

void do_update() 
{
    set_short(capitalize(hrace) + " basher");
    set_long("%^BOLD%^%^GREEN%^This small club is made from "+
    "a %^BOLD%^%^BLACK%^blackened "+
    "%^BOLD%^%^GREEN%^oak.  The head of the club is the "+
    "thickest part and is covered "+
    "with %^YELLOW%^knots%^BOLD%^%^GREEN%^.  The club "+
    "gradually narrows to the opposite "+
    "end, which serves as a handle.  The handle has a "+
    "piece of %^MAGENTA%^dirty brown%^BOLD%^%^GREEN%^ "+
    "cloth wrapped around it several layers thick and a "+
    "%^RED%^phrase%^BOLD%^%^GREEN%^ "+
    "is roughly scribed into it.  The entire "+
    "surface of the club %^YELLOW%^glistens"+
    "%^BOLD%^%^GREEN%^ from years of frequent use.%^RESET%^");
    TO->delete("read");
    set_read("Me " + hrace + " basher!");	
}

void create()
{
    ::create();
    hrace = HATEDRACE[random(sizeof(HATEDRACE))];
    set_language("giant");
    do_update();
    set_name("small club");
    set_id(({ "small club", "club", "oak club", "small oak club" }));
    set_obvious_short("A small club");
    set_value(1000);
    set_property("enchantment",3);
    set_hit((:TO,"hit_func":));
    set_wield((:TO,"wield_me":));
    set_unwield((:TO,"unwield_me":));
}

void init() 
{
    ::init();
    if(avatarp(ETO)) 
    {
        add_action("hrace_change","changehrace");
    }
}

int hrace_change(string str) 
{
    if(!avatarp(ETO) && !wizardp(ETO)) 
    {
        return 0;
    }
    if(!str) 
    {
        write("Please specify the race you want to make the hated race.");
        return 1;
    }
    if(hrace == lower_case(str)) 
    {
        write("The hated race is already " + lower_case(str) + ".");
        return 1;
    }
    if(str) 
    {
        hrace = lower_case(str);
        if(query_wielded()) 
        {
            ETO->force_me("unwield club");
        }
        do_update();
        write("The hated race of the club is now set to " +hrace+ ".");
        return 1;
    }	
}

int wield_me() 
{
    if(ETO->query_highest_level() < 15 || 
    ((string)ETO->query_race() == hrace && interactive(ETO))) 
	{
        tell_object(ETO,"%^RED%^The club keeps slipping "+
        "from your hands!%^RESET%^");
        return 0;
    }
    tell_object(ETO,"%^RED%^You growl in anger and prepare to "+
    "bash some %^BOLD%^%^WHITE%^skulls%^RED%^!%^RESET%^");
    tell_room(EETO,ETO->QCN + "%^RED%^ growls angrily "+
    "and suddenly becomes enraged!%^RESET%^",ETO);
    return 1;
}

int unwield_me() 
{
    tell_object(ETO,"%^RED%^You calm down considerably, "+
    "no longer plagued with the "+
    "overwhelming desire to bash %^BOLD%^%^WHITE%^skulls%^RED%^.%^RESET%^");
    if(!ETO->query_invis()) 
    {
        tell_room(EETO,ETO->QCN + "%^RED%^ shakes " + 
        ETO->QP+" head and seems to calm down considerably.%^RESET%^",ETO);
    }
    return 1;
}

int hit_func(object targ){
    int chance, dam;
    if((string)targ->query_race() == hrace) 
    {
        chance = 650;
        dam = roll_dice(1, (int)TO->query_enchantment() * 2);
    }
	
    if((string)targ->query_race() != hrace) 
    {
        chance = 350;
        dam = roll_dice(1, 2);
    }

    if(random(1000) < chance)
    {
        tell_room(EETO,"The small club makes a loud crack as "
        +ETO->QCN+" smacks "+targ->QCN+" with it.",({ETO,targ}));
        tell_object(ETO,"The small club makes a loud crack as it "+
        "smacks "+targ->QCN+".");
        tell_object(targ,"The small club makes a loud crack as "+
        ETO->QCN+" hits you with with it.");
        return dam;
    }
}
