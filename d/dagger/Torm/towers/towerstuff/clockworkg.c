#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit WEAPONLESS;
  string type;
  object ob,ob2;
create(){
::create();
  set_name("clockwork gnome");
  set_id(({
  "gnome","clockwork gnome",
  }));
  set_short(
  "%^YELLOW%^Clockwork gnome%^RED%^"
  );
  set_long(
  "  This strange toy looks to be a statue of a little gnome."
  "  It whirrs and hums as it bumps into walls and wanders around in circles."
  "  A large key on it's back turns slowly as it's spring winds down."
  );
  set_race("construct");
  set_gender("male");
set_body_type("human");
  set_hd(1,1);
  set_max_hp(1000);
  set_hp(1000);
set_overall_ac(10);
  set_size(1);
set_stats("strength",12);
set_stats("intelligence",7);
set_stats("dexterity",9);
set_stats("charisma",7);
set_stats("constitution",11);
set_stats("wisdom",8);
set_money("silver",random(100));
set_exp(15);
  set_property("no dominate",1);
  set_property("no death",1);
set_wielding_limbs( ({"left hand", "right hand"}) );
  set_property("weapon resistance",50);
  set_mob_magic_resistance("average");
}
void heart_beat(){
  ::heart_beat();
  if(!objectp(TO) || !objectp(ETO)) return;
  if(query_hp() != 1000){
  TO->set_hp(1000);
  }
  if((object *)TO->query_attackers() != ({})){
  tell_room(ETO,"%^YELLOW%^The gnome ignores his attackers and continues blithly running into walls.");
  new("/d/dagger/Torm/towers/towerstuff/clockworkg.c")->move(ETO);
  TO->move("/d/shadowgate/void.c");
  TO->remove();
  }
  if(present("rubblex",ETO)){
  ob=present("rubblex",ETO);
  ob->do_fix();
  }
}
