#include <std.h>
inherit MONSTER;
create(){
    ::create();
    set_name("kort");
    set_id(( {"kort","guard", "dwarf", "watch captain","captain","korthak"}));
      set_short("%^BOLD%^%^BLACK%^W%^RESET%^a%^BOLD%^%^BLACK%^tch %^RED%^C%^RESET%^"
				"a%^BOLD%^%^RED%^ptain%^RESET%^, %^ORANGE%^Korthak");
      set_long("%^ORANGE%^This %^WHITE%^broad-chested %^BOLD%^%^RED%^dwarf soldier"
			   " %^RESET%^%^ORANGE%^is a g%^WHITE%^r%^ORANGE%^e%^WHITE%^y%^ORANGE%"
			   "^-b%^WHITE%^e%^ORANGE%^ar%^WHITE%^d%^ORANGE%^e%^WHITE%^d %^ORANGE%"
			   "^v%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^e%^RESET%"
			   "^%^ORANGE%^r%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^n of many %^BOLD%"
			   "^%^RED%^campaigns%^RESET%^%^ORANGE%^. He is the %^BOLD%^%^WHITE%^l"
			   "eader %^RESET%^%^ORANGE%^of Kinaro's town %^BOLD%^%^RED%^guard %^R"
			   "ESET%^%^ORANGE%^and a %^BOLD%^%^CYAN%^respected %^RESET%^%^ORANGE%"
			   "^member of the dw%^RED%^a%^ORANGE%^rv%^RED%^e%^ORANGE%^n community."
			   " The recent periods of %^CYAN%^instability %^ORANGE%^has proven pro"
			   "ven his %^BOLD%^%^CYAN%^competence %^RESET%^%^ORANGE%^time and again."
			   " %^BOLD%^%^BLACK%^Korthak %^RESET%^%^ORANGE%^led several successful"
			   " %^BOLD%^%^CYAN%^expeditions %^RESET%^%^ORANGE%^against %^GREEN%^or"
			   "cs %^ORANGE%^and %^GREEN%^goblins %^ORANGE%^early in his career and"
			   " earned his current position based on his skill as a %^BOLD%^%^RED%"
			   "^battlefield %^BLACK%^commander%^RESET%^");
      set_gender("male");
      set("race", "dwarf");
      set_body_type("human");
      set_hd(19,1);
      set_exp(900);
      set_overall_ac( 0 );
      set_wielding_limbs( ({ "right hand", "left hand" }) );
      set_max_hp(170);
      set_hp(170);
      set_hp(225);
      set_stats("strength", 25);
      set_stats("dexterity", 20);
      set_stats("constitution", 25);
      set_stats("intelligence", 15);
      set_stats("wisdom", 18);
      set_stats("charisma", 16);
      set_class("fighter");
      set("aggressive", 0);
      set_alignment(1);
	  set_diety("tempus");
      add_money("gold", 1000 + random(1000));
      new("/d/dagger/kinaro/obj/cryssword.c")->move(TO);
      present("sword",TO)->set_property("monsterweapon",1);
      new("/d/dagger/kinaro/obj/silvchain.c")->move(TO);
      present("chain",TO)->set_property("monsterweapon",1);
      command("wield sword in right hand");
      command("wear chain");
  }
