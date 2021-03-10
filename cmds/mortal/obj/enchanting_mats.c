// the idea is to have only one material object for all enchanting, and just make the cost to enchant items
// in materials grow exponentially.  This will keep the players searching for materials while making the system
// less complicated to use.  I've had first hand experience playing with very complicated crafting mechanics
// and while the roleplay of it might be more realistic strictly speaking, the added confustion and difficulty
// for both the player and the coder don't make it worth it, IMHO
#include <std.h>
#include <daemons.h>
#include <move.h>

inherit OBJECT;

int COUNT;


void create()
{
    set_count(1);
    
    ::create();
    set_name("enchanting materials");
    set_id( ({ "materials","ingredients","enchanting materials","enchanting ingredients", "enchanting_materials_9999", "mats" }) );
    set_short("%^YELLOW%^a collection of enchanting materials%^RESET%^");
    update_long();
    
    set_value(query_count());
    set_weight(5);
}


void update_long()
{
    TO->set_long("%^RESET%^%^BOLD%^%^YELLOW%^This is a collection of various different %^GREEN%^"
        "materials %^RESET%^%^BOLD%^%^YELLOW%^that look like they "
        "would be used in some sort of %^RESET%^%^BOLD%^complex %^CYAN%^magical "
        "%^RESET%^%^BOLD%^%^YELLOW%^or %^BLUE%^alchemical %^RESET%^%^BOLD%^%^YELLOW%^"
        "procedure.  There are various different %^CYAN%^powders %^RESET%^%^BOLD%^%^YELLOW%^and "
        "%^RED%^glyphs%^RESET%^%^BOLD%^%^YELLOW%^, %^BOLD%^%^BLACK%^markings "
        "%^RESET%^%^BOLD%^%^YELLOW%^and %^RESET%^%^GREEN%^scrapings %^RESET%^%^BOLD%^%^YELLOW%^and "
        "%^RESET%^small%^RESET%^%^BOLD%^%^YELLOW%^, %^CYAN%^delicate "
        "%^BLUE%^instruments%^RESET%^%^BOLD%^%^YELLOW%^.  The whole collection of "
        "%^RESET%^%^BOLD%^%^MAGENTA%^stuff%^RESET%^%^BOLD%^%^YELLOW%^ is contained in a %^RESET%^%^BOLD%^small %^GREEN%^box %^RESET%^%^BOLD%^%^YELLOW%^with "
        "%^RESET%^tiny %^BOLD%^drawers%^RESET%^%^BOLD%^%^YELLOW%^ to keep everything organized.  "
        "\nIt contains %^RESET%^%^BOLD%^%^MAGENTA%^("+COUNT+")%^RESET%^%^BOLD%^%^YELLOW%^ materials."
        "\n\n%^RESET%^%^BOLD%^%^GREEN%^You can %^RESET%^%^BOLD%^%^MAGENTA%^merge mats %^RESET%^%^BOLD%^%^GREEN%^to combine your materials "
        "into a single box or %^RESET%^%^BOLD%^%^MAGENTA%^separate 10 mats %^RESET%^%^BOLD%^%^GREEN%^to put X materials "
        "into a box by themselves.%^RESET%^");

    TO->set_value(COUNT * 5);
    return;
}


init()
{
    ::init();
    add_action("combine_mats", "merge");
    add_action("split_mats", "separate");
}


int split_mats(string str)
{
    object mats_ob;
    string what;
    int num;
    
    if(sscanf(str, "%d %s", num, what) != 2)
    {
        tell_object(TP,"%^RESET%^%^BOLD%^%^YELLOW%^Please use %^RESET%^%^BOLD%^%^MAGENTA%^separate "
            "10 mats %^RESET%^%^BOLD%^%^YELLOW%^or %^RESET%^%^BOLD%^%^MAGENTA%^separate 10 materials");
        return 1;
    }
    
    if(ETO != TP)
    {
        tell_object(TP,"%^RESET%^%^BOLD%^%^YELLOW%^You should be carrying the crafting materials first.");
        return 1;
    }
    
    if(num >= query_count())
    {
        tell_object(TP,"%^RESET%^%^BOLD%^%^YELLOW%^Can't split more than or all that you have.  Still can't make something out of nothing, sorry.");
        return 1;
    }
    
    mats_ob = new(base_name(TO));
    
    TO->add_count(-1*num);
    mats_ob->set_count(num);
    
    tell_object(TP,"%^RESET%^%^BOLD%^%^GREEN%^Separating %^RESET%^%^BOLD%^%^MAGENTA%^"+num+"%^RESET%^%^BOLD%^%^GREEN%^ enchanting materials out into a new set.");
    tell_object(TP,"%^RESET%^%^BOLD%^%^GREEN%^Finished...");
    
    if(mats_ob->move(TP) != MOVE_OK)
    {
        tell_object(TP,"%^RESET%^%^BOLD%^%^YELLOW%^Oops, you dropped your new mats.");
        mats_ob->move(ETP);
        return 1;
    }
    
    return 1;    
}


int combine_mats(string str)
{
    object *inv,*dest=({});
    int i,num;
    if(!stringp(str)) { return 0; }
    
    if(str != "mats" && str != "ingredients" && str != "materials" && str != "enchanting ingredients" && str != "enchanting materials")
    {
        tell_object(TP,"%^RESET%^%^BOLD%^%^YELLOW%^Please use merge ingredients or merge materials");
        return 1;
    }
    
    if(ETO != TP)
    {
        tell_object(TP,"%^RESET%^%^BOLD%^%^YELLOW%^You should be carrying the crafting materials first.");
        return 1;
    }
    
    tell_object(TP,"%^RESET%^%^BOLD%^%^GREEN%^You start putting all of your materials together..");
    
    inv = all_inventory(TP);
    
    for(i=0;sizeof(inv),i<sizeof(inv);i++)
    {
        if(!objectp(inv[i])) { continue; }        
        if(!inv[i]->is_enchanting_material()) { continue; }        
        num += inv[i]->query_count();
        if(inv[i] != TO) 
        { 
            inv[i]->move("/d/shadowgate/void");
            inv[i]->remove();
        }
    }

    TO->set_count(num);
    update_long();
    
    tell_object(TP,"%^RESET%^%^BOLD%^%^GREEN%^Finished..  You now have %^RESET%^%^BOLD%^%^MAGENTA%^"+query_count()+"%^RESET%^%^BOLD%^%^GREEN%^ materials.");
    return 1;
}


int is_enchanting_material() { return 1; }


void set_count(int num) 
{    
    COUNT = num;
    update_long();
}


int add_count(int num)
{
    if(num > 0) 
    { 
        COUNT += num;
        update_long();
        return 1;
    }
    else
    {
        if( (COUNT - num) < 1 )
        {
            return 0;
        }
        COUNT += num;
        if(COUNT == 0)
        {
            if(objectp(ETO) && userp(ETO))
            {
                tell_object(ETO,"%^RESET%^%^BOLD%^%^YELLOW%^You use up a box a enchanting materials.");
            }
            TO->move("/d/shadowgate/void");
            TO->remove();
            return 1;
        }
        update_long();
        return 1;
    }
}


int query_count() { return COUNT; }

