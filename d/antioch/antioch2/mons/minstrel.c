#include <std.h>
#include "../antioch.h"
inherit INTERACTIVE;

int SINGING;
string LASTSONG, THISSONG;

void create() {
	::create();
   remove_std_db();
   remove_dbs(({"miscvendors"}));
   set_items_allowed("misc");
   set_storage_room(ROOMDIR+"instrument");
	set_name("Gerand");
	set_id(({"minstrel","gerand","Gerand","bard"}));
	set_short("Gerand, Antioch's minstrel");
	set_long(
	"Gerand is obviously the town's minstrel. He is dressed in a %^BOLD%^%^RED%^red%^RESET%^%^CYAN%^"+
	" jacket and brown trousers. The boots he's wearing are low cut brown"+
	" suede. Long brown hair falls down his back, tied back to keep it out"+
	" of his face. He is wearing a stylish %^BOLD%^%^RED%^red%^RESET%^%^CYAN%^"+
	" hat with a %^WHITE%^%^BOLD%^white%^RESET%^%^CYAN%^ feather in it. In"+
	" his hand is a lute that he uses for his songs. His livelihood is his"+
	" music, and donations are happily accepted."
	);
	set_race("human");
        set_body_type("human"); // Shouldn't need it but does.
	set_gender("male");
	set_hd(15,4);
	set_alignment(2);
	set_max_hp(random(20)+100);
	set_hp(query_max_hp());
	set_overall_ac(5);
	set_class("bard");
	set_mlevel("bard",15);
	set_level(15);
	set_stats("charisma",20);
	set_stats("strength",18);
	set_stats("constitution",15);
	set_stats("dexterity",17);
	set_stats("intelligence",18);
	set_stats("wisdom",10);
	set("aggressive",0);
	set_exp(100);
	add_money("silver",random(100));
	set_speed(99);
	set_moving(1);
	set_property("unique",1);
	new("/d/dagger/tonovi/obj/lute.c")->move(TO);
	force_me("wield lute");
	add_search_path("/d/antioch/antioch2/obj/songs");
//	set_laungages(({"common","elven","voadkyn","gnomish","bugbear","halfling","firbolg","dwarvish","wemic","beastman"}));
}

void heart_beat()
{
	::heart_beat();
	if(SINGING == 1) return;
	else if(!random(550)) {
		call_out("random_pick",1,TO);
	}
	return;
}

void init() {
	::init();
	add_action("request","request");
   add_action("end","end");
}

void catch_say(string msg) {
	if(SINGING != 1) call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who) {
	if((strsrch(msg,"song") != -1)) call_out("song_list",1,TP);
	if((strsrch(msg,"poem") != -1)) call_out("poem_list",1,TP);
	return;
}

void song_list() {
	force_me("say I know quite a few songs, if there's one you'd like me to sing"+
	" simply %^BOLD%^request%^RESET%^ it.");
	force_me("emote tunes his lute.");
	tell_object(TP,"The songs you may request are:\n"+
	"bards farewell, candles out, creepie crawlies, enraptured, ring bells,"+
	" battle, glory of adventure, paladin flight, sea hound\n");
}

void poem_list() {
	force_me("say I don't know as many poems as songs, but I'd be happy to recite one for you.");
	force_me("smile");
	tell_object(TP,"The poems you may request are:\n"+
	"crying skies, shars way, subtle lies, open eyes, black hair\n");
}

void receive_given_item(object who, string what) {
	if(what == "coin" && SINGING != 1) {
		force_me("smile "+who->query_name());
		force_me("say Thank you.");
	}
	return;
}

void request(string str) {
	if(SINGING == 1) {
		tell_object(TP,"Gerand is already in the middle of a piece. Please wait until he is finished.");
		return;
	}
	if(str == "bards" || str == "bards farewell" || str == "farewell") {
		SINGING = 1;
		set_speed(0);
      force_me("bardfarewell");
      THISSONG = "bardfarewell";
      call_out("end",60,TP);
		return;
	}
	if(str == "black hair" || str == "black" || str == "hair") {
		SINGING = 1;
		set_speed(0);
		force_me("blackhair");
		THISSONG = "blackhair";
      call_out("end",60,TP);
		return;
	}
	if(str == "candles out" || str == "candles") {
		SINGING = 1;
		set_speed(0);
		force_me("candlesout");
		THISSONG = "candlesout";
      call_out("end",60,TP);
		return;
	}
	if(str == "creepie crawlies" || str == "crawlies" || str == "creepie") {
		SINGING = 1;
		set_speed(0);
		force_me("creepiecrawlies");
		THISSONG = "creepiecrawlies";
      call_out("end",60,TP);
		return;
	}
	if(str == "enraptured") {
		SINGING = 1;
		set_speed(0);
		force_me("enraptured");
		THISSONG = "enraptured";
      call_out("end",60,TP);
		return;
	}
	if(str == "ring bells" || str == "bells" || str == "ring") {
		SINGING = 1;
		set_speed(0);
		force_me("ringbells");
		THISSONG = "ringbells";
      call_out("end",60,TP);
		return;
	}
	if(str == "battle" || str == "battle of tylorune" || str == "tylorune") {
		SINGING = 1;
		set_speed(0);
		force_me("battle");
		THISSONG = "battle";
      call_out("end",60,TP);
		return;
	}
	if(str == "glory of adventure" || str == "glory adventure" || str == "adventure") {
		SINGING = 1;
		set_speed(0);
		force_me("gloryadventure");
		THISSONG = "gloryadventure";
      call_out("end",60,TP);
		return;
	}
	if(str == "paladin flight" || str == "paladin") {
		SINGING = 1;
		set_speed(0);
		force_me("paladinflight");
		THISSONG = "paladinflight";
      call_out("end",60,TP);
		return;
	}
	if(str == "sea hound") {
		SINGING = 1;
		set_speed(0);
		force_me("seahound");
		THISSONG = "seahound";
      call_out("end",60,TP);
		return;
	}
	if(str == "crying sky" || str == "crying" || str == "crying skies" || str == "skies" || str == "sky") {
		SINGING = 1;
		set_speed(0);
		force_me("cryingsky");
		THISSONG = "cryingsky";
      call_out("end",60,TP);
		return;
	}
	if(str == "shars way" || str == "shar's way" || str == "shar") {
		SINGING = 1;
		set_speed(0);
		force_me("sharsway");
		THISSONG = "sharsway";
      call_out("end",60,TP);
		return;
	}
	if(str == "subtle lies" || str == "lies" || str == "subtle") {
		SINGING = 1;
		set_speed(0);
		force_me("subtlelies");
		THISSONG = "subtlelies";
      call_out("end",60,TP);
		return;
	}
	if(str == "open eyes" || str == "open" || str == "eyes") {
		SINGING = 1;
		set_speed(0);
		force_me("openeyes");
		THISSONG = "openeyes";
      call_out("end",60,TP);
		return;
	}
	else {
		force_me("say I'm sorry, I didn't understand your request.");
		return;
	}
}

void random_pick() {
	set_speed(0);
	switch(random(14)) {
		case 0:
         THISSONG = "bardfarewell";
			break;
		case 1:
			THISSONG = "blackhair";
			break;
		case 2:
			THISSONG = "candlesout";
			break;
		case 3:
			THISSONG = "creepiecrawlies";
			break;
		case 4:
			THISSONG = "enraptured";
			break;
		case 5:
			THISSONG = "ringbells";
			break;
		case 6:
			THISSONG = "battle";
			break;
		case 7:
			THISSONG = "gloryadventure";
			break;
		case 8:
			THISSONG = "paladinflight";
			break;
		case 9:
			THISSONG = "seahound";
			break;
		case 10:
			THISSONG = "cryingsky";
			break;
		case 11:
			THISSONG = "sharsway";
			break;
		case 12:
			THISSONG = "subtlelies";
			break;
		case 13:
			THISSONG = "openeyes";
			break;
	}
	if(LASTSONG == THISSONG) {
		call_out("random_pick",1,TO);
		return;
	}
	else {
		SINGING = 1;
		force_me(THISSONG);
      call_out("end",60,TP);
		return;
	}
}

void end() {
	TO->force_me("speech say");
	SINGING = 0;
	set_speed(99);
	LASTSONG = THISSONG;
	return;
}
