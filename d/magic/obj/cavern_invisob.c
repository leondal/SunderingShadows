#include <std.h>
inherit OBJECT;

int move_ok, prof;

int go_vis();
void show_up();

#define val_terrains ({"desert rocks","rocky","old mounts","new mounts","ruins","stone building","nat cave","built cave","nat tunnel","built tunnel"})

void create() {
   ::create();
   set_name("invisob");
   set_id(({"invisobx999"}));
   set("short", "");
   set("long", "");
   set_weight(0);
   set_property("no animate",1);
   set_heart_beat(2);
}

void set_prof(int x){
    prof = x;
}

void init() {
   ::init();
   if(living(environment(TO)) && TP==environment(TO) ) {
      if(TO->query_property("spell")) {
         tell_object(TP,"%^BOLD%^%^BLACK%^You are slowly absorbed "+
            "into the stone, hiding you from view of outsiders.  "+
            "Type <appear> if you'd like to step out.%^RESET%^");
         if(TP->query_invis()) {
            TO->remove();
            return;
         }
         tell_room(EETO,"%^BOLD%^%^BLACK%^"+TPQCN+" disappears "+
            "into the stone as you watch.%^RESET%^",TP);
         TP->set_magic_hidden(1);;
         add_action("go_vis","appear");
         call_out("check_attacks",2);
      } else {
         show_up();
      }
   }
}

int go_vis() {
   if(TO->query_property("spell"))
      TO->query_property("spell")->dest_effect();
   else
      show_up();
   return 1;
}

void show_up() {
   object cloaker;
   cloaker=ETO;
   if(!cloaker) {
      TO->remove();
      return;
   }
   if(!cloaker->query_magic_hidden()) {
      TO->remove();
      return;
   }
   tell_object(cloaker,"%^BOLD%^You slip out from the stone, "+
      "appearing in the room before all eyes.%^RESET%^");
   tell_room(environment(cloaker),"%^BOLD%^"+cloaker->QCN+" suddenly "+
      "slips out from the stone and appears in view!",cloaker);
   cloaker->set_magic_hidden(0);
   TO->remove();
   return;
}

void heart_beat(){
   object caster;
   string mytype = EETO->query_terrain();
   if (TO->query_property("spell")) {
      caster = TO->query_property("spell")->query_caster();

   }
   if (!objectp(caster)) {
      show_up();
   }
   if (caster->query_unconscious()) {
      go_vis();
   }
   if(member_array(mytype,val_terrains) == -1){
       tell_object(caster,"You step out of the rocky surroundings.");
       go_vis();
   }
   caster->increment_stamina(3);
}

void move(mixed dest) {
   if(!objectp(TO)) return;
   if(!objectp(dest)) return 1;
   if(!move_ok && interactive(dest))
      return 1;
   else {
      if(!objectp(ETO)) return ::move(dest);
      if( !interactive(dest) && interactive(ETO) ) {
         go_vis();
         return 1;
      }
      return ::move(dest);
   }
}

void move_is_ok(int a) {
   move_ok=a;
   return 1;
}

void check_attacks() {

   object cloaker;
   cloaker=ETO;
   if( !ETO )
      go_vis();
   if( !living(ETO) ||
       !TO->query_property("spell") ||
       !ETO->query_invis() ||
       (object *)ETO->query_attackers() != ({}) ) {
      go_vis();
      return;
   }
   call_out("check_attacks",2);
   return;
}

int drop() {
   return 1;
}

int save_me(string file) {
   return 1;
}

int is_detectable() { return 0; }
int query_invis() { return 1; }
