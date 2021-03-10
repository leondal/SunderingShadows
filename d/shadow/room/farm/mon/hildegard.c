//Hildegard leader of the Bandits -Cythera
//Updated 1/1/2012 by Ergo: gave random chance for which of her torso items is enchanted
#include <std.h>
#include <daemons.h>
#include "../farm.h";

inherit MONSTER;
int step1;
int step2;

void create(){
	object obj,curiass,shirt;
   	::create();
   	set_name("hildegard");
   	set_short("Hildegard, the one armed halfling");
   	set_id(({"hildegard","halfling","bandit","farm_mon"}));
   	set_long("Hildegard is a stout and wide halfling female"+
		" with reddish brown hair.  Her ruddy complexion"+
		" is dotted with dark freckles.  Her reddish brown"+
		" sideburns frame her lower face, with bits of mud in "+
		"the tangled mess.  The buxom halfling is dressed in a "+
		"steel breastplate over a chainmail shirt, over a "+
		"robe.  The right sleeve of the robe is pinned up, "+
		"due to her missing limb.  A leather belt holds a "+
		"holster for her trusty axe.  As the leader of these"+
		" bandits, Hildegard is a tough-as-nails 'den mother',"+
		" keeping her boys in line.  A brass and wood pipe "+
		"sticks out of her lips, as she puffs away on it.");
   	set_race("halfling");
        set_size(1);
        set_gender("female");
   	set_hd(12,4);
   	set_max_hp(120+random(50));
   	set_hp(query_max_hp());
   	set_overall_ac(10);
   	set_alignment(6);
   	set_class("fighter");
   	set_mlevel("fighter",12);
   	set_level(12);
	set_parrying(1);
   	set_stats("intelligence",13);
   	set_stats("wisdom",13);
   	set_stats("charisma",11);
   	set_stats("strength",18);
   	set_stats("constitution",19);
   	set_stats("dexterity",14);
	add_search_path("/cmds/fighter");
	set("aggressive",13);
	set_funcs(({"rushit","flashit","flashit"}));
	set_func_chance(30);
	set_property("full attacks",1);
	
	//50% chance of one of her torso items not being enchanted --Ergo
	curiass = new("/d/common/obj/rand/s_curiass.c");
	shirt = new("/d/common/obj/rand/rand_shirts.c");
        if(random(2)){
		curiass->remove_property("enchantment");
	}
	else{
		shirt->remove_property("enchantment");
	}
	curiass->move(TO);
	shirt->move(TO);
	obj=new("/d/common/obj/rand/r_helm.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	new("/d/barriermnts/lothwaite/obj/leather_breeches.c")->move(TO);
	obj=new("/d/dagger/kinaro/obj/crysaxe.c");
	obj->set_property("monsterweapon",1);
	obj->set_size(1);
	obj->move(TO); 
	force_me("wearall");
	force_me("wield axe");
      set_property("add kits",4);
   	set_exp(2200);
     	add_money("gold",random(400));
	add_money("silver",random(75));
	add_money("copper",random(200));
   	force_me("speech say in a gruff voice");
  
}
void rushit(object targ) {
	TO->force_me("rush "+targ->query_name());
}

void flashit(object targ) {
  	TO->force_me("flash "+targ->query_name());
}

void init(){
   ::init();
   add_action("ask_em","ask");
}


void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
   object current;
   object obj;
   string race;
   string name;
   set_spoken("wizish");
   race = who->query_race();
   name = who->query_name();
   if(!msg || !objectp(who)) return;
   if (objectp(current) && who != current) {
     force_me("emote chews on her pipe as she speaks to "+who->QCN+".");
     return;
   }
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"ail") != -1) && !step1){
            force_me("emote belches as she looks you over.");
      force_me("say Well, what do you want?");
      force_me("say Come on, out with it.");
      force_me("say That gnome didn't send you, did he?");
      step1 = 1;
      return;
   }
   if((strsrch(msg,"yes") != -1 || strsrch(msg,"Yes") != -1 ||
      strsrch(msg,"kay") != -1 || strsrch(msg,"yea") != -1) && step1 && !step2){
      force_me("say I don't care what that little runt said to you.");
      force_me("say He owes me for what he did to my arm. I'm just claiming what is due.");
      force_me("say You have a problem with that?");
      step2 = 1;
      return;
   }   
   if((strsrch(msg,"yea") != -1 || strsrch(msg,"Yea") != -1 ||
   strsrch(msg,"yes") != -1 || strsrch(msg,"kay") != -1 || 
   strsrch(msg,"No") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"no") !=-1) && step2 == 1) {
      force_me("say Good.");
      force_me("emote chews on the end of her pipe as she looks you over.");
      force_me("say Now about that fee to see me..");
      force_me("say I will take that now.");
      force_me("give grabs her battle axe and grins at "+name+"");
      force_me("say Thank you for contriubting to my wealth.");
      force_me("emote grins as she gets ready to attack.");
	force_me("rush "+TP->query_name()+"");
	step1 = 0;
      step2 = 0;
      return;
  }
}
void die(object ob) {
    new(OBJ"hildpipe")->move(TO);
	new(OBJ"shadow_note")->move(TO);
    ::die(ob);
}
