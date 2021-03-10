#include <std.h>
#include <daemons.h>
#include "/d/common/obj/brewing/brew.h"
inherit BREWPOWDER;

int uses;

void create() 
{
    ::create();
    set_name("small bag");
    set_id(({"powder","bag","gleaming powder","enchanting powder", "powder of enchanting"}));
    set_obvious_short("%^RESET%^%^CYAN%^a small bag of %^BOLD%^%^CYAN%^gleaming powder%^RESET%^");
    set_short("%^BOLD%^%^CYAN%^powder of %^WHITE%^e%^CYAN%^nch%^WHITE%^ant%^CYAN%^ing%^RESET%^");
    set_long("This bag contains a collection of powders with a very odd smell.  "
    "A sharp, but not unpleasant, aroma rises from the bag and seems to put an edge "
    "on your senses even from the slightest whiff. The fine dust gleams under any "
    "light with a rather pretty incandescence. You could probably <scatter the "
    "powder over object>.");
    set_property("lore difficult", 25);
    set_value(6000);
    set_weight(2);
    uses = 1;
    set_myname("enchanting powder");
}

void set_myname(string thename) 
{
    set_lore("This powder is one crafted by many alchemists of the land.  Because of the ingredients used, "+
    "such powders often have similar qualities, such as color and smell.  You're familiar enough with this "+
    "particular variety, to believe it is probably a "+thename+", able to increase the magical enchantment on "+
    "an item. You believe that there is a limit to the effect that the powder would have.");
    myname = thename;
}

void init()
{
    object *Objs, *tmp;
    ::init();
    add_action("enchant","scatter");
    if(!objectp(ETO)) return;
    if(!uses) return;
    if(living(ETO))
    {
        Objs = deep_inventory(ETO);
        Objs -= ({TO});
        tmp = Objs->is_enchanting_powder();
        tmp -= ({0});
        if(sizeof(tmp))
        {
            tell_object(ETO, TO->query_short()+" %^BOLD%^%^WHITE%^spills out!%^RESET%^");
            if(objectp(EETO))
            {
                tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^'s "+TO->query_short()+
                "%^BOLD%^%^WHITE%^ spills out!%^RESET%^", ETO);
            }
            uses = 0;
            TO->set_short("An empty bag");
            TO->set_obvious_short("An empty bag");
            TO->set_value(1);
            set("coin type","copper");
            set_long("This empty bag used to hold some kind of powder, but there are only a few gleaming motes left now.");
        }
    }
        
}

int enchant(string str) 
{
    string mystring;
    int enchant;
    object what;
    if(!objectp(TP)) return 1;
    if(!objectp(ETP)) return 1;
    if(TP->query_property("shapeshifted")) 
    {
        tell_object(TP,"You can't use powder while shapeshifted");
        return 1;
    }
    if((int)TP->is_retinue()) 
    {
        tell_object(TP,"You wouldn't know how to use that!");
        return 1;
    }
    if(!uses)
    {
        tell_object(TP,"The bag of powder is empty!");
        return 1;
    }
    if(!str)
    {
        tell_object(TP,"What do you want to <scatter the powder over>?");
        return 1;
    }
    if(sscanf(str,"the powder over %s",mystring) != 1)
    {
        tell_object(TP,"What do you want to <scatter the powder over>?");
        return 1;
    }
    if(!objectp(what = present(mystring, TP)))
    {
        tell_object(TP, "You do not have "+mystring+".");
        return 1;
    }
    tell_object(TP,"%^BOLD%^%^CYAN%^You scatter the small bag of powder over the "+
    what->query_short()+"%^BOLD%^%^CYAN%^.%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" scatters a small bag of gleaming powder over "+
    what->query_short()+"%^BOLD%^%^CYAN%^.%^RESET%^",TP);
    
    enchant = what->query_property("enchantment");
    if(enchant >= 4) enchant = 4;
    else enchant++;
    uses = 0;
    TO->set_short("An empty bag");
    TO->set_obvious_short("An empty bag");
    TO->set_value(1);
    set("coin type","copper");
    set_long("This empty bag used to hold some kind of powder, but there are only a few gleaming motes left now.");
    while(query_property("no offer")) remove_property("no offer");
    what->set_property("no curse", 1);
    what->remove_property("enchantment");
    what->set_property("enchantment", enchant);
    what->set_property("no curse", -1);
    return 1;
}

int is_enchanting_powder() { return uses;}