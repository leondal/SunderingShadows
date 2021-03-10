#include <std.h>

#define SAVEFILE "/d/save/darts_list"

inherit OBJECT;

string *masters;

void add_master(string str);
void remove_master(string str);
string query_masters();

void create() {
   ::create();
   set_name("list of mastery in darts");
   set_short("List of Mastery in Darts");
   set_long("This is a list of people who ever achieved mastery in the game "
      "of darts in the realms of ShadowGate. On this wooden board you can "
      "see names of people who was long disappeared and living people who "
      "are still venturing all around the known realms and exploring unknown "
      "worlds. You eager to read the list to see if your name is on it!");
   set_id( ({"list","mastery list","darts list","list of darts"}) );
   set_weight(100000);
   set_property("no animate",1);
   set_property("no offer",1);
   set_value(0);
   masters = ({});
   restore_object(SAVEFILE);
}

void init() {
   ::init();
   add_action("read_func","read");
   restore_object(SAVEFILE);
}

int read_func(string str) {
   int i;
   restore_object(SAVEFILE);
   if(member_array(str,query_id()) != -1) {
      write("%^BLUE%^Masters of darts of "+mud_name()+" as of "+
         hour(time())+":"+minutes(time())+" on "+month(time())+" "+date(time())+
         ","+year(time())+" NM:");
      for(i=0;i<sizeof(masters);i++) {
         write(capitalize(masters[i]));
      }
      save_object(SAVEFILE);
      return 1;
   }
   return 0;
}

void add_master(string str) {
   if(!masters) masters = ({});
   if(!str) return;
   if(member_array(str,masters) != -1) return;;
   masters += ({str});
   save_object(SAVEFILE);
   return;
}

void remove_master(string str) {
   if(!masters) masters = ({});
   if(member_array(str,masters) == -1) return;
   masters -= ({str});
   save_object(SAVEFILE);
   return;
}

string query_masters() {
   return masters;
}
