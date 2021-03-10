#include <std.h>
inherit "/std/weapon";
create (){
  ::create();
  set_id(({"sword","scimitar","scimitar of the starless night",}));
  set_name("black scimitar");
  set_short("%^BOLD%^%^BLACK%^scimitar of the starless night%^RESET%^");
  set_long(
  "%^B_BLUE%^%^CYAN%^ "
  "This scimitar is as black as a shadow at midnight.   Its edge is hard and clean and no scratches or nicks adorn its surface.   It seems formed of one piece with no mold or forge marks or variances in color between blade and hilt."
  "  Its almost as if it were poured from the escence of dark and formed perfectly into the shadow of a scimitar."
  "%^RESET%^"
  );
  set_weight(5);
  set_size(2);
  set_value(1000);
  set_wc(1,8);
  set_large_wc(2,5);
  set_property("enchantment",2);
  set_type("slashing");
  set_prof_type("medium blades");
  set_hit((:TO,"extra_hit":));
}
int extra_hit(object ob){
  if(!objectp(ob)) return 1;
  if(!random(10)){
  tell_object(ETO,"%^BLUE%^Your scimitar seems to fade from sight as it slices through "+ob->query_cap_name()+"!");
  tell_object(ob,"%^BLUE%^"+ETO->query_cap_name()+"'s scimitar slices through you leaving you chilled to the core.");
  tell_room(environment(ETO),"%^BLUE%^"+ETO->query_cap()+"'s sword fades from sight as is slashes through "+ob->query_cap_name()+"!",(({ETO,ob})));
  ob->do_damage("torso",random(10)+1);
  if(!random(5)){
  tell_object(ob,"%^BLUE%^As the scimitar slashes through your body it steals the light from your eyes!");
  if(ob->query_blind()) return 1;
  ob->set_blind(1);
  }
  return 1;
}
}
