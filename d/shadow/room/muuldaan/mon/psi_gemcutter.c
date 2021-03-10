#include <std.h>
inherit MONSTER;

void create(){
   ::create();
   set_name("aged gemcutter");
   set_short("An aged gemcutter");
   set_id(({"cutter","gemcutter","aged gemcutter","man"}));
   set_long("This aged duergar is dressed in ragged robes that "+
      "hint at a long, weary life.  His salt and pepper beard "+
      "is the only hair upon him, and he bears no arms or "+
      "armors.  He wears a radiant purple crystal on a thin "+
      "chain about his head, with the gem itself resting "+
      "in the center of his forehead.  Though he carries "+
      "nothing else, it is well known that a psion might "+
      "ask him to <shape> a gem to be attuned to the "+
      "psion's image.");
   set_race("duergar");
   set_body_type("human");
   set_hd(1,1);
   set_exp(1);
//adjusted his language 7/24/19 - he used to speak drow ~Circe~
   command("speak undercommon");
}

void init(){
   ::init();
   add_action("shape_em","shape");
}

int shape_em(){
   object ob;
   command("emoteat "+TPQN+" glances up at $N for a moment.");
   command("say You wish a gem that resonates with your spirit, hmm?");
   command("emoteat "+TPQN+" draws forth a gem from a pouch and "+
      "studies $N through it.");
   if(!TP->is_class("psion") && !avatarp(TP)){
      command("say I will not do it.  Your mind does not hold the "+
         "capacity to use such a thing, and my time is precious.");
      return 1;
   }
   if(!TP->query_funds("gold",2000))  {
      command("say You lack the funds to pay me, young one.  For "+
         "you, it will cost two thousand gold coins.");
      command("emote slips the gem back into a pouch.");
      return 1;
   }
   TP->use_funds("gold",2000);
   command("emote allows the crystal to hover in the air before "+
      "him as he summons power.");
   tell_room(ETO,"The crystal flashes with a brilliant "+
      "light before the carver plucks it from the air.");
   ob = new("/d/magic/obj/exigency_gem");
   ob->set_weight(0);
   ob->move(TP);
   ob->move(TO);
   ob->set_weight(10);
   command("give exigency gem to "+TPQN+"");
   return 1;
}
