#include <std.h>
#include <magic.h>
inherit OBJECT;

object mytarg;
void finish_me();

void create() {
   ::create();
   set_name("gleaming-mote-obj");
   set("id", ({ "gleaming-mote-obj"}) );
   set("short", "");
   set("long", "");
   set_weight(0);
   set_property("no animate",1);
   set_heart_beat(1);
}

void init() {
   ::init();
   if(living(environment(TO)) && TP==environment(TO)) {
      TP->set_property("faerie fire",1);
      TP->set_property("added short",({"%^BOLD%^%^YELLOW%^ (sparkling)%^RESET%^"}));
      call_out("finish_me",60); // same as the recharge timer on the bow
      mytarg = TP;
   }
   else finish_me();
}

void finish_me() {
   if(!objectp(TO)) return;
   if(objectp(mytarg)) {
     tell_object(mytarg,"%^YELLOW%^The sparkling dust finally fades from your skin.%^RESET%^");
     tell_room(environment(mytarg),"%^YELLOW%^The sparkling dust finally fades from "+mytarg->QCN+"'s skin.%^RESET%^");
     mytarg->remove_property("faerie fire");
     mytarg->remove_property_value("added short",({"%^BOLD%^%^YELLOW%^ (sparkling)%^RESET%^"}));
   }
   TO->remove();
}

int drop() { return 1; }
int save_me(string file) { return 1; }
int is_detectable() { return 0; }
int query_invis() { return 1; }

void heart_beat(){
    if(!objectp(TO)) return;
    if(!objectp(mytarg)) return;

    if(mytarg->query_invis()) {
      tell_object(mytarg,"%^YELLOW%^The gleaming dust gives away your position!%^RESET%^");
      tell_room(environment(mytarg),"%^YELLOW%^The gleaming dust gives away "+mytarg->QCN+"'s position!",mytarg);
      mytarg->set_invis(0);
    }
}