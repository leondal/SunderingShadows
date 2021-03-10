#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
#include "/d/common/common.h"
inherit "/d/dagger/Torm/mon/dayperson.c";

void create (){
  ::create ();
  set_id(({"torm tax collector","tax collector","tax man","collector"}));
  set_property("swarm",1);
  switch(random(2)){
      case 0:  set_name("sheldon");
               set_gender("male");
               set_race("human");
               set_short("Sheldon, a tax collector");
               add_id("sheldon");
               set_long("Sheldon is a young man in his mid-twenties.  "+
                  "He has short blonde hair that just brushes his ears, "+
                  "and his eyes are a watery blue that seem to match "+
                  "the Dagger Sea outside these doors.  He is dressed "+
                  "in a leather jerkin and breeches with tall black "+
                  "boots that reach his knees.  He seems to be a neat, "+
                  "ordered young man, and it seems likely he will "+
                  "someday rise out of this office to do bigger things.");
               break;
      default:  set_name("maryAnn");
               set_gender("female");
               set_race("half-elf");
               add_id("maryann");
               set_short("MaryAnn, a tax collector");
               set_long("MaryAnn is an energetic young woman who "+
                  "walks with the swagger of so many sailors.  She "+
                  "has clear chestnut eyes that match the shade of "+
                  "her long hair, which is kept pulled into a ponytail "+
                  "running down her back.  Despite being a tax "+
                  "collector, she is dressed in well-made leather armor "+
                  "and seems quite confident with the weapon at her "+
                  "side.");
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