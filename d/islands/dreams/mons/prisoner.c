#include <std.h>
#include "../defs.h"
inherit NPC;

int talking = 0;

void create(){
  	::create();
  	set_name("prisoner");
  	set_short("A gaunt and sickly looking human male prisoner");
  	set_id(({"prisoner","human"}));
  	set_long("This poor broken and battered man looks as if he"+
		" has been here for some time.  His matted hair hangs"+
		" in dirty clumps down his back.  His full shaggy beard"+
		" is shot through with white hair, even though he does "+
		"not look old enough to be going gray.  His gaunt face "+
		"and body highlight nearly every bone in his body.  "+
		"Dressed in a dirty rotting loin cloth, his scars and"+
		" old wounds are on display. On his right forearm the"+
		" faded inked tattoo of a gauntlet with an eye can be"+
		" seen.");
  	set_race("human");
  	set_body_type("human");
  	set_class("fighter");
  	set_hd(30,1);
  	set_hp(1000);
  	set_diety("helm");
  	set_alignment(1);
  	remove_std_db();
  	set_gender("male");
  	command("speech whisper in a raspy voice");
}

init()
{
  ::init();
  if(talking == 0)
  {
    talking = 1;
    call_out("greet",5,TP);
  }
}

void greet()
{
  force_me("say Please, "+TP->query_race()+", help us!  "+
	"I beg of you, we do not belong here!");
  call_out("step1",7);
}

void step1()
{
  force_me("say Our village was raided...it must have been weeks "+
	"ago by now, though time seems to have stood still for us.");
  call_out("step2",7);
}

void step2()
{
  force_me("say I awoke to screams one night.  I looked around to "+
	"what was going on, only to realize...the screams, they came "+
	"from my wife...this creature was holding her in the air, just "+
	"before he...");
  force_me("emote lowers his head as his body shakes softly, tears "+
	"falling to the ground.");
  call_out("step3",10);
}

void step3()
{
  force_me("emote wipes the tears from his face and looks up again.");
  force_me("say At least she didn't have to suffer through this.  "+
	"Everyday these beasts, they come here to torture us again and "+
	"again.");
  call_out("step3andahalf",10);
}

void step3andahalf()
{
  force_me("say Just when you think death will finaly grant you peace, "+
	"they use their foul magics to heal us, just enough to keep on "+
	"breathing.  I beg of you, free us!!!");
  call_out("step4",10);
}

void step4()
{
  if(!present("black abishai"))
  {
    new(MON+"abishai.c")->move(ETO);
    tell_room(ETO,"A tall, scaley beast rushes into the room");
  }
  force_me("say Oh god, he is back again...please save us!");
  call_out("callhim",7);
}

void callhim()
{
  present("black abishai",ETO)->step5();
}  

void step9()
{
  force_me("say NO!  It is you who deserves to die, foul beast!");
  force_me("emote looks back to you, with tear filled eyes.");
  call_out("step10",10);
}

void step10()
{
  force_me("say I do not know what god sent you to us, but I can "+
	"only hope that one of our prayers have been answered, and "+
	"you are here to free us.  Please, kill the beast and set "+
	"us free!");
  call_out("step11",10);
}

void step11()
{
  if(present("black abishai",ETO)->step12()) talking = 1;
}
