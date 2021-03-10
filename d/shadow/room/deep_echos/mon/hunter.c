//hunter 
#include <std.h>
#include "../deep_echo.h"
inherit MONSTER;

void create()
{
  ::create();
  set_name("half-ogre");
  set_id(({"ogre","ogre hunter","half-ogre","monster","hunter"}));
  set_short("A half-ogre hunter");
  set_long("This dirty half-ogre is covered in skins."+
      "  He has matted black hair and black eyes."
      "  He has many tools for leatherworking.  From how he "+
      "carries himself, he looks to be a ranger.  He is "+
	  "very ugly and has an evil look about him.  "+
	  "He is more dangerous looking than other creatures here.");
  set_race("half-ogre");
  set_body_type("human");
  set_gender("male");
  set_size(3);
  set("aggressive",0);
  set_class("ranger");
  set_mlevel("ranger",26);
  add_search_path("/cmds/ranger");
  set_hd(22,10);
  set_level(22);
  set_hp(random(125)+500);
  set_overall_ac(2);
  set_alignment(9);
  set_stats("intelligence",5);
  set_stats("wisdom",14);
  set_stats("strength",23);
  set_stats("charisma",3);
  set_stats("dexterity", 17);
  set_stats("constitution",20);
  //set_exp(10000);
  set_new_exp(15,"boss");
  new(OBJ"acid_ax")->move(TO);
  new(OBJ"boots")->move(TO);
  command("wield axe");
  "/d/common/daemon/randgear_d"->arm_me(TO,"polearm",20,3);
  "/d/common/daemon/randgear_d"->armor_me(TO,"armorlt",20,3);
  new(OBJ"cog")->move(TO);
  command("wearall");
  set_emotes(2,({
        "%^MAGENTA%^The hunter says:%^RESET%^"+
        "  there is nothing as useful "+
        "as a sharp skinning knife.",
        "The hunter sharpens a knife on a stone.",
        "%^MAGENTA%^The hunter says:%^RESET%^ There"+
        " is nothing like a good hunt",
        "%^MAGENTA%^The hunter says:%^RESET%^  "+
        "I found some drow tracks, didn't"+
		" know they came this far out ", }),0);
  add_money("gold",random(200));
  set_property("full attacks",1);
  // had to give all these feats so he gets all his attacks
  set_monster_feats(({"light weapon","crushingstrike","blade block",
  "sweepingblow","impale",
  "two weapon fighting","ambidexterity","greater two weapon fighting",
  "two weapon defense","knockdown","exotic weapon proficiency"}));
  add_damage_bonus(6);
  set_property("damage resistance",7); //hard for melee
  set_funcs(({"kick"}));
  set_func_chance(30);
  
}
void kick(object targ)
{
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
		
   tell_object(targ,"%^ORANGE%^The hunter kicks you in the face!");
   tell_room(ETO,"%^ORANGE%^The hunter kicks"+
   " "+targ->query_cap_name()+" in the face!",targ);
   targ->cause_typed_damage(targ,0,roll_dice(3,10),"slashing");
   if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-17))
    targ->set_paralyzed(10+random(20),
     "%^MAGENTA%^Your face hurts too much!");
   return;
}
void whirl()
{
   if(random(4)==1)tell_room(ETO,"%^RED%^The hunter madly slashes out "+
   "with his huge weapons.");
   force_me("whirl");
   return 1;
}
void heart_beat(){
  object *attackers;
  int x;
  ::heart_beat();
  if(!objectp(TO))return;
 
  if(!objectp(query_current_attacker())) { return ; } 
   if(query_attackers()==({ })) return;
  attackers = query_attackers();
  x = sizeof (attackers);
  if(random(2)==0)
    force_me("knockdown "+attackers[random(x)]->query_name());
  whirl();
  return;
}


void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
   set_spoken("wizish");
   if(!msg || !objectp(who)) return;
    force_me("emote eyes you evily");
    force_me("say seen any drow around?"+
	"  I found some drow tracks but"+
	" no drow, must be lurking around somewhere.");
	force_me("emote smirks crookedly");
     return;
}

