#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;

object * trainees;

void create() {
  ::create();
  trainees = ({});
  set_short("Training field");
  set_long("You are in the western section of the %^ORANGE%^stockade%^RESET%^. This %^GREEN%^field"
          +" %^RESET%^has been set up with a %^ORANGE%^circular sparring area%^RESET%^ and a number of"
          +" %^ORANGE%^straw padded targets%^RESET%^ for weapons practice. There are some%^ORANGE%^"
          +" archery targets%^RESET%^ in the archery range to the west. To the south, you can see"
          +" a somewhat %^GREEN%^overgrown field %^RESET%^with a %^ORANGE%^catapult%^RESET%^ in it."
          +" The main centre of the community is to the east");
  set_exits( ([ "north" : TABAXROOM + "northwest_corner" ,
               "south": TABAXROOM + "southwest_corner",
               "east" : TABAXROOM + "centre",
            "west" : TABAXROOM + "archery"
             ]) );

}

void init(){
  ::init();
  add_action("train_em", "train");
  set_had_players(3);
}

string query_granary_dir(){
  return "north";
}

void reset(){
  int i, j, flag;
  object war, * commanders, *stuff;
  ::reset();
  if (sizeof(trainees)>0){
  tell_room(TO, "%^ORANGE%^Another batch of tabaxi trainees graduate to warrior status");
    for(i=0;i<sizeof(trainees);i++){
      if (!present(trainees[i], TO)){
        continue;
      }
      war = new (MOB + "tabaxi_warrior");
      war->move(TO);
      commanders = trainees[i]->query_commanders();
      if (sizeof(commanders)>0){
        for (j=0;j<sizeof(commanders);j++){
          war->add_commander(commanders[j]);
        }
      }
      war->set_gender(trainees[i]->query_gender());
      stuff=all_inventory(trainees[i]);
      if (sizeof(stuff)>0){
        for (j=0;j<sizeof(stuff);j++){
          flag = 0;
          if (stuff[j]->query_worn()){
            flag = 1;
          }
          if (member_array(stuff[j], trainees[i]->query_wielded())!=-1){
            flag = 2;
          }
          stuff[j]->move(war);
          if (flag ==1){
            war->force_me("wear " + stuff[j]->QCN);
          }
          if (flag ==2){
            war->force_me("wield " + stuff[j]->QCN);
          }
        }
      }
      trainees[i]->remove();
    }
  }
}

int train_em(string str){
  object * wielded, who;
  who = previous_object();
  if (!objectp(who)){
    tell_object(TP, "Who is not a valid object. Sorry, training cannot occur."); 
  }
  if (who->id("tabaxi peasant")){
    if (sizeof(who->query_wielded())<1){ 
      tell_room(TO, who->QCN + " would like to train, but doesn't have a weapon in hand to train with");
      return 1;
    }
    trainees += ({TP});
    wielded = TP->query_wielded();
    who->force_me("emote sets about training with " + TP->QP + " " +
                    (string)wielded[0]->query_short() );
    who->force_me("pose training with " + TP->QP + " " + (string)wielded[0]->query_short() );
    return 1;
  } else {
    tell_object(who, "Your skills are somewhat more advanced than could be improved at these facilities. You do not need to train here");
  }
  return 0;
}

object * query_trainees(){
  return trainees;
}

