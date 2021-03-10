//Moved Thorby one room north, made him move around, and not repop every time
//Added elven ranger leader, increase delay to 600 from 500   *Styx*  3/24/02
//changed the wandering guards to the crow soldiers for yuki
// hades 9/1/11

#include "/d/dagger/road/short.h"

#define ELF "/d/dagger/road/mon/elranger.c"
//#define GUARD "/d/dagger/road/mon/wanguard1.c"
#define GUARD "/d/player_houses/yuki/mobs/crow_soldier.c"
#define THORBY "/d/dagger/road/mon/thorby.c"
#define RANGER "/d/dagger/road/mon/elranglead.c"
#define ROOMS1 ({"83", "87", "90", "91", "95", "99", "103", "109"})
#define ROOMS2 ({"4", "7", "13", "18", "23", "29", "34", "40"})
#define ROOMS3 ({"45", "49", "81", "88", "92", "96", "105", "107"})
#define THROOM "/d/dagger/road/road41"
#define BASE "/d/dagger/road/road"
#define DELAY 600

int started, ranger;

void do_elf();
void do_guard();
void do_thorby();
void do_rangerlead();

void clean_up() { return; }

int startup() {
    seteuid(getuid(TO));
    if(started) return 2;
    started = 1;
    do_elf();
    do_guard();
    do_thorby(); 
    do_rangerlead(); 
    call_out("check_mobs", DELAY);
    return 1;
}

void check_mobs(){

    do_elf();
    do_guard();
    if(!random(3))  do_thorby();
    if(!ranger) { 
       if(!random(3))  do_rangerlead(); 
    }
    call_out("check_mobs", DELAY);
}

void do_elf(){
    int num, numelves, i, j;

    numelves = sizeof(children(ELF))-1;
    num = random(4)+1;

    if(num <= numelves) return;

    num -= numelves;
    for(i=0;i<=num;i++){
      j = random(sizeof(ROOMS1));
      new(ELF)->move(find_object_or_load(BASE+ROOMS1[j]));
    }
}

void do_guard(){
    int num, numguards, i, j;

    //return; // Temporary fix for guards being pulled off dagger road.
    numguards = sizeof(children(GUARD))-1;
    num = random(10)+1;

    if(num <= numguards) return;

    num -= numguards;
    for(i=0;i<=num;i++){
      j = random(sizeof(ROOMS2));
      new(GUARD)->move(find_object_or_load(BASE+ROOMS2[j]));
    }
}

void do_thorby(){
    int num;
    if(!random(3)) return;
    num = sizeof(children(THORBY));
    if(num < 2)
      new(THORBY)->move(find_object_or_load(THROOM));
}

void do_rangerlead(){
    int num, i;
    if(!random(3)) return;
    num = sizeof(children(RANGER));
    if(num < 2) {
       i = random(sizeof(ROOMS3));
       new(RANGER)->move(find_object_or_load(BASE+ROOMS3[i]));
       ranger = 1;
    }
}
