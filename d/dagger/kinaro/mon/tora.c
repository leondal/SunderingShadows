#include <std.h>

inherit MONSTER;
create(){
    ::create();
    set_name("tora");
    set_id(( {"guard", "dwarf", "dwarven guard"}));
      set_short("%^BOLD%^%^BLACK%^S%^CYAN%^e%^BLACK%^rg%^CYAN%^e%^BLACK%^ant of the %^WHITE%^guard%^BLACK%^,"
			    " %^RESET%^%^ORANGE%^Tora Longhammer%^WHITE%^");
      set_long("%^ORANGE%^This fr%^RED%^e%^ORANGE%^ckl%^RED%^e%^ORANGE%^d, %^RED%^r%^BOLD%^e%^RESET%^%^RED%^"
			   "d-h%^BOLD%^e%^RESET%^%^RED%^ad%^BOLD%^e%^RESET%^%^RED%^d %^BOLD%^%^BLACK%^dwarfess %^RESET%^"
			   "%^ORANGE%^is the %^CYAN%^granddaughter %^ORANGE%^of %^BOLD%^%^RED%^watch captain %^RESET%^Ko"
			   "rthak Longhammer%^ORANGE%^. A one-time %^BOLD%^%^CYAN%^adventurer%^RESET%^%^ORANGE%^, she ha"
			   "s a reputation for being a %^BOLD%^%^RED%^hothead %^RESET%^%^ORANGE%^with a bit of a %^BOLD%"
			   "^%^CYAN%^vigilante %^RESET%^%^ORANGE%^streak. Despite her %^BOLD%^%^MAGENTA%^youth%^RESET%^%"
			   "^ORANGE%^, she is %^CYAN%^admired %^ORANGE%^and %^BOLD%^%^WHITE%^respected %^RESET%^%^ORANGE"
			   "%^both for her prowess in %^BOLD%^%^RED%^battle %^RESET%^%^ORANGE%^and her sharp %^WHITE%^to"
			   "ngue%^ORANGE%^.%^WHITE%^");
      set_gender("female");
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
	  set_diety("grumbar");
      add_money("gold", 1000 + random(1000));
      new("/d/dagger/kinaro/obj/cryssword.c")->move(TO);
      present("sword",TO)->set_property("monsterweapon",1);
      new("/d/dagger/kinaro/obj/silvchain.c")->move(TO);
      present("chain",TO)->set_property("monsterweapon",1);
      command("wield sword in right hand");
      command("wear chain");
  }
