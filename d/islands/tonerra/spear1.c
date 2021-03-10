//spear1.c one handed spear from M+O island

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit WEAPON;

void create(){
  ::create();
  set_name("Short spear");
  set_id(({"spear","short","short spear","Short spear"}));
  set_short("Short spear");
  set_long(
@OLI
  This is a short spear. The head is carved from stone and attached 
solidly to the hard jungle wood shaft. The butt of the shaft is rounded 
off to serve as a bludgeoning weapon.
OLI
  );
  set_type("piercing");
  set_wc(2,3);
  set_large_wc(3,3);
  set_hit((:TO,"hit_me":));
  set_size(1);
  set_weight(5);

}

int hit_me(object targ){
  int i;
  
  if((random(40) < 4 && !interactive(ETO)) || random(40) < 2){
    tell_object(targ,"The butt of the spear swing around and clubs you as blade swings through you.");
    tell_room(environment(targ),"The but of the spear swings around and clubs "+targ->query_cap_name()+" and the blade swings through "+targ->query_objective()+".",targ);
      targ->do_damage("torso",roll_dice(2,3));
  }
  return 0;
}
