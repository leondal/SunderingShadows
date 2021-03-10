#include <std.h>
inherit "/std/weapon";
object *LIMB,OB2;


create() {
    ::create();
  set_id(({"axe","lochebar","phederias lochebar"}));
  set_name("damned lochebar");
  set_short("%^BOLD%^%^BLUE%^Phederias Lochebar%^RESET%^");
   set_long(
  "  %^BLUE%^This is the axe given to Phederia by the Bone Shaman to help in her rise to power."
  "  Its power is great but so is its curse.   Beware those who would try to use the axe after it's fallen from her hands!"
  "%^BLUE%^  This long heavy axe is more commonly refered to as a headsmans axe."
  "  Its single square razor edged blade is made of dark burnished steel."
  "  The long dark shaft is covered in %^RED%^dull red runes%^BLUE%^ that glow with unholy power."
  "   Its weight makes you dream of seeing someones limbs come away from their body."
   );
  set_weight(20);
   set_size(3);
  set_value(4000);
  set_wc(1,13);
  set_large_wc(1,13);
  set_type("slash");
   set_prof_type("large axe");
  set_property("enchantment",4);
  set_wield((:TO,"extra_wield":));
  set_hit((:TO,"extra_hit":));
}
int extra_hit(object ob){
  if((int)ob->query_hp() < 0){
  if(!random(15)){
  LIMB=ob->return_target_limb();
  OB2=new("/std/obj/body_part.c");
  OB2->set_limb(ob->query_cap_name(),LIMB);
  OB2->move(environment(ETO));
  ob->do_damage("torso",(int)ob->query_max_hp());
  tell_object(ETO,"%^BLUE%^As "+ob->query_name()+" staggers back you lunge forward with the axe and sever "+ob->query_possessive()+" "+LIMB+" from "+ob->query_possessive()+" body!");
  tell_object(ob,"%^BLUE%^"+ETO->query_cap_name()+" severs your "+LIMB+"!");
  tell_room(environment(ETO),"%^BLUE%^"+ETO->query_cap_name()+" severs "+ob->query_name()+"s "+LIMB+" with a maniacal grin!",({ob,ETO}));
  ob->do_damage(ob->query_max_hp());
  }
  }
  if(!random(4)){
  tell_object(ETO,"\n%^BOLD%^BLUE%^The %^RESET%^%^RED%^rune%^BOLD%^%^BLUE%^ on the weapon glows brightly as you strike "+ob->query_cap_name()+"!");
  tell_room(environment(ETO),"\n%^BOLD%^%^BLUE%^A %^RESET%^%^RED%^rune%^BOLD%^%^BLUE%^ on "+ETO->query_cap_name()+"s "+TO->query_name()+" glows brightly as "+ETO->query_subjective()+" hits "+ob->query_cap_name()+"!",(({ETO,ob})));
  tell_object(ob,"%^BOLD%^%^BLUE%^\nA %^RESET%^%^RED%^rune %^BOLD%^%^BLUE%^on "+ETO->query_cap_name()+"s "+TO->query_name()+" glows brightly as "+ETO->query_subjective()+" hits you!");
  return(random(10)+1);
  }
}
  int extra_wield(){
  if((int)ETO->query_level() < 25){tell_object(ETO,"%^BLUE%^The weapon laughs as such a weak hand as yours tries to wield it!");return 0;}
  tell_object(ETO,"%^BLUE%^Evil flows into you from the "+TO->query_name()+" that you hold!");
  tell_room(environment(ETO),"%^BLUE%^"+ETO->query_cap_name()+" shudders as evil flows into "+ETO->query_objective()+" from the axe.",ETO);
  if(!wizardp(ETO)){
  ETO->add_align_adjust(-10);
   "daemon/killing_d"->check_align(ETO);
  }
  return 1;
}
