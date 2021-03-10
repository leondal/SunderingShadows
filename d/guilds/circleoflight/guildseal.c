#include <std.h>
inherit ARMOUR;

int port, det, detb, hbeat;
string symbol1;

void create(){
	::create();
	set_name("ring");
	set_id(({"ring","black ring","jet black ring","jet-black ring"}));
	set_short("%^BOLD%^%^BLACK%^jet-black ring inscribed with %^YELLOW%^g%^RESET%^%^ORANGE%^ol%^YELLOW%^d%^RESET%^");
	symbol1 = "a single perfect circle";
	set_long("This finely crafted signet ring is made of glossy %^BOLD%^%^BLACK%^jet-black %^RESET%^stone.  It is a "
"rather thick ring with a round, flat top that features "+(string)TO->query_seal()+", inscribed with pure %^YELLOW%^g"
"%^RESET%^%^ORANGE%^ol%^YELLOW%^d%^RESET%^.\n");
	set_weight(1);
	set_value(550);
	set_property("death keep",1);
	set_limbs(({"left hand","right hand"}));
	set_type("ring");
	set_lore("This signet ring was made by Edric, the firbolg jeweler in the village of Lothwaite.  While he normally "
"crafts signets as personal seals, a special set was commissioned from him by Natalia Everstar of Selune, to represent "
"those members of the Circle of Light.  Plain and unrecognizeable to most, it serves as a sign of the group who claim "
"their intent to turn back the tide of evil across the realm.");
	set_property("lore difficulty",12);
	set_wear((:TO,"wear_fun":));
	set_heart_beat(1);
}

int wear_fun() {
   if(((int)ETO->query_alignment()%3) != 1) {
     tell_object(ETO,"The ring repels you!");
     return 0;
   }
   tell_object(ETO,"%^CYAN%^As you wear the ring you realise you could %^BOLD%^touch ring to object%^RESET%^%^CYAN%^, or "
"%^BOLD%^focus on ring%^RESET%^%^CYAN%^.%^RESET%^");
   hbeat = time() + 300;
   return 1;
}

void init() {
   ::init();
   add_action("detect_fun","touch");
   add_action("port_fun","focus");
}

int query_seal(){ return "a finely detailed image of "+symbol1+""; }

int query_is_seal_device(){ 
   if(TO->query_worn()) return 1;
   return 0;
}

int detect_fun(string str){
   string myobj, myglow;
   object ob;
   int mychant;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) return notify_fail("You need to be wearing the ring.\n");
   if(!str) return notify_fail("You need to specify what you want to touch the ring against.\n");
   if(sscanf(str,"ring to %s", myobj) != 1)
     return notify_fail("You need to specify what you want to touch the ring to.\n");
   if(!ob = present(myobj,TP)) return notify_fail("You aren't carrying a "+myobj+".\n");
   if(det > time()) return notify_fail("You've exhausted the ring's detection powers for today.\n");
   if(detb > 1) { det = time() + 28800; detb = 0; }
   else detb++;
   mychant = absolute_value((int)ob->isMagic());
   tell_room(ETP,"%^CYAN%^"+TP->QCN+" touches "+TP->QP+" ring against the "+myobj+".%^RESET%^",TP);
   if(!mychant) {
     tell_object(TP,"%^CYAN%^You touch the ring to the "+myobj+", but it shows no aura.%^RESET%^");
     return 1;
   }
   switch(mychant) {
     case 1: myglow = "a faint blue glow"; break;
     case 2: myglow = "a blue glow"; break;
     case 3: myglow = "a bright blue glow"; break;
     case 4: myglow = "a very bright blue glow"; break;
     case 5: myglow = "an extremely bright blue glow"; break;
     default: myglow = "a nearly blinding blue glow"; break;
   }
   tell_object(TP,"%^CYAN%^You touch the ring to the "+myobj+", and it shimmers briefly with "+myglow+".%^RESET%^");
   return 1;
}

int port_fun(string str){
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) return notify_fail("You need to be wearing the ring.\n");
   if(!str) return notify_fail("What do you want to focus on?\n");
   if(str != "on ring") return notify_fail("You can't focus on that.\n");
   if(port > time()) return notify_fail("You've exhausted the ring's translocation powers for today.\n");
   if(hbeat > time()) return notify_fail("You need to calm down for a few moments before you can do that.\n");
   if(ETP->query_property("no teleport")) return notify_fail("There is too much magical interferance here.\n");
   port = time() + 28800;
   tell_object(TP,"%^ORANGE%^You focus on the ring, and the golden circle begins to %^YELLOW%^glow%^RESET%^%^ORANGE%^.  Suddenly you find yourself elsewhere!%^RESET%^");
   tell_room(ETP,"%^ORANGE%^The golden circle on "+TP->QCN+"'s ring begins to %^YELLOW%^glow%^RESET%^%^ORANGE%^, and "
"suddenly "+TP->QS+" disappears!%^RESET%^",TP);
   tell_room("/d/darkwood/tabor/road/road16","%^ORANGE%^"+TP->QCN+" suddenly appears from nowhere!%^RESET%^");
   TP->move_player("/d/darkwood/tabor/road/road16");
   return 1;
}

void heart_beat(){
   if(!userp(ETO)) return;
   if(!interactive(ETO)) return;
   if(!TO->query_worn()) return;
   if(sizeof(ETO->query_attackers())) hbeat = time() + 300;
}