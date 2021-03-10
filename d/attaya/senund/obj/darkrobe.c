#include <std.h>
inherit ARMOUR;
object OWNER;
void init()
{
    ::init();
    if(interactive(ETO) && ETO==environment(TO) && !OWNER) OWNER = ETOQN;
}
create() 
{ 
    ::create();
    set_name("robe");
    set_id(({"robe","robe of darkness","dark robe","darkness robe"}));
    set_short("%^RESET%^%^BLUE%^Robe of Darkness%^RESET%^");
    set_long(
@BRUENOR
    %^BOLD%^%^BLACK%^The robe embodies darkness. It is completly black 
    and in the dark cannot be seen at all. Only reason you can even see
    this robe during the day is because it contrasts with everything else.
    It is not as if this robe is dyed to appear as dark black as possible, 
    it is almost as if this robe is infact the complete absense of light. 
    Due to the odd almost insubstantial material of the robe you seem to 
    think the latter may be true.%^RESET%^
BRUENOR
    );
    set_weight(10);
    set_value(500);
    set_type("clothing");
    set_limbs(({"torso"}));
    set_ac(0);
    set_property("enchantment",3);
    set_item_bonus("stealth",2);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
    set_struck((:TO,"strikeme":));

}
int wearit() 
{
    if((int)ETO->query_highest_level() < 25) 
    {    
        tell_object(ETO,"%^BLUE%^You feel ill as you try to don the robe and decide its best to take it back off.");
        return 0;
    }
     if(interactive(ETO) && (string)ETO->query_name() != OWNER)
    {
        tell_object(ETO,"%^BOLD%^%^RED%^The robe does not fit to the frame of your body");
        return 0;
    }

    tell_object(ETO,
        "%^BLUE%^You don the robe and feel more at ease in the dark!%^RESET%^");
    tell_room(EETO,
        "%^BLUE%^"+ETOQCN+" seems to fade into the shadows a bit.%^RESET%^",ETO);       
    return 1;
}
int removeit() 
{
    tell_object(ETO,
        "%^BLUE%^The world of light seems more substantial to you now.%^RESET%^");
    tell_room(EETO,
        "%^BLUE%^"+ETOQCN+" appears more substantial now.%^RESET%^",ETO);
    return 1;
}
int strikeme(int damage, object what, object who)
{
      int num;
      int num2;
      num2 = 20;
      if (!random(4))
      {
      	if(objectp(what))
      	{

      	tell_object(ETO,"%^BLUE%^The force behind "+who->QCN+
      			  "'s weapon gets abosrbed into the robe "+
       			  "as it strikes you.%^RESET%^");
      
      
      	tell_object(who,"%^BLUE%^The insubstantial folds of "+ETOQCN+
      			 "'s robe absorbs the majority of your blow%^RESET%^");


      	tell_room(environment(query_worn()),"%^BLUE%^"+who->QCN+
      	       "'s blow is absorbed into the shadowy form of "
      	       +ETOQCN+".",({who,ETO}));
      	num = ((damage)-(num2));
      	if (num < 0)
      	{
      		num = damage;
      	}
      	num = ((-1)*(num));
      	return num;
      	}
      }
      	else
      	{
      	    return 0;
   	  	}
}


