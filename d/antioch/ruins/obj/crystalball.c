#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("crystal ball");
   set_id(({"crystal ball","ball","crystal"}));
   set_obvious_short("%^BOLD%^WHITE%^Crystal Ball%^RESET%^");
   set_short("crystal ball");
   set_long("%^BOLD%^%^WHITE%^This is a crystal ball, filled with a smokey gray"+
            " mist. The mist is constantly swirling.%^RESET%^");
   set_weight(10);
   set_value(10);
}

void init() {
   ::init();
   add_action("scry_func","scry");
}

int scry_func(string str) {
    object ob,locale,*inv;
    string target,desc,*map_keys,real;
    int i,matches;
    mapping map;

    if(!str) {
        notify_fail("What?\n");
        return 0;
    }
//    target = str;
//    ob = find_player(target);
//Begin code to use recognized names ~Circe~ 6/18/08
/*
%^BOLD%^Removing this code to update to newer code. Leaving here just in case. ~Circe~ 5/8/11
    target = lower_case(str);
    if(ETO->isKnown(target) || ((string)ETO->realName(target) != "") ) {
      map = (mapping)ETO->getRelationships();
      map_keys = keys(map);
      for(i=0;i<sizeof(map_keys);i++) {
         if (!stringp(map[map_keys[i]])) continue;
         if(lower_case(map[map_keys[i]]) == target) {
            matches++;
            real = lower_case(map_keys[i]);
         }
      }
     }
      if(!matches){
	   tell_object(ETO,"%^BOLD%^RED%^You do not recall a person called "+target+"!%^RESET%^");
	   return 1;
      }
      if(matches > 1) {
	   tell_object(ETO,"%^BOLD%^RED%^You know too many people with the same name!%^RESET%^");
	   return 1;
      }
    ob = find_player(real);
//End code to use recognized names
*/
    target = lower_case(str);
    ob = find_player(ETO->realName(target));

    if(!ob) {
        notify_fail("%^BOLD%^%^WHITE%^The mist stirs...");
        return 0;
    }
    if(ob == TP) {
        notify_fail("%^BOLD%^%^WHITE%^You need only look around you to find yourself!\n");
        return 0;
    }
//Remember to add scry blocking stuff once it's fixed
    if(ob->query_property("no scry")){
      notify_fail("%^BOLD%^%^WHITE%^The ball fills with intense fog, it is unclear!");
      return 0;
    }
    if(ob->query_true_invis() || wizardp(ob)) { return 0; }
    locale = environment(ob);
    desc = (string)locale->query_long()+"\n";
    inv = all_inventory(locale);
    for(i=0; i<sizeof(inv); i++) {
        if(inv[i]->query_invis()) continue;
        desc += (string)inv[i]->query_short()+"\n";
    }
    tell_object(TP,"%^BOLD%^WHITE%^You concentrate while peering through the ball.\n"+desc+"");
    tell_room(ETP,"%^BOLD%^%^WHITE%^"+TPQCN+" peers into the crystal ball.",TP);
    if( random(10) > 2) {
        tell_object(TP,"%^BOLD%^%^WHITE%^The ball fills with mist, then %^BOLD%^%^RED%^cracks%^BOLD%^%^WHITE%^!");
        TO->remove();
    }
    return 1;
}
