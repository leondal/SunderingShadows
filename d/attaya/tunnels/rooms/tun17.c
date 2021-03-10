#include <std.h>
#include <terrain.h>
#include "../tunnel.h"
inherit TUNNELS + "mouthroom";

int hp;

void create() {
  ::create();

  set_exits( ([ "southwest" : TUNNELS + "tun16" ,
	          "east" : TUNNELS + "tun18",
                "south" : TUNNELS + "pit1"]) );

set_trap_functions(({"south",}),({"pit_trap",}),({"south",}));

}


void reset()
{
  ::reset();
}

void enter_room()
{
  if (!present("magicmouth"))
  {
    mouthsay("Don't walk to the south, you will die. There is a bad"
            +" thing there.");
  }
}

int pit_trap(string str)
{
  if (!objectp(TP)||!objectp(TO)){return 0;}
  if("daemon/saving_d"->saving_throw(TP,"rod_staff_wand", -20))
  {
    tell_object(TP, "You jump backwards, just barely avoiding falling"
                   +" into a pit as your foot disappears through a"
                   +" seemingly solid floor!");
    tell_room(TO, TPQCN + " jumps back, barely keeping " + TP->QP
                 +" balance as " + TP->QP + " foot disappears through a"
                 +" seemingly solid floor to the south!",TP);
    return 1;
  }
  else
  {
    tell_object(TP, "You topple forwards as your lead foot disappears"
                   +" underneath you and you fall right through a"
                   +" seemingly solid floor. You just have time to"
                   +" register some nice, pointy spikes at the bottom of"
                   +" the pit before you hit them.");
    tell_room(TO, TPQCN + " topples forwards as " + TP->QP + " lead foot"
                 +" disappears underneath you and you fall right through"
                 +" a seemingly solid floor to the south!",TP);
    hp = (int)TP->query_max_hp()/6;
    TP->do_damage(TP->return_target_limb(),random(hp));
    TP->add_attacker(TO);
    TP->continue_attack();
    if(objectp(TP))    TP->remove_attacker(TO);
    if(!TP->query_ghost())
    {
      TP->move(find_object_or_load(TUNNELS + "pit1"));
    }
    return 1;
  }
}