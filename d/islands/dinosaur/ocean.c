#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit ROOM;

int flag, mobs;
object room;

void create(){
    ::create();
   set_terrain(ROCKY);
   set_travel(LEDGE);
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

void reset(){
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
         "water" : "In the water you can see several large moving shapes.",
         "shapes" : "They seem to be, well, large.",
        "cliffs" : "Some of these rocks look like they could give way at any moment.",
      ]) );

    if(!pointerp(TO->query_exits()) || !sizeof(TO->query_exits()) ){
      flag = 1;
      return;
    }

    if(!present("dino")){
      if(!random(4)){
        switch(random(40)){

        case 16..30:
          if((mapping)TO->query_traps() != ({}) ) // added to keep from adding more once set *Styx* 
		break;
          str = (string *)TO->query_exits();
          dir = str[random(sizeof(str))];
          set_trap_functions(({dir}),({"elas"}),({dir}));
          add_item("cliffs", "You can see where dirt was poured on the cliffs to try to hide a strange looking trap.");
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

void elas(){
    string verb;
    object ob;

    if(TP->free_movement()) return 0;

    verb = query_verb();

    tell_room(TO, "As "+TPQCN+" moves "+verb+", the cliffs suddenly crumble under "+TP->query_possessive()+" weight, dropping "+TP->query_objective()+" into the sea!", TP);
    tell_object(TP, "As you walk "+verb+" you footing suddenly disappears and you are tossed into the sea!");

    if(!objectp(room)){
      room = new("/d/islands/dinosaur/elasocean.c");
      room->add_exit(TO->query_exit(verb),"up");
    }
    TP->do_damage("torso", roll_dice(5,10));
    TP->move_player(room);
    return 1;
}
