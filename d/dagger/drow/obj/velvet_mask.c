//updated by ~Circe~ 4/16/08 to use recognized names

#include <std.h>
inherit ARMOUR;
int CHARGES;

void create() {
    ::create();
    CHARGES = roll_dice(1,4) + 1;
    set_name("velvet mask");
    set_id(({"mask","velvet mask","shroud","velvet shroud","xxxmask"}));
    set_short("%^BOLD%^%^BLACK%^Shroud of Malshial%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^a velvet mask%^RESET%^");    
    set_long("%^BOLD%^%^BLACK%^The sheer fabric of this once enchanting shroud "
        "now hangs limply. Its edges, once adorned with %^BOLD%^%^WHITE%^s%^RESET%^"
        "i%^BOLD%^lv%^RESET%^e%^BOLD%^%^WHITE%^r%^BOLD%^%^BLACK%^ and %^BOLD%^%^GREEN%^"
        "j%^RESET%^%^GREEN%^ad%^BOLD%^%^GREEN%^e%^BOLD%^%^BLACK%^, are now tattered and "
        "frayed, revealing only glimpses of its former beauty. Thin %^BOLD%^%^WHITE%^si"
        "%^RESET%^lv%^BOLD%^%^WHITE%^er%^BOLD%^%^BLACK%^ thread sewn into the delicate "
        "material creates a hypnotizing pattern that enraptures the eyes with its smooth, "
        "spiraling tendrils. A single rounded shard of %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^"
        "ad%^BOLD%^%^GREEN%^e%^BOLD%^%^BLACK%^ has been sewn into the cloth, designed "
        "to sit upon the brow when the shroud is draped over the head.%^RESET%^");    
    set_lore("This delicate shroud was buried long ago with a priestess of "
        "Kelemvor, Malshial, who was highly revered for her compassion in "
        "leading dying souls to their final rest. It is said that when on "
        "her own deathbed, the priestess blessed this shroud so that others "
        "could, after her passing, find their way across great distances.");
    set_weight(10);
    set_value(1000);
    set_type("clothing");
    set_item_bonus("sight bonus",3);
    set_limbs(({"head"}));
    set_ac(0);
}

void init(){
    ::init();
    add_action("scry_func","scry");
    if(living(ETO) && present("drow mask",ETO)){
        tell_object(ETO,"The magic in the masks interacts, and the new mask "
            "crumbles to dust!");
        TO->remove();
        return;
    }
}

int scry_func(string str){
    object ob,locale,*inv;
    string target,desc,*map_keys,real;
    int i,matches;
    mapping map;

    if(!str) { return notify_fail("Scry whom?\n"); }
    if(!CHARGES) 
    { 
        tell_object(TP,"The mask's eyes flicker and then the entire thing crumbles "
            "to dust!");
        TP->force_me("remove xxxmask");
        TO->remove();
        return 0;
    }

//    ob = find_player(str);
//Begin code to use recognized names ~Circe~ 4/16/08
    target = lower_case(str);
    /*if(ETO->isKnown(target) || ((string)ETO->realName(target) != "")) 
    {
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
      }*/

    if((string)ETO->realName(target) != "") { real = lower_case((string)ETO->realName(target)); }
    else
    {
	    tell_object(ETO,"%^BOLD%^RED%^You do not recall a person called "+target+"!%^RESET%^");
	    return 1;
    }

    ob = find_player(real);
//End code to use recognized names
    if(!ob) { return notify_fail("The mask is unable to find that person!\n"); }
    if(ob == TP) { return notify_fail("The mask glows faintly, but nothing happens!\n"); }

//    if(ob->query_invis()) { return notify_fail("The mask is unable to find that person!\n"); } 
//Removing this since real scry doesn't get blocked by invis ~Circe~ 6/18/08
//Will need to add in scry block stuff once it's fixed
   if(ob->query_property("no scry") || present("blockerx111",ob) || present("blockerx111",environment(ob)))
    { 
        tell_object(ETO,"You vision blurs white and a pain "
            "shoots through your skull as you try to scry "+ob->QCN+"");
         return 1;
    }
    if(ob->query_true_invis() || wizardp(ob)) { return 0; }
    locale = environment(ob);
    desc = (string)locale->query_short()+"\n";
    desc += (string)locale->query_long()+"\n\n";
    desc += "%^CYAN%^"+(string)locale->query_long_exits()+"";
    desc += "\n\n%^RED%^";
    inv = all_inventory(locale);
    for(i=0; i<sizeof(inv); i++) 
    {
        if(inv[i]->query_invis()) continue;
        desc += (string)inv[i]->query_short()+"\n";
    }
    tell_object(TP,"%^YELLOW%^You stare intently through the eyes of the mask.\n%^BLUE%^"+desc+"%^RESET%^");
    tell_room(ETP,"%^RED%^"+TPQCN+"'s eyes glow yellow as "+TP->QS+" gazes through the mask!%^RESET%^",TP);
    CHARGES--;
    return 1;
}


int query_size()
{
    if(!objectp(ETO) || !living(ETO)) return 2;
    return ETO->query_size();
}
