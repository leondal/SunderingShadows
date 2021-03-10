//worker4.c - workers to help advance the plot to open new Seneca
//They are being dropped in a few weeks before opening to give 
//players a hint.  They will disappear once the plot's done.
//~Circe~ 1/27/08
#include <std.h>
inherit MONSTER;

int head_home;

void create(){
string myrace,mydesc,mygender,myposs;
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
               myposs = "her";
               break;
      default: mygender = "male";
               myposs = "his";
               break;
   }
   set_name("painter");
   set_short("A skilled "+mydesc+" painter");
   set_id(({"worker",""+myrace+" painter",""+mydesc+" painter","painter",""+myrace+" painter",""+mydesc+" painter"}));
   set_long(
      "A leather backpack bristling with brushes, rags, and "+
      "other supplies is perched upon the back of this "+mygender+" "+
      "painter.  With "+myposs+" hair pulled out of the way and "+
      "buckets of paint in each hand, the painter looks ready "+
      "for work, but sadly seems to lack a building to paint.  "+
      "White coveralls cover the painter's body, marked here and "+
      "there with splashes of color that hint that the painter "+
      "has, in fact, painted before.");
   set_gender(""+mygender+"");
   set_race(""+myrace+"");
   set_body_type("humanoid");
   set_hd(10,3);
   set_exp(10);
   set_emotes(6,({
	"The "+mydesc+" painter shrugs "+myposs+" shoulders, easing tension.",
	"The painter stares blankly at a building, head tilted slightly.",
	"The painter's gaze moves slowly up the street, apparently counting.",	
   }),0);
   call_out("head_home",400+random(100));
}

int head_home(){
	tell_room(ETO,"%^BOLD%^%^GREEN%^The painter sighs and hefts the buckets of paint, going home.");
	TO->move("/d/shadowgate/void");
	destruct(TO);
	return 1;
}
