#include <std.h>
#include "../squires_trial.h"

#define RW "%^RESET%^%^WHITE%^"
#define BW "%^BOLD%^%^WHITE%^"
#define BR "%^BOLD%^%^RED%^"
#define BB "%^BOLD%^%^BLACK%^"

inherit BASEROOM;

int *tilesplaced;
int y;
int tilecol;
int x;
int opened;

void create(){
  ::create();
  tilesplaced = ({7,3,8,9,5,2,1,4,6});
  opened = 0;
  set_name("Squire's Trial Room 11");
  set_short("A square chamber");
  set_property("light",4);
  set_long( 

  
            (string) TO->stonedesc() +
            "  This is an enlarged chamber compared to the rest. " + 
            "  At" +
            " each corner of the room, a " +
            "%^RED%^t%^BOLD%^%^YELLOW%^o%^RED%^r%^YELLOW%^c%^RESET%^%^RED%^h%^WHITE%^" +
            " is mounted in an iron bracket," +
            " burning with flames which do not seem to consume.  A " +
            "%^RESET%^%^ORANGE%^bronze statue%^WHITE%^" +
            " of a vigilant armored knight" +
            " stands here, pointing to a " +
            "%^BOLD%^%^WHITE%^tiled panel%^RESET%^%^WHITE%^" +
            " on the west wall."
            
          );
          
          add_item(
              ({"statue","knight","bronze statue"}),
              "%^RESET%^%^ORANGE%^" +
              "This statue, made of pure bronze, stands vigilantly pointing at" +
              " the tiled section of the west wall.  The knight's other arm" +
              " is at his side, holding a cubic vault to his hip."
          );
          
          add_item(
              "vault",
              "%^RESET%^%^ORANGE%^" +
              "This bronze vault is a perfect cube, and is strongly" +
              " made as part of the statue itself.  A door on the front" +
              " panel is flush with the rest, and shows no sign of a " +
              "locking mechanism, yet it will not open."
          );
          
          add_item(
              ({"tiled panel","panel"}),
              "This panel is a shallow, square hollowed area cut from " +
              "the same stone as the rest of the walls.  " +
              "%^BOLD%^%^WHITE%^White tiles %^RESET%^" +
              "cover most of the recessed surface, except for a few " +
              "small square holes, spaced evenly across the vertical and " +
              "horizontal directions.  You could probably " +
              "%^BOLD%^%^RED%^view %^RESET%^%^WHITE%^the " +
              "%^BOLD%^%^RED%^panel " +
              "%^RESET%^%^WHITE%^or %^BOLD%^%^RED%^grid%^RESET%^%^WHITE%^."
          );
          
  set_exits(([
            "east" : SQUIREROOMS+"room10"
  ]));
}          

void init(){
  ::init();
  add_action("view_function","view");
  add_action("slide_function","slide");
}

int open_vault(){
  object obj;
  obj = new(SQUIREITEMS + "black_pearl");
  if(objectp(obj)) obj->move(ETP);
}

int switch_tiles(int first, int second){
  int swap;
  swap = tilesplaced[first];
  tilesplaced[first] = tilesplaced[second];
  tilesplaced[second] = swap;
  return 1;
}

int check_puzzle(){
  int pos;
  for(pos = 0; pos < 9; pos++){
    if(tilesplaced[pos] != pos+1)
      return 0;
  }
  return 1;
}

int slide_function(string str){
  int index;
  int five;
  int success;
  five = member_array(5,tilesplaced);
  success = 0;
  index = -1;
  if(opened){ tell_object(TP,"View what?"); return 1;}
  if(!str)  { tell_object(TP,"View what?"); return 1;}
  
  switch(str){
    case "a":
      index = 0;
    break;
    case "b":
      index = 1;
    break;
    case "c":
      index = 2;
    break;
    case "d":
      index = 3;
    break;
    case "e":
      index = 4;
    break;
    case "f":
      index = 5;
    break;
    case "g":
      index = 6;
    break;
    case "h":
      index = 7;
    break;
    case "i":
      index = 8;
    break;
  }
  
  if(index != -1 && index != five){
  
    if ( (index - 3 == five) ||
         (index + 3 == five) ||
         ((index - 1 == five) && (index % 3 != 0)) ||
         ((index + 1 == five) && (index % 3 != 2)) ){
      success = switch_tiles(index, five);
    }

  }
  if(success){
    if(check_puzzle() && !opened){
      open_vault();
      tell_object(TP, BW+"As you slide the last tile in to place" +
                      " there is a slight click as the vault " +
                      "held by the statue opens, drops something" +
                      " from within, and slams shut again!"+RW
      );
      
      tell_room(ETP, BW+"As " + TPQCN + " slides the last tile in to place" +
                      " there is a slight click as the vault " +
                      "held by the statue opens, drops something" +
                      " from within, and slams shut again!"+RW , TP);
      opened = 1;
    }
    else{
      tell_object(TP, BW+"The tile slides easily."+RW);
    }
  }
  if(!success){
    tell_object(TP,BW+"The tile won't budge."+RW);
  }
  return 1;
}


string tiles(int tilenum, int row){
  switch(tilenum){
    case 0:
      return RW+"XXXXXX"+BB;
    case 1:
    //tile 1
      switch(row){
        case 1:
          return BW + "      " + BB;
        break;
        case 2:
          return BW + "      " + BB;
        break;
        case 3:
          return BW + "  ____" + BB;
        break;
        case 4:
          return BW + " //---" + BB;
        break;
        case 5:
          return BW + "||    " + BB;
        break;
      }
    case 2:
    //tile 2
      switch(row){
        case 1:
          return BW + "      " + BB;
        break;
        case 2:
          return BW + "      " + BB;
        break;
        case 3:
          return BW + "__/\\__" + BB;
        break;
        case 4:
          return BW + "------" + BB;
        break;
        case 5:
          return BW + "      " + BB;
        break;
      }
    case 3:
    //tile 3
      switch(row){
        case 1:
          return BW + "  (0) " + BB;
        break;
        case 2:
          return BW + "  //  " + BB;
        break;
        case 3:
          return BW + "\\//_  " + BB;
        break;
        case 4:
          return BW + "---\\\\ " + BB;
        break;
        case 5:
          return BW + "    ||" + BB;
        break;
      }
    case 4:
    //tile 4
      switch(row){
        case 1:
          return BW + "||    " + BB;
        break;
        case 2:
          return BW + "||    " + BB;
        break;
        case 3:
          return BW + " \\\\   " + BB;
        break;
        case 4:
          return BW + "  \\\\  " + BB;
        break;
        case 5:
          return BW + "   \\\\ " + BB;
        break;
      }
    case 5:
      return RW+"XXXXXX"+BB;
      break;
    case 6:
    //tile 6
      switch(row){
        case 1:
          return BW + "    ||" + BB;
        break;
        case 2:
          return BW + "    ||" + BB;
        break;
        case 3:
          return BW + "   // " + BB;
        break;
        case 4:
          return BW + "  //  " + BB;
        break;
        case 5:
          return BW + " //   " + BB;
        break;
      }
    case 7:
    //tile 7
      switch(row){
        case 1:
          return BW + "    \\\\" + BB;
        break;
        case 2:
          return BW + "    /\\" + BB;
        break;
        case 3:
          return BW + "   / /" + BB;
        break;
        case 4:
          return BW + "  / / " + BB;
        break;
        case 5:
          return BW + "  \\/  " + BB;
        break;
      }
    case 8:
    //tile 8
      switch(row){
        case 1:
          return BW + "      " + BB;
        break;
        case 2:
          return BW + "\\    /" + BB;
        break;
        case 3:
          return BW + "\\\\  //" + BB;
        break;
        case 4:
          return BW + " \\\\// " + BB;
        break;
        case 5:
          return BW + "  \\/  " + BB;
        break;
      }
    case 9:
    //tile 9
      switch(row){
        case 1:
          return BW + "//    " + BB;
        break;
        case 2:
          return BW + "/     " + BB;
        break;
        case 3:
          return BW + "      " + BB;
        break;
        case 4:
          return BW + "      " + BB;
        break;
        case 5:
          return BW + "      " + BB;
        break;
      }
  }
  return "";
}

int view_function(object str){
  int i;
  string temp;
  
  if(!str) return 0;
  switch(str){
  
    case "panel":
      tell_object(TP,BB+"********************"+RW);
      for(tilecol = 0; tilecol < 9; tilecol += 3){
      
        for(x = 1; x < 6 ; x++){
          temp = BB+"*"+BW+ 
                        tiles(tilesplaced[(tilecol + 0)], x) +
                        tiles(tilesplaced[(tilecol + 1)], x) + 
                        tiles(tilesplaced[(tilecol + 2)], x) + 
                        "*";
          tell_object(TP,temp);
        }
      }
      tell_object(TP,BB+"********************"+RW);
      return 1;
    break;


    case "grid":
      tell_object(TP,BB+"*"+BR+"(a)"+BB+"****"+BR+"(b)"+BB+"****"+BR+
      "(c)"+BB+"****"+RW);
      for(tilecol = 0; tilecol < 9; tilecol += 3){
      
        for(x = 1; x < 6 ; x++){
          temp = BB+"*" + 
                        tiles(tilesplaced[(tilecol + 0)], x) +BB+"*" +
                        tiles(tilesplaced[(tilecol + 1)], x) +BB+"*" + 
                        tiles(tilesplaced[(tilecol + 2)], x) +BB+
                        "*"+RW;
          tell_object(TP,temp);
        }
        
        if(tilecol == 0){ tell_object(TP,BB+"*"+BR+"(d)"+
        BB+"****"+BR+"(e)"+BB+"****"+BR+"(f)"+BB+"****"+RW); }
        else if(tilecol == 3){ tell_object(TP,BB+"*"+BR+"(g)"+
        BB+"****"+BR+"(h)"+BB+"****"+BR+"(i)"+BB+"****"+RW); }
        else{ tell_object(TP,BB+"**********************"+RW); }
      }
      tell_object(TP,BW+"You could probably "+BR+"slide letter"+BW+".");
      return 1;
    break;


  }
  return 0;
}

void reset(){
  if(!sizeof(all_living(TO))){
    opened = 0;
    tilesplaced = ({7,3,8,9,5,2,1,4,6});
  }
  ::reset();
}


