#include "/d/dagger/road/short.h"

#define ROADEND "/d/dagger/road/road2b"
#define TONOVI1 "/d/dagger/tonovi/1path1"
#define TONOVI2 "/d/dagger/tonovi/2path1"
#define TORM "/d/dagger/Torm/road/path1"
#define DALE1 "/d/dagger/Daggerdale/gates/Wgate"
#define DALE2 "/d/dagger/Daggerdale/gates/Ngate"
#define DALE3 "/d/dagger/Daggerdale/gates/Egate"
#define D_MARSH "/d/dagger/marsh/marsh1"
#define KINARO "/d/dagger/kinaro/path1"
#define ELEMENTS "/d/dagger/elements/path/path1"
#define AKETON "/d/dagger/aketon/path/path1"
#define KEEP "/d/dagger/keep/road/road5"
#define SOLAREN "/d/player_houses/solaren/solaren1"
#define STELLA "/d/dagger/road/stella/sroad5"
#define NOGO ({ROADEND, TONOVI1, TONOVI2, TORM, DALE1, DALE2, DALE3, D_MARSH, KINARO, ELEMENTS, AKETON, KEEP, STELLA, SOLAREN})

int okExit(string exit);
inherit MONSTER;

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

    if(exit == "temple") return 0;

    filename = environment(this_object())->query_exit(exit);
    if(member_array(filename, NOGO) != -1) return 0;
    return 1;
}
