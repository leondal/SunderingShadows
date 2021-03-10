#include <std.h>
inherit "/std/monster";

string TARGET;
int wander,ATTACK;
void init() {
   ::init();
   if(interactive(TP)) {
      call_out("do_kill",10,TP);
//      add_action("drink_fun","drink");
   }
}
void create() {
   object ob;

   ::create();
   set_property( "no_scry", 1 );
   set_property("assassin",1);
    set_property("monsteroffer", 1);
   set_name("dryzil");
   set_id( ({"dryzil","assassin","hobbit"}) );
   set_hd(30,9);
   set_short("%^RESET%^%^RED%^Dryzil, the hobbit assassin%^RESET%^");
   set_long("%^BLUE%^"
            "Dryzil the Hobbit Assassin, the wandering strangler of Shadowgate is a "
            "incredibly powerful and deadly creature released upon the lands "
            "to carry out unspeakable acts for the gods. "
            "He travels with swift silence and purpose seeking out those who he hates. "
            "And his hatred is immense. He believes all adventurers who deem themselves powerful "
            "and rank themselves with titles of grandeur need to be erased from the lands. "
            "Many have often wondered when he passes them by and does not attempt to slay them "
            "if they should be insulted or thankful. He is reputed to be able to execute "
            "a series of lightning fast stabbing and slicing maneuvers when fighting, but when attempting "
            "to assassinate one of his victims with surprise, his opening attacks are even faster and deadlier. "
            "He wears a shadowy dark robe, with the hood pulled low over his face, and the pair of blackened daggers "
            "he wields never leave his hands, even as he sleeps with one eye open. A swirl of shadowy mist always "
            "surrounds him, no one is quite sure what the mist does for him or means."
           );
   set_race("hobbit" );
   set_gender( "male" );
   set_body_type("human");
   set_overall_ac(-10);
   set_alignment(5);
   set_stats("intelligence", 22);
   set_stats("wisdom", 22);
   set_stats("charisma",22);
   set_stats("strength", 22);
   set_stats("dexterity", 22);
   set_stats("constitution", 22);
   set_class("thief");
   set_mob_magic_resistance("average");
   set_guild_level("thief",23);
   set_thief_skill("move silently",95);
   set_thief_skill("hide in shadows",95);
   add_search_path("cmds/thief");
   set_max_hp(375);
   set_hp(375);
   set_exp(19000);
   set_funcs(({"dart"}));
   set_func_chance(25);
   set("aggressive","attack_fun");
   set_emotes(5, ({
      "%^MAGENTA%^Dryzil says:%^RESET%^ I long for blood!%^RESET%^",
      "%^RED%^Dryzil cackles madly.",
      "%^MAGENTA%^Dryzil says:%^RESET%^ You will die like the rest of my victims!",
      "%^MAGENTA%^Dryzil says: %^RESET%^DIE ALREADY!  What the hell?!?",
   }), 1);
   ob =  new( "/d/common/assassins/obj/assassins_dagger.c" );
   ob->set_property("monsterweapon",1);
   ob->move(TO);
   command("wield dagger in left hand");
   ob =  new( "/d/common/assassins/obj/assassins_dagger.c" );
   ob->set_property("monsterweapon",1);
   ob->move(TO);
   command("wield dagger");
   remove_property("swarm");
}

void do_kill(object ob) {
   string who;
   if(!TO->query_current_attacker()) return;
   if(objectp(ob) && present(ob,environment(TO))) {
      who = ob->query_name();
      if(!TO->query_paralyzed()) {
         ("/cmds/spells/d/_dispel_magic.c")->use_spell(TO,who,10,100,"mage");
      }
      call_out("do_kill",20,ob);
   }
}
void dart(object targ) {
   command( "say You are hereby found guilty of being too powerful.");
   command( "say Time to pay justice!");
   message( "info","%^RED%^"
            "Dryzil slices you repeatedly across the face!\n"
            "As your own blood flows into your eyes blinding you, you\n"
            "feel Dryzil plunge his dagger into your neck!%^RESET%^"
            ,targ );
   message( "info","%^RED%^Dryzil whirls around slashing "
            +targ->query_cap_name()+" deep across the face!\n"
            "As "+targ->query_cap_name()+"'s blood flows, Dryzil stabs\n"
            "his dagger into "+targ->query_cap_name()+
            "'s neck!%^RESET%^"
            ,environment(targ), targ );
   targ->do_damage("head",roll_dice(6,8));
   targ->set_paralyzed(random(23)+8,"%^RED%^The venom from the dagger seizes you!%^RESET%^");
   return 1;
}

int attack_fun() {
   object *user;
   int i,j;
   if( !userp(this_player()) ) return 1;
   if( (int)this_player()->query_level() > 499) return 1;
   if(TP->query_true_invis()) return 1;
   if( this_player()->query_ghost() ) return 1;
   if((int)TP->query_level() < 20) {
      command("say Do not trifle with me "+TPQCN+"!");
      command("say I have no time to deal with one as puny as yourself, but if you interfere with my plans..." );
      command("grin "+TP->query_name());
   } else {
      command("say Death shall be served to you "+TPQCN+"!!!");
      user = users();
      i = sizeof(user);
      if((string)TPQCN == TARGET) {
         for(j = 0;j < i;j++) {
            if(high_mortalp(user[j])){
               tell_object(user[j],"%^RESET%^Dryzil %^MAGENTA%^<hm>%^RESET%^ "
               "Lovely show "+TPQCN+"! Saved me hunting you down a second time!");
            }
         }
      } else {
         for(j = 0;j < i;j++) {
            if(high_mortalp(user[j])){
               tell_object(user[j],"%^RESET%^Dryzil %^MAGENTA%^<hm>%^RESET%^ "
               "Well, well, well "+TPQCN+"...I knew I would find you among the weenies!");
            }
         }
      }
      call_out("stab",1,TP);
      TARGET = (string)TP->query_cap_name();
      ATTACK = 1;
      return 1;
   }
}
void heart_beat() {
   object *user;
   string *exits;
   string exitn;
   int i,j;
   int ii,jj;
   ::heart_beat();
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if(present("corpse",ETO) && !living(present("corpse",ETO))) {
      if(!query_current_attacker() ) {
         /*command("grin");
         message("environment","%^RED%^Suddenly, Dryzil decides to offer the items in the room!%^RESET%^",ETO);
         command("offerall");
         command("offer corpse");
         command("offer katana");
         command("offer sword");
         command("offer sword");
         command("offer armor");
         command("offer armour");
         command("chuckle");*/
         ATTACK = 0;
         return;
      }
   } else {
      if(ATTACK == 1 && !query_current_attacker()) {
         user = users();
         ii = sizeof(user);
         for(jj = 0;jj < ii;jj++) {
            if(high_mortalp(user[jj])){
               tell_object(user[jj],"%^RESET%^Dryzil %^MAGENTA%^<hm>%^RESET%^ Wait! "+TARGET+" come back! I am not finished with you yet!!!");
            }
         }
         ATTACK = 0;
         return;
      } else {
         if((int)TO->query_hp() < 200) {
            TO->add_hp(2);
            return;
         } else {
// Thanks to Tristan for example for this.
            if(wander > 20) {
               exits = environment(TO)->query_exits();
               i = sizeof(exits);
               j = random(i);
               exitn = (string)environment(TO)->query_exit(exits[j]);
// added to keep him doing his job in Goblins over longer reboots *Styx* 1/26/03
	       if(exitn == "/d/shadow/room/goblin/rooms/gate2" ||
		     exitn == "/d/shadow/room/forest/road3")
		  return;
               TO->force_me(exits[j]);
               wander = 0;
               return;
            } else {
               wander = wander + 1;
               return;
            }
         }
      }
   }
}
int test_heart() {return 1;}
int drink_fun(string str) {
   if(TP->query_lowest_level()<20) return 0;
   write("For some reason, you find that impossible!");
   return 1;
}
void stab(object targ) {
   int mod;
   if(!present(targ,environment(TO))) return;
   if((string)TO->query_current_attacker() != targ) {
      mod = 8;
      if((string)targ->query_class() == "mage") mod = 4;
      if((string)targ->query_class() == "cleric") mod = 5;
      if((string)targ->query_class() == "druid") mod = 5;
      if((string)targ->query_class() == "ranger") mod = 7;
      if((string)targ->query_class() == "paladin") mod = 7;
      if((string)targ->query_class() == "antipaladin") mod = 7;
      if((string)targ->query_class() == "bard") mod = 4;
      if((string)targ->query_class() == "thief") mod = 5;
      if((string)targ->query_race() == "firbolg") mod = mod + 3;
      if((string)targ->query_race() == "ogre") mod = mod + 2;
      write("%^BOLD%^%^RED%^"
            +TO->query_cap_name()+" wraps his steel garot around your throat and begins to "
            "squeeze!"
            "%^RESET%^"
           );
      say("%^BOLD%^%^RED%^"
          +TO->query_cap_name()+" executes an assassin like move upon "
          +targ->query_cap_name()+" and swiftly the steel garot finds its mark!"
          "%^RESET%^"
          ,TP);
      targ->set_paralyzed(80,"Dryzil has a garot wrapped around your throat and you struggle in vain to break free!");
      TO->set_paralyzed(80,"Bug report if seen!");
      write("%^RED%^You are being strangled to death!%^RESET%^");
      targ->do_damage("head",random(mod)+5);
      call_out("squeeze",10,targ,mod);
      if(!targ->kill_ob(TO, 0)) return 1;
   }
}
void squeeze(object targ,int mod) {
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if(!targ) return;
   if(!present(targ,ETO)) return;
   if(!TO->query_paralyzed()) return;
   write("%^RED%^You are being strangled to death!%^RESET%^");
   targ->do_damage("head",random(mod)+5);
   call_out("squeeze",10,targ,mod);
}
