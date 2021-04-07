/* Originally by Tristan, edited by Grendel to lower length of paralysis, but add a factor to incapacitate. */
// Fixed so should always change value when empty.  *Styx* 9/8/02
// Another fix by Garrett to keep tp as a variable around so that this_player() being 0 doesn't fuck things up?
// stuck in a new function that reveals all hidden people in the room for 2-4 seconds or so -Ares
// locked to new 'tools of the trade' feat for thieves and bards. N, 4/15.
#include <std.h>
#include <daemons.h>
#include <magic.h>
#define DAMNIT 0

inherit OBJECT;

int uses;

void create() {
   ::create();
   set_name("small bag");
   set("id",({"powder","bag","blinding powder"}));
   set_obvious_short("a small bag of powder");
   set_short("blinding powder");
   set("long",
       "This bag contains a collection of powders mixed into quite "
       "a fetid mixture.  Whiffs of ammonia and other irritants reach "
       "your nose as you inspect the bag.  You feel that if you <toss powder> "
       "at some target's eyes and hit would hurt them badly.  You could also "
       "spread the powder in a wide circle and <reveal> anyone hidden "
       "in the room.");
   set_value(200);
   set_weight(2);
   uses = random(5) + 5;
}

void init() {
   ::init();
   add_action("toss","toss");
   add_action("find_em","reveal");
}

int invis_again(object here)
{
    object obj;
    if(!objectp(here)) { return 1; }
    here->set_property("no invis",-1);
    return 1;
}

int find_em(string str)
{
    object here;
    if(!objectp(TP)) { return 1; }
    if(!objectp(ETP)) { return 1; }
    if(TP->query_property("shapeshifted"))
    {
        tell_object(TP,"You can't use powder while shapeshifted");
        return 1;
    }
    if(userp(TP) && !FEATS_D->usable_feat(TP,"tools of the trade")) {
        tell_object(TP,"You wouldn't know how to use that!");
        return 1;
    }
    if((int)TP->is_retinue()) {
        tell_object(TP,"You wouldn't know how to use that!");
        return 1;
    }
    if(!uses)
    {
        tell_object(TP,"The bag is empty!");
        return 1;
    }
    here = ETP;
    tell_object(TP,"%^BOLD%^%^CYAN%^You whirl the powder in sweeping arc, causing the "
        "dust to settle over everything nearby!%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" whirls a bag of powder in a sweeping arc, "
        "the dust coats everything in the room!%^RESET%^",TP);
    here->set_property("no invis", 1);
    uses -= 2;
    "/daemon/delay_d"->sleep(base_name(TO),"invis_again",10,({ here }));
    return 1;
}

int toss(string str) {
   string who, newwho;
   object ob;

   if(!str) return notify_fail("Syntax: toss powder at <target>\n");
   if(TP->query_property("shapeshifted"))
   {
       tell_object(TP,"You can't use powder while shapeshifted.");
       return 1;
   }
    if(userp(TP) && !FEATS_D->usable_feat(TP,"tools of the trade")) {
        tell_object(TP,"You wouldn't know how to use that!");
        return 1;
    }
    if((int)TP->is_retinue()) {
        tell_object(TP,"You wouldn't know how to use that!");
        return 1;
    }

   if(sscanf(str,"powder at %s",who) != 1) return notify_fail("Syntax: toss powder at <target>\n");

   if(TP->query_bound() || TP->query_unconscious()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(uses < 1) {
      notify_fail("The bag is empty!");
      set_short("An empty bag");
    set_value(1);
    set("coin type","copper");
      set_long("This empty bag used to hold powder with irritants, now it's size and strength render it useless.");
      while(query_property("no offer")){
         remove_property("no offer");
      }
      return 0;
   }
   if(TP->query_polymorphed()) return notify_fail("Not in your current polymorphed form.\n");
   if(TP->id("summoned monster") || TP->id("elemental")) return notify_fail("Not you!\n");

   if(TP->query_paralyzed()){
      return notify_fail(TP->query_paralyze_message());
   }

   if(!(ob=present(who,ETP))){
       tell_room(ETP, "%^BOLD%^%^CYAN%^You see "+TPQCN+" reach into a small bag, from which "+TP->query_subjective()+" pulls a handful of powder and throws it in the air!",({TP}));
       tell_room(ETP,"%^BOLD%^%^CYAN%^The cloud of dust formed by the powder billows about but the cloud doesn't seem to hit anything.",ob);
       uses -= 1;
       return 1;
   }

   if(ob->query_property("powdered")) return notify_fail("Jeez, isn't once enough for a little while?\n");

   if(!TP->kill_ob(ob,0)) return 1;

   tell_room(ETP, "%^BOLD%^%^CYAN%^You see "+TPQCN+" reach into a small bag, from which "+TP->query_subjective()+" pulls a handful of powder and throws it in the air!",({TP}));
   tell_object(TP,"%^BOLD%^%^CYAN%^You reach into the bag and grab a handful of powder and toss it!\n");

   TP->set_paralyzed(2,"%^CYAN%^%^BOLD%^You are busy throwing the dust!%^RESET%^");

   if(!ob->reflex_save(10 + TP->query_skill("thievery"))) {
     tell_room(ETP,"%^BOLD%^%^CYAN%^The cloud of dust formed by the powder billows toward "+ob->query_cap_name()+", and "+ob->query_subjective()+" tries to avoid the cloud, but is unsuccessful.",ob);
     tell_room(ETP,"%^BOLD%^%^CYAN%^The irritants in the dust quickly effect "+ob->query_cap_name()+"'s eyes causing "+ob->query_objective()+" to become paralyzed with stinging pain.",ob);
     tell_object(ob,"%^BOLD%^%^CYAN%^The dust cloud billows toward you. You try to avoid the cloud but it hit's you full in the face!\n");
     tell_object(ob,"%^BOLD%^%^CYAN%^The irritants in the dust quickly effect your eyes causing you to become paralyzed with stinging pain!\n");
      ob->set_tripped(roll_dice(1,6), "%^BOLD%^%^YELLOW%^Your eyes are burning and searing with pain!%^RESET%^");
      ob->set_temporary_blinded(roll_dice(1,6));
      ob->set_property("powdered", 1);
      call_out("undo_incap", (ROUND_LENGTH * 12), ob);
   }
   else{
     tell_room(ETP,"%^BOLD%^%^CYAN%^The cloud of dust formed by the powder billows about but the cloud doesn't seem to hit anything.",ob);
     tell_object(ob, "%^BOLD%^%^CYAN%^The cloud of dust formed by the powder billows toward you, but you turn your head and avoid the cloud of irritants!\n");
   }

   uses -=1;

   if(uses < 1) {
      set_short("An empty bag");
      set_long("This empty bag used to hold powder with irritants, now it's size and strength render it useless.");
      set_value(1);    // above only fixed value on a toss when already empty
      set("coin type","copper");
   }
   return 1;
}

int undo_incap(object ob) {
   if(!objectp(ob)) return 1;
   tell_object(ob, "%^BOLD%^%^GREEN%^Your tears clear the last of that heinous substance from your eyes, and you resume attack with a vengeance!\n");
   tell_room(environment(ob), "%^BOLD%^%^CYAN%^"+ob->query_cap_name()+"'s tears finally clear away all the powder, and "+ob->query_subjective()+" attacks with a vengeance!!\n", ob);
   ob->remove_property("powdered");
   return 1;
}
