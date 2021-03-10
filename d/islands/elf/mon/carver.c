#include <std.h>
#include <move.h>

inherit MONSTER;

void create(){
   ::create();
   set_name("moonstone carver");
   set_short("An elven moonstone carver");
   set_id(({"carver","moonstone carver","elf","elven carver"}));
   set_long("This elf wears a simple red and gold robe.  "+
   "He seems not quite as regal as the other gold elves "+
   "but his eyes shine with years of experience.  The elf"+
   " has neatly cropped blonde hair and matching gold eyes."+
   "  In his hands he carries a block of moonstone ore and "+
   "a strange looking knife.  This man might <carve> a statue"+
   " in your likeness for some change.");
   set_race("elf");
   set_hd(1,1);
   set_base_damage_type("bludgeoning");
}

void init(){
   ::init();
   add_action("carve","carve");
}

int carve(){
   object ob;
   command("speak elven");
   command("smile "+TPQN+"");
   command("say The weave lives within the people.");
   command("emote draws forth a block of moonstone and then waits.");
   if(!TP->is_class("mage") && !TP->is_class("bard") 
   && !TP->is_class("sorcerer") && !avatarp(TP)){
      command("emote gasps when he sees you are not a mage!");
      command("say You will never get one of these!");
      return 1;

    }
   if(!TP->query_funds("gold",3000))  {
      command("gasp");
      command("say You lack the funds to pay me. You are nothing.");
      command("emote hides the moonstone away.");
      return 1;
   }
   TP->use_funds("gold",3000);
   command("emote draws his knife across the moonstone in a magical motion.");
   ob = new("/d/magic/obj/statue");
   ob->set_short("block of moonstone");

   ob->set_weight(0);
   ob->move(TO);
   ob->set_long("%^BOLD%^This is a small statue of %^RESET%^%^CYAN%^moonstone%^BOLD%^%^WHITE%^, carved in the"+
   " likeness of a particular "+TP->query_race()+".");
   if(ob->move(TP) != MOVE_OK){
      force_me("say Hmm...it seems you cannot carry this, so I "+
         "will leave it here for you.");
      ob->move(ETO);
   }else{
      force_me("say There you are!");
      command("give statue to "+TPQN+"");
   }
   return 1;

}