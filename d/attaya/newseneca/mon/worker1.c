//worker1.c - workers to help advance the plot to open new Seneca
//They are being dropped in a few weeks before opening to give 
//players a hint.  They will disappear once the plot's done.
//~Circe~ 1/27/08
#include <std.h>
inherit MONSTER;

int head_home;

void create(){
string myrace,mydesc,mygender;
   ::create();
   switch(random(7)){
      case 0:  myrace = "half-elf";
               mydesc = "half-elven";
               break;
      case 1:  myrace = "elf";
               mydesc = "elven";
               break;
      case 2:  myrace = "dwarf";
               mydesc = "dwarven";
               break;
      default: myrace = "human";
               mydesc = "human";
               break;
   }
   switch(random(4)){
      case 0:  mygender = "female";
               break;
      default: mygender = "male";
               break;
   }
   set_name("worker");
   set_short("A skilled "+mydesc+" worker");
   set_id(({"worker",""+myrace+" worker",""+mydesc+" worker","worker",""+myrace+" worker",""+mydesc+" worker"}));
   set_long(
      "Carrying a basket of supplies, this "+mygender+" "+mydesc+" "+
      "worker walks slowly through the streets of Seneca as if "+
      "lost.  An intelligent expression lurks behind the eyes, but "+
      "the slack-jawed confusion makes this worker seem anything "+
      "but smart.  Clearly dressed for physical labor, the worker "+
      "wears sturdy burlap pants and a thin shirt to help fight "+
      "the heat of Attaya.");
   set_gender(""+mygender+"");
   set_race(""+myrace+"");
   set_body_type("humanoid");
   set_hd(10,3);
   set_exp(10);
   set_emotes(6,({
	"The worker walks a few steps before stopping and turning to walk the other way.",
	"The worker stares at a nearby building and frowns in consternation.",
	"The worker shifts the basket's weight and counts the nearby buildings.",	
   }),0);
   call_out("head_home",400+random(100));
}

int head_home(){
	tell_room(ETO,"%^BOLD%^%^GREEN%^The worker sighs and hefts the basket, heading home.");
	TO->move("/d/shadowgate/void");
	destruct(TO);
	return 1;
}
