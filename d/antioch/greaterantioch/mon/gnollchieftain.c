#include <std.h>
#include "../gantioch.h"

inherit MONSTER;
object ob;

void create() {
   ::create();
   set_name("Gnoll Chieftain");
   set_id(({"gnoll","chieftain","gnoll chieftain","hellfang","Hellfang"}));
   set_short("%^BOLD%^%^WHITE%^Hellfang, %^BOLD%^%^RED%^Chieftain of the %^BOLD%^%^WHITE%^Elberan %^BOLD%^%^RED%^Gnolls%^RESET%^");
   set_long("%^RESET%^This is a massive, heavily haired and angry gnoll. It stands"+
              " over seven feet in height and looks around hungrily. The creature is"+
              " gripping a massive %^BOLD%^%^YELLOW%^axe %^RESET%^and seems ready"+
			  " for battle. The gnoll is adorned with furs and leather armors, painted"+
			  " with some sort of %^RESET%^%^BLUE%^tribal paint %^RESET%^which adds to its"+
			  " feracity. This creature is adorned with many items and seems to hold a lot of"+
			  " respect amongst the others. It is likely a leader of this clan. It's %^BOLD%^%^RED%^red eyes %^RESET%^glare at you, and you are"+
			  " sure there is no parlaying with this beast!");
   set_class("fighter");
   set_guild_level("fighter",20);
   set_race("gnoll");
   set_body_type("humanoid");
   set_property("no bows",1);
   set_gender("male");
   set_hd(20,10);
   set_alignment(6);
   set_max_hp(550);
   set_hp(550);
   set_overall_ac(-2);
   set_size(3);
   set("aggressive",26);
   set_exp(25000);
   ob = new(OBJ+"chieftainaxe");
   set_max_level(12);
   set_wielding_limbs(({"right hand","left hand"}));
   if(random(1)) ob->set_property("monsterweapon", 1);
   ob->move(TO);
   command("wield axe");
   set_property("full attacks",4);
   set_stats("strength",20);
   set_stats("constitution",20);
   set_stats("intelligence",14);
   set_stats("wisdom",12);
   set_stats("charisma",12);
   set_stats("dexterity",15);
   set_func_chance(45);
   set_funcs( ({ "flashit","rushit","rushit"}) );
   add_search_path("/cmds/fighter");
   set_monster_feats(({
      "parry",
	  "powerattack",
	  "shatter",
	  "sunder",
	  "rush"
   }));
   if(!present("gnollkey",TO)) new(OBJ+"gnollkey")->move(TO);
}

void rushit(object targ) {
   TO->force_me("rush "+targ->query_name());
}

void flashit(object targ) {
   TO->force_me("flash "+targ->query_name());
}
void reset(){
    ::reset();
    if(!present("gnollkey",TO))
    new(OBJ+"gnollkey")->move(TO);
}

void die(object ob){
object oba;
oba = new(MON"younggnoll");
oba->move(ETO);
oba = new(MON"younggnoll");
oba->move(ETO);
oba = new(MON"younggnoll");
oba->move(ETO);
oba = new(MON"younggnoll");
oba->move(ETO);
oba = new(MON"younggnoll");
oba->move(ETO);
oba = new(MON"younggnoll");
oba->move(ETO);
oba = new(MON"younggnoll");
oba->move(ETO);
oba = new(MON"younggnoll");
oba->move(ETO);
oba = new(MON"younggnoll");
oba->move(ETO);
oba = new(MON"younggnoll");
oba->move(ETO);
oba = new(MON"younggnoll");
oba->move(ETO);
tell_room(ETO,"%^BOLD%^%^WHITE%^As the massive gnoll falls to the ground, the %^BOLD%^%^RED%^gnolls %^BOLD%^%^WHITE%^rise up out of their seats and rush the arena!%^RESET%^");
   ::die(TO);
}
