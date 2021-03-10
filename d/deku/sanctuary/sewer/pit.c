#include <std.h>
#include "../dragon.h";

inherit BSEWER;
int mob;
int items;
object ob;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long(
      "%^BOLD%^%^BLACK%^This pit is one of the draining areas for the sewers."+
      " All the water in this region of the sewers flow down into this pit and"+
      " out out to sea through an underwater tunnel. This area is chest high in"+
      " disgusting sewage and smells awful."
    );
    set_exits(([
       "up" : SEWER+"sewer20"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary.",
       "water":"The water comes up to your chest and smells awful.",
       "walls":"The walls are covered fungus and are starting to decay from all the water.",
       ({"floor","ground","bottom"}):"You can not see the ground you are standing on, but can feel something down there."
    ] ));
    set_search("default","There is not much here except a lot of water.");
    set_search("water","The water is murky and full of disgusting waste.");
    set_search("walls","The walls are slimey and starting to decay.");
    set_search("floor","There is definately something on the bottom.");
    set_search("ground","There is definately something on the bottom.");
    set_search("bottom", (: TO, "searching" :) );
    items = 1;
    mob = 1;
}

void searching() {
   object ob;
   if(!mob) {
      if(!items) {
        write("You do not find anything.");
        return;
      }
      switch(random(5)){
         case 0:
         ob = new(OBJ+"boots")->move(TO);
         tell_room(ETP, "%^BOLD%^%^BLUE%^"+TPQCN+" finds some boots on the bottom of the pit.",TP);
         tell_object(TP, "%^BOLD%^%^BLUE%^You find some boots on the bottom of the pit.");
         break;
         case 1:
         ob = new(OBJ+"warmring")->move(TO);
         tell_room(ETP, "%^BOLD%^%^YELLOW%^"+TPQCN+" finds a ring on the bottom of the pit.",TP);
         tell_object(TP, "%^BOLD%^%^YELLOW%^You find a ring on the bottom of the pit.");
         break;
         case 2:
         ob = new(OBJ+"weatherring")->move(TO);
         tell_room(ETP, "%^BOLD%^%^WHITE%^"+TPQCN+" finds a ring on the bottom of the pit.",TP);
         tell_object(TP, "%^BOLD%^%^WHITE%^You find a ring on the bottom of the pit.");
         break;
         case 3:
         ob = new(OBJ+"coralsword")->move(TO);
         tell_room(ETP,"%^RESET%^%^MAGENTA%^"+TPQCN+" finds a large sword on the bottom of the pit.",TP);
         tell_object(TP, "%^RESET%^%^MAGENTA%^You find a large sword on the bottom of the pit.");
         break;
         case 4:
         ob = new(OBJ+"rod")->move(TO);
         tell_room(ETP, "%^BOLD%^%^RED%^"+TPQCN+" finds a rod on the bottom of the pit.",TP);
         tell_object(TP, "%^BOLD%^%^RED%^You find a rod on the bottom of the pit.",TP);
         break;
         }
         items = 0;
         return;
         }
         tell_room(ETP, "%^BOLD%^%^GREEN%^As "+TPQCN+" searches around the bottom, a huge snake snaps to the surface of the water!",TP);
         tell_object(TP, "%^BOLD%^%^GREEN%^As you search around the bottom, a huge snake snaps to the surface of the water!");
         ob = new(MON+"snake")->move(TO);
         mob = 0;
}
