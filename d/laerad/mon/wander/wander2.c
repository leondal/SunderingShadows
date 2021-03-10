//wander code for laerad

#include <std.h>
#include <move.h>

inherit MONSTER;

int count;

void create(){
    ::create();
    call_out("start_wonder",1);
}

void start_wonder(){
    if(objectp(ETO))
        environment(TO)->init();
}

varargs void move_player(mixed dest, string message) {
   object prev;
   string here,going,temp1,temp2,temp3;
   prev = environment(this_object());
   here = file_name(prev);
   if (stringp(dest)) {
     if (sscanf(dest,"/%s",temp1)!=1) {
       sscanf(here,"/%s",temp1);
       going = "";
       while(sscanf(temp1,"%s/%s",temp2,temp3)==2) {
         going = going + "/"+temp2;
         temp1 = temp3;
       }
       temp1 = dest;
       if (file_size(going+"/"+temp1+".c") != -1) {
         dest = going+"/"+temp1;
       }
     }
   }
    if(move(dest) == MOVE_OK){
    }
}

void move_around() {
    string *exits;
    if(!this_object()) return;
    if(environment(this_object()))
      exits = (string*)environment(this_object())->query_exits();
    else exits = 0;
    if(exits) command(exits[random(sizeof(exits))]);
    moving=0;
}

void set_moving(int i) { moving = i; }
void set_speed(int i) { speed = i; }

void heart_beat(){
    string *exits, exitn;
    int i,j;
    ::heart_beat();
    if(!objectp(TO) || !objectp(ETO)) return;

    if(count > 10){
      exits = environment(TO)->query_exits();

      i = sizeof(exits);
      if(exits && i){
        j = random(i);
        exitn = (string)environment(TO)->query_exit(exits[j]);
        TO->force_me(exits[j]);
      }
      count = 0;
    }
    count++;
}
