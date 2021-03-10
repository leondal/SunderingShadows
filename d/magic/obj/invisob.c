#include <std.h>
inherit OBJECT;

int move_ok, prof;

//this player init message
//this players environment init message
/**
 * Default invisibility messages
 */
mapping messages = (["tpim":"%^BOLD%^%^BLUE%^A dark mist swirls about, wrapping itself around you, concealing your form from view.\n%^CYAN%^Type <appear> to become visible again.",
                     "tpeim":"%^BOLD%^%^BLUE%^A dark mist swirls about, wrapping itself around, concealing from view.",
                     "tpdm":"%^YELLOW%^A dark mist hisses and fizzles as it sprays off your skin, unveiling you to view.",
                     "tpedm":"%^BOLD%^%^BLUE%^From an indiscernible point in the air before you, a dark mist hisses and fizzles as it sprays from it, and below it."]);

int go_vis();
void show_up();

void create() {
   ::create();
   set_name("invisob");
   set("id", ({ "invisobx999"}) );
   set("short", "");
   set("long", "");
   set_weight(0);
   set_property("no animate",1);
   set_heart_beat(2);
}

/**
 * Public method to set invis object's appear/disappear messages
 */
void set_message(string mt, string msg){
    messages[mt]=msg;
}

void set_prof(int x){
    prof = x;
}

void init() {
   ::init();
   if(living(environment(TO)) && TP==environment(TO) ) {
      if(TO->query_property("spell")) {
         tell_object(TP,messages["tpim"]);
         if(TP->query_invis()) {
            TO->remove();
            return;
         }
         tell_room(environment(TP),messages["tpeim"],TP);
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
   cloaker=environment(TO);
   if(!cloaker) {
      TO->remove();
      return;
   }
   if(!cloaker->query_magic_hidden()) {
      TO->remove();
      return;
   }
   tell_object(cloaker,messages["tpdm"]);
   tell_room(environment(cloaker),messages["tpedm"],
             cloaker);
   cloaker->set_magic_hidden(0);
   TO->remove();
   return;
}

void heart_beat(){
   object caster;
   if (TO->query_property("spell")) {
      caster = TO->query_property("spell")->query_caster();

   }
   if (!objectp(caster)) {
      show_up();
   }
   if (caster->query_unconscious()) {
      go_vis();
   }
   caster->increment_stamina(6 - prof/33);
   if(caster->query_condition_percent()<5)
       go_vis();
}

void move(mixed dest) {
   if(!objectp(TO)) return;
   if(!objectp(dest)) return 1;
   if(!move_ok && interactive(dest))
      return 1;
   else {
      if(!objectp(ETO)) return ::move(dest);
      if( !interactive(dest) && interactive(environment(TO)) ) {
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
   cloaker=environment(TO);
   if( !environment(TO) )
      go_vis();
   if( !living(environment(TO)) ||
       !TO->query_property("spell") ||
       !environment(TO)->query_invis() ||
       (object *)environment(TO)->query_attackers() != ({}) ) {
      go_vis();
      return;
   }
   if (cloaker->query_magic_hidden()) {
       if (prof < random(100)) {
        cloaker->set_magic_hidden(0);
       }
   } else {
       if (prof > random(100)) {
           cloaker->set_magic_hidden(1);
       }
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
