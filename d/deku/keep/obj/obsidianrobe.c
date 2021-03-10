#include <std.h>
inherit "/d/common/obj/clothing/magerobe.c";
int x;

void init() 
{   
    ::init();
    if(interactive(ETO)) 
    {
        if(TO->add_item_owner(ETOQN))
        {
            TO->set_size(ETO->query_size()); 
        }	           	 	
    }
    add_action("touch_action","touch");
}

void create() 
{
    ::create();
    
    set_name("robe");
    
    set_id(({"robe","obsidian robe","black robe","garment",
    "obsidian garment","blacktongues robe","blacktongues garment",
    "blacktongues obsidian garment"}));

    set_short("%^BLUE%^Lord Bl%^BOLD%^%^BLACK%^ac%^RESET%^%^BLUE%^"+
    "kT%^BOLD%^%^BLACK%^on%^RESET%^%^BLUE%^gue's %^BOLD%^%^BLACK%^"+
    "obs%^RESET%^%^BLUE%^idi%^BOLD%^%^BLACK%^an%^RESET%^%^BLUE%^ "+
    "g%^YELLOW%^a%^RESET%^%^BLUE%^rm%^YELLOW%^e%^RESET%^"+
    "%^BLUE%^nt%^RESET%^");

    set_obvious_short("An obsidian robe");

    set_long("%^BLUE%^This robe is made from a dull, thin, %^BOLD%^%^BLACK%^obs%^BLUE%^idi"+
    "%^BOLD%^%^BLACK%^an%^RESET%^%^BLUE%^ fabric.  It is seamless and several bizarre "+
    "%^BOLD%^%^BLACK%^runes%^RESET%^%^BLUE%^ have been sewn into the front of it.  "+
    "The %^BOLD%^%^BLACK%^runes%^RESET%^%^BLUE%^ seem to constantly shift, making you "+
    "think of something that has yet to find its true shape.  Looking at the robe causes "+
    "you to squint, it's almost as if the robe is giving off some amazingly bright "+
    "light, yet there is no light visible.  For a brief instant the thought that maybe you "+
    "could touch the %^BOLD%^%^BLACK%^runes%^RESET%^%^BLUE%^ and see what happens passes "+
    "through the mind.  An obviously powerful magic is somehow involved with this robe.%^RESET%^");	
    
    set_weight(5);

    set_lore("This robe was sewn and enchanted for the foul and "+
    "evil lord blacktongue.  The original tailor for the "+
    "robe has long been forgotten, but it is likely that blacktongue "+
    "captured him and forced him to make this garment.  "+
    "The exact enchantments are not known, only that one "+
    "who was close to the evil lord provided them.");

    set_property("enchantment",3);
    set_value(2000);
    set_type("clothing");
    set_limbs(({"torso"}));
    set_wear((:TO,"wear_robe":));
    set_remove("%^BOLD%^%^BLUE%^You remove the perfectly "+
	"fitted robe%^BOLD%^%^BLUE%^.%^RESET%^");
    set_item_bonus("magic resistance", 1);
    set_struck((:TO,"strike_func":));
    x = random(4);
    set_max_internal_encumbrance(10);
}

void set_x(int y) 
{ 
    x = y;
}

void touch_action(string str) 
{
    if(!str) return 0;
    if(str == "runes" || str == "rune") 
    {
        if(!TO->query_owns_item(ETOQN) || (int)TO->query_size() != (int)ETO->query_size()) 
        {       		
            write("%^BLUE%^As you touch the runes the robe shifts form to fit your body!%^RESET%^");
            
            if(!ETO->query_invis()) 
            {
                tell_room(environment(ETO),"%^BLUE%^ " +
				ETO->QCN + "%^BLUE%^ touches "+
                "the runes on the robe and it shifts form to fit " +
				ETO->query_objective()+ 
                "%^BLUE%^ perfectly!%^RESET%^",ETO);
            }

            TO->clear_item_owners();
            TO->add_item_owner(ETOQN);		
            TO->set_size(ETO->query_size());
          
            if(ETO->is_class("mage")) 
            {
                if((int)TO->query_max_internal_encumbrance() != 10 && x == 3) 
                {
                    tell_object(ETO,"%^BOLD%^%^BLUE%^The robe rips near "+
					"the bottom edge creating a small pocket!");										
					
                    TO->set_long("%^BLUE%^This robe is made from a dull, "+
                    "thin, %^BOLD%^%^BLACK%^obs%^BLUE%^"+
					"idi%^BLACK%^an %^RESET%^"+
					"%^BLUE%^fabric.  It is seamless and several bizarre "+
					"%^BOLD%^%^BLACK%^runes %^RESET%^"+
					"%^BLUE%^have been sewn "+
					"into the front of it.  The %^BOLD%^%^BLACK%^runes "+
					"%^RESET%^%^BLUE%^seem to constantly shift, "+
					"making you "+
					"think of something that has yet to find its true "+
					"shape.  Looking at the robe causes you "
					"to squint, it's almost as if the robe is giving off "+
					"some amazingly bright light, yet "
					"there is no light visible.  For a brief instant "+
					"the thought that maybe you could touch "+
					"the %^BOLD%^%^BLACK%^runes %^RESET%^%^BLUE%^and "+
					"see what happens passes through the "+
					"mind.  An obviously powerful magic is somehow "+
					"involved with this robe.  One small pocket "+
					"lines the bottom edge of the robe.%^RESET%^");  

                    TO->set_max_internal_encumbrance(10);
                    return 1;
                }
				
                else 
                {
                    return 1;
                }

            }	
            	
            if(!ETO->is_class("mage")) 
            {
                TO->set_max_internal_encumbrance(0);
                			
                TO->set_long("%^BLUE%^This robe is made from a dull, thin, "+
                "%^BOLD%^%^BLACK%^obs%^BLUE%^idi"+
                "%^BOLD%^%^BLACK%^an%^RESET%^%^BLUE%^ fabric.  "+
				"It is seamless and several bizarre "+
                "%^BOLD%^%^BLACK%^runes%^RESET%^%^BLUE%^ have been "+
				"sewn into the front of it.  "+
                "The %^BOLD%^%^BLACK%^runes%^RESET%^%^BLUE%^ "+
                "seem to constantly shift, making you "+
                "think of something that has yet to find its "+
                "true shape.  Looking at the robe causes "+
                "you to squint, it's almost as if the robe is "+
                "giving off some amazingly bright "+
                "light, yet there is no light visible.  "+
                "For a brief instant the thought that maybe you "+
                "could touch the %^BOLD%^%^BLACK%^runes%^RESET%^%^BLUE%^ "+
                "and see what happens passes "+
                "through the mind.  An obviously powerful "+
                "magic is somehow involved with this robe.%^RESET%^");
                return 1;
            }	
        }
        
        write("You touch the runes but nothing seems to happen...");
        return 1;
    }
    return 0;
}

int wear_robe() 
{
    if(interactive(ETO) && !TO->query_owns_item(ETOQN)) 
    {
        write("%^BOLD%^%^BLUE%^The robe does not fit you!%^RESET%^");
        return 0;
    }

    write("%^BOLD%^%^BLUE%^You wear the perfectly fitted robe%^BOLD%^%^BLUE%^.%^RESET%^");
    
    if(!ETO->is_class("mage")) { TO->set_max_internal_encumbrance(0); }

    if(ETO->is_class("mage") && (int)TO->query_max_internal_encumbrance() != 10 && x == 3) 
    {
        write("%^BOLD%^%^BLUE%^The robe rips near the bottom edge, creating a small pocket!");
        
        TO->set_max_internal_encumbrance(10);
    
        TO->set_long("%^BLUE%^This robe is made from a dull, thin, "
        "%^BOLD%^%^BLACK%^obs%^BLUE%^idi%^BLACK%^an %^RESET%^%^BLUE%^fabric.  It is seamless and "
        "several bizarre %^BOLD%^%^BLACK%^runes %^RESET%^%^BLUE%^have been sewn into the front of "
        "it.  The %^BOLD%^%^BLACK%^runes %^RESET%^%^BLUE%^seem to constantly shift, making you "
        "think of something that has yet to find its true shape.  Looking at the robe causes you "
        "to squint, it's almost as if the robe is giving off some amazingly bright light, yet "
        "there is no light visible.  For a brief instant the thought that maybe you could touch "
        "the %^BOLD%^%^BLACK%^runes %^RESET%^%^BLUE%^and see what happens passes through the "
        "mind.  An obviously powerful magic is somehow involved with this robe.  One small pocket "
        "lines the bottom edge of the robe.%^RESET%^");
    }
    return 1;
}

int strike_func(int damage, object what, object who)
{
    if(random(1000) < 500  && (string)ETO->query_class_string() == "mage")
    {
        tell_room(EETO,"%^BOLD%^%^RED%^As "+who->QCN+" hits the "+
        "robe worn by "+ETO->QCN+"%^BOLD%^%^RED%^ "+who->QP+
        "%^BOLD%^%^RED%^ blow is weakened!%^RESET%^",({ETO,who}));
	
        tell_object(ETO,"%^BOLD%^%^RED%^"+who->QCN+"%^BOLD%^%^RED%^'s attack is "+
        "weakened by your obsidian robe!%^RESET%^");

        tell_object(who,"%^BOLD%^%^RED%^Your attack on "+ETO->QCN+
        "%^BOLD%^%^RED%^ is weakened by "+ETO->QP+"%^BOLD%^%^RED%^"+
        " robe!%^RESET%^");
        return ((damage * 50) / 100);
    }
    return damage;
}
	
