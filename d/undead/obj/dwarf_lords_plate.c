#include <std.h>
#include "../undead.h"

inherit CARMOR"fullplate";

string owned;

void init() 
{
    ::init();
    if(interactive(TP) && TP==ETO && !owned && !avatarp(TP)) owned = TPQN;
}

void create() 
{
    ::create();
    set_name("%^BLUE%^Plate of Dwarven Lords%^RESET%^");
    set_id(({"plate","full plate","fullplate","armor","armour","dwarven","dwarven armor","dwarven fullplate","flawless armor","flawless fullplate","flawless plate","plate of dwarven lords"}));
    
    set_obvious_short("flawless fullplate armor");
    set_short("%^BLUE%^Plate of Dwarven Lords%^RESET%^");
    
    set_long("This exquisite armor was excellently crafted by a very "+
       "skilled dwarven smith. It has obviously seen many battles "+
       "but is in remarkably good condition with hardly a scratch "+
       "on it anywhere. From the superb quality of the work you can "+
       "tell this was obviously meant for dwarven lords, perhaps "+
       "even a king.");
   
    set_lore("This armor was forged in the distant Dwarven Mountains "+
      "by the High King's mystic furnace itself. Perhaps one of the "+
      "most cherished treasures of the Dwarven people it was a "+
      "symbol of great power for hundreds of years, until High "+
      "King Morock rode into battle against the Undead Lord's of "+
      "the Plains, and was slain. For generations now this mighty "+
      "armor has been worn by the Undead Lords skilled warrior, "+
      "the Seer. But now the Seer and his Master have been slain, "+
      "and the armor has found a new master.");

    set_property("lore difficulty",28);
    set_size(2);
    set_value(15000);
    set_property("enchantment", 3);
    set_wear((:TO,"wear_plate":));
    set_remove((:TO,"remove_plate":));
}

int wear_plate()
{
    if(!interactive(ETO)) { return 1; }
    if(((string)TP->query_name() != owned) && ((string)TP->query_name() != "Morock") && ((string)TP->query_name() != "seer"))
    {
        tell_object(ETO,"%^MAGENTA%^The Dwarven Lords reject you as unworthy.");
        TO->remove();
        return 0;
    }
    tell_object(ETO,"%^BLUE%^Your body is filled with the power of "
        "the Dwarven Lords!");
   return 1;
}

int remove_plate()
{
    tell_object(ETO,"%^RED%^The might of the Dwarven Lords "
        "fades from your body!\n");
    return 1;
}
