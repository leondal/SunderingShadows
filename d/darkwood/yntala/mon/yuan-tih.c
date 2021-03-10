#include <std.h>
#include "../yntala.h"
inherit MONSTER;

   void create (){
   object ob;
   ::create ();
      set_name("Yuan-ti Halfblood");
      set_id(({"yuan-ti","Yuan-TI","Yuan-ti","yuan-ti halfblood","halfblood","yuan ti","Yuan TI","yuan TI","Yuan Ti"}));
      set_short("A scaly Yuan-ti");
      set_long("%^RESET%^This human-like creature is much like its pureblood counterparts with the exception that its head resembles that of a snake, complete with long fangs, forked tongue and dark, slanted eyes.  It is slightly thinner than the other yuan-ti and its hands, arms, legs and body are covered in gleaming scales that mimic the look of a diamondback rattlesnake.");
      set_race("yuan-ti");
      set_gender("female");
      set_body_type("human");
      set_overall_ac(-3);
      set_size(2);
      set_hd(12,2);
      set_stats("intelligence",18);
      set_stats("strength",15);
      set_stats("wisdom",18);
      set_stats("dexterity",13);
      set_stats("constitution",13);
      set_stats("charisma",16);
      set_money("gold",random(300)+121);
      set_money("silver",random(100)+23);
      set_money("copper",random(50)+175);
      set_money("electrum",random(75)+50);
      set_class("ranger");
      set_moving(1);
      set_speed(12);
      set_nogo(({"/d/darkwood/yntala/rooms/forestpath"}));
      set_exp(2000);
      set_hp(random(150)+100);
      set_max_hp(query_hp());
      set_alignment(9);
      set_property("full attacks",1);
      set_mlevel("ranger",12);
      set_max_level(13);
      set_func_chance(25);
      set_funcs(({"bite","whirlit"}));
	  set_monster_feats(({
      "ambidexterity",
	  "two weapon fighting",
	  "improved two weapon fighting",
	  "unassailable parry",
	  "whirl"
   }));
      set_achats(10, ({"%^GREEN%^A cobra like hood fans out behind the Yuan-ti's head as it gets ready to attack you!%^RESET%^",
         "%^BLUE%^The Yuan-ti %^BOLD%^%^BLACK%^hisses %^RESET%^%^BLUE%^as it snaps the %^GREEN%^whip %^BLUE%^at you.%^RESET%^",
         "%^RESET%^%^GREEN%^The Yuan-ti's eyes %^YELLOW%^glow %^RESET%^%^GREEN%^as it moves in for the kill.%^RESET%^"}) );
     set_emotes(1, ({"%^GREEN%^The Yuan-ti flicks its forked tongue as it warily watches the surrounding forest.%^RESET%^",
         "%^RED%^The Yuan-ti idly strokes its whip as its snake-like eyes scan the area for a victim.%^RESET%^",
         "%^GREEN%^The Yuan-ti's unblinking %^YELLOW%^eyes %^RESET%^%^GREEN%^sweep across its surroundings.%^RESET%^",
         "With a snap of its %^GREEN%^whip, %^RESET%^The Yuan-ti sends a %^ORANGE%^squirrel %^RESET%^running for cover!",
         "%^BOLD%^%^BLACK%^The Yuan-ti chuckles quietly as it snaps its %^GREEN%^w%^RESET%^%^GREEN%^h%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^p %^BOLD%^%^BLACK%^at a nearby %^RESET%^%^GREEN%^bush, %^BOLD%^%^BLACK%^scattering the %^RESET%^%^ORANGE%^wildlife %^BOLD%^%^BLACK%^hiding there.%^RESET%^"}), 0);
      new(OBJD+"vinewhip.c")->move(TO);
      command("wield vinewhip");
      ob = new(OBJD+"vinewhip.c");
      ob->move(TO);
      if(!random(3)) ob->set_property("monsterweapon",1);
      command("wield vinewhip");
      if(!random(2)){
      new(OBJD+"snakearmband.c")->move(TO);
      command("wear armband");
      }
    if(!random(10)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("reptile scales");
      ob->move(TO);
    }
}
void bite(object target){
   tell_room(ETO,"%^RESET%^%^GREEN%^The Yuan-ti sinks its %^RESET%^fangs %^GREEN%^deep into "+target->query_cap_name()+"'s neck.",target);
   tell_object(target, "%^RESET%^%^GREEN%^The Yuan-ti lunges forward and sinks its %^RESET%^fangs %^GREEN%^deep into your neck!");
   target->do_damage("torso",roll_dice(2,6));
   target->add_poisoning(15);
}

void whirlit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("whirl "+targ->query_name());
}
