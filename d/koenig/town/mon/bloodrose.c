//The inherit for the various color bushes.  Moved to this dir. from Pegasus'
//directory and made changes to (try at least) to fix bugs.  *Styx*  3/13/02

#include <std.h>
inherit WEAPONLESS;

//void set_body(string type);

void create() {
  ::create();
  set_property("weapon resistance", 1);
  set_name("bloodrose");
  set_id( ({"bloodrose", "rosebush", "yellow bloodrose", "bush"}) );
  set_short("Yellow Bloodrose Bush");
  set_long("A beautiful yellow rose bush with some of its blossoms in full bloom
while others are still in bud.  Odd how it has little veins of pale red in it.");
  set_race("rosebush");
  set_body_type("snake");
  set_gender("female");
  set_size(2);
  set_hd(10, 10);
  set_max_hp(90);
  set_hp(90);
  set_new_exp(10, "normal");
  set_stats("strength", 18);
  set_stats("constitution", 12);
  set_stats("dexterity", 15);
  set_stats("wisdom", 5);
  set_stats("intelligence", 2);
  set_stats("charisma", 16);
  set_overall_ac(8);
  set("aggressive", 20);
      remove_limb("tail");
      remove_limb("mouth");
      remove_limb("torso");
//      add_limb("head", "FATAL", 30, 30, 10);
      add_limb("stem", "FATAL", 40, 40, 10);
      add_limb("substem 1", "stem", 30, 30, 10);
      add_limb("substem 2", "stem", 30, 30, 10);
      add_limb("branch 1", "substem 1", 20, 20, 10);
      add_limb("branch 2", "substem 1", 20, 20, 10);
      add_limb("branch 3", "substem 1", 20, 20, 10);
      add_limb("branch 4", "substem 2", 20, 20, 10);
      add_limb("branch 5", "substem 2", 20, 20, 10);
      add_limb("branch 6", "substem 2", 20, 20, 10);
      add_limb("bud 1", "branch 1", 10, 10, 10);
      add_limb("bud 2", "branch 2", 10, 10, 10);
      add_limb("bud 3", "branch 3", 10, 10, 10);
      add_limb("bud 4", "branch 4", 10, 10, 10);
      add_limb("bloom 1", "branch 5", 10, 10, 10);
      add_limb("bloom 2", "branch 6", 10, 10, 10);
      add_limb("tendril 1", "bud 1", 20, 20, 10);
      add_limb("tendril 2", "bud 1", 20, 20, 10);
      add_limb("tendril 3", "bud 2", 20, 20, 10);
      add_limb("tendril 4", "bud 2", 20, 20, 10);
      add_limb("tendril 5", "bud 3", 20, 20, 10);
      add_limb("tendril 6", "bud 3", 20, 20, 10);
      add_limb("tendril 7", "bud 4", 20, 20, 10);
      add_limb("tendril 8", "bud 4", 20, 20, 10);
      add_limb("tendril 9", "branch 1", 20, 20, 10);
      add_limb("tendril 10", "branch 2", 20, 20, 10);
      add_limb("tendril 11", "branch 3", 20, 20, 10);
      add_limb("tendril 12", "branch 4", 20, 20, 10);
      add_limb("roots", "stem", 30, 30, 10);
    set_wielding_limbs( ({"tendril 1", "tendril 2", "tendril 3", "tendril 4",
"tendril 5", "tendril 6", "tendril 7", "tendril 8", "tendril 9", "tendril 10",
"tendril 11", "tendril 12"}) );
  set_funcs( ({"embrace"}) );
  set_func_chance(75);
}
/* using weaponless and moving into create
void set_body(string type) {
  switch( type )   {
    case "bloodrose": add_limb("head", "FATAL", 30, 30, 10);
                      add_limb("stem", "FATAL", 40, 40, 10);
                      add_limb("substem 1", "stem", 30, 30, 10);
                      add_limb("substem 2", "stem", 30, 30, 10);
                      add_limb("bloom 1", "substem 1", 20, 20, 10);
                      add_limb("bloom 2", "substem 2", 20, 20, 10);
                      add_limb("branch 1", "substem 1", 20, 20, 10);
                      add_limb("branch 2", "substem 1", 20, 20, 10);
                      add_limb("branch 3", "substem 1", 20, 20, 10);
                      add_limb("branch 4", "substem 2", 20, 20, 10);
                      add_limb("branch 5", "substem 2", 20, 20, 10);
                      add_limb("branch 6", "substem 2", 20, 20, 10);
                      add_limb("bud 1", "branch 1", 10, 10, 10);
                      add_limb("bud 2", "branch 2", 10, 10, 10);
                      add_limb("bud 3", "branch 3", 10, 10, 10);
                      add_limb("bud 4", "branch 4", 10, 10, 10);
                      add_limb("bud 5", "branch 5", 10, 10, 10);
                      add_limb("bud 6", "branch 6", 10, 10, 10);
                      add_limb("tendril 1", "bud 1", 20, 20, 10);
                      add_limb("tendril 2", "bud 1", 20, 20, 10);
                      add_limb("tendril 3", "bud 2", 20, 20, 10);
                      add_limb("tendril 4", "bud 2", 20, 20, 10);
                      add_limb("tendril 5", "bud 3", 20, 20, 10);
                      add_limb("tendril 6", "bud 3", 20, 20, 10);
                      add_limb("tendril 7", "bud 4", 20, 20, 10);
                      add_limb("tendril 8", "bud 4", 20, 20, 10);
                      add_limb("tendril 9", "bud 5", 20, 20, 10);
                      add_limb("tendril 10", "bud 5", 20, 20, 10);
                      add_limb("tendril 11", "bud 6", 20, 20, 10);
                      add_limb("tendril 12", "bud 6", 20, 20, 10);
                      add_limb("roots", "stem", 30, 30, 10);
// Don't need wielding limbs, just attack limbs
add_wielding_limb("tendril 1");
             add_wielding_limb("tendril 2");
             add_wielding_limb("tendril 3");
             add_wielding_limb("tendril 4");
             add_wielding_limb("tendril 5");
             add_wielding_limb("tendril 6");
             add_wielding_limb("tendril 7");
             add_wielding_limb("tendril 8");
             add_wielding_limb("tendril 9");
             add_wielding_limb("tendril 10");
             add_wielding_limb("tendril 11");
             add_wielding_limb("tendril 12");
             break;
  }
}
*/

void embrace(object targ) {
  if(!targ) return;
  tell_room(environment(targ),"Tendrils lash out at "+targ->query_cap_name()+" "
  "from the beautiful rose bush, its thorns easily slicing the flesh and "
  "letting the blood flow freely onto the ground near its roots.", targ);
   tell_object(targ,"Tendrils lash out from the beautiful rose bush at you, "
      "its thorns slicing through your flesh with ease and letting your blood "
      "flow freely onto the ground near its roots!", targ);
    targ->do_damage("torso", random(20)+5);
    targ->add_attacker(TO);
    targ->continue_attack();
//    targ->remove_attacker(TO);
//The remove_attacker was stopping combat, prompting bug reports.
//removed by Circe 12/20/04
    targ->set_paralyzed(random(5),"You are temporarily paralyzed by the pain.");
  return;
}
/*  Not sure why this was there since it doesn't carry anything and this object is the bush not whatever it would kill.
void die(mixed ob) {
   	object *contents;
   	int i;

   	contents = all_inventory(this_object());
   	for(i=0;i<sizeof(contents);i++) contents[i]->remove();
   	if(TO->query_property("riding"))
     	(TO->query_owner())->remove_pet(TO);
   	remove();

}
*/