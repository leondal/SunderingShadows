//adapted for Juran by Circe 1/17/05
#include <std.h>

inherit MONSTER;

void create(){
	::create();
	set_name("old goblin");
	set_id(({"goblin","Goblin","wizened goblin","old goblin","wizened old goblin"}));
	set_short("A wizened old goblin");
	set_long(
	   "This old goblin is wizened and leathery, her skin "+
         "aged to a putrid yellow-green.  A thick beaten "+
         "golden ring pierces her septum, stained with age "+
         "and ill-use.  She is dressed in what was once a "+
         "rich brocade robe but is now tattered rags the color "+
         "of moss.  Despite her threadbare appearance, she is "+
         "clearly quite clever."
	);
	set_hd(40,8);
	set_hp(500);
	set_exp(30);
	set_race("goblin");
	set_gender("female");
	set_class("thief");
	set_overall_ac(-10);
	set_wielding_limbs(({"right hand","left hand"}));
	new("/d/common/obj/weapon/dagger")->move(TO);
	command("wield dagger");
}

void init(){
	::init();
   if(TP->query_true_invis()) return;
   call_out("give_quest",1,TP);
   add_action("ask_lady","ask");
}

int give_quest(object ob){
	int r;
  if ((!objectp(ob)) || (!userp(ob))) return 0;
	
    tell_room(environment(ob),"You see the goblin say something to "+ob->QCN+".",ob);
    tell_object(ob,"%^RESET%^%^MAGENTA%^The goblin looks up at you and says:");
    if(ob->query_lowest_level()<19){
       tell_object(ob,"%^BOLD%^%^RED%^You are not yet experienced enough "+
          "to help me, "+ob->QCN+".");
    }
    else if(member_array("High Mortal Quest",ob->query_quests())!=-1){
       tell_object(ob,"%^BOLD%^%^RED%^You have already helped me, "+ob->QCN+".");
    }
    else if(ob->query("which_hm_quest")){
       tell_object(ob,"%^BOLD%^%^RED%^I already told ya what to do, "+
          ""+ob->QCN+"!  If ya need to start over, please ask for help.");
    }else{
	tell_object(ob,"%^BOLD%^%^RED%^Come closer, "+ob->QCN+", I "+
	   "got a job for ya.");
	tell_object(ob,"%^BOLD%^%^GREEN%^There was a time long ago when "+
	   "the battles for power seemed endless.");
	tell_object(ob,"%^BOLD%^%^GREEN%^Three great swords were created "+
	   "by an unknown power in order to bring an end to the fighting.");
	tell_object(ob,"%^BOLD%^%^GREEN%^The power of these swords was "+
	   "found to be so great, that the one who possessed them was unstoppable.");
	tell_object(ob,"%^BOLD%^%^GREEN%^The time came when the world was "+
	   "restored to its peaceful state, and the leader feared that "+
	   "the swords could be used in a rebellion.");
	tell_object(ob,"%^BOLD%^%^GREEN%^The mighty swords were broken "+
	   "apart and the pieces scattered, locked in magical chests, "+
	   "with the intent that they could be reassembled if the time "+
	   "came when their power was once again needed to restore the peace.");	
	tell_object(ob,"%^BOLD%^%^RED%^The time has come, not to use "+
	   "the power of the swords, but to return them to their rightful home.");
	tell_object(ob,"%^BOLD%^%^RED%^I ask you to collect the pieces of "+
	   "one of these swords from across the lands.  Once the sword "+
	   "is assembled, you must take it to an ancient temple on a "+
	   "hidden island.");
	tell_object(ob,"%^BOLD%^I can give you only this - a note leading "+
	   "to the location of the first piece of the sword.  One warning, "+
	   "my friend: Be sure to keep close watch over the pieces - they "+
	   "will disappear if they leave your possesion.");
	tell_object(ob,"%^BOLD%^%^GREEN%^Those who succeed in this task "+
	   "will truly be considered great and high mortals.");
		
		r = random(3);
		switch (r){
			case 0: 
				ob->set("which_hm_quest","destiny");
				new("/d/hm_quest/obj/note1a.c")->move(ob);
				break;
			case 1:
				ob->set("which_hm_quest","ages");
				new("/d/hm_quest/obj/note1b.c")->move(ob);
				break;
			case 2:
				ob->set("which_hm_quest","fate");
				new("/d/hm_quest/obj/note1c.c")->move(ob);
				break;
			default: break;
		};
	}
	tell_object(ob,"\n%^MAGENTA%^The goblin returns to her work.");	
	return 1;
}

int ask_lady(string str){
  string which;

  which = (string)TP->query("which_hm_quest");
  if(!str || str!="for help"){
    tell_object(TP,"Try %^BOLD%^ask for help%^RESET%^.");
    return 1;
  }
  else{
    tell_object(TP,"%^MAGENTA%^The goblin says: %^RESET%^The only help I can give you is to restart your quest, "+TPQCN+".");
  switch (which) {
     case "destiny": new("/d/hm_quest/obj/note1a.c")->move(TP);
                    break;
     case "ages": new("/d/hm_quest/obj/note1b.c")->move(TP);
                 break;
     case "fate": new("/d/hm_quest/obj/note1c.c")->move(TP);
                 break;
    default: break;
  }
    tell_object(TP,"%^MAGENTA%^The goblin says: %^RESET%^I hope this will be of help, my friend.");
    return 1;
  }
}
