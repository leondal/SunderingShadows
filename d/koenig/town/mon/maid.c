#include <std.h>
inherit MONSTER;

void create() {
  ::create();
  set_name("maid");
  set_id( ({"maid","maddie"}) );
  set_short("%^BOLD%^%^WHITE%^Maddie the Maid%^RESET%^");
  set_long("%^RESET%^This maid looks to be human and dressed in a very skimpy little %^BOLD%^%^BLACK%^maid "+
"uniform%^RESET%^. Her %^BOLD%^%^RED%^red wild curls%^RESET%^ fall from beneath her little maid cap and over a "+
"pair of %^BOLD%^%^GREEN%^predatory %^RESET%^%^GREEN%^green %^BOLD%^eyes%^RESET%^. You really can't tell if she is smiling at you or "+
"sneering. She wanders about the huge room getting little work done, and flirting "+
"with the %^BOLD%^%^BLACK%^golems%^RESET%^ lining the wall.");
  set_race("human");
  set_gender("female");
  set_body_type("human");
  set_alignment(6);
  set_hd(10,5);
  set_max_hp(85);
  set_hp(85);
  set_stats("strength", 12);
  set_stats("constitution", 8);
  set_stats("dexterity", 9);
  set_stats("wisdom", 6);
  set_stats("intelligence", 10);
  set_stats("charisma", 20);
  set_overall_ac(6);
  set_size(2);
  set_wielding_limbs( ({"left hand", "right hand"}) );
  set_class("bard");
  set_guild_level("bard", 10);
  set_spell_chance(30);
  set_spells( ({"charm", "detect", "rally", "steal"}) );
  set_emotes(6, ({"The maid slinks by.",
    "%^BOLD%^%^WHITE%^The maid flirts shamelessly with you.%^RESET%^",
    "%^CYAN%^The maid pulls out a mirror to admire her reflection.%^RESET%^",
    "%^BOLD%^%^WHITE%^The maid fixes her hair.%^RESET%^",
    "%^BOLD%^%^GREEN%^The maid looks you over with a predatory eye.%^RESET%^",
    "%^BOLD%^%^BLACK%^The maid gives you a wink and a come hither look.%^RESET%^"}), 0);
  set_new_exp(10, "high");
  set_funcs( ({"scratch", "bite", "whine", "backstab"}) );
  set_func_chance(60);
  set_moving(1);
  set_speed(80);
//  call_out("start_wonder",1);
}

void scratch(object targ) {
  if(!targ) return 0;
  tell_room(environment(targ),"The maid scratches "+targ->query_cap_name()+	
  	" about the face and neck with her 9-inch nails.", targ);
  targ->do_damage(targ->return_random_limb(),(6)+1);
  tell_object(targ,"The maid scratches you about your face and neck!");

  return 1;
}
void bite(object targ)
{
  if(!targ) return 0;
  tell_room(environment(targ),"The maid bites down on "
  +targ->query_cap_name()+"'s arm, drawing blood!", targ);
  targ->do_damage("arm",random(6)+1);
  tell_object(targ,"The maid grabs your arm and bites down, drawing blood!");
  return 1;
}
void backstab(object targ) {
  if(!targ) return 0;
  tell_room(environment(targ),"The maid suddenly draws a dagger and backstabs " 
  +targ->query_cap_name(), targ);
  targ->do_damage("torso",random(10)+5);
  tell_object(targ,"The maid suddenly draws a dagger in hand and backstabs you!");
  return 1;
}

void whine(object targ) {
  if(!targ) return 0;
  tell_room(environment(targ),"The maid begins to whine horribly, "
  +targ->query_cap_name()+" has become paralyzed!", targ);
  targ->do_paralyzed(random(20));
  tell_object(targ,"The maid begins to whine horribly, you feel it down to your"+
  " very marrow, YOU'RE PARALYZED!");
  return 1;
}

void move_around() {
   string *exits;
   string exit;
   if(!this_object()) return;
   if(!objectp(ETO)) return;
   ETO->setupExits();
   if(query_current_attacker()) return;
   if(environment(this_object()))
        exits = (string*)environment(this_object())->query_obvious_exits();
   else exits = 0;
   if(sizeof(exits)) {
      exit = exits[random(sizeof(exits))];
      (environment(this_object())->query_exit(exit))->init();
//**** replace this with below   if(exit != "temple")
	if(exit != "down" && exit != "up")
       force_me(exit);
   }
   moving=0;
}
