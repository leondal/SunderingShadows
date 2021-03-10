#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>

inherit MONSTER;
create (){
  ::create ();
  set_name("Duntar");
  set_id(({
  "squad leader","leader","horseman","torm squad leader","duntar"
  }));
  set_property("swarm",1);
  set_short("Duntar, Torm squad leader");
  set_long(
  "Duntar is the captain of these troops, he looks down at you from his"+
  " horse and seems to be judging you. His horse seems well trained and"+
  " attentive to his commands and a lance with a gleaming head rests in"+
  " his hands. He glances to the west and to the dark forest to the"+
  " south once in awhile as if waiting for something to emerge."
  );
set_property("swarm",1);
set_gender("male");
  set_race("human"); 
set_body_type("human");
set_hd(18,1);
set_size(2);
  set_class("cavalier");
  set_mlevel("cavalier",20);
// added so he can control his horse *Styx*  4/3/05
  set_nwp("riding", 20);
  set_property("full attacks",1);
  set_overall_ac(5);
  set_stats("strength",17);
set_stats("intelligence", 13);
set_stats("dexterity", 17);
set_stats("charisma", 16);
set_stats("wisdom", 10);
set_stats("constitution", 14);
set_alignment(1);
  set_max_hp(random(100)+200);
  set_hp(query_max_hp());
set_exp(3500);
set("aggressive", 0);
set_emotes(5, ({"%^BOLD%^You shall never defeat the Forces of Good!!"}), 1);
add_money("gold", 50 + random(100));
  call_out("do_horse",1);
  new(OBJ"Mlance+1.c")->move(TO);
  command("wield lance");
  new(OBJ"torm_scalemail.c")->move(TO);
  new(OPATH"Mcoif.c")->move(TO);
  new(OBJ"torm_shield.c")->move(TO);
 command("wearall");
set_funcs( ({"slice"}) );
  set_func_chance(15);
}

void do_horse(){
  object horse;
  if(!objectp(ETO)) return;
  horse=new("/d/dagger/Torm/mon/ghorse.c");
  horse->set_owner(TO);
  horse->move(ETO);
 command("mount horse");
}

void slice(object targ){
     if(!targ) return 0;
     if(random(25) > targ->query_stats("dexterity")){
  tell_room(environment(targ),"The squad leader plunges his lance into "+targ->query_cap_name()+"s chest!",targ);
  tell_object(targ,"The squad leader plunges his lance into your chest!");
  targ->do_damage("torso",random(15)+10);
     return 1;

     } else {

  tell_object(targ,"The squad leader attemps to plunge his lance into your chest but you dodge out of the way!");
  tell_room(environment(targ),"The squad leader attemps to plunge his lance into "+targ->query_cap_name()+"s chest but he dodges out of the way!",targ);
}
}
int kill_ob(object victim, int which){
 int hold;
  hold= ::kill_ob(victim,which);
  if(hold){
  command("sic "+victim->query_name());
  }
return hold;
}

void heart_beat(){
  ::heart_beat();
  if(!objectp(TO))return;
  if(!objectp(ETO))return;
  if(!present("lance",TO)){
    if(!present("sword",TO)){
      new("/d/dagger/Torm/obj/Mlong+2.c")->move(TO);
      present("sword",TO)->set_property("monsterweapon",1);
      command("wield sword");
      tell_room(ETO,"The squad leader draws his sword to continue to fight!");
    }
  }
}
