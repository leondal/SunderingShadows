#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_name("banish stone");
    if(random(3))
      set_property("magic", 1);
    set_short("%^BLUE%^A small black stone");
    set_id( ({"stone", "black stone", "small black stone"}) );
    set_long(
      "This small rounded black stone shines slightly when you look at it."
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
      tell_object(TP, "You smash the small black rock into pieces on the ground.");
      tell_room(ETP, TPQCN+" smashes the small black rock into pieces on the ground.");
      TO->remove();
      return 1;
    }

    tell_object(TP, "%^BOLD%^You throw the small %^BLUE%^black%^RESET%^%^BOLD%^ stone at the ground as hard as you can, breaking it on the ground!");
    tell_room(ETP, "%^BOLD%^"+TPQCN+" throws a small %^BLUE%^black%^RESET%^%^BOLD%^ rock at the ground, breaking it into pieces!", ({TP}) );


    tell_room(ETP, "%^BOLD%^%^YELLOW%^As the rock shatters, there is a burst of light as a rainbow colored light jumps from the broken rock and starts flying around the room!");

    inv = all_inventory(environment(TP));
    flag = 0;

    for(i=0;i<sizeof(inv);i++){
      if( (living(inv[i]) && !interactive(inv[i])) &&
          ( inv[i]->id("summoned monster") ||
            ( inv[i]->id("elemental") && inv[i]->query_property("spell") )
          )
      ){
        if(random(5)){
          tell_room(ETP, "%^BOLD%^The rainbows enter "+inv[i]->query_short()+", leaving behind a pile of dust.");
          inv[i]->remove();
          new("/realms/pegasus/shops/items/dust.c")->move( environment(TP));
          flag = 1;
        }
      }
    }
    tell_room(ETP, "%^BOLD%^%^YELLOW%^The rainbows leave the room.");
    if(!flag) tell_room(ETP, "Unfortunately, nothing has happened");
    TO->remove();
    return 1;
}
