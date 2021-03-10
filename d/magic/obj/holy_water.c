//changed value so it's not worth more in a store than it costs *Styx* 6/7/02
//updated with new description by Shar.  Circe 12/30/04
//Added Sune, Beshaba, Shaundakul, and Auppenser - Cythera 8/05
//Altered by ~Circe~ 6/4/08 to allow for multiple blessings in a 
//room and the ability to <cleanse> a room of all other blessings
#include <std.h>

inherit OBJECT;

int uses;
string god;

void set_god(string str){
   god = str;
}

string query_god(){
    return god;
}

void create(){
   ::create();
   set_name("holy water");
   set_short("a vial of water");
   set_property("no animate", 1);
   set_long("Within this glass vial, water concentrated in the name of ");
   set_weight(3);
   set_value(1);
   set_id(({"water","holy water"}));
   uses = 1;
   set_lore("Like the holy symbols they carry, holy water can be "+
      "found on any priest or cleric in the lands.  These sacred "+
      "vials of water carry the blessings of the temple with them "+
      "where ever they go.  The process for creating holy water "+
      "varies from faith to faith.  Some use rare spices and oils "+
      "in the creation, while others demand more gruesome sacrifices.  "+
      "Priests have always carried vials of holy water with them, "+
      "for they claim it puts their minds closer to the gods when they pray.");
}

void init(){
   ::init();
	
   if(TP == ETO){
      add_action("split","take");
      add_action("split","split");
      add_action("combine","combine");
      add_action("combine","join");
      add_action("bless","bless");
      add_action("cleanse","cleanse");
   }
}

int bless(){
   object vial;

   if(!uses){
      return 0;
   }
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(ETP->is_temple()){
     tell_object(TP,"You are already standing on holy ground, your "+
       "blessings will not work here!");
     return 1;
   }
   if(ETP->query_property("blessed")){
      if(pointerp(ETP->query_property("blessed"))){
         if(member_array(god,(string*)ETP->query_property("blessed")) != -1) {
            tell_object(TP,"As you prepare to begin your ritual, you "+
               "sense that "+capitalize(god)+"'s presence is already in "+
               "this room and decide not to use your water.");
            return 1;
         }
      }else if(stringp(ETP->query_property("blessed"))){
         if((string)ETP->query_property("blessed") == god) {
            tell_object(TP,"As you prepare to begin your ritual, you "+
               "sense that "+capitalize(god)+"'s presence is already in "+
               "this room and decide not to use your water.");
            return 1;
         }
      }
   }
   tell_object(TP,"You whisper a prayer to "+capitalize(god)+" "+
      "as you sprinkle holy water around part of the room, "+
      "blessing it.");
   tell_room(ETP,"%^BOLD%^"+TPQCN+" whispers a prayer and sprinkles "+
      "holy water in a portion of the room, blessing it in "+
      ""+capitalize(god)+"'s name.%^RESET%^",TP);
   ETP->set_property("blessed",({god}));
   uses--;
   set_weight(query_weight() - 2);
   ETO->add_encumbrance(-2);
   if(uses < 1) call_out("remove",1);
   return 1;
}

int cleanse(string str){
   int x;
   string *blessings = ({});

   if(!uses){
      return 0;
   }
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(ETP->is_temple()){
     tell_object(TP,"You are already standing on holy ground, your "+
       "blessings will not work here!");
     return 1;
   }
   if(str == "room" || str == "here" || str == "area"){
      if(ETP->query_property("blessed")){
         if(pointerp(ETP->query_property("blessed"))){
            x = sizeof((string*)ETP->query_property("blessed"));
            if(member_array(god,(string*)ETP->query_property("blessed")) != -1) {
               x--;
            }
            x = x+1;
            if(uses < x){
               tell_object(TP,"You do not have enough holy water "+
                  "to overtake the blessings already in this room.");
               return 1;
            }
            tell_object(TP,"%^BOLD%^%^CYAN%^Beginning a powerful "+
               "ritual, you use "+x+" vials of holy water to "+
               "fully cleanse the area and consecrate it solely to "+
               ""+capitalize(god)+"'s name.%^RESET%^");
            tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" walks around "+
               "the room, sprinkling "+x+" vials of holy water to "+
               "fully cleanse the room and consecrate it solely to "+
               ""+capitalize(god)+"'s name.%^RESET%^",TP);
            uses = uses - x;
            set_weight(query_weight() - (2*x));
            ETO->add_encumbrance(-2*x);
            if(uses < 1) call_out("remove",1);
            ETP->remove_property("blessed");
            ETP->set_property("blessed",({god}));
            return 1;
         }else if(stringp(ETP->query_property("blessed"))){
            if((string)ETP->query_property("blessed") != god) {
               if(uses < 2){
                  tell_object(TP,"You do not have enough holy water "+
                     "to overtake the blessings already in this room.");
                  return 1;
               }
               tell_object(TP,"%^BOLD%^%^CYAN%^Beginning a powerful "+
                  "ritual, you use "+x+" vials of holy water to "+
                  "fully cleanse the area and consecrate it solely to "+
                  ""+capitalize(god)+"'s name.%^RESET%^");
               tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" walks around "+
                  "the room, sprinkling "+x+" vials of holy water to "+
                  "fully cleanse the room and consecrate it solely to "+
                  ""+capitalize(god)+"'s name.%^RESET%^",TP);
               uses = uses - 2;
               set_weight(query_weight() - 4);
               ETO->add_encumbrance(-4);
               if(uses < 1) call_out("remove",1);
               ETP->remove_property("blessed");
               ETP->set_property("blessed",({god}));
               return 1;
            }
         }
      }else{
         tell_object(TP,"This room is not blessed in any deity's "+
            "name.  You should simply <bless> it.");
         return 1;
      }
   }else{
      if(ETP->query_property("blessed")){
         if(pointerp(ETP->query_property("blessed"))){
            if(member_array(str,(string*)ETP->query_property("blessed")) == -1) {
               tell_object(TP,"There is no blessing to "+
                  ""+capitalize(str)+" in this room!");
               return 1;
            }else if(str == god) {
               tell_object(TP,"Why would you want to cleanse the "+
                  "room of "+capitalize(str)+"'s blessing?");
               return 1;
            }else{
               if(uses < 2){
                  tell_object(TP,"You do not have enough holy water "+
                     "to overtake the blessings of "+
                     ""+capitalize(str)+" in this room.");
                  return 1;
               }
               tell_object(TP,"%^BOLD%^You focus your energy "+
                  "upon the area of the room consecrated in "+
                  ""+capitalize(str)+"'s name and sprinkle "+
                  "holy water there, cleansing the area.%^RESET%^");
               tell_room(ETP,"%^BOLD%^"+TPQCN+" takes two vials of "+
                  "holy water and sprinkles them around a certain "+
                  "part of the room, cleansing it of its previous "+
                  "blessing.%^RESET%^",TP);
               uses = uses - 2;
               set_weight(query_weight() - 4);
               ETO->add_encumbrance(-4);
               if(uses < 1) call_out("remove",1);
               blessings = ETP->query_property("blessed");
               blessings -= ({str});
               ETP->remove_property("blessed");
               ETP->set_property("blessed",blessings);
               return 1;
            }
         }else if(stringp(ETP->query_property("blessed"))){
            if((string)ETP->query_property("blessed") != str) {
               tell_object(TP,"There is no blessing to "+
                  ""+capitalize(str)+" in this room!");
               return 1;
            }else if(str == god) {
               tell_object(TP,"Why would you want to cleanse the "+
                  "room of "+capitalize(str)+"'s blessing?");
               return 1;
            }else{
               if(uses < 2){
                  tell_object(TP,"You do not have enough holy water "+
                     "to overtake the blessings of "+
                     ""+capitalize(str)+" in this room.");
                  return 1;
               }
               tell_object(TP,"%^BOLD%^You focus your energy "+
                  "upon the area of the room consecrated in "+
                  ""+capitalize(str)+"'s name and sprinkle "+
                  "holy water there, cleansing the area.%^RESET%^");
               tell_room(ETP,"%^BOLD%^"+TPQCN+" takes two vials of "+
                  "holy water and sprinkles them around a certain "+
                  "part of the room, cleansing it of its previous "+
                  "blessing.%^RESET%^",TP);
               uses = uses - 2;
               set_weight(query_weight() - 4);
               ETO->add_encumbrance(-4);
               if(uses < 1) call_out("remove",1);
               ETP->remove_property("blessed");
               ETP->set_property("blessed",({god}));
               return 1;
            }
         }
      }else{
         tell_object(TP,"This room is not blessed in any deity's "+
            "name.  You should simply <bless> it.");
         return 1;
      }
   }
}



void add_use(){
   uses += 1;
}

int query_uses() { return uses; }

void set_uses(int num){
   uses = num;
   set_weight(2 * num);
}

string query_short(){
	string holder;
	
	holder = ::query_short();
	holder += " ["+uses+" left]";
	return holder;
}

string query_long(string str){
	string holder, GOD, COLOR;
   switch((string)TO->query_god()){
      case "akadi": GOD = "%^BOLD%^%^BLUE%^Akadi";
                    COLOR = "%^BOLD%^%^BLUE%^sky blue";
                    break;
      case "anhur": GOD = "%^BOLD%^%^RED%^Anhur";
                    COLOR = "%^YELLOW%^gold";
                    break;
	case "auppenser": GOD = "%^CYAN%^Auppenser";
				COLOR = "%^ORANGE%^bronze";
			  break;
      case "auril": GOD = "%^BOLD%^%^WHITE%^Auril";
                    COLOR = "%^BOLD%^%^WHITE%^snow white";
                    break;
      case "bane": GOD = "%^BOLD%^%^GREEN%^Bane";
                    COLOR = "%^BOLD%^%^GREEN%^emerald green";
                    break;
	case "beshaba": GOD = "%^BOLD%^%^MAGENTA%^Beshaba";
			  COLOR = "%^BOLD%^%^MAGENTA%^mauve";
			  break;
      case "cyric": GOD = "%^BOLD%^%^BLACK%^Cyric";
                    COLOR = "%^BOLD%^%^BLACK%^black";
                    break;
      case "grumbar": GOD = "%^ORANGE%^Grumbar";
                    COLOR = "%^ORANGE%^clay";
                    break;
      case "helm": GOD = "%^BOLD%^Helm";
                    COLOR = "%^CYAN%^steel gray";
                    break;
      case "istishia": GOD = "%^CYAN%^Istishia";
                    COLOR = "%^CYAN%^blue-green";
                    break;
      case "kelemvor": GOD = "%^BOLD%^%^BLACK%^Kelemvor";
                    COLOR = "%^BOLD%^%^BLACK%^gray-%^RESET%^%^GREEN%^green";
                    break;
      case "kossuth": GOD = "%^BOLD%^%^RED%^Kossuth";
                    COLOR = "%^BOLD%^%^RED%^fiery red";
                    break;
      case "lathander": GOD = "%^BOLD%^%^MAGENTA%^Lathander";
                    COLOR = "%^BOLD%^%^MAGENTA%^rose%^RED%^-red";
                    break;
      case "loviatar": GOD = "%^RED%^Loviatar";
                    COLOR = "%^BOLD%^%^RED%^scarlet";
                    break;
      case "malar": GOD = "%^ORANGE%^Malar";
                    COLOR = "%^ORANGE%^rust";
                    break;
      case "mask": GOD = "%^BOLD%^%^BLACK%^Mask";
                    COLOR = "%^BOLD%^%^BLACK%^gray";
                    break;
      case "mielikki": GOD = "%^GREEN%^Mielikki";
                    COLOR = "%^GREEN%^forest green";
                    break;
      case "mystra": GOD = "%^BOLD%^%^BLUE%^Mystra";
                    COLOR = "%^BLUE%^midnight blue";
                    break;
      case "oghma": GOD = "%^MAGENTA%^Oghma";
                    COLOR = "%^MAGENTA%^wine";
                    break;
      case "selune": GOD = "%^BOLD%^%^WHITE%^Selune";
                    COLOR = "%^BOLD%^%^WHITE%^silver";
                    break;
      case "shar": GOD = "%^MAGENTA%^Shar";
                    COLOR = "%^MAGENTA%^amethyst";
                    break;
	case "shaundakul": GOD = "%^CYAN%^Shaundakul";
			   COLOR = "%^CYAN%^blue-gray";
			  break;
	case "sune": GOD= "%^RED%^Sune";
			  COLOR = "%^RED%^deep crimson";
			  break;
      case "talos": GOD = "%^YELLOW%^Talos";
                    COLOR = "%^YELLOW%^sulfur yellow";
                    break;
      case "tempus": GOD = "%^RED%^Tempus";
                    COLOR = "%^RED%^blood red";
                    break;
      case "torm": GOD = "%^BOLD%^%^WHITE%^Torm";
                    COLOR = "%^BOLD%^%^BLUE%^cobalt";
                    break;
      case "tymora": GOD = "%^BOLD%^%^BLUE%^Tymora";
                    COLOR = "%^BOLD%^%^BLUE%^cerulean blue";
                    break;
      case "tyr": GOD = "%^CYAN%^Tyr";
                    COLOR = "%^CYAN%^slate blue";
                    break;
      default:  GOD = "a god";
                COLOR = "faintly";
                break;
   }

	holder = ::query_long(str);
	
	holder += ""+GOD+" %^RESET%^is housed.  The "+COLOR+" "+
         "tinted water %^RESET%^fills the heavy glass vials.  "+
         "Protected by a wax seal, these vials of holy water "+
         "can <%^CYAN%^bless%^RESET%^> a room or secluded spot.  "+
         "By sanctifying the area, many hope to invoke "+
         "the blessings of the gods.  For more complex rituals "+
         "or to simply purify an area, one may <%^CYAN%^cleanse "+
         "room%^RESET%^>, or if a particular taint is present, "+
         "one may <%^CYAN%^cleanse [deity]%^RESET%^>.  ["+uses+" left]";
	return holder;
}

int restore_me(string file){
	int holder;
	
	holder = ::restore_me(file);
	
	set_weight(uses *2);
	return holder;
}

int split(string str){
	object ob;
	int num;
	string word;
	
	if(!str) return 0;
	
	if(sscanf(str,"%d from %s",num,word) !=2)
		return notify_fail("Syntax: take # from kit\n");
	
	if(num >= uses || num <= 0)
		return notify_fail("You may take from 1 to "+(uses-1)+" vials from this kit!\n");
	
	set_uses(uses-num);
	seteuid(getuid());
	ob=new(base_name(TO));
	ob->set_uses(num);
	ob->toggle();
	TP->add_encumbrance((-1)*2*num);
	ob->move(TP);
	ob->toggle();
    ob->set_god(god);
	tell_room(ETP,"%^BLUE%^You see "+TPQCN+" take several vials from "+TP->query_possessive()+" kit.",TP);
	write("%^BLUE%^You remove "+num+" vials from your kit.");
	return 1;
}

int combine(string str){
	object ob;
	int num;
	string targ, dest;
	
	if(!str) return 0;
	
	if(sscanf(str,"%s with %s",targ,dest) !=2)
		return notify_fail("Syntax: combine kit # with kit #\n");
	
	if(!id(targ))
		return 0;
    if(!id(dest)) return 0;
	if(!ob=present(dest,TP))
		return notify_fail("No second kit.\n");
   if(ob==TO)
      return notify_fail("You can't do that.\n");
	
	num = ob->query_uses();
	set_uses(query_uses()+num);
	seteuid(getuid());
     ob->remove();
	TP->add_encumbrance(2*num);
	tell_room(ETP,"%^BLUE%^You see "+TPQCN+" combine two kits of "+::query_short()+".",TP);
	write("%^BLUE%^You combine the two kits of "+::query_short()+".");
	return 1;
}

int isMagic(){ return 1; }

/*
%^BOLD%^Old version of bless - changing after conversations with Ares and Tsera.  With so many more clerics now than there once were, it's really difficult for them to party together with having to bless rooms.  So changing it so that you bless a part of the room when you use <bless> but you can also <cleanse> a room to get rid of other blessings.  Bless will cost only one vial, while cleanse will cost 1 vial plus 1 for every other blessing already present in the room that does not match the blesser's deity. ~Circe~ 6/4/08%^RESET%^
int bless() {

    object vial;
    int temp,x ;

    if (!uses) {
       return 0;
    }
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
    if(ETP->query_property("blessed") && (string)ETP->query_blessed("blessed") != god){
       if(uses < 2){
   tell_object(TP,"You haven't enough holy waters to break the control of the controlling god.");
	  return 1;
       }
       tell_object(TP,"This room fights against your blessing, however you manage to bless it with an extra bottle.");
       x =2;
    } else {
       tell_object(TP,"You bless the room in the name of "+capitalize(god)+".\n");
       x = 1;
    }
    tell_room(ETP,"%^BOLD%^"+TPQCN+" blesses this room in the name of "+capitalize(god)+".",TP);
   ETP->remove_property("blessed");
    ETP->set_property("blessed",god);
    uses-=x;
    set_weight(query_weight() - 2*x);
    ETO->add_encumbrance(-2*x);
    if(uses < 1)
       call_out("remove",1);
    return 1;


}
*/
