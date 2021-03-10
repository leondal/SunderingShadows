// updated to inherit the /d/common file but at a glance I think it really needs some other fixes, last change was 10/00 *Styx* 8/20/05

#include <std.h>

int num;

//inherit "/std/weapon";
inherit "/d/common/obj/weapon/scourge.c";

create() {
    ::create();
   set_id(({ "whip", "serpent whip"}));
   set_name("whip");
   set_short("Serpent whip");
   set_long("This is no ordinary whip, for it has at its end five snake "
        "heads moving about....  It looks like a well-timed and executed "
	"flick of the wrist would <crack> it quite effectively, perhaps "
	"even doing some damage at a target."
   );
   set_value(30);
  num = 0;
/*  these should come from /d/common now
   set_weight(2);
   set_size(2);
   set_cointype("silver");
   set_wc(1,2);
   set_large_wc(1,1);
   set_type("bludgeoning");
   set_prof_type("whip");
*/
}

void init() {
  ::init();
  add_action("crack_it","crack");
}

int crack_it(string str) {
  string tplayer;
  object targ;
  int need, tac, tlevel, roll;
  if(!str) {
    tell_room(ETP, "%^GREEN%^"+TPQCN+" whips the whip around creating a large CRACK!",TP);
    tell_object(TP,"%^GREEN%^You whip the whip around creating a large CRACK!");
    return 1;
  }
  targ = present(str, environment(this_player()));
    tplayer = ETO->QCN;
   if(!query_wielded()) {
    write("You must first have the whip wielded before you can use it!");
    return 1;
  }
  if(!targ) {
      tell_room(ETP, "%^GREEN%^"+tplayer+" does a wonderful display with the whip, making a loud CRACK!",TP);
    tell_object(TP,"%^GREEN%^You perform a wonderful display with the whip, making a loud CRACK!");
    return 1;
  }
  if(member_array(this_player(), targ->query_attackers()) == -1) {
    write("You can only target someone if you are already in battle!");
    return 1;
  }
  if(num == 1) {
    tell_object(this_player(), "%^GREEN%^You are recovering from your last attack with this whip!");
    return 1;
  }
   tlevel = ETO->query_level();
  roll = roll_dice(1,20);
   need = "/daemon/bonus_d.c"->thaco(tlevel, ETO->query_class());
  tac = targ->query_ac();
  if(!((roll >= (need - tac)) || (roll == 20))) {
    tell_room(environment(targ), "%^RED%^"+tplayer+" cracks the whip upon "+targ->QCN+" but does no damage!",({targ,ETO}));
    tell_object(ETO,"%^RED%^You crack the whip upon "+targ->QCN+" but do no damage!");
    tell_object(targ,"%^RED%^"+tplayer+" cracks the whip upon you but does no damage!");
    return 1;
  }
    tell_room(environment(targ), "%^GREEN%^"+tplayer+" cracks the whip upon "+targ->QCN+"'s chest inflicting some damage!",({ETO,targ}));
    tell_object(ETO,"%^GREEN%^You crack the whip upon "+targ->QCN+"'s chest inflicting some damage!");
    tell_object(targ,"%^GREEN%^"+tplayer+" cracks the whip upon your chest inflicting some damage!");
  targ->do_damage("torso", roll_dice(2,6));
  num = 1;
  call_out("next_hit",40);
  return 1;
}

void next_hit() {
  if(!objectp(TO))
	return;
  num = 0;
  tell_object(ETO, "%^GREEN%^The whip pulsates within your hand, waiting for the next strike.");
//  bug fix above, was - tell_object(this_player(), "%^GREEN%^The whip pulsates within your hand, waiting for the next strike.");
}
