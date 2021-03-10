#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

string which_skill, skill_str;
int bonus, skill;
void choose_skill();

void init() 
{
    ::init();
    if(interactive(ETO)) 
    {
        if(TO->add_item_owner(ETOQN)) 
        {
            TO->set_size(ETO->query_size());
        }
    }
}

void create()
{
    ::create();
    set_name("mummified hand");
	
    set_id(({ "necklace", "hand", "hand necklace", 
    "mummified hand", "mummified hand necklace", 
    "halfling hand", "hagtharts hand", 
    "mummified hagtharts hand", "halfling hand necklace" }));
	
    set_short("%^BOLD%^%^RED%^Hagth%^BOLD%^%^GREEN%^ar%^BOLD%^"+
    "%^RED%^ts %^BOLD%^%^WHITE%^m%^BOLD%^RED%^u%^BOLD%^"+
    "%^WHITE%^mm%^BOLD%^%^RED%^ufied h%^BOLD%^"+
    "%^GREEN%^a%^BOLD%^%^RED%^nd%^RESET%^");
	
    set_obvious_short("A mummified hand necklace");

    set_long("%^BOLD%^%^RED%^This disturbing necklace holds the "+
    "shriveled and mummified hand of what appears to have been a "+
    "halfling.  The chain of the necklace is made from a tarnished "+
    "%^BOLD%^%^WHITE%^silver%^BOLD%^%^RED%^ that has easily seen more "+
    "than a few years out in the weather.  "+
    "The chain hooks through the hand where it was once connected "+
    "to a wrist and the wound that took the hand has been "+
    "cauterized around the %^BOLD%^%^WHITE%^chain%^BOLD%^%^RED%^ "+
    "to make certain it is held in "+
    "place.  The fingers on the hand are curled in close "+
    "to the palm and seem to point at an %^BOLD%^%^BLACK%^inscription%^BOLD%^%^RED%^ that "+
    "has been sewn into the palm.%^RESET%^");
    
    set_language("halfling");
    set_read("%^RED%^May my hand lend aid to all my fellow "+
    "rogues throughout all centuries.\n\n"+
    "Hagthart, The Renown%^RESET%^");

    set_lore("This disturbing necklace was said to have been "+
    "the renown rogue hagthart's last and lasting contribution "+
    "to the living.  He supposedly lived some several centuries "+
    "ago and eventually died from old age.  The legends suggest "+
    "a powerful wizard caught him breaking into his tower "+
    "when he was a young lad and for some reason befriended him.  "+
    "Hagthart spent many a day listening to the wizard and "+
    "assisting him.  The ensuing friendship between hagthart and "+
    "the old wizard lasted even beyond hagthart's death.  It is "+
    "believed that the wizard took one of his hands, made it "+
    "into a necklace, and imbued it with a magic that would grant "+
    "temporary knowledge to the rogue who donned it.  Strangely, "+
    "it has been reported that more than one of them exist and it "+
    "is likely that the wizard was, in fact, a necromancer and "+
    "used hagthart's body in his experiments.  Whatever the "+
    "truth maybe, it is certain that hagthart has lived on.");

    set_weight(5);
    set_value(1000);
    set_size(1);
    set_property("enchantment",3);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    choose_skill();
    set_item_bonus(which_skill,2);
}

void choose_skill() 
{
    switch(random(4)) 
    {
        case 0:
            which_skill = "thievery";
            //which_skill = "pick pockets";
            skill_str = "%^RED%^you think it would be easier to "+
            "probe the pockets of an unsuspecting victim.%^RESET%^";
            break;
        case 1:
            which_skill = "dungeoneering";
            //which_skill = "open lock";
            skill_str = "%^BLUE%^with the proper tools "+
            "you're more certain than ever that you could "+
            "open any lock.%^RESET%^";
            break;
        case 2:
            which_skill = "dungeoneering";
            //which_skill = "find/remove traps";
            skill_str = "%^CYAN%^you feel "+
            "more confident in your ability to remove "+
            "traps.%^RESET%^";
            break;
        case 3:
            which_skill = "athletics";
            //which_skill = "climb walls";
            skill_str = "%^BOLD%^%^GREEN%^you feel "+
            "the grip in your hands strengthen and "+
            "ache to go for a climb somewhere.%^RESET%^";
            break;
    }
    bonus = 2;
}

int BonusCheck(string BonusName)
{
    if((ETO->is_class("thief") || ETO->is_class("bard")) && 
    (int)ETO->query_thief_skill(which_skill) < 90) 
    {
        return 1;
    }
    return 0;
}

int wearme() 
{
    if(!objectp(ETO)) { return 0; }
    if(!TO->query_owns_item(ETOQN)) 
    {
        tell_object(ETO,"The magic of the hand rejects you!");
        return 0;
    }

    tell_object(ETO,"You feel a strange power flow "+
    "out from the hand and "+skill_str);
    return 1;
}

int removeme() 
{
    if(!objectp(ETO)) { return 1; }
    tell_object(ETO,"You feel the strange power "+
    "flee from your grasp.");
    return 1;
}