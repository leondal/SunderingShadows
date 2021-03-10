#include "/d/dagger/road/short.h"
/* converting to use std move_around with new set_nogo() *Styx* 12/12/03, last change 5/02
     #define NOGO ({"/d/dagger/cave2/cave2.c", "/d/dagger/cave2/cave106.c"})
   adding cave22 to cover the one down exit, enter is all cracks on an add_action
*/


// int okExit(string exit);

inherit MONSTER;

void create(){
    ::create();
    set_moving(1);
    set_speed(80);
    set_nogo( ({"/d/dagger/cave2/cave2", "/d/dagger/cave2/cave106", "/d/dagger/cave2/cave22", "/d/dagger/cave2/cave13"}) );

}

/*
void move_around() {
    string *exits;
    string exit;

    if(!this_object()) return;
    if(!objectp(ETO)) return;
    ETO->setupExits();
    if(query_current_attacker()) return;
    if(environment(this_object()))
      exits = (string *)environment(this_object())->query_exits();
    else
      exits = 0;
    if(sizeof(exits)){
      exit = exits[random(sizeof(exits))];
      (environment(this_object())->query_exit(exit))->init();
      if(okExit(exit))
        command(exit);
    }
    moving = 0;
}

int okExit(string exit){
    string filename;

    if(exit == "enter") return 0;
    if(exit == "down") return 0;

    filename = environment(this_object())->query_exit(exit);
    if(member_array(filename, NOGO) != -1) return 0;
    return 1;
}
*/
