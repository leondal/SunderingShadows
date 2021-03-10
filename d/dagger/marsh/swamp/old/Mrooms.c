//mod by Styx 5/3/02 - only allow reset 1/3 time and only spawn if users init

#include <std.h>
#define MPATH "/d/dagger/marsh/swamp/mon/"+

int Gmademonsters;
int rea, wra, cal, ban, ist;

object rand_marsh_mon();
int xp_additions();

inherit ROOM;

void create(){
    ::create();
    Gmademonsters = 0;

}

void init(){
    int num, num2, i;
    int addxp;
    int j;
    object *peo;
    object *mobs;
    ::init();
    mobs = allocate(5);
    rea = 0;
    wra = 0;
    cal = 0;
    ban = 0;
    ist = 0;
    
    if(!userp(TP)) return;  // don't let wandering mobs cause more to spawn
    if(Gmademonsters) return;  //moved up to check this first for efficiency
    if(present("calf")) return;
    if(present("reaver")) return;
    if(present("banshee")) return;
    if(present("wraith")) return;
    if(present("istvan")) return;

    Gmademonsters++;

    if(random(100) > 65) return;

    // Get a random number of monsters, weighted to be lower.
    num = random(4) + 1;
    num2 = random(4) + 1;
    if(num2 < num) num = num2;

    if(num<3 && !random(12)){
      // If 2 or less mons, there's a chance for Istvan, and maybe a friend.
      mobs[0] = new(MPATH "uncle.c");
      ist++;
      if(num>1){
        mobs[1] = rand_marsh_mon();
      }
    } else {
      // If Istvan's not around, get other monsters.
      for(i=0;i<num;i++){
        mobs[i] = rand_marsh_mon();
      }
    }

    // Okay, we have an array full of mob objects, we gotta move them
    //   to the room, and see who's gonna attack.
    //   There is an XP bonus depending on what monsters are in the party.

    addxp = xp_additions();
    for(i=0;i<sizeof(mobs);i++){
      if(!objectp(mobs[i])) continue;
      mobs[i]->add_exp(addxp);
      if(!random(3)) mobs[i]->set_property("no rush",1);
      mobs[i]->move(TO);
      if(!random(15)){
        peo=all_living(TO);
        for(j=0;j<sizeof(peo);j++){
          if(interactive(peo[j]) && !random(15)) mobs[i]->force_me("kill "+peo[j]->query_name());
        }
      }
    }

}

void reset(){
    ::reset();
    if(!random(3)) 
       Gmademonsters = 0;
}

object rand_marsh_mon(){
    int i;
    object ob;

//  Make 'i' out of 100 and change the case statements, and monsters can be weighted on a percentage and not just purely random.
    i = random(4);
    switch(i){
      case 0:
        ob = new(MPATH "reaver.c");
        rea++;
        break;
      case 1:
        ob = new(MPATH "bog.c");
        wra++;
        break;
      case 2:
        ob = new(MPATH "banshee.c");
        ban++;
        break;
      case 3:
        ob = new(MPATH "calf.c");
        cal++;
        break;
    }
    return ob;
}

int xp_additions(){
    int temp;

    //  Single monster gets no bonus.
    if( (ban+rea+wra+cal+ist)<2 ) return 0;

    // Banshees alone are wusses
    if(ban && !rea && !wra && !cal && !ist) {
      return ban*750;
    }
    // But in a party their paralyze gets to be nasty.
    temp += cal*750;
    temp += wra*1000;
    temp += ban*1750;
    temp += rea*2000;
    temp += ist*1500;
    return temp;
}
