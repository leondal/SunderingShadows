#include <std.h>
inherit "/d/common/obj/weapon/mspear.c";


create() {
   int i;
    ::create();
    set_obvious_short("A medium spear");
    set_short("Ammunition of the atlatl");
    set_id(({"spear","medium spear","atlatl spear"}));
    set_name("A medium spear");
    set_long("A spear that has been flung with an atlatl");
    set_property("enchantment", 1);
    set_value(1000);
}

int throw_hit(object targ){
  object room, thrower;
  if (!objectp(targ)){
    return 0;
  }
  room = environment(targ);
  thrower = ETO;
  if (!objectp(room)||!objectp(thrower)){
    return 0;
  }
  
  if (random (3)>1){
    tell_object(targ, "%^BOLD%^%^RED%^The %^RESET%^" + query_short() 
                     +"%^BOLD%^%^RED%^hits you with such force it knocks"
                     +" you clean off your feet!");
    tell_object(thrower, "%^BOLD%^%^RED%^Great shot! Your " + query_short()
                        +"%^BOLD%^%^RED%^ hits " + targ->query_short() 
                        +"%^BOLD%^%^RED%^ with such force, it knocks " 
                        + targ->QO + " clean off " + targ->QP + " feet!");
    tell_room(room, "%^BOLD%^%^RED%^" + targ->QCN + "%^BOLD%^%^RED%^ is"
                   +" knocked clean off " + targ->QP + " feet by the force"
                   +" of the " + query_short() + " %^BOLD%^%^RED%^slamming"

                   +" into " + targ->QO +"!", targ, thrower);
    targ->set_tripped(random(3) + 3, "%^BOLD%^%^BLUE%^You are winded by"
                        +" the blow and trying to stand.");
   }
} 



