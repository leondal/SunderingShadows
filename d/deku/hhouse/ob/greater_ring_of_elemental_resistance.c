#include <std.h>
inherit "/d/common/obj/jewelry/ring";
string *possible_protections = ({"fire", "divine", "cold", "electricity", "force", "negative energy", "positive energy"});
string choose_protection();
void create()
{
    int Num;
	::create();
    set_name("greater ring of elemental resistance");
    set_id(({"ring", "ring of elemental resistance", "greater ring", 
    "greater ring of elemental resistance", "ring of elemental resistance", 
    "dark metal band", "band", "metal band", "metal ring", "dark metal ring",
    "dark ring"}));
    
    set_obvious_short("A dark metal ring");
    
    set_short("%^BOLD%^%^BLACK%^Gr%^BOLD%^%^WHITE%^ea%^BOLD%^%^BLACK%^"+
    "t%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^r R%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^"+
    "ng %^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^f %^BOLD%^%^WHITE%^E%^BOLD%^%^BLACK%^"+
    "l%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^m%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^nt"+
    "%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^l R%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^"+
    "s%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^st%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^"+
    "nc%^BOLD%^%^WHITE%^e%^RESET%^");
    
    
    set_long("%^BOLD%^%^BLACK%^This band is composed of a thick "+
    "and dark met%^BOLD%^%^CYAN%^a%^BOLD%^%^BLACK%^ll%^BOLD%^%^CYAN%^i"+
    "%^BOLD%^%^BLACK%^c material. It has been %^BOLD%^%^WHITE%^exquisitely"+
    "%^BOLD%^%^BLACK%^ crafted into a perfect circle and is completely "+
    "%^BOLD%^%^WHITE%^smooth%^BOLD%^%^BLACK%^ and flawless on the "+
    "outter portion of the band. The inside of the b%^BOLD%^%^WHITE%^a"+
    "%^BOLD%^%^BLACK%^nd strangely appears almost fluid, as if it is constantly "+
    "and continuously flowing in an ever completing c%^BOLD%^%^CYAN%^i%^BOLD%^%^BLACK%^"+
    "rcl%^BOLD%^%^CYAN%^e.%^BOLD%^%^BLACK%^ Occasionally and only for brief moments "+
    "of time there appear strange r%^BOLD%^%^WHITE%^u%^BOLD%^%^BLACK%^n%^BOLD%^%^WHITE%^"+
    "e%^BOLD%^%^BLACK%^s but they are quickly swept away by the fluid movement "+
    "before any of them can be deciphered.%^RESET%^");
       
    set_lore("%^BOLD%^%^BLACK%^The history of these rings are a "+
    "vast mystery. The material that they are composed of is rare and "+
    "perhaps impossible to find today. Some suggest that the substance "+
    "comes from the mines under the Island of Deku, however, the entrance "+
    "to the mines has been lost for years now. Legend suggest that "+
    "sometime before the mines were closed and seal that Aorus Devar "+
    "had set out to retrieve some of the material in order to "+
    "experiment with it. Perhaps this is one such experiment? There "+
    "were thought to be several of these rings that each offered "+
    "different elemental protections.%^RESET%^");
       
    set_property("lore difficulty",25);
    set_ac(0);
    set_weight(2);
    set_value(4000);

	set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    Num = 2;
    while(Num--)
    {
        set_item_bonus(choose_protection(), 10);
        continue;
    }
    
}

int wearme()
{
    if(ETO->query_highest_level() < 25)
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^The power of the ring is far too great for "+
        "one so inexperienced!%^RESET%^");
        return 0;
    }
    tell_object(ETO, "%^BOLD%^%^GREEN%^The underside of the band feels bizarre as it "+
    "slips onto your finger and you can't help but to feel slightly squeamish as "+
    "an aura of protection surrounds you for a brief instant%^RESET%^");
    
    if(!ETO->query_invis())
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^ looks slightly squeamish "+
        "as a visible aura flickers around "+ETO->QO+"!%^RESET%^", ETO);
    }
	return 1;
}
	
int removeme()
{
    tell_object(ETO, "%^BOLD%^%^GREEN%^You feel relieved as the band slips off "+
    "your finger but somehow less protected as the aura around you "+
    "falters!%^RESET%^");
    
     if(!ETO->query_invis())
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^ looks slightly relieved "+
        "as a visible aura flickers around "+ETO->QO+"!%^RESET%^", ETO);
    }
	return 1;
}


int isMagic() { return 5; }

string choose_protection()
{
    int x;
    string myprot;
    x = sizeof(possible_protections);
    myprot = possible_protections[random(x)];
    possible_protections -= ({myprot});
    return myprot + " resistance";
}

