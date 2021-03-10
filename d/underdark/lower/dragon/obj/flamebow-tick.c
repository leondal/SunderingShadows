#include <std.h>
#include <magic.h>
inherit OBJECT;

object mytarg;
void finish_me();

void create() {
   ::create();
   set_name("flamebow-obj");
   set("id", ({ "flamebow-obj"}) );
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
//     mytarg->do_damage("torso",roll_dice(3,10)); //making this typed damage now
     mytarg->cause_typed_damage(mytarg, mytarg->return_target_limb(),roll_dice(3,10),"fire");
     tell_object(mytarg,"%^BOLD%^%^WHITE%^Finally after an agonizing few seconds, the searing flame dissipates from your skin!%^RESET%^");
     tell_room(environment(mytarg),"%^BOLD%^%^WHITE%^Finally after an agonizing few seconds, the searing flame dissipates from "+mytarg->QCN+"'s skin!%^RESET%^");
   }
   TO->remove();
}

int drop() { return 1; }
int save_me(string file) { return 1; }
int is_detectable() { return 0; }
int query_invis() { return 1; }