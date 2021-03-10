#include <std.h>
// psychic for Seneca by Styx
// changed her to load from /daemon/monster_d *Styx* 12/21/03, last change 10/16/02

inherit "/std/psychic.c";

void create(){
   ::create();
   set_nwp("eavesdropping",15,500);
   set_name("Celastral");
   set_short("Celastral");
   set_id(({"Celastral", "celastral", "psychic"}));
   set_long("Celastral looks worn from age or perhaps life in general.  Grey "
	"wisps are sprinkled through her otherwise short, dark brown hair and "
	"her face is lined with wrinkles.  She wears simple priestly garb and "
	"her deepset brown eyes seem to reflect a calm wisdom gained over her "
	"years.  She has retired to this area, supporting herself by charging "
	"adventurers for use of her telepathic ability."
   );
   set_race("human");
   set_gender("female");
   set_hd(25,1);
   set_exp(10);
   set_stats("intelligence",25);
   set_stats("wisdom",25);
   set_body_type("human");
   set_overall_ac(4);
   set_price(150);
   set_speed(60);
   set_nogo( ({ "/d/attaya/seneca3" }) );
//   "daemon/place_d"->place_in("/d/attaya/seneca/",TO);
}

int kill_ob(object who, int i){
   ::kill_ob(who,i);

   force_me( "laugh "+TPQN);
   force_me("emote glares angrily at"+TPQCN+" and concentrates.");
   TP->force_me("emote staggers back and struggles suddenly as "+TP->query_possessive()+" clothing constricts.");
   TP->force_me("emote grabs "+TP->query_possessive()+" head and screams.");
   TP->do_damage("head",random(100));
   TP->force_me("fall");
   TP->set_paralyzed(10,"Your head is pounding!");
   TP->set_bound(50,"Your clothes have tightened, binding you fast.");
   remove_attacker(TP);
}

/* changing to use the set_nogo() too *Styx* 12/21/03
void move_around() {
   string *exits;
   string exitn;
   int j;

   if(!this_object()) return;
   if(!objectp(ETO)) return;
   ETO->setupExits();
   if(query_current_attacker()) return;
   if(environment(this_object()))
      exits = environment(TO)->query_exits();
   if(sizeof(exits)){
      j = random(sizeof(exits));
      exitn = (string)environment(TO)->query_exit(exits[j]);
      if(exitn != "/d/attaya/seneca3") {
         exitn->init();
         TO->force_me(exits[j]);
      }
   }
   moving=0;
}
*/