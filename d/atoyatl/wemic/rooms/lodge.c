//Coded by Lujke//
#include <std.h>
#include "../wemic.h"

inherit ROOM;
object* plat_guests;
string query_plat_occupants();

void create(){
  ::create();
  plat_guests = allocate(6);
  set_name("A hunting lodge");
  set_short("Inside a hunting lodge");
  set_long( (:TO, "long_desc":) );
  set_property("indoors", 1);
  set_property("light",1);
  set_terrain(WOOD_BUILDING);
  set_travel(FOOT_PATH);
  set_smell("default","");

  set_listen("default","");

    set_exits( ([ "curtain" : ROOMS + "balcony",
                  "out": ROOMS + "trail09"
    ]) );

  set_items( ([ ({"wall", "walls"}) : "The walls of the lodge are cut"
             +" from some unidentified %^ORANGE%^dun coloured hide"
             +"%^RESET%^. Beams of wood and massive bones add strength"
             +" and structure to the building.",

       ({"beam", "beams", "bone"}) : "The beams form a complex lattice,"
            +" adding strength to the lodge's walls and ceiling. Massive"
            +" thigh bones from a huge beast have been cut into strips to"
            +" work into the lattice, and several enormous rib bones"
            +" curve from the back of the lodge to the front, supporting"
            +" the sloping, curved ceiling.",

        "celing": "The ceiling is high and curved and slopes inwards from"
           +" the south wall at its lowest point to the north wall at its"
           +" highest. Massive rib bones support it and the overall"
           +" effect is not unlike the shape of an open clam shell. But"
           +" much bigger.",

        ({"platform", "platforms"}) : (:TO , "plat_desc":), 

        "bar" : "A simple long, wooden bar, just a touch higher than is"
               +" common in human establishments."
  ]) );
}

void init(){
  ::init();
  add_action("climb_func", "climb");
  add_action("jump_func", "jump");
  add_action("descend_func", "descend");
  add_action("descend_func", "down");
}


string long_desc(){
  string desc;
  desc =  "%^ORANGE%^Small %^BOLD%^%^YELLOW%^shafts%^RESET%^%^ORANGE%^ of"
        +" l%^BOLD%^%^YELLOW%^i%^RESET%^%^ORANGE%^ght pierce the %^BOLD%^"
        +"%^BLACK%^gloom %^RESET%^%^ORANGE%^of the lodge interior,"
        +" gaining access through a number of window slots covered with a"
        +" translucent, gauzy material. Once your eyes adjust, a long bar"
        +" can be made out long the south wall of the room. The rest of"
        +" the area is dotted with thick wooden beams holding up the high"
        +", sloped ceiling. A variety of fine %^MAGENTA%^blankets"
        +"%^ORANGE%^, %^BOLD%^%^WHITE%^f%^RESET%^u%^BOLD%^%^WHITE%^rs"
        +"%^RESET%^%^ORANGE%^ and %^BOLD%^%^CYAN%^m%^GREEN%^a%^CYAN%^ts"
        +"%^RESET%^%^ORANGE%^ have been provided for the %^BOLD%^"
        +"%^YELLOW%^W%^RESET%^%^ORANGE%^e%^BOLD%^%^YELLOW%^m%^RESET%^"
        +"%^ORANGE%^i%^BOLD%^%^YELLOW%^c%^RESET%^%^ORANGE%^ to sit on."
        +" under the highest section of the roof is a series of three"
        +" separate, tiered %^RESET%^platforms%^ORANGE%^, each supported"
        +" on a single thick beam under its centre. The walls are"
        +" decorated with a selection of weapons and hunting trophies.";
   return desc;
}

string plat_desc(){
  string desc;
  desc = "%^ORANGE%^The three platforms rise in steps, the first slightly"
        +" higher than a human's head, the second half as high again, and"
        +" the third a little higher than that. They are supported on"
        +" massive beams of wood, which have been s%^RESET%^c%^ORANGE%^ra"
        +"%^RESET%^p%^ORANGE%^ed r%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^gg"
        +"%^RESET%^e%^ORANGE%^d by many %^RESET%^claws%^ORANGE%^ over"
        +" time. Atop each platform is a cosy %^BOLD%^%^WHITE%^f"
        +"%^RESET%^u%^BOLD%^%^WHITE%^r%^RESET%^%^ORANGE%^ rug.\n"
        +"%^RESET%^" ;
  desc += query_plat_occupants();
  desc +="If there is space, you could probably climb to one of the"
        +" platforms if you wanted to.\n" ;
  return desc;
}

string night_desc(){


  return "";
}

void jump_down(object ob){
  int cur_occ_num, i;
  cur_occ_num = -1;
  for (i=0;i<6;i++){
    if (ob==plat_guests[i]){
      cur_occ_num = i;
    }
  }
  if (cur_occ_num == -1){
    tell_object(ob, "You don't need to jump down. You aren't on a"
                   +" platform at the moment.");
    return;
  }
  switch (cur_occ_num){
  case 0..1:
    tell_object(ob, "%^ORANGE%^You jump down to the floor from the lowest"
                   +" platform");
    tell_room(TO, "%^ORANGE%^"+ob->QCN + "%^RESET%^%^ORANGE%^ jumps down"
                 +" to the floor from the lowest platform", ob);
    break;
  case 2..3:
    tell_object(ob, "%^ORANGE%^You jump down from the middle platform to"
                   +" the lowest one then down to the floor");
    tell_room(TO, "%^ORANGE%^"+ob->QCN+ "%^RESET%^%^ORANGE%^ jumps from"
                 +" the middle platform to the lowest one, then down to"
                 +" the floor", ob);
    break;
  case 4..5:
    tell_object(ob, "%^ORANGE%^You jump down from the highest platform to"
                   +" the middle one, then to the lowest one and finally"
                   +" down to the floor");
    tell_room(TO, "%^ORANGE%^"+ ob->QCN + "%^RESET%^%^ORANGE%^ jumps from"
                 +" the highest platform to the middle one, then to the"
                 +" lowest one and finally down to the floor", ob);
    break;
  }
  plat_guests[cur_occ_num] = 0;
  ob->force_me("pose clear");
}

int jump_func(string str){
  if (str!= "down"){
    tell_object(TP, "Try 'jump down'");
    return 1;
  }
  jump_down(TP);
}

int descend_func(string str){
  jump_down(TP);
  return 1;
}

string query_plat_occupants(){
  int i;
  string occupants, platform, addition;
  object occupier1, occupier2;
  occupants = "";
  for (i=0;i<3;i++){
    occupier1 = plat_guests[i*2];
    occupier2 = plat_guests[(i*2)+1];
    
    if (i==0){platform = "lower";}
    if (i==1){platform = "middle";}
    if (i==2){platform = "highest";}

    if (objectp(occupier1)){
      
      if (objectp(occupier2)){

        addition = (string)occupier1->QCN + " and " 
                  + (string) occupier2->QCN + " are"
                  +" together on the " + platform + " platform.\n";
        occupants += addition;
      } else {

        occupants += (string)occupier1->QCN + " is alone on the " 
                  + platform + " platform.\n";
      }       
    } else {
      if (objectp(occupier2)){

        occupants += (string) occupier2->QCN + " is alone on the " 
                  + platform + " platform.\n";
      }
    }
  }
  if (occupants ==""){
    occupants = "The platforms are empty at the moment.\n";
  }

  return occupants;
}


int climb_func(string str){
  int plat_num, cur_occ_num, transfer_num, i;
  object occupier1, occupier2;
  string plat_name;

  if (!str){
    tell_object(TP, "Try 'climb to platform <number>'");
    return 1;
  }
  if (str=="down"){
    jump_down(TP);
    return 1;
  }
  if (sscanf(str, "to platform %d", plat_num)<1){
    tell_object(TP, "Try 'climb to platform <number>'");
    return 1;
  }
  cur_occ_num = -1;
  for (i=0;i<6;i++){
    if (TP==plat_guests[i]){
      cur_occ_num = i;
      break;
    }
  }
  switch(plat_num){
  case 1:
    plat_name = "lowest";
    occupier1 = plat_guests[0];
    occupier2 = plat_guests[1];
    break;
  case 2:
    plat_name = "middle";
    occupier1 = plat_guests[2];
    occupier2 = plat_guests[3];
    break;
  case 3:
    plat_name = "highest";
    occupier1 = plat_guests[4];
    occupier2 = plat_guests[5];
    break;
  default:
    tell_object(TP, "Try 'climb to platform 1' (the lowest platform)\n"
                   +" or 'climb to platform 2' (the middle platform)\n"
                   +" or 'climb to platform 3' (the highest platform)");
    return 1;  
  }
  if (TP==occupier1 ||TP==occupier2){
    tell_object(TP, "There's no need to climb to the " + plat_name + " platform. You are"
                   +" already there!");
    return 1;
  }

  if (objectp(occupier1) && objectp(occupier2)&& present(occupier1, TO)
                                                      &&present(occupier2, TO)){
    tell_object(TP, "You can't climb to the " + plat_name + " platform. " + occupier1->QCN 
                   +" and " + occupier2->QCN + " are already up there"
                   +" and there isn't enough room for any more.");
    return 1;
  }

  if (cur_occ_num >-1){
    transfer_num = (((cur_occ_num/2)+1)*10)+plat_num;
    switch(transfer_num){
    case 12: 
      tell_object(TP, "%^ORANGE%^You jump up from the lowest platform to the middle one.");
      tell_room(TO, "%^ORANGE%^"+ TPQCN+ "%^RESET%^%^ORANGE%^jumps languidly from the lowest"
                   +" platform to the middle one.", TP);
      TP->force_me("pose sitting atop the middle platform");
      break;
    case 13:
      tell_object(TP, "%^ORANGE%^You jump up from the lowest platform to the middle one and"
                     +" then to the highest one");
      tell_room(TO, "%^ORANGE%^"+ TPQCN+ "%^RESET%^%^ORANGE%^jumps languidly from the lowest"
                   +" platform to the middle one and then up to the top one.", TP);
      TP->force_me("pose sitting atop the highest platform");
      tell_room(TO, "%^ORANGE%^" + TPQCN + "%^RESET%^%^ORANGE%^ looks faintly smug.", TP);  
      break;
    case 21:
      tell_object(TP, "%^ORANGE%^You jump down from the middle platform to the lowest one.");
      tell_room(TO, "%^ORANGE%^"+ TPQCN+ "%^RESET%^%^ORANGE%^jumps languidly from the middle"
                   +" platform down to the lowest one.", TP);
      TP->force_me("pose sitting atop the lower platform");
      break;
    case 23:
      tell_object(TP, "%^ORANGE%^You jump up from the middle platform to the highest one.");
      tell_room(TO, "%^ORANGE%^"+ TPQCN+ "%^RESET%^%^ORANGE%^jumps languidly from the middle"
                   +" platform to the highest one.", TP);
      TP->force_me("pose sitting atop the highest platform");
      tell_room(TO, "%^ORANGE%^" + TPQCN + "%^RESET%^%^ORANGE%^ looks faintly smug.", TP);
      break;
    case 31:
      tell_object(TP, "%^ORANGE%^You jump down from the highest platform to the middle one,"
                     +" then down to the lowest.");
      tell_room(TO, "%^ORANGE%^"+ TPQCN+ "%^RESET%^%^ORANGE%^jumps languidly from the highest"
                   +" platform to the middle one, then down to the lowest.", TP);
      TP->force_me("pose sitting atop the lower platform");
      break;
    case 32:
      tell_object(TP, "%^ORANGE%^You jump down from the highest platform to the middle one.");
      tell_room(TO, "%^ORANGE%^"+ TPQCN+ "%^RESET%^%^ORANGE%^jumps languidly from the highest"
                   +" platform to the middle one.", TP);
      TP->force_me("pose sitting atop the middle platform");
      break;
    default:
      tell_room(TO, "Something's gone horribly wrong with the platforms! Run! Run for your"
                   +" lives before the whole building collapses! (Or tell a wiz there is a bug"
                   +" with the platforms in this room)");
      return 1; 
    }
    plat_guests[cur_occ_num] = 0;
    if (!objectp(plat_guests[(plat_num-1)*2])){
      plat_guests[(plat_num-1)*2] = TP;
    } else {
      plat_guests[((plat_num-1)*2)+1] = TP;
    }
  return 1;
  }

  switch (plat_num){
  case 1:
    tell_object(TP, "%^ORANGE%^You climb to the lowest platform and settle there");
    tell_room(TO, "%^ORANGE%^" + TPQCN + "%^RESET%^%^ORANGE%^ climbs to the lowest platform"
                +" and settles there", TP);
    TP->force_me("pose sitting atop the lower platform");
    break;
  case 2:
    tell_object(TP, "%^ORANGE%^You climb to the lowest platform then jump up to the middle"
                  +" one and settle there");
    tell_room(TO, "%^ORANGE%^" + TPQCN + "%^RESET%^%^ORANGE%^ climbs to the lowest platform,"
                 +" then jumps languidly across to the middle one and settles there", TP);
    TP->force_me("pose sitting atop the middle platform");
    break;
  case 3:
    tell_object(TP, "%^ORANGE%^You climb to the lowest platform then jump up to the middle"
                  +" and then on to the highst one, where you settle.");
    tell_room(TO, "%^ORANGE%^" + TPQCN + "%^RESET%^%^ORANGE%^ climbs to the lowest platform,"
                 +" then jumps languidly across to the middle one and then on to the highst"
                 +" one, where " + TP->QS + " settles.", TP);
    tell_room(TO, "%^ORANGE%^" + TPQCN + "%^RESET%^%^ORANGE%^ looks faintly smug.", TP);
    TP->force_me("pose sitting atop the highest platform");
    break;
  }
  if (!objectp(plat_guests[(plat_num-1)*2])){
    plat_guests[(plat_num-1)*2] = TP;
  } else {
    plat_guests[((plat_num-1)*2)+1] = TP;
  }
  return 1;
}

object query_plat_guests(){
  return plat_guests;
}
