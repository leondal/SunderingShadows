#include <std.h>
#include "../defs.h" 
inherit NPC;

#define HIDES1 ({ "elk","rabbit","basilisk","snake","goat" }) // prey
#define HIDES2 ({ "wolf","lynx","panther","leopard","fox" }) // predators
#define HIDES3 ({ "hawk","eagle","owl","raven","parrot" }) // bird feathers
int choose;
string hide1, hide2, hide3;

void create() {
    ::create();
    set_name("tiktik");
    set_id( ({ "beastkin", "tiktik", "TikTik", "beastfolk", "trader", "hides trader"}) );
    set_short("%^RESET%^%^ORANGE%^TikTik, beastkin hides trader%^RESET%^");
    set("aggressive", 0);
    set_hd(29,2);
    set_long("%^GREEN%^TikTik is a lean beastkin, somewhat shorter and slimmer than a standard human.  Her face, certainly, looks very human, "
"with a flattened nose and sharply angled eyes, that are made to appear even more so by the way she has braided her fur/hair severely "
"back from her face.  You're sure there's not an ounce of fat on her, beneath the rippling layers of muscle and green/black fur that "
"covers her from head to toe.  Her only garment is a hide belt strung with pouches and a knife sheath.  Her amber eyes often spare a "
"swift glance your way, and her nimble fingers are regularly at work on this piece of hide and that.  Some she scrapes, others she "
"washes or oils, and some she hangs about over branches to dry, or above a small fire-pit to smoke.  Across other branches are nets "
"and strings of birdfeathers in a variety of hues.%^RESET%^");
    set_gender("female");
    set_property("no dominate", 1);
    set_property("no kill", 1);
    set_mob_magic_resistance("average");
    set_property("full attacks",1);
    set_alignment(5);
    set_race("beastkin");
    set_overall_ac(-19);
    set_stats("strength", 18);
    set_stats("dexterity", 20);
    set_stats("constitution", 18);
    set_stats("intelligence", 12);
    set_stats("wisdom", 14);
    set_stats("charisma", 14);
    set_class("fighter");
    set_body_type("human");
    set_hp(400);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_mp(0);
    set_max_mp(query_mp());
    force_me("speak common");
    force_me("speech chatter");
    hide1 = HIDES1[random(sizeof(HIDES1))];
    hide2 = HIDES2[random(sizeof(HIDES2))];
    hide3 = HIDES3[random(sizeof(HIDES3))];
}

void catch_say(string msg){
   ::catch_say(msg);
   call_out("do_stuff",1,msg,TP);
}

void do_stuff(string msg, object ob){
   object obj;
   int oktogive=0;

// messages for invis folks
   if(TP->query_invis()) {
      switch(random(5)) {
        case 0: force_me("emote spares a wary glance around.");
          break;
        case 1: force_me("say Who there? Come out, tricksy!"); force_me("emote motions her knife at the air.");
          break;
        case 3:  force_me("emote narrows her yellow eyes and tightens her grip on her knife.");
          break;
        default: break;
      }
      return;
   }

// messages to pick up conversation
   if(!choose) {
     if(strsrch(msg, "hello") != -1 || strsrch(msg,"greeting") != -1 || 
         strsrch(msg,"Hello") != -1 || strsrch(msg,"Greeting") != -1) {
       force_me("say Greets. Come here wit' good things for trade? Maybe lookin' for good-hides?");
       force_me("emote nods towards one of the hides drying over a branch.");
       force_me("say TikTik got many good ones.");
       return;
     }
     if(strsrch(msg, "hide") != -1 || strsrch(msg,"feathers") != -1 || strsrch(msg,"trade") != -1) {
       force_me("emote grins, showing sharp-filed teeth.");
       force_me("say Came to right place. No better hides than TikTik's! Today, has "+hide1+" and "+hide2+" hides, and "+hide3+" feathers.");
       force_me("say TikTik is happy to swap. You bring human stuff, metals. Good stuff, least five spans!");
       force_me("emote motions to you.");
       force_me("say TikTik waits. Go get!");
       return;
     }   
   } 

// messages to choose an item if they've brought back metal
   if(choose) {
     if(strsrch(msg,hide1) != -1) {
       obj = new("/std/obj/skin");
       obj->setup_tanned_skin(hide1);
       obj->move(TO);
       oktogive = 1;
     }
     if(strsrch(msg,hide2) != -1 && !oktogive) {
       obj = new("/std/obj/skin");
       obj->setup_tanned_skin(hide2);
       obj->move(TO);
       oktogive = 1;
     }
     if(strsrch(msg,hide3) != -1 && !oktogive) {
       obj = new("/std/obj/skin");
       obj->setup_feathers(hide3);
       obj->move(TO);
       oktogive = 1;
     }
     if(oktogive) {
       force_me("say Good pick! For you, take, take.");
       force_me("give skin to "+TPQN);
       if(present("skin", TO)) {
         command("say You got too much stuff. TikTik puts it here.");
         command("emote sets it down before you.");
         command("drop skin");
	 }
       choose = 0;
       return;
     }
   }

// messages if nothing in their convo matches trigger words!
   if(random(4)) return;
   switch(random(5)) {
     case 0:  
       force_me("say TikTik's hides are best. None better anywhere!");
       break;
     case 1:
       force_me("emote adjusts the positioning on one of the drying hides, to better let it catch the air.");
       break;
     case 2:
       force_me("emote scrapes at a fresh skin with a deft and practiced hand.");
       break;
     case 3:
       force_me("emote binds a few more feathers along a string made of plant-fibers.");
       break;
     case 4:
       force_me("say Come you here for trade? Got many good hides!");
       break;
   }
   return;
}
 
void receive_given_item(object ob){
   if(base_name(ob) == "/std/obj/metal") {
      force_me("emote 's bright eyes light up as she spies the metal.");
      force_me("say Good! You bring!");
      force_me("emote checks it over carefully.");
      if((int)ob->query_uses() < 5) { // she wants at least 5 pieces
        force_me("say Not enough. TikTik want least five spans!");
        force_me("emote holds up one hand to show five fingers, and then sets the metal back down before you.");
        force_me("say Bring more. Then trade!");
        force_me("drop metal");
        return;
      }
      if((int)ob->query_quality_type() < 8) { // she wants at least excellent quality
        force_me("say Not good. TikTik want good metal!");
        force_me("emote sets the metal back down before you.");
        force_me("say Bring better. Then trade!");
        force_me("drop metal");
        return;
      }
      choose = 1;
      force_me("say Is good metal! And many!");
      force_me("emote quickly scales the tree she sits beneath, and stashes the metal somewhere in the shelter tangled within the leaves above.");
      ob->move("/d/shadowgate/void");
      ob->remove();
      force_me("emoteat tiktik Just when you were starting to worry that she wasn't returning, $M re-emerges and hops easily back down to ground level.");
      force_me("say Today, has "+hide1+" and "+hide2+" hides, and "+hide3+" feathers.  Which you want?");
      return;
   }
   force_me("say TikTik not want this. You keep.");
   force_me("emote puts the item back down before you.");
   force_me("drop "+ob->query_name() );
   return;
}