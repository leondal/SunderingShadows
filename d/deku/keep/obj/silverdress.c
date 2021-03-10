#include <std.h>
inherit "/std/armour";
void create()
{
    ::create();
    set_name("%^BOLD%^%^WHITE%^silver dress%^RESET%^");
    set_id(({"dress","silver dress","thin silver dress"}));
    set_obvious_short("A thin silver dress");
    set_short("%^BOLD%^%^WHITE%^Siere's thin silver dress%^RESET%^");
    set_long(
    "%^BOLD%^%^WHITE%^This dress is made from a very thin, "+
    "%^RESET%^silver%^BOLD%^%^WHITE%^ "+
    "fabric.  The fabric is %^YELLOW%^shiny%^BOLD%^%^WHITE%^ "+
    "and sewn to lewdly display " +
    "the curves of the wearer.  A dull, "+
    "%^RESET%^%^WHITE%^silver%^BOLD%^%^WHITE%^ pattern "+
    "on the right shoulder contrasts the fabric and "+
    "forms a large wolf-head.  Only a very "+
    "small framed individual would be able to fit into this dress.%^RESET%^"
    );
    set_lore("This dress was crafted for the lover of Lord Blacktongue before "+
    "he was turned into a lycanthrope. Rumours suggest that his lover was a half-drow"+
    " of great beauty who manipulated him at the bidding of the Shadowlord. ");
    set_weight(3);
    set_size(2);
    set_value(3000);
    set_cointype("silver");
    set_type("clothing");
    set_limbs(({"torso"}));
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    set_property("enchantment",2);
    set_item_bonus("charisma", 2);
}

int wearme()
{
    string body;
    body = (string)ETO->query_body_type();
    if(body == "skinny" || body == "slim" || body == "slender" || 
    body == "frail" || body == "gaunt" || body == "slight" || 
    body == "lean" || body == "scrawny" || body == "thin" ||
    body == "svelte") 
    {
        if((string)ETO->query_gender() == "female") 
        {	
            tell_object(ETO,"%^BOLD%^%^BLUE%^The dress clinges to "+
            "your curves!%^RESET%^");
            if(!ETO->query_invis()) 
            {
                tell_room(environment(ETO),"%^BOLD%^%^BLUE%^The "+
                "dress clinges to " + ETO->query_name() +
                "%^BOLD%^%^BLUE%^'s curves!%^RESET%^",ETO);
            }
        }
        if((string)ETO->query_gender() == "male") 
        {
            tell_object(ETO, "%^RED%^You wear the tight fitting "+
            "dress and feel a little awkward.%^RESET%^");
            if(!ETO->query_invis()) 
            {
                tell_room(environment(ETO),"%^RED%^" + 
                ETO->query_name() + "%^RED%^ wears a tight fitting "+
                "dress.%^RESET%^",ETO);
            }
           
        }
        return 1;
    }

    
    tell_object(ETO, "%^BLUE%^You try to wear the dress but "+
    "your frame is far too large for it.%^RESET%^");
    if(!ETO->query_invis()) 
    {
        tell_room(environment(ETO),"%^BLUE%^" + ETO->query_name() + 
        "%^BLUE%^ tries to wear the "+
        "dress, but it doesn't fit " +
        ETO->query_possessive()+ "%^BLUE%^ large frame!%^RESET%^"
        ,ETO);
    }
    return 0;
}

int removeme()
{	
    if((string)ETO->query_gender() == "male") 
    {
        tell_object(ETO, "%^RED%^You finally remove your "+
        "tight fitting dress and feel a little less awkward."+
        "%^RESET%^");
    }
    if((string)ETO->query_gender() == "female") 
    {
        write("%^BLUE%^The dress relaxes its grip on your curves."+
        "%^RESET%^");
    }
    return 1;
}

int isMagic(){
    int i;
    i = ::isMagic();
    i = i+1;
    return i;
}
