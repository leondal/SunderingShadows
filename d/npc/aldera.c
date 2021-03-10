#include <std.h>

inherit "/std/psychic.c";

void create(){
   ::create();

   set_nwp("eavesdropping",10,500);
   set_name("Aldera Carena");

   set_short("Aldera Carena, wandering psychic");
   set_id(({"Aldera Carena","aldera","carena","aldera carena", "psychic"}));

   set_long(
@OLI
Aldera Carena is a calm, passive woman, wearing servicable clothing.  Her long, black hair is braided back into a ponytail to keep it out of her face.  She provides her services for a fee, and has traveled here after noticing that another psychic has made money doing the same job she can do.
OLI
);
   set_race("human");
   set_gender("female");
   set_hd(5,1);
   set_exp(1);
   set_stats("intelligence",25);
   set_body_type("human");
   set_overall_ac(9);
   set_price(150);
   set_speed(60);
   set_nogo( ({"/d/dagger/road/road25", "/d/dagger/road/road36", "/d/dagger/tonovi/2path1", "/d/dagger/road/road24", "/d/dagger/Daggerdale/shops/inn", "/d/dagger/Daggerdale/shops/woodwright" }) );


//   "daemon/place_d"->place_in("/d/dagger/Daggerdale/streets/",TO);
//  changing to load from Garrett's improved /daemon/monster_d.c to solve clean_up problems & save memory, more flexibility, easier maintenance, etc. *Styx*  3/23/03
}

int kill_ob(object who, int i){
   if (!objectp(who)) return 0;//corrected some issues with TP being invalid, and added a valid object check -Ares
   ::kill_ob(who,i);

   force_me( "laugh "+who->QCN);
   force_me("emote tilts her head curiously at"+who->QCN+" and concentrates.");
   who->force_me("emote staggers back and struggles suddenly as "+who->query_possessive()+" clothing constricts.");
   who->force_me("emote grabs "+who->query_possessive()+" head and screams.");
   who->cause_typed_damage(who, "head", random(100), "mental");
   who->force_me("fall");
   who->set_paralyzed(10,"Your head is pounding");
   who->set_bound(50,"Your clothes have tightened, binding you fast.");
   remove_attacker(who);
}
