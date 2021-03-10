/* copied/modified elranger to create a leader - to give good people ways to 
get the elven longswords and studded by doing good deeds using Crystal's 
Swanmay and Silvim as examples (Styx 3/2002) */
//Changed refrences to Barrows being near Azha - Cythera 3/05
// made it make the stuff monster weapon in create(), then remove the property
// when somebody trades for it, so people can't strip him of his stuff - Ares 09/04/05
#define ROADEND "/d/dagger/road/road2b"
#define TONOVI1 "/d/dagger/tonovi/1path1"
#define TONOVI2 "/d/dagger/tonovi/2path1"
#define TORM "/d/dagger/Torm/road/path1"
#define DALE1 "/d/dagger/Daggerdale/gates/Wgate"
#define DALE2 "/d/dagger/Daggerdale/gates/Ngate"
#define D_MARSH "/d/dagger/marsh/marsh1"
#define KINARO "/d/dagger/kinaro/path1"
#define ELEMENTS "/d/dagger/elements/path/path1"
#define AKETON "/d/dagger/aketon/path/path1"
#define KEEP "/d/dagger/keep/road/road5"
#define SOLAREN "/d/player_houses/solaren/solaren1"
#define STELLA "/d/dagger/road/stella/sroad5"
#define NOGO ({ROADEND, TONOVI1, TONOVI2, D_MARSH, KINARO, ELEMENTS, AKETON, STELLA})


#include "/d/dagger/road/short.h"
inherit NPC;

int okExit(string exit);

void create() {
   object ob;
    ::create();
   set_nwp("forage",10,500);
   set_nwp("hunting",10,500);
    set_name("Yardleyu Erksine");
    set_id(({"elf", "ranger", "leader", "ranger leader", "yardleyu", "Yardleyu"}));
    set_short("Yardleyu Erskine, elven ranger leader");
    set_long(
      "This is a leader of the elven scout rangers that can be found on the roads in this area.  Although good at hiding in the brush around the roads, this one more often makes himself seen to speak with travellers and especially aid those who fight against notorious evil."
    );
  if(!random(3)){ set_mob_magic_resistance("average");}
  set_overall_ac(0);
  set_class("ranger");
  set_class("cleric");
  set_spells(({"call lightning", "dispel magic", "dispel magic", "hold person" }));
  set_spell_chance(20);
  set_mlevel("ranger", 35);
  set_mlevel("cleric",20);
  set_guild_level("cleric",20);
  set_guild_level("ranger", 35);
  set_hd(35,3);
  set_max_hp(400);
  set_hp(400);
  set_property("full attacks", 1);
  remove_property("swarm");
  set_gender("male");
  set("race", "elf");
  set_body_type("human");
  set_size(2);
  set_property("alignment adjustment",-10);
  set_property("no dominate",1);
  set_stats("strength", 18);
  set_stats("dexterity", 19);
  set_stats("constitution", 15);
  set_stats("intelligence", 14);
  set_stats("charisma", 14);
  set_stats("wisdom", 14);
  set_alignment(4);
  set("aggressive", 2);
  set_moving(1);
  set_speed(80);
// setting monsterweapons randomly in die() function so they can be given out ok
  new("/d/dagger/road/obj/elfsword")->move(TO);
  switch(random(2)) {
    case 0:  new(OPATH "studded+2")->move(TO);           break;
    case 1:  new(OPATH "studded+3")->move(TO);           break;
  }
  switch(random(3)) {
    case 0:  new("/d/laerad/obj/bracers3")->move(TO);    break;
    case 1:  new("/d/laerad/obj/bracers4")->move(TO);    break;
    case 2:  new("/d/laerad/obj/bracers5")->move(TO);    break;
  }
//Be sure to leave this sword second for the give below to work right
  new("/d/tharis/obj/psword")->move(TO);
  command("wield longsword");
  command("wield longsword 2");
  command("wearall");
  add_money("gold", 100 + random(100));
  add_money("platinum", 50 + random(10));
  set_funcs( ({"slash"}) );
  set_func_chance(40);

//yes, I meant to not have any breaks so low numbers would monsterweapon everything
   switch(random(10)) {
     case 0..3:  
         ob = present("long sword");
         if (objectp(ob)) { ob->set_property("monsterweapon",1); }
     case 4..5:  
         ob = present("studded");
         if (objectp(ob)) { ob->set_property("monsterweapon",1); }
     case 6..7:  
         ob = present("elven longsword"); 
         if (objectp(ob)) { ob->set_property("monsterweapon",1); }
     case 8:     
         ob = present("bracers");
//I do mean to repeat studded so bracers wouldn't always & give it another chance
         if (objectp(ob)) { ob->set_property("monsterweapon",1); }
     case 9:     
         ob = present("studded");
         if (objectp(ob)) { ob->set_property("monsterweapon",1); }
   }
}

void init() {
    ::init();
    if( (string)TP->query_name() == "Wandering guard") {
       command("say You shall soon take your last breath!");
       command("kill Wandering guard");
    }
}

int query_watched(){
    return 90;
}

int slash(object targ){
    tell_room(ETO, "%^BOLD%^%^GREEN%^The ranger lunges at "+targ->query_cap_name()+", the sword glowing in his hands!", targ);
    tell_object(targ, "%^BOLD%^%^GREEN%^The ranger lunges at you with a great glowing sword!");
    if(targ->query_stats("dexterity") < random(35)){
      tell_room(ETO, "%^BOLD%^%^GREEN%^The ranger strikes "+targ->query_cap_name()+" powerfully with his sword!", targ);
     tell_object(targ, "%^BOLD%^%^GREEN%^The ranger slashes you with his powerful glowing sword!");
      targ->do_damage("torso",roll_dice(4,10));
      targ->set_paralyzed(random(30), "That blow left you shaken up.");
    } else {
      tell_room(ETO, "%^BOLD%^%^GREEN%^"+targ->query_cap_name()+" moves out of the way of the glowing sword's arc!", targ);
      tell_object(targ, "You are able to move out of the way of the glowing sword's arc!");
    }
    return 1;
}

void catch_say(string msg){
   ::catch_say(msg);
   call_out("do_stuff",1,msg,TP);
}

int choose;

void do_stuff(string msg, object ob){
   string race;
   int align;
   object obj;
   race = TP->query_race();
   align = TP->query_alignment();
   if(race == "elf" || race == "half-elf")  force_me("speak elven");
   if(race == "voadkyn")                    force_me("speak giant");
   if(race != "elf" && race != "half-elf" && race != "voadkyn")  
      force_me("speak common");
   if((string)TP->query_name() == "Yardleyu Erksine") return;
//first, deal with invis. people
   if(TP->query_invis()) {
      switch(random(5)) {
        case 0:  force_me("emote looks around cautiously");
                   break;
        case 1:  force_me("say Who goes there?  Kindly come visible to speak?");
                   break;
        case 2:  //command("chant dispel magic");
                 new("/cmds/spells/d/_dispel_magic")->use_spell(TO,0,20,100,"cleric");
                   break;
        case 3:  force_me("emote frowns and grips his swords more tightly.");
                   break;
        case 4:  force_me("say Are you a criminal or evil that you hide or is "
                          "there evil about that you hide in fear?");
                   break;
      }
      if(random(5))  return;
   }
//second, tell evil people to get lost and attack if they don't.
   if(align == 3 || align == 6 || align == 9) {
     force_me("eye "+TPQN);
     force_me("emote concentrates deeply\n");
     force_me("say I sense evil within you.");
     force_me("say Begone before I feel the need to rid the world of you!");
     call_out("kill_em",10,TP); 
     return;
   }
  
//if they haven't handed over a weapon and been given a choice yet, interact
//and give them the mission
   if(!choose) {
     if(strsrch(msg, "evil") != -1) {
       force_me("say My rangers patrol diligently but evil is still quite "
         "strong in many places.");
       force_me("say There are weapons of great evil I cannot leave here to "
         "seek out and destroy myself.  Will you help us rid the world of them?");
       return;
     }   
     if(strsrch(msg, "help") != -1 || strsrch(msg,"weapon") != -1 || 
         strsrch(msg,"sword") != -1 || strsrch(msg,"yes") != -1 || 
         strsrch(msg,"Yes") != -1) {
       force_me("say If you dare to join us to destroy great evils, I will "
         "reward you for your bravery.");
       call_out("say1",1);
       call_out("say2",8);
       return;
     }
     if(strsrch(msg, "hello") != -1 || strsrch(msg,"greeting") != -1 || 
         strsrch(msg,"Hello") != -1 || strsrch(msg,"Greeting") != -1 || 
         strsrch(msg,"Yes") != -1) {
       if(race == "elf") {
         force_me("say Greetings cousin.  I hope this day finds you faring "
           "well and safe from the evils of the lands.");
         return;
       }
       force_me("say Greetings.  I hope your travels find you safe from the evils "
         "all about us.");
       return;
     }
     if(strsrch(msg, "caves") != -1 || strsrch(msg, "drow") != -1) {
      force_me("say Prepare well if you enter deep into those caves where the "
        "drow reside for they guard the means to escape from there with great "
        "magic and powerful creatures.");
      return;
     }
     if(strsrch(msg, "barrows") != -1 || strsrch(msg, "slaying") != -1) {
      force_me("say The skeletal guardians in the pits near Cyric's Temple are "
        "formidable and all must be defeated to descend to defeat the greater "
        "evil they serve and guard.  May the light strengthen you and guide "
        "your hand in that dark place.");
      return;
     }
     if(strsrch(msg,"bane") != -1 || strsrch(msg,"baneblade") != -1 ||
       (strsrch(msg,"Bane") != -1) ) {
      force_me("say There is a shadowy beast deep within the caves southeast of "
"Shadow's desert, servant to Bane and wielder of that god's prized blade.");
      force_me("say Do not allow evil beings to discover where they are found, "
        "but do work diligently to destroy them and their weapons.");
      return;
     }
   } 
//this section deals with the trade (choose has been set from receiving the item)
   if(choose) {
     if(strsrch(msg,"elven sword") != -1) {
       force_me("bow "+TPQN);
       if(race == "half-elf") {
         force_me("eye "+TPQN);
         force_me("say Clearly you are not of pure elven blood.  I am sorry for "
           "your misfortune of birth.  The elven sword's magic would simply "
           "reject you.");
         force_me("say Please choose again.");
         return;
       }
       if(race != "elf") {
         force_me("say This fine elven longsword is crafted with magic that "
           "will reject any but those of pure elven blood.");
          force_me("say I am sorry but I must ask you choose differently.");
         return;
       }
       if(race == "elf") {
         force_me("say You have chosen wisely cousin.  Wield it proudly and "
            "may it serve you well.");
         obj = present("elven longsword");
         obj->remove_property("monsterweapon");
         force_me("unwield elven longsword");
         force_me("give elven longsword to "+TPQN);
         choose = 0;
         call_out("go_hide",2);
         return;
       }
     }
     if(strsrch(msg,"longsword") != -1) {
         force_me("say It is a fine sword, may it serve you well.");
         obj = present("long sword");
         obj->remove_property("monsterweapon");
         force_me("unwield long sword");
         force_me("give long sword to "+TPQN);
         choose = 0;
         call_out("go_hide",2);
         return;
     }
     if(strsrch(msg,"bracers") != -1) {
         force_me("say Bracers are truly a boon.  I hope the enchantment on these "
            "is blessed in your favour.");
         obj = present("bracers");
         obj->remove_property("monsterweapon");
         force_me("remove bracers");
         force_me("give bracers to "+TPQN);
         choose = 0;
         call_out("go_hide",2);
         return;
     }
     if(strsrch(msg,"leather") != -1) {
         force_me("say I thank you for helping destroy such evil.  May this "
            "leather protect you well.");
         obj = present("studded");
         obj->remove_property("monsterweapon");
         force_me("remove studded");
         force_me("give studded to "+TPQN);
         choose = 0;
         call_out("go_hide",2);
         return;
     }
   }
//default responses if none above fits to give them hints, only respond 1/3 though   
   if(random(3)) return;
   switch(random(6)) {
     case 0:  
       force_me("say If you wish to help in our fight against evil, "
          "perhaps you seek a fine weapon or armor?");
       break;
     case 1:
       force_me("say These swords my rangers and I use are finely crafted.  "
          "Perhaps you are interested in them?");
       break;
     case 2:
       force_me("say Locally we fight evil among Tonovi slavers and in the "
         "caves north.  Drow reside deep in one and ogre hoards in yet another.");
       break;
     case 3:
       force_me("say There is so much evil hidden about.  We must never let "
          "our guard down lest they trick and betray us.");
       break;
     case 4:
       force_me("say Bane's influence is strong in Tonovi and he tempts many "
          "with promises of power and his evil weapons.");
       break;
     case 5:
       force_me("say The Tonovi guards that wander are not typical guards.  "
          "They serve the evil in control of Tonovi and that slave trade and "
          "must be stopped.");
       break;
   }
   return;
}

void say1() {
   force_me("say There are several vile and evil weapons we seek to see "
      "destroyed.");
   force_me("whisper "+TPQN+" %^CYAN%^There is a sword of slaying that is "
       "found deep in the barrows near Cyric's Temple.");
   force_me("say Do not allow evil beings to discover where they are found, "
       "but do work diligently to destroy them and their weapons.");
   return;
}

void say2() {
   force_me("whisper "+TPQN+" There is also the Baneblade, found "
      "well-hidden and deep in caves east and south of the Shadow desert.");
   force_me("say %^BOLD%^Bring either of those vile weapons to me and I will trade "
      "and reward you with something you wish of mine.");
   return;
}
 
void receive_given_item(object ob){
   string race;
   race = TP->query_race();
   if(race == "elf" || race == "half-elf")  force_me("speak elven");
   if(race == "voadkyn")                    force_me("speak giant");
   if(race != "elf" && race != "half-elf" && race != "voadkyn")  
      force_me("speak common");
   if (ob->id("sword of slaying") || ob->id("baneblade")) {
      choose = 1;
      TO->set_speed(0);
      TO->set_moving(0);
      force_me("say Yes, this is one of the weapons I seek to see destroyed!");
      force_me("offer sword");
      force_me("say You have done the realm a great service and I will reward "
        "you as promised.");
      if( (string)TP->query_race() == "elf") {
         force_me("say I can offer you this fine %^GREEN%^elven sword%^RESET%^, "
           "crafted by our elders and only useful to one of full elven blood.");
      }
      force_me("say Any may choose the enchanted %^BOLD%^longsword %^RESET%^or "
              "the fine %^ORANGE%^leather armor %^RESET%^or %^YELLOW%^bracers "
              "%^RESET%^I wear.");
      force_me("say You have two minutes to say which item you choose.");
      return;
   }
   force_me("say I am sorry but this is not one of the items I can reward you "
      "for bringing to me.");
   return;
}

void kill_em(object targ) {
   if(!present(TP))  
      return;
   force_me("say %^YELLOW%^I warned you, begone!");
   force_me("kill "+TPQN);
}

void go_hide() {
  force_me("say May you find happiness and success in your travels.");
  force_me("emote slips silently into the undergrowth and disappears.");
//      tell_room(ETO,"The Gatekeeper shrugs and lumbers off.");
  move("/d/shadowgate/void");
  remove();
}

void die(object obj) {
/*    object ob; // moved this to create so people can't stip him when he's uncon -Ares
//yes, I meant to not have any breaks so low numbers would monsterweapon everything
   switch(random(10)) {
     case 0..3:  
         ob = present("long sword");
         if (objectp(ob)) {
             ob->set_property("monsterweapon",1);
         }

     case 4..5:  
         ob = present("studded");
         if (objectp(ob)) {
             ob->set_property("monsterweapon",1);
         }
     case 6..7:  
         ob = present("elven longsword"); 
         if (objectp(ob)) {
             ob->set_property("monsterweapon",1);
         }
     case 8:     
         ob = present("bracers");
//I do mean to repeat studded so bracers wouldn't always & give it another chance
         if (objectp(ob)) {
             ob->set_property("monsterweapon",1);
         }
     case 9:     
         ob = present("studded");
         if (objectp(ob)) {
             ob->set_property("monsterweapon",1);
         }
   }*/
   tell_room(ETO,"The ranger screams an elven curse on you and offers most of "
     "his gear as he dies.",TO);
   ::die(obj);
}

void move_around() {
    string *exits;
    string exit;

    if(!this_object()) return;
    if(!objectp(ETO)) return;
    ETO->setupExits();
    if(query_current_attacker()) return;
    if(environment(this_object()))
      exits = (string *)environment(this_object())->query_exits();
    else
      exits = 0;
    if(sizeof(exits)){
      exit = exits[random(sizeof(exits))];
      (environment(this_object())->query_exit(exit))->init();
      if(okExit(exit))
        command(exit);
    }
    moving = 0;
}

int okExit(string exit){
    string filename;

    if(exit == "temple") return 0;

    filename = environment(this_object())->query_exit(exit);
    if(member_array(filename, NOGO) != -1) return 0;
    return 1;
}
