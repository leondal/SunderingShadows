// Slot changed from left/right foreleg to lower torso - this is the wemic/centaur "legs" slot. N, 1/18.
#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/armour/leather_greaves.c";

int SETUP;

string get_long()
{
    string str = "These greaves are fashioned from a leathery hide that is of the darkest midnight black.  It wraps securely around "
        "the wearer's lower legs and extends up until mid thigh.  Darker still are large scales taken from what must be a shadow "
        "dragon.  The scales are placed to fit over the shin and the sides and back of the calves, over the kneecap and the top "
        "of the thigh.  Those scales are so dark that they almost seem to drink in the light around them.";
    str = CRAYON_D->color_string(str, "very black", ({ "greaves", "leathery", "hide", "darkest", "midnight", "black", 
    "legs", "Darker", "large", "scales", "shadow", "dragon", "shin", "calves", "kneecap", "dark", "drink","light" }));
    return str;
}

string get_short()
{
    string str = "Shadow Stride";
    str = CRAYON_D->color_string(str, "very black");
    return str;
}

string get_obvious_short()
{
    string str = "stygian greaves";
    str = CRAYON_D->color_string(str, "very black");
    return str;
}
        

void create()
{
    ::create();
    set_name("Dragon Greaves");
    set_id(({ "greaves", "dragon greaves", "shadow greaves", "shadow dragon greaves", "shadow" }));    
    set_obvious_short(get_obvious_short());    
    set_short(get_short());    
    set_long(get_long());    
    set_lore("These greaves were rumored to be designed by a old shadow dragon named Gruntilliarzh as a reward to a loyal "
        "retainer who had served him well for many years.  Unfortunately for the retainer, the items were so unique that "
        "many people attempted to take them from him by force until one finally succeeded.  It was told that the retainer "
        "was incredibly quick during his life, and that the greaves somehow make him more deadly in battle, in addition to "
        "providing protection.");    
    set_property("lore difficulty",25);    
    set_value(95000);
    set_size(-1);    
    set_property("no curse",1);
    set_property("enchantment",5);    
    set_item_bonus("dexterity",4);    
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_struck((:TO,"struck":));
}


void init()
{
    string race;
    ::init();
    if(!objectp(ETO) || !interactive(ETO) || !living(ETO) || SETUP) { return; }
    race = ETO->query_race();
    switch(race)
    {
        case "centaur":
        case "wemic":
            TO->set_limbs(({ "lower torso" }));
            break;
        default:
            TO->set_limbs(({ "left leg","right leg"}));
            break;
    }

    TO->set_size(ETO->query_size());
    tell_object(ETO,"The greaves shift themselves to better fit you!");
    SETUP = 1;
    return;
}


int wear_func()
{
    string quest = "%^RESET%^%^YELLOW%^Returned the Dominion Warrior to eternal rest.%^RESET%^";
    
    if(ETO->query_name() == "Cruiser Tetron") { return 1; }
    
    if(member_array(quest,ETO->query_mini_quests())== -1 && member_array("Achieved: "+ quest,ETO->query_mini_quests())== -1) 
    {
        tell_object(ETO,"You have not earned the right to make use of this item.");
        return 0;
    }
   
    if((int)ETO->query_level() < 40) 
    {
        tell_object(ETO,"You are not strong enough to wear these greaves.");
        return 0;
    }
        
    tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETO->QCN+" pulls on the greaves and they mold perfectly to "+ETO->QP+" legs.%^RESET%^",ETO);
    tell_object(ETO,"%^BOLD%^%^BLUE%^You pull on the greaves and they mold perfectly to your legs.%^RESET%^");
    return 1;
}


int remove_func()
{
    tell_room(EETO, "%^MAGENTA%^"+ETO->QCN+" touches the greaves and they are simply in "+ETO->QP+" hand, already removed.%^RESET%^",ETO);
    tell_object(ETO, "%^MAGENTA%^You touch the greaves and they are simply in your hand, already removed!%^RESET%^");
    return 1;
}


int struck(int damage, object what, object who)
{
    if(!objectp(ETO) || !objectp(EETO)) { return 0; }
    tell_object(ETO,"%^RESET%^%^BOLD%^%^BLACK%^You feel "+who->QCN+"'s attack make contact and then you feel a pull from "
        "your greaves, sending you through the shadows to execute a quick attack!%^RESET%^");
    tell_room(EETO,"%^RESET%^%^BOLD%^%^BLACK%^As "+who->QCN+"'s attack makes contact with "+ETO->QCN+"'s greaves, "+ETO->QO+" "
        "vanishes for an instant and then reappears to launch a surprise attack!%^RESET%^",({ETO, who}));
    tell_object(who, "%^RESET%^%^BOLD%^%^BLACK%^As your attack makes contact with "+ETO->QCN+"'s greaves, "+ETO->QO+" vanishes "
        "for an instant and then reappears to launch a surprise attack!%^RESET%^");
    if(sizeof(ETO->query_attackers())) { ETO->execute_attack(); }    
    return damage;
}




