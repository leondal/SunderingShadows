#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit ROOM;

int flag, mobs;
string what;

void rush_hit(object ob);

void create(){
    ::create();
   set_terrain(DENSE_JUNGLE);
   set_climate("tropical");
   set_travel(FRESH_BLAZE);
   set_light(2);
}

void init() {
    if(flag) {
      reset();
      flag = 0;
    }
    ::init();
}

void reset(){
    string *str, dir;
    int i;

    ::reset();
    if(!random(10) && !present("dino")) {
// this will at least let new traps get set and mobs added eventually in case it gets cleaned out and the rooms don't unload in the meantime.  *Styx*  5/10/03
	TO->clear_all_traps();
	mobs = 0;
    }
// added check for traps so it wouldn't wipe hints about traps already set *Styx* 5/10/03
    if((mapping)TO->query_traps() == ({}) )
      set_items( ([
        "ferns" : "The green ferns are much larger than any you remember.",
        "path" : "The path here seems to be made by large reptillian feet.",
      ]) );

    if(!pointerp(TO->query_exits()) || !sizeof(TO->query_exits()) ) {
      flag = 1;
      return;
    }

    if(!present("dino")) {
      if(!random(3)) {
        switch(random(120)) {

        case 5..19:
          if((mapping)TO->query_traps() != ({}) ) // added to keep from adding more once set *Styx* 
		break;
          str = (string *)TO->query_exits();
          dir = str[random(sizeof(str))];
          set_trap_functions(({dir}),({"deino"}),({dir}));
          add_item("trees", "As you look at the trees to the "+dir+", you can see an intricate trap that has been laid that would cause several caged dinosaurs to spring at you.");
          what = "deino&"+dir;
          break;

        case 20..34:
          if((mapping)TO->query_traps() != ({}) )  // added to keep from adding more once set *Styx*
		break;
          str = (string *)TO->query_exits();
          dir = str[random(sizeof(str))];
          set_trap_functions(({dir}),({"tric"}),({dir}));
          set_listen("default", "You can hear something crashing through the trees to the "+dir+".");
          add_item("ground", "You can see a thin wire on the ground.  The wire leads off to the "+dir+".");
          what = "tric&"+dir;
          break;

        case 35..49:
          if((mapping)TO->query_traps() != ({}) )  // added to keep from adding more once set *Styx*
		break;
          str = (string *)TO->query_exits();
          dir = str[random(sizeof(str))];
          set_trap_functions(({dir}),({"tyrano"}),({dir}));
          add_item("ground", "There is a large footprint in the ground here.  It looks like whatever made it was headed "+dir+" recently");
          add_item("footprint", "Ummm, that belongs to a T-Rex.");
          what = "tyrano&"+dir;
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


int deino(){
    string verb;
    object *tmp, *mobs, *inv, ob;
    int i, num;

    verb = query_verb();

    if(TP->query_invis()) return 0;
    if(TP->free_movement()) return 0;

    tell_room(TO, "As "+TPQCN+" moves north, the bushes suddenly explode in a fury of claws and teeth as a pack of Deinonychus strike!", TP);
    tell_object(TP, "As you move north, suddenly a pack of Deinonychus attacks from the bushes!");

    num = roll_dice(2,2);
    mobs = ({});
    for(i=0;i<num;i++){
      ob = new(MPATH "deino.c");
      mobs += ({ob});
    }

    inv = all_living(TO);
    inv -= ({TP});
    tmp = ({TP});
    for(i=0;i<sizeof(inv);i++){
      if(!random(4) && !(int)TP->query_invis())
        tmp += ({inv[i]});
    }

    for(i=0;i<sizeof(mobs);i++){
      if(random(4) && sizeof(tmp)){
        ob = tmp[random(sizeof(tmp))];
        tell_object(ob, "A Deinonychus slams into you, raking you with its claws and knocking you to the ground!");
        ob->do_damage("torso", roll_dice(2,10));
        ob->set_paralyzed(30-((int)ob->query_stats("strength")), "You have been knocked to the ground!");
        tmp -= ({ob});
      }
      mobs[i]->move(TO);
      mobs[i]->kill_ob(TP, 0);
    }
    toggle_trap(verb);
    return 1;
}

/*
int tyrano(){
   string verb;
    if(TP->free_movement()) return 0;

    verb = query_verb();

    tell_object(TP, "As you move "+verb+" your foot catches on a root, tripping you forward!");
    tell_object(TP, "You hit your head, and are dazed.");
    TP->set_paralyzed(6, "Your head is spinning");

    tell_room(TO, TPQCN+" trips over a root, and falls, hitting "+TP->query_possessive()+" head and knocking "+TP->query_objective()+"self out.", TP);
    tell_room(TO, "Unfortunately for "+TPQCN+" "+TP->query_subjective()+" fell into the nest of a Tyrannosaurus Rex, and smashed some of the eggs, and woke up some baby T-Rexs.", TP);
    tell_room(TO, "A chill runs down your spine as the cries of the babies call their mama to the nest.  A great roar can be heard over the jungle, and a crashing sound can be heard coming your way!", TP);

    toggle_trap(verb);
    call_out("mama", 5, TP);
    return 1;
}

int mama(object tp){
    object ob;

    tell_object(tp, "You shake your head and wake up to find yourself lying in the nest of a Tyrannosaurus Rex, and having smashed some egggs!  Mama's not gonna be happy about this, speaking of which, as you look over your shoulder...  there she is!!");
    ob = new(MPATH "tyrano.c");
    ob->move(TO);
    ob->set_gender("female");
    ob->force_me("roar");
    return 1;
}
*/

int tyrano(){
    string verb;
    object ob;
    if(TP->free_movement()) return 0;
    verb = query_verb();
    tell_object(TP, "As you move "+verb+" you run face first into a very large very clawed foot of a Tyrannosaurus.");
      toggle_trap(verb);
    ob = new(MPATH "tyrano.c");
    ob->move(TO);
    ob->force_me("roar");
    return 1;
}

int tric(){
string verb;

    if(TP->free_movement()) return 0;

    verb = query_verb();

    tell_object(TP, "As you begin to move "+verb+" you hear a great crashing noise from that direction headed towards you!");
    tell_room(TO, "As "+TPQCN+" starts to move "+verb+" you can hear a crashing noise head in your direction from there.", TP);
    toggle_trap(verb);
    call_out("incoming", 2, TP, 1);
    return 1;
}

void incoming(object tp, int count){

    switch(count++){
      case 1:
        tell_room(TO, "%^BOLD%^%^BLUE%^The crashing noise is getting closer.");
        call_out("incoming", 2, tp, count);
        break;
      case 2:
        tell_room(TO, "%^BOLD%^%^BLUE%^The crashing noise is getting closer.  You can hear a rumble in the distance.");
        call_out("incoming", 2, tp, count);
        break;
      case 3:
        tell_room(TO, "%^BOLD%^%^BLUE%^The thunder and crash is deafening, you can see the bushes starting to move!");
        call_out("incoming", 2, tp, count);
        break;
      case 4:
        rush_hit(tp);
        break;
      default:
        tell_room(TO, "Hmm, somthing screwed up.  Mail Grendel.");
    }
}

void rush_hit(object tp){
    object ob;

    tell_room(TO, "%^BOLD%^Suddenly a Triceratops crashes through the bushes!");
      if(present(tp)){
      tell_room(TO, "And it slams into "+tp->query_cap_name()+"!", tp);
      tell_object(tp, "And the Triceratops slams into you!!");
      tp->do_damage("torso", roll_dice(15,8));
      tp->set_paralyzed(8, "The rush has stunned you!");
    }
    ob = new(MPATH "tric.c");
    ob->move(TO);
    ob->force_me("kill "+tp->query_name());
}

string query_long(string str){
    string hold, one, two;

    hold = ::query_long(str);
    if(!what) return hold;
    sscanf(what, "%s&%s",one,two);
    if(!one || !trapped(two)) return hold;

    switch(one){
      case "deino":
        hold += "\nThe bushes seem to shake from time to time.";
        return hold;
        break;
      case "tyrano":
        hold += "\nThe ground here looks strange.";
        return hold;
        break;
      case "tric":
        hold += "\nA gleem on the ground catches your eye.";
        return hold;
      break;
    }
    return hold;
}
