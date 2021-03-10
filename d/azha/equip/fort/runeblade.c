// A Runeblade
// Thorn@ShadowGate
// 001116
// Azha Underground
// runeblade.c

#include <std.h>
#include "/d/shadow/room/goblin/short.h"

inherit "/std/weapon";

int uses,xx,yy,FLAG;

void create() {
  ::create();
  set_name("long sword");
  set_id(({
    "sword","runesword","black sword","rune sword", "rune", "long sword"
}));
  set_short("%^BLACK%^BOLD%^A black long sword inscribed with %^RED%^vivid red runes%^RESET%^");
  set_long(
@THORN
%^RED%^  This is a large long sword, its blade almost as broad as that of a 
broadsword, but not quite.  The blade is of a black metal that defies 
description, and might not be metal at all.  There are elven runes of a 
strange and very unsettling nature that are etched in the blade in a 
vivid red.  Or at least you think they must be etched, even though they 
actually seem to sort of hover above the blade.  
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
  set_property("cursed",1);
  set_heart_beat(1);
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
        " life energy!"
        "")
      );
      owner->heal(random(10)+2);
      uses = uses + random(2)+1;
      obj->remove();
      return;
    } else {
      xx = random(500);
      yy = random(8)+1;
      if(xx < 1) {
        env->add_align_adjust(-4);
                tell_object(owner,
                  wrapit("%^GREEN%^BOLD%^You feel your will being bent to the blade's alignment a little bit!%^RESET%^")); 
        if(yy == 1) {
          tell_object(owner,wrapit(""
             "%^BLACK%^BOLD%^The sword tells you: %^RESET%^"
            "Destroy.")
          );
        }
        if(yy == 2) {
          tell_object(owner,wrapit(""
             "%^BLACK%^BOLD%^The sword tells you: %^RESET%^"
            "Kill.")
          );
        }
        if(yy == 3) {
          tell_object(owner,wrapit(""
             "%^BLACK%^BOLD%^The sword tells you: %^RESET%^"
            "Serve me.")
          );
        }
        if(yy == 4) {
          tell_object(owner,wrapit(""
             "%^BLACK%^BOLD%^The sword tells you: %^RESET%^"
            "Maim.")
          );
        }
        if(yy == 5) {
          tell_object(owner,wrapit(""
             "%^BLACK%^BOLD%^The sword tells you: %^RESET%^"
            "Bring terror.")
          );
        }
        if(yy == 6) {
          tell_object(owner,wrapit(""
             "%^BLACK%^BOLD%^The sword tells you: %^RESET%^"
            "Obey.")
          );
        }
        if(yy == 7) {
          tell_object(owner,
             wrapit("%^BLACK%^BOLD%^The sword tells you: %^RESET%^"
            "Kill. ")
          );
        }
        if(yy == 8) {
          tell_object(owner,wrapit(""
             "%^BLACK%^BOLD%^The sword tells you: %^RESET%^"
            "Death.")
          );
        }
      }
      return;
    }
  }
}
int extra_hit(object ob) 
{
    int xx,dam,cost;
    object rab;
    object vic = environment(TO)->query_current_attacker();
    if(!objectp(ob) || !objectp(vic)) return 1;
    if(uses < 0) return 0;
    if(random(8) > 3) return 0;
    xx=random(6)+1;
    
    switch(xx) 
    {

    case 1:
    case 2:
        message("my_action",wrapit("%^RED%^BOLD%^Suddenly, a %^BLACK%^BOLD%^black fire%^RED%^ leaps from the sword at "
            +vic->query_cap_name()+"!"),environment(TO));
        message("other_action",wrapit(""
            "%^RED%^BOLD%^Suddenly, a %^BLACK%^BOLD%^black fire%^RED%^ leaps from the sword at "
            +vic->query_cap_name()+"!"),environment(ob),(({environment(TO), ob})));
        message("my_action",wrapit("%^BLACK%^BOLD%^Suddenly, a %^BLACK%^BOLD%^black fire%^RED%^ leaps from the sword at you "
            "causing you to scream in pain!"),ob);
        vic->cause_typed_damage(vic, "head", roll_dice(1, 10) + 9, "fire");
        uses = uses - random(3)+1;
        return 1;

    case 3:
        dam = random((int)environment(TO)->query_level());
        if(dam < 0) dam = 1;
        message("other_action",wrapit(""
            +environment(TO)->query_cap_name()+" gets a wild look in "
            +environment(TO)->query_possessive()+
            " eyes as the black sword slices into its victim!"
            ""),environment(ob),(({environment(TO), ob})));
        message("my_action",wrapit(""
            +environment(TO)->query_cap_name()+" gets a wild look in "
            +environment(TO)->query_possessive()+
            " eyes as the black sword slices into its victim!"
            ""),ob);
        uses = uses - 1;
        return dam;

    case 4:
        if((int)environment(TO)->query_hp() < 10) {
            message("my_action",
            wrapit("%^RED%^BOLD%^The sword says sarcastically:%^RESET%^ You are weak.  Retreat like the weakling you are."
            ""),environment(TO));
        }
        dam = random(1)+1;
        uses = uses -1;
        return dam;

    case 5:
        if(present("felemental",environment(ETO))) return 1;
            message("my_action",wrapit(""
            "%^RED%^BOLD%^The sword begins to glow.")
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


int extra_wield() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
    write(
      wrapit("%^BOLD%^The sword fights to take control of your soul!"
      "")
    );
    say(
      wrapit("%^CYAN%^BOLD%^"+environment(TO)->query_cap_name()+
	  " wields a sword and "+environment(TO)->query_possessive()+
	  " eyes seem to become lifeless!")
    );
    tp->add_stat_bonus("strength",1);
    tp->add_stat_bonus("wisdom",-1);
    tp->add_stat_bonus("charisma",-4);
                
  return 1;
}


int extra_unwield() {
  object tp;
  tp = ETO;
  if (!tp) return 0;
  tell_object(ETO,
    wrapit("%^BLACK%^BOLD%^The sword tells you:%^RESET%^ I will have your soul eventually, weakling.")
  );
  tp->add_align_adjust(-10);
  tp->add_stat_bonus("strength",-1);
  tp->add_stat_bonus("wisdom",1);
  tp->add_stat_bonus("charisma",4);
  return 1;
}


