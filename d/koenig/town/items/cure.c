#include <std.h>
#include <daemons.h>
inherit POTION;

void create() 
{
   ::create() ;
   set_name("antidote");
   set_short("%^BOLD%^%^WHITE%^A small vial%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^A dull white colored potion swirls in the glass vial.%^RESET%^");
   set ("color", "dull white") ;
   set ("effect_time", 0) ;
   set_value(20);
   set_lore("You seem to recall this dull white potion removing poisons from one's system.");
}

int do_effect() 
{
    string *tmp;
    int temp;
	temp = POISON_D->is_poisoned(drinker);
	if(temp > 0)
    {
//         tmp = POISON_D->clear_poisons_by_dc(drinker, 10 + random(15));
        tmp = "/std/magic/cleanse"->cleanse(drinker);
        if(!tmp)
        { 
            tell_object(drinker,"Nothing happens!\n");
            return 1;
        }
        tell_object(drinker, "The dull white potion cures the following:\n"+tmp);
        return 1;
	}
	else
		tell_object(drinker,"Nothing happens!\n") ;
    return 1 ;
}

int do_wear_off() 
{
    return 1 ;
}
