#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit MAZE;

int hp;

void create() {
  ::create();

set_trap_functions(({"south",}),({"pit_trap",}),({"south",}));

}

void reset()
{
  ::reset();
}


int pit_trap(string str)
{
  if (!objectp(TP)||!objectp(TO)){return 0;}
  if("daemon/saving_d"->saving_throw(TP,"rod_staff_wand", -20))
  {
    tell_object(TP, "You jump backwards, just barely avoiding falling"
                   +" into a pit as a massive flagstone tilts and flips"
                   +" under your feet");
    tell_room(TO, TPQCN + " jumps back, barely keeping " + TP->QP
                 +" balance as a massive flagstone tilts and flips under"
                 +" " + TP->QP + " feet",TP);
    return 1;
  }
  else
  {
    tell_object(TP, "You topple forwards as a massive flagstone flips and"
                   +" tilts underneath your feet. Empty space opens up"
                   +" beneath you and as you fall, the slab slams closed"
                   +"once more above your head.");
    tell_room(TO, TPQCN + " topples forwards as a massive flagstone flips"
                 +" and tilts underneath" + TP->QP + " feet. Empty space"
                 +" opens up beneath " + TP->QO + " and as " + TP->QS 
                 +" disappears, the slab slams closed once more above "
                 + TP->QO + ", sealing the way shut.",TP);
    hp = (int)TP->query_max_hp()/4;
    TP->cause_typed_damage(TP, TP->return_target_limb(), roll_dice(1, hp / 2) + hp / 2, "bludgeoning");
    TP->add_attacker(TO);
    TP->continue_attack();
    if(objectp(TP))    TP->remove_attacker(TO);
    if(!TP->query_ghost())
    {
      TP->move(find_object_or_load(LOW_MAZE+1));
    }
    return 1;
  }
}