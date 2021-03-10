#include <std.h>
#include "../inherit/ruins.h"
inherit WEAPONLESS;

object ob;

create() {
   ::create();
   set_name("goblin");
   set_id(({ "goblin","goblinoid","filthy goblin","goblin1"}));
   set_short("%^RESET%^%^GREEN%^filthy goblin%^RESET%^");
   set_wimpy(10);
   set_property("swarm",1);
   set_long("%^GREEN%^This spindly-limbed creature is constantly in motion.  Its skin is a sickly "
"%^ORANGE%^yellow%^GREEN%^ shade, with matted %^BLACK%^%^BOLD%^black%^RESET%^%^GREEN%^ hair and pointy "
"ears.  Bright %^RED%^%^BOLD%^red%^RESET%^%^GREEN%^ eyes peer out from a brutish face with a flat nose, "
"and a wide mouth of small, sharp %^YELLOW%^yellowed%^RESET%^%^GREEN%^ teeth.  The creature is clad in "
"rags and looks absolutely filthy, and is waving around a nasty-looking sharp stick.%^RESET%^");
   set_hd(10,10);
   set_class("fighter");
   set_mlevel("fighter",18);
   set_guild_level("fighter",18);
   add_search_path("/cmds/fighter");
   set_body_type("human");
   set_stats("intelligence",9);
   set_stats("wisdom",8);
   set_stats("strength",14);
   set_stats("charisma",4);
   set_stats("dexterity",15);
   set_stats("constitution",14);
   set_alignment(9);
   set_race("goblin");
   set_gender("male");
   set_size(1);
   set_exp(1200);
   set_overall_ac(1);
   set_max_hp(random(50)+75);
   set_hp(query_max_hp());
   set_property("full attacks",1);
   add_money("silver",random(100)+15);
   add_money("copper",random(1000)+50);
   command("speak goblin");
   set_funcs(({"stones","flashit","flashit","rushit"}));
   set_func_chance(40);
   set("aggressive","agg_fun");
   set_emotes(1, ({"The goblin chews experimentally on the end of the stick.",
"The goblin scratches around in the dirt, looking for something to eat.",
"The goblin picks at his greasy hair."}), 0);
   set_achats(2, ({"The little goblin scampers around you, trying to get a better position.",
"The goblin cackles and takes another swipe at you.",
"The goblin stabs at you with the sharp-ended stick."}) );
   set_nogo(({ROOM+"b1-3",ROOM+"u1-3",ROOM+"entry",ROOM+"inner1"}));
   ob = new(OBJ+"gobstick");
   ob->move(TO);
   ob->set_property("monsterweapon", 1);
   command("wield stick");
}

int agg_fun() {
   if (!TP->query_invis()) {
     if(sizeof(TO->query_attackers()) < 1) {
       force_me("emoteat "+TPQN+ " waves a broken stick at $N.");
       force_me("speech yell");
       force_me("say Ooh, more stuffs for killin!");
     }
     force_me("kill "+TP->query_name());
   }
}

void stones(object target) {
   tell_room(ETO,"The goblin hisses and grabs at a few loose pebbles on the ground.");
   tell_room(ETO,"The goblin throws the handful of stones at "+target->query_cap_name()+"!",target);
   tell_object(target, "The goblin throws the handful of stones at you!  They are more painful than they look!");
   target->do_damage("torso",roll_dice(1,10));
}

void flashit(object target) {
   force_me("flash "+target->query_name());
}

void rushit(object target) {
   force_me("rush "+target->query_name());
}