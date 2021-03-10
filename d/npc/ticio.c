inherit "/std/npc";


void create() {
  ::create();

  set_name("ticio");
  set("id", ({"sailor", "a sailor", "the sailor", "ticio","Ticio","ticio the sailor"}) );
  set_short("Ticio the sailor");
  set_long(
@OLI
   Ticio is a burly large fellow who seems to enjoy his shore leave 
from the heaving waves of the Saakrune Sea.  His bushy beard and bushy 
eye brows give him the look of great hairy northman.  His tanned and 
sea worn face, carries the broad smile of several hours of heavy
drinking.  His stained and bleached clothing carries the rips and
scars of sea battles and a rough and tumble life.
OLI
           );
  set_race("human");
  set_gender("male");
//   set_unique(1);  // was bugging the guards, loading master object now instead *Styx* 11/02
  set_body_type("human");
  set_hd(5, 1);
  set_ac(8);
  set_size(2);
  set_max_hp(10);
  set_hp(10);
  set_max_sp(9);
  set_sp(9);
  set_stats("strength", 15);
  set_stats("intelligence", 6);
  set_stats("dexterity", 6);
  set_stats("charisma", 4);
  set_stats("constitution", 11);
  set_stats("wisdom", 5);
  set_money("gold", random(100));
  add_intox(250);
  set_exp(15);
  set_speed(40);
  set_wielding_limbs( ({"left hand", "right hand"}) );
  //set("aggressive", 8);
/* changing to load from Garrett's improved /daemon/monster_d.c to solve clean_up problems & save memory, more flexibility, easier maintenance, etc. *Styx*  3/23/03
     "daemon/place_d"->place_in("/d/shadow/room/city/",);
*/
}
