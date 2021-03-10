#include <std.h>
inherit "/std/weapon.c";

create() {
    ::create();
  set_id(({"axe","lochebar","damned lochebar axe","damned lochebar"}));
  set_name("damned lochebar axe");
  set_short("%^BLUE%^Damned Lochebar Axe%^RESET%^");
   set_long(
  "%^BLUE%^  This long heavy axe is more commonly refered to as a headsmans axe."
  "  Its single square razor edged blade is made of dark burnished steel."
  "  The long dark shaft is covered in %^RED%^dull red runes%^BLUE%^ that glow with unholy power."
  "   Its weight makes you dream of seeing someones limbs come away from their body."
   );
  set_weight(15);
   set_size(3);
  set_value(150);
  set_wc(1,13);
  set_large_wc(1,13);
  set_type("slash");
   set_prof_type("large axe");
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
