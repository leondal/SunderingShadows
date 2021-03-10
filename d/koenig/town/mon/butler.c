#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_name("butler");
  set_id( ({"butler", "lurch"}) );
  set_short("%^BOLD%^%^BLACK%^Lurch, the Tower Butler%^RESET%^");
   set_long("%^RESET%^Lurch stands 8-feet tall, and looks like a %^BOLD%^%^BLACK%^corpse%^RESET%^ that's been laid out for viewing, except for the fact that he's breathing. And looking pretty unhappy to see you. He has shaggy %^BOLD%^%^BLACK%^dark hair%^RESET%^ and his %^BOLD%^%^BLACK%^black eyes%^RESET%^ remind you of a void. He is dressed in the finest butler attire and stands as still as a statue. You notice he has a %^BOLD%^%^BLACK%^black rose%^RESET%^ in his lapel.");
  set_race("giant");
  set_gender("male");
  set_new_exp(12, "boss");
  set_body_type("human");
  set_hd(15,5);
  set_max_hp(125);
  set_hp(125);
  set_stats("strength", 20);
  set_stats("constitution", 18);
  set_stats("dexterity", 14);
  set_stats("wisdom", 12);
  set_stats("intelligence", 9);
  set_stats("charisma", 5);
  set_overall_ac(4);
  set_size(3);
  set_wielding_limbs( ({"left hand", "right hand"}) );
  set_class("fighter");
  set_guild_level("fighter", 15);
  
  set_emotes(5, ({"The butler has a very disapproving look on his face, it makes you wonder if the maid has been through here.",
  "The butler straightens his attire.",
  "The butler bows his head to smell his black rose...",
  "The butler looks off towards the outdoors with a puzzled look on his face.",
  "The butler looks over at you and raises an eyebrow...",
  "The butler looks at the tapestry here and a slight smile crosses his lips.",
  "The butler stands motionless..."}), 0);
  set_funcs( ({"embrace", "crush", "toss"}) );
  set_func_chance(50);
}
void embrace(object targ)
{
  if(!targ) return 0;
  tell_room(environment(targ),"Lurch embraces "+targ->query_cap_name()+" and begins to SQUEEZE!", targ);
   targ->do_damage("torso", random(20)+5);
  tell_object(targ,"%^BOLD%^%^RED%^Lurch embraces you with his huge arms and begins to %^RESET%^%^RED%^SQUEEZE%^BOLD%^%^RED%^. You can fill some ribs begin to give!%^RESET%^");
  return 1;
}
void crush(object targ)
{
  if(!targ) return 0;
  tell_room(environment(targ),"Lurch puts his hands together and swings a crushing blow into "+targ->query_cap_name()+"'s body!", targ);
    targ->do_damage("torso", random(10)+5);
  tell_object(targ,"%^BOLD%^%^RED%^Lurch puts his hands together and swings a crushing blow into your body...OOOOF that hurts!");
  return 1;
}
void toss(object targ)
{
  if(!targ) return 0;
  tell_room(environment(targ),"Lurch grabs hold of "+targ->query_cap_name()+" and lifts them above his head then tosses them like a rag doll across the large room!", targ);
  targ->move_player("/d/koenig/town/tower14.c");
    targ->do_damage("torso", random(20)+10);
  tell_object(targ,"%^BOLD%^%^RED%^Lurch picks you up above his head and throws you across the room like a rag doll! You smash into the wall!");
  return 1;
}
