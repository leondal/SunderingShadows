//jerax.c - The guard in the tunnels underneath Stefano's tower.
// Coded by Lujke 5/05/05
#include <std.h>
#include "../tunnel.h"
inherit MONSTER;

void create(){
   ::create();
   set_name("jerax");
   set_id(({"jerax","jerax the guard","guard"}));
   set_short("Jerax the guard");
   set_long("%^RED%^Jerax is in his mid thirties, with black hair and"
           +" %^RESET%^sl%^CYAN%^a%^RESET%^te gray e%^CYAN%^y%^RESET%^es"
           +"%^RED%^. His skin is %^ORANGE%^tanned and leathery%^RED%^,"
           +" with deep wrinkles round the edges of his mouth and at the"
           +" corners of his eyes. His muscular build and callused hands"
           +" suggest that he is more used to active duty as a guard or"
           +" soldier than to desks and paper work. He is dressed in"
           +" leather, with bracers protecting his forearms and a"
           +" %^RESET%^dull grey circlet%^RED%^ on his head");
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_hd(35,5);
   set_alignment(3);
   set_max_hp(250+random(100));
   set_hp(query_max_hp());
   set_overall_ac(-12);
   set_class("fighter");
   set_mlevel("fighter",35);
   set_level(35);
   set_stats("wisdom",12);
   set_stats("strength",18);
   set_stats("constitution",17);
   set_stats("intelligence",16);
   set_stats("charisma",9);
   set_stats("dexterity",18);
   set_exp(6000);
   set("aggressive",0);

  	set_emotes(5,({
	   "%^BOLD%^%^BLUE%^The guard mutters something and looks at one of"
         +" his lists.",
          "%^BOLD%^%^BLUE%^Jerax reads something from the log",
          "%^BOLD%^%^BLUE%^Jerax writes himself a note",
          "%^BOLD%^%^BLUE%^Jerax puts his feet up on the table",
          "%^BOLD%^%^BLUE%^Jerax looks at you suspiciously",
          "%^BOLD%^%^BLUE%^With a bored look on his face, Jerax idly"
         +" twiddles his thumbs",
          "%^BOLD%^%^BLUE%^Jerax suddenly jumps up from his seat and"
         +" takes a few practice swings with his sword. He looks fairly"
         +" proficient.",
          "%^BOLD%^%^BLUE%^Jerax uses a %^RESET%^dagger%^BOLD%^%^BLUE%^"
         +" to dig some %^BOLD%^%^BLACK%^gr%^RESET%^i%^BOLD%^%^BLACK%^me"
         +" %^BOLD%^%^BLUE%^out from under his fingernails.",
          "%^MAGENTA%^Jerax says%^RESET%^: Bloody passwords. I reckon"
         +" they don' trust me near the treasury.",
          "%^MAGENTA%^Jerax says%^RESET%^: Who'd wanna work with a"
         +" pitfull of devils? I reckon the old git only put them down"
         +" here to guard his stuff."
    	}),0);
      new(OBJ+"circlet_of_c")->move(TO);
}

void init()
{
  ::init();
  force_me("wear circlet");
}

void die(mixed ob)
{
  object circlet;
  if (!objectp(TO)||!objectp(ETO)){return;}
  circlet = present("circlet", TO);
  if (objectp(circlet) &&random(30)>0)
  { 
    tell_room(ETO,"%^GREEN%^As Jerax falls, his %^RESET%^dull gray"
                 +" circlet %^GREEN%^crumbles to nothing!", TO);
    circlet->remove(TO);
  }
  ::die(ob);
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
  if (!objectp(TO)||!objectp(ETO)||!objectp(who)){return;}
  if (interact("devil", msg)||interact("devils", msg)){
             force_me("say %^CYAN%^Damn devils all over tha shop now. I'm"
             +" sure the master knows what e's doin, but I'll be honest -"
             +" them things make me skin crawl. An' they're powerful n'"
             +" all. What about 'em rock devils? Can' even touch 'em with"
             +" a weap'n, magic's yer only hope! Can' stand their talk"
             +" neither. That language they speak'll wreck yer ears tha"
             +" way they shriek it an' it's a jawbreaker to try n"
             +" talk.");
    return;
  }
  if (interact("tunnel", msg)||interact("tunnels", msg)){
    force_me("say %^CYAN%^Well, most of it's natural n 'all,"
            +" but some of it 'em rock devils jest clawed out wi' their"
            +" bare hands! I askya - d' them things make yer shiver or"
            +" wha'?");
    return;
  }
  if (interact("devilkin", msg)||interact("devilkins", msg)){
    force_me("say %^CYAN%^Funny lill fellas them. Ye ain' seen"
             +" nuthin till ye've seen 'em all dancin' round in a circle."
             +" They love a bit of a tune n' all. Somethin' ye can hum"
             +" along wit'.");
    return;
  }
  if (interact("treasury", msg)||interact("password", msg)){
    force_me("say %^CYAN%^Here now, I can' be tellin' ye 'bout"
             +" tha'! S'more'n me job's werth - or me neck even. I gotta"
             +" be keepin' that stuff safe an' guardin tha' log n' all."
             );
    return;
  }
  if (interact("mouth", msg)||interact("mouths", msg)){
    force_me("say %^CYAN%^I dunno nuthin 'bout all tha' magic"
             +" stuff, but I'm sure tha master knows what they're there"
             +" fer. Dun like 'em meself an I haveta say this - 'e's got"
             +" a right wierd sense o' humour, that one!");
    return;
  }
  if (interact("notice", msg)||interact("notices", msg)){
    force_me("say %^CYAN%^Yeah, we haveta do all 'em notices in"
             +" both languages now, so tha' devils can read 'em too,"
             +" curse their 'ides!");
    return;
  }
  if (interact("barbazu", msg)||interact("barbazus", msg)){
    force_me("say %^CYAN%^Ugh, them ones're sick. I mean really"
             +" sick. They got some kinda wierd disease 'ey can give ya."
             +" Ugh. Wouldn' get too close to 'em, given tha'"
             +" choice! I did 'ear there's a cure fer it somewhere,"
             +" tho'.");
    return;
  }
}