//Updated to be appropriately fearsome - Octothorpe 6/3/09
#include <std.h>
inherit "/std/monster";
string TARGET;
int wander,ATTACK;
void init() {
   ::init();
   if(interactive(TP)) {
      call_out("do_kill",10,TP);
   }
}
void create() {
   ::create();
   set_property( "no_scry", 1 );
   set_property("assassin",1);
    set_property("monsteroffer", 1);
   set_name("freloc");
   set_id( ({"freloc","assassin","hobbit"}) );
   set_hd(80,9);
   set_short("%^RESET%^%^RED%^Freloc, the hobbit assassin%^RESET%^");
   set_long("%^BLUE%^"
            "Freloc the Hobbit Assassin, the wandering butcher of Shadowgate is a "
            "incredibly powerful and deadly creature released upon the lands "
            "to carry out unspeakable acts for the gods. "
            "He travels with swift silence and purpose seeking out those who he hates. "
            "And his hatred is immense. He believes all adventurers who deem themselves powerful "
            "and rank themselves with titles of grandeur need to be erased from the lands. "
            "Many have oftened wondered when he passes them by and does not attempt to slay them "
            "if they should be insulted or thankful. He is reputed to be able to execute "
            "a series of lightning fast stabbing and slicing manuveurs when fighting, but when attempting "
            "to assassinate one of his victims with surprise, his opening attacks are even faster and deadlier. "
            "He wears a shadowy dark robe, with the hood pulled low over his face, and the pair of blackened daggers "
            "he wields never leave his hands, even as he sleeps with one eye open. A swirl of shadowy mist always "
            "surrounds him, no one is quite sure what the mist does for him or means."
           );
   set("race", "hobbit" );
   set_gender( "male" );
   set_body_type("humanoid");
   set_overall_ac(-30);
   set_alignment(9);
   set_stats("intelligence", 25);
   set_stats("wisdom", 25);
   set_stats("charisma",25);
   set_stats("strength", 25);
   set_stats("dexterity", 25);
   set_stats("constitution", 25);
   set_class("thief");
   set_mlevel("thief",80);
   set_mob_magic_resistance("average");
   set_property("magic",1);
   set_property("full attacks",1);
   set_guild_level("thief",80);
   set_thief_skill("move silently",95);
   set_thief_skill("hide in shadows",95);
   add_search_path("cmds/thief");
   set_max_hp(1500);
   set_hp(1500);
   set_exp(666);
   set_funcs(({"dart"}));
   set_func_chance(25);
   set("aggressive","attack_fun");
   set_emotes(5, ({
                  "%^MAGENTA%^Freloc says:%^RESET%^ I long for blood!"
                  "%^RESET%^",
                  "%^RED%^"
                  "Freloc cackles madly. "
                  "%^RESET%^",
                  "%^MAGENTA%^Freloc says:%^RESET%^ You will die like the rest of my victims!",
                  "%^MAGENTA%^Freloc says: %^RESET%^DIE ALREADY! "
                  "What the hell?!?",}), 1);
   new( "/d/common/assassins/obj/assassins_dagger.c" )->move(TO);
   command("wield dagger in left hand");
   new( "/d/common/assassins/obj/assassins_dagger.c" )->move(TO);
   command("wield dagger in right hand");
   remove_property("swarm");

}
void do_kill(object ob) {
   string who;
   if(!TO->query_current_attacker()) return;
   if(objectp(ob) && present(ob,environment(TO))) {
      who = ob->query_name();
      ("/cmds/spells/d/_dispel_magic.c")->use_spell(TO,who,80,100,"mage");
      call_out("do_kill",20,ob);
   }
}
void dart(object targ) {
   command( "say Now that you have arrived...please stay awhile.");
   command( "say I promise I won't keep you long...I'LL KEEP YOU FOREVER!");
   message( "info","%^RED%^"
            "Freloc slices you repeatedly across the face!\n"
            "As your own blood flows into your eyes blinding you, you\n"
            "feel Freloc plunge his dagger into your neck!%^RESET%^"
            ,targ );
   message( "info","%^RED%^"
            "Freloc whirls around slashing "
            +targ->query_cap_name()+
            " deep across the face!\n"
            "As "
            +targ->query_cap_name()+
            "'s blood flows, Freloc stabs\n"
            "his dagger into "
            +targ->query_cap_name()+
            "'s neck!%^RESET%^"
            ,environment(targ), targ );
   targ->do_damage("head",roll_dice(10,20));
   targ->set_paralyzed(random(30)+10,"%^RED%^The venom from the dagger seizes you!%^RESET%^");
   return 1;
}
int attack_fun() {
   object *user;
   int i,j;
   if( !userp(this_player()) ) return 1;
   if( (int)this_player()->query_level() > 499) return 1;
   if(avatarp(TP) && TP->query_invis()) return 1;
   if( this_player()->query_ghost() ) return 1;
   if((int)TP->query_level() < 30) {
      command(
             "say Do not trifle with me "+TPQCN+"!"
             );
      command(
             "say I have no time to deal with one as puny as yourself, but if you interfere with my plans..."
             );
      command("grin "+TP->query_name());
   } else {
      command(
             "say Slaughter time "+TPQCN+"!!!"
             );
      user = users();
      i = sizeof(user);
      if((string)TPQCN == TARGET) {
         for(j = 0;j < i;j++) {
            if((string)user[j]->query_level() > 19) {
               tell_object(user[j],"%^RESET%^Freloc %^MAGENTA%^<hm>%^RESET%^ "
                           "Alright "+TPQCN+"! What a sport, came back to play!");
            }
         }
      } else {
         for(j = 0;j < i;j++) {
            if((string)user[j]->query_level() > 19) {
               tell_object(user[j],"%^RESET%^Freloc %^MAGENTA%^<hm>%^RESET%^ "
                           "I have hunted long for you "+TPQCN+"...let the pain begin!");
            }
         }
      }
      call_out("stab",1,TP);
      command("scramble");
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
   if(present("corpse",ETO) && !present("corpse",ETO)->is_living()) {
      if(!query_current_attacker() ) {
         /*command("grin");
         message("environment","%^RED%^Suddenly, Freloc decides to offer the corpse!%^RESET%^",environment(this_object()));
         command("get corpse");
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
            if((string)user[jj]->query_level() > 19) {
               tell_object(user[jj],"%^RESET%^Freloc %^MAGENTA%^<hm>%^RESET%^ GET BACK HERE "+TARGET+" YOU SPINELESS WUSS!!!");
            }
         }
         ATTACK = 0;
         return;
      } else {
         if((int)TO->query_hp() < 300) {
            TO->add_hp(200);
            return;
         } else {
// Thanks to Tristan for example for this.
            if(wander > 20) {
               exits = environment(TO)->query_exits();
               i = sizeof(exits);
               j = random(i);
               exitn = (string)environment(TO)->query_exit(exits[j]);
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
void stab(object targ) {
   int mod;
   if(!present(targ,environment(TO))) return;
   if((string)TO->query_current_attacker() != targ) {
      mod = 10;
      if((string)targ->query_class() == "mage") mod = 5;
      if((string)targ->query_class() == "cleric") mod = 6;
      if((string)targ->query_class() == "druid") mod = 6;
      if((string)targ->query_class() == "ranger") mod = 8;
      if((string)targ->query_class() == "paladin") mod = 8;
      if((string)targ->query_class() == "antipaladin") mod = 8;
      if((string)targ->query_class() == "bard") mod = 6;
      if((string)targ->query_class() == "thief") mod = 6;
      if((string)targ->query_race() == "firbolg") mod = mod + 3;
      if((string)targ->query_race() == "ogre") mod = mod + 2;
      write("%^BOLD%^%^RED%^"
            +TO->query_cap_name()+" executes a blinding stab of assassination upon you!"
            "%^RESET%^"
           );
      say("%^BOLD%^%^RED%^"
          +TO->query_cap_name()+" executes an assassin like stab upon "
          +targ->query_cap_name()+
          "!%^RESET%^"
          ,TP);
      write("%^RED%^"
            +TO->query_cap_name()+" plunges his dagger into your head!"
            "%^RESET%^"
           );
      say("%^RED%^"
          +TO->query_cap_name()+" plunges his dagger into "
          +targ->query_cap_name()+
          "'s head!%^RESET%^"
          ,TP);
      targ->do_damage("head",random(mod)+4);
      write("%^RED%^"
            +TO->query_cap_name()+" plunges his dagger into your head!"
            "%^RESET%^"
           );
      say("%^RED%^"
          +TO->query_cap_name()+" plunges his dagger into "
          +targ->query_cap_name()+
          "'s head!%^RESET%^"
          ,TP);
      targ->do_damage("head",random(mod)+4);
      write("%^RED%^"
            +TO->query_cap_name()+" plunges his dagger into your head!"
            "%^RESET%^"
           );
      say("%^RED%^"
          +TO->query_cap_name()+" plunges his dagger into "
          +targ->query_cap_name()+
          "'s head!%^RESET%^"
          ,TP);
      targ->do_damage("head",random(mod)+4);
      write("%^RED%^"
            +TO->query_cap_name()+" plunges his dagger into your head!"
            "%^RESET%^"
           );
      say("%^RED%^"
          +TO->query_cap_name()+" plunges his dagger into "
          +targ->query_cap_name()+
          "'s head!%^RESET%^"
          ,TP);
      targ->do_damage("head",random(mod)+6);
      write("%^RED%^"
            +TO->query_cap_name()+" plunges his dagger into your head!"
            "%^RESET%^"
           );
      say("%^RED%^"
          +TO->query_cap_name()+" plunges his dagger into "
          +targ->query_cap_name()+
          "'s head!%^RESET%^"
          ,TP);
      targ->do_damage("head",random(mod)+8);
      write("%^RED%^"
            +TO->query_cap_name()+" plunges his dagger into your head!"
            "%^RESET%^"
           );
      say("%^RED%^"
          +TO->query_cap_name()+" plunges his dagger into "
          +targ->query_cap_name()+
          "'s head!%^RESET%^"
          ,TP);
      targ->do_damage("head",random(mod)+8);
      if(!targ->kill_ob(TO, 0)) return 1;
   }
}
void set_paralyzed(int time,string message) {return 1;}
