inherit "/std/weapon";
#include <std.h>

string OWNER;
void init(){
  ::init();
  if(interactive(TP) && TP==environment(TO) && !OWNER) OWNER=TPQN;
}
create() {
    ::create();

  set_id(({
  "justice","dagger"
  }));
  set_name("justice");
  set_property("no offer",1);
  set_short("%^BOLD%^%^YELLOW%^Justice%^RESET%^");
   set_long(
  "%^RESET%^%^BOLD%^"
  "  This gleaming silver dagger holds the markings of the magistrates who judge those in the city of Torm."
    "  Its long, fine blade is honed to a razor's edge. Although it's polished to a high shine the weapon itself is not guilded or set with any jewels."
    "  You get a feeling from it as if it's searching your heart for evil deeds, and you hope you never don't have any that need to be ended upon its edge."
  );
  set_weight(5);
   set_size( 1 );
  set_large_wc(2,4);
  set_wc(2,4);
  set_value(1300);
  set_property("enchantment",3);
  set_type("slashing");
  set_prof_type("small blades");
  set_wield((:TO,"extra_wield":));
}
int extra_wield(){
  if(!ETO) return 0;
  if(!interactive(TP)) return 1;
  if(((int)ETO->query_alignment() % 3)==0){
  write("%^BOLD%^%^RED%^The dagger bursts into flames and disapears as you try to wield it!");
    say(""+ETO->query_cap_name()+" screams and clutches at "+ETO->query_possessive()+" hand.");
  TO->set_property("magic");
  ETO->do_damage("torso",50);
  TO->remove_property("magic");
  ETO->add_attacker(TO);
  ETO->continue_attack();
    TO->remove();
  return 0;
  }
  if((string)ETO->query_name() !=OWNER){
  write("This blade is not yours to use.\n");
  TO->remove();
  return 0;
  }
  if(ETO->query_level()<25) {
  write("%^BOLD%^%^CYAN%^The dagger whispers to you that it cannot do justice in your hands till you are stronger.");
  return 0;
  }
  write("%^BOLD%^%^YELLOW%^The thoughts of bringing the criminals of shadowgate to justice fills your heart!");
  say("%^BOLD%^%^YELLOW%^"+ETO->query_cap_name()+" seems to glow with purpose wielding a silver dagger.");
  ETO->set_property("magic",1);
  return 1;
}
