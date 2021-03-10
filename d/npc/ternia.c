#include <std.h>
// psychic for Torm by Styx, finally put in 11/23/03

inherit "/std/psychic.c";

void create(){
   ::create();
   set_nwp("eavesdropping",15);
   set_name("Ternia");
   set_short("Ternia, wandering psychic");
   set_id(({"Ternia", "ternia", "psychic"}));
   set_long("Ternia has shoulder-length, jet-black hair and large, dark "
	"brown eyes.  She is dressed rather elaborately in a long, flowing, "
	"multi-color skirt and blouse with gauzy, flowing sleeves.  She is "
	"adorned in a variety of jewelry including ornate, dangling "
	"earrings and numerous bracelets and rings.  She seems often "
	"distracted as though her mind is somewhere else.  Perhaps she is "
	"exercising or even "
	"tuning out her telepathic abilities in between sessions of "
	"helping those who are willing to hire her to help them communicate "
	"with others from a distance."
   );
   set_race("human");
   set_gender("female");
   set_hd(25,1);
   set_exp(10);
   set_stats("intelligence",25);
   set_stats("wisdom",25);
   set_overall_ac(4);
   set_price(150);
   set_speed(120);
   set_nogo( ({ "/d/dagger/Torm/road/path12", "/d/dagger/Torm/road/path22", "/d/dagger/Torm/city/c130", "/d/dagger/Torm/city/c133"  }) );
}

int kill_ob(object who, int i){
   ::kill_ob(who,i);

   force_me( "laugh "+TPQN);
   force_me("emote glares angrily at"+TPQCN+" and concentrates.");
   TP->force_me("emote staggers back and struggles suddenly as "+TPQP+" clothing constricts.");
   TP->force_me("emote grabs "+TPQP+" head and screams.");
   TP->do_damage("head",random(100));
   TP->force_me("fall");
   TP->set_paralyzed(10,"Your head is pounding!");
   TP->set_bound(50,"Your clothes have tightened, binding you fast.");
   remove_attacker(TP);
}

