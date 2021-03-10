#include <std.h>
//Raising the exp per Ares order to increase leveling speed. Dinji 8/14/07
#include "../meadow.h"
inherit MONSTER;

int CALL;

void create()
{
   object ob;
  ::create();
  set_name("wererat");
  set_id(({"wererat","were rat","lycanthrope","monster","ratman","sneaky wererat","monster"}));
  set_short("A sneaky wererat");
  set_long("The wererat stands almost five feet tall with his shoulders"+
  " slightly hunched. He is covered in brownish-black wiry fur and has a"+
  " long pink tail. He has the face of a rat, with red beady eyes, fury"+
  " ears, and whiskers. His arms and hands are still mostly human and he"+
  " wields two short swords. A few tattered remenants of clothing still"+
  " cling to him."
  );
  set_hd(11,5);
  set_race("wererat");
  set_body_type("human");
  set_gender("male");
  set_size(1);
  set("aggressive",25);
  set_property("swarm",1);
  //set_level(14);
  //set_class("ranger");
  //set_mlevel("ranger",14);
  set_hp(random(25)+75);
  set_stats("strength",15 + random(2));
   //set_exp(400);
   set_new_exp(6,"normal");
  set_property("full attacks",1);
  add_limb("tail","torso",0,0,0);
//  set_property("weapon resistance",1);  not appropriate now that it's a lowbie area
  new("/d/common/obj/weapon/shortsword")->move(TO);
  command("wield sword");
  new("/d/common/obj/weapon/dagger")->move(TO);
  command("wield dagger");
  if(!random(2)) {
    new(OBJ+"leather")->move(TO);
    command("wear leather");
  }
  set_overall_ac(6);
  set_funcs(({"call"}));
  set_func_chance(6);
  set_alignment(5);
  add_money("gold",random(100)+50);
  set_max_level(12);
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("werebeast fang");
      ob->move(TO);
    }
}

void call(object targ)
{
  int num,mons;
  object mon;
  mons=random(3)+2;
  if(CALL > 2) return;
  for(num=1;num<=mons;num++)
  {
    mon=new("/d/newbie/rooms/keep/mon/rat");
    mon->move(ETO);
    mon->command("protect wererat");
  }
  tell_room(ETO,"%^YELLOW%^The wererat lifts his head up and "+
	"issues a series of loud squeeks and clicking sounds.\n"+
	"Suddenly, several rats rush out of the surroundings "+
	"to his aid!%^RESET%^");
   CALL += 1;
   return;
}

void reset()
{
   ::reset();
   CALL = 0;
   if(!random(3) && !present("jewelry")) {
      new("/d/antioch/valley/obj/jewelry")->move(TO);
   }
   if(!random(4) && !present("gem")) {
      new("/d/antioch/valley/obj/gem")->move(TO);
   }
}
