#include "/d/dagger/tonovi/town/short.h"
#define USEEX ({"walls"})
string *useable_exits(string *types, object tp);

inherit "/std/monster";

void create(){
    ::create();
    call_out("start_wonder", 2);
}

void start_wonder(){
    if(objectp(ETO))
      ETO->init();
}

void heart_beat(){
    int count, i;
    string *exits;
    ::heart_beat();

    if(!objectp(TO)) return;
    if((mixed *)TO->query_attackers() != ({})) return;
    if( (count > 20) && (objectp(ETO))){
      exits = useable_exits( USEEX, TO);
      i = sizeof(exits);
      if(!exits || !i) return;
      TO->force_me(exits[random(i)]);
      count = 0;
    }
    count++;
}

int test_heart() {return 1;}

string *useable_exits(string *types, object tp){
    string *retn_str;
    int i;
    string exit, *exits;

    retn_str = ({});
    exits = environment(tp)->query_exits();
    for(i=0;i<sizeof(exits);i++){
      exit = environment(tp)->query_exit(exits[i]);
      if(exit->query_room_type()) {
        if(member_array(exit->query_room_type(), types) != -1) {
          retn_str += ({exits[i]});
        }
      }
    }
    return retn_str;
}
