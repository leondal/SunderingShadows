#include <std.h>
#include <terrain.h>
#include "../tunnel.h"
inherit ROOM;

void fall();
void fall2(object ob);
void do_damage(object ob);

void create() {
  ::create();
  set_name("A long fall");
  set_short("A long fall");
  set_long("You are tumbling through a black rock tunnel!");
  set_items( ([ 
 ({ "wall", "walls"}):"%^BOLD%^%^BLACK%^The walls are of black slate"
                     +". They are smooth, and damp with condensation",
  

   ]) );
  set_terrain(NAT_CAVE);
  set_travel(SLICK_FLOOR);
}


void fall()
{
  if (TP->query_true_invis())
  {
    tell_object(TP,"Being immortal, you transport yourself unharmed to"
                  +" the end of the fall.");
    TP->move(TUNNELS+"ugstream");
    return;
  }
  if (!TP->is_player())
  {
    return 1;
  }
  tell_object(TP, "You bounce and crash against the rocks on the way down"
                 +" as the water rushes past you!");
  tell_room(TO,TPQCN+ " bounces and crashes against the rocks!",TP);
  do_damage(TP);
  call_out("fall2",1,TP);
  return 1;
}

void fall2(object ob)
{
  if (!objectp(ob)){return;}
  if (ob->query_ghost()){return;}
  switch(random(5))
  {
  case 0:
    tell_object(ob, "You hit your head on a large rock!");
    tell_room(TO,ob->query_cap_name() + " hits " + ob->QP + " head!",ob);
    do_damage(ob);
    break;
  case 1:
    tell_object(ob, "You bounce against the side of the chute!");
    tell_room(TO,ob->query_cap_name() + " bounces against the side of the"
                +" chute!",ob);
    do_damage(ob);
    break;
  case 2:
    tell_object(ob, "You start to drown!");
    tell_room(TO,ob->query_cap_name() + " chokes and gurgles!");
    do_damage(ob);
    break;
  case 3:
    tell_object(ob, "You are smashed against the side by the torrent of"
                   +" water");
    tell_room(TO,ob->query_cap_name() + " is smashed against the side by"
                +" the torrent of water!",ob);
    do_damage(ob);
    break;
  case 4:
    
    tell_object(ob, "You tumble out of the chute, onto the floor of a"
                   +" large underground cavern");
    tell_room(TO, ob->query_cap_name() + " tumbles out of the bottom of"
                 +" the rocky chute");
    do_damage(ob);
    ob->move(find_object_or_load(TUNNELS+"ugstream"));
    ob->force_me("look");
    return;
  }
  call_out("fall2",1,ob);
}

 void do_damage(object ob)
{
  int hp;
  if (!objectp(ob)){return;}
  hp = (int)ob->query_max_hp()/9;
  ob->do_damage(ob->return_target_limb(),random(hp));
  ob->add_attacker(TO);
  ob->continue_attack();
  if(objectp(ob))    ob->remove_attacker(TO);

}