#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit DINOS;
int flying;
int flag;

void create(){
    ::create();
    flying = 0;
    set_name("pteranodon");
    flag = 0;
    set_short("Pteranodon");
    set_property("meat eater", 1);
    set_id( ({"dino", "dinosaur", "ptera", "pteranodon"}) );
    set_long(
      "This small winged dinosaur looks much bigger because of its giant wingspan.  A feared carnivore, this dinosaur flies around looking for creatures to eat for its dinner."
    );
    set_size(2);
    set_hd(8+random(5), 10);
    set_max_hp(100 + (8*query_hd()));
    set_exp(query_hd()*400);
    set_hp(query_max_hp());
    set_race("dinosaur");
    if(random(2)) set_gender("male");
      else set_gender("female");
    set_overall_ac(0);
    set("aggressive", 15);
    set_body_type("fowl");
    set_attack_limbs( ({"beak", "right claw", "left claw"}) );
    set_base_damage_type("piercing");
    set_attacks_num(2);
    set_damage(2,4);
    set_funcs( ({"fly"}) );
    set_func_chance(80);
    set_moving(1);
    set_speed(10);
}

int fly(object targ){

    if(!flying){
      if(random(3) && flag) return 1;
      tell_room(ETO, "%^YELLOW%^The Pteranodon spreads its wings and flies high above your head.");
      set_overall_ac(-100);
      set_func_chance(101);
    set_attack_bonus(10);
      flag = 1;
      flying = 1;
      return 1;
    } else {
        if(!random(8)){
      tell_room(ETO, "%^YELLOW%^The Pteradon lands in front of you and begins attacking!");
        set_overall_ac(0);
        set_func_chance(50);
      set_attack_bonus(0);
        flying = 0;
        return 1;
      } else {
        tell_object(targ, "%^RED%^The Pteradon dives at you with its sharp beak!");
        tell_room(ETO, "%^RED%^The Pteradon dives at "+targ->query_cap_name()+"!", targ);
        if(random(20)+1 < Thaco(0,targ,0)){
          tell_object(ETO, "%^RED%^The Pteradon misses.");
        } else {
          targ->do_damage("torso", roll_dice(2,6));
        }
      }
    }
}

void heart_beat(){
    ::heart_beat();
    if(!objectp(TO) || !objectp(ETO))   return;
    if(query_attackers() == ({}) && flying){
      tell_room(ETO, "%^YELLOW%^The Pteradon lands.");
      set_overall_ac(0);
      set_func_chance(50);
      set_attack_bonus(0);
      flying = 0;
    }
}

int free_movement() { return 1; }

void init(){
    ::init();
    add_action("stab", "stab");
    add_action("stab", "rush");
    add_action("stab", "charge");
}

int stab(string str){
    if(!str) return 0;
    if(str != "pteranodon" && str != "dino" && str != "dinosaur" && str != "ptera") return 0;

    if(flying){
      tell_object(TP, "%^BOLD%^%^CYAN%^You can't "+query_verb()+" something that's flying.  Duh.");
      tell_room(ETO, ""+TPQCN+" valiantly but uselessly tries to "+query_verb()+" the flying dinosaur.", TP);
      return 1;
    }
    return 0;
}
