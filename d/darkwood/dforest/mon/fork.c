inherit "/std/monster";
object ob;
create()
{
  ::create();
  set_name("giant fork");
set_id(({"fork","giant fork"}));
  set_short("a Giant Fork");
  set_long("This Fork is way off his dinner table and looks very pissed off!");
  set_race("fork");
  set_gender("neuter");
  set_body_type("human");
  remove_limb("right arm");
  remove_limb("left arm");
  remove_limb("head");
  add_limb("forkhead","torso",0,0,0);
  set_hd(6,5);
  set_overall_ac(4);
  set_alignment(5);
  set_size(3);
  set_max_hp(75);
  set_hp(75);
  set_exp(650);
  set("aggressive", 18);
  add_money("gold", 100 + random(300));
  set_wielding_limbs( ({ "forkhead" }) );
new("/d/darkwood/dforest/wpns/tines.c")->move(this_object());
       command("wield tines in forkhead");
}

