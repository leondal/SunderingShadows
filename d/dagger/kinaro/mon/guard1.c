#include <std.h>

inherit MONSTER;
create(){
    ::create();
    set_name("dwarven guard");
    set_id(( {"guard", "dwarf", "dwarven guard"}));
      set_short("Dwarven Guard");
      set_long("This is one of the dwarven guards of the town of Kinaro.  Though they may be small in stature, their combat abilities are well known, and feared.");
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
      set_stats("strength", 17);
      set_stats("dexterity", 14);
      set_stats("constitution", 14);
      set_stats("intelligence", 15);
      set_stats("wisdom", 11);
      set_stats("charisma", 12);
      set_class("fighter");
      set("aggressive", 0);
      set_alignment(1);
	  set_diety("tempus");
      set_emotes(5, ({
	  "The guard says, Och!  Did ya go to the bar last night?  Oh, my aching head!",
	  "The Guard says, Welcome to Kinaro!"
	}),0);
      add_money("gold", 100 + random(1000));
      new("/d/dagger/kinaro/obj/cryssword.c")->move(TO);
      present("sword",TO)->set_property("monsterweapon",1);
      new("/d/dagger/kinaro/obj/silvchain.c")->move(TO);
      present("chain",TO)->set_property("monsterweapon",1);
      command("wield sword in right hand");
      command("wear chain");
  }
