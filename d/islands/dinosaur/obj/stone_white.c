#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_name("banish stone");
    if(random(3))
      set_property("magic", 1);
    set_short("%^BOLD%^A small bright white stone%^RESET%^");
    set_id( ({"stone", "white stone", "small white stone", "bright white stone", "small bright white stone"}) );
    set_long(
      "This small rounded bright white stone shines slightly when you look at it."
    );
    set_weight(2);
    set_value(20);
}

void init(){
    ::init();
    add_action("throw", "throw");
}

int throw(string str){
    int i, flag;
    object *inv;

    if(!str || str != "stone") return notify_fail("throw what?\n");

    if(!query_property("magic")){
      tell_object(TP, "You smash the small white stone into pieces on the ground.");
      tell_room(ETP, TPQCN+" smashes the small white stone into pieces on the ground.");
      TO->remove();
      return 1;
    }

    tell_object(TP, "You throw the small %^BOLD%^white%^RESET%^ stone at the ground as hard as you can, breaking it on the ground!");
    tell_room(ETP, ""+TPQCN+" throws a small %^BOLD%^white%^RESET%^ rock at the ground, breaking it into pieces!", ({TP}) );


    tell_room(ETP, "%^BOLD%^%^YELLOW%^As the rock shatters, there is a burst of light as a rainbow colored light jumps from the broken rock and starts flying around the room!");

    inv = all_inventory(environment(TP));
    flag = 0;

    for(i=0;i<sizeof(inv);i++){
      if(living(inv[i]) && (inv[i]->is_class("cleric") || inv[i]->is_class("ranger") || inv[i]->is_class("paladin") || inv[i]->is_class("antipaladin") ) ){
        if(!random(3)){
          tell_room(ETP, "%^BOLD%^The rainbows enter "+inv[i]->query_cap_name()+"'s soul!", ({inv[i]}) );
          tell_object(inv[i], "%^BOLD%^The rainbows enter your soul, pulling your god's spells from you!");
          inv[i]->forget_all_cl_spells();
          flag = 1;
        }
      }
    }
    tell_room(ETP, "%^BOLD%^%^YELLOW%^The rainbows leave the room.");
    if(!flag) tell_room(ETP, "Unfortunately, nothing has happened");
    TO->remove();
    return 1;
}
