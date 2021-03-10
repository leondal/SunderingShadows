#include <std.h>
#include "../yntala.h"

inherit MONSTER;

void create (){
object ob;

::create ();
   set_name("Yuan-ti Pureblood");
   set_id(({"yuan ti pureblood","yuan-ti","creature","Yuan-TI","Yuan-ti","pureblood"}));
   set_short("A lithe Yuan-ti");
   set_long("%^RESET%^This tall creature wears her %^BOLD%^%^BLACK%^dark hair %^RESET%^back away from her face, accentuating her high cheekbones and slanting eyes. Her form is lithe and agile, with long limbs and slight curves.  If you look closely enough, you notice that although she looks much like a female human, she has small patches of scales on her neck and forearms.");
   set_race("yuan-ti");
   set_gender("female");
   set_body_type("human");
   set_overall_ac(-3);
   set_hd(12,2);
   set_size(2);
   set_stats("intelligence",12);
   set_stats("strength",12);
   set_stats("wisdom",10);
   set_stats("dexterity",13);
   set_stats("constitution",14);
   set_stats("charisma",12);
   set_money("gold",random(90)+50);
   set_money("silver",random(100)+75);
   set_money("copper",random(50)+100);
   set_money("electrum",random(75)+45);
   set_class("ranger");
   set_hp(random(150)+100);
   set_max_hp(query_hp());
   set_exp(2500);
   set_max_level(13);
   set_moving(1);
   set_speed(12);
   set_nogo(({"/d/darkwood/yntala/rooms/forestpath"}));
   set_alignment(9);
   set_property("full attacks",1);
   set("aggressive",17);
   set_mlevel("ranger",12);
   set_func_chance(25);
   set_funcs(({"whirlit"}));
   set_achats(5, ({"%^RED%^The Yuan-ti lunges for you!%^RESET%^",
"%^BLUE%^A demonic cackle escapes the Yuan-ti's lips as it ducks down low and thrusts its %^RESET%^swords %^BLUE%^at you!%^RESET%^"}) );
   RANDGEAR->arm_me(TO,"edgeds",20,1,50);
   RANDGEAR->arm_me(TO,"edgedm",20,1,50);
      if(random(10) < 2){
      new(OBJD+"blackcloak.c")->move(TO);
      command("wear cloak");
      }
   set_monster_feats(({
      "ambidexterity",
	  "two weapon fighting",
	  "improved two weapon fighting",
	  "unassailable parry",
	  "whirl"
   }));
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("reptile scales");
      ob->move(TO);
    }
}

void whirlit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("whirl "+targ->query_name());
}
