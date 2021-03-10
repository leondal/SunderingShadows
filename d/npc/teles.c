#include <std.h>

inherit "/std/psychic.c";

void create(){
   ::create();

   set_name("Telespalin");

   set_short("Telespalin, half-drow psychic");
   set_id(({"Telespalin","telespalin","psychic"}));

   set_long(
		"%^BOLD%^%^BLUE%^"+
		"Telespalin is a psychic that will offer his services to any who "+
		"has the gold to pay for them.  Wearing dark robes to cover his "+
		"frail body. Telespalin seems to be constantly watching over his "+
		"shoulder and moving about, never staying in one place too "+
		"long.  His dark heritage has gifted him "+
		"with mental powers that surpass most who live in this city and he "+
		"learned long ago to turn a tidy profit from those abilities.  His "+
		"gifts are so powerful, and widely known, that even drow have "+
		"found him useful and have spared his life for as long as he "+
		"remains useful."+
		"%^RESET%^"
	);
   set_race("half-drow");
   set_gender("male");
   set_hd(1,1);
   set_exp(1);
   set_stats("intelligence",25);
   set_body_type("human");
   set_overall_ac(9);
   set_price(200);
   set_nogo(({ "/d/shadow/juran/city/arch1"}));
   set_speed(30);
	set_lang("undercommon", 100);
	set_lang("drow", 100);
	set_lang("common", 100);
   set_spoken("undercommon");
// adding to monster_d.c placement *Styx* 3/5/05
//   "daemon/place_d"->place_in("/d/shadow/juran/city/",TO);
}

int kill_ob(object who, int i){
   ::kill_ob(who,i);

   force_me( "cackle "+TPQCN);
   force_me("emote stares at "+TPQCN+" coldly and grins with malice.");
   TP->force_me("emote starts to struggle against "+TP->query_possessive()+" own clothing and mind.");
   TP->force_me("emote grabs "+TP->query_possessive()+" head and screams.");
   TP->do_damage("head",random(100));
   TP->force_me("fall");
   TP->set_paralyzed(10,"Your head is pounding");
   TP->set_bound(50,"Your clothes have tightened, binding you.");
   remove_attacker(TP);
}
