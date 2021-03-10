//Delorn Meritas - psychic for Tabor by Circe
// altered temporarily to be Delorn's brother. Covering for while he gets ressed and healed after demi-god NF exploded his brain when sykari tried to contact him. Back in a week :P
// Nienne, 09/07.
#include <std.h>

inherit "/std/psychic.c";

void create(){
   ::create();
   set_nwp("eavesdropping",10,500);
//   set_name("Delorn Meritas");
   set_name("Ramirez Meritas");
//   set_short("Delorn Meritas, wandering psychic");
   set_short("Ramirez Meritas, wandering psychic");
//   set_id(({"Delorn Meritas","delorn","Delorn","psychic"}));
   set_id(({"Ramirez Meritas","ramirez","Ramirez","psychic"}));
//   set_long("Delorn Meritas is a young man in his early twenties.  "
   set_long("Ramirez Meritas is a young man in his early twenties.  "
	"Judging from his well-formed physique, he could do physical "
	"labor if he chose, but why should he, given his gift for "
        "telepathic communication?  His eyes are a light, almost "
	"eerie shade of blue, and they are quite wide, giving him a "
	"somewhat startled appearance at all times.  His skin is tanned "
	"from wandering the streets in the sun all day, but he wears a "
	"fine silk shirt under an embroidered vest with the shirt tucked "
	"neatly into his leather breeches.  His black hair is pulled into "
	"a ponytail at the base of his neck, and his appearance suggests "
	"that he makes quite a decent living at his job.");
   set_race("human");
   set_gender("male");
   set_hd(5,1);
   set_exp(1);
   set_stats("intelligence",25);
   set_body_type("human");
   set_overall_ac(-3);
   set_price(150);
   set_speed(60);
   set_nogo(({"/d/koenig/streams/path18","/d/shadow/room/forest/road58", "/d/darkwood/tabor/road/road1", "/d/darkwood/tabor/room/psientry", "/d/darkwood/tabor/room/tgate"}));
}

int kill_ob(object who, int i){
   ::kill_ob(who,i);

   force_me( "laugh "+TPQCN);
   force_me("emote tilts his head curiously at"+TPQCN+" and concentrates.");
   TP->force_me("emote staggers back and struggles suddenly as "+
      ""+TP->QP+" clothing constricts.");
   TP->force_me("emote grabs "+TP->QP+" head and screams.");
   TP->do_damage("head",random(100));
   TP->force_me("fall");
   TP->set_paralyzed(10,"Your head is pounding");
   TP->set_bound(50,"Your clothes have tightened, binding you fast.");
   remove_attacker(TP);
}
