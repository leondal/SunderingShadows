#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
  set_id(({"halberd","damned halberd"}));
  set_name("damned halberd");
  set_short("%^BLUE%^Damned Halberd%^RESET%^");
   set_long(
  "%^BLUE%^  This long dark pole arm glows with unholy power."
  "   Its axe head is burnished black steel and %^RED%^dull red runes %^BLUE%^run the length of the shaft."
  "  The spike and hook on the weapon are barbed horribly to catch and tear at flesh through armor."
   );
  set_weight(20);
   set_size(3);
  set_value(150);
  set_wc(3,4);
  set_large_wc(3,6);
   set_type("slash");
   set_prof_type("polearm");
  if(!random(5)){set_property("enchantment",1);}
  if(!random(25)){set_property("enchantment",1);}
  if(!random(75)){set_property("enchantment",1);}
  if (!TO->query_property("enchantment")){
  set_property("monsterweapon",1);
  set_property("enchantment",4);
  }
  set_hit((:TO,"extra_hit":));
  set_wield((:TO,"extra_wield":));
}
  int extra_hit(object ob){  
  if(!random(4)){
  tell_object(ETO,"\n%^BOLD%^BLUE%^The %^RESET%^%^RED%^rune%^BOLD%^%^BLUE%^ on the weapon glows brightly as you strike "+ob->query_cap_name()+"!");
  tell_room(environment(ETO),"\n%^BOLD%^%^BLUE%^A %^RESET%^%^RED%^rune%^BOLD%^%^BLUE%^ on "+ETO->query_cap_name()+"s "+TO->query_name()+" glows brightly as "+ETO->query_subjective()+" hits "+ob->query_cap_name()+"!",(({ETO,ob})));
  tell_object(ob,"%^BOLD%^%^BLUE%^\nA %^RESET%^%^RED%^rune %^BOLD%^%^BLUE%^on "+ETO->query_cap_name()+"s "+TO->query_name()+" glows brightly as "+ETO->query_subjective()+" hits you!");
  return(random(5)+1);
  }
}
int extra_wield(){
  if((int)ETO->query_level() < 20){tell_object(ETO,"%^BLUE%^The weapon laughs as such a weak hand as yours tries to wield it!");return 0;}
  tell_object(ETO,"%^BLUE%^Evil flows into you from the "+TO->query_name()+" that you hold!");
  tell_room(environment(ETO),"%^BLUE%^"+ETO->query_cap_name()+" shudders as evil flows into him from the axe.",ETO);
  if(!wizardp(ETO)){
  ETO->add_align_adjust(-5);
  "daemon/killing_d"->check_align(ETO);
  }
  return 1;
}
