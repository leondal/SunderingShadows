// a drowish cloak that poofs in the sun
#include <std.h>
#include <daemons.h>
inherit ARMOUR;
string tod;

void create(){
        ::create();
        set_name("blackened pants");
        set_id(({ "pants", "blackended pants", "pants of darkness" }));
        set_short("%^BOLD%^%^BLACK%^Pants of Blackness%^RESET%^");
        set_obvious_short("%^BOLD%^%^BLACK%^darkened pants%^RESET%^");
        set_long("%^BOLD%^%^BLACK%^These pants are made of spider silk.  "+
         "It seems to %^BLUE%^glow%^BLACK%^ with negative energy.  "+
         "Darkness pours out from it.  There are %^RESET%^gray "+
		 "spider leg %^BOLD%^%^BLACK%^patterns that are sewn"+
		 " on the legs of the pants.%^RESET%^");
        set_weight(5);
		set_property("lore difficulty",15);
        set_value(1000);
        set_lore("This clothing is made by a drow priestess"+ 
         " with innate weaving ability.  The pants"+
         " are used for scouts that wish to remain safe"
         " from stray blows while infiltrating." );
        set_type("clothing");
        set_limbs(({ "left leg","right leg" }));
        set_size(2);
        set_property("enchantment",2);
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
        " some pants making "+ETO->QO+""+
        " look darker",ETO);
        tell_object(ETO,"%^BOLD%^%^BLACK%^you wear the pants "+
        "and darkness seeps from you.");
       }
      else
       {tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" wears"+
        " some pants making "+ETO->QO+""+
        " but they hiss giving off a mist in the sunlight",ETO);
        tell_object(ETO,"%^BOLD%^BLACK%^you wear the pants "+
        "but they hiss giving off a mist in the sunlight.");
        TO->set_overallStatus(1);
        }
                return 1;
}
int remove_func(){
        tell_room(environment(ETO),"%^BOLD%^%^BLACK%^As "+ETOQCN+" "+
        "pulls off "+ETO->QP+" silk pants "+
        "darkness seems to seep back into them",ETO);
        tell_object(ETO,"You slip the pants off"+
        " and the world seems brighter.");
                return 1;


}
int strike_func(int damage, object what, object who){
if(!objectp(ETO)) return 1;
     
  tod = EVENTS_D->query_time_of_day();
     if(EETO->query_property("indoors") || tod=="night" )
       {tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+"'s"+
        " pants hiss"+
        " giving off a mist in the sunlight",ETO);
        tell_object(ETO,"%^BOLD%^BLACK%^your pants "+
        "hiss giving off a mist in the sunlight.");
        TO->set_overallStatus(1);
        return 1;
        }
    
        if(random(500) < 50){
        tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^For"+
        " a moment "+who->QCN+" looks surprised"+
        " by "+ETOQCN+"'s pants, as darkness pours "+
        "out of them",({ETO,who}));
        tell_object(ETO,"%^BOLD%^%^BLACK%^Darkness"+
        " begins to shed from the pants, clouding"+
        " "+who->QCN+" with uncertainty.");
        tell_object(who,"%^BOLD%^%^BLACK%^The darkness of "+ETOQCN+"'s"+
        " pants seems to cloud them from view.");
                return (-1*damage/2);}
}
