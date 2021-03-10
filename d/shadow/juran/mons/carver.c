#include <std.h>
#include <move.h>

inherit MONSTER;

void create(){
   	::create();
   	set_name("Old carver");
   	set_short("An old ivory carver");
   	set_id(({"monster","carver","ivory carver"}));
set_long("This old orc appears rather broken and harmless. He is missing several teeth"+
   " and has hardly any hair left on his head. He appears rather weak except for his"+
   " arms. His hands are quite gnarled but still have some obvious dexterity left"+
   " in them as he holds a knife that he can use to <carve> you a statue for some gold.");
    	set_race("orc");
   	set_body_type("humanoid");
  	set_size(2);
   	set_hd(1,1);
   	set_exp(1000);
}
void init(){
   	::init();
   	add_action("carve","carve");
}
int carve(){
        int i;
   	object ob;
   	command("smile "+TPQN);
   	command("speech cackle");
   	command("say my magic is way great too.");
   	command("emote draws forth a block of ivory and then waits.");
    	if(!TP->is_class("mage") && !TP->is_class("bard")
		&& !TP->is_class("sorcerer") && !avatarp(TP)){
      	command("emote gasps when he sees you are not a mage!");
      	command("say You will never get one of these!");
      	return 1;
    	}
   	if(!TP->query_funds("gold",2000))  {
      	command("gasp");
      	command("say you lack the funds to pay me, you are nothing.");
      	command("emote hides the ivory away.");
      	return 1;
   	}
   	TP->use_funds("gold",2000);
   	command("emote draws his knife across the ivory in a magical motion.");
   	ob = new("/d/magic/obj/statue");
   	ob->set_weight(0);
   	ob->move(TP);
   	ob->move(TO);
  	ob->set_weight(10);
        command("give statue to "+TPQN);
   	return 1;
}
