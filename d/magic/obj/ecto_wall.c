#include <std.h>

inherit WEAPONLESS;

int blocking = 0;
string exitname;
object caster;
int level;

void remove_wall();

void create() {
   ::create();
   set_name("wall of ectoplasm");
   set_short("%^BOLD%^%^MAGENTA%^Wall of Ect%^CYAN%^o%^MAGENTA%^plasm%^RESET%^");
   set_long("%^BOLD%^%^MAGENTA%^This shimmering field is generated "+
      "from ectoplasm, a substance found on the Astral Plane.  "+
      "The wall generates a small amount of light, and energy "+
      "seems to radiate from it.%^RESET%^");
   set_id(({"wall","wall of ectoplasm","ectowall","ecto_wall","field","field of ectoplasm"}));
   set_gender("neuter");
   set_race("wall");
   add_limb("wall","",0,0,0);
   set_size(4);
   set_alignment(5);
   set_overall_ac(-50);
   set_hd(10,50);
   set_level(10);
   set_class("fighter");
   set_mlevel("fighter",10);
   set_hp(2000);
   set_max_hp(2000);
   set_damage(1,1);
   set_attacks_num(0);
   set_base_damage_type("slashing");
   remove_property("swarm");
   set("aggressive",0);
   remove_property("swarm");
   set_stats("strength",18);
   set_stats("dexterity",18);
   set_max_level(1);
   set_property("magic",1);
}

int do_damage(string str, int i){
    return 0;
}

int is_invincible(){ return 1;}

void init() {
   ::init();
   add_action("end_walls","remove");
/*
   if(blocking)
      add_action("damager",exitname);
*/
}

/*
Retaining this code, but the wall no longer has the option to surround the caster
void surround(object ob) {
   int k,j;
   object *foes;
   string whose,wallname;

   caster = ob;
   add_action("end_walls","remove");
   foes = caster->query_attackers();
   whose = caster->query_name();
   level = caster->query_guild_level("psion");
   wallname = whose+"surroundingectowall";
   if(present(wallname,environment(caster))) {
      tell_object(caster,"The new wall simply melts into the wall that is already surrounding you!\n");
      tell_room(environment(caster),"The wall surrounding "+caster->QCN+" glows brighter for a second.\n");
      if(objectp(query_property("spell")))
         query_property("spell")->dest_effect();
      return;
   }
   add_id(wallname);
   j = sizeof(foes);
   for(k=0;k<j;k++) {
      if(!present(wallname,environment(caster))) continue;
      tell_room(environment(foes[k]),"%^BOLD%^%^CYAN%^"+foes[k]->QCN+" is "+
         "struck by the might of the wall!",foes[k]);
      tell_object(foes[k],"%^BOLD%^%^CYAN%^You are struck by "+caster->QCN+"'s "+
         "wall of ectoplasm and feel a painful energy coursing "+
         "through your veins!");
      if(foes[k]->query_property("undead"))
         foes[k]->do_damage(foes[k]->return_target_limb(),4+random(21) );
      else
         foes[k]->do_damage(foes[k]->return_target_limb(),2+random(11) );
      if(objectp(foes[k]))
         foes[k]->continue_attack();
   }
   call_out("monitor",7);
}

void monitor() {
   int k,j;
   object *foes;

   if((!objectp(caster) || !present(caster->query_name(),ETO)) && !blocking) {
      if(objectp(query_property("spell"))) {
         query_property("spell")->dest_effect();
         return;
      }
      remove_call_out("monitor");
      TO->remove();
   }
   foes = caster->query_attackers();
   j = sizeof(foes);
   for(k=0;k<j;k++) {
      if(!objectp(foes[k])) continue;
      tell_room(environment(foes[k]),"%^BOLD%^%^CYAN%^"+foes[k]->QCN+" is "+
         "struck by the might of the wall!",foes[k]);
      tell_object(foes[k],"%^BOLD%^%^CYAN%^You are struck by "+caster->QCN+"'s "+
         "wall of ectoplasm and feel a painful energy coursing "+
         "through your veins!");
      if(foes[k]->query_property("undead"))
         foes[k]->do_damage(foes[k]->return_target_limb(),4+random(21) );
      else
         foes[k]->do_damage(foes[k]->return_target_limb(),2+random(11) );
      if(objectp(foes[k]))
         foes[k]->continue_attack();
   }
   call_out("monitor",7);
}
*/

void block(object ob, string exitn) {
   string whose, wallname;

   blocking = 1;
   caster = ob;
   if(caster->is_class("psywarrior")){
      level = caster->query_guild_level("psywarrior");
   }else{
      level = caster->query_guild_level("psion");
   }
   exitname = exitn;
   set_short("%^BOLD%^%^MAGENTA%^A wall of Ect%^CYAN%^o"+
      "%^MAGENTA%^plasm blocking the "+exitname+" exit%^RESET%^");
   set_long("%^BOLD%^%^MAGENTA%^This shimmering field is generated "+
      "from ectoplasm, a substance found on the Astral Plane.  "+
      "The wall generates a small amount of light, and energy "+
      "seems to radiate from it.  It fully blocks the "+exitname+" exit.%^RESET%^");
   set_stats("strength",(int)caster->query_stats("intelligence"));
   set_stats("dexterity",(int)caster->query_stats("intelligence"));
   set_hd(level,50);
   set_level(level);
   set_class("fighter");
   set_mlevel("fighter",level);

   whose = caster->query_name();
   wallname = whose+exitname+"ectowall";
   ETO->set_blocked(exitname,TO);
   if(present(wallname,environment(caster))) {
      tell_object(caster,"The new wall simply melts into the wall that is already blocking the "+exitname+"\n");
      tell_room(environment(caster),"The wall blocking the "+exitname+" glows brighter for a second.\n");
      if(objectp(query_property("spell")))
         query_property("spell")->dest_effect();
      return;
   }
   add_id(wallname);
}

void remove_wall() {
   object *notsee = ({});
   string exitdesc = "";

   if(blocking)
      exitdesc = ", blocking the "+exitname+",";
   if(objectp(caster) && objectp(ETO)) {
      if(present(caster,ETO)) {
         if(blocking)
            tell_object(caster,"%^CYAN%^Your wall of ectoplasm"+exitdesc+" dissipates away.");
         else {
            tell_object(caster,"%^CYAN%^The wall of ectoplasm that surrounds you dissipates away.");
         }
      }
      tell_room(ETO,"%^CYAN%^"+caster->QCN+"'s wall of ectoplasm"+exitdesc+" dissipates away.", caster);
   }
   destruct(TO);
   return;
}

int damager(string str) {
   if(TP->query_paralyzed() || TP->query_bound() || TP->query_tripped() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(caster)
      if((string)caster->query_name()==(string)TPQN )
         return 0;
   tell_object(TP,"%^BOLD%^%^MAGENTA%^You feel a painful surge of "+
      "energy as you walk through the wall!");
   tell_room(ETP,"%^BOLD%^%^MAGENTA%^"+TPQCN+" dashes through the "+
      "wall blocking the "+exitname+", as a crackle of energy "+
      "surrounds "+TP->QO+"!",TP);
   if( TP->query_property("undead") )
      TP->do_damage(TP->return_target_limb(),(roll_dice(2,6)+level+level/2)*2 );
   else
      TP->do_damage(TP->return_target_limb(),roll_dice(2,6)+level+level/2 );
   if(TP)
      TP->continue_attack();
   return 0;
}

int end_walls(string str) {
   if(!caster || (TP != caster))
      return 0;
   if(str != "wall")
      return 0;
   if(objectp(query_property("spell")))
      query_property("spell")->dest_effect();
   return 1;
}

int query_blocking(){
   return blocking;
}
