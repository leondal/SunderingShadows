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
  "greed","dagger"
  }));
  set_name("greed");
  set_short("%^MAGENTA%^Greed%^RESET%^");
   set_long(
  "%^BOLD%^%^GREEN%^"
   "  This short evil looking dagger fills you with longing for things you don't have."
  "  Its copper blade is stained green and there are settings in the pommel where jewels must once have been pried out."
  );
  set_weight(10);
   set_size( 1 );
  set_large_wc(1,6);
  set_wc(1,6);
  set_value(5);
  set_type("piercing");
  set_property("enchantment",3);
  set_prof_type("small blades");
  set_wield((:TO,"extra_wield":));
  set_hit((:TO,"extra_hit":));
}
int extra_wield(){
  if(!ETO) return 0;
  if(!interactive(TP)) return 1;
  if((string)ETO->query_name() !=OWNER){
  write("The dagger laughs and fills your eyes with tears as it disapears.\n");
  TO->remove();
  return 0;
  }
  if(ETO->query_level()<25) {
  write("The dagger laughs as your weak hand tries to hold it!\n");
  return 0;
  }
  ETO->set_property("magic",1);
  return 1;
}
int extra_hit(object ob){
 if(!random(10)){
  tell_object(ETO,"%^YELLOW%^"+ob->query_cap_name()+"s things are yours and the dagger bites a little deeper to help you get them back.");
  tell_room(environment(ETO),"%^YELLOW%^"+ETO->query_cap_name()+"s eyes are filled with hate as the dagger strikes "+ob->query_cap_name()+"!",(({ETO,ob})));
  tell_object(ob,"%^YELLOW%^"+ETO->query_cap_name()+"s eyes hold a queer gleam as the brass blade bites into you!");
  ob->do_damage("torso",random(20)+1);
 return (random(6)+2);
   }
  return(random(6)+2);
}
