#include <std.h>
#include "../inherit/ruins.h"
inherit WEAPONLESS;

object ob;

create() {
   ::create();
   set_name("goblin");
   set_id(({ "goblin","goblinoid","filthy goblin","goblin2"}));
   set_short("%^RESET%^%^GREEN%^dirty goblin%^RESET%^");
   set_wimpy(10);
   set_property("swarm",1);
   set_long("%^GREEN%^This spindly-limbed creature is constantly in motion.  Its skin is a sickly "
"%^ORANGE%^yellow%^GREEN%^ shade, with matted %^BLACK%^%^BOLD%^black%^RESET%^%^GREEN%^ hair and pointy "
"ears.  Bright %^RED%^%^BOLD%^red%^RESET%^%^GREEN%^ eyes peer out from a brutish face with a flat nose, "
"and a wide mouth of small, sharp %^YELLOW%^yellowed%^RESET%^%^GREEN%^ teeth.  The creature is clad in "
"rags and looks absolutely filthy, and has a nasty-looking sharp stone in one hand.%^RESET%^");
   set_hd(10,8);
   set_class("thief");
   set_mlevel("thief",16);
   set_guild_level("thief",16);
   add_search_path("/cmds/thief");
   set_thief_skill("hide in shadows",95);
   set_thief_skill("move silently",95);
   set_body_type("human");
   set_stats("intelligence",11);
   set_stats("wisdom",8);
   set_stats("strength",14);
   set_stats("charisma",4);
   set_stats("dexterity",17);
   set_stats("constitution",13);
   set_alignment(9);
   set_race("goblin");
   set_gender("male");
   set_size(1);
   set_exp(1200);
   set_overall_ac(1);
   set_max_hp(random(50)+50);
   set_hp(query_max_hp());
   set_property("full attacks",1);
   add_money("silver",random(100)+15);
   add_money("copper",random(1000)+50);
   command("speak goblin");
   set_funcs(({"stones"}));
   set_func_chance(10);
   set("aggressive","agg_fun");
   set_emotes(1, ({"The goblin picks at his ear.",
"The goblin grabs a bug from the ground and pops it in his mouth.",
"The goblin peers around curiously."}), 0);
   set_achats(2, ({"The little goblin scampers around you, trying to get a better position.",
"The goblin giggles madly and slashes at you again.",
"The goblin takes a swipe at you with a sharp stone."}) );
   set_nogo(({ROOM+"b1-3",ROOM+"u1-3",ROOM+"entry",ROOM+"inner1"}));
   ob = new(OBJ+"gobstone");
   ob->move(TO);
   ob->set_property("monsterweapon", 1);
   command("wield stone");
   if(random(3)) { set_scrambling(1); }
}

int agg_fun() {
   if (!TP->query_invis()) {
     if(sizeof(TO->query_attackers()) < 1) {
       force_me("emoteat "+TPQN+ " eyes $N with a malicious grin.");
       force_me("speech screeche");
       force_me("say Food! Me kill, me kill!");
     }
     if (random(2)) { call_out("force_me",0,"stab "+TPQN+ ""); }
   }
}

void stones(object target) {
   tell_room(ETO,"The goblin hisses and grabs at a few loose pebbles on the ground.");
   tell_room(ETO,"The goblin throws the handful of stones at "+target->query_cap_name()+"!",target);
   tell_object(target, "The goblin throws the handful of stones at you!  They are more painful than they look!");
   target->do_damage("torso",roll_dice(1,10));
}