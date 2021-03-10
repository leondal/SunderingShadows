#include <std.h>
inherit ARMOUR;

int charges;
int FLAG;

void create()
{
    ::create();
    set_id(({"ring","jade ring","jade","lesser jade ring","lesser jade","lesserjade"}));
    set_name("ring of invisibility");
    set_obvious_short("A jade ring");
    set_short("lesser jade ring");
    set_long("This ring is made out of a solid piece of carved "
        "jade that is an exquisitely dark green, almost black.  "
        "On close inspection, tiny flaws can be seen in the ring");
    set_type("ring");
    set_weight(1);
    set_value(500);
    set_language("common");
    set_read("Those who know the secret of this "
        "ring can become %^BOLD%^invisible%^RESET%^.");
    set_limbs(({"right hand","left hand"}));
    set_remove( (: ETO,"remove_ring" :) );
    charges = (random(16)+5);
}

void init()
{
    ::init();
    add_action("invisible","invisible");
}

int invisible(string str)
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
    TO->remove();
    return 1;
    }

    if(!query_worn()) 
    {
        tell_object(TP, "You must wear this first.");
        return 1;
    } 

    new("/cmds/spells/i/_invisibility.c")->use_spell(TP,ETO->query_name(),10,100,"mage");
    if(ETO->query_magic_hidden()) FLAG = 1;
    charges -= 1;
    return 1;
    
}

int remove_ring()
{
    if(ETO->query_magic_hidden())
    {
        ETO->force_me("appear");
        FLAG = 0;
    }
    return 1;
}
