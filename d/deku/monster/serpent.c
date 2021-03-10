#include <std.h>
inherit WEAPONLESS;

void create() {
   ::create();
   set_name("giant serpent");
   set_short("A giant black serpent");
   set_id(({"serpent","black serpent","giant serpent","giant black serpent","snake"}));
   set_long("The giant serpent is rather daunting to look at. It seems"+
   " to take up almost the entire room! Its scales are thick and black"+
   " and look as though they would protect the monster well. Red eyes"+
   " stare out of its lidless sockets, and a black tongue darts out"+
   " between its giant ivory fangs.");
   set_race("serpent");
   set_gender("neuter");
   set_level(10);
   set_hd(15,3);
   set_size(3);
   set("aggressive",18);
   set_max_hp(150 + random(25));
   set_hp(query_max_hp());
   set_exp(2500);
   set_max_level(12);
   set_alignment(9);
   set_overall_ac(2);
   set_body_type("snake");
   set_attack_limbs(({"mouth"}));
   set_attacks_num(2);
   set_base_damage_type("slashing");
   set_damage(2,3);
   set_stats("strength",18);
   set_funcs(({"squeeze"}));
   set_func_chance(10);
}

void init() {
   ::init();
   if(avatarp(TP) && TP->query_invis()) return;
   if(wizardp(TP)) return;
   else if(TP->query_invis()) {
      tell_object(TP,"The serpent flicks its tongue out and senses your"+
      " presence!");
      force_me("kill "+TP->query_name()+"");
   }
}

void squeeze(object targ)
{
   if((random(20)+1) > targ->query_stats("dexterity")) {
      tell_object(targ,"%^GREEN%^The serpent wraps you in its giant"+
      " coils and SQUEEZES!");
      tell_room(ETO,"%^GREEN%^The serpent wraps "+targ->query_cap_name()+""+
      " in its giant coils and SQUEEZES!",targ);
      targ->do_damage("torso",roll_dice(2,6));
      targ->set_tripped(2,"You're still getting your breath back!");
      return 1;
   }
   tell_object(targ,"%^BOLD%^%^GREEN%^The serpent attempts to wrap"+
   " you in its giant coils, but you manage to get away!");
   tell_room(ETO,"%^BOLD%^%^GREEN%^The serpent attempts to wrap "+targ->query_cap_name()+""+
   " in its giant coils, but "+targ->query_subjective()+" gets away!",targ);
   return 1;
}

void die(object ob) {
   object obj, money;
   tell_room(ETO,"%^BLUE%^The serpent shudders as it dies, its coils"+
   " collapsing to the ground.");
   tell_room(ETO,"A treasure chest that was hidden in the coils is revealed.");
   obj = new("/d/common/obj/misc/lkchest");
   obj->move(ETO);
   obj->set_key("chestkey");
   obj->set_short("A large treasure chest");
   obj->set_long("This is a large, rectangular treasure chest with a"+
   " sturdy looking lock.\nIt is closed.");
   obj->set_open_long("This is a large, rectangular treasure chest with a"+
   " sturdy looking lock.\nIt is open.");
   obj->set_closed_long("This is a large, rectangular treasure chest with"+
   " a sturdy looking lock.\nIt is closed.");
   obj->set_name("treasure chest");
   obj->set_id(({"chest","treasure chest","large chest","large treasure chest"}));
   obj->set_weight(2000);
   money = new("/std/obj/coins");
   money->set_money("gold",random(500)+50);
   money->set_money("electrum",random(500)+10);
   money->set_money("copper",random(2000)+100);
   money->set_money("silver",random(300)+5);
   money->move(obj);
   switch(random(3)) {
      case 0:
         new("/d/antioch/valley/obj/gem")->move(obj);
      case 1:
         new("/d/antioch/valley/obj/gem")->move(obj);
      case 2:
         new("/d/antioch/valley/obj/gem")->move(obj);
         break;
   }
   switch(random(3)) {
      case 0:
         new("/d/newbie/obj/misc/gem")->move(obj);
      case 1:
         new("/d/newbie/obj/misc/gem")->move(obj);
      case 2:
         new("/d/newbie/obj/misc/gem")->move(obj);
         break;
   }
   obj->toggle_closed();
   obj->set_lock("locked");
   obj->set_lock_difficulty(50);
   ::die(ob);
}
