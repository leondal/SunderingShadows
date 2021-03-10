#include <std.h>
#define LIMBS ({"right foot", "left foot", "right leg", "left leg", "right arm", "left arm", "head", "torso"})
#define MOB_TYPES ({"frog", "cat", "dog", "horse", "elephant", "fish", "lizard"})

inherit WEAPONLESS;

string *my_limbs;

string *choose_limbs(){
    string *lmbs, *lmbs2;
    int xyz, x, i;

    lmbs = ({"right foot", "left foot", "right leg", "left leg", "right arm", "left arm", "head"});
    xyz = 20;
    while(xyz > 5){
      xyz = random(sizeof(lmbs)+1);
    }

    lmbs2 = ({});
    for(i=0;i<xyz;i++){
      x = random(sizeof(lmbs));
      lmbs2 += ({lmbs[x]});
      lmbs -= ({lmbs[x]});
    }

    return lmbs2;
}

void create_mong_body(string *str){
    string *lmbs;
    string temp,type;
    string lng;
    int i;

    lmbs = str;
    lng = "This mishapen creature looks like it once was human.  Now you can see a monstrosity of body parts including";
    set_body_type("humanoid");
    for(i=0;i<sizeof(lmbs);i++){
      remove_limb(lmbs[i]);
      type = MOB_TYPES[random(sizeof(MOB_TYPES))];
      temp = type+"'s "+lmbs[i];
      lng = lng + ", a "+temp+"";
      my_limbs += ({temp});
      add_limb(temp, temp, 0, 0, 0);
    }
    if(!sizeof(lmbs)) lng += " well, it looks completely human.";
    set_long(lng);
}

void create(){
    string *duh;
    ::create();
    my_limbs = ({});
    duh = choose_limbs();
    create_mong_body(duh);
    set_name("mongrelman");
    set_id( ({"mong", "mongrelman", "humanoid", "dino", "mongrel", "man"}) );
    set_short("Mongrelman");
    set_hd(20,1);
    set_exp(4900);
    set_gender("male");
    set_race("mongrelman");
    set_attack_limbs( ({"right hand", "left hand"}) );
    set_size(2);
    set_max_hp(275+random(100));
    set_hp(query_max_hp());
    set_alignment(6);
    set_attacks_num(3);
    set_damage(2,6);
    set_base_damage_type("bludgeoning");
    set_property("swarm",1);
    add_money("platinum", roll_dice(2,10));
    add_money("gold", roll_dice(10,10));
    set_moving(1);
    set_speed(10);
    set_property("add kits",20);
}

int free_movement() { return 1; }
