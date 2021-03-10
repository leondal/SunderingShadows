#include <std.h>
inherit "/std/vendor";
//Added checks to make sure they get the object and aren't carrying too much weight
//if they are, sheas will drop the item on the counter for them - Saide


int choose;

void create() {
    ::create();
    set_nwp("weaponsmithing",15,500);
    set_name("sheas");
    set_id( ({ "clerk", "sheas", "shopkeeper"}) );
    set_short("Sheas");
    set("aggressive", 0);
    set_hd(29,2);
    set_long("%^BOLD%^%^BLACK%^Sheas %^RESET%^%^ORANGE%^is an old %^CYAN%^renowned %^BOLD%^%^BLACK%^fighter %^RESET%^%^ORANGE%^who"
	         " have now taken set up %^BOLD%^%^WHITE%^shop %^RESET%^%^ORANGE%^in %^WHITE%^Kinaro%^ORANGE%^. Her hair is %^BOLD%^%^RE"
			 "D%^f%^RESET%^%^RED%^l%^BOLD%^a%^RESET%^%^RED%^m%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^g r%^RESET%^%^RED%^e%^BOLD%^d%^RESET%^"
			 "%^ORANGE%^, with %^BOLD%^%^WHITE%^si%^RESET%^lv%^BOLD%^er%^RESET%^y %^BOLD%^st%^RESET%^r%^BOLD%^e%^RESET%^a%^BOLD%^ks%^RE"
			 "SET%^%^ORANGE%^, and she keeps it long and tied into a %^BOLD%^%^MAGENTA%^bun %^RESET%^%^ORANGE%^upon her head. She is not"
			" %^BOLD%^%^MAGENTA%^beautiful%^RESET%^%^ORANGE%^, even by %^RED%^dwarven %^ORANGE%^standards, with a %^RED%^scared face %^"
			"ORANGE%^and d%^WHITE%^u%^ORANGE%^ll b%^WHITE%^r%^ORANGE%^o%^WHITE%^w%^ORANGE%^n eyes. %^BOLD%^%^BLACK%^Sheas %^RESET%^%^ORA"
			"NGE%^is quite %^CYAN%^slender %^ORANGE%^as %^RED%^dwarves %^ORANGE%^go, but with %^BOLD%^%^MAGENTA%^womanly curves%^RESET%^%"
			"^ORANGE%^. She wears a nice brown %^MAGENTA%^dress %^ORANGE%^and a pair of %^BOLD%^%^WHITE%^quality %^RESET%^%^ORANGE%^boots,"
			" but nothing %^MAGENTA%^gaudy%^ORANGE%^. She tends %^BOLD%^%^CYAN%^carefully %^RESET%^%^ORANGE%^to a few special %^BOLD%^%^WH"
			"ITE%^weapons %^RESET%^%^ORANGE%^and %^BOLD%^%^BLACK%^armor %^RESET%^%^ORANGE%^on %^BOLD%^%^CYAN%^display %^RESET%^%^ORANGE%^in"
			" cases around the room; you could probably %^BOLD%^%^WHITE%^ask %^RESET%^%^ORANGE%^her about them.%^WHITE%^");
    set_gender("female");
    set_property("no dominate", 1);
    set_property("no kill", 1);
    set_mob_magic_resistance("average");
    set_property("full attacks",1);
	set_diety("tempus");
    set_alignment(4);
    set_race("dwarf");
    set_overall_ac(-5);
    set_stats("strength", 18);
    set_stats("dexterity", 15);
    set_stats("constitution", 15);
    set_stats("intelligence", 11);
    set_stats("wisdom", 11);
    set_stats("charisma", 14);
    set_class("fighter");
    set_body_type("human");
    set_storage_room("/d/dagger/kinaro/storage/w_storage");
    set_hp(300);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_mp(0);
    set_max_mp(query_mp());
    set_items_allowed("weapon");
    remove_std_db();
    remove_dbs( ({"/d/db/vendor","/d/db/weapons" }) );
    force_me("speak wizish");
    force_me("speech rumble");
}

void catch_say(string msg){
   ::catch_say(msg);
   call_out("do_stuff",1,msg,TP);
}

void do_stuff(string msg, object ob){
   string race;
   int align;
   object obj;
   race = TP->query_race();
   if(TP->query_invis()) {
      switch(random(5)) {
        case 0: force_me("emote looks around suspiciously.");
          break;
        case 1: force_me("say Who goes there?  Come outta yer hiding!");
          break;
        case 3:  force_me("emote frowns and checks that a weapon is close by.");
          break;
        default: break;
      }
      return;
   }
   if(!objectp(TP->query_property("shapeshifted")) && (race == "bugbear" || race == "goblin" || race == "hobgoblin" || race == "kobold" || race == "orc" || race == "drow" || race == "gnoll" || race == "half-drow" || race == "ogre" || race == "ogre-mage" || race == "half-ogre" || (string)TP->query("subrace") == "duergar")) {
     force_me("say Hell with ye, get ye gone afore I chase ye out!");
     force_me("emote snarls.");
     call_out("kill_em",10,TP);
     return;
   }
//if they haven't handed over a weapon and been given a choice yet, interact
//and give them the mission
   if(!choose) {
     if(strsrch(msg, "evil") != -1) {
       force_me("say That elf's lot patrol the road lookin' for evil sorts.  "
"Got good intents, but ain't got a clue how ta reward properly fer such "
"efforts.");
       force_me("say Ya bring me such wicked weapons an' I'll see ya given "
"somethin' good fer ya troubles.  Just let me know if ya wanna help out.");
       force_me("emote winks.");
       return;
     }   
     if(strsrch(msg, "help") != -1 || strsrch(msg,"weapon") != -1 || 
         strsrch(msg,"sword") != -1 || strsrch(msg,"yes") != -1 || 
         strsrch(msg,"Yes") != -1 || strsrch(msg,"ask") != -1 || 
         strsrch(msg,"Ask") != -1) {
       force_me("say If ya wanna help us destroy these evils, I'll see ya "
"properly rewarded.");
       call_out("say1",1);
       call_out("say2",8);
       return;
     }
     if(strsrch(msg, "hello") != -1 || strsrch(msg,"greeting") != -1 || 
         strsrch(msg,"Hello") != -1 || strsrch(msg,"Greeting") != -1) {
       force_me("say Hey there.  I hope yer travels find ya safe from the evils "
         "around 'ere.");
       return;
     }
     if(strsrch(msg, "bane") != -1 || strsrch(msg, "baneblade") != -1) {
      force_me("say It's an evil lot that skulk in that excuse fer a city "
"called Tonovi.  If ya wanna take a piece outta their Bane-lovin' lot, there's "
"a shadowy servant of their god that hides in the caves southeast of the Shadow "
"desert. Mind yer step in there, nasty little creatures hide in the dark.");
      return;
     }
     if(strsrch(msg, "barrows") != -1 || strsrch(msg, "slaying") != -1) {
      force_me("say The skeletal guardians in the pits near Cyric's Temple are "
"a fearsome lot, and all must be defeated so ya can get inside ta defeat the "
"greater evil they serve and guard.  Gods watch over ya an' strengthen yer arm "
"ta strike 'em down!");
      return;
     }
   } 
//this section deals with the trade (choose has been set from receiving the item)
   if(choose) {
     if(strsrch(msg,"hammer") != -1) {
       if(race != "dwarf") {
       force_me("bow "+TPQN);
         force_me("say This hammer's precious ta my kin, and won't serve ta be "
"wielded by any other.");
          force_me("say I'm sorry but I must ask that ya choose differently.");
         return;
       }
       force_me("say A fine choice, an' the legacy of our people. It'll serve "
"ye well.");
       force_me("emote opens one of the display cases and carefully lifts out "
"the hammer.");
       new("/d/shadow/virtual/mon/dhammer")->move(TO);
       force_me("give hammer to "+TPQN);
	 if(present("hammer", TO)) 
	 {
		command("say I'll lay it on the counter for you then.");
		command("drop hammer");
	 }
       choose = 0;
       return;
     }
     if(strsrch(msg,"axe") != -1) {
       force_me("say Old faithful, this one's served me many years.");
       force_me("emote opens one of the display cases and takes out an axe.");
       new("/d/dagger/kinaro/obj/crysaxe")->move(TO);
       force_me("give axe to "+TPQN);
	 if(present("axe", TO))
	 {
		command("say I'll lay it on the counter for you then.");
		command("drop axe");
	 }
       choose = 0;
       return;
     }
     if(strsrch(msg,"sword") != -1) {
       force_me("say One of my finer craftings, this one.  Don' be misled by "
"the look of it, she's a sturdy blade.");
       force_me("emote opens one of the display cases and takes out a sword.");
       new("/d/dagger/kinaro/obj/cryssword")->move(TO);
       force_me("give sword to "+TPQN);
	 if(present("sword", TO))
	 {
		command("say I'll lay it on the counter for you then.");
                command("drop sword");
	 }
       choose = 0;
       return;
     }
     if(strsrch(msg,"plate") != -1) {
       force_me("say One of Gake's best efforts, that.  Saved many a dwarven "
"life in battle against the evils this realm seems to breed.");
       force_me("emote opens one of the display cases and lifts out the pieces "
"of a full suit of platemail.");
       obj = new("/d/dagger/kinaro/obj/silvplate");
       obj->move(TO);
       if((int)TP->query_size() < 3) obj->set_size((int)TP->query_size());
       obj->set_owned(TP);
       force_me("give plate to "+TPQN);
       if(present("plate", TO))
	 {
		command("say I'll lay it on the counter for you then.");
		command("drop plate");
	 }
       choose = 0;
       return;
     }
     if(strsrch(msg,"chain") != -1) {
       force_me("say I'm not one for this lighter stuff myself, but it's fine "
"crafted an' it'll protect well.");
       force_me("emote opens one of the display cases and takes out a suit of "
"silvered chainmail.");
       obj = new("/d/dagger/kinaro/obj/silvchain");
       obj->move(TO);
       if((int)TP->query_size() < 3) obj->set_size((int)TP->query_size());
       force_me("give chain to "+TPQN);
       if(present("chain", TO))
	 {
		command("say I'll lay it on the counter for you then.");
		command("drop chain");
	 }
       choose = 0;
       return;
     }
   }
//default responses if none above fits to give them hints, only respond 1/3 though
   if(random(4)) return;
   switch(random(5)) {
     case 0:  
       force_me("say If ya wish ta help in our fight against evil, maybe ya "
"seek a fine weapon or armor?");
       break;
     case 1:
       force_me("say Ain't any finer crafted than the weapons an' armor made "
"right here in Kinaro.  Maybe ya have an interested in 'em?");
       break;
     case 2:
       force_me("emote carefully polishes one of the display cases.");
       break;
     case 3:
       force_me("emote sets a newly crafted weapon out near the front of the "
"shop.");
       break;
     case 4:
       force_me("say About time they got them nasty Tonovi lot off the roads, "
"I tell ye.  Good work ta whoever burnt down that rotten tollbooth.");
       break;
   }
   return;
}

void say1() {
   force_me("say There's a few evil weapons that elf lot want destroyed.");
   force_me("whisper "+TPQN+" There's a sword of slaying that they reckon is "
       "found deep in the barrows near Cyric's Temple, up northwest of 'ere.");
   force_me("say Best not ta let 'em fall inta the wrong hands, if ya know "
"what I mean.");
   return;
}

void say2() {
   force_me("whisper "+TPQN+" There's also the corrupted Baneblade, a weapon "
"found well-hidden and deep in caves east and south of the Shadow "
"desert.");
   force_me("say Of course, ya can take any ta the elf leader an' he'll give ya something 'pretty' I'm sure. But if ya want a real reward, ya bring 'em here.");
   force_me("smirk");
   return;
}
 
void receive_given_item(object ob){
   string race;
   race = TP->query_race();
   if (ob->id("sword of slaying") || ob->id("baneblade")) {
      choose = 1;
      force_me("say Aye, this is one'a them weapons we're after. One less in "
"the realm now!");
      force_me("offer sword");
      force_me("say You've done a good service, so look around an' see what "
"ya'd like ta have.  Any in the display cases are free fer choice.");
      force_me("say There's %^YELLOW%^chain%^RESET%^ and %^YELLOW%^plate%^RESET%^ "
"of Gake's craftin', an' some of my own weapons as well: %^YELLOW%^sword%^RESET%^ "
"an' %^YELLOW%^axe%^RESET%^.");
      if( (string)TP->query_race() == "dwarf") {
         force_me("say There's also a fine %^YELLOW%^hammer %^RESET%^there, "
"what'd be a right prize ta any of our kin.");
      }
      force_me("say Ya have two minutes ta say which item ya choose.");
      return;
   }
   force_me("say I am sorry but this is not one of the items I can reward you "
      "for bringing to me.");
   force_me("emote puts the item back down on the counter in front of her.");
   force_me("drop "+ob->query_name() );
   return;
}

void kill_em(object targ) {
   if(!present(TP)) return;
   force_me("say I warned ye, begone!");
   force_me("kill "+TPQN);
}
