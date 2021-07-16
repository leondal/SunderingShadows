#include <std.h>
inherit "/std/monster";
int builder;
object player;
object scroll;

void create() {
   ::create();
   set_name("wizard");
   set_id( ({ "wizard","drow","jarrow" }) );
   set_race("drow");
   set_gender("male");
   set_short("Jarrow, an old drow with a thinning white mane");
   set_long("This drow has began showing the signs of aging, he is "+
   "obviously very old.  His flesh has thinned and is stretched "+
   "grotesquely tight in some places.  The %^RESET%^white mane%^CYAN%^ "+
   "atop his head is thinning yet still flowing to reach slightly "+
   "below his shoulders.  His eyes are a deep and intense %^RED%^"+
   "red%^RESET%^%^CYAN%^ that show a strange alertness for one as "+
   "old as he.");//  Perhaps you should listen to him.");
   set_class("mage");
   set_mlevel("mage",15);
   set_guild_level("mage",15);
   set_hp(130 + random(61));
   set_exp(6000);
   set("aggressive", 0);
   set_alignment(9);
   set_stats("intelligence",18);
   set_stats("wisdom",18);
   set_stats("strength",18);
   set_stats("charisma",18);
   set_stats("dexterity",18);
   set_stats("constitution",18);
   add_money("electrum",random(10));
   add_money("silver",random(10));
   add_money("gold",random(5));
   add_money("copper",random(20));
   set_spells( ({ "lightning bolt", "magic missile", "fireball",
   "acid arrow","hideous laughter" }) );
   set_spell_chance(95);
   set_overall_ac(0);
   if(!random(3)) {
     scroll = new("/d/magic/scroll");
     scroll->set_spell(random(6) + 1);
     scroll->move(TO);
   }     
}

void init(){
    ::init();
  if(interactive(TP))
    if(member_array("Stone Quest",TP->query_quests()) == -1){
	//add_action("startit","talk");
    //add_action("listenit","listen");
   }
}

void reply_back(string str) {
  tell_room(ETO,"%^MAGENTA%^The drow wizard says:%^RESET%^ "+str,TO);
}

void reply_back1(string str) {
  tell_room(ETO,"%^MAGENTA%^The drow wizard sighs, but continues: %^RESET%^"+str,TO);
}

void reply_back2(string str) {
  tell_room(ETO,"%^MAGENTA%^The old wizard takes a puff on his pipe and continues: %^RESET%^"+str,TO);
}

void reply_back3(string str) {
  tell_room(ETO,""+str,TO);
}


int listenit(string str) {
  string tem;
  player = this_player();
  if(!str) return notify_fail("Listen to whom?\n");
  if(!sscanf(str, "to %s", tem)) return notify_fail("You can't listen to that!\n");
  if(tem != "jarrow") return notify_fail("The "+tem+" in not present!\n");
  call_out("reply_back",2,"\n"+
    "Well it started along time ago.  The realm as you know it "+
      "was much smaller, and we drow once adventured upon the surface world.\n"+    "You know that we are a chaotic race.  Well there was once a old wizard\n"+
    "who wanted to kill his matron mother, so he created this great magical\n"+
    "weapon,  the stones of Deku'-arkenazzen.  These stones are very\n"+
    "powerful and a fine weapon indeed.\n");
  call_out("reply_back1",12,"\n");
  call_out("reply_back3",13,""+
      "Well many years ago, these stones were taken from our home, and thus\n"+
    "the purpose why I'm here.  I need to recover these stones, to study \n"+
      "them.  What I do know is this:  You my good "+TP->query_race()+", must find and\n"+
    "retrieve three stones and return back to me.  These stones are very \n"+
    "important to the balance between good and evil on this island \n"+
    "and I must have them to study.\n");
  call_out("reply_back2",16,"\n");
  call_out("reply_back3",17,""+
      "  What I can tell you about the stones is this.  The first stone, a \n"+
    "black stone, represents death.  The second stone, a purple stone, \n"+
    "represents pain.  The final and most important, a red stone, represents\n"+
    "hate.  Come back after you have gathered these three stones and talk\n"+
    "to me.  The fate of this island rests upon your shoulders.\n\n");
  return 1;
}

int startit(string str){
     string temp;
        player = this_player();
	if(!str) return notify_fail("Talk to who?\n");
	if(!sscanf(str,"to %s",temp))
		return notify_fail("You can't talk to that!\n");
	if(temp != "jarrow") return notify_fail("The "+temp+" is not here!\n");
	builder = 1;
	return 1;

}

void start_heart() {
	set_heart_beat(1);
}

void heart_beat() {
    object obj, obj2, obj3;
   ::heart_beat();
      if (builder) {
	builder++; 
	if (builder == 2) 
          say("%^MAGENTA%^Jarrow says:%^RESET%^ Well, good day "+player->query_race()+".");
	if (builder == 3) 
		say("%^MAGENTA%^Jarrow says:%^RESET%^ It's good to see there are still those who can find me!.\n");
	if (builder == 4) {
		say("%^MAGENTA%^Jarrow says:%^RESET%^ Do you have the stones for me?\n");
                if(!(obj = present("red stone",player))) {
			builder = 0;
			say("%^MAGENTA%^Jarrow says:%^RESET%^ You don't have the red stone!!!");
			return 1;
		}
                if(!(obj2 = present("black stone",player))) {
                        builder = 0;
                        say("%^MAGENTA%^Jarrow says:%^RESET%^ You don't have the black stone!!!");
                        return 1;
                }
                if(!(obj3 = present("purple stone",player))) {
                        builder = 0;
                        say("%^MAGENTA%^Jarrow says:%^RESET%^ You don't have the purple stone!!!");
                        return 1;
                }
		obj->remove();
                obj2->remove();
                obj3->remove();
             say("%^MAGENTA%^Jarrow says:%^RESET%^ Ahh, yes you do have the stones!\n");
		write("Jarrow takes the stones from you.\n");
	}
	if (builder == 5) 
		say("%^MAGENTA%^Jarrow says:%^RESET%^ Many thanks for bringing these to me.\n");
	if (builder == 6) 
		say("%^MAGENTA%^Jarrow says:%^RESET%^ As a reward, I shall give you something.\n");
	if(builder == 7)
                say("%^MAGENTA%^Jarrow says:%^RESET%^ Here, take these stones, as a reward!\n");
	if(builder == 8){
if(member_array("Stone Quest",player->query_quests()) == -1){
     obj = new("/d/deku/weapons/Deku");
     obj->move(player);
     player->set_quest("Stone Quest");
     player->fix_exp(2000000,player);
     tell_object(player,"%^BOLD%^You have finished the Quest for the Stones!");
}
	}
	if(builder == 9)
                  say("%^MAGENTA%^Jarrow says:%^RESET%^ You can wield the stones, they are a fine weapon.  Perhaps you will grow closer to my kind and help us even more as, in using them, you come to better understand what I said each color represents.\n");
	if(builder == 10)
    		builder = 0;

    }
    return 1;
}
