#include <std.h>

inherit "/std/armour";

int isSetup, isLight, isBroke;

void create() 
{
    ::create();   
}

string my_long()
{
    string tmp;
    if(isLight) 
    {
        if(isBroke)
        {
            tmp = "%^BOLD%^%^WHITE%^The band of this simple ring is made from a "+
                  "pure white material. The material is impossible to identify but you believe "+
                  "that it is some type of mineral. There is a very tiny and almost indistinguishable "+
                  "gem set into the top of the band that is cracked into multiple pieces. %^RESET%^";
            
        }
        else if(!query_worn())
        {
            tmp = "%^BOLD%^%^WHITE%^The band of this simple ring is made from a "+
                  "pure white material. The material is impossible to identify but you believe "+
                  "that it is some type of mineral. There is a very tiny and almost indistinguishable "+
                  "gem set into the top of the band. The gem seems to give off a faint light that sometimes "+
                  "flickers.%^RESET%^";   
        }
        else
        {
             tmp = "%^BOLD%^%^WHITE%^The band of this simple ring is made from a "+
                  "pure white material. The material is impossible to identify but you believe "+
                  "that it is some type of mineral. There is a very tiny and almost indistinguishable "+
                  "gem set into the top of the band. The gem is currently illuminated, giving off a "+
                  "soft light.%^RESET%^";   
        }
    }
    else if(!isLight)
    {
        if(isBroke)
        {
            tmp = "%^BOLD%^%^BLACK%^The band of this simple ring is made from a "+
                  "pure black. material. The material is impossible to identify but you believe "+
                  "that it is some type of mineral. There is a very tiny and almost indistinguishable "+
                  "gem set into the top of the band that is cracked into multiple pieces.%^RESET%^";   
        }
        else if(!query_worn())
        {
            tmp = "%^BOLD%^%^BLACK%^The band of this simple ring is made from a "+
                  "pure black. material. The material is impossible to identify but you believe "+
                  "that it is some type of mineral. There is a very tiny and almost indistinguishable "+
                  "gem set into the top of the band. The gem seems to give off a faint darkness that sometimes "+
                  "shimmers.%^RESET%^";   
        }
        else
        {
            tmp = "%^BOLD%^%^BLACK%^The band of this simple ring is made from a "+
                  "pure black. material. The material is impossible to identify but you believe "+
                  "that it is some type of mineral. There is a very tiny and almost indistinguishable "+
                  "gem set into the top of the band. The gem is currently radiating darkness.%^RESET%^";  
        }
    }
    return tmp;
}

string my_short()
{
    string tmp;
    if(isLight) tmp = "%^BOLD%^%^WHITE%^A lesser ring of light%^RESET%^";
    else tmp = "%^BOLD%^%^BLACK%^A lesser ring of darkness%^RESET%^";
    if(query_worn() && !isBroke)
    {
        if(isLight) tmp += " %^BOLD%^%^WHITE%^(%^BOLD%^%^CYAN%^ softly illuminated%^BOLD%^%^WHITE%^ )%^RESET%^";
        else tmp += "%^BOLD%^%^WHITE%^ ( %^BOLD%^%^BLACK%^radiating darkness %^BOLD%^%^WHITE%^)%^RESET%^";
    }
    return tmp;        
}

string my_obvious_short()
{
    string tmp;
    if(isLight) tmp = "%^BOLD%^%^WHITE%^A pure white ring%^RESET%^";
    else tmp = "%^BOLD%^%^BLACK%^A pure black ring%^RESET%^";
    if(query_worn() && !isBroke)
    {
        if(isLight) tmp += " %^BOLD%^%^WHITE%^(%^BOLD%^%^CYAN%^ softly illuminated%^BOLD%^%^WHITE%^ )%^RESET%^";
        else tmp += "%^BOLD%^%^WHITE%^ ( %^BOLD%^%^BLACK%^radiating darkness %^BOLD%^%^WHITE%^)%^RESET%^";
    }
    return tmp;        
}

void set_for(object myPlayer)
{
    if(!objectp(myPlayer)) return;
    isSetup = 1;
    if(member_array((string)myPlayer->query_race(), ({"bugbear", "hobgoblin",
    "goblin", "gnoll", "orc", "half-drow", "minotaur", "ogre", "ogre-mage", "half-ogre", 
    "kobold", "drow", "troll"})) == -1)
    {
        
        set_name("lesser ring of light");
        set_id(({"ring","ring of light", "lesser ring", "lesser ring of light"}));
        isLight = 1;
    }
    else 
    {
        set_name("lesser ring of darkness");
        set_id(({"ring","ring of darkness", "lesser ring", "lesser ring of darkness"}));
        isLight = 0;
    }    
    
    set_item_bonus("sight bonus", 2);    
    set_long((:TO, "my_long":));   
    set_obvious_short((:TO, "my_obvious_short":));
    set_short((:TO, "my_short":));
    set_type("ring");
    set_ac(0);
    set_weight(3);
    set_value(0);
    set_limbs(({"right hand","left hand"}));
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}

int wearme()
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(isBroke) return 1;
    if(isLight)
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^The gem on your ring begins illuminating softly.%^RESET%^");
        if(objectp(EETO)) 
        {
            tell_room(EETO, "%^BOLD%^%^WHITE%^The gem on "+ETOQCN+"%^BOLD%^%^WHITE%^"+
            "'s begins illuminating softly.%^RESET%^", ETO);
        }
    }
    else if(!isLight)
    {
        tell_object(ETO, "%^BOLD%^%^BLACK%^The gem on your ring begins radiating darkness.%^RESET%^");
        if(objectp(EETO)) 
        {
            tell_room(EETO, "%^BOLD%^%^BLACK%^The gem on "+ETOQCN+"%^BOLD%^%^WHITE%^"+
            "'s ring begins radiating darkness.%^RESET%^", ETO);
        }
    }
	return 1;
}
	
int removeme()
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(isBroke) return 1;
    if(isLight)
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^The gem on your ring dims.%^RESET%^");
        if(objectp(EETO)) 
        {
            tell_room(EETO, "%^BOLD%^%^WHITE%^The gem on "+ETOQCN+"%^BOLD%^%^WHITE%^"+
            "'s ring suddenly dims.%^RESET%^", ETO);
        }
    }
    else if(!isLight)
    {
        tell_object(ETO, "%^BOLD%^%^BLACK%^The gem on your ring flickers before becoming mundane once again.%^RESET%^");
        if(objectp(EETO)) 
        {
            tell_room(EETO, "%^BOLD%^%^BLACK%^The gem on "+ETOQCN+"%^BOLD%^%^WHITE%^"+
            "'s ring flickers before becoming mundane once again.%^RESET%^", ETO);
        }
    }
    if(!newbiep(ETO) && !isBroke)
    {
        if(!random(8))
        {
            tell_object(ETO, "%^BOLD%^%^RED%^The gem in your ring suddenly cracks!%^RESET%^");
            remove_property("sight bonus");
            isBroke = 1;
        }
    }
	return 1;
}

void init()
{
    ::init();
    if(isSetup) return;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!userp(ETO)) return;
    if(userp(ETO)) 
    {
        set_for(ETO);
        return;
    }
}
