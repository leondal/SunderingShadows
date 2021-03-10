#include <std.h>
#include "/realms/grendel/grendel.h"

inherit "/std/weapon";

int dam, i;
string pl, att;

create() {
  ::create();
  set_name("stones");
  set_id(({"stones","elfstones","stones of Deku'-arkenazzen"}));
   set_size(1);
  set_wc(1,3);
  set_weight(1);
  set("short","Stones of Deku'-arkenazzen");
  set("long","A soft, twinkling blue light emanates from the three small\n"+
             "stones.  One for hate, death, and pain.  These stones were\n"+
             "created ages past by drow wizards as a weapon to destroy\n"+
             "good.  A feeling of evil radiates from the stones.\n");
  set_value(500);
  set_type("bludgeoning");
   set_prof_type("magic club");
   set_weapon_speed(4);
  set_hit((:this_object(),"weapon_hit":));
    set_wield((:this_object(),"extra_wield":));
}

void get() {
  int dam;
  if(ALIGN->is_evil(TP)) {
     write("The fire of the stones burns through your blood! Seek and \n"+
          "destroy good wherever it may lurk!\n");
    return 1;
  }
  else {
    write("You scream in pain as the stones burn you!  Good taints your\n"+
          "blood.\n");
say(TPQCN+" screams in pain as "+TP->query_objective()+" tries to get the stones.");
    dam = 5 + random(5);
    this_player()->add_hp(-dam);
    this_player()->force_me("drop stones");
    return 0;
  }
  return dam;
}

void weapon_hit(object ob) {
  int bonus;
  if(!is_evil(ETO)){
     tell_object(ETO,"You scream in agony as the stones' fire burns you!  You have\n"+
          "turned away from the dark and must be punished!\n");
   ETO->force_me("drop stones");
  }
  i = random(100);
  if (i <40) {
    bonus = random(5);
    tell_object(ETO,"Blue fire surges from the stones battering "+ob->query_cap_name()+" backwards.");
    tell_room(environment(query_wielded()),"Blue fire surges from the stones battering "+ob->query_cap_name()+" backwards.",({ETO,ob}));
     tell_object(ob,"Blue fire surges from "+ETO->query_cap_name()+"'s stones, battering you backwards.");
  }
  else if (i <70) {
    bonus = 5 + random(5);
    tell_object(ETO,"Magical fire tears through "+ob->query_cap_name()+".");
      tell_room(environment(query_wielded()),"Magical fire tears through "+ob->query_cap_name()+".",({ETO,ob}));
      tell_object(ob,"Magical fire tears through you!");
  }
  else if (i <90) {
    bonus = 10;
    tell_object(ETO,"The magic flares against "+ob->query_cap_name()+".");
       tell_room(environment(query_wielded()),"The magic flares against "+ob->query_cap_name()+".",({ETO,ob}));
      tell_object(ob,"The magic flares against you.");
  }
  else if (i <100) {
    bonus = 10;
    tell_object(ETO,"Blue fire explodes from the elfstones!");
    tell_object(environment(query_wielded()),"Blue fire explodes from the elfstones!");
  }
  return bonus;
}
int extra_wield() {
    if((int)this_player()->query_level() < 7) {
     notify_fail("You are too weak to control the stones' inner fury!\n");
    return 0;
} else {
    return 1;
}
}
