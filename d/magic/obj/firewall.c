#include <std.h>

inherit OBJECT;

int blocking = 0;
string exitname;
object caster;
object spellob;
int level;

void remove_wall();

void create() {
   ::create();
   set_name("wall of fire");
   set_short("%^BOLD%^%^RED%^A %^RESET%^%^MAGENTA%^w%^BOLD%^%^RED%^all %^RESET%^%^MAGENTA%^o%^BOLD%^%^RED%^f %^RESET%^%^MAGENTA%^f%^BOLD%^%^RED%^ire%^RESET%^");
   set_long("%^BOLD%^%^RED%^You see a massive opaque sheet of fire raging wildly upward in shades of %^MAGENTA%^violet %^RED%^and red.");
   set_id( ({"wall","wall of fire","firewall","fire","mirror"}) );
   set_weight(10000);
   set_value(10000);
   set_property("no animate",1);
 }

void init() {
   ::init();
   add_action("end_walls","remove");
   if(blocking)
      add_action("damager",exitname);
}

void surround(object ob, object spell) {
   int k,j,dmg;
   object *foes;
   string whose,wallname;

   caster = ob;
   add_action("end_walls","remove");
   foes = caster->query_attackers();
   whose = caster->query_name();
   level = spell->query_clevel();
   spellob = spell;
   wallname = whose+"surroundingfirewall";
   if(present(wallname,environment(caster))) {
      tell_object(caster,"The new wall simply melts into the wall that is already surrounding you!\n");
      tell_room(environment(caster),"The wall surrounding "+caster->query_cap_name()+" glows brighter for a second.\n");
      if(objectp(query_property("spell")))
         query_property("spell")->dest_effect();
      return;
   }
   add_id(wallname);
   j = sizeof(foes);

   if(j)
       tell_room(environment(foes[k]),"%^BOLD%^%^RED%^"+caster->QCN+"'s enemies are singed by the flames and leaps back as they rise up!",foes[k]);
   for(k=0;k<j;k++)
   {
       if(!present(wallname,environment(caster))) continue;
       if(foes[k]->query_property("strength") &&
          strsrch(foes[k]->query_property("strength"),"fire") != -1)
           continue;
       dmg = spellob->query_base_damage();
       tell_object(foes[k],"%^BOLD%^%^RED%^You get burned by the flames!");
       foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg,"fire" );

       if(objectp(foes[k]))
           foes[k]->continue_attack();
   }
   call_out("monitor",7);
}

void monitor() {
   int k,j,dmg;
   object *foes;

   if ((!objectp(caster) || !present(caster->query_name(), ETO)) && !blocking) {
       if (objectp(query_property("spell"))) {
           query_property("spell")->dest_effect();
           return;
       }
       remove_call_out("monitor");
       TO->remove();
       return;
   }
   if (!objectp(environment(TO))) {
       TO->remove();
       return;
   }
   if (objectp(caster)) {
       foes = caster->query_attackers();
       j = sizeof(foes);
       if (j) {
           tell_room(environment(TO), "%^BOLD%^%^RED%^" + caster->QCN + "'s enemies are singed by the flames!", foes[k]);
           for (k = 0; k < j; k++) {
               if (!objectp(foes[k])) {
                   continue;
               }
               if (foes[k]->query_property("strength") &&
                   strsrch(foes[k]->query_property("strength"), "fire") != -1) {
                   continue;
               }
               tell_object(foes[k], "%^BOLD%^%^RED%^You get burned by the flames!");
               dmg = spellob->query_base_damage();
               foes[k]->cause_typed_damage(foes[k], foes[k]->return_target_limb(), dmg, "fire");
               if (objectp(foes[k])) {
                   foes[k]->continue_attack();
               }
           }
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
   set_long("%^BOLD%^%^RED%^You see a massive opaque sheet of fire raging wildly upward in shades of %^MAGENTA%^violet %^RED%^and red.  It fully blocks the "+exitname+".");
   whose = caster->query_name();
   wallname = whose+exitname+"firewall";
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
         notsee = ({caster});
         if(blocking)
            tell_object(caster,"%^RED%^Your wall of flame"+exitdesc+" dissipates away.");
         else {
            tell_object(caster,"%^RED%^The wall of flame that surrounds you dissipates away.");
            caster->move(ETO);
         }
      }
      tell_room(ETO,"%^RED%^"+caster->query_cap_name()+"'s wall of flame"+exitdesc+" dissipates away.", notsee);
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
        tell_object(TP,"%^BOLD%^%^RED%^You step into the violet inferno, walking calmly through the flames, unharmed.");
        tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" walks calmly into the violet inferno blocking the "+exitname+", unaffected by the flames.",TP);
        return 0;
    }
    tell_object(TP,"%^BOLD%^%^RED%^You step into the violet inferno, rushing through before the flames engulf you.");
    tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" rushes into the violet inferno blocking the "+exitname+", as the flames attack "+TP->query_objective()+"!",TP);
    if(TP->query_property("undead")) dmg = (roll_dice(2,6)+level+level/2)*2;
    else dmg = roll_dice(2,6)+level+level/2;
    TP->cause_typed_damage(TP,TP->return_target_limb(),dmg,"fire" );
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

int is_scrying_mirror() {
	return 1;
}
