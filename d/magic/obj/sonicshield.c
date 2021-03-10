#include <std.h>

inherit OBJECT;

int blocking = 0;
string exitname;
object caster;
int level;

void remove_wall();

void create() {
   ::create();
   set_name("sonic shield");
   set_short("%^RESET%^%^CYAN%^A blurred sonic shield%^RESET%^");
   set_long("%^RESET%^%^CYAN%^You can see a blurred field of %^BOLD%^"
"%^WHITE%^son%^CYAN%^i%^WHITE%^c energy%^RESET%^%^CYAN%^, causing the air "
"around it to vibrate violently.%^RESET%^");
   set_id( ({"shield","sonic shield","sonic field","field of sonic"}) );
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
   level = caster->query_guild_level("mage");
   wallname = whose+"surroundingfirewall";
   if(present(wallname,environment(caster))) {
      tell_object(caster,"%^BOLD%^%^CYAN%^The new wall simply melts into "
"the wall that is already surrounding you!%^RESET%^\n");
      tell_room(environment(caster),"%^BOLD%^%^CYAN%^The wall surrounding "
+caster->query_cap_name()+" glows brighter for a second.%^RESET%^\n");
      if(objectp(query_property("spell")))
         query_property("spell")->dest_effect();
      return;
   }
   add_id(wallname);
   j = sizeof(foes);
   for(k=0;k<j;k++) {
      if(!present(wallname,environment(caster))) continue;
      if(foes[k]->query_property("strength") &&
         strsrch(foes[k]->query_property("strength"),"sonic") != -1)
         continue;
      tell_room(environment(foes[k]),"%^CYAN%^"+foes[k]->query_cap_name()
+" leaps back as the sonic field rises up and catches "
+foes[k]->query_objective()+" on its edge!%^RESET%^",foes[k]);
      tell_object(foes[k],"%^CYAN%^You jump away as a piercing note "
"strikes your ears from the field of sonic that springs up around "
+caster->query_cap_name()+".%^RESET%^");
      if(foes[k]->query_property("undead")) dmg = 4+random(21);
      else dmg = 2+random(11);
      foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg,"sonic" );
      if(objectp(foes[k]))
         foes[k]->continue_attack();
//          foes[k]->set_attackers((object *)foes[k]->query_attackers() -({caster}) );
//          caster->set_attackers((object *)caster->query_attackers() -({foes[k]}) );
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
   foes = caster->query_attackers();
   j = sizeof(foes);
   for(k=0;k<j;k++) {
      if(!objectp(foes[k])) continue;
      if(foes[k]->query_property("strength") &&
         strsrch(foes[k]->query_property("strength"),"sonic") != -1)
         continue;
      tell_room(environment(foes[k]),"%^BOLD%^%^CYAN%^"+
foes[k]->query_cap_name()+" is buffeted by the sonic "
"field!%^RESET%^",foes[k]);
      tell_object(foes[k],"%^BOLD%^%^CYAN%^The scream of the sonic shield "
"echoes violently in your ears!%^RESET%^");
      if(foes[k]->query_property("undead")) dmg = 4+random(21);
      else dmg = 2+random(11);
      foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg,"sonic" );
      if(objectp(foes[k]))
         foes[k]->continue_attack();
   }
   call_out("monitor",7);
}

void block(object ob, string exitn) {
   string whose, wallname;

   blocking = 1;
   caster = ob;

   level = caster->query_guild_level("mage");
   exitname = exitn;
   set_short("%^RESET%^%^CYAN%^A sonic shield blocking the "+exitname);
   set_long("%^RESET%^%^CYAN%^You can see a blurred field of %^BOLD%^"
"%^WHITE%^son%^CYAN%^i%^WHITE%^c energy%^RESET%^%^CYAN%^, causing the air "
"around it to vibrate violently.  It fully blocks the "
+exitname+".%^RESET%^");
   whose = caster->query_name();
   wallname = whose+exitname+"firewall";
   if(present(wallname,environment(caster))) {
      tell_object(caster,"%^BOLD%^%^CYAN%^The new wall blurs into the "
"wall that is already blocking the "+exitname+".%^RESET%^\n");
      tell_room(environment(caster),"%^BOLD%^%^CYAN%^The wall blocking "
"the "+exitname+" glows brighter for a second.%^RESET%^\n");
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
            tell_object(caster,"%^CYAN%^The sonic shield"+exitdesc+
" fades away.%^RESET%^");
         else {
            tell_object(caster,"%^CYAN%^The sonic shield protecting you "
"fades away.%^RESET%^");
            caster->move(ETO);
         }
      }
      tell_room(ETO,"%^CYAN%^"+caster->query_cap_name()+"'s sonic "
"shield"+exitdesc+" fades away.%^RESET%^", notsee);
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
   if(TP->query_property("strength") &&
strsrch(TP->query_property("strength"),"sonic") != -1 ) {
      tell_object(TP,"%^BOLD%^%^CYAN%^You step calmly through the field "
"of sonic vibrations, totally unharmed.%^RESET%^");
      tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" steps calmly through the "
"field of sonic vibrations blocking the "+exitname+", totally "
"unharmed.%^RESET%^",TP);
      return 0;
   }
   tell_object(TP,"%^BOLD%^%^CYAN%^You rush quickly through the sonic "
"field as the vibrations scream in your ears!%^RESET%^");
   tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" rushes quickly through the "
"sonic field blocking the "+exitname+"!%^RESET%^",TP);
   if(TP->query_property("undead")) dmg = (roll_dice(2,6)+level+level/2)*2;
   else dmg = roll_dice(2,6)+level+level/2;
   TP->cause_typed_damage(TP,TP->return_target_limb(),dmg,"sonic" );
   if(TP) TP->continue_attack();
   return 0;
}

int end_walls(string str) {
   if(!caster || (TP != caster))
      return 0;
   if(str != "shield")
      return 0;
   if(objectp(query_property("spell")))
      query_property("spell")->dest_effect();
   return 1;
}

int query_blocking(){
   return blocking;
}
