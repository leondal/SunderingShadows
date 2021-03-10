//Dome - this is the dome described in the mage combat room, 
//and it is meant as a permanent scrying device so people
//outside the dome can watch the combat happening within.
//The dome is supposed to be an anti-magic thing that makes 
//observation safe.
//~Circe~ 1/12/08 for new Seneca

#include <std.h>
#include "../seneca.h"

inherit OBJECT;

object scry_object;
int send_living_name(object targ);
int long_look_room(object dest);

void create(){
   ::create();
   set_name("dome");
   set_id(({"dome","magic dome","magical dome","transluscent dome"}));
   set_short("%^BOLD%^%^CYAN%^a magical dome%^MAGENTA%^");
   set_property("no animate", 1);
   set_long("%^BOLD%^%^CYAN%^A transluscent %^WHITE%^dome%^CYAN%^ "+
      "that shimmers with coruscating %^RED%^c%^YELLOW%^o%^BLUE%^"+
      "l%^GREEN%^o%^MAGENTA%^r%^CYAN%^s protects the reverse "+
      "dais in the middle of the room.  It looks as though you "+
      "might %^WHITE%^<%^BLACK%^enter%^WHITE%^> %^CYAN%^the dome "+
      "to duel with someone else in a protective environment.%^RESET%^");
   set_value(1);
   set_weight(100000);
   set_no_clean(1);
}

int get() { return 0; }

int drop() { return 1; }

void init(){
   ::init();
   add_action("look_em","look");
   add_action("recognize_em","recognize");
   add_action("help_em","help");
}

int look_em(string str) {
  if(str != "into dome") return 0;
  if(TP->query_blind() || TP->query_blindfolded() || TP->query_unconscious()){
     write("You cannot do that in your current state!");
     return 1;
  }
  write("%^BOLD%^%^CYAN%^You look carefully within the dome "+
     "and study what lies within:");
  long_look_room(find_object_or_load("/d/attaya/newseneca/rooms/mage_combat2"));
  return 1;
}

int recognize_em(string str) {
  string who,as;
  object ob;
  
  if(!str) {
    return 0;
  }
  if(sscanf(str, "%s as %s through dome",who, as) != 2) {
    return 0;
  }
  ob = present(who,find_object_or_load("/d/attaya/newseneca/rooms/mage_combat2"));
  if(!objectp(ob)) {
    return write("There is no "+who+" in the area you are viewing.\n");
  }
  if(TP->query_blind() || TP->query_blindfolded() || TP->query_unconscious()){
     write("You cannot do that in your current state!");
     return 1;
  }
  else{
    if(userp(ob)){
      write("You will recognize "+who+" as "+capitalize(as)+".");
      TP->addRelationship(ob,as);
    }
    else{
      write("You can only recognize other players at this time.");
    }
  }
  return 1;
}

int long_look_room(object dest){
    object *inv;
    int i,j;
    message("room_description","\n%^BOLD%^%^CYAN%^[D] %^RESET%^"+(string)dest->query_long()+"", TP);
    inv = all_inventory(dest);
    if(sizeof(inv)< 1) return 1;
    for(i=0;i<sizeof(inv);i++){
     	if(!objectp(inv[i])) continue;
     	if(inv[i]->query_invis()) continue;
    	if(!inv[i]->is_detectable()) continue;
    	TO->send_living_name(inv[i]);
    }
    return 1;
}

int send_living_name(object targ){
	string known, str;
	int i,j;
	
    if(targ->is_monster()){
	    str = targ->query_short();
	    message("living_item", "%^CYAN%^%^BOLD%^[D] %^RED%^"+str,TP);
        return 1;
    }
    if(objectp(TP) && TP->knownAs(targ->query_true_name())){
	    known = TP->knownAs(targ->query_true_name());
    }
    str = targ->getWholeDescriptivePhrase();
    if(known){
        str = capitalize(known)+", "+str;
    }
    if(str){
       message("living_item", "%^CYAN%^%^BOLD%^[D] %^RED%^"+str, TP);
    }
    known = 0;
    return 1;
}


int help_em(string str) {
  if(str == "here" || str == "room" || str == "dome"){
  write("%^YELLOW%^Instructions for use of this room.%^RESET%^\n");
  write("%^BOLD%^This room is provided as a practice area for the "+
     "magic users of the realm.  You may do any of the following "+
     "within this room:%^RESET%^\n"+
     "To obtain a practice dummy............... %^YELLOW%^<%^RESET%^"+
     "retrieve dummy%^YELLOW%^>%^RESET%^\n"+
     "To send a dummy back to its plane........ %^YELLOW%^<%^RESET%^"+
     "return dummy%^YELLOW%^>%^RESET%^\n"+
     "To use the dome for combat............... %^YELLOW%^<%^RESET%^"+
     "enter dome%^YELLOW%^>%^RESET%^\n\n"+
     "%^BOLD%^This room is also safe zone from which to view people "+
     "in combat within the dome.  You may simply stand here and let "+
     "the action come to you, or you may do one of the following:%^RESET%^");
  write("To look within the dome.......... %^YELLOW%^<%^RESET%^look "+
     "into dome%^YELLOW%^>%^RESET%^");
  write("To recognize someone in the dome: %^YELLOW%^<%^RESET%^recognize "+
     "%^BOLD%^[%^RESET%^id%^BOLD%^]%^RESET%^ as %^BOLD%^[%^RESET%^name"+
     "%^BOLD%^]%^RESET%^ through dome%^YELLOW%^>%^RESET%^");
  return 1;
  }
  return 0;
}
