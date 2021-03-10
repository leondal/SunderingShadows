#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
#include "/d/common/common.h"
#include <daemons.h>

inherit "/d/dagger/Torm/mon/dayperson.c";

void create (){
  ::create ();
  set_id(({"torm tax collector","tax collector","tax man","collector"}));
  set_property("swarm",1);
  switch(random(2)){
      case 0:  set_name("carson");
               set_gender("male");
               set_race("half-elf");
               add_id("carson");
               set_short("Carson, a tax collector");
               set_long("Carson is a half-elf who is beginning to show "+
                  "his age.  His hair is a salt-and-pepper that just "+
                  "brushes his shoulders, and he wears a pair of silver "+
                  "half-glasses over his pale blue eyes.  His is dressed "+
                  "in a simple tunic above flowing cotton pants, with "+
                  "his feet clad in sandals.  An air of confidence hangs "+
                  "about the man, and despite his position as a tax "+
                  "collector, he has a dangerous glint in his eyes.");
               break;
      default:  set_name("kalidas");
               set_gender("male");
               set_race("human");
               add_id("kalidas");
               set_short("Kalidas, a tax collector");
               set_long("Kalidas is a dark-skinned male human with "+
                  "flowing black hair.  His eyes are a glittering deep "+
                  "brown that seem somehow enhanced by his skin tone.  "+
                  "He wears a richly embroidered red kameez above "+
                  "black salwar, though he seems to have adopted the "+
                  "cork sandals typical of the sailors in Torm.  Every "+
                  "move he makes is fluid and seems to possess an "+
                  "implied power.");
               break;
   }
   set_hd(18,1);
   set_size(2);
   set_class("fighter");
   set_mlevel("fighter",18);
   set_property("full attacks",1);
   set_stats("strength",18);
   set_stats("intelligence", 16);
   set_stats("dexterity", 17);
   set_stats("charisma", 16);
   set_stats("wisdom", 10);
   set_stats("constitution", 14);
   set_alignment(5);
   set_max_hp(random(200)+40);
   set_hp(query_max_hp());
   set_exp(1500);
   set("aggressive", 0);
   add_money("gold", 50 + random(100));
   set_overall_ac(-2);
   RANDGEAR->arm_me(TO,"edgedm",25,1,50);
   RANDGEAR->armor_me(TO,"armorlt",10,1,75);
}

int kill_ob(object victim, int which){
//Note:  If someone is on the list that shouldn't be (i.e. name was used by
//another player that is gone), you can use the following eval to clear it
//eval return SAVE_D->remove_name_from_array("Torm_dock_killers", "stringname")
    int hold;
    hold = ::kill_ob(victim, which);
    command("say %^BOLD%^You will pay for this!!");
    log_file("reports/tormdocks",""+capitalize(victim->query_true_name())+" "+
       "attacked "+capitalize(TO->query_name())+".  "+
       "["+ctime(time())+"].\n");
    return hold;
}
