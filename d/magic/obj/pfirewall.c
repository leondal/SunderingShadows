#include <std.h>
inherit OBJECT;

int blocking = 0;
string exitname;
object caster;
int level;

void remove_wall();

void create() {
   ::create();
   set_name("wall of fire");
   set_short("A wall of fire");
   set_long("%^BOLD%^%^CYAN%^You see a massive opaque sheet of fire raging wildly upward in shades of %^BOLD%^%^BLUE%^cobalt blue%^BOLD%^%^CYAN%^.%^RESET%^");
   set_id( ({"wall","wall of fire","firewall","fire"}) );
   set_weight(10000);
   set_value(0);
   set_property("no animate",1);
}

void init() {
   ::init();
   add_action("end_walls","remove");
   if(blocking)
      add_action("damager",exitname);
}

void surround(object ob) {
   int k,j,dmg;
   object *foes;
   string whose,wallname;

   caster = ob;
   add_action("end_walls","remove");
   foes = caster->query_attackers();
   whose = caster->query_name();
   level = caster->query_guild_level("warlock");
   wallname = whose+"surroundingfirewall";
   if(present(wallname,environment(caster))) {
      tell_object(caster,"%^BOLD%^%^WHITE%^The new wall of flame simply melts into the wall that is already surrounding you!\n");
      tell_room(environment(caster),"%^BOLD%^%^WHITE%^The wall of flame surrounding "+caster->QCN+" glows brighter for a second.\n");
      if(objectp(query_property("spell")))
         query_property("spell")->dest_effect();
      return;
   }
   add_id(wallname);
   j = sizeof(foes);
   for(k=0;k<j;k++) {
      if(!present(wallname,environment(caster))) continue;
      if(foes[k]->query_property("strength") &&
         strsrch(foes[k]->query_property("strength"),"fire") != -1)
         continue;
      tell_room(environment(foes[k]),"%^BOLD%^%^CYAN%^"+foes[k]->QCN+" is singed by the flames and leaps back as they rise up!",foes[k]);
      tell_object(foes[k],"%^BOLD%^%^CYAN%^You get singed by the flames and jump away from "+caster->QCN+" as they spring up around "+caster->QO+".");
      if(foes[k]->query_property("undead")) dmg = 4+random(21);
      else dmg = 2+random(11);
      foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg/2,"fire" );
      foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg/2,"untyped" );
      if(objectp(foes[k])) foes[k]->continue_attack();
   }
   call_out("monitor",7);
}

void monitor() {
   int k,j,dmg;
   object *foes;

   if((!objectp(caster) || !present(caster->query_name(),ETO)) && !blocking) {
      if(objectp(query_property("spell"))) {
         query_property("spell")->dest_effect();
         return;
      }
      remove_call_out("monitor");
      TO->remove();
   }
   if(objectp(caster)) {
     foes = caster->query_attackers();
     j = sizeof(foes);
     for(k=0;k<j;k++) {
       if(!objectp(foes[k])) continue;
       if(foes[k]->query_property("strength") &&
         strsrch(foes[k]->query_property("strength"),"fire") != -1)
         continue;
       tell_room(environment(foes[k]),"%^BOLD%^%^CYAN%^"+foes[k]->query_cap_name()+" is burned by the flames!",foes[k]);
       tell_object(foes[k],"%^BOLD%^%^CYAN%^You get burned by the flames!");
       if(foes[k]->query_property("undead")) dmg = 4+random(21);
       else dmg = 2+random(11);
       foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg/2,"fire" );
       foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg/2,"untyped" );
       if(objectp(foes[k])) foes[k]->continue_attack();
     }
   }
   call_out("monitor",7);
}

void block(object ob, string exitn) {
   string whose, wallname;

   blocking = 1;
   caster = ob;

   level = caster->query_guild_level("mage");
   exitname = exitn;
   set_short("A wall of fire blocking the "+exitname);
   set_long("%^BOLD%^%^CYAN%^You see a massive opaque sheet of fire raging wildly upward in shades of %^BOLD%^%^BLUE%^cobalt blue%^BOLD%^%^CYAN%^. It fully blocks the "+exitname+".");
   whose = caster->query_name();
   wallname = whose+exitname+"firewall";
   if(present(wallname,environment(caster))) {
      tell_object(caster,"%^BOLD%^%^WHITE%^The new wall simply melts into the wall that is already blocking the "+exitname+"\n");
      tell_room(environment(caster),"%^BOLD%^%^WHITE%^The wall blocking the "+exitname+" glows brighter for a second.\n");
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
         notsee = ({caster});
         if(blocking)
            tell_object(caster,"%^CYAN%^Your wall of flame"+exitdesc+" dissipates away.");
         else {
            tell_object(caster,"%^CYAN%^The wall of flame that surrounds you dissipates away.");
            caster->move(ETO);
         }
      }
      tell_room(ETO,"%^CYAN%^"+caster->QCN+"'s wall of flame"+exitdesc+" dissipates away.", notsee);
   }
   destruct(TO);
   return;
}

int damager(string str) {
   int dmg;
   if(TP->query_paralyzed() || TP->query_bound() || TP->query_tripped() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(caster)
      if((string)caster->query_name()==(string)TPQN )
         return 0;
   if(TP->query_property("strength") && strsrch(TP->query_property("strength"),"fire") != -1 ) {
      tell_object(TP,"%^BOLD%^%^CYAN%^You step into the cobalt inferno, walking calmly through the flames, unharmed.");
      tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" walks calmly into the cobalt inferno blocking the "+exitname+", unaffected by the flames.",TP);
      return 0;
   }
   tell_object(TP,"%^BOLD%^%^CYAN%^You step into the cobalt inferno, rushing through before the flames engulf you.");
   tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" rushes into the cobalt inferno blocking the "+exitname+", as the flames attack "+TP->query_objective()+"!",TP);

   if(TP->query_property("undead")) dmg = (roll_dice(2,6)+level+level/2)*2;
   else dmg = roll_dice(2,6)+level+level/2;
   TP->cause_typed_damage(TP,TP->return_target_limb(),dmg/2,"fire" );
   TP->cause_typed_damage(TP,TP->return_target_limb(),dmg/2,"untyped" );
   if(TP) TP->continue_attack();
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
