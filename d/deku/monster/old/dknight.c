#include <std.h>
#include <daemons.h>

inherit "/std/monster";

void create() {
  ::create();
  set_name("death knight");
  set_id(({"death knight","knight"}));
  set_race("undead");
  set_gender("male");
  set_short("Death Knight");
  set_long("The death knight is a horrifying form of lich created by\n"+
             "a demon prince from a fallen human paladin.\n");
  set_body_type("human");
  set("aggressive",30);
  set_alignment(9);
  set_hd(9,1);
  set_stats("strength",19);
  set_stats("charisma", 8);
  set_stats("dexterity",15);
  set_stats("constitution",14);
  set_stats("wisdom",13);
  set_stats("intelligence",9);
  set_hp(150);
  set_exp(2140);
  set_overall_ac(0);
  new("/d/common/obj/weapon/two_hand_sword")->move(TO);
  command("wield sword");
  new("/d/common/obj/misc/pouch")->move(TO);
  command("wear pouch");
  new("/d/deku/armours/leather")->move(TO);
  command("wear leather");
  add_money("silver",random(100));
  add_money("gold",random(20));
  set_funcs(({"point","cast"}));
  set_func_chance(20);
}

void point(object targ) {
  string dam;
// this was save_throw which wasn't even a valid function and was also TP, not targ but I guess without a valid function it didn't have a chance to bug on that *Styx*  11/16/03
  if(SAVING_D->saving_throw(targ, "spells")) {
    dam = "touches";
  } else {
    dam = "chills";
  }
  tell_object(targ, "The Death Knight "+dam+" you with his fingers.");
  tell_room(environment(targ), "The Death knight "+dam+" "+targ->QCN+" with his fingers.", targ);
  if(dam = "chills") {
    targ->add_hp(-200);
  } else {
    tell_object(targ, "You resisted the Death Knight's touch!");
  }
  return 1;
}

void cast(object targ) {
  string dam;
// this was save_throw which wasn't even a valid function and was also TP, not targ but I guess without a valid function it didn't have a chance to bug on that *Styx*  11/16/03
  if(SAVING_D->saving_throw(targ, "spells")) {
    dam = "surrounds";
  } else {
    dam = "engulfs";
  }
  tell_object(targ, "%^GREEN%^The Death Knight casts a Fireball that "+dam+" you!\n");
  tell_room(environment(targ), "%^RED%^The Death Knight casts a fireball towards "+targ->QCN+"!\n");
  if(dam = "surrounds") {
    set_property("magic",1);
    targ->do_damage("torso", roll_dice(20,6));
    remove_property("magic");
  } else {
    set_property("magic",1);
    targ->do_damage("torso", ((roll_dice(20,6))/2));
    remove_property("magic");
  }
  return 1;
}
