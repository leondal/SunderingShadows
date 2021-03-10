//Updated by Lujke April 2007
#include <std.h>
#include "cardpics2.h"
#define BAD_VERBS ({"drop", "put"})

inherit OBJECT;

string face;

object who;

int faceUp = 0 ;
string deck_id;


string query_card_name();
string * query_card_pic(); //added by Lujke to implement card pics

void create(){
    ::create();

    set_name("card");
    set_id(({"card"}));
    set_short("A card");
    set_long("This is a thick parchment with strange symbols on it.");
   set_property("no animate", 1);

    set_value(0);
    set_weight(1);

}

void set_deck_id(string id){
    deck_id = id;
    add_id(deck_id);
}

string get_deck_id(){ // changed to return type string by Lujke because
    return deck_id;  // it didn't seem to make sense for it to be void.
}

void set_face_up(int xx){
    faceUp = xx;
}

int query_face_up(){
    return faceUp;
}

string query_long(string str){
    string slong, *pic;
    int i;
    slong = "";
    pic = query_card_pic();
    for (i=0;i<sizeof(pic);i++){
        slong += pic[i] + "\n";
    }
    return slong;
}

string query_short(){
    string sshort;
    sshort = ::query_short();
    if(((member_array(query_verb(), BAD_VERBS) == -1) && TP== ETO) || faceUp) {
        sshort = sshort +" "+query_card_name();
    }
    return sshort;
}

void set_face(string str){
    face = str;
}

string query_card(){
    return face;
}

string * query_card_pic(){ //added by Lujke to implement card pics
  string * pic, suit,card;
  if(!face) {
      return ({""});
  }
  suit = face[strlen(face)-1..strlen(face)];
  card = face[0..strlen(face)-2];
  if (faceUp==0 && objectp(ETO) && !interactive(ETO)){
    return CARDBACK;
  }
  switch (suit){
  case "T":
    switch (card){
    case "2":
      pic = TWOTOWERS;
      break;
    case "3":
      pic = THREETOWERS;
      break;
    case "4":
      pic = FOURTOWERS;
      break;
    case "5":
      pic = FIVETOWERS;
      break;
    case "6":
      pic = SIXTOWERS;
      break;
    case "7":
      pic = SEVENTOWERS;
      break;
    case "8":
      pic = EIGHTTOWERS;
      break;
    case "9":
      pic = NINETOWERS;
      break;
    case "10":
      pic = TENTOWERS;
      break;
    case "H":
      pic = HUNTERTOWERS;
      break;
    case "D":
      pic = DAMSELTOWERS;
      break;
    case "L":
      pic = LORDTOWERS;
      break;
    case "R": 
      pic = ROGUETOWERS;
      break;
    }
    break;
  case "G":
    switch (card){
    case "2":
      pic = TWOGEMS;
      break;
    case "3":
      pic = THREEGEMS;
      break;
    case "4":
      pic = FOURGEMS;
      break;
    case "5":
      pic = FIVEGEMS;
      break;
    case "6":
      pic = SIXGEMS;
      break;
    case "7":
      pic = SEVENGEMS;
      break;
    case "8":
      pic = EIGHTGEMS;
      break;
    case "9":
      pic = NINEGEMS;
      break;
    case "10":
      pic = TENGEMS;
      break;
    case "H":
      pic = HUNTERGEMS;
      break;
    case "D":
      pic = DAMSELGEMS;
      break;
    case "L":
      pic = LORDGEMS;
      break;
    case "R": 
      pic = ROGUEGEMS;
      break;
    }
    break;
  case "S":
    switch (card){
    case "2":
      pic = TWOSWORDS;
      break;
    case "3":
      pic = THREESWORDS;
      break;
    case "4":
      pic = FOURSWORDS;
      break;
    case "5":
      pic = FIVESWORDS;
      break;
    case "6":
      pic = SIXSWORDS;
      break;
    case "7":
      pic = SEVENSWORDS;
      break;
    case "8":
      pic = EIGHTSWORDS;
      break;
    case "9":
      pic = NINESWORDS;
      break;
    case "10":
      pic = TENSWORDS;
      break;
    case "H":
      pic = HUNTERSWORDS;
      break;
    case "D":
      pic = DAMSELSWORDS;
      break;
    case "L":
      pic = LORDSWORDS;
      break;
    case "R": 
      pic = ROGUESWORDS;
      break;
    }
    break;
  case "C":
    switch (card){
    case "2":
      pic = TWOCLUBS;
      break;
    case "3":
      pic = THREECLUBS;
      break;
    case "4":
      pic = FOURCLUBS;
      break;
    case "5":
      pic = FIVECLUBS;
      break;
    case "6":
      pic = SIXCLUBS;
      break;
    case "7":
      pic = SEVENCLUBS;
      break;
    case "8":
      pic = EIGHTCLUBS;
      break;
    case "9":
      pic = NINECLUBS;
      break;
    case "10":
      pic = TENCLUBS;
      break;
    case "H":
      pic = HUNTERCLUBS;
      break;
    case "D":
      pic = DAMSELCLUBS;
      break;
    case "L":
      pic = LORDCLUBS;
      break;
    case "R": 
      pic = ROGUECLUBS;
      break;
    }
    break;
  }  
  return pic;
}

string query_card_name(){
    string suit,card;

    if(!face) {
        return "";
    }
    suit = face[strlen(face)-1..strlen(face)];
    card = face[0..strlen(face)-2];
    if (suit == "T"){
        suit = "Towers";
    } else if(suit =="G"){
        suit = "Gems";
    } else if(suit == "S"){
        suit = "Swords";
    } else {
        suit = "Clubs";
    }
    if(card == "2") {
        card = "Two";
    } else if (card == "3"){
        card = "Three";
    } else if (card == "4"){
            card = "Four";
    } else if (card == "5"){
            card = "Five";
    } else if (card == "6"){
            card = "Six";
    } else if (card == "7"){
            card = "Seven";
    } else if (card == "8"){
            card = "Eight";
    } else if (card == "9"){
            card = "Nine";
    } else if (card == "10"){
            card = "Ten";
    } else if (card == "H"){
            card = "Hunter";
    } else if (card == "D"){
            card = "Damsel";
    } else if (card == "L"){
            card = "Lord";
    } else if (card == "R"){
            card = "Rogue";
    }

    return card+" of "+suit;
}

init(){
    ::init();
    add_action("view","view");
    add_action("flip","flip");
    add_action("reveal","reveal");
    if (ETO == TP) {
        faceUp = 0;
    }
}

int reveal(string str){
    int i;
    object ob;
    if (!str || str != "hand") {
        return notify_fail("Reveal what?\n");
    }
    i=1;
    tell_object(TP,"You reveal your hand to the room.");
    tell_room(ETP,TPQCN +" reveals "+TP->query_possessive()+" hand to the room.",TP);
    while ((ob=present("card"+" "+i))) {
        // changed by lujke April 2007, to allow cards from different decks
       // to form a hand
        tell_room(ETP,"%^YELLOW%^"+i+"> "+ob->query_card_name());
        i++;
    }
    return 1;
}

int flip(string str){
    if (!str) {
        return notify_fail("Flip what?\n");
    }

    if (TO != present(str, ETP)) {
        return notify_fail("Flip what?\n");
    }
    if (query_face_up()) {
        tell_object(TP,"You flip the card over hiding its face.");
        tell_room(ETP,TPQCN+" flips a card over hiding its face.",TP);        
    } else {
        tell_object(TP,"You flip the card revealing it as a "+query_card_name()+".");
        tell_room(ETP,TPQCN+" flips a card revealing it as a "+query_card_name()+".",TP);
    }
    set_face_up(!query_face_up());
    return 1;
}

string get_hand_pic(){
  int i, j;
  object ob, * inv, * hand;
  string * pic, result;
  hand = ({});
  if (!objectp(ETO)){return "error = problem with the card's environment."
                 +" If this is you, seek medical assistance immediately";}
  inv = all_inventory(ETO);
  if(!(ob=present("card",ETO))){
     return "You don't have any cards in hand!";
  }
  for (i=0;i<sizeof(inv);i++){
    if (inv[i]->id("card")){
      hand += ({inv[i]});
    }
  }
  ob = hand[0];
  pic = query_card_pic();  
  result = "";
  tell_room(ETP,TPQCN +" looks over "+TP->query_possessive()+" hand.",TP);
  if (sizeof(hand)<6){
    for (j=0;j<sizeof(pic);j++){
      for (i=0;i<sizeof(hand);i++){
//        if (!hand[i]->query_faceup() && ETO->id("table")){
//          pic = CARDBACK;
//        } else {
          pic = hand[i]->query_card_pic();
//       }
        if (j<sizeof(pic)){
          result += pic[j] + " ";
        } else {
          result += "              ";
        }
      }
      result += "\n";
    }
     return result;
  }
  while ((ob=present(deck_id+" "+i,TP))) {
      result += ""+i+"> "+ob->query_card_name();
      i++;
  }
  return result;
}

int view(string str){
    int i, j;
    object ob, * inv, * hand;
    string * pic, result;
    hand = ({});
    if (str != "hand") {
        return notify_fail("View what?\n");
    }
    i=1;
    inv = all_inventory(TP);
    if(!(ob=present("card",TP))){
       tell_object(TP,"You don't have any cards in hand!");
       return 1;
    }
    for (i=0;i<sizeof(inv);i++){
      if (inv[i]->id("card")){
        hand += ({inv[i]});
      }
    }
    ob = hand[0];
    pic = query_card_pic();  
    result = "";
    tell_object(TP,"You look over your hand.");
    tell_room(ETP,TPQCN +" looks over "+TP->query_possessive()+" hand.",TP);
    if (sizeof(hand)<6){
      for (j=0;j<sizeof(pic);j++){
        for (i=0;i<sizeof(hand);i++){
          pic = hand[i]->query_card_pic();
          result += pic[j] + " ";
        }
        result += "\n";
      }
      tell_object(TP, result);
      return 1;
    }
    while ((ob=present(deck_id+" "+i,TP))) { 
        tell_object(TP,""+i+"> "+ob->query_card_name());
        i++;
    }
    return 1;
//fixed by Circe to show cards in hand rather than on the floor.
//also added check for no cards in hand 6/26/04
}

