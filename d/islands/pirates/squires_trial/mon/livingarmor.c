#include <std.h>
#include "../squires_trial.h"

inherit MONSTER;
void create(){
  object falconsword;
  ::create();
  set_name("Living Armor");
  set_short("%^BOLD%^%^WHITE%^Living Armor%^BOLD%^%^RED%^");
  set_long(
      "%^BOLD%^%^WHITE%^" +
      "This shining suit of armor is immaculately polished.  Consisting of " +
      "a heavy breastplate, helm, shoulders, armguards and gauntlets, " +
      "this impressive sight seems to hover and exist by means of a strange " +
      "%^BOLD%^%^BLUE%^blu%^CYAN%^e gl%^BLUE%^ow%^WHITE%^.  " +
      "The helm glows from within, but less brightly than the chestpiece.  " +
      "Grasped in one gauntlet is the hilt of a massive sword which " +
      "lays across the other gauntlet, as if waiting."
      
  ); 
  set_id( ({"armor","living armor","animated armor"}) );
  set_race("armor");
  set_body_type("human");
  set_gender("neuter");
  set_size(3);
  set_hd(20,10);
  set_alignment(5);
  set_stats("strength",20);
  set_stats("dexterity",14);
  set_stats("constitution",18);
  set_stats("intelligence",6);
  set_stats("wisdom",10);
  set_stats("charisma",10);
  set_class("fighter");
  set_mlevel("fighter",20);
  set_max_level(25);
  set_guild_level("fighter",20);
  set_property("full attacks",1);
  set_property("no tripped",1);
  set_property("no paralyze",1);
  set_hp(450 + random(51));
//  set_exp(15000);
  set_new_exp(20, "high");
  set_overall_ac(-4);
  set_funcs(({"maim_it"}));
  set_func_chance(40);
  set_monster_feats(({"parry","powerattack","shatter","sunder","rush"}));
  falconsword = new(SQUIREITEMS + "falcon_sword.c");
  if(objectp(falconsword)){
    falconsword->move(TO);
    falconsword->set_property("monsterweapon",1);
    command("wield sword");
  }
}

void maim_it(object targ) {
  command("yell %^BOLD%^%^RED%^A true warrior must withstand pain!%^RESET%^");
  tell_room(environment(targ),"%^BOLD%^%^RED%^As the armor's sword catches in " + targ->QCN + "'s flesh" +
    ", the armor gives a mighty heave, impaling and shearing!%^RESET%^%^WHITE%^",targ);
  tell_object(targ,"%^BOLD%^%^RED%^As the armor's sword catches in your flesh" +
    ", the armor gives a mighty heave, impaling and shearing!%^RESET%^%^WHITE%^");
  targ->do_damage("torso",random(60) + 60); 
}

void die(object ob){
  object room;
  object item;
  tell_room(ETO,"%^BOLD%^%^WHITE%^The plate suddenly jerks around " +
        "violently, and then tongues of %^BOLD%^%^BLUE%^blue energy" +
        " %^WHITE%^streak off in all directions before disappearing!");

  item = new(SQUIREITEMS + "polished_plate");
  if(objectp(item)) item->move(ETO);
  item = new(SQUIREITEMS + "falcon_sword");
  if(objectp(item)) item->move(ETO);
  
  if(objectp(ETO)) ETO->set_spawn_elemental();
  
  TO->move("/d/shadowgate/void");
  ::die(ob);
}
