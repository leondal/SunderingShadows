//Many thanks to Shar for creating this item :)
#include <std.h>
inherit "/d/common/obj/weapon/sickle.c";

void create(){
        ::create();
        set_name("harvest moon");
        set_id(({ "harvest moon", "moon", "sickle" }));
set_short("%^ORANGE%^Har%^YELLOW%^v%^RESET%^%^ORANGE%^est %^YELLOW%^M%^RESET%^%^ORANGE%^oo%^YELLOW%^n%^RESET%^");
        set_obvious_short("A copper sickle");
        set_long(
           "%^ORANGE%^This copper sickle has a crescent moon-like "+
           "shaped blade.  Carved into the copper is a relief of farmers "+
           "harvesting the fields.  Some of the copper has already started "+
           "to oxidize, turning a %^BOLD%^%^WHITE%^silver %^GREEN%^green "+
           "%^RESET%^%^ORANGE%^color.  The hand grip of the sickle has been "+
           "wrapped in green cotton, well worn from use."
        );
        set_value(750);
        set_lore("The Harvest Moon is used by the elder of the village to cut the first "
"grain of the new year.  It is a time honored tradition, going back hundreds "
"of years.  Some claim that the earth itself has blessed the sickle, because "
"of the farmer's actions.");
	set_property("lore difficulty",8);
        set_property("enchantment",1);
        set_item_bonus("damage bonus",1);
        set_wield((:TO,"wield_func":));
        set_unwield((:TO,"unwield_func":));
        set_hit((:TO,"hit_func":));
}
int wield_func(){
        tell_room(environment(ETO),"",ETO);
        tell_object(ETO,"%^ORANGE%^The sickle glows softly at your touch.%^RESET%^");
        return 1;
}
int unwield_func(){
        tell_room(environment(ETO),"",ETO);
        tell_object(ETO,"");
        return 1;
}
int hit_func(object targ)
{
    if(!objectp(targ)) { return 0; }
    if(!objectp(TO)) { return 0; }
    if(!objectp(ETO)) { return 0; }
    if(!objectp(EETO)) { return 0; }
        
    if(random(1000) < 300)
    {
        tell_room(EETO,"%^YELLOW%^"+ETO->QCN+"'s sickle glows softly as it sinks "
            "into "+targ->QCN+"%^RESET%^",({ETO,targ}));
        tell_object(ETO,"%^YELLOW%^The sickle glow softly as it sinks into "+targ->QCN+"%^RESET%^");
        tell_object(targ,"%^YELLOW%^"+ETO->QCN+"'s sickle glows softly as it sinks into you.%^RESET%^");
        return roll_dice(2,4)+2;        
    }
    else if(random(1000) < 200)
    {
         set_property("magic",1);
         tell_room(EETO,"%^ORANGE%^"+ETO->query_cap_name()+"'s sickle glows %^YELLOW%^g"
             "%^RESET%^%^ORANGE%^o%^YELLOW%^l%^RESET%^%^ORANGE%^d%^YELLOW%^e%^RESET%^"
             "%^ORANGE%^n orange, causing "+ETO->query_objective()+" to look refreshed.",({ETO,targ}));
         tell_object(ETO,"%^ORANGE%^You sickle glows %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^"
             "l%^RESET%^%^ORANGE%^d%^YELLOW%^e%^RESET%^%^ORANGE%^n orange, proving to be refreshing.");
         ETO->do_damage("torso",(-1)*(random(5)+1));
         remove_property("magic");
         return 1;
   }
   else return 0;
}
