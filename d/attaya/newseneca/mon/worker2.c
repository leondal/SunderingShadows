//worker2.c - workers to help advance the plot to open new Seneca
//They are being dropped in a few weeks before opening to give 
//players a hint.  They will disappear once the plot's done.
//~Circe~ 1/27/08
#include <std.h>
inherit MONSTER;

int head_home;

void create(){
string myrace,mydesc;
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
   set_name("roofer");
   set_short("A skilled "+mydesc+" roofer");
   set_id(({"worker",""+myrace+" worker",""+mydesc+" worker","roofer",""+myrace+" roofer",""+mydesc+" roofer"}));
   set_long(
      "This "+mydesc+" thatcher is dressed for the job, wearing "+
      "thick pants gathered at the ankles and a shirt that seems "+
      "to let the skin breathe.  A straw hat covers his head, "+
      "blocking out the worst of the hot Attaya sun.  The confused "+
      "expression on his face hints that the sun has indeed "+
      "gotten to him though, as he wanders the streets staring "+
      "blankly at the buildings and muttering to himself.");
   set_gender("male");
   set_race(""+myrace+"");
   set_body_type("humanoid");
   set_hd(10,3);
   set_exp(10);
   set_emotes(6,({
	"The roofer scratches his chin and mutters as he looks around.",
	"The roofer points towards the buildings as he mumbles and seems to count them.",
	"%^RESET%^%^MAGENTA%^The roofer says gruffly%^RESET%^: I know I roofed that one yesterday!",
	"The roofer shakes his head in confusion.",	
   }),0);
   call_out("head_home",400+random(100));
}

int head_home(){
	tell_room(ETO,"%^BOLD%^%^GREEN%^The roofer shrugs his broad shoulders and gives up, going home.");
	TO->move("/d/shadowgate/void");
	destruct(TO);
	return 1;
}
