// a drowish cloak that melts in sun
#include <std.h>
#include <daemons.h>
inherit ARMOUR;
string tod;

void create(){
        ::create();
        set_name("blackness cloak");
        set_id(({ "cloak", "cloak of blackness", "blackness cloak","darkened cloak" }));
        set_short("%^BOLD%^%^BLACK%^Cloak of Blackness%^RESET%^");
        set_obvious_short("%^BOLD%^%^BLACK%^A darkened cloak%^RESET%^");
        set_long("%^BOLD%^%^BLACK%^"+
		 "This cloak is made of spider silk.  "+
         "It seems to glow with negative energy.  "+
         "Darkness pours out from it.  Sewn into the fabric "+
		 "are many %^BLUE%^dark runes%^RESET%^.  There is a gray spider "+
		 "%^BOLD%^%^BLACK%^on the back.  "+
		 "One can sense the power of darkness in "+
		 "this piece of clothing.%^RESET%^");
        set_weight(5);
        set_value(1000);
		set_property("lore difficulty",15);
        set_lore("This clothing is made by a drow priestess"+ 
         " with innate weaving ability.  The cloaks"+
         " are used for scouts that wish to remain safe"
         " from stray blows while infiltrating." );
        set_type("clothing");
        set_limbs(({ "neck" }));
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
       {tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" dons"+
        " a cloak making "+ETO->QO+""+
        " look darker",ETO);
        tell_object(ETO,"%^BOLD%^%^BLACK%^you don the cloak "+
        "and darkness seeps from you.");
       }
      else
       {tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" dons"+
        " a cloak making "+ETO->QO+" look darker,"+
        " but it hisses giving off a mist in the sunlight",ETO);
        tell_object(ETO,"%^BOLD%^BLACK%^you don the cloak "+
        "but it hisses giving off a mist in the sunlight.");
        TO->set_overallStatus(1);
        }
                return 1;
}
int remove_func(){
        tell_room(environment(ETO),"%^BOLD%^%^BLACK%^As "+ETOQCN+" "+
        "pulls off "+ETO->QP+" silk cloak "+
        "darkness seems to seep back into it",ETO);
        tell_object(ETO,"You slip the cloak off"+
        " and the world seems brighter.");
                return 1;


}
int strike_func(int damage, object what, object who){
if(!objectp(ETO)) return 1;
     
  tod = EVENTS_D->query_time_of_day();
     if(EETO->query_property("indoors") || tod=="night" )
       {tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" dons"+
        " a cloak making "+ETO->QO+""+
        " but it hisses giving off a mist in the sunlight",ETO);
        tell_object(ETO,"%^BOLD%^BLACK%^you don the cloak "+
        "but it hisses giving off a mist in the sunlight.");
        TO->set_overallStatus(1);
        return 0;
        }
    
        if(random(500) < 50){
        tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^For"+
        " a moment "+who->QCN+" looks surprised"+
        " by "+ETOQCN+"'s cloak, as darkness pours "+
        "out of it",({ETO,who}));
        tell_object(ETO,"%^BOLD%^%^BLACK%^Darkness"+
        " begins to shed from the cloak, clouding"+
        " "+who->QCN+" with uncertainty.");
        tell_object(who,"%^BOLD%^%^BLACK%^The darkness of "+ETOQCN+"'s"+
        " cloak seems to cloud them from view.");
                return (-1*damage/2);}
}
