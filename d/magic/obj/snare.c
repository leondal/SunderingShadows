//Based from glyph of warning object (minus caster warnings); please apply updates to both as needed -Nienne.
#include <std.h>
#include <daemons.h>
inherit "/d/magic/obj/glyphofwarding";

void create(){
    ::create();
    set_name("snare");
}

void init(){
int bonus,lvl;
   ::init();
   if(!TP->query_property("already_there") || (string)TP->query_property("already_there") != mycaster && !TP->query_true_invis()){
      if(TP->is_class("thief") && TP->query_hidden()){
         bonus = TP->query_stats("dexterity");
         bonus = (bonus - 10)/2;
         if(TP->is_singleClass()){
            lvl = (TP->query_guild_level("thief"));
            lvl = lvl+bonus;
         }
         else{
            lvl = 2*((int)TP->query_guild_level("thief"));
            lvl = lvl/3;
            lvl = lvl+bonus;
         }
//The thief code allows for hidden single class thieves to have
//a 50/50 chance of avoiding the glyph by sneaking.  Multi class
//thieves have a lower chance but still have a chance.
         if(random(lvl) > random(glyph_power)) success();
         else failure();
      }
      else{
//For everyone else, their wisdom gives them a chance to avoid the
//glyph.  So someone with an 18 wisdom has an 18% chance of avoiding
         bonus = TP->query_stats("wisdom");
         if(random(101) < bonus) success();
         else failure();
      }
   }
   else tell_object(TP,"%^BOLD%^%^GREEN%^You carefully avoid the snare, already aware of its presence.%^RESET%^");
}

void failure(){
   tell_object(find_player(mycaster),"%^BOLD%^%^GREEN%^You feel a brief "+
      "jerk on your senses as "+TPQCN+" trips your snare!%^RESET%^");
   tell_room(ETO,"%^BOLD%^%^GREEN%^"+TPQCN+" trips a hidden snare, and "+
      "stumbles in pain as short spikes drive into "+TP->QP+
      " feet!%^RESET%^",({TP,find_player(mycaster)}));
   tell_object(TP,"%^BOLD%^%^GREEN%^As you walk forward you trigger a "+
      "hidden snare, and short spikes drive into the undersides of your "+
      "feet!%^RESET%^");
   dam = glyph_power/3;
   if(dam < 1) dam = 1;
   if(dam > 12) dam = 12;
   dam = roll_dice(dam,6);
   TP->do_damage(TP->return_target_limb(),dam);
   TP->add_attacker(TO);
   TP->continue_attack();
   if(objectp(TP)) TP->remove_attacker(TO);
   self_destruct();
   return;
}

void success(){
   tell_object(TP,"%^RESET%^%^GREEN%^You carefully move into the "+
      "area, managing to avoid the concealed snare on the ground.%^RESET%^");
   return;
}

void self_destruct() {
int i;
object casterobj,*spells = ({});
   if(sizeof(mygroup)>0){
      for(i=0;i<sizeof(mygroup);i++){
         if(!objectp(mygroup[i])) break;
         if(!mygroup[i]->query_property("already_there")) break;
         if((string)mygroup[i]->query_property("already_there") != mycaster) break;
         mygroup[i]->remove_property("already_there");
      }
   }
//   if(sizeof(mini_mes)>0){
      for(i=0;i<sizeof(mini_mes);i++){
         if(objectp(mini_mes[i])){
//            tell_object(find_player(mycaster),"Removing mini mes.");
//The above was for debugging - leaving in case needed again.
            mini_mes[i]->remove();
         }
      }
//   }
   casterobj = find_player(mycaster);
   if(objectp(casterobj)){                  // Adjusted by Lujke 5th July 2010, to make this whole
     casterobj->remove_property("glyphed");  //section dependent on casterobj being a valid object
     spells += casterobj->query_property("dispellable spells");
     for(i=0;i<sizeof(spells);i++){
        if(objectp(spells[i])){
           if(!spells[i]->query_target_object()){
              if((string)spells[i]->query_spell_name() == "snare"){
                 if(!objectp(spells[i])) return notify_fail("Your snare seems to have been lost.\n");
                 tell_object(casterobj,"%^CYAN%^The energies holding the snare fade away.", TP);
                 spells[i]->removeSpellFromCaster();
              }
           }
        }
     }
   }
   if(objectp(TO)) TO->remove();
   return;
}
