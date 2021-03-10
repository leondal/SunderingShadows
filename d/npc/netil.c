#include <std.h>
#define SCITY "/d/shadow/room/city/"

inherit "/std/psychic.c";

void create(){
   ::create();

   set_name("Netil Tign");

   set_short("Netil Tign, rogue psychic");
   set_id(({"Netil Tign","netil","tign","netil tign", "psychic"}));

   set_long(
"Netil Tign is a rogue psychic. She has left the "+
"training offered to her by many guilds who would see "+
"her flourish in her powers. Now she travels the lands "+
"making her living by offering trivial psychic services. "+
"She has grown old and haggard by time and the harshness "+
"of life, especially for one who is physically so weak, "+
"but mentally so powerful. Her long ragged robes brush "+
"the ground. Her form is now hunched, but her eyes are "+
"filled with power and confidence.  Her mental prowess "+
"is well known, as are the memories of those who once tried to "+
"take advantage of her when she was young and beautiful."
   );
   set_race("human");
   set_gender("female");
   set_hd(1,1);
   set_exp(1);
   set_stats("intelligence",25);
   set_body_type("human");
   set_overall_ac(9);
   set_price(100);
   set_speed(50);
  set_speed(80);
   set_nogo( ({ SCITY+"westgate", SCITY+"cguild/cleric/cleric1", SCITY+"southgate",
	SCITY+"entrance", SCITY+"eastgate", "/d/shadow/room/main/northgate" }) );

/* changing to load from Garrett's improved /daemon/monster_d.c to solve clean_up problems & save memory, more flexibility, easier maintenance, etc. *Styx*  3/23/03
   "daemon/place_d"->place_in("/d/shadow/room/city/",TO);
*/
}

int kill_ob(object who, int i){
   ::kill_ob(who,i);

   force_me( "laugh "+TPQCN);
   force_me("emote stares at "+TPQCN+" coldly and grins.");
   TP->force_me("emote starts to struggle against "+TP->query_possessive()+" own clothing and mind.");
   TP->force_me("emote grabs "+TP->query_possessive()+" head and screams.");
   TP->do_damage("head",random(100));
   TP->force_me("fall");
   TP->set_paralyzed(10,"Your head is pounding");
   TP->set_bound(50,"Your clothes have tightened, binding you.");
   remove_attacker(TP);
}


