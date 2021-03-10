#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit "/d/common/obj/weapon/mstaff.c";

void create() 
{
    ::create();
    set_name("staff");
    set_id(({"staff", "quarterstaff", "spider staff", "spider bane", 
    "bane staff", "spiders bane", "bane"}));

    set_short("%^BOLD%^%^BLACK%^Sp%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^"+
    "d%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r's B%^BOLD%^%^WHITE%^"+
    "a%^BOLD%^%^BLACK%^n%^BOLD%^%^WHITE%^e%^RESET%^"); 

    set_obvious_short("%^BOLD%^%^GREEN%^A twisted dark green staff%^RESET%^");

    set_long("%^RESET%^%^GREEN%^This twisted staff has been carved from "+
    "%^BOLD%^%^BLACK%^knotted%^RESET%^%^GREEN%^ dark green wood. "+
    "It has %^BOLD%^%^YELLOW%^intricate%^RESET%^%^GREEN%^ and tiny "+
    "depictions of %^BOLD%^%^BLACK%^sp%^RESET%^%^ORANGE%^"+
    "i%^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^rs "+
    "%^RESET%^%^GREEN%^covering the majority of it. "+
    "Each depiction varies somewhat from the last and the "+
    "only constant shared among them are the %^BOLD%^%^RED%^red"+
    "%^RESET%^%^GREEN%^ eyes of each spider. There are "+
    "bands of %^BOLD%^%^BLUE%^"+
    "blue metal%^RESET%^%^GREEN%^ placed evenly along the "+
    "length of the staff to help add support to it. "+
    "Each band is slightly cool to the "+
    "touch. The far end of the staff comes to almost a point "+
    "before meeting with one larger %^BOLD%^%^BLACK%^knot"+
    "%^RESET%^%^GREEN%^. The opposite end of the "+
    "staff is exceptionally twisted and has a "+
    "particularly gruesome depiction of a "+
    "%^BOLD%^%^BLACK%^sp%^RESET%^%^ORANGE%^"+
    "i%^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^e"+
    "%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^ consuming "+
    "a %^BOLD%^%^BLACK%^wolf-like%^RESET%^%^GREEN%^ "+
    "creature.%^RESET%^");
    
    set_lore("This staff was created many ages ago by "+
    "a druid who was particularly fond of spiders. "+
    "It was said to have the ability to be both a "+
    "bane to the creatures and an attraction to them. "+
    "Some even suggest that it has the ability to "+
    "curse those it is used against in combat by making "+
    "them appear exceptionally appetizing to many "+
    "Arachnids. Its whereabouts have been largely unknown "+
    "with rumors that Ashilla The Mad might be in possession "+
    "of it."); 

    set_property("lore difficulty",15); 

    set_value(1200);

    set_property("enchantment",2);
    set_wield((: TO,"extra_wield" :));
    set_unwield((: TO,"extra_unwield" :));
    set_hit((: TO,"extra_hit" :));
}

int extra_wield() 
{
    if (!ETO->query_property("silent_wield")) {
        tell_object(ETO, "%^RESET%^%^GREEN%^You almost sense life emmitting out " +
            "from the staff!%^RESET%^");
    }
    return 1;
}

int extra_unwield() 
{
    if (!ETO->query_property("silent_wield")) {
        tell_object(ETO, "%^RESET%^%^GREEN%^You feel the sense of life " +
            "emitted from the staff fade away!%^RESET%^");
    }
    return 1;
}

int extra_hit(object vic)
{
    object curse_ob;
    int which, dam;
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    if(!objectp(EETO)) return 1;
    if(!objectp(vic)) return 1;
    
    if(random(250) < 225) return 1;

    switch(random(30)) 
    {
        case 0..15:
            which = 1;
            break;
        case 16..19:
            which = 2;
            break;
        case 20..25: 
            which = 1;
            break;
        case 26..29:
            which = 3;
            break;
    }
    if(objectp(curse_ob = present("spider_curse_ob", vic)) && which == 3)
    {
        if((int)curse_ob->query_potency() >= 2) which = 1;
    }
    switch(which)
    {
        case 1:

            tell_object(ETO, "%^BOLD%^%^RED%^Your staff suddenly "+
            "emits a LOUD %^BOLD%^%^BLUE%^S%^BOLD%^%^YELLOW%^H"+
            "%^BOLD%^%^BLUE%^R%^BOLD%^%^YELLOW%^I%^BOLD%^%^BLUE%^"+
            "E%^BOLD%^%^YELLOW%^K%^BOLD%^%^BLUE%^I%^BOLD%^"+
			"%^YELLOW%^N%^BOLD%^%^BLUE%^G%^BOLD%^RED%^ and a "+
			"B%^BOLD%^%^BLACK%^U%^BOLD%^%^RED%^R%^BOLD%^%^BLACK%^"+
			"S%^BOLD%^%^RED%^T of flame erupts from the "+
			"knot on the end of it and slams into "+
			vic->QCN+"%^BOLD%^%^RED%^!%^RESET%^");

			tell_object(vic, ETOQCN+"%^BOLD%^%^RED%^'s staff suddenly "+
			"emits a LOUD %^BOLD%^%^BLUE%^S%^BOLD%^%^YELLOW%^H"+
			"%^BOLD%^%^BLUE%^R%^BOLD%^%^YELLOW%^I%^BOLD%^%^BLUE%^"+
			"E%^BOLD%^%^YELLOW%^K%^BOLD%^%^BLUE%^I%^BOLD%^"+
			"%^YELLOW%^N%^BOLD%^%^BLUE%^G%^BOLD%^RED%^ and a "+
			"B%^BOLD%^%^BLACK%^U%^BOLD%^%^RED%^R%^BOLD%^%^BLACK%^"+
			"S%^BOLD%^%^RED%^T of flame erupts from the "+
			"knot on the end of it, slamming into "+
			"you!%^RESET%^");	
			
			tell_room(EETO, ETOQCN+"%^BOLD%^%^RED%^'s staff suddenly "+
			"emits a LOUD %^BOLD%^%^BLUE%^S%^BOLD%^%^YELLOW%^H"+
			"%^BOLD%^%^BLUE%^R%^BOLD%^%^YELLOW%^I%^BOLD%^%^BLUE%^"+
			"E%^BOLD%^%^YELLOW%^K%^BOLD%^%^BLUE%^I%^BOLD%^"+
			"%^YELLOW%^N%^BOLD%^%^BLUE%^G%^BOLD%^RED%^ and a "+
			"B%^BOLD%^%^BLACK%^U%^BOLD%^%^RED%^R%^BOLD%^%^BLACK%^"+
            "S%^BOLD%^%^RED%^T of flame erupts from the "+
			"knot on the end of it, slamming into "+
			vic->QCN+"%^BOLD%^%^RED%^!%^RESET%^", ({ETO, vic}));	
			
            vic->cause_typed_damage(vic, vic->return_target_limb(),
            roll_dice(4,4),"fire");

            break;

        case 2:
    
            tell_object(ETO, "%^BOLD%^%^CYAN%^You feel a sudden "+
            "sense of %^BOLD%^%^RED%^E%^BOLD%^%^YELLOW%^U%^BOLD%^%^RED%^"+
            "P%^BOLD%^%^YELLOW%^H%^BOLD%^%^RED%^O%^BOLD%^%^YELLOW%^R"+
            "%^BOLD%^%^RED%^I%^BOLD%^%^YELLOW%^A%^BOLD%^%^CYAN%^ "+
            "when your staff strikes "+vic->QCN+"%^BOLD%^%^CYAN%^ "+
            "you feel %^BOLD%^%^WHITE%^LIFE%^BOLD%^%^CYAN%^ energy "+
            "leeched from "+vic->QO+"%^BOLD%^%^CYAN%^ to replenish "+   
            "your own!%^RESET%^");

            tell_object(vic, "%^BOLD%^%^BLACK%^You feel "+  
            "some of your very %^BOLD%^%^WHITE%^LIFE%^BOLD%^"+
            "%^BLACK%^ energy %^BOLD%^%^RED%^S%^BOLD%^%^YELLOW%^A"+
            "%^BOLD%^%^RED%^P%^BOLD%^%^YELLOW%^P%^BOLD%^%^RED%^E"+
            "%^BOLD%^%^YELLOW%^D %^BOLD%^%^BLACK%^"+
            "as "+ETOQCN+"%^BOLD%^%^BLACK%^'s staff strikes "+
            "you!%^RESET%^");
				
            tell_room(EETO, vic->QCN + "%^BOLD%^%^GREEN%^"+
            "looks quite %^BOLD%^%^BLACK%^P%^BOLD%^%^WHITE%^"+
            "A%^BOLD%^%^BLACK%^L%^BOLD%^%^WHITE%^E %^BOLD%^%^GREEN%^"+
            "as "+ETOQCN+"%^BOLD%^%^GREEN%^'s staff strikes "+
            vic->QO+"!%^RESET%^", ({vic, ETO}));
		
            dam = roll_dice(4,4);

            vic->caused_typed_damage(vic, vic->return_target_limb(),
            dam,"negative energy");
            
            ETO->caused_type_damage(ETO, ETO->return_target_limb(),
            (dam*-1), "positive energy");

            break;
        case 3:
			
            tell_object(ETO, "%^BOLD%^%^WHITE%^You feel a "+
            "%^BOLD%^%^RED%^M%^BOLD%^%^BLACK%^A%^BOLD%^%^RED%^S"+
            "%^BOLD%^%^BLACK%^S%^BOLD%^%^RED%^I%^BOLD%^%^BLACK%^"+
            "V%^BOLD%^%^RED%^E %^BOLD%^%^WHITE%^jolt of "+
            "%^BOLD%^%^CYAN%^ENERGY%^BOLD%^%^WHITE%^ traverse "+
            "the length of your staff as it "+
            "places the mark of the %^BOLD%^%^BLACK%^SP"+
            "%^BOLD%^%^RED%^I%^BOLD%^%^BLACK%^D%^BOLD%^%^RED%^"+
            "E%^BOLD%^%^BLACK%^R%^BOLD%^%^WHITE%^ on "+ 
            vic->QCN+"%^BOLD%^%^WHITE%^!%^RESET%^");

            tell_object(vic, ETOQCN+"%^BOLD%^%^BLACK%^'s "+
            "staff %^BOLD%^%^RED%^SLAMS%^BOLD%^%^BLACK%^ "+
            "into you and you feel the mark of the "+
            "%^BOLD%^%^WHITE%^SP"+      
            "%^BOLD%^%^RED%^I%^BOLD%^%^WHITE%^D%^BOLD%^%^RED%^"+
            "E%^BOLD%^%^WHITE%^R%^BOLD%^%^BLACK%^ taint "+
            "your soul!%^RESET%^");

            tell_room(EETO, vic->QCN+"%^BOLD%^%^BLACK%^ "+
            "seems quite alarmed as "+ETOQCN+"%^BOLD%^"+        
            "%^BLACK%^'s staff %^BOLD%^%^RED%^SLAMS"+
            "%^BOLD%^%^BLACK%^ into "+vic->QO+
            "!%^RESET%^", ({vic, ETO}));
		
            if(objectp(curse_ob)) 
            {		
                curse_ob->increase_potency(1);
                curse_ob->set_save_allowed(1);
                curse_ob->set_frequency(5);
            }
            else
            {
                curse_ob = new(FFOB+"spider_ob");
                curse_ob->set_save_allowed(1);
                curse_ob->set_frequency(5);
                curse_ob->move(vic);
            }
            break;
        }
    return 0;			
}
