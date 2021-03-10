#include "/d/dagger/aketon/short.h"
#include <daemons.h>

inherit MONSTER;

void create(){
   ::create();
   set_name("siacz");
   set_id( ({"siacz","bureaucrat","revenue bureaucrat","offical"}) );
   set("short","Siacz the revenue bureaucrat");
   set("long","This beautiful elf with pointing ears, blue eyes and olive "
      "skin looks towards you. She is the official here in the Aketon "
      "Revenue who's in charge of all registration of new citizens. You "
      "will need her approval to be an officially registered citizen of "
       "this city. Then you can enjoy the many benefits of Aketon's elven "
      "civilizations.");
   set("race","elf");
   set_gender("female");
   set_class("thief");
   set_hd(20,8);
   set_hp(200);
   set_exp(500);
   set_body_type("human");
}

void init(){
   ::init();
   add_action("register_func","register");
}

int register_func() {
   if( (string)TP->query_race() != "elf" ) {
      command("say Only elves can register as an offical citizen of this "
         "city, be gone!");
      notify_fail("Siacz returns to her business.\n");
      return 0;
   }
   else if( (int)SAVE_D->is_member("aketon_list",TPQN) != -1 ) {
      command("say You are already a registered citizen of this city.");
      return 1;
   }
   else if( !TP->query_funds("gold",20000) ) {
      command("say I'm sorry, You need 20000 gold to register yourself.");
      notify_fail("Siacz returns to her business.\n");
      return 0;
   }
   else {
      ETO->add_citizen(TPQN);
      TP->use_funds("gold",20000);
      command("say Welcome to the city of Aketon "+TPQCN+". You can enjoy "
         "full citizenship of this city now.");
      return 1;
   }
}
