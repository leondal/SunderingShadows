//seagull.c - nuisance monster for Leilani ~Circe~ 5/27/07
#include <std.h>
inherit MONSTER;

object deadcrab;

void create() {
   ::create();
   set_name("seagull");
   set_id(({"seagull","gull","bird"}));
   set_race("seagull");
   if(!random(2)){
      set_gender("male");
   }else{
      set_gender("female");
   }
   set_short("%^BOLD%^%^WHITE%^A graceful white seagull%^RESET%^");
   set_long(
      "This graceful seagull has a slender white body with a "
      "thin black ring around its neck.  Its beady black eyes "
      "cast a calculating glance along the shore as it looks "
      "for food.  In the air, the gull soars gracefully on "
      "spread wings, though it loses some of its agility when "
      "it walks upon the shore.");
   set_level(3);
   set_body_type("fowl");
   set("aggressive",6);
   set_alignment(5);
   set_size(1);
   set_hd(3,5);
   set_exp(30);
   set_max_hp(15+random(10));
   set_hp(query_max_hp());
   set_max_level(5);
   set_emotes(5,({
      "The seagull takes flight for a few paces, flapping its wings.",
      "The seagull darts quickly across the sand.",
      "The seagull soars high overhead on outstretched wings."
   }),0);
   set_achats(3, ({
      "The seagull dives down from overhead, attacking with its beak.",
      "The seagull takes wing, flying just out of reach."
   }) );
   set_funcs(({"swoop"}));
   set_func_chance(25);
   set_moving(1);
   set_speed(60);
   set_nogo(({"/d/islands/spriggans/room/s52", "/d/islands/spriggans/room/s26"}));
//will need to set nogos once the island is complete.  For now, keeping it where rooms are made.
   force_me("message in soars in");
   force_me("message out soars $D");
}

void init(){
   ::init();
   if(present("crab")){
      tell_room(ETO,"%^BOLD%^%^RED%^The seagull spots the crab and dives!");
      force_me("kill crab");
      return;
   }
   if(present("corpse")){
      deadcrab = present("corpse");
      if((string)deadcrab->query_name() == "Crab"){
         tell_room(ETO,"%^BOLD%^%^RED%^The seagull makes a quick meal of the crab!%^RESET%^");
         deadcrab->remove();
      }
   }
}

int swoop(object targ){
   if(random(20) < (int)targ->query_stats("dexterity")){
      tell_object(targ,"%^BOLD%^%^WHITE%^The seagull swoops at you, but "
         "you dodge out of the way!");
      tell_room(ETO,"%^BOLD%^%^WHITE%^The seagull swoops at "+targ->QCN+" "
         "but "+targ->QS+" dodges out of the way!",targ);
      return 1;
   }else{
      tell_object(targ,"%^BOLD%^%^WHITE%^The seagull swoops at you, "
         "battering you!");
      tell_room(ETO,"%^BOLD%^%^WHITE%^The seagull swoops at "+targ->QCN+", "
         "battering "+targ->QO+"!",targ);
      targ->do_damage(targ->return_target_limb(),random(10)+10);
      return 1;
   }
}
