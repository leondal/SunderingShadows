#include <std.h>
#include <move.h>
#include "../defs.h"
inherit NPC;

void create() {
   ::create();
   set_name("Ilmayne");
   set_id(({"ilmayne","Ilmayne","sculptor","arcane sculptor","drow","mage"}));
   set_short("%^RESET%^%^BLUE%^Ilmayne Ghorred'Malac, arcane sculptor%^RESET%^");
   set_long("%^BLUE%^Ilmayne is a drow of slender build and %^RED%^pr%^MAGENTA%^ou%^RED%^d %^BLUE%^bearing, "
"possessed of the fine features hallmark to drowkind.  Her nobility is more than apparent, given her regal "
"manner and expensive clothes, and her clear distain for any that dare address her.  Her sharp %^BOLD%^"
"%^CYAN%^i%^BLUE%^c%^CYAN%^e-b%^BLUE%^l%^CYAN%^ue %^RESET%^%^BLUE%^eyes scrutinize each visitor, as if measuring "
"up their right to approach.  A house insignia is one of many jewelry pieces that adorn her deft hands, %^BOLD%^"
"%^WHITE%^sp%^RESET%^ar%^BOLD%^%^WHITE%^kl%^YELLOW%^i%^BOLD%^%^WHITE%^ng %^RESET%^%^BLUE%^as she moves with "
"practiced precision to shape another sculpture.  She may <carve> one for you, if you ask.%^RESET%^");
   set_gender("female");
   set_race("drow");
   set_body_type("human");
   set("aggressive",0);
   set_hd(18,2);
   set_level(22);
   set_class("mage");
   set_mlevel("mage",22);
   set_guild_level("mage",22);
   set_alignment(9);
   add_money("gold", random(500));
   set_mob_magic_resistance("average");
   set_overall_ac(-10);
   set_stats("strength",18);
   set_stats("intelligence",18);
   set_max_hp(200+random(50));
   set_hp(query_max_hp());
   set_exp(300);
   set_spell_chance(95);
   set_spells(({"acid orb", "acid orb", "hold person", "powerword stun", "acid breath", "acid breath", "static field", "monster summoning vi", "greater dispel magic" }));
   set_property("no bow",1);
   force_me("speak wizish");
   force_me("speech voice in a low hiss");
}

void init(){
   ::init();
   add_action("carve","carve");
}

int carve(){
   object ob;
   command("emote smiles darkly.");
   command("say Of course, of course.  Let us see what can be done.");
   command("emote draws forth a block of obsidian, and considers you at length.");
   if(!TP->is_class("mage") && !TP->is_class("sorcerer") && !avatarp(TP)){
      command("emote 's frosty eyes narrow as she realises you are not a true arcanist!");
      command("say I would hardly waste my time on you!");
      return 1;
   }
   if(!TP->query_funds("gold",2000))  {
      command("emote scowls and turns away.");
      command("say You have not even sufficient coin to pay me. Do not waste my time.");
      command("emote sets the carving block away again.");
      return 1;
   }
   TP->use_funds("gold",2000);
   command("emote draws her knife in slow, precise patterns across the stone as she murmurs spellcraft, drawing clear shape from the formless block.");
   ob = new(OBJ"statue");
   ob->set_weight(0);
   ob->move(TP);
   ob->move(TO);
   ob->set_weight(10);
   if(ob->move(TP) != MOVE_OK){
      force_me("say You cannot carry this. Take it when you are ready.");
      force_me("drop statue");
   }else{
      force_me("say It is done!");
      command("give statue to "+TPQN+"");
   }
   return 1;
}