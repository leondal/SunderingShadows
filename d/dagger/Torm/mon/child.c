#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
  inherit "/d/dagger/Torm/mon/dayperson.c";
create(){
::create();
  set_name("child");
  set_id(({ "child","small child","playing child" }));
  set_long(
   "  This small girl glows with all the joy of an innocent child."
   "  She is busy playing at the foot of a huge troll and appears oblivious to anything in the world but her playmates.  She couldn't be more than three or four years old, she is still short and has her baby fat, as well as a constant smile and happiness.  %^YELLOW%^Golden curls%^RESET%^%^CYAN%^ frame her face and her eyes are a %^BOLD%^sky blue%^RESET%^%^CYAN%^ color.  Her once pink dress is now a bit covered in dirt and dust, but is still mendable."
  );
  set_short( "A playing child"  );
  set_property("no bows",1);
  set_race("human");
  set_gender("female");
set_body_type("human");
set_emotes(5,({
  "The child laughs and dives after a ball.",
  "The playing child giggles and runs about in a frantic game of tag.",
  }),0);
  set_hd(1,1);
set_max_hp(5);
set_hp(5);
set_overall_ac(10);
set_size(2);
set_stats("strength",12);
set_stats("intelligence",7);
set_stats("dexterity",9);
set_stats("charisma",7);
set_stats("constitution",11);
set_stats("wisdom",8);
set_money("silver",random(100));
set_exp(15);
set("aggressive",5);
set_wielding_limbs( ({"left hand", "right hand"}) );
}
int kill_ob(object victim, int which){
  int hold;
  object ob;
  hold = ::kill_ob(victim, which);
  if(hold){
  command("yell help me please!!");
  }
  return hold;
}
void die(mixed ob){
  object attr;
  TO->set_hp(1);
  command("beserk");
  tell_room(ETO,"Child falls into a bloody heap.");
  attr=TO->query_attackers();
  attr->set_disabled(8);
  TO->set_hp(-10);
  ::die(ob);
}
