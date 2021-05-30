#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;

object * trainees;

void create() {
  ::create();
  trainees = ({});
  set_short("Training field");
  set_long("You are in the western section of the%^ORANGE%^"
    +" stockade%^RESET%^. This %^GREEN%^field %^RESET%^has"
    +" been set up with an archery range. The targets are"
    +" all lined up to the west. A %^ORANGE%^circular"
    +" sparring area%^RESET%^ and a number of%^ORANGE%^"
    +" straw padded targets%^RESET%^ are located to the"
    +" east. This would be a good place to train as an archer");
  set_exits( ([ "east": TABAXROOM + "west_section",
               "west" : TABAXROOM + "arch1"
             ]) );

}

void init(){
  ::init();
  add_action("train_em", "train");
  set_had_players(3);
}

string query_granary_dir(){
  return "east";
}

void reset(){
  int i, j, flag;
  object war, * commanders, *stuff;
  ::reset();
  if (sizeof(trainees)>0){
  tell_room(TO, "%^ORANGE%^Another batch of tabaxi trainees graduate to archer status");
    for(i=0;i<sizeof(trainees);i++){
      if (!present(trainees[i], TO)){
        continue;
      }
      war = new (MOB + "tabaxi_archer");
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
  trainees = ({});
}

int train_em(string str){
  object * wielded, who;
  who = previous_object();
  if (!objectp(who))
  {
    tell_object(TP, "Your skills are somewhat more advanced than could be improved at these facilities. You do not need to train here"); 
  }
  if (who->id("tabaxi peasant"))
  {
    wielded = TP->query_wielded();
    if (sizeof(who->query_wielded())<1)
    { 
      tell_room(TO, who->QCN + " would like to train, but doesn't have a weapon in hand to train with");
      return 1;
    }
    if (!wielded[0]->is_lrweapon())
    {
      tell_room(TO, who->QCN + " would like to train, but isn't wielding a missile weapon");
      return 1;      
    }
    trainees += ({TP});
    who->force_me("emote sets about training with " + TP->QP + " " +
                    (string)wielded[0]->query_short() );
    who->force_me("pose training with " + TP->QP + " " + (string)wielded[0]->query_short() );
    return 1;
  } else 
  {
    tell_object(who, "Your skills are somewhat more advanced than could be improved at these facilities. You do not need to train here");
  }
  return 0;
}

object * query_trainees(){
  return trainees;
}

