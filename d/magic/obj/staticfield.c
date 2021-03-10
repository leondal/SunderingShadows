#include <std.h>

inherit OBJECT;

int blocking = 0;
string exitname;
object caster;
int level;

void remove_wall();

void create() {
   ::create();
   set_name("static field");
   set_short("%^YELLOW%^A crackling field of static%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^You can see a crackling field of "
"%^YELLOW%^sta%^WHITE%^t%^YELLOW%^ic en%^WHITE%^e%^YELLOW%^rgy%^RESET%^"
"%^ORANGE%^, sending jolts of electricity into the air around "
"it.%^RESET%^");
   set_id( ({"field","static field","electric field","static"}) );
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
      tell_object(caster,"%^YELLOW%^The new wall simply melds into the "
"wall that is already surrounding you!%^RESET%^\n");
      tell_room(environment(caster),"%^YELLOW%^The wall surrounding "
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
         strsrch(foes[k]->query_property("strength"),"electricity") != -1)
         continue;
      tell_room(environment(foes[k]),"%^YELLOW%^"+foes[k]->query_cap_name()
+" leaps back as a crackling field of static comes into being near "
+foes[k]->query_objective()+"!%^RESET%^",foes[k]);
      tell_object(foes[k],"%^YELLOW%^You leap back as a crackling field "
"of static comes into being around "
+caster->query_cap_name()+".%^RESET%^");
      if(foes[k]->query_property("undead")) dmg = 4+random(21);
      else dmg = 2+random(11);
      foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg,"electricity" );
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
         strsrch(foes[k]->query_property("strength"),"electricity") != -1)
         continue;
      tell_room(environment(foes[k]),"%^YELLOW%^"+
foes[k]->query_cap_name()+" is zapped by the field of "
"static!%^RESET%^",foes[k]);
      tell_object(foes[k],"%^YELLOW%^The static field crackles and zaps "
"you!%^RESET%^");
      if(foes[k]->query_property("undead")) dmg = 4+random(21);
      else dmg = 2+random(11);
      foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg,"electricity" );
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
   set_short("%^YELLOW%^A static field blocking the "+exitname);
   set_long("%^RESET%^%^ORANGE%^You can see a crackling field of "
"%^YELLOW%^sta%^WHITE%^t%^YELLOW%^ic en%^WHITE%^e%^YELLOW%^rgy%^RESET%^"
"%^ORANGE%^, sending jolts of electricity into the air around it.  It "
"fully blocks the "+exitname+".%^RESET%^");
   whose = caster->query_name();
   wallname = whose+exitname+"firewall";
   if(present(wallname,environment(caster))) {
      tell_object(caster,"%^YELLOW%^The new wall blurs into the wall that "
"is already blocking the "+exitname+".%^RESET%^\n");
      tell_room(environment(caster),"%^YELLOW%^The wall blocking the "
+exitname+" glows brighter for a second.%^RESET%^\n");
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
            tell_object(caster,"%^ORANGE%^The static field"+exitdesc+
" fades away.%^RESET%^");
         else {
            tell_object(caster,"%^ORANGE%^The static field protecting you "
"fades away.%^RESET%^");
            caster->move(ETO);
         }
      }
      tell_room(ETO,"%^ORANGE%^"+caster->query_cap_name()+"'s static field"
+exitdesc+" fades away.%^RESET%^", notsee);
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
strsrch(TP->query_property("strength"),"electricity") != -1 ) {
      tell_object(TP,"%^ORANGE%^You step calmly through the static field, "
"totally unharmed.%^RESET%^");
      tell_room(ETP,"%^ORANGE%^"+TPQCN+" steps calmly through the static "
"field blocking the "+exitname+", totally unharmed.%^RESET%^",TP);
      return 0;
   }
   tell_object(TP,"%^ORANGE%^You dash through the static field and the "
"air %^YELLOW%^cra%^WHITE%^c%^YELLOW%^kles %^RESET%^%^ORANGE%^over your "
"skin!%^RESET%^");
   tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" rushes quickly through the "
"static field blocking the "+exitname+", as the charged air %^YELLOW%^"
"cra%^WHITE%^c%^YELLOW%^kles %^RESET%^%^ORANGE%^over "+TP->QP+
" skin!%^RESET%^",TP);
   if(TP->query_property("undead")) dmg = (roll_dice(2,6)+level+level/2)*2;
   else dmg = roll_dice(2,6)+level+level/2;
   TP->cause_typed_damage(TP,TP->return_target_limb(),dmg,"electricity" );
   if(TP) TP->continue_attack();
   return 0;
}

int end_walls(string str) {
   if(!caster || (TP != caster))
      return 0;
   if(str != "field")
      return 0;
   if(objectp(query_property("spell")))
      query_property("spell")->dest_effect();
   return 1;
}

int query_blocking(){
   return blocking;
}
