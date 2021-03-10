#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit ROOM;

int flag, mobs;

void create(){
    ::create();
   set_terrain(SHORE);
   set_travel(FOOT_PATH);
   set_climate("tropical");
 
    set_light(2);
}

void init(){
    if(flag){
      reset();
      flag = 0;
    }
    ::init();
}

void reset() {
    string *str, dir;
    int i;
    ::reset();
    if(!random(10)) {
// this will at least let new traps get set and mobs added eventually in case it gets cleaned out and the rooms don't unload in the meantime.  *Styx*  5/10/03
	TO->clear_all_traps();
	mobs = 0;
    }
// added check for traps so it wouldn't wipe hints about traps already set *Styx* 5/10/03
    if((mapping)TO->query_traps() == ({}) )
      set_items( ([
        "footprints" : "These footprints are huge semi-circular prints with bumps where the toes would have been.  Whatever made these is very large and very heavy.",
        "lake" : "The water of the lake looks rather clear.  There is an island in the middle of the lake.",
        "island" : "The island looks to be deserted.",
      ]) );

    if(!pointerp(TO->query_exits()) || !sizeof(TO->query_exits()) ){
      flag = 1;
      return;
    }

    if(!present("dino")){
      if(!random(4)){
        switch(random(100)) {
        case 6..54:
	  if(mobs)
	     break;
          for(i=0;i<(random(2)+1);i++){
            new(MPATH "diplo.c")->move(TO);
          }
	  mobs = 1;
          break;
        case 55..64:
          if((mapping)TO->query_traps() != ({}) ) // added to keep from adding more once set *Styx* 
		break;
          str = (string *)TO->query_exits();
          dir = str[random(sizeof(str))];
          set_trap_functions(({dir}),({"diplo"}),({dir}));
          add_item("ground", "You can see where a dinosaur has made a nest here.");
          add_item("nest", "This nest contains Diplodocus eggs.");
          break;
        default:
	  if(!mobs)  // added to keep from overpopulating in longer reboots
             DINO_D->dino_party(TO);
	  mobs = 1;  // more of the the population control
	  // this will let it continue to have chances to add traps but not keep adding mobs when the original ones may have wandered off and still be alive. 
        }
      }
    }
}

/*
int diplo(){
    string verb;


    verb = query_verb();

    tell_object(TP, "As you move "+verb+" your foot catches on a root, tripping you forward!");
    tell_object(TP, "As you move "+verb+" your foot catches on a root, tripping you forward!");
    tell_object(TP, "You hit your head, and are dazed.");
    TP->set_paralyzed(6, "Your head is spinning");

tell_room(TO, TPQCN+" trips over a root, and falls, hitting "+TP->query_possessive()+" head and knocking "+TP->query_objective()+"self out.", TP);
    tell_room(TO, "Unfortunately for "+TPQCN+" "+TP->query_subjective()+" fell into the nest of a Diplodocus, and smashed some of the eggs, and woke up some baby Diplodoci.", TP);
    tell_room(TO, "A chill runs down your spine as the cries of the babies call their mama to the nest.  A great bellow can be heard over the jungle, and a crashing sound can be heard coming your way!", TP);

    toggle_trap(verb);
    call_out("mama", 5, TP);
    return 1;
}

int mama(object tp){

    object ob;

    tell_object(tp, "You shake your head and wake up to find yourself lying in the nest of a Diplodocus, and having smashed some egggs!  Mama's not gonna be happy about this, speaking of which, as you look over your shoulder...  there she is!!");
    ob = new(MPATH "diplo.c");
    ob->move(TO);
    ob->set_gender("female");
    ob->force_me("emote bellows");
    ob->force_me("kill "+tp->query_name());
    return 1;
}
*/

int diplo(){
    string verb;
    object ob;

    if(TP->free_movement()) return 0;

    verb = query_verb();
    tell_object(TP, "As you walk through the swamp, you hear the sickening sound of your foot crunching eggs.");
    tell_object(TP, "You then hear the more sickening sound of the mother of the eggs coming to find out what happened.");
    tell_room(ETP, TPQCN+" turns a very pale white just before you hear a large crashing headed your way.", TP);
    ob = new(MPATH "diplo.c");
    toggle_trap(verb);
    ob->move(TO);
    ob->set_gender("female");
    ob->force_me("emote bellows");
    ob->force_me("kill "+TP->query_name());
    return 1;
}
