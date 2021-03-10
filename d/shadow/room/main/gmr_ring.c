// Ring of Greater Magic Protection
// Thorn@ShadowGate
// 970225
// gmr_ring.c
// modified to grant a set amount, and fixed to ETO wear/remove. nienne, 08/07.
//Added some color - Octothorpe 12/5/09
// Fixed it so the ring vapes when it says it's destroyed - it's been bug reported
// several times. ~Circe~ 4/30/11
#include <std.h>

inherit ARMOUR;

int uses, old;
object protect;

int resist_magic();
int takeoff();



void create() 
{
    ::create();
    set_property("ring of magic protection", 1);
    set_property("magic", 1);
    set_name("ring");
    set_id(({"band", "ring of greater magic protection","metal band", "tarnished band",
        "platinum ring", "ring", "glowing platinum ring"}));
  
    set_short("%^BOLD%^%^WHITE%^a t%^YELLOW%^a%^WHITE%^rn%^YELLOW%^i%^WHITE%^sh"
        "%^YELLOW%^e%^WHITE%^d band of metal%^RESET%^");
  
    set_long("%^BOLD%^On your finger is revealed a glowing platinum ring pulsing with "
        "a field of magic that seems to charge even the air around it.  Runes "
        "of power glow on the surface where you originally saw what you thought "
        "were nicks.%^RESET%^");

    set_lore("This ring is rumored to possess great power "+
        "against those who wield magic.  The battered "+
        "appearance of the ring is a disguise to keep "+
        "some authorities from recognizing the ring for "+
        "what it is.  At one time, such a ring had been "+
        "banned in Azha for its ability to keep the law-"+
        "enforcing magic users from apprehending certain "+
        "criminals.  This particular ring seems able to "+
        "combat more magic than others.");
  
    set_property("lore difficulty",7);
    set_type("ring");
    set_ac(0);
    set_weight(5);
    set_value(125);
    set_limbs(({"right hand","left hand"}));
    set_wear((:TO,"do_wear":));
    set_remove((:TO,"takeoff":));
    uses = roll_dice(1,12)+3;
}

int do_wear()
{
    object *stuff, onering;
    int i,j, flag;

    stuff = ETO->all_armour();
    j = sizeof(stuff);

    for(i=0;i<j;i++)
    {
        if((string)stuff[i]->query_type() == "ring" && stuff[i]->query_property("ring of magic protection")) 
        {
            onering = stuff[i];
            flag = 1;
            break;
        }
    }

    if(flag)
    {
        write("The magic of this ring reacts with the one already worn...\n"+
            "and they %^RED%^EXPLODE!!%^RESET%^");
        ETO->do_damage(0, (random(uses)+1)*5);
        if(!onering->remove()) destruct(TO);
        if(!TO->remove()) destruct(TO);
        return 0;
    }

    if(ETO->query_property("raised psionic")) 
    {
        tell_object(ETO,"The magical spell protecting you conflicts with the magic in the ring, and it "
            "forcefully repels your hand!");
        return 0;
    }

    if((int)ETO->query_highest_level() < 20) 
    {
        tell_object(ETO,"You aren't powerful enough to use this item yet!");
        return 0;
    }

    protect = ETO;
    protect->set_property("magic resistance", 50);
    set_heart_beat(30);

    tell_object(ETO, "%^BOLD%^The ring %^YELLOW%^flashes %^WHITE%^brightly for a brief instant "+
        "%^BOLD%^on your finger and then fades to a steady glow.%^RESET%^");
    TO->set_short("%^BOLD%^%^WHITE%^a %^YELLOW%^glowing %^BOLD%^%^WHITE%^platinum ring%^RESET%^");
    TO->set_long("%^BOLD%^On your finger is revealed a %^YELLOW%^glowing %^WHITE%^platinum "
        "ring pulsing with a field of magic that seems to charge even "
        "the air around it.  Runes of power glow on the surface where "
        "you originally saw what you thought were nicks.%^RESET%^");

    return 1;
}

void heart_beat()
{
    if (!objectp(TO->query_worn())) TO->takeoff();
    if(!objectp(TO) || !objectp(ETO) || !objectp(protect)) return;

    if(uses <= 0) 
    {
        tell_object(protect, "%^BOLD%^The ring flashes and suddenly "+
            "%^BOLD%^is no more!%^RESET%^");
        set_heart_beat(0);
        takeoff();
        if(!TO->remove()) destruct(TO);
        return 1;
    }

    if(!ETO->is_monster()) { uses--; }

    tell_object(protect, "%^BOLD%^The ring flashes for a moment.%^RESET%^");
    return 1;
}

int takeoff()
{
    set_heart_beat(0);
    
    if(objectp(protect)) { protect->set_property("magic resistance",-50); }
/*
    TO->set("short","%^BOLD%^%^WHITE%^a t%^YELLOW%^a%^WHITE%^rn%^YELLOW%^i%^WHITE%^sh"
        "%^YELLOW%^e%^WHITE%^d band of metal");
    
    TO->set_long("%^BOLD%^This band of metal looks like it was used for the ring to "
        "a beggar's bed curtains.  It is tarnished and nicked in a "
        "few places and seems to have a greasy look to it.  This looks "
        "like the sort of thing that mothers warn their children about "
        "bringing in the house.%^RESET%^");
*/

    protect = 0;
    if(objectp(TO)) destruct(TO);
    return 1;
}


