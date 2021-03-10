#include <std.h>
#include "../defs.h"
inherit NPC;

void create(){
  ::create();
  set_name("Comadon");
  set_short("The spirit of Comadon");
  set_id(({"comadon","Comadon","spirit"}));
  set_long("%^CYAN%^The spirit of a once proud warrior shimmers before "+
	"you.  Even in death, he stands tall...holding himself in "+
	"such a way that he gives off an aura of nobility.  His "+
	"face, however, tells a different story than his stance.  "+
	"His translucent eyes seem weary, and his jaw is set in "+
	"grim determination.");
  set_race("human");
  set_body_type("human");
  set_class("paladin");
  set_hd(30,1);
  set_hp(1000);
  set_diety("helm");
  new("/d/shadow/room/city/cguild/paladin/hlyplate")->move(TO);
  command("wear plate");
  new("/d/shadow/room/city/cguild/paladin/hlycoif")->move(TO);
  command("wear coif");
  new("/d/shadow/obj/weapon/longsword")->move(TO);
  command("wield sword");
  new("/d/shadow/obj/armor/mshield")->move(TO);
  command("wear shield");
  set_unique(1);
  set_alignment(1);
  remove_std_db();
  set_gender("male");
}

init()
{
   ::init();
  add_action("teleport","teleport");
  add_action("awaken","awaken");
	if(interactive(TP) && !TP->query_invis()) {
		  call_out("greet",1,TP);
	}
}
void greet()
{

   force_me("say Spare me a moment of your time, "+
	""+TP->query_race()+"?  I believe I may have some "+
	"%^CYAN%^information %^RESET%^that can help you here.");
}

void teleport()
{
  force_me("say I wish you well, "+TP->query_race()+".  I shall "+
	"send you deeper into the void.");
  force_me("salute "+TPQN+"");
  TP->move_player(ROOMS+"maze1");
  return 1;
}

void catch_say(string message)
{
  if(strsrch(message,"information") != -1)
  {
    call_out("do_information",1,TP);
    return 1;
  }
  else if(strsrch(message,"wake") != -1)
  {
    call_out("do_wake",1,TP);
    return 1;
  }
  else if(strsrch(message,"teleport") != -1)
  {
    call_out("do_teleport",1,TP);
    return 1;
  }
}

int do_information()
{
  force_me("sigh");
  force_me("say I assume you fell asleep upon the same small island "+
	"that has doomed us all?");
  call_out("do_information2",5,TP);
  return 1;
}

int do_information2()
{
  force_me("say I do not know of much, except that I failed in my "+
	"my duties to protect my charge.  Kreysneothosies seems to have left "+
	"me here until I can redeem myself to him.  I have learned "+
	"how to traverse between regions in this area, and can "+
	"%^CYAN%^teleport%^RESET%^ you deeper or %^CYAN%^wake%^RESET%^ "+
	"you up.");
  return 1;
}


int do_wake()
{
  force_me("say It is a strange situation you are in, but I shall "+
	"try to explain.");
  call_out("do_wake2",5,TP);
  return 1;
}

int do_wake2()
{
  force_me("say You are here, but not really here.  I do not know "+
	"for sure where your body is, but do not for one moment think "+
	"this is all just an illusion.  No amount of disbelieving will "+
	"save you from the horrors within.  I can %^GREEN%^awaken "+
	"%^RESET%^you if you like, but if you are stranded on that "+
	"island, then your only hope is to destroy whatever it is that "+
	"brought you here.  I could %^CYAN%^teleport%^RESET%^ you "+
	"deeper into the void to investigate, if you like.  Though I"+
	" caution you that the dangers are great.  Death is very possible.");
  return 1;
}

int do_teleport()
{
  force_me("say I do not know exactly what has brought us to this "+
	"realm, but I know it resides deeper than I have been able "+
	"to traverse.  Should you be able to destroy that which "+
   "binds us here, it may be your only chance to truly escape "+
	"this region.");
  call_out("do_teleport2",5,TP);
  return 1;
}

int do_teleport2()
{
  force_me("say If you feel confident, I can "+
	"%^GREEN%^teleport%^RESET%^ you deeper into the void.  "+
      "It is all I can do to help protect future innocents from falling "+
	"to the same fate as I have.  "+
	"The cleric, Adilon, made it much deeper than I.  He may have "+
   "more information.  Seek him out, if you wish to be truly free "+
	"again.");
  return 1;
}

void awaken()
{
  force_me("say I hope you can manage to escape that cursed "+
	"island.");
  tell_room(TP,"%^YELLOW%^Comadon reaches out with his shimmering "+
	"hand.  Just as his fingers touch your forehead, you suddenly "+
	"snap awake.  You look around, and find yourself back in "+
	"the tiny hut.");
  TP->move_player(ROOMS+"hut");
  return 1;
}
