#include <std.h>
inherit OBJECT;

object scry_object;
int send_living_name(object targ);
int long_look_room(object dest);

void create(){
   ::create();
   set_name("stage");
   set_id(({"stage","performance stage","platform","ballroom"}));
   set_short("%^RESET%^%^ORANGE%^a large wooden stage%^RESET%^");
   set_property("no animate", 1);
   set_long("%^BOLD%^%^WHITE%^From the "
"balcony you can see all of the ballroom below, where people in brightly clad "
"costumes mingle and dance.  The golden wood of the floor gleams under the "
"light of magically lit globes of crystal, and the white marble of the walls "
"glitters when that same light catches against the imbedded quartz veins.  On "
"the far side of the ballroom a large stage can be seen, one portion sectioned "
"off for musicians, while the rest is available for performers to use during "
"the contest. You can %^YELLOW%^<look at stage> %^WHITE%^if you want to take a "
"closer look at the performance stage.%^RESET%^");
   set_value(1);
   set_weight(100000);
   set_no_clean(1);
}

int get() { return 0; }
int drop() { return 1; }

void init(){
   ::init();
   add_action("look_em","look");
}

int look_em(string str) {
  if(str != "at stage") return 0;
  if(TP->query_blind() || TP->query_blindfolded() || TP->query_unconscious()){
     write("You cannot do that in your current state!");
     return 1;
  }
  write("You look over at the performance stage.");
  long_look_room(find_object_or_load("/d/av_rooms/lurue/masq_m3"));
  return 1;
}

int long_look_room(object dest){
    object *inv;
    int i,j;
    message("room_description","\n%^BOLD%^%^CYAN%^[Stage] %^RESET%^"+(string)dest->query_long()+"", TP);
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
            message("living_item", "%^BOLD%^%^CYAN%^[Stage] %^RESET%^"+str,TP);
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
       message("living_item", "%^BOLD%^%^CYAN%^[Stage] %^RESET%^"+str, TP);
    }
    known = 0;
    return 1;
}
