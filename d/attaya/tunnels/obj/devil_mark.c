//Coded by Lujke
// This is a devil mark caused by the disease-bearing attack of a barbarzu 
// devil. It becomes active after an incubation period of 1-4 days and
// drains 1-4 points of str

// The disease can be cured in a number of ways. A break_curse spell will 
// allow the character to remove the mark, and the disease with it - as 
// will paying the fee to a temple to break the curse on the mark.

// Alternatively, the use of a phylactery of health by a cleric level 30+
// or a character with at least 16 ranks in the heal nwp will cure the 
// disease.

#include <std.h>
#define DAY 24000

inherit "/std/armour";  // so it can be worn. :)

// incubation date is the time when the disease finishes its incubation
// and becomes active.
int incubation_date, str_loss, begun;
void setup();


create() {
  ::create();
  set_name("mark");     //  set the name to ring
                        
  set_id(({"mark","devil mark","devil's mark", "disease"}));   

  set_short("%^RESET%^%^GREEN%^u%^ORANGE%^g%^GREEN%^ly"
            +" m%^BOLD%^%^BLACK%^a%^RESET%^%^GREEN%^rk");   
  set_long("An %^GREEN%^u%^ORANGE%^g%^GREEN%^ly m%^BOLD%^%^BLACK%^a"
          +"%^RESET%^%^GREEN%^rk on your face, like a bad bruise that has"
          +" turned %^GREEN%^s%^ORANGE%^e%^GREEN%^ptic%^RESET%^%^GREEN%^"
          +" and the skin has started to open");

  set_type("ring"); 
    
  set_ac(1);             
  set_weight(0);          
  set_value(0);         
  
  set_limbs(({"right hand","left hand"}));  
  set_property("enchantment",-1);
//  set_property("no remove",1); -> prevented removal at temples/by spell. Nienne, 10/09.
  if(query_property("enchantment") > 0){
      remove_property("enchantment");
      set_property("enchantment",-1);
   }
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
   setup();
}
int wear_func()
{

  if (time()>incubation_date)
  {
    ETO->add_stat_bonus("strength",(-1*str_loss));
    tell_object(ETO, "You feel weakened by %^GREEN%^d%^BOLD%^%^GREEN%^i"
                      +"%^RESET%^%^GREEN%^se%^ORANGE%^a%^GREEN%^se");
  }
  return 1;
}

int remove_func()
{
  if (time()>incubation_date)
  {
    ETO->add_stat_bonus("strength",(str_loss));
    tell_object(ETO, "You feel the disease leave you, and hope that it is"
                    +" gone for good!");
  }
  return 1;
}

void setup()
{
  incubation_date = time()+ ((random(3)+1)*DAY); 
  str_loss = random(3)+1;
  begun = 0;
}

int query_incubation_date()
{
  return incubation_date;
}
int query_str_loss()
{
  return str_loss;
}
void set_str_loss(int loss)
{
  str_loss = loss;
}
void set_incubation_date(int date)
{
  incubation_date = date;
}
