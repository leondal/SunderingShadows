//watch.c
#include <std.h>

inherit "/d/shadow/mon/guards/watchint.c";

string rank;
int monster_ac;

nosave object leader;

void set_leader(object ob){
    leader = ob;
}


object query_leader(){
    return leader;
}


void create(){
    ::create();

    set_name("a watch man");
    set_id(({"guard","city guard","human"}));
    set_short("A tall human");
    doGender();
    hairColor();
    eyeColor();
    doHeight();
    doWeight();
    setupName("guard");
    set_race("human");
    add_search_path("/cmds/fighter");
    set_body_type("human");
    set_class("fighter");
    set_property("magic resistance",random(30));

    set_hd(20+random(31),1);
    set_hp(roll_dice(query_hd(),15));
  set_ac(monster_ac=(10-random(20)));
  if(!monster_ac) monster_ac=-1;
    set_exp(1);
    if(query_hd() < 30) {
        rank = "rookie";
    } else if (query_hd() < 40) {
        rank = "lieutenant";
    } else if(query_hd() < 45) {
        rank = "sergeant";
    } else if(query_hd() < 50) {
        rank = "captain";
    } else {
        rank = "Commander";
    }
    set_long(
    query_cap_name()+" is a "+query("height")+" foot, "+query("weight")+" pound "+query_gender()+
    " member of the Shadow guard. "+capitalize(query_possessive())+" current rank is "+rank+". "+
    "Wearing standard equipment of the shadow guard, "+query_subjective()+" guards the city gates and key locations "+
    "of Shadow with "+query_possessive()+" fellow guardsmen, attempting to enforce Shadow law."
        );

    restore_monster();
    init_attack();

    new("/d/common/obj/armour/chain")->move(TO);
    command("wear armor");
    new("/d/common/obj/armour/coif")->move(TO);
    command("wear coif");
    new("/d/common/obj/weapon/longsword")->move(TO);
    command("wield sword");
    new("/d/common/obj/weapon/dagger")->move(TO);
    command("wield dagger");


}

//moving heart_beat below create.  Shouldn't matter, but since it keeps 
//gagging on race and the first line it shows is ::heart_beat(), what
//can it hurt? Circe 6/18/05
void heart_beat(){
    ::heart_beat();

    if(!objectp(TO) ) {
        return;
    }
}

void restore_monster() {
  ::restore_monster();
  if (!monster_ac) {
    set_ac(monster_ac=(10-random(20)));
    if(!monster_ac) monster_ac=-1;
  }
  else {
  set_ac(monster_ac);
  }
}
