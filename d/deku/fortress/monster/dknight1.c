#include <std.h>

inherit "/std/monster";
int flag;

void create() {
  object obj;
::create();
  set_name("alphonso");
  set_id(({"death knight","knight","alphonso","alphonso jalimpar"}));
  set_race("human");
  set_gender("male");
  set_short("Alphonso Jalimpar");
  set_long("The weathered darkened features of a once handsome and proud human"+
           " can still be seen on Alphonso's face.  His strong jaw line and the"+
           " regal way he holds himself shows that he was once a well bred man.  "+
           "Now his long silver hair takes on a tarnished color.  His skin is an"+
           " ashy gray color.  One alarming feature about him, are his eyes.  "+
           "Black voids with bright blue fires that burn where the eyes once use"+
           " to be. He is dressed in noble finery, down to the elegant blade and"+
           " armor he uses. An overwhelming aura of evil radiates from this man.\n");
  set_level(18);
  set_body_type("human");
  set_class("antipaladin");
  set_alignment(3);
  set_size(2);
  set_hd(18,5);
  set_property("full attacks",1);
  set_stats("strength",19);
  set_stats("charisma", 18);
  set_stats("dexterity",16);
  set_stats("constitution",14);
  set_stats("wisdom",13);
  set_stats("intelligence",9);
  set("aggressive","rush");
  set_property("full attacks",1);
  set_monster_feats(({
            "rush",
        }));        
  set_hp(250);
  set_new_exp(10, "boss");

               // will loose much more if you die.... here :)
  //set_overall_ac(0);
  //set_wielding_limbs(({"right hand","left hand"}));
  obj=new("/d/deku/fortress/obj/majesty_blade")->move(TO);
  command("wield sword");
  new("/d/dagger/Torm/obj/fullplateb")->move(TO);
/*  obj=new("/d/common/obj/rand/rand_shirts");
if(random(3)){
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
I removed the shirt as it no longer stacks with plate.
~Circe~ 1/4/13
*/
  obj=new("/d/tharis/obj/clothing/pants")->move(TO);
  new("/d/shadow/obj/clothing/wolfboots")->move(TO);
  command("wearall");
  add_money("silver",random(100));
  add_money("gold",random(2000));
  set_funcs(({"point"}));
  set_func_chance(10);
  set_property("no animate",1);
  set_property("no death",1);
}

void point(object targ) {
   if(!"/daemon/saving_throw_d.c"->fort_save(targ,-15)){
    tell_room(environment(targ), "The death knight chills "+
        targ->query_cap_name()+" with his fingers.", targ);
    tell_object(targ, "The death knight chills you with his "+
        "fingers.");
     set_property("magic",1);
     targ->cause_typed_damage(targ, "torso", 10000, "cold");
     remove_property("magic");
  return 1;
   }
}

void rush(){
    if(!objectp(TO)) return;
    if(!objectp(TP)) return;
	if(flag == 0) 
    {
	command("say %^RESET%^%^RED%^Time for you to join the ranks of the dead!");
        flag = 1;
	}
    TO->add_attack_bonus(4);
	command("rush "+TPQN);
    TO->add_attack_bonus(-4);
	return;
}

void set_paralyzed(int time, string message){
   return 1;
}

void set_tripped(int severity, string message) {
   return 1;
}
