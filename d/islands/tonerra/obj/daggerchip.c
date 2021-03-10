//spear1.c one handed spear from M+O island

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit WEAPON;

int chips;
void create(){
  ::create();
  set_name("stone dagger");
  set_id(({"stone dagger","dagger","Dagger","Stone dagger"}));
  set_short("Stone Dagger");
  set_long(
@OLI
  This is a small stone dagger. A solid piece of stone carved into a
knife like shape. The handle is shaped to fit the hand perfectly. The 
blade is solid, slightly chipped and hune extremely sharp. 
OLI
  );
  set_type("piercing");
  set_wc(1,5);
  set_large_wc(1,6);
  set_hit((:TO,"hit_me":));
  set_size(1);
  set_weight(5);
  chips = random(200);
}

int hit_me(object targ){
  int i;
  object ob;
  
  if((random(10) < 4 && !interactive(ETO)) || random(10) < 2){
    tell_room(environment(targ),"A small chip flakes off the dagger into the wound.");
    targ->do_damage("torso",roll_dice(2,3));
    ob = new(OBJ+"stonechip");

    ob->move(targ);
    ob->hurt(targ);
  }
  return 0;
}
