#include <std.h>
#include <magic.h>
inherit OBJECT;

object mytarg;
void finish_me();

void create() {
   ::create();
   set_name("choking-dust-obj");
   set("id", ({ "choking-dust-obj"}) );
   set("short", "");
   set("long", "");
   set_weight(0);
   set_property("no animate",1);
}

void init() {
   ::init();
   if(living(environment(TO)) && TP==environment(TO) ) {
      TP->set_static("spell interrupt","%^CYAN%^You're still choking on the cloud of dust!%^RESET%^");
      TP->set_property("spell interrupt","%^CYAN%^You're still choking on the cloud of dust!%^RESET%^");
      call_out("finish_me",ROUND_LENGTH*2);
      mytarg = TP;
   }
   else finish_me();
}

void finish_me() {
   if(!objectp(TO)) return;
   if(objectp(mytarg)) {
     mytarg->set_static("spell interrupt",0);
     mytarg->remove_property("spell interrupt");
   }
   TO->remove();
}

int drop() { return 1; }
int save_me(string file) { return 1; }
int is_detectable() { return 0; }
int query_invis() { return 1; }