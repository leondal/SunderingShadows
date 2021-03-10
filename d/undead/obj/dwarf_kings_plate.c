#include <std.h>
#include <magic.h>
#include <clock.h>
#include "../undead.h"

inherit CARMOR"fullplate";

int uses_per_day=10,used,end_day;

string owned;

void create() 
{
   ::create();
   set_name("plate of dwarven kings");
   set_id( ({"plate","dwarven","kings"}) );
   set_short("%^RESET%^%^BOLD%^Plate of Dwarven Kings");
   set_long("%^BOLD%^This armor was forged in the distant Dwarven "
      "Mountains for High King Morock himself. Its strength and power are "
      "one of a kind, for nothing else would be good enough for the High "
      "King. Morock only lost one battle while wearing this armor, its "
      "might is feared throughout the realms. Now you don it, will you "
      "live up to its former glory? A strange symbol of a half-opened "
      "eye is on the left shoulder plate.");

    set_lore("This armor was said to have been worn by high king "
        "Morock during his long rule over the dwarven clans of "
        "Sangri many years before the island was taken over by "
        "Kartakass and his undead minions.  The armor is said to "
        "have magical properties that give the wearer the ability "
        "to see enemies who are hidden from view.  Sadly, the enemy "
        "who eventually took the life of the long dead king struck "
        "from plain sight.");

    set_read("\nWhen ye' beh thinkin' there be thieves use yer "
        "%^BOLD%^%^GREEN%^vision%^RESET%^ ter see tha' pansy arses."); 

    set_language("dwarvish");

    set_size(2);
    set_property("lore difficulty",25);
    set_property("enchantment",3);
    set_item_bonus("sight bonus",3);
    set_item_bonus("constitution",1);
    set_wear( (:TO,"wear_me":) );
    set_remove( (:TO,"remove_me":) );
}

void init() 
{
   ::init();
   if(interactive(TP) && TP == ETO && !owned) owned = TPQTN;
   add_action("vision","vision");
}

void vision() // Detect invis 10 times per day at the moment, I'll decide to adjust it up or down later.
{

    if(!objectp(ETO)) return 0;
    if(!objectp(TO)) return 0;    
    if(!TO->query_worn()) return notify_fail("You have to wear this first.\n");
    if(ETO->query_bound() || TP->query_unconscious()) { TP->send_paralyzed_message("info",ETO); return 1;}
    if((string)ETO->query_race() != "dwarf") { tell_object(ETO,"You can't use that, you are not a dwarf!\n"); return 1; }
    if(ETO->detecting_invis()) { tell_object(ETO,"You are already detecting invisible.\n"); return 1; }

    if(!end_day) { end_day = time() + DAY; }

    if(end_day)
    {
        if(time() < end_day)
        {
            if(used < uses_per_day)
            {
                used++;
                write(used+"  "+uses_per_day);
                new("/cmds/spells/d/_detect_invisibility.c")->use_spell(TP,TP,30,100,"mage");
                return 1;
            }
            else if(used >= uses_per_day)
            {
                tell_object(ETO,"The magic has been drained from the armor, it needs time "
                    "to recharge.");
                return 1;
            }
        }
        if(time() > end_day)
        {
            end_day = time() + DAY;
            used = 0;
        }
    }    

    return 1;
}

int wear_me() 
{
    if( ((string)TPQTN != owned) && ((string)TPQN != "Morock") ) 
    {
        tell_object(ETO,"%^CYAN%^You are not a worthy candidate for this "
            "kind of power!");
        TO->remove();
        return 0;
    }
    tell_object(ETO,"%^BOLD%^The legacy of the Dwarven Kings resides upon "
        "your shoulders now!");
    return 1;
}

int remove_me() 
{
    tell_object(ETO,"%^MAGENTA%^You dishonor yourself by removing this "
        "sacred armor!");
    return 1;
}
