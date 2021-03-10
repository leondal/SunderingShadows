//  Desecrator originally done by Thorn@shadowgate, 970316
// Updated 990908 by Amidon.
#include <std.h>
inherit WEAPON;

void create(){
  ::create();
  set_name("Sword of Desecration");
  set_id(({"sword","desecration","sword of desecration","desecrator"}));
  set_short("%^RED%^Sword of Desecration%^RESET%^");
  set_long(
  "%^BLUE%^"
  " This is a Sword of Desecration, a weapon of evil and destruction."
  "  The hilt of this weapon is blackened iron, wrapped in black velvet."
  "  The blade shines like dull obsidian, flecked here and there with rust brown stains that can only be %^BOLD%^%^RED%^BLOOD%^RESET%^."
  );
  set_weight(15);
  set_value(1000);
  set_wc(1,8);
  set_large_wc(1,12);
  set_size(2);
  set_type("slashing");
  set_prof_type("avengers");
  set_property("enchantment",2);
  set_hit((:TO,"extra_hit":));
  set_wield((:TO,"extra_wield":));
  set_unwield((:TO,"extra_unwield":));
}
int extra_hit(object ob){
  int dam;
  if(!objectp(ob)) return 1;
  if (((int)ob->query_alignment() % 3)==1){
  if((int)ob->query_alingment()==1){dam=10;}
  if((int)ob->query_alignment()==4){dam=6;}
  if((int)ob->query_alignment()==7){dam=8;}
  if(!random(2)){
  tell_object(ob,"%^RED%^The sword wielded by "+ETO->query_cap_name()+" flames as it cuts into your flesh!%^RESET%^");
  tell_object(ETO,"%^RED%^A bright red flame eminates from the blade as it cuts into the flesh of your enemy!%^RESET%^");
  tell_room(environment(ETO),"%^RED%^The sword wielded by "+ETO->query_cap_name()+" flashes with a red flame as it strikes "+ob->query_cap_name()+"!%^RESET%^",({ob,ETO}));
  }
  return dam;
  }
  return random(5)+1;
}
int extra_wield(){
  if(!TP) return 0;
  if((int)TP->query_level()<25){
  tell_object(ETO,"You may not wield such a powerful weapon!");
  return 0;
  }
  if(TP->is_class("antipaladin")){
  if (!TP->query_property("desecrated")){
    remove_property("enchantment");
    set_property("enchantment",5);
    TP->set_property("magic resistance",50);
  ETO->set_property("desecrated",1);
  }
  write("%^RED%^The evil sword blazes with the flames of the Pit itself in your hands!%^RESET%^");
  say("%^CYAN%^You hear the screams of tortured souls as "+ETO->query_cap_name()+" wields the Sword of Desecration!");
    return 1;
  }
  if(((int)TP->query_alignment() % 3) ==1){
  ETO->do_damage(1,10);
  write("%^RED%^The evil sword blazes in your hands and sears your flesh leaving an evil burn!%^RESET%^");
    say("%^CYAN%^You hear "+ETO->query_cap_name()+" scream in pain as the Sword of Desecration falls to the ground and disappears!");
  TO->remove();
  return 0;
  }
  remove_property("enchantment");
  set_property("enchantment",2);
  write("%^RED%^The sword blazes with POWER in your hands!%^RESET%^");
  say("%^CYAN%^"+ETO->query_cap_name()+" wields the Sword of Desecration.%^RESET%^");
  return 1;
}
int extra_unwield(){
  remove_property("enchantment");
  set_property("enchantment",2);
  if(ETO->query_property("desecrated")){
    ETO->set_property("magic resistance",-50);
  ETO->remove_property("desecrated");
  }
  return 1;
}
