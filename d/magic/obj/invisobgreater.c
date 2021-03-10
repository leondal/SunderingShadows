
#include <std.h>
#define TYPES ({"ring","bracer","clothing","leather"})
inherit OBJECT;
object current_room;

string name;
object player;
object spell;
int mychance;
void set_player_name(string str);
void set_mychance(int mychance);
int query_mychance();
void dest_fun();

void set_player_name(string str) {
   name = str;
   player = find_player(name);
   spell = PO;
}
void create() {
   int score;
   ::create();
   set_id( ({"completely random id "+random(32),"TSR80"}) );
   set_name(" ");
   set("short", " ");
   set_weight(0);
   set_property("no animate",1);

   name = "-1";
}
void init() {
   ::init();
   if(!objectp(TO)) return;
   if(!objectp(player)) return;
   if(name != "-1") {
      if(environment(TO) != player) {
         if(player->query_magic_hidden())
            player->set_magic_hidden(0);
         TO->remove();
      }
      TP->set_magic_hidden(1);
      current_room=environment(player);
      add_action("cancel_inv","step");
      call_out("test_invis",5);
   }
}

int cancel_inv() {
   if(player->query_magic_hidden())
      player->set_magic_hidden(0);
   tell_object(player,"You become visible again.");
   call_out("dest_fun",1);
   return 1;
}

void dest_fun() {
   if(objectp(spell)) spell->dest_effect();
   remove_call_out("test_invis");
   remove();
}

void test_invis() {
   int i,j,flag;
   object *armour;

   if(!objectp(player)) return;
/*   if(sizeof(player->query_attackers()))
      cancel_inv(); */
   if(environment(player)!=current_room) {
      if(random(query_mychance())){
         current_room = environment(player);
      } else {
         cancel_inv();
      }
   }
   call_out("test_invis",2);
}

void set_mychance(int x){
   mychance = x;
}

int query_mychance(){
   if(!mychance) mychance = 5;
   return mychance;
}

void remove() {
   if(objectp(player) && player->query_magic_hidden(0)) {
      player->set_magic_hidden(0);
      player->force_me("save");
   }
   return ::remove();
}
int save_me(string file) {return 0;}
int query_invis() { return 1; }
