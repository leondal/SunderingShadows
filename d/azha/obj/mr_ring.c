// Ring of Magic Protection (exploding test)
// Thorn@ShadowGate
// 970225
// mr_ring.c
// modified to grant a set amount, and fixed to ETO wear/remove. nienne, 08/07.

#include <std.h>

inherit "/d/common/obj/jewelry/ring.c";

int uses, old, resamt;
object protect;

int resist_magic();
int takeoff();



create()
{
    ::create();
    set_property("ring of magic protection", 1);
    set_name("ring");
    set_id(({"ring of magic protection", "ring","golden ring", "gold ring"}));

    set("short","a golden ring");

    set_long("This is a simple looking gold ring, worth a few gold pieces at "
        "the market.  Looking carefully at it, you notice a few illegible "
        "scratchings on the inside of the band, but nothing else.");

    set_lore("This ring is rumored to possess great power "+
        "against those who wield magic.  The battered "+
        "appearance of the ring is a disguise to keep "+
        "some authorities from recognizing the ring for "+
        "what it is.  At one time, such a ring had been "+
        "banned in Azha for its ability to keep the law-"+
        "enforcing magic users from apprehending certain "+
        "criminals.  This particular ring seems only able "+
        "to offer a small amount of magic resistance.");

    set_property("lore difficulty",7);
    set("value", 25);
    set_wear((:TO,"do_wear":));
    set_remove((:TO,"takeoff":));
    uses = roll_dice(1,12)+10;
}

int do_wear()
{
    object *stuff, onering, env;
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
            "and they repel violently!");
        env = environment(ETO);
        onering->move(env);
        return 0;
    }

    if(ETO->query_property("raised resistance"))
    {
        tell_object(ETO,"The magical spell protecting you conflicts with the magic in the ring, and it "
            "forcefully repels your hand!");
        return 0;
    }

    protect = ETO;
    resamt = protect->query_level();
    protect->set_property("magic resistance",resamt);
    protect->set_property("raised resistance",1);

    set_heart_beat(20);

    tell_object(ETO, "%^BOLD%^The ring glows for a brief instant "+
        "%^BOLD%^on your finger and then fades.%^RESET%^");

    TO->set_short("a %^YELLOW%^glowing%^RESET%^ golden ring");
    return 1;
}

int heart_beat()
{
    if(!objectp(TO->query_worn())) TO->takeoff();
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
    if(objectp(protect)) {
        protect->set_property("magic resistance",(-1)*resamt);
        protect->set_property("raised resistance",-1);
    }
    TO->set_short("a golden ring");
    protect = 0;
    return 1;
}
