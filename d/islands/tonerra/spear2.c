//spear2.c one handed spear from M+O island
//"hit_me" messages changed for clarification.  Circe 12/8/03

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit WEAPON;

void create(){
  ::create();
  set_name("Long spear");
  set_id(({"spear","long","long spear","Long spear"}));
  set_short("Long spear");
  set_long(
@OLI
  This is a long spear. The head is carved from stone and attached 
solidly to the hard jungle wood shaft. The long shaft provides for  
strong thrust an good leverage. The head is slightly hooked so that 
when the spear is removed from a deep wound it tears and rips the 
flesh more.
OLI
  );
  set_type("piercing");
   set_prof_type("large spear");
   set_value(30);
  set_wc(2,4);
  set_large_wc(3,4);
  set_hit((:TO,"hit_me":));
  set_size(3);
  set_weight(8);
  set_property("enchantment",3);
  set_value(80);
}

int hit_me(object targ){
  int i;
  
  if(!objectp(ETO)) return 1;
   if( !random(6)) {
    tell_object(targ,"The spearhead digs deeply into your flesh and as "+ETO->query_cap_name()+" pulls it out, it tears your flesh horribly");
    tell_room(environment(targ),"The spearhead digs deeply into "+targ->query_cap_name()+"'s flesh and as it is yanked out, it tears "+targ->query_possessive()+" flesh horribly.",targ);
    targ->do_damage("torse",roll_dice(2,5));
  }
  return 0;
}
