#include "/d/dagger/aketon/short.h"
#include <daemons.h>

void repeat();

inherit DAEMONROOM;

void create() {
   ::create();
    set_property("light",2);
   set_short("On the barrack opens");
   set_long("%^BOLD%^%^RED%^On the barrack opens%^RESET%^
You are on an open area within the barracks of the Aketon military. "
      "There are soldiers marching in double file. Some are practicing "
       "with others using weapons or hand-to-hand combat. There are many "
      "kinds of weapons and armours left on the floor for the soldiers to "
      "choose from. A large structure is by the side of this open area. "
      "A large sign is hanging over the doorway of that building.");
   set_items( (["area":"This is an open area in the barracks here for the "
      "soldiers to practice their different combat skills.",
      "barracks":"The barracks is large and occupied the whole level of "
      "the tree.",
      "soldiers":"There are quite a number of them here, some marching, "
      "some practicing with each other and some are repairing weapons and "
      "armours.",
      ({"weapons","armours"}):"These weapons and armours are left on the "
      "floor on purpose for the soldiers to choose from for practicing.",
      "floor":"Lots of scratchings by metals are observable.",
      "structure":"A large building at the side of the open area.",
         "sign":"It reads: Headquarters of the cavalry"]) );
    set_smell("default","You smell the blood of soldiers who were wounded during "
       "practice.");
    set_listen("default","You hear the sound of weapons clashing against armour.");
   set_exits( (["northeast":RPATH1+"1two12",
      "southwest":RPATH1+"1two1"]) );
   set_pre_exit_functions( ({"northeast"}),({"northeast_func"}) );
}

int northeast_func() {
   object obj;
   if( obj = present("standing guard") ) {
      if( (int)SAVE_D->is_member("aketon_list",TPQN) == -1 ) {
         obj->force_me("say What are your business here? You are not "
            "a citizen of our city, you are not allowed to go in there! ");
         return 0;
      }
      else {
         obj->force_me("say Welcome "+TPQCN+"! All citizens are welcomed "
            "to visit our leaders.");
         return 1;
      }
   }
   return 1;
}

void reset() {
   ::reset();
   repeat();
}

void repeat() {
   object obj;
   if( present("akesold 4") && random(2) )
      return;
   if( present("akesold 5") )
      return;
   switch( random(5) ) {
      case 0:
         obj = new(MPATH+"guardD");
         obj->add_id("akesold");
         obj->move(TO);
         break;
      case 1:
         obj = new(MPATH+"infantry");
         obj->add_id("akesold");
         obj->move(TO);
         break;
      case 2:
         obj = new(MPATH+"archer");
         obj->add_id("akesold");
         obj->move(TO);
         break;
      case 3:
         obj = new(MPATH+"scout");
         obj->add_id("akesold");
         obj->move(TO);
         break;
      case 4:
         obj = new(MPATH+"cavalry");
         obj->add_id("akesold");
         obj->move(TO);
         break;
   }
   repeat();
}
