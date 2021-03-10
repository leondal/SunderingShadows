
#include <std.h>
#include <daemons.h>
#include "/d/stella/short.h"

inherit OBJECT;
int item, searched;

void init(){
	::init();
	add_action("search_func","search");
	}
	
void create(){
	::create();

      	set_name("SuperNova_Remnant");
	set_id(({"remnant","supernova remnant"}));
        set_short("%^YELLOW%^A Supernova Remnant%^RESET%^");
        set_long("It is a strange glowing shell of gas and dust.  "
		 "There appears to be something in the center!");
	set_weight(100000);
	set_value(100000);
	searched=0;
	}

int search_func(string str){

       if (!str){
	  notify_fail("You find nothing odd.\n");
	  return 0;
	}
	if ((str != "remnant")&&(str != "supernova remnant")){
	  notify_fail("You find nothing odd.\n");
	  return 0;
	}
	if (!searched){
	  item = random(11)+1;
	}

	switch(item) {
	case 1:
	case 2:
	  tell_object(TP,"You search the supernova remnant and find a black hole "
		"in the center!");
	  say(TPQCN+" investigates the center of the Supernova Remnant",TP);
          set_long("It is a strange glowing shell of gas and dust.  In the center "
		   "there is a black hole.  The black hole is a dark area in the "
		   "center from which no light escapes.");
	  searched = 1;
	  return 1;
	case 3:
	case 4:
	  tell_object(TP,"You search the supernova remnant and find a quasar "
		"in the center!");
	  say(TPQCN+" investigates the center of the Supernova Remnant",TP);
          set_long("It is a strange glowing shell of gas and dust.  In the center, "
		   "you see a very tiny but bright point source.  Somehow you know "
		   "that it emits a great deal of radio energy.");
	  searched = 1;
	  return 1;
	case 5:
	case 6:
          tell_object(TP,"You search the supernova remnant and find a pulsar "
                "in the center!");
          say(TPQCN+" investigates the center of the Supernova Remnant",TP);
          set_long("It is a strange glowing shell of gas and dust.  In the center, "
		   "you see a small star that pulses brighter and fainter.  It "
		   "appears to be spinning really quickly!");
          searched = 1;
          return 1;
	case 7:
	case 8:
	  tell_object(TP,"You search the supernova remnant and find a white dwarf star "
		"in the center!");
	  say(TPQCN+" investigates the center of the Supernova Remnant",TP);
          set_long("It is a strange glowing shell of gas and dust.  In the center, "
		   "there is a white dwarf.  It is a small, faint, nondescript star.");
	  searched = 1;
	  return 1;
	case 9:
	case 10:
	  if (searched) {
	    tell_object(TP,"You find nothing more.");
	    return 1;
	  }
	  tell_object(TP,"You search the supernova remnant and find a sparkling diamond "
		"in the center!");
	  say(TPQCN+" investigates the center of the Supernova Remnant",TP);
          set_long("It is a strange glowing shell of gas and dust.  The center is empty "
		   "now.");
	  new(OPATH "gem.c")->move(TP);
	  searched = 1;
	  return 1;
	case 11:
	  if (searched) {
	    tell_object(TP,"You find nothing more.");
	    return 1;
	  }
	  tell_object(TP,"You search the supernova remnant and find an opal bracelet "
		"in the center!");
	  say(TPQCN+" investigates the center of the Supernova Remnant",TP);
          set_long("It is a strange glowing shell of gas and dust.  The center is empty "
		   "now.");
	  new(OPATH "opal.c")->move(TP);
	  searched = 1;
	  return 1;
	}
      }


