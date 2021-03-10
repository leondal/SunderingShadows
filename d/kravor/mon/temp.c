inherit "/std/monster";
 
int eventPunch() {
  object ob;
  if(!ob = query_current_attacker()) return 0;
  message("info",
    "%^BLUE%^%^BOLD%^The bandit sends you a vicious right hook to the jaw!",
    ob);
  message("other_action",
    "%^BLUE%^%^BOLD%^The bandit sends "+
    (string)ob->query_cap_name()+" a vicious right hook!",
    environment(), ob);
  ob->cause_typed_damage(ob, "head", roll_dice(1, 10)+4, "bludgeoning");
  ob->check_on_limb("head");
  return 1;
}
 
void heart_beat() {
  if(!query_current_attacker()) return ::heart_beat();
  if(!random(10)) eventPunch();
  ::heart_beat();
}
 
void create() {
  ::create();
  set_name("bandit");
  set_id(({"bandit", "thief", "rogue"}));
  set_short("a %^RED%^blood-thirsty%^RESET%^ bandit");
  set("long", "This bandit seeems to be searching this ruins for whatever "
     "he can get his hands on.  You are sure that the dagger he wields can't "
     "possibly be his.  His %^BLACK%^BOLD%^black leather %^RESET%^%^CYAN%^armour "
     "looks like a useful piece of clothing.  Maybe he deserves the same "
     "punishment that he has given every other traveler that he has come "
     "across.");
  set_level(10);
  set("race", "halfling");
  set_gender("male");
  set_ac(10);
  set_hp(350);
  set_max_hp(400);
  set_mp(200);
  set_max_mp(250);
  set_body_type("halfling");
  set_class("thief");
  set_size(2);
  set_hd(10,1);
  new("/realms/arabesque/fdagger")->move(this_object());
  new("/realms/arabesque/barmour")->move(this_object());
  command("wear armour");
  command("wield dagger in right hand");
}
 
 
