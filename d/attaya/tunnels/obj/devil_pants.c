// Coded by Lujke. These are the rock devils' leather pants. They are
// enchanted to +1, and give a bonus of +1 to cha.
// updated cha bonus from the new system. Nienne, 09/07.

#include <std.h>
#include <move.h>
inherit ARMOUR;

void create()
{
  ::create();
  set_obvious_short("%^BOLD%^%^RED%^A pair of red pants%^RESET%^");
  set_name("red pants");
  set_short("%^BOLD%^%^RED%^P%^RESET%^%^RED%^a%^BOLD%^%^RED%^nts of the %^BOLD%^%^RED%^r%^BOLD%^%^BLACK%^o%^BOLD%^%^RED%^ck d%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^v%^RED%^i%^BOLD%^%^BLACK%^l%^RESET%^");
  set_id(({"pants","devil pants","red pants"}));
  set_long("%^BOLD%^%^RED%^A pair of f%^YELLOW%^i%^RESET%^%^RED%^e"
          +"%^BOLD%^%^RED%^ry red leather pants cut tight and low around"
          +" the h%^YELLOW%^i%^BOLD%^%^RED%^ps, but a little looser lower"
          +" d%^YELLOW%^o%^BOLD%^%^RED%^wn. Traces of y%^YELLOW%^e"
          +"%^BOLD%^%^RED%^llow patterning flicker are c%^YELLOW%^u"
          +"%^BOLD%^%^RED%^t into the leather like random f%^YELLOW%^l"
          +"%^RESET%^%^RED%^a%^BOLD%^%^RED%^mes There is not a h"
          +"%^YELLOW%^i%^BOLD%^%^RED%^nt of subtlety about these"
          +" p%^YELLOW%^a%^BOLD%^%^RED%^nts. They look like they were"
          +" c%^YELLOW%^u%^BOLD%^%^RED%^t by someone who may not have"
          +" known what th%^YELLOW%^e%^BOLD%^%^RED%^y wanted to say but"
          +" just wanted to say it L%^YELLOW%^O%^BOLD%^%^RED%^UD.");
  set_lore("The pits of the lower hells are places of heat and fire,"
          +" worlds of hurt and damage. The devils who live there are"
          +" fierce and aggressive, and their dress sense reflects"
          +" this. The fire design on these pants and the rather strange"
          +" leather they are made out of makes you suspect that they"
          +" could be infernal in origin");
  set_property("lore difficulty",14);
  set_weight(8);
  set_type("leather");
  set_limbs(({"left leg","right leg"}));
  set_ac(0);
  set_property("enchantment",4);
  set_value(1000);
  set_wear((:TO,"wear_func":));
  set_remove((:TO,"remove_func":));
  switch (random(8))
  {
  case 0:
    set_size(1);
    set_lore(query_lore()+"\nThe devil who wore this pair must"
             +" have been smaller than most!");
    break;
  case 1:
    set_size(3);
    set_lore(query_lore()+"\nThe devil who wore this pair must"
             +" have been rather large!");
    break;
  default:
    set_size(2);
  }
  set_item_bonus("charisma",1);
}



int wear_func(){
  string godtype;
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  if((int)ETO->query_level() < 25) {
    notify_fail("The pants are too powerful for you at present!");
    return 0;
  }    
  if ((string)ETO->query_gender()=="male"){
    godtype = "God";
  }
  else {
    godtype = "Goddess";
  }

  tell_room(EETO,"BOLD%^%^RED%^"+ETOQCN+" pulls on "+ETO->QP 
                 +query_short() + ".",ETO);
        tell_object(ETO,"%^BOLD%^%^RED%^You pull on the " + query_short()
                  + "%^BOLD%^%^RED%^ and feel like a "+godtype +"!");
        return 1;
}

int remove_func(){
  string gender;
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  if ((string)ETO->query_gender()=="male"){
    gender = "man";
  }
  else {
    gender = "woman";
  }

  tell_room(EETO,"%^BOLD%^%^RED%^ shucks off "+ETO->QP+" " + query_short()
                +" and seems a little less impressive.",ETO);
  tell_object(ETO,"%^BOLD%^%^RED%^You remove the " + query_short() 
                + " and feel a little less " + gender + "ly");
        return 1;
}