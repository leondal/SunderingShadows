// The Sword of Chaos - an artifact of great power
// Thorn@ShadowGate
// 001116
// Azha Underground
// swordchaos.c

#include <std.h>
#include "/d/shadow/room/goblin/short.h"

inherit "/std/weapon";

int uses,xx,yy,FLAG;

void create() {
  ::create();
  set_name("long sword");
  set_id(({
    "sword","chaos sword","sword of chaos","chaos", "long", "long sword"
}));
  set_short("A long sword");
  set_long(
@THORN
%^CYAN%^  The Sword of Chaos is an ancient artifact of great power.  Even without
magical identification, you know of %^BOLD%^this%^RESET%^BLUE%^ blade from your childhood stories.
As with any artifact, it has great power, but you may find that it exacts
a high price and it certainly has a mind of its own.  
THORN
  );
  set_weight(20);
  set_size(2);
  set("value",10000);
  set_wc(1,10);
  set_large_wc(1,12);
  set_type("slashing");
  set_hit((: TO, "extra_hit":));
  set_wield((: TO, "extra_wield":));
  set_unwield((: TO, "extra_unwield" :));
  set_property("enchantment",6);
  set_heart_beat(1);
  set_unique(1);
  uses = random(5)+50;
}

string wrapit(string str) {
  return wrap(str,70);
}

void heart_beat() {
  int align,i;
  object owner,env,obj,*inv;
  env = ETO;
  if(!objectp(ETO)) return;
  if(objectp(env) && living(env)) {
    owner = env;
    env = environment(owner);
  }
  if(!(TO->query_wielded())) {
    return;
  } else {
    if( obj = present("corpse",env)) {
      tell_object(owner,wrapit(""
        "%^CYAN%^BOLD%^A streak of light shoots from the sword "
        "into the corpse, disintegrating it and leaving only "
        "sparks of released energy!"
        "")
      );
      tell_object(owner,wrapit(""
        "%^YELLOW%^BOLD%^You absorb some of these sparks of"
        "life energy!"
        "")
      );
      owner->heal(random(6)+2);
      uses = uses + random(2)+1;
      obj->remove();
      return;
    } else {
      xx = random(500);
      yy = random(8)+1;
      if(xx < 1) {
        env->add_align_adjust(-1);
                tell_object(owner,
                  wrapit("%^GREEN%^BOLD%^You feel your will being bent to the blade's alignment a little bit!%^RESET%^")); 
        if(yy == 1) {
          tell_object(owner,wrapit(""
             "%^CYAN%^BOLD%^The sword tells you: %^RESET%^"
            "Don't you just want to break things every so often?")
          );
        }
        if(yy == 2) {
          tell_object(owner,wrapit(""
             "%^CYAN%^BOLD%^The sword tells you: %^RESET%^"
            "Laws are for cowards to hide behind.  A hero does what is required to win.")
          );
        }
        if(yy == 3) {
          tell_object(owner,wrapit(""
             "%^CYAN%^BOLD%^The sword tells you: %^RESET%^"
            "Use your imagination.  Do not let your inhibitions take control!")
          );
        }
        if(yy == 4) {
          tell_object(owner,wrapit(""
             "%^CYAN%^BOLD%^The sword tells you: %^RESET%^"
            "The universe seeks to bring itself to Chaos, "
            "why would anyone wish to fight against what is natural?")
          );
        }
        if(yy == 5) {
          tell_object(owner,wrapit(""
             "%^CYAN%^BOLD%^The sword tells you: %^RESET%^"
            "Order causes oppression, not freedom!  "
            "Fight against this oppression with me!")
          );
        }
        if(yy == 6) {
          tell_object(owner,wrapit(""
             "%^CYAN%^BOLD%^The sword tells you: %^RESET%^"
            "Listen to me, young one.  I have been forged "
            "to help you do what needs to be done!")
          );
        }
        if(yy == 7) {
          tell_object(owner,
             wrapit("%^CYAN%^BOLD%^The sword tells you: %^RESET%^"
            "Make use of my power! ")
          );
        }
        if(yy == 8) {
          tell_object(owner,wrapit(""
             "%^CYAN%^BOLD%^The sword tells you: %^RESET%^"
            "The Way is like a stream that sweeps all along. "
            "Those who seek to fight the current will drown.")
          );
        }
      }
      return;
    }
  }
}
int extra_hit(object ob) {
  int xx,dam,cost;
  object rab;
  object vic = environment(TO)->query_current_attacker();
  if(!objectp(ob) || !objectp(vic)) return 1;
  if(uses < 0) return 0;
  if(random(8) > 3) return 0;
  xx=random(6)+1;
  switch(xx) {

  case 1:
  case 2:
  message("my_action",wrapit(""
    "%^CYAN%^BOLD%^Suddenly, a %^RESET%^BOLD%^pale white fire%^CYAN%^ leaps from the sword at "
    +vic->query_cap_name()+
    "!")
  ,environment(TO));
  message("other_action",wrapit(""
    "%^CYAN%^BOLD%^Suddenly, a %^RESET%^BOLD%^pale white fire%^CYAN%^ leaps from the sword at "
    +vic->query_cap_name()+
    "!")
  ,environment(ob),(({environment(TO), ob})));
  message("my_action",
    wrapit("%^CYAN%^BOLD%^Suddenly, a %^RESET%^BOLD%^pale white fire%^CYAN%^ leaps from the sword at you "
    "causing you to gnash your teeth in anguish!")
  ,ob);
  vic->cause_typed_damage(vic, "head", roll_dice(1, 10) + 9, "fire");
  uses = uses - random(3)+1;
  return 1;

  case 3:
  dam = random((int)environment(TO)->query_level());
  if(dam < 0) dam = 1;
  message("my_action",
    wrapit("%^CYAN%^BOLD%^The sword tells you: %^RESET%^"
    "WE BRING CHAOS TO OUR ENEMIES!!!"
    "")
  ,environment(TO));
  message("other_action",wrapit(""
    +environment(TO)->query_cap_name()+" gets a wild look in "
    +environment(TO)->query_possessive()+
    " eyes as the Sword of Chaos traces its deadly arc!"
    "")
  ,environment(ob),(({environment(TO), ob})));
  message("my_action",wrapit(""
    +environment(TO)->query_cap_name()+" gets a wild look in "
    +environment(TO)->query_possessive()+
    " eyes as the Sword of Chaos traces its deadly arc!"
    "")
  ,ob);
  uses = uses - 1;
  return dam;

  case 4:
  if((int)environment(TO)->query_hp() < 10) {
  message("my_action",
    wrapit("%^CYAN%^BOLD%^The sword shouts:%^RESET%^ You are gravely wounded!  Pull back!"
    "")
  ,environment(TO));
  dam = random(1)+1;
  uses = uses -1;
  return dam;

  case 5:
  if(present("felemental",environment(ETO))) return 1;
  message("my_action",wrapit(""
    "%^CYAN%^BOLD%^The sword tells you:%^RESET%^ I shall call for aid in "
    "our battle!!!")
  ,environment(TO));
  message("other_action",wrapit(""
    "%^YELLOW%^BOLD%^The blade in the hands of "
    +environment(TO)->query_cap_name()+
    " glows and an elemental is summoned to aid "
    +ob->query_cap_name()+"!"
    "")
  ,environment(ob),(({environment(TO), ob})));
  message("my_action",wrapit(""
    "%^YELLOW%^BOLD%^An elemental is summoned by the sword that "
    +environment(TO)->query_cap_name()+" wields, and it attacks you!"
    "")
  ,ob);
  new("/d/magic/obj/felemental")->move(environment(ETO));
  if(rab = present("felemental",environment(ETO))) {
    rab->force_me("kill "+vic->query_name());
  }
  uses = uses - 2;
  return 1;

  case 6:
  message("my_action",""
    "%^CYAN%^BOLD%^The sword tells you:%^RESET%^ I shall protect us! "
  ,environment(TO));
  message("other_action",""
    "%^YELLOW%^BOLD%^A flame leaps out of nowhere!"
    ""
  ,environment(ob),(({environment(TO), ob})));
  message("my_action",""
    "%^YELLOW%^BOLD%^A flame leaps out of nowhere!"
    ""
  ,ob);
  rab = new("/d/magic/obj/firewall.c");
        rab->move(environment(ETO));
        rab->surround(environment(TO));
  uses = uses - 1;
  return 1;
  }
  }
}
int extra_wield() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  TO->set_name("%^CYAN%^Sword of Chaos%^RESET%^");
  TO->set_short("%^CYAN%^Sword of Chaos%^RESET%^");
    write(
      wrapit("%^BOLD%^You wield the sword and feel stronger, but less inclined to put up with people standing in your way!"
      "")
    );
    say(
      wrapit("%^CYAN%^BOLD%^"+environment(TO)->query_cap_name()+
	  " wields a sword and a %^RED%^red light %^CYAN%^"+
      "seems to flicker in "+environment(TO)->query_possessive()+" eyes!")
    );
                tp->add_stat_bonus("strength",1);
                tp->add_stat_bonus("wisdom",-2);
                tp->add_stat_bonus("charisma",-3);
                
  return 1;
}
int extra_unwield() {
  object tp;
  tp = ETO;
  TO->set_name("long sword");
  TO->set_short("A long sword");
  if (!tp) return 0;
  tell_object(ETO,
    wrapit("%^CYAN%^BOLD%^The sword tells you:%^RESET%^ Call on me again when you need the power that only Chaos can give!")
  );
  tp->add_stat_bonus("strength",-1);
  tp->add_stat_bonus("wisdom",2);
  tp->add_stat_bonus("charisma",3);
  return 1;
}


