// a drowish mask that doesn't like the sun
#include <std.h>
#include <daemons.h>
inherit ARMOUR;
string tod;

void create(){
        ::create();
        set_name("blackened mask");
        set_id(({ "mask", "blackended mask", "mask of darkness","darkened mask" }));
        set_short("%^BOLD%^%^BLACK%^mask of Blackness%^RESET%^");
        set_obvious_short("%^BOLD%^%^BLACK%^darkened mask%^RESET%^");
        set_long("%^BOLD%^%^BLACK%^This mask is made of spider silk.  "+
         "It seems to %^BLUE%^glow%^BLACK%^ with negative energy.  "+
		 "A %^RESET%^gray spider pattern%^BOLD%^%^BLACK%^ is woven on the face.  "+
         "Darkness pours out from it.  When moving about the item leaves"+
		 " a trail of darkness much like a black mist.  There are several "+
		 "onyx stones that line the edge of the face.  "+
		 "Silk straps on the back hold the mask in place.%^RESET%^");
        set_weight(1);
        set_value(1000);
		set_property("lore difficulty",15);
        set_lore("This clothing is made by a drow priestess"+ 
         " with innate weaving ability.  The masks"+
         " are used for scouts that wish to remain safe"
         " from stray blows while infiltrating." );
        set_type("clothing");
        set_limbs(({ "head" }));
        set_size(-1);
        set_property("enchantment",2);
	set_item_bonus("sight bonus",-1);
        set_ac(0);
        set_wear((:TO,"wear_func":));
        set_remove((:TO,"remove_func":));
        set_struck((:TO,"strike_func":));
}
int wear_func(){
      if(!objectp(ETO)) return 1;
	  if(!objectp(EETO)) return 1;
      tod = EVENTS_D->query_time_of_day();
      if(EETO->query_property("indoors") || tod=="night" )
       {tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" wears"+
        " the mask making "+ETO->QO+""+
        " look darker",ETO);
        tell_object(ETO,"%^BOLD%^%^BLACK%^you wear the mask "+
        "and darkness seeps from you.");
       }
      else
       {tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" wears"+
        " the mask "+
        " but it hisses giving off a mist in the sunlight",ETO);
        tell_object(ETO,"%^BOLD%^BLACK%^you wear the mask "+
        "but it hisses giving off a mist in the sunlight.");
        TO->set_overallStatus(1);
        }
                return 1;
}
int remove_func(){
        tell_room(environment(ETO),"%^BOLD%^%^BLACK%^As "+ETOQCN+" "+
        "pulls off "+ETO->QP+" silk mask "+
        "darkness seems to seep back into it",ETO);
        tell_object(ETO,"You slip the mask off"+
        " and the world seems brighter.");
                return 1;


}
int strike_func(int damage, object what, object who){
if(!objectp(ETO)) return 1;
     
  tod = EVENTS_D->query_time_of_day();
     if(EETO->query_property("indoors") || tod=="night" )
       {tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+"'s mask"+
        " gives off a mist in the sunlight",ETO);
        tell_object(ETO,"%^BOLD%^BLACK%^your mask "+
        "hisses and gives off a mist in the sunlight.");
        TO->set_overallStatus(1);
        return 1;
        }
    
        if(random(500) < 50){
        tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^For"+
        " a moment "+who->QCN+" looks surprised"+
        " by "+ETOQCN+"'s mask, as darkness pours "+
        "out of them",({ETO,who}));
        tell_object(ETO,"%^BOLD%^%^BLACK%^Darkness"+
        " begins to shed from the mask clouding"+
        " "+who->QCN+" with uncertainty.");
        tell_object(who,"%^BOLD%^%^BLACK%^The darkness of "+ETOQCN+"'s"+
        " mask seems to cloud them from view.");
                return (-1*damage/2);}
}
