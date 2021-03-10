#include <std.h>
inherit "/d/common/obj/clothing/hat";
int FLAG;

create() {
    ::create();
    FLAG = 0;
    set_name("drow mask");
    set_id(({"mask","drow mask"}));
    set_short("%^BLUE%^Mask of the Drow%^RESET%^");
    set_obvious_short("a mask");
    set_long("This mask depicts the many eye'd face of a great spider. Its dominated by shades of black, with stark contrasts of whites thrown in. The edges of the mask flair out in 4 directions for each side. These add to the general spider like feel.");
    set_lore(
    "%^BLUE%^The mask of the drow is reknowned for the evil it "
    "possesses its wearer with.  Only the high priests of the "
    "Drow Regime utilize it.  It is known to possess the "+
    "power to %^CYAN%^scry%^RESET%^%^BLUE%^ those who "+
    "find themselves on the wrong side of the high priests.%^RESET%^");
    set_value(10);
    set_item_bonus("sight bonus",3);
    set_wear((: TO, "wearit" :));
    set_remove((: TO, "removeit" :));
}
void init() {
    ::init();
    add_action("say_func","say");
    add_action("look_func","look");
    add_action("cackle_func","cackle");
    add_action("scry_func","scry");
   if(ETO == TP && !wizardp(TP)) {
        TP->force_me("wear mask");
    }
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
    if(ALIGN->is_good(TP)) {
       tell_object(TP,"The mask refuses to help one with such disgustingly"+
       " good intentions!");
       return 1;
    }
//    target = str;
//    ob = find_player(target);
//Begin code to use recognized names ~Circe~ 6/18/08
    target = lower_case(str);
    /*if(ETO->isKnown(target) || ((string)ETO->realName(target) != "") ) {
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
    if(!ob) {
        notify_fail("Your senses do not extend to the realm known as Real Life!\n");
        return 0;
    }
    if(ob == TP) {
        notify_fail("You need only look around you to find yourself!\n");
        return 0;
    }
/*
Removing this since real scry doesn't get blocked by invis
~Circe~ 6/18/08
    if(ob->query_invis()) {
        notify_fail("Your senses do not extend to the realm known as Real Life!\n");
        return 0;
    }
*/
    if(ob->query_property("no scry") || present("blockerx111",ob))
    {
        tell_object(ETO,"%^RED%^Your eyes burn with an unholy pain as you try to peer through the eyes of the mask!%^RESET%^\n");
        return 1;
    }
    if(ob->query_true_invis() || wizardp(ob)) { return 0; }
    locale = environment(ob);
    desc = (string)locale->query_long()+"\n";
    inv = all_inventory(locale);
    for(i=0; i<sizeof(inv); i++) {
        if(inv[i]->query_invis()) continue;
        desc += (string)inv[i]->query_short()+"\n";
    }
    tell_object(TP,"%^RED%^You concentrate while peering through the eyes.\n%^BLUE%^"+desc+"%^RESET%^");
    tell_room(ETP,"%^RED%^"+TPQCN+"'s eyes glow with an evil red light.%^RESET%^",TP);
    if((string)TP->query_name() != "grazzt" && random(30) < 2) {
	tell_object(TP,"%^BOLD%^%^RED%^Lloth tells you: %^RESET%^You are not a Drow! How dare you use the powers I have granted to them! I will look forward to erasing your existence.\n%^BLUE%^The mask vanishes!");
	TP->force_me("remove mask");
	TO->remove();
    }
    return 1;
}
int say_func(string str) {
    string msg;
    msg = str;
    if(TP->query_gagged() || TP->query_paralyzed()) return 0;
   if(!query_worn()) return 0;
    if(FLAG == 0) {
        return 0;
    }
    else {
       if (!str) {
          tell_object(TP,"%^BLUE%^Lloth attempts to force you to speak, but you manage to suppress her words.%^RESET%^");
          tell_room(ETP,"%^BLUE%^""An evil look fills "+TP->query_cap_name()+"'s eyes and a low moan is heard in the room.",TP);
          return 1;
       }
       else {
    if((string)TP->query_name() != "grazzt") {
   msg = "daemon/language_d"->translate(msg,TP->query_spoken(),TP);
    }
          message("say","%^BLUE%^You speak to the room in a low and hollow tone: %^RED%^"+msg,TP);
      message("say","%^BLUE%^"+TPQCN+" speaks in a low and hollow tone: %^RED%^"+msg,ETP,TP);
          return 1;
       }
    }
}

int wearit() {
   if((string)TP->query_race() == "elf" || (string)TP->query_race() == "half-elf") {
        if(!random(3)) {
           tell_object(TP,"%^RED%^The mask bites you as you attempt to wear it!");
           TP->do_damage("torso",random(8)+3);
           return 0;
        }
        tell_object(TP,"The mask will not be worn by one of your race!");
        return 0;
    }
    if(ALIGN->is_good(TP)) {
        if(!random(3)) {
           tell_object(TP,"%^RED%^The mask bites you as you attempt to wear it!");
           TP->do_damage("torso",random(8)+3);
           return 0;
        }
       tell_object(TP,"The mask refuses to be worn by someone with your"+
       " misguided morals!");
       return 0;
    }
    tell_object(TP, "%^BLUE%^You begin to see the world in a more %^RED%^evil%^BLUE%^ light.");
   ETO->set_property("evil item",1);
    FLAG = 1;
    return 1;
}

int removeit() {
    FLAG = 0;
    tell_object(TP, "%^BOLD%^%^RED%^Lloth tells you: %^RESET%^I will have your soul for rejecting my gift!");
   ETO->set_property("evil item",-1);
    return 1;
}

int look_func(string str) {
    if(TP->query_paralyzed()) return 0;
   if(!query_worn()) return 0;
    if(FLAG == 0) {
        return 0;
    } else {
       tell_object(TP,"%^BLUE%^You feel %^RED%^Lloth%^BLUE%^ look through your eyes.");
       if (!str || str == "$*") {
          /*if(!TP->query_invis()) {
            tell_room(ETP,"%^BLUE%^"+TPQCN+" sweeps %^MAGENTA%^spider like eyes%^BLUE%^ slowly over "+TP->query_possessive()+" surroundings.",TP);
          }*/ //commenting out to eliminate spam
       }
       return 0;
    }
}

int cackle_func(string str) {
    string msg;
    msg = str;
    if(FLAG == 0) {
        return 0;
    }
    else {
       if (!str) {
          tell_object(TP,"%^RESET%^%^RED%^You cackle in an insane and %^BLUE%^evil%^RED%^ manner.");
          tell_room(ETP,"%^RED%^"+TPQCN+" ponders briefly and %^BLUE%^cackles%^RED%^ evilly.",TP);
          return 1;
        }
        else {
        if((string)TP->query_name() != "grazzt") {
          msg = "daemon/language_d"->translate(msg,TP->query_spoken(),TP);
        }
            message("say","%^BLUE%^You cackle to those around you: %^RED%^"+msg,TP);
            message("say","%^BLUE%^"+TPQCN+" cackles insanely to those who listen: %^RED%^"+msg,ETP,TP);
           return 1;
	}
    }
}

int query_size(){
    if(!objectp(ETO) || !living(ETO)) return 2;
    return ETO->query_size();
}
