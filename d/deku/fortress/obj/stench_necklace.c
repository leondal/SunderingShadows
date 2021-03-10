#include <std.h>
#include <daemons.h>
#define WAIT_TIME 1200

inherit "/d/common/obj/jewelry/necklace";

int used_time;
void create()
{
    ::create();
    set_name("emerald necklace");
    set_id(({ "necklace", "stench necklace","emerald necklace",
    "necklace of horrid stench", "horrid stench necklace" }));

    set_short("%^YELLOW%^N%^BOLD%^%^GREEN%^e%^YELLOW%^cklac%^BOLD%^"+
    "%^GREEN%^e %^YELLOW%^of h%^RED%^o%^YELLOW%^rr%^RED%^i"+
    "%^YELLOW%^d %^BOLD%^%^GREEN%^stench%^RESET%^");
    set_obvious_short("An emerald necklace");

    set_long("%^BOLD%^%^GREEN%^The band of this necklace is "+
    "made from numerous oval pieces of emerald that have "+
    "been attached to one another.  The band connects together "+
    "with a %^BOLD%^%^BLACK%^dark metal%^BOLD%^%^GREEN%^ clasp.  "+
    "A heavier, thicker, and round emerald hangs "+
    "down from the front of the necklace.  The surface of "+
    "the larger emerald is smooth and seems to reflect "+
    "even the most trivial amount of light into a "+
    "magnificent dancing spectrum of green hues.  "+
    "A barely visible inscription has been carefully "+
    "scribed onto the understand of it.%^RESET%^");

    set_read("Poison vapors hide within,\n"+
    "Such sweet reflection masks such dark deception,\n"+
    "To you my sweet love, may you "+
    "%^BOLD%^%^GREEN%^choke%^RESET%^.\n\n"+
    "Arnalian Zult");

    set_lore("The ancestor of this necklace is said to have been the final "+
    "anniversary gift received by the wife of a mysterious "+
    "man known as Arnalian Zult.  The stories suggest the man "+
    "went into a mindless rage after finding out his wife had "+
    "been in several adulterous affairs, but then seemingly calmed.  "+
    "The man finally gave the necklace to his wife and reportedly "+
    "just laughed as she fell over choking from a heavy odor "+
    "of decay that seemed to drain the life from her, he "+
    "was said to have died with her.  After his death the "+
    "necklace was studied and its magic recreated by a "+
    "necromancer who managed to fashion a frightful number of "+
    "the necklaces to distribute between his enemies and some allies.  "+
    "This necklace is probably one of those.");

    set_language("common");
    set_weight(4);
    set_value(1000);
    set_size(-1);
    set_property("enchantment",3);
    set_item_bonus("damage bonus", 2);
    set_wear((:TO,"wear_me":));
}

int wear_me() 
{
    tell_object(ETO,"%^BOLD%^%^GREEN%^The large emerald "+
    "on the necklace begins a quick and beautiful spin.%^RESET%^");
    if(!ETO->query_invis()) 
    {
        tell_room(EETO,"%^BOLD%^%^GREEN%^The large emerald on "+
        ETO->QCN+"%^BOLD%^%^GREEN%^'s necklace begins a quick "+
        "and beautiful spin.%^RESET%^",ETO);
    }
    return 1;
}

void init() 
{
    ::init();
    if(living(ETO) && !interactive(ETO)) 
    {
        TO->set_size(ETO->query_size());
    }
    if(living(ETO)) 
    {
        add_action("choke_em","choke");
    }
}

int do_affect(object victim) 
{
    switch(random(20)) {
        case 0..3:
            tell_object(victim,"%^BOLD%^%^GREEN%^The odor causes your "+
            "stomach to lurch and you begin vomitting!%^RESET%^");
            
            tell_room(EETO,victim->QCN+"%^BOLD%^%^GREEN%^ begins "+
            "vomitting!%^RESET%^",victim);
            victim->set_paralyzed(5 + random(4),"%^BOLD%^%^GREEN%^Your "+
            "body is trembling and you continue to vomit!%^RESET%^");
            return 1;
            break;
        case 4..19:
            tell_object(victim,"%^BOLD%^%^GREEN%^Your lungs ache "+
            "from breathing in the heavy odor!%^RESET%^");
            victim->force_me("emote screams %^RED%^loudly%^RESET%^ in pain!");
            victim->do_damage("torso",roll_dice(4,4));
            break;
    }
}

int choke_em(string str) 
{
    object *people;
    int x;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!TO->query_worn()) return 0;
    if (ETO->query_bound() || ETO->query_unconscious()) 
    {
        ETO->send_paralyzed_message("info",ETO);
        return 1;
    }
  
    tell_object(ETO,"%^BOLD%^%^GREEN%^You grab the larger emerald "+
    "tightly and whisper something that you don't even understand!");
  
    tell_room(EETO,ETO->QCN+"%^BOLD%^%^GREEN%^ grabs the larger "+
    "emerald on "+ETO->QP+" necklace and whispers something that is "+
    "too faint to make out.%^RESET%^",ETO);
  
    if(used_time + WAIT_TIME > time()) 
    {
        tell_object(ETO,"%^BOLD%^%^GREEN%^You sense that the emerald "+
        "is still charging from its last use.%^RESET%^");
        return 1;
    }

    used_time = time();
    
    people = all_living(EETO);
    people -= ({ETO});
  
    tell_room(EETO,"%^BOLD%^%^GREEN%^A powerful odor of decay "+
    "spews forth from the necklace worn by "+ETO->QCN+
    "%^BOLD%^%^GREEN%^ and fills the air!%^RESET%^",ETO);
  
    tell_object(ETO,"%^BOLD%^%^GREEN%^A powerful odor of decay "+
    "suddenly spews forth from your necklace!%^RESET%^");

    for(x = 0; x < sizeof(people);x++) 
    { 
        if(people[x]->query_true_invis()) continue;
       
        tell_object(people[x],"%^BOLD%^%^GREEN%^You take "+
        "a deep breath and are assaulted by the odor of "+
        "decay emitted by the "+ETO->QCN+"%^BOLD%^%^GREEN%^'s "+
        "necklace!%^RESET%^");
                
        people[x]->add_attacker(ETO);
        people[x]->continue_attack();
        ETO->add_attacker(people[x]);
        ETO->continue_attack();    
        if(!SAVING_D->saving_throw(people[x],"paralyzation_poison_death",-2)) 
        { 
            do_affect(people[x]);
        }
    }
    return 1;
}