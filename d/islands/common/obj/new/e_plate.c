#include <std.h>

inherit "/d/common/obj/armour/fullplate.c";

string owner;


int is_metal() { return 0; } // dracon scale


void create()
{
    ::create();
    
    set_name("Razunakmail's sapphire");
    
    set_id(({ "plate", "fullplate", "dragonplate" }));
    
    set_obvious_short("%^BOLD%^%^BLUE%^dull blue fullplate%^RESET%^");
    
    set_short("%^BOLD%^%^BLUE%^Razunakmail's %^RESET%^%^BLUE%^S%^CYAN%^a"+
        "%^BOLD%^p%^BLUE%^p%^RESET%^%^BLUE%^h%^CYAN%^i%^BOLD%^r%^BLUE%^e%^RESET%^");
    
    set_long("%^BOLD%^%^BLUE%^This armor is suprisingly light. The craftsmanship is obviously that of a master. "
        "The plates are shaped to lock perfectly with each other, while still leaving room for mobility. It would "
        "seem each plate is molded from an individual blue dragon scale. When in the light, the armor shines from "
        "dull blue to sapphire.");
        
    set_value(140000);
    
    set_property("no curse",1);
    set_property("enchantment",7);

    set_item_bonus("constitution",6);
    set_item_bonus("damage resistance",10);
      
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
   
    set_lore("Who made this armor is not known, but what is known is that the dwarf Maros Battlefield was first "
        "seen with it. He led parties to kill several dragons, out of revenge, after his brother was killed by a "
        "red dragon. It was only fate that Maros would eventually suffer the same fate as his brother to the exact same dragon.");
      
    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required",35);
}


int wear_func()
{
    tell_room(ETP,"%^WHITE%^%^BOLD%^"+ETO->QCN+" buckles up the fullplate",TP);
    tell_object(TP,"%^WHITE%^%^BOLD%^You buckle up the heavy plate, and feel reinsured by its protection");
    return 1;
}


int remove_func()
{
    tell_room(ETP,"%^WHITE%^%^BOLD%^"+ETO->QCN+" removes the plate and lets out a sob",TP);
    tell_object(TP,"%^WHITE%^%^BOLD%^You remove the plate, and your body longs after its protection");
    return 1;
}


void heart_beat()
{
    if(ETO && living(ETO))
    {
        if(TO->query_worn())
        {
            if((int)ETO->query_hp() >= (int)ETO->query_max_hp()) return;
            ETO->add_hp(roll_dice(4,12));
            tell_room(ETO,"%^BOLD%^%^BLUE%^The scales of the plate soothe you.");
        }
    }
}


int query_size()
{ 
    if(living(ETO)) { return ETO->query_size(); }
    else return 1;
}