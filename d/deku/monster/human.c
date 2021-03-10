inherit "/std/monster";

create() {
  ::create();
  set_name("Ambassador");
  set_id(({"human","ambassador", "levec", "Levec"}));
  set_race("human");
  set_gender("male");
  set("short","Levec De'felc, human ambassador");
  set("long","This human is a tall man, standing well over 6 feet and clad "
	"in plate armor.  His shaggy brown hair is streaked with silver, "
	"revealing that he is in middle age for humans.  His pox marred face seems "
	"to speak of the many battles this man has had, or perhaps torture he "
	"endured that led to him being in the service of these drow.  Dull "
	"blue, almost lifeless, eyes gaze back at the world through thick "		"coarse brows.");
  set_level(15);
  set_body_type("human");
  set_class("fighter");
  set("aggressive",18);
  set_alignment(6);
  set_size(2);
  set_hd(14,3);
  set_wielding_limbs(({"right hand","left hand"}));
  new("/d/common/obj/weapon/two_hand_sword")->move(this_object());
  command("wield sword");
  new("/d/deku/armours/plate")->move(this_object());
  command("wear platemail");
  add_money("gold",150);
  set_hp(random(25)+113);
  set_exp(750);
  set_max_level(15);
}
