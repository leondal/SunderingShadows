#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit MONSTER;
int ok_contents(object ob);

void create(){
    object ob;
    ::create();
    set_name("guardian");
    set_id( ({"guard", "tent guard", "guardian"}) );
    set_short("Tent Guard");
    set_long(
      "This tall man is clothed completely in a cloak from head to toe, keeping you from being able to see any part of his body, except for one yellow eye, and one hand sticking out from under the cloak, holding a long spear."
    );
    set_race("mongrelman");
    set_gender("male");
    set_body_type("humanoid");
    set_hd(30, 1);
    set_class("fighter");
    set_mlevel("fighter", 30);
    set_max_hp(300);
    set_hp(query_max_hp());
    set_exp(5);
    ob = new("/d/islands/dinosaur/obj/ispear.c");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    ob = new("/d/islands/dinosaur/obj/ishield.c");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wear shield");
    command("wield spear");
    set_speed(5);
    set_moving(1);
}

void die(object targ){
    object ob;

    if(ob = present("tent", ETO)) {
      ob->remove();
      DINO_D->dead_healer();
    }
    ::die(targ);
}

void move_around(){
    object ob, ob2;

    ob = present("tent", ETO);
    ob2 = find_object_or_load("/d/islands/dinosaur/healer.c");
    if(!ok_contents(ob2)){
      return;
    }
    if(objectp(ob)){
      tell_room(ETO, "The healer suddenly steps out of the tent, and wanders into the woods.");
      tell_room(ETO, "The guard folds up the tent.");
      ob2->remove_exit("down");
      ob->move("/d/islands/dinosaur/empty_room.c");
      ::move_around();
      ob->move(ETO);
      ob2->add_exit(base_name(ETO), "out");
      tell_room(ETO, "The guard sets up the tent.");
      tell_object(ETO, "The healer wanders in from the woods, and enters the tent.");
    } else {
      tell_room(ETO, "The guard suddenly takes off running.");
      TO->move("/d/shadowgate/void.c");
      destall(TO);
      TO->remove();
    }
    return;
}

int ok_contents(object ob){
    int i;
    object *inv;
    int flag = 1;

    inv = all_living(ob);
    for(i=0;i<sizeof(inv);i++){
      if(inv[i]->query_property("Gflagprop")) continue;
      else flag = 0;
    }
    return flag;
}

int free_movement() { return 1; }
