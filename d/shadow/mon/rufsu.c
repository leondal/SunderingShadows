//put the silk cloak on a Tonovi head guard and a comparable one on Pirate
//island a while back.  Now low levels don't get something they can't use &
//higher level ones don't have to kill a hermit wizard who doesn't hurt anyone
//or keep running to DD to get it.  *Styx*  2/22/02

#include "melnmarn.h"

inherit MONSTER;
int builder;
object player;

void create() {
    ::create();
	set_name("the wizard");
	set_id( ({ "wizard","human","rufsu" }) );
	set("race", "human");
	set_gender("female");
        set_level(19);
	set_short("An old wizard");
	set_long("She looks like an old and wise wizard. Maybe you can talk to her.\n");
	set_body_type("human");
	set_class("mage");
  	set("aggressive", 0);
  	set_alignment(9);
  	set_size(2);
   	set_stats("intelligence",18);
   	set_stats("wisdom",18);
   	set_stats("strength",18);
   	set_stats("charisma",18);
   	set_stats("dexterity",18);
   	set_stats("constitution",18);
        set_hd(19,5);
	set_max_hp(query_hp());
	add_money("electrum",random(10));
	add_money("silver",random(10));
	add_money("gold",random(5));
	add_money("copper",random(20));
//        new("/d/shadow/obj/clothing/silkcloak")->move(TO);
//        command("wear cloak");
}
void init(){
    ::init();
	add_action("startit","talk");
}

int startit(string str){
     string temp;
	player = TP;
	if(!str) return notify_fail("Talk to who?\n");
	if(!sscanf(str,"to %s",temp))
		return notify_fail("You can't talk to that!\n");
	if(temp != "wizard") return notify_fail("The "+temp+" is not here!\n");
	builder = 1;
	return 1;

}

void start_heart() {
	set_heart_beat(1);
}

void heart_beat() {
    object obj;
    ::heart_beat();
    if(!objectp(TO)) return;
      if (builder) {
	builder++; 
	if (builder == 2) 
		say("The Wizard says: Well, good day, my dear fellow.\n");
	if (builder == 3) 
		say("The Wizard says: It's good to see there are still those who can find me!.\n");
	if (builder == 4) {
		say("The Wizard says: Do you have a note for me?\n");
		if(!(obj = present("cave note",player))){
			builder = 0;
			say("The Wizard says: You don't have the note!!!");
			return 1;
		}
       if(member_array("Pipe Quest",player->query_quests()) != -1){
         builder = 0;
    return;
   }
player->set_quest("Pipe Quest");
		obj->remove();
		say("The Wizard says: Aah, yes you do have the note!\n");
		write("The wizard takes the note from you.\n");
	}
	if (builder == 5) 
		say("The Wizard says: Many thanks for bringing this to me.\n");
	if (builder == 6) 
		say("The Wizard says: As a reward, I shall give you something.\n");
	if(builder == 7)
		say("The Wizard says: Here, take this pipe, as reward!\n");
	if(builder == 8){
		obj = new("/d/shadow/obj/misc/pipe");
    player->fix_exp(10000, TP);
		obj->move(player);
	}
	if(builder == 9)
		say("The Wizard says: You can smoke tobacco in it.\n");
	if(builder == 10)
    		builder = 0;

    }
    return 1;
}
