#include <std.h>
#include <magic.h>
inherit OBJECT;

object mytarg;
void finish_me();

void create() {
   ::create();
   set_name("dreambow-obj");
   set("id", ({ "dreambow-obj"}) );
   set("short", "");
   set("long", "");
   set_weight(0);
   set_property("no animate",1);
}

void init() {
   ::init();
   mytarg = TP;
   call_out("finish_me",ROUND_LENGTH);
}

void finish_me() {
   if(!objectp(TO)) return;
   if(objectp(mytarg)) {
     mytarg->do_damage("torso",roll_dice(3,10));
     tell_object(mytarg,"%^GREEN%^The last of the acid finally dissipates, bringing some relief.%^RESET%^");
     tell_room(environment(mytarg),"%^RESET%^%^GREEN%^At last "+mytarg->QCN+" looks relieved as the acid fades away.%^RESET%^",mytarg);
   }
   TO->remove();
}

int drop() { return 1; }
int save_me(string file) { return 1; }
int is_detectable() { return 0; }
int query_invis() { return 1; }