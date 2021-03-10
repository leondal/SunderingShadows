#include <std.h>
#include <magic.h>
inherit "/d/common/obj/armour/breastplate.c";

// gawd I hate crayoning
#define B       +"%^BOLD%^%^BLACK%^"+
#define L       +"%^RESET%^%^BLUE%^"+
#define S       +"%^RESET%^"+
#define D       +"%^RESET%^%^BOLD%^"+
#define M       +"%^MAGENTA%^"+
#define Y       +"%^YELLOW%^"+
#define R       +"%^RED%^"+
#define O       +"%^ORANGE%^"+
#define G       +"%^GREEN%^"+
#define C       +"%^CYAN%^"+
#define INK     +""B"i"L"n"B"k"L"y"S""B""+  // inky
#define CINK    +""B"I"L"n"B"k"L"y"S""B""+  // Inky
#define HAR     +""B"Harbi"L"n"B"ger"L"'"B"s "L"Citadel"S""+ // Harbinger's Citadel
#define BP      +""L"breast"B"plate"S""B""+ // breastplate
#define DQ      +""M"d"S"i"R"s"S"q"M"u"B"i"L"e"Y"t"O"i"D"n"M"g"S""B""+ // disquieting
#define SH      +""L"s"B"h"L"a"B"p"M"e"L"s"B""+ // shapes
#define SF      +""L"su"C"rfac"M"e"B""+ // surface
#define MA      +""D"ma"B"t"D"er"S"i"D"al"B""+ // material
#define LI      +""S""G"l"D"i"G"v"S"i"G"n"S""G"g"B""+ // living
#define WO      +""L"w"S"o"D"r"C"l"L"d"B""+ // world
#define AR      +""D"arm"B"o"D"r"B""+ // armor
#define IT      +""D"int"B"e"D"rloc"B"k"D"ing"B""+ // interlocking
#define PA      +""G"plat"D"e"S""G"s"B""+ // plates
#define ST      +"st"D"e"S"e"B"l"+ // steel
#define desc    what->query_short()

int is_metal() { return 0; } // made from shaped fragments of astral plane
int BONUSES_SET;


void create()
{
    ::create();
    set_name("Harbinger's Citadel");
    set_id(({ "plate", "breastplate", "breast plate","citadel","harbinger's citadel" }));    
    set_obvious_short(""INK" "BP"");    
    set_short(""HAR"");    
    set_long(""B"This "INK" suit of "BP" is a "DQ" sight to behold.  "CINK" "SH" move beneath the "SF" of the "MA" as "
        "if a whole "LI" "WO" were contained inside of the "AR".  The "SH" glide under the "SF" and dart away any time you look "
        "directly at them.  The "BP" is fashioned of "IT" "PA" of the "INK" "MA", hardened to mimic the rigidity of "
        ""ST".  The "PA" are attached to a more flexible version of the same sort of "INK" "MA" that forms an under layer of "
        "flexible "AR" that molds perfectly to the wearers body."S"");  
        
    set_value(125000);    
    set_property("no curse",1);
    set_property("enchantment",6);

    set_property("lore difficulty",35);
    set_lore("All the stories regarding the "HAR" "S"are so ancient that it's impossible to know if there could be "
        "any truth to them.  In perhaps the only known example in all of history, it was said that this armor was fashioned by "
        "an Aboleth Savant.  The Savant, who's name has been lost to time, was said to have torn a piece of the fabric of the "
        "astral plane away and used its incredible will to fashion the material into a suit of powerful armor.  The armor was then "
        "given to a warrior who was charged with the destruction of a legendary Illithid Slayer named Ipok'Tu-Savken.  The Ipok'Tu "
        "was rumored to be totally immune to all forms of psionics, so the Savant was forced to turn to more traditional means in order "
        "to confront his enemy.  History has no tales about what happened to the warrior who the armor was fashioned for or what "
        "eventually happened to Ipok'Tu-Savken.  The last known user of the armor was a member of Lord Thundercracker's "
        "Dark Dominion.");
      
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_struck((:TO,"struck":));
}


void init()
{
    ::init();
    if(!objectp(TO) || !objectp(ETO) || !interactive(ETO) || BONUSES_SET) { return; }
    set_bonuses();
    TO->set_size(ETO->query_size());
    tell_object(ETO,"%^BLUE%^The "DQ" "AR" seems to reorganize itself to fit you!");
    return;    
}


void set_bonuses()
{
    string *classes,*stats=({});
    mapping reqs;
    int i,bonus;
    object class_ob;
    if(!objectp(ETO) || !interactive(ETO) || BONUSES_SET) { return; }
    
    classes = ETO->query_classes();

    for(i=0;i<sizeof(classes);i++)
    {
        class_ob = find_object_or_load("/std/class/"+classes[i]+".c");
        if(!objectp(class_ob)) { stats += ({ "strength" }); } 
        reqs = class_ob->stat_requirements();
        stats += keys(reqs);
    }
    
    switch(sizeof(stats))
    {
        case 1: bonus = 5; break;
        case 2: bonus = 3; break;
        default: bonus = 2; break;
    }
    
    for(i=0;i<sizeof(stats);i++)
    {
        set_item_bonus(stats[i],bonus);        
    }
    BONUSES_SET = 1; 
}


int wear_func()
{
    string quest = "%^RESET%^%^YELLOW%^Returned the Dominion Warrior to eternal rest.%^RESET%^";
    
    if(ETO->query_name() == "Cruiser Tetron") { return 1; }
    
    if(member_array(quest,ETO->query_mini_quests())== -1 && member_array("Achieved: " + quest,ETO->query_mini_quests())== -1) 
    {
        tell_object(ETO,"You have not earned the right to make use of this item.");
        return 0;
    }
   
    if((int)ETO->query_level() < 40) 
    {
        tell_object(ETO,"You are not strong enough to wear this armor.");
        return 0;
    }
        
    tell_room(EETO,""B""+ETO->QCN+" touches the "DQ" "AR" and it molds itself to "+ETO->QP+" body of its own accord.",ETO);
    tell_object(ETO,""B"You touch the "DQ" "AR" and it molds itself to your body of its own accord!"S"");
    return 1;
}


int remove_func()
{
    tell_room(EETO,""B""+ETO->QCN+"'s "DQ" "AR" seems to slough off by itself"S"",ETO);
    tell_object(ETO,""B"Your "DQ" "AR" seems to slough off by itself!"S"");
    return 1;
}


int query_size()
{ 
    if(objectp(ETO) && living(ETO)) { return ETO->query_size(); }
    else return -1;
}


int struck(int damage, object what, object who)
{
    int dam,condition;
    string *ids;
    if(!objectp(ETO) || !objectp(EETO) || !living(ETO)) { return 0; }


    switch(random(6))
    {
    case 0:
        
        if(objectp(who) && objectp(what) && what->is_weapon())
        {
            tell_object(ETO,""L"A surge of energy leaps from your "DQ" "AR" as "+who->QCN+" "L"hits you with "+who->QP+" "+desc+""L", nearly knocking the "+desc+" "L"from "+who->QP+" "L"hands!"S"");
            tell_room(EETO,""L"A surge of energy leaps from "+ETO->QCN+"'s "DQ" "AR" and hits "+who->QCN+""L", nearly knocking "+who->QP+" "L" "+desc+" from "+who->QP+" "L"hands!"S"",({who,ETO}));
            
            if(!who->fort_save(ETO->query_level()))
            {
                tell_object(who,""L"A surge of energy leaps from "+ETO->QCN+"'s "DQ" "AR""L", knocking your "+desc+" "L"from your hand!"S"");
                ids = what->query_id();
                if(who->query_property("disarm time") < time())
                {
                    who->force_me("unwield "+ids[0]);
                    who->remove_property("disarm time");
                    who->set_property("disarm time",time()+ (ROUND_LENGTH * roll_dice(1,4)));
                }
                return 0;
            }
            else
            {
                tell_object(who,""L"A surge of energy leaps from "+ETO->QCN+"'s "DQ" "AR""L", nearly knocking your "+desc+" "L"from your hand!"S"");            
            }
        }
        
        condition = TO->query_overallStatus();
        TO->set_overallStatus(condition + damage);
        if(TO->query_overallStatus() > 100) { TO->set_overallStatus(100); }
        tell_object(ETO,""L"The "DQ" "AR" "L"seems to absorb the energy from the attack and uses it to repair itself!"S"");
        return 0;  

    case 1:
    
        if(objectp(who))
        {
            tell_object(ETO,""L"One of the "SH" "L"from your "DQ" "AR" "L"leaps free and dives into "+who->QCN+""L"'s forehead!"S"");
            tell_room(EETO,""L"One of the "SH" "L"from "+ETO->QCN+""L"'s "DQ" "AR" "L"leaps free and dives into "+who->QCN+""L"'s forehead!"S"",({who,ETO}));
            tell_object(who,""L"One of the "SH" "L"from "+ETO->QCN+""L"'s "DQ" "AR" "L"leaps free and dives into your forehead!"S"");
            
            if(!who->will_save(ETO->query_level()))
            {                
                tell_object(who,""R "You feel soul crushing pain as your mind is assaulted from the inside!"S"");
                who->do_damage("head", roll_dice(1,6) * damage);
                who->set_paralyzed(roll_dice(1,6),""M"Your mind is being assaulted from the inside!"S"");
                return 0;
            }
            tell_object(who,""C"You painfully drive the foreign invader from your mind!"S"");
            who->do_damage("head",damage);
            return 0;
        }
        // This falls through intentionally, if no valid attacker then do the next special

    default:
    
        tell_object(ETO,""L"Your "DQ" "AR" "L"absorbs the force of the attack and sends it to your body in the form of healing energy!"S"");
        ETO->add_hp(damage * roll_dice(1,6));
        return 0;
    }

}


