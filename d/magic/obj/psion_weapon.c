#include <std.h>

inherit WEAPON;
string owner;

int FLAG;
void make_me(string str);


void create()
{
    ::create();
    set_name("energy weapon");
    set_short("a shimmering energy weapon");
    set_long("If you are seeing this, contact a wiz and tell "+
        "them what you were manifesting and that you got this "+
        "message.  Something is wrong with the power.");
    set_id(({"weapon","psion weapon","energy weapon"}));
    set_type("piercing");
    set_weight(0);
    set_value(0);
    set("no curse",1);
    set_prof_type("magic weapons");
    set_wc(1,8);
    set_large_wc(1,10);
    set_wield((:TO, "extra_wield":));
    set_unwield((:TO,"extra_unwield":));
    set_hit((:TO,"hit_func":));
    FLAG = 0;
}


void init()
{
    int ench;

    ::init();
    if(stringp(owner)) return;
    if(interactive(TP) && TP == ETO)
    {
        owner = TPQN;
    }
    
    ench = ((int)TP->query_guild_level("psion"))/5;
    if(ench < 0) ench = 0;
    if(ench > 10) ench = 10;
    
    set_property("no curse",1);
    set_property("enchantment",ench);
}


int extra_wield()
{
    if(interactive(TP) && owner != (string)TPQN)
    { 
        tell_object(TP,"You are not allowed to wield this weapon.");
        return 0;
    }
    
    if(objectp(ETO)) 
    {
        if((int)ETO->query_guild_level("psion") > 5 || (int)ETO->query_guild_level("psywarrior") > 10)
        {
            set_item_bonus("attack bonus",2);
            //ETO->add_attack_bonus(2);
            //FLAG = 1;
        }
        return 1;
    }
}


int extra_unwield()
{
    if(objectp(ETO)) 
    {
        //if(FLAG) ETO->add_attack_bonus(-2);
    }
    return 1;
}


int drop()
{
    tell_object(TP,"Your hand will not release the energy weapon!");
    return 1;
}


int save_me(string file){ return 1;}


void make_me(string str)
{
    switch(str)
    {
    case "staff": 
    
        set_short("%^YELLOW%^Scepter of %^CYAN%^E%^YELLOW%^n"+
            "%^CYAN%^e%^YELLOW%^r%^CYAN%^g%^YELLOW%^y%^RESET%^");
        set_id(({"weapon","psion weapon","energy weapon","staff","scepter","scepter of energy"}));
        set_long("%^BOLD%^Fashioned from pure %^CYAN%^"+
            "psychic energy%^WHITE%^, this staff stands a "+
            "good six feet tall.  Its features seem to blur "+
            "as the weapon is moved, s%^RESET%^h%^BOLD%^i"+
            "%^RESET%^m%^BOLD%^m%^RESET%^e%^BOLD%^r%^RESET%^i"+
            "%^BOLD%^n%^RESET%^g %^BOLD%^through shades of "+
            "%^YELLOW%^yellow%^WHITE%^, %^GREEN%^green%^WHITE%^, "+
            "and %^CYAN%^blue%^WHITE%^.  The staff moves with "+
            "an amazing quickness, as though it can sense the "+
            "wielder's every thought.%^RESET%^");
        break;
        
    case "battleaxe": 
    
        set_size(3);
        set_wc(1,10);
        set_short("%^BOLD%^%^RED%^M%^CYAN%^i%^RED%^n"+
            "%^CYAN%^d %^RED%^C%^CYAN%^l%^RED%^e%^CYAN%^"+
            "a%^RED%^v%^CYAN%^e%^RED%^r%^RESET%^");
        set_id(({"weapon","psion weapon","energy weapon","axe","battleaxe","cleaver","mind cleaver"}));
        set_long("%^BOLD%^Fashioned from pure %^CYAN%^"+
            "psychic energy%^WHITE%^, this battleaxe sports "+
            "two wicked %^RED%^heads %^WHITE%^balanced across "+
            "a haft of %^YELLOW%^light%^WHITE%^.  The axeheads "+
            "%^RED%^r%^RESET%^%^RED%^i%^BOLD%^p%^RESET%^%^RED%^"+
            "p%^BOLD%^l%^RESET%^%^RED%^e %^BOLD%^%^WHITE%^in "+
            "shades of %^RED%^red%^WHITE%^, each ending in a "+
            "glimmering arc of %^CYAN%^steel blue%^WHITE%^.  "+
            "The axe moves with an amazing quickness, as "+
            "though it can sense the wielder's every thought.%^RESET%^");
        break;
        
    default:
    
        set_short("%^BOLD%^%^GREEN%^E%^CYAN%^g%^GREEN%^o%^CYAN%^'"+
            "%^GREEN%^s %^CYAN%^E%^GREEN%^d%^CYAN%^g%^GREEN%^e%^RESET%^");
        set_id(({"weapon","psion weapon","energy weapon","sword","scimitar","edge","ego's edge"}));
        set_long("%^BOLD%^Though crafted only of light and %^CYAN%^"+
            "psychic energy%^WHITE%^, this short sword looks utterly "+
            "real.  The blade is formed of %^GREEN%^c%^CYAN%^o"+
            "%^GREEN%^r%^CYAN%^u%^GREEN%^s%^CYAN%^c%^GREEN%^a"+
            "%^CYAN%^t%^GREEN%^i%^CYAN%^n%^GREEN%^g %^CYAN%^blue "+
            "%^WHITE%^and %^GREEN%^green %^WHITE%^light that seems "+
            "to hold a keen slashing edge.  The handle is composed "+
            "of deeper %^BLUE%^blue light%^WHITE%^ that molds "+
            "to the wielder's hand.  The short sword moves with "+
            "an amazing quickness, as though it can sense the "+
            "wielder's every thought.%^RESET%^");
        set_size(1);
        break;
    }
}


int hit_func(object targ)
{
    targ = ETO->query_current_attacker();
    if(!objectp(ETO)) return 1;
    if(!objectp(targ)) return 1;

    if(!random(6)) 
    {
        tell_object(ETO,"%^BOLD%^%^CYAN%^The weapon emits a burst "+
            "of energy as it connects with "+targ->QCN+"!");
        tell_object(targ,"%^BOLD%^%^CYAN%^You feel a blast of "+
            "energy wrack your body as "+ETOQCN+" strikes you!");
        tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+"'s weapon emits a burst "+
            "of energy as it connects with "+targ->QCN+"!",({ETO,targ}));
        targ->do_damage("torso",random(6)+6);
        return 1;
    }
}
