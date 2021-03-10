#include <std.h>


inherit OBJECT;


int blocking = 0;
string exitname;
object caster;
int level;
int sdamage;


void remove_wall();


void create()
{
   ::create();
   set_name("wall of thorns");
   set_short("%^GREEN%^A wall of thorns%^RESET%^");
   set_long("%^BOLD%^%^GREEN%^This is a twisted mass of nearly impassible thorns.  The points are razor sharp and tipped with "
       "red, almost as if some unluckly soul had already tried to walk through it!");
   set_id( ({"wall","wall of thorns","thornwall","thorn","thorns"}) );
   set_weight(10000);
   set_value(0);
   set_property("no animate",1);
   call_out("monitor",7);
}


void init()
{
   ::init();
   add_action("end_walls","remove");
   if(blocking) { add_action("damager",exitname); }
}


void surround(object ob)
{
   int k,j;
   object *foes;
   string whose,wallname;

   caster = ob;
   add_action("end_walls","remove");
   foes = caster->query_attackers();
   whose = caster->query_name();
   level = caster->query_guild_level("druid");
   wallname = whose+"surroundingthornwall";
   if(present(wallname,environment(caster))) {
      tell_object(caster,"The new wall of thorns grows into the existing wall!\n");
      tell_room(environment(caster),"The thorns surrounding "+caster->query_cap_name()+" seem to grow even more dense.\n");
      if(objectp(query_property("spell")))
         query_property("spell")->dest_effect();
      return;
   }
   sdamage = query_property("spell")->query_sdamage();
   add_id(wallname);
   j = sizeof(foes);
   for(k=0;k<j;k++) {
      if(!present(wallname,environment(caster))) continue;
      if(foes[k]->query_property("strength") &&
         strsrch(foes[k]->query_property("strength"),"thorns") != -1)
         continue;
      tell_room(environment(foes[k]),"%^BOLD%^%^GREEN%^"+foes[k]->query_cap_name()+" is torn by the thorns from the tangled wall!",foes[k]);
      tell_object(foes[k],"%^BOLD%^%^GREEN%^You body is torn painfully by the thorns that spring up around "+caster->query_cap_name()+".");
      foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),sdamage,"piercing" );
      if(objectp(foes[k]))
         foes[k]->continue_attack();
//          foes[k]->set_attackers((object *)foes[k]->query_attackers() -({caster}) );
//          caster->set_attackers((object *)caster->query_attackers() -({foes[k]}) );
   }
}


void monitor()
{
   int k,j;
   object *foes;

   if((!objectp(caster) || !present(caster->query_name(),ETO)) && !blocking)
   {
      if(objectp(query_property("spell")))
      {
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
         strsrch(foes[k]->query_property("strength"),"thorns") != -1)
         continue;
      tell_room(environment(foes[k]),"%^BOLD%^%^GREEN%^"+foes[k]->query_cap_name()+" is torn by the thorns!",foes[k]);
      tell_object(foes[k],"%^BOLD%^%^GREEN%^You get torn by the thorns!");
      foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),sdamage,"piercing" );
      if(objectp(foes[k]))
         foes[k]->continue_attack();
   } }
   call_out("monitor",7);
}


void block(object ob, string exitn)
{
   string whose, wallname;

   blocking = 1;
   caster = ob;

   level = caster->query_guild_level("druid");
   exitname = exitn;
   set_short("%^GREEN%^A wall of thorns blocking the "+exitname+"%^RESET%^");
   set_long("%^BOLD%^%^GREEN%^This is a twisted mass of nearly impassible thorns.  The points are razor sharp and tipped with "
       "red, almost as if some unluckly soul had already tried to walk through it!  It fully blocks the "+exitname+"!");
   whose = caster->query_name();
   wallname = whose+exitname+"thornwall";
   if(present(wallname,environment(caster)))
   {
      tell_object(caster,"The new wall of thorns grows into the existing wall!\n");
      tell_room(environment(caster),"The thorns surrounding "+caster->query_cap_name()+" seem to grow even more dense.\n");
      if(objectp(query_property("spell")))
         query_property("spell")->dest_effect();
      return;
   }
   add_id(wallname);
}


void remove_wall()
{
   object *notsee = ({});
   string exitdesc = "";

   if(blocking)
      exitdesc = ", blocking the "+exitname+",";
   if(objectp(caster) && objectp(ETO)) {
      if(present(caster,ETO)) {
         notsee = ({caster});
         if(blocking)
            tell_object(caster,"%^GREEN%^Your wall of thorns"+exitdesc+" dissipates away.");
         else {
            tell_object(caster,"%^GREEN%^The wall of thorns that surrounds you dissipates away.");
            caster->move(ETO);
         }
      }
      tell_room(ETO,"%^GREEN%^"+caster->query_cap_name()+"'s wall of thorns"+exitdesc+" dissipates away.", notsee);
   }
   destruct(TO);
   return;
}


int damager(string str)
{
   if(TP->query_paralyzed() || TP->query_bound() || TP->query_tripped() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(caster)
      if((string)caster->query_name()==(string)TPQN )
         return 0;
   if(TP->query_property("strength") && strsrch(TP->query_property("strength"),"thorns") != -1 ) {
      tell_object(TP,"%^BOLD%^%^GREEN%^You step into the wall of thorns and they part, allowing you to pass unharmed!");
      tell_room(ETP,"%^BOLD%^%^GREEN%^"+TPQCN+" walks into the wall of thorns and they part, allowing "+TPQCN+" to go "+exitname+" unharmed.",TP);
      return 0;
   }
   tell_object(TP,"%^BOLD%^%^RED%^You step into the wall of thorns and feel the pointed tips tearing at you!");
   tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" steps into the wall of thorns blocking the "+exitname+" and they tear into "+TP->QO+"!",TP);
   TP->cause_typed_damage(TP, TP->return_target_limb(), sdamage, "piercing");
   if(TP)
      TP->continue_attack();
   return 0;
}


int end_walls(string str)
{
   if(!caster || (TP != caster))
      return 0;
   if(str != "wall")
      return 0;
   if(objectp(query_property("spell")))
      query_property("spell")->dest_effect();
   return 1;
}


int query_blocking() { return blocking; }
