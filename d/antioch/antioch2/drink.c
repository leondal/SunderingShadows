// DO NOT USE THIS FILE now, inherit /std/drink and set_canSave(1) to make saveable
// *Styx*  12/24/03

///std/drink.c
//from the Nightmare mudlib
//inheritable drink code
//created by Descartes of Borg October 1992

#include <std.h>

inherit "/std/drink.c";

/* getting rid of the redundancy in case something does use it *Styx* 12/24/03
inherit OBJECT;

string my_mess, your_mess;
int poison, healing;

void set_my_mess(string mess);
void set_your_mess(string mess);
void set_empty_name(string str);
void clone_empty(object tp);
void set_strength(int x);
int query_strength();
void set_type(string str);
string query_type();

void init() {
    ::init();
   add_action("drink","drink");
}

void create() {
   ::create();
   set_weight(1);
}

void set_name(string str) {
   set_my_mess("You drink some "+str+".\n");
   set_your_mess("drinks some "+str+".\n");
   set_weight(210);
   ::set_name(str);
}

void set_empty_name(string str) { set("empty name", str); }

void set_strength(int x) {
   set("strength", x);
}

void set_poison(int x){
   poison = x;
 }
  void set_healing(){
    int x;
    x = roll_dice(2,4)+2;
    healing = x;
}
void set_x_healing() {
int x;
x = roll_dice(3,8) + 3;
healing = x;
}

void set_my_mess(string str) {
   my_mess = str;
}

void set_your_mess(string str) {
   your_mess = str;
}

int query_strength() {
   return query("strength");
}

void set_type(string str) { set("type", str); }

string query_type() { return query("type"); }

int drink(string str) {
   if(!id(str)) return 0;
  
   if(environment(this_object()) != this_player()) {
      notify_fail("You must get it first.\n");
      return 0;
   }
   if(query("type") == "soft drink") {
      if(!this_player()->add_quenched(query("strength")*20)) {
         notify_fail("You are too bloated to drink that!\n");
         return 0;
      }
   }
   else if(query("type") == "caffeine") {
      if((int)this_player()->query_intox() < query("strength")) {
         notify_fail("You do not feel the need for that right now.\n");
         return 0;
         }
      if(!this_player()->add_quenched(query("strength")*10)) {
         notify_fail("You are too bloated to drink that!\n");
         return 0;
         }
      this_player()->add_intox(-(query("strength")/2)*10);
   }
   else if(query("type") == "alcoholic") {
      if(!this_player()->add_intox(query("strength")*10)) {
         notify_fail("You are just about to pass out as it is.\n");
         return 0;
         }
   }
   else if(query("type") == "water") {
      if(!this_player()->add_quenched(query("strength")*50)) {
         notify_fail("Your stomach is sloshing already!\n");
         return 0;
         }
   }
  this_player()->heal(healing);
   write(my_mess);
   say(this_player()->query_cap_name()+" "+your_mess, this_player());
   this_player()->add_poison(poison);
   clone_empty(this_player());
   remove();
   return 1;
}

void clone_empty(object tp) {
   object empty;
   string empty_name;
   
   if(!query("empty name")) set("empty name", "bottle");
   empty_name = query("empty name");
   empty = new("std/Object");
   empty->set_short("An empty "+empty_name);
   empty->set_long("A "+empty_name+" which used to hold something.\n");
   empty->set_id( ({ empty_name, query_short(), "empty container" }) );
  empty->set_value(0);
    empty->set_weight(5);
   empty->set_destroy(1);
   empty->move(tp);
}
*/