#include <std.h>
#include "../../tecqumin.h"
#define DEST "/daemon/destinations_d.c"
#define OTHERSIDE "stockade"
#include <party.h>

inherit TABAXROOM + "field_base.c";

string long_desc();
int gate;

int check_open();

void create() {
  ::create();
  DEST->add_waystation(file_name(TO), file_name(TO), 1);
  DEST->add_waystation(file_name(TO), TABAXROOM + "treetop_base1", 2);
  DEST->add_waystation(file_name(TO), TABAXROOM +"jungle27", 2);
  DEST->add_waystation(file_name(TO), TABAXROOM +"jungle09", 3);
  DEST->add_waystation(file_name(TO), TABAXROOM +"jungle04", 3);
  DEST->add_waystation(file_name(TO), TABAXROOM +"jungle16", 3);
  DEST->add_waystation(file_name(TO), TABAXROOM +"jungle18", 4);
  gate = 500;
  set_name("The main field");
  set_indoors(0);
  set_property("light", 2);
  set_terrain(GRASSLANDS);
  set_travel(FOOT_PATH);
  set_short("%^GREEN%^A well tended m%^ORANGE%^a%^GREEN%^i%^BOLD%^%^YELLOW%^z%^RESET%^%^GREEN%^e"
           +" field");
  set_long( (:TO, "long_desc":) );
  set_items(([ ({"maize", "corn", "plants"}): (: TO, "long_corndesc" :),  
                "stockade" : (: TO, "stock_desc":), 
                "gate" : (:TO, "gate_desc" :),
             ({"battlement", "battlements"}): (: TO, "batt_desc" :)  ]));
   set_exits( ([ "east" : TABAXROOM + "corner_field2",
                 "west": TABAXROOM + "corner_field1",
                "south": TABAXROOM + "entry"]) );
  if (check_open() == 1){
    add_exit(TABAXROOM + OTHERSIDE, "north");
  }
  battlement = find_object_or_load(TABAXROOM + "battlement6");
  set_post_exit_functions( ({ "north" }), ({ "go_north" }) );
}

void init() {
   ::init();
   add_action("open_gate", "open");
   add_action("close_gate", "close");
   add_action("knock_gate", "knock");
}

int open_gate(string str){
  if (interact("gate", str)){
    tell_object(TP, "The gate can't be opened from this side. There"
              +" must be a mechanism on the other side - or you could"
              +" always try to batter it down");
    return 1;
  }
  return 1;
}

int close_gate(string str){
  if (str == "gate"){
    tell_object(TP, "The gate can't be closed from this side. There"
              +" must be a mechanism for doing that on the other side.");
    return 1;
  }
  return 1;
}

int knock_gate(string str){
  object * party;
  string party_name;
  if (str != "gate" && str != "on gate"){
    notify_fail("Knock on what?");
    return 0;
  }
  if (query_exit("north") == TABAXROOM + OTHERSIDE){
    tell_object(TP, "You don't need to"
                   +" knock, you can just walk north.");
    return 1;
  }
  party_name = TP->query_party();
  if (stringp(party_name)){
    party = (object *)PARTY_OB->query_party_members(party);
  }
  if (sizeof(party)<1){
    party = ({TP});
  }
  tell_room(TO, TPQCN + " knocks on the gate.", TP);
  tell_object(TP, "You knock on the gate.");
  call_out("usher", 2, party);
  return 1;
}

void usher (object * party){
  object mover, room;
  int i;
  tell_room(TO, "The gate swings open");
  if (sizeof(party)<1){
    return;
  }
  room = find_object_or_load(TABAXROOM + OTHERSIDE);
  if (!objectp(room)){
    tell_room(TO, "Error with destination room when you knocked on the gate."
                +" Please tell someone that Lujke is a silly lizard. Or make"
                +" a bug report or something");
    return;
  }
  for (i=0;i<sizeof(party);i++){
    mover = party[i];
    if (objectp(mover) && present(mover, TO)){
      tell_object(mover, "You are ushered through the gate");
      tell_room(TO, (string)mover->QCN + " is ushered through the gate", mover);
      mover->move(room);
      mover->force_me("look");
    }
  }
  tell_room(TO, "The gate swings closed again");
}

int query_gate_open(){
  if (query_exit("north")==TABAXROOM + OTHERSIDE){
    return 1;
  }
  return 0;
}

int check_open(){
  object room;
  room = find_object_or_load(TABAXROOM + OTHERSIDE);
  if (objectp(room)){
    return room->query_gate_open();
  } else {
    return 0;
  }
}

void gate_opens(){
  if (query_gate_open() ==1){
    return;
  }
  tell_room(TO, "%^ORANGE%^Under the power of an unseen mechanism, the stockade"
               +" gate creaks open");
  add_exit(TABAXROOM + "stockade", "north");
}

void gate_closes(){
  if (query_gate_open()==0){
    return;
  }
  tell_room(TO, "%^ORANGE%^Under the power of an unseen mechanism, the stockade"
               +" gate creaks closed");
  remove_exit("north");
}

void reset_battlement(){
  battlement = find_object_or_load(TABAXROOM + "battlement6");
}

string query_gate_condition(){
  string desc;
  desc = "";
  switch (gate){
  case 1..50:
    desc += " and was well reinforced but is now badly damaged. The hinges are %^BOLD%^%^RED%^twisted"
           +" %^RESET%^and %^BOLD%^%^BLACK%^buckled %^RESET%^and the gate"
           +" hangs at an alarming angle. It looks ready to fall to the ground.";
    break;
  case 51..100:
    desc += " and was well reinforced, but is now showing major signs of damage. The %^ORANGE%^wood"
           +" %^RESET%^has splintered all the way through leaving gaping holes and it's not hanging"
           +" straight.";
    break;
  case 101..200:
    desc += " and is well reinforced, but is showing real signs of damage. The %^ORANGE%^wood"
           +" %^RESET%^is starting to splinter in several places, and small gaps are showing around"
          +" the hinges.";
    break;
  case 201..300:
    desc +=" and is well reinforced, but showing some minor signs of damage. A few splinters of wood"
          +" can be seen, and"
          +" the surface of it is dented in a few places";
    break;
  case 301..400:
    desc += " and is well reinforced, making it more difficult to batter down or force open. The gate"
           +" is in near pristine condition. Almost no damage can be seen on it.";
    break;
  case 401..501:
    desc += " and is well reinforced, making it more difficult to batter down or force open. It looks"
           +" in perfect condition";
    break;
  default:
    desc += " %^RESET%^but has now been completely battered off its hinges and is lying in the mud on"
           +" the ground.";
    break;
  }
  return desc;
}

string gate_desc(){
  string desc;
  desc = "The %^ORANGE%^stockade gate%^RESET%^ is tall, and robust looking, built from the strongest"
        +" timbers of the %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^"
        +"%^GREEN%^e%^RESET%^ trees. It is designed to open outwards";
  desc += query_gate_condition();
  if (query_exit("north")==TABAXROOM + OTHERSIDE){
    desc += " The gate is currently open, allowing you to head north into the stockade";
  }
  return desc;
}

string stock_desc(){
  string desc;
  desc =  "%^ORANGE%^A sturdy looking wooden stockade stands to the north. The walls are twenty feet"
         +" high and it looks like there are %^RESET%^battlements%^ORANGE%^ behind them, as well as a"
         +" %^RESET%^watch tower %^ORANGE%^above the gate. The %^RESET%^main"
         +" gate%^ORANGE%^ is in the southern wall, just in front of you here.";
  switch (gate){
  case 1..50:
    desc += " %^BOLD%^%^RED%^The gate is badly damaged. The hinges are %^RESET%^twisted%^BOLD%^%^RED%^"
           +" and %^BOLD%^%^BLACK%^buckled %^BOLD%^%^RED%^and the gate"
           +" hangs at an alarming angle. It looks ready to fall to the ground.";
    break;
  case 51..100:
    desc += " %^RESET%^%^RED%^The gate is showing major signs of damage. The %^ORANGE%^wood%^RED%^ has"
           +" splintered all the way through leaving gaping holes and it's not hanging straight.";
    break;
  case 101..200:
    desc += " %^RESET%^%^MAGENTA%^The gate is showing real signs of damage. The %^ORANGE%^wood"
           +" %^MAGENTA%^is starting to splinter in several places, and small gaps are showing around"
          +" the hinges.";
    break;
  case 201..300:
    desc +=" The gate is showing some minor signs of damage. A few splinters of wood can be seen, and"
          +" the surface of it is dented in a few places";
    break;
  case 301..400:
    desc += " The gate is in near pristine condition. Almost no damage can be seen on it.";
    break;
  case 401..501:
    desc += " The gate is showing no visible signs of damage.";
    break;
  default:
    desc += " %^RESET%^The gate has been completely battered off its hinges and is lying in the mud on"
           +" the ground.";
    break;
  }
  return desc;
}

int query_gate(){
  return gate;
}

void set_gate(int g){
  gate = g;
}

string long_desc(){
  string desc, corndesc, pitdesc, stakedesc;
  corndesc = corn_desc(); // Gives a different description for the maize, depending on current month
  pitdesc = pit_desc(); //gives a description of the pits (if any) in the field
  stakedesc = stake_desc(); // gives a description of the stakes (if any) in the field
  desc =  "You stand in a large field of maize. " + corndesc + " A solid looking %^ORANGE%^stockade"
        +" %^RESET%^bars the way to the north, with a central %^ORANGE%^gate%^RESET%^ and a"
         +" %^ORANGE%^watch tower%^RESET%^ above the gate. %^GREEN%^Terraced fields"
         +" %^RESET%^stand to the east and to the west, surrounding the %^ORANGE%^stockade%^RESET%^ on"
         +" three sides. The western field is higher than the field you are standing in, and the"
         +" eastern one is lower.\n";
  if (pitdesc) desc += pitdesc;
  if (stakedesc) desc += stakedesc;
  return desc;
}

string query_batterable(){
  return "gate";
}

int batter(string str, object ob, object ram_int){
  int damage, i, j, num;
  object stockade,  room, orog, *critters;
  string * rooms;
  if(!objectp(ram_int)){
    return 0;
  }
  if(sizeof(all_living(ram_int))<2){
    tell_room(ram_int, "There aren't enough people operating the ram to batter anything!");
    tell_room(TO, "The %^BOLD%^%^BLACK%^battering ram%^RESET%^ appears to be lacking enough people"
                 +" operating it to batter anything.");
    orog = present("orog", TO);
    if (objectp(orog)){
      orog->force_me("enter ram");
      orog->call_out("force_me", 2, "batter gate");
    }
    return 1;
  }
  tell_room(ram_int, "%^BOLD%^%^CYAN%^You swing the ram back and %^RED%^SLAM %^CYAN%^it into the"
                    +" gate!");
  tell_room(TO, "The %^BOLD%^%^BLACK%^battering ram %^RESET%^swings back and %^BOLD%^%^RED%^SLAMS"
               +" %^RESET%^into the gate");
  damage = 30 + random(35);
  gate -= damage;
  if (gate<1){
    add_exit(TABAXROOM + "stockade", "north");
    add_item("gate", "The gate has been completely smashed in, leaving the entrance to the stockade"
            +" wide open");
    stockade = find_object_or_load(TABAXROOM + "stockade");
    if (objectp(stockade)){
      tell_room(stockade, "With a loud crash the gate collapses inward under the fierce battering"
                         +" it has taken");
      stockade->add_exit(TABAXROOM + "main_field", "south");
    }
    tell_room(ram_int, "%^MAGENTA%^The gate finally %^BOLD%^%^RED%^breaks%^RESET%^%^MAGENTA%^ and"
                      +" collapses inward.");
    DEST->remove_destination(TABAXROOM + "granary");
    DEST->generate_waystations(TABAXROOM + "granary", 4, 4);
    rooms = ({"high_field", "low_field", "main_field", "stockade", "granary", "north_section", 
              "east_section", "west_section", "northwest_corner", "southeast_corner", 
              "southwest_corner", "northeast_corner", "trainer", "kitchen", "foodhall", "smithy",
              "battlement1", "battlement2", "battlement3", "battlement4", "battlement5", 
              "battlement6", "battlement7", "battlement8", "centre", "stockwall1", "stockwall2", 
              "stockwall3", "treetop_base", "treetop_base2", "treetop_base3", "treetop1",
              "treetop2", "treetop3"});
    for (i=0;i<sizeof(rooms);i++){
      room = find_object_or_load(TABAXROOM + rooms[i]);
      if (objectp(room)){
        tell_room(room, "%^BOLD%^%^YELLOW%^A huge %^BOLD%^%^RED%^crash%^BOLD%^%^YELLOW%^ resounds"
                       +" around the %^RESET%^%^ORANGE%^stockade%^BOLD%^%^YELLOW%^ as the"
                       +" %^RESET%^%^ORANGE%^gate%^BOLD%^%^YELLOW%^ gives way under the battering"
                       +" ram's fearsome assault and collapses inward!");
        tell_room(room, "%^MAGENTA%^There is a sudden rush as all the orogs in the vicinity make"
                       +" a dash for the granary!");
        critters = children(MOB + "orog");
        num = sizeof(critters);
        if (num>0){
          for (j=0;j<num;j++){
            if (critters[j]->id("orog")){
              critters[j]->start_walking(TABAXROOM + "granary");
              critters[j]->set_entry_method("battered down the gate with a huge ram to gain entry"
                                           +" to the stockade");

            }
          } 
        }
      }
    }
    return 1;
  }
  call_out("batter", 2+ random(3), str, ob, ram_int);
  return 1;
}
