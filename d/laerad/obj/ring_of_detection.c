#include <std.h>
inherit ARMOUR;

int charges;

void create()
{
    ::create();
    set_id(({"ring","gray ring","grey ring","ring of detection"}));
    set_name("ring of detection");
    set_obvious_short("an ordinary gray ring");
    set_short("ring of detection");
    set_long("%^RESET%^%^BOLD%^This ring appears to be fashioned from a "
        "cheap band of steel.  The simple worskmanship has imbued the "
        "ordinary band of metal with only one frill;  The single groove "
        "that runs around the outside of the entire circumference.  The "
        "groove of the ring appears to be filled with an almost indistinguishable "
        "amount of some mercurial substance.  If one squints and looks "
        "close enough they could see tiny movements of images ghosting "
        "across the surface of the thin rivulet.\n  There is something "
        "inscribed on the inside of the ring.%^RESET%^");
    set_lore("%^RESET%^%^CYAN%^The ring of detection is rumored to have been "
        "created by the ailing Arch Mage Dophiriciese.  In the last years of "
        "his life he contracted a terrible wasting disease during his studies "
        "and could not venture forth from his tower for fear of spreading "
        "the illness to others.  Several townsfolk from the local village that "
        "the mage had watched over for years volunteered to help him find the "
        "ingredients that he needed to cure his illness.  The townsfolk, however, "
        "lacked the magical aptitude to see the properties of the items that "
        "Dophiriciese needed.  Never one to give up without trying, the Arch Mage "
        "created many of these rings and gave them to the villagers so that they "
        "could help him find his antidote.  The rest of the story, along with "
        "Dophiriciese's fate has been lost to time.%^RESET%^");
    set_type("ring");
    set_weight(1);
    set_value(500);
    set_language("common");
    set_read("You need only gaze apon the reagents to detect their "
        "magical properties.");
    set_limbs(({"right hand","left hand"}));
    charges = (random(16)+5);
    set_property("treasure_type", "20B");
}

void init()
{
    ::init();
    add_action("detect_stuff","gaze");
}

int detect_stuff(string str)
{
    if(str) return 0;
    if (TP->query_bound() || TP->query_unconscious()) 
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }

    if(charges == 0)
    {
        tell_object(TP,"The ring is out of uses.");
        return 1;
    }

    if(!query_worn()) 
    {
        tell_object(TP, "You must wear this first.");
        return 1;
    } 

    new("/cmds/spells/d/_detect_magic.c")->use_spell(TP,0,25,100,"mage");
    charges -= 1;
    return 1;    
}

