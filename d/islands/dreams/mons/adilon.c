#include <std.h>
#include "../defs.h"
inherit NPC;

void create()
{
  ::create();
  set_name("Adilon");
  set_short("The spirit of Adilon");
  set_id(({"adilon","Adilon","spirit"}));
  set_long("%^CYAN%^The spirit of a weary priest shimmers before you.  "+
	"A middle aged man once in life, the spirit is now but an "+
	"image of what was.  Greying, thick hair frames a broad, "+
	"friendly looking face which is covered by a neatly "+
	"trimmed beard.  His robes are clean and official "+
	"looking, and the signet ring he wears on a chain "+
	"around his neck leaves little doubt that he once held "+
	"a position of some importance.");
  set_race("human");
  set_body_type("human");
  set_class("cleric");
  set_hd(30,1);
  set_hp(1000);
  set_spells(({"flame strike","moon blade","hold person"}));
  set_spell_chance(90);
  set_diety("selune");
  new("/d/shadow/obj/armor/robe")->move(TO);
  command("wear robe");
  set_unique(1);
  set_alignment(4);
  remove_std_db();
  set_gender("male");
  command("speech speak in a calm, kind tone");
}

init()
{
  ::init();
	if(interactive(TP) && !TP->query_invis()) {
  	call_out("greet",1,TP);
	}
}

void greet()
{
  force_me("say You have done well to make it this far, "+
	""+TP->query_visual_race()+".  I may be able to help guide "+
	"you through your journey.  I have acquired much "+
	"%^CYAN%^information %^RESET%^that may help you here.");
}

void catch_say(string message)
{
  if(strsrch(message,"information") != -1)
  {
    call_out("do_information",1,TP);
    return 1;
  }
  else if(strsrch(message,"portals") != -1)
  {
    call_out("do_portal",1,TP);
    return 1;
  }
  else if(strsrch(message,"pedestal") != -1)
  {
    call_out("do_ped",1,TP);
    return 1;
  }
  else if(strsrch(message,"place") != -1)
  {
    call_out("do_place",1,TP);
    return 1;
  }
}

int do_information()
{
  force_me("sigh");
  force_me("say I had hoped that the journal I left behind would have "+
	"steered you away from this fate.  But perhaps you were stranded "+
	"upon the island as we were.");
  call_out("do_information2",10,TP);
  return 1;
}

int do_information2()
{
  force_me("say So tell me, what is it that you would know?  "+
	"I know of many things, but you may find what I have to "+
	"say about the %^CYAN%^portals%^RESET%^, the "+
	"%^CYAN%^pedestal%^RESET%^, and this "+
	"%^CYAN%^place %^RESET%^in general most interesting.");
  return 1;
}

int do_portal()
{
  force_me("say Where they actually go, I really can not say.  They "+
	"seem to lead straight into someone's dreams...or nightmares.");
  call_out("do_portal2",10,TP);
  return 1;
}

int do_portal2()
{
  force_me("say Each one seems to place you in some sort of dilemma.  "+
	"Heed my words, stranger.  Though they may be dreams to others, "+
	"to you and I, they are quite real.  Your actions will have "+
	"their consequences just as they would outside of this realm.");
  return 1;
}

int do_ped()
{
  force_me("say The pedestal is clearly magical in nature.  I have "+
	"studied it much...I often have little else to do.");
  force_me("emote points at the white crystal on the pedestal.");
  call_out("do_ped2",10,TP);
  return 1;
}

int do_ped2()
{
  force_me("say From what I can tell, there are more of these crystals.  "+
	"Given that there are four empty slots, and four portals, I can "+
	"only imagine that each portal may hold those crystals, which "+
	"you could then %^GREEN%^insert%^RESET%^ them into the pedestal.");
  call_out("do_ped3",10,TP);
  return 1;
}

int do_ped3()
{
  force_me("say What good that will do?  Sadly, I do not know.");
  force_me("shrug");
  return 1;
}

int do_place()
{
  force_me("say From what I can tell, we are standing in what "+
	"resulted from a powerful spell gone wrong.  Lady Graymantle "+
	"has given me some guidance on this matter, and I shall "+
	"share with you what little I know.");
  call_out("do_place2",10,TP);
  return 1;
}

int do_place2()
{
  force_me("say Not long ago, apparently a powerful, dark mage "+
	"developed an infatuation with capturing various creatures "+
	"and then torturing them until they would do his bidding.");
  call_out("do_place3",10,TP);
  return 1;
}

int do_place3()
{
  force_me("say The mage had found a way to create his own version "+
	"of gems of entrapment.  They allowed him to carry with him "+
	"many powerful beasts, all neatly held within the gems he placed "+
	"in his pockets or sacks.");
  call_out("do_place4",10,TP);
  return 1;
}

int do_place4()
{
  force_me("say As is often the case, this mage seems to have grown "+
	"overconfident in his powers.  He set out to acquire a beast "+
	"that, if he could control it, would tremendously increase "+
	"his strength.  But as you can imagine, dragons "+
	"don't care much about the desires of a simple mage.");
  call_out("do_place5",10,TP);
  return 1;
}

int do_place5()
{
  force_me("emote looks you over sternly.");
  force_me("say Not any dragon would do for him, though.  He desired "+
	"to show exactly how great he and his gems were.  Of all "+
	"the dragons, no one has ever tamed a dream dragon.");
  call_out("do_place6",10,TP);
  return 1;
}

int do_place6()
{
  force_me("say What happened, I can not say.  My guess is that it "+
	"occured upon the island our ship crashed into.  I believe "+
	"we exist within one of those gems.  How it is that we can "+
	"get here, and how so many of us can be within just one gem, "+
	"I really do not know.");
  call_out("do_place7",10,TP);
  return 1;
}

int do_place7()
{
  force_me("say Lady Graymantle has willed that I remain here, until "+
	"I can finally guide lost souls such as yourself back to the "+
	"paths they seek.  You must find the four crystals, and "+
	"place them within that pedestal.  From there, we may figure "+
	"out our next path together.");
  return 1;
}

void crysin()
{
  call_out("crysin2",10,TP);
}

void crysin2()
{
  force_me("say Yes!  That's it.  It would appear that you need to "+
	"%^GREEN%^press%^RESET%^ the crystals until all of them are "+
	"lit.");
  force_me("hmm");
  call_out("crysin3",10,TP);
}

void crysin3()
{
  force_me("say That may be easier said than done.  I sense more "+
	"magics coming from that pedestal...I believe I can make them "+
	"dim again, but you will have to figure out how to brighten "+
	"them all.");
  force_me("say Should you become confused, you may simply "+
	"%^GREEN%^restart%^RESET%^ the crystals to be all dim again.");
}

void done()
{
  force_me("clap");
  force_me("say Great job!  That portal surely leads you closer "+
	"to getting out of here.  I fear I can guide you no further, "+
	"my friends.  May the path you walk be forever lit.");
}
