#include <std.h>
#include "/d/islands/dinosaur/short.h"
#define LIMBS ({"right foot", "left foot", "right leg", "left leg", "right arm", "left arm", "head", "torso"})
#define MOB_TYPES ({"frog", "cat", "dog", "horse", "elephant", "fish", "lizard"})

inherit MONSTER;

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
    string temp, gtype;
    string lng;
    int i;

    lmbs = str;
    lng = "This mishapen creature looks like it once was human.  Now you can see a monstrosity of body parts including";
    set_body_type("humanoid");
    for(i=0;i<sizeof(lmbs);i++){
      remove_limb(lmbs[i]);
      gtype = MOB_TYPES[random(sizeof(MOB_TYPES))];
      temp = gtype+"'s "+lmbs[i];
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
    set_gender("male");
    set_race("mongrelman");
    set_size(2);
    set_max_hp(275+random(100));
    set_hp(query_max_hp());
    set_exp(4500);
    set_alignment(6);
    set_property("swarm",1);
    add_money("platinum", roll_dice(2,10));
    add_money("gold", roll_dice(10,10));
    set_moving(1);
    set_speed(10);
    switch(random(3)) {
      case 0:
        new(OPATH "horn.c")->move(TO);
        new(OPATH "tooth.c")->move(TO);
        command("wield horn");
        command("wield tooth");
        break;
      case 1:
        new(OPATH "ispear.c")->move(TO);
        command("wield spear");
        new(OPATH "ishield.c")->move(TO);
        command("wear shield");
        set_property("full attacks", 1);
        break;
      default:
        new(OPATH "sling.c")->move(TO);
        command("wield sling");
        break;
    }
    set_property("add kits",20);
}

int free_movement() { return 1; }
