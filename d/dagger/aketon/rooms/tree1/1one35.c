#include "/d/dagger/aketon/short.h"
#include <daemons.h>

inherit ROOM;

void create() {
   ::create();
   set_short("%^BOLD%^Aketon Revenue%^RESET%^");
   set_long("%^BOLD%^Aketon Revenue%^RESET%^
This large building is known as the revenue bureau of the elven city of "
      "Aketon. Citizens of Aketon come here to pay their taxes. Tax is "
      "the main source of income of the Aketon government. The money "
      "collected here will be transferred to the treasury of Aketon for "
      "various city expenses. The building is made entirely of wood. A "
      "large counter is over the western side of the place. Behind it "
      "sits several clerks busy with the citizens. A few citizens are "
      "here lining up a queue before the counter.\nThere is a large sign "
      "hanging on the wall beside the counter.");
   set_items( (["counter":"The counter is quite long and several clerks "
      "sit behind it",
      "clerks":"They are busy with citizens here and money they payed.",
      ({"building","place"}):"A large wooden structure sitting on one of "
      "the main branches of the Aketon trees.",
      "citizens":"Some simple citizens of Aketon.",
      "sign":"A sign with some words written on it, perhaps you should "
      "read it."]) );
   set_property("light",2);
   set_property("indoors",1);
   set_smell("default","You smell the odour of money.");
   set_listen("default","You hear muttering about citizens complaining "
      "the high taxes.");
   set_exits( (["west":RPATH1+"1one34"]) );
}

void init() {
   ::init();
   add_action("read_func","read");
}

int read_func(string str) {
   if(str != "sign") {
      notify_fail("Read what?");
      return 0;
   }
   else {
      tell_object(TP,"Elven citizens come here to pay tax to the Aketon "
         "government. If you are an outsider and wants to be a citizen of "
         "this great city, you need to <register> yourself first when the "
         "offical is here.");
      return 1;
   }
}

int add_citizen(string str) {
   SAVE_D->set_value("aketon_list",str);
}

void reset() {
   ::reset();
   if( !present("siacz") )
      new(MPATH+"siacz")->move(TO);
}
