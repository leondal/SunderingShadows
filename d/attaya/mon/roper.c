//making him auto under level 20 due to abuse of mini-quest stuff, last change was 1998 *Styx*  10/25/03

#include <std.h>
inherit MONSTER;

/* there was a wander in heart_beat that was commented out in 1998 but apparently meant to keep him from going into the following and maybe we'll put that back if we have him load via CROOM or the place_monsters database - *Styx*  10/25/03
#define SHDIR "/d/attaya/seneca/road"+
if(exitn != SHDIR "sm7" && exitn != SHDIR "t2" && exitn != SHDIR "sm17"&& exitn != SHDIR "im10")
*/

void create() {
    object ob;
    :: create();
    set_name("phantasmic wanderer");
    set_id(({ "wanderer","phantasm","phantasmic wanderer"  }));
    set_short("Phantasmic wanderer");
    set_long("%^RESET%^It is possible that at one point this "+
    "creature was a human but its flesh has long since vanished "+
    "leaving only a skeleton behind.  Judging by the %^BOLD%^%^BLACK%^blackened"+
    "%^RESET%^ bones that hold it together one would assume that "+
    "the vanishing of its flesh was assisted by an intense "+
    "%^RED%^h%^YELLOW%^e%^RED%^at%^RESET%^.  Strange symbols have "+
    "been forever etched into the surface of the larger bones, "+
    "making you think that this creature is itself an %^RED%^"+
    "emblem%^RESET%^ of some %^RED%^dark power%^RESET%^.  Inset "+
    "deeply into its skull are two glowing %^BOLD%^%^BLACK%^"+
    "obsidian%^CYAN%^ orbs%^RESET%^, they radiate an intense "+
    "%^RED%^hatred%^RESET%^ for all living things.  On occassion "+
    "it seems to fade from existence, as if it truly isn't solid "+
    "at all.  You cannot help but to wander what %^RED%^dark "+
    "force%^RESET%^ this creature represents and you begin to "+
	"question your own judgement for coming to this horrid "+
    "island.%^RESET%^");
    set_gender("male");
    set_hd(60,8);
    set_property("full attacks",1);
    set_size(2);
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(-14);
    set_hp(5000);
    set_max_hp(5000);
    set_property("undead", 1);
    set_exp(random(150000)+10000);
    set_body_type("human");
    set_race("entity");
    set_class("fighter");
    set_guild_level("fighter",40);
    set_stats("strength",22);
    set_stats("constitution",25);
    set_stats("dexterity",25);
    set_stats("wisdom",15);
    set_stats("intelligence",18);
    set_stats("charisma",15);
    set_alignment(5);
    set("aggressive","aggfunc");
    set_emotes(2, ({
	"Phantasmic Wanderer seems to fade in and out of existence before you.",
	"Phantasmic Wanderer opens its hand and waves it before your eyes... \n%^YELLOW%^You feel very dizzy.",
	"%^CYAN%^Phantasmic Wanderer lets out a horrible shriek",
	"%^BOLD%^%^BLUE%^Phantasmic Wanderer seems to crackle with unseen energies.",
	"Phantasmic Wanderer cackles evilly.",
	"%^MAGENTA%^Phantasmic Wanderer says%^RESET%^: Death comes to us all, I am an implement of that death.",
      }),1);
    set_emotes(1, ({
	"Phantasmic Wanderer closes in on you.  Its shiny, narrow, black slits for eyes grow narrower and closer till you can see your frightened expression peering back at you from within.",
	"Phantasmic Wanderer hisses at you threateningly.",
	"Phantasmic Wanderer seems to fade in and out of existence before you.",
	"Phantasmic Wanderer opens its hand and waves it before your eyes... \n%^YELLOW%^You feel very dizzy.",
	"Phantasmic Wanderer waves its skeletal hand around in rhythmic patterns...  Trails of blue light follow its motions.",
	"Phantasmic Wanderer lowers its head and turns his view to your feet.",
	"Phantasmic Wanderer cackles evilly.",
	"Phantasmic Wanderer mutters something about forcewaves.",
	"Phantasmic Wanderer slams its fists against the ground and slowly rises to stand before you gain.",
	"%^MAGENTA%^Phantasmic Wanderer says%^RESET%^: The time will come when I will be sent by my dark masters to steal your soul...  Be wary.",
	"Phantasmic Wanderer opens its jaw as if to speek but says nothing.",
	"Phantasmic Wanderer breathes cold air past you and you shiver.",
	"Phantasmic Wanderer peers back over its shoulder.",
	"Phantasmic Wanderer displays a dark burlap sack.  It is filled with some round objects the size of large melons.",
      }),0);
    ob = new("/d/common/obj/brewing/herb_special_inherit");
    ob->set_herb_name("bone dust");
    ob->move(TO);
}

void init() {
   ::init();
   add_action("kill_func","kill");
   add_action("kill_func","rush");
// adding this check here so it will catch invis. lower levels *Styx* 10/25/03
   if(!interactive(TP))  return;
   if(TP->query_highest_level() < (15 + random(3)) ) {
     if(TP->query_invis()) {
        TO->force_me("say %^BOLD%^%^RED%^You think your puny tricks "+
        "hide you from the sight I have from the afterlife?");
        TO->force_me("cackle");
        TO->force_me("say %^BOLD%^%^RED%^You are either brave or "+
        "foolish to be here in such an evil place of such great "+
        "power, "+TP->query_race()+".  I shall have your eyes!  We "+
        "shall see if you prove a worthy challenge!");
        TO->force_me("kill "+TPQN);
        new("/cmds/spells/d/_dispel_magic.c")->use_spell(TO,TPQN,30,100,"cleric");
	 }
   }
}

void aggfunc() {
    int j;
    j = random(6);
    if(TP->query_invis()) {
	return 1;
    }
    if(j == 0) {
	TO->force_me("say Have you come to nourish me with your lifeforce energies, "+(string)TPQCN+"?");
	TO->force_me("look "+TPQN);
	return 1;
    }
    if(j == 1) {
	TO->force_me("say I know your fate, "+(string)TPQCN+".  I know everyone's fate.");
	TO->force_me("say Stay here and the Kinnesaruda will strike on your party with increased hatred...  now...");
	return 1;
    }
    if(j == 2) {
	TO->force_me("say I curse you, "+(string)TPQCN+"! On this day, evil stands between you and hope in all those empty places you must walk.");
	TO->force_me("glare "+TPQN);
	return 1;
    }
    if(j == 3) {
	TO->force_me("say Proceed, "+(string)TPQCN+", on your way to oblivion...");
	TO->force_me("grin with an ancient hatred");
	return 1;
    }
    if(j == 4) {
	if((int)TP->query_level() > 35) {
	    TO->force_me("grin "+TPQN);
	    TO->force_me("say When I was a warrior in the Phantom Legion, I held powers greater than you will ever know, "+(string)TPQCN+"!");
	    return 1;
	} else {
	    TO->force_me("say You are brave to be here in such an evil place, "+(string)TPQCN+", I shall have your eyes!");
	    TO->force_me("kill "+TPQCN);
	    return 1;
	}
    }
    if(j == 5) {
	TO->force_me("say %^BOLD%^Everything dies, your time is now!");
	TO->force_me("kill "+TPQN);
	return 1;
    }
}

int kill_func(string str) {
    if(!str) {
	notify_fail("Kill what?\n");
	return 0;
    }
    if(str == "wanderer" || str == "phantasmic wanderer" || str == "phantasm"){
	if((int)TP->query_money("gold") < 100) {
	    write("Phantasmic wanderer laughs at you!\n");
// adding a failure message to the room *Styx* 10/25/03
	    tell_room(ETO, "Phantasmic wanderer laughs at "+TPQCN+".", TP);
	    return 0;
	}
	TP->add_money("gold",-100);
	new( "/d/attaya/newseneca/obj/candle.c" )->move(TO);
	TO->force_me("say Here is a token of my apathy "+(string)TPQCN+"!");
	TO->force_me("say Foolish child!");
	TO->force_me("give candle to "+TPQN);
	TO->force_me("grin "+TPQN);
	return 1;
    }
   //changed to fix the changing of commands into emotes
   //the emote it performed when something attacks in
   //the room with it (which was causing the problem)
   //has been moved down to the kill function below
   //he will auto attack anyone who attacks in the room
   //with him for now anyway - Saide - 11/04/03
   if(str) {
     return 0;
   }
   if(!str) {
     return 0;
   }
}

int kill_ob(object victim, int which){
    int hold;
   //Okay, well - he auto attacks anyone that attacks in
   //the room with him - at least for now
    TO->force_me("emote shrieks horribly");
    hold = ::kill_ob(victim, which);
    if(hold){
      if(interactive(victim))
        new("/cmds/spells/a/_animate_object.c")->use_spell(TO,victim->query_name(),30,100,"cleric");
    }
    return hold;

}
