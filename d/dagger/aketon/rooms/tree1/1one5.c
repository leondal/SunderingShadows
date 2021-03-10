#include "/d/dagger/aketon/short.h"
#include <daemons.h>
#include <move.h>

inherit HEALER;

void create() {
   ::create();
   set_short("Wallados' House of Healing");
   set_long("%^BOLD%^Wallados' House of Healing%^RESET%^
The odors of various salves and poultices assault your nose as soon as "
      "you enter. Though the shop seems a bit disorganized, it is "
      "extraordinarily clean. Many patients lie on cots, as Wallados "
      "rushes to tend to them all.");
   set_property("light",3);
   set_property("indoors",1);
   set_smell("default","The strong odor of herbs and balms turns your "
      "stomach.");
   set_listen("default","You hear occasional moans and groans from "
      "Wallados' patients.");
   set_items( (["shop":"This is the place where Wallados attend his "
      "business and take care of his patients.",
      "patients":"They are lying on cots moaning."]) );
   set_exits( (["south":RPATH1+"1one13"]) );
   set_cl_price(30);
   set_cs_price(60);
   set_cc_price(120);
   set_np_price(180);
   set_bp_price(40);
   set_cb_price(220);
   set_name("wallados");
}

int read_list(string str){
   if(str != "list") return 0;
   ::read_list(str);
   write("All prices halved for citizens and tripled for humans.");
   return 1;
}

int cure_light(string str) {
   if( (int)SAVE_D->is_member("aketon_list",TPQN) != -1)
      set_cl_price(15);
   else if( (string)TP->query_race() == "human" )
      set_cl_price(90);
   else
      set_cl_price(30);
   ::cure_light(str);
   set_cl_price(30);
   return 1;
}

int cure_serious(string str) {
   if( (int)SAVE_D->is_member("aketon_list",TPQN) != -1)
      set_cs_price(30);
   else if( (string)TP->query_race() == "human" )
      set_cs_price(180);
   else
      set_cs_price(60);
   ::cure_serious(str);
   set_cs_price(60);
   return 1;
}

int cure_critical(string str) {
   if( (int)SAVE_D->is_member("aketon_list",TPQN) != -1)
      set_cc_price(60);
   else if( (string)TP->query_race() == "human" )
      set_cc_price(360);
   else
      set_cc_price(120);
   ::cure_critical(str);
   set_cc_price(120);
   return 1;
}

int neut_poison(string str) {
   if( (int)SAVE_D->is_member("aketon_list",TPQN) != -1)
      set_np_price(90);
   else if( (string)TP->query_race() == "human" )
      set_np_price(540);
   else
      set_np_price(180);
   ::neut_poison(str);
   set_np_price(180);
   return 1;
}

int buy_potion(string str) {
   if( (int)SAVE_D->is_member("aketon_list",TPQN) != -1)
      set_bp_price(20);
   else if( (string)TP->query_race() == "human" )
      set_bp_price(120);
   else
      set_bp_price(40);
   ::buy_potion(str);
   set_bp_price(40);
   return 1;
}

int cure_blindness(string str){
   if( (int)SAVE_D->is_member("aketon_list",TPQN) != -1)
      set_cb_price(110);
   else if( (string)TP->query_race() == "human" )
      set_cb_price(660);
   else
      set_cb_price(220);
   ::cure_blindness(str);
   set_cb_price(220);
   return 1;
}

void reset() {
   ::reset();
   if( !present("wallados") )
      new(MPATH+"wallados")->move(TO);
}
