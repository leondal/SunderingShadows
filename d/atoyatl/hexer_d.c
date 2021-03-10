#include <std.h>
#include <daemons.h>
#include "/realms/lujke/tecqumin/tecqumin.h"
#include "/realms/lujke/tecqumin/seal_pics.h"
inherit DAEMON;

string * hex_pattern, * seal_pic, * all_pics, *colour_maps, * colour_map, highlight;
int pic_num, hex_height, hex_width;
mapping __hex_positions, __hex_blocks, __hex_x, __hex_y, __colour_blocks;
void create(){
//        1         2         3         4         5         6    
//234567890123456789012345678901234567890123456789012345678901234567890
  hex_pattern = ({
"AAAAAAAABBBBBBBBBBBBBBBBCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDDEEEEEEEEEE"  //01
"AAAAAAAABBBBBBBBBBBBBBBBCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDDEEEEEEEEEE",  //02
"AAAAAAFFFFBBBBBBBBBBBBGGGGCCCCCCCCCCCCHHHHDDDDDDDDDDDDIIIIEEEEEEEE",  //03 
"AAAAFFFFFFFFBBBBBBBBGGGGGGGGCCCCCCCCHHHHHHHHDDDDDDDDIIIIIIIIEEEEEE",  //04
"AAFFFFFFFFFFFFBBBBGGGGGGGGGGGGCCCCHHHHHHHHHHHHDDDDIIIIIIIIIIIIEEEE",  //05
"FFFFFFFFFFFFFFFFGGGGGGGGGGGGGGGGHHHHHHHHHHHHHHHHIIIIIIIIIIIIIIIIEE",  //06
"FFFFFFFFFFFFFFFFGGGGGGGGGGGGGGGGHHHHHHHHHHHHHHHHIIIIIIIIIIIIIIIIEE",  //07
"FFFFFFFFFFFFFFFFGGGGGGGGGGGGGGGGHHHHHHHHHHHHHHHHIIIIIIIIIIIIIIIINN",  //08
"FFFFFFFFFFFFFFFFGGGGGGGGGGGGGGGGHHHHHHHHHHHHHHHHIIIIIIIIIIIIIIIINN",  //09
"JJFFFFFFFFFFFFKKKKGGGGGGGGGGGGLLLLHHHHHHHHHHHHMMMMIIIIIIIIIIIINNNN",  //10
"JJJJFFFFFFFFKKKKKKKKGGGGGGGGLLLLLLLLHHHHHHHHMMMMMMMMIIIIIIIINNNNNN",  //11
"JJJJJJFFFFKKKKKKKKKKKKGGGGLLLLLLLLLLLLHHHHMMMMMMMMMMMMIIIINNNNNNNN",  //12
"JJJJJJJJKKKKKKKKKKKKKKKKLLLLLLLLLLLLLLLLMMMMMMMMMMMMMMMMNNNNNNNNNN",  //13
"JJJJJJJJKKKKKKKKKKKKKKKKLLLLLLLLLLLLLLLLMMMMMMMMMMMMMMMMNNNNNNNNNN",  //14
"JJJJJJJJKKKKKKKKKKKKKKKKLLLLLLLLLLLLLLLLMMMMMMMMMMMMMMMMNNNNNNNNNN",  //15
"JJJJJJJJKKKKKKKKKKKKKKKKLLLLLLLLLLLLLLLLMMMMMMMMMMMMMMMMNNNNNNNNNN",  //16
"JJJJJJOOOOKKKKKKKKKKKKPPPPLLLLLLLLLLLLQQQQMMMMMMMMMMMMRRRRNNNNNNNN",  //17
"JJJJOOOOOOOOKKKKKKKKPPPPPPPPLLLLLLLLQQQQQQQQMMMMMMMMRRRRRRRRNNNNNN",  //18
"JJOOOOOOOOOOOOKKKKPPPPPPPPPPPPLLLLQQQQQQQQQQQQMMMMRRRRRRRRRRRRNNNN",  //19
"OOOOOOOOOOOOOOOOPPPPPPPPPPPPPPPPQQQQQQQQQQQQQQQQRRRRRRRRRRRRRRRRNN",  //20
"OOOOOOOOOOOOOOOOPPPPPPPPPPPPPPPPQQQQQQQQQQQQQQQQRRRRRRRRRRRRRRRRNN",  //21
"OOOOOOOOOOOOOOOOPPPPPPPPPPPPPPPPQQQQQQQQQQQQQQQQRRRRRRRRRRRRRRRRWW",  //22
"OOOOOOOOOOOOOOOOPPPPPPPPPPPPPPPPQQQQQQQQQQQQQQQQRRRRRRRRRRRRRRRRWW",  //23
"SSOOOOOOOOOOOOTTTTPPPPPPPPPPPPUUUUQQQQQQQQQQQQVVVVRRRRRRRRRRRRWWWW",  //24
"SSSSOOOOOOOOTTTTTTTTPPPPPPPPUUUUUUUUQQQQQQQQVVVVVVVVRRRRRRRRWWWWWW",  //25
"SSSSSSOOOOTTTTTTTTTTTTPPPPUUUUUUUUUUUUQQQQVVVVVVVVVVVVRRRRWWWWWWWW",  //26
"SSSSSSSSTTTTTTTTTTTTTTTTUUUUUUUUUUUUUUUUVVVVVVVVVVVVVVVVWWWWWWWWWW",  //27
"SSSSSSSSTTTTTTTTTTTTTTTTUUUUUUUUUUUUUUUUVVVVVVVVVVVVVVVVWWWWWWWWWW",  //28
"SSSSSSSSTTTTTTTTTTTTTTTTUUUUUUUUUUUUUUUUVVVVVVVVVVVVVVVVWWWWWWWWWW",  //29
"SSSSSSSSTTTTTTTTTTTTTTTTUUUUUUUUUUUUUUUUVVVVVVVVVVVVVVVVWWWWWWWWWW",  //30
"SSSSSSXXXXTTTTTTTTTTTTYYYYUUUUUUUUUUUUZZZZVVVVVVVVVVVVaaaaWWWWWWWW",  //31
"SSSSXXXXXXXXTTTTTTTTYYYYYYYYUUUUUUUUZZZZZZZZVVVVVVVVaaaaaaaaWWWWWW",  //32
"SSXXXXXXXXXXXXTTTTYYYYYYYYYYYYUUUUZZZZZZZZZZZZVVVVaaaaaaaaaaaaWWWW",  //33
"XXXXXXXXXXXXXXXXYYYYYYYYYYYYYYYYZZZZZZZZZZZZZZZZaaaaaaaaaaaaaaaaWW",  //34
"XXXXXXXXXXXXXXXXYYYYYYYYYYYYYYYYZZZZZZZZZZZZZZZZaaaaaaaaaaaaaaaaWW",  //35
"XXXXXXXXXXXXXXXXYYYYYYYYYYYYYYYYZZZZZZZZZZZZZZZZaaaaaaaaaaaaaaaaff",  //36
"XXXXXXXXXXXXXXXXYYYYYYYYYYYYYYYYZZZZZZZZZZZZZZZZaaaaaaaaaaaaaaaaff",  //37
"bbXXXXXXXXXXXXccccYYYYYYYYYYYYddddZZZZZZZZZZZZeeeeaaaaaaaaaaaaffff",  //38
"bbbbXXXXXXXXccccccccYYYYYYYYddddddddZZZZZZZZeeeeeeeeaaaaaaaaffffff",  //39
"bbbbbbXXXXccccccccccccYYYYddddddddddddZZZZeeeeeeeeeeeeaaaaffffffff",  //40
"bbbbbbbbccccccccccccccccddddddddddddddddeeeeeeeeeeeeeeeeffffffffff",  //41
"bbbbbbbbccccccccccccccccddddddddddddddddeeeeeeeeeeeeeeeeffffffffff",  //42
"bbbbbbbbccccccccccccccccddddddddddddddddeeeeeeeeeeeeeeeeffffffffff",  //43
"bbbbbbbbccccccccccccccccddddddddddddddddeeeeeeeeeeeeeeeeffffffffff",  //44
"bbbbbbggggcccccccccccchhhhddddddddddddiiiieeeeeeeeeeeejjjjffffffff",  //45
"bbbbggggggggcccccccchhhhhhhhddddddddiiiiiiiieeeeeeeejjjjjjjjffffff",  //46
"bbggggggggggggcccchhhhhhhhhhhhddddiiiiiiiiiiiieeeejjjjjjjjjjjjffff",  //47
"gggggggggggggggghhhhhhhhhhhhhhhhiiiiiiiiiiiiiiiijjjjjjjjjjjjjjjjff",  //48
"gggggggggggggggghhhhhhhhhhhhhhhhiiiiiiiiiiiiiiiijjjjjjjjjjjjjjjjff",  //49
"gggggggggggggggghhhhhhhhhhhhhhhhiiiiiiiiiiiiiiiijjjjjjjjjjjjjjjjoo",  //50
"gggggggggggggggghhhhhhhhhhhhhhhhiiiiiiiiiiiiiiiijjjjjjjjjjjjjjjjoo",  //51
"kkggggggggggggllllhhhhhhhhhhhhmmmmiiiiiiiiiiiinnnnjjjjjjjjjjjjoooo",  //52
"kkkkggggggggllllllllhhhhhhhhmmmmmmmmiiiiiiiinnnnnnnnjjjjjjjjoooooo",  //53
"kkkkkkggggllllllllllllhhhhmmmmmmmmmmmmiiiinnnnnnnnnnnnjjjjoooooooo",  //54
"kkkkkkkkllllllllllllllllmmmmmmmmmmmmmmmmnnnnnnnnnnnnnnnnoooooooooo",  //55
"kkkkkkkkllllllllllllllllmmmmmmmmmmmmmmmmnnnnnnnnnnnnnnnnoooooooooo",  //56
"kkkkkkkkllllllllllllllllmmmmmmmmmmmmmmmmnnnnnnnnnnnnnnnnoooooooooo",  //57 
"kkkkkkkkllllllllllllllllmmmmmmmmmmmmmmmmnnnnnnnnnnnnnnnnoooooooooo",  //58 
"kkkkkkppppllllllllllllqqqqmmmmmmmmmmmmrrrrnnnnnnnnnnnnssssoooooooo",  //59
"kkkkppppppppllllllllqqqqqqqqmmmmmmmmrrrrrrrrnnnnnnnnssssssssoooooo",  //60
"kkppppppppppppllllqqqqqqqqqqqqmmmmrrrrrrrrrrrrnnnnssssssssssssoooo",  //61
"ppppppppppppppppqqqqqqqqqqqqqqqqrrrrrrrrrrrrrrrrssssssssssssssssoo",  //62
"ppppppppppppppppqqqqqqqqqqqqqqqqrrrrrrrrrrrrrrrrssssssssssssssssoo",  //63
"ppppppppppppppppqqqqqqqqqqqqqqqqrrrrrrrrrrrrrrrrssssssssssssssssxx",  //64
"ppppppppppppppppqqqqqqqqqqqqqqqqrrrrrrrrrrrrrrrrssssssssssssssssxx",  //65
"ttppppppppppppuuuuqqqqqqqqqqqqvvvvrrrrrrrrrrrrwwwwssssssssssssxxxx",  //66
"ttttppppppppuuuuuuuuqqqqqqqqvvvvvvvvrrrrrrrrwwwwwwwwssssssssxxxxxx",  //67
"ttttttppppuuuuuuuuuuuuqqqqvvvvvvvvvvvvrrrrwwwwwwwwwwwwssssxxxxxxxx",  //68
"ttttttttuuuuuuuuuuuuuuuuvvvvvvvvvvvvvvvvwwwwwwwwwwwwwwwwxxxxxxxxxx",  //69
"ttttttttuuuuuuuuuuuuuuuuvvvvvvvvvvvvvvvvwwwwwwwwwwwwwwwwxxxxxxxxxx",  //70
"ttttttttuuuuuuuuuuuuuuuuvvvvvvvvvvvvvvvvwwwwwwwwwwwwwwwwxxxxxxxxxx",  //71
"ttttttttuuuuuuuuuuuuuuuuvvvvvvvvvvvvvvvvwwwwwwwwwwwwwwwwxxxxxxxxxx"   //72
  });
  reset_pics();
}

void setup_hex_positions(){
  string * ks;
  int i, count;
  ks = keys(__hex_blocks);
  count = sizeof(ks);
  __hex_positions = ([]);
  for (i=0;i<count;i++){
    __hex_positions[ks[i]] = ks[i];
  }
/*  __hex_positions = ([ "A":"A", "B:"B", "C":"C", "D":"D", "E":"E",
    "F":"F", "G":"G", "H":"H", "I":"I", "J":"J", "K":"K", "L":"L",
    "L":"L", "M":"M", "N":"N", "O":"O", "P":"P", "Q":"Q", "R":"R",
    "S":"S", "T":"T", "U":"U", "V":"V", "W":"W", "X":"X", "Y":"Y",
    "Z":"Z", "a":"a", "b":"b", "c":"c", "d":"d", "e":"e", "f":"f",
    "g":"g", "h":"h", "i":"i", "j":"j", "k":"k", "l":"l", "m":"m",
    "n":"n", "o":"o", "p":"p", "q":"q", "r":"r", "s":"s", "t":"t",
    "u":"u", "v":"v", "w":"w", "x":"x"
  ]);*/  
}

int query_pic_num(){
  return pic_num;
}

string * query_right_hexes(){
  int string_len;
  string * right_hexes;
  right_hexes = ({"E","N", "W", "f", "o", "x"});
  string_len = strlen(seal_pic[0]);
  if (string_len< 64){
    right_hexes = ({"I", "R", "a", "j", "s"});
  }
  if (string_len< 56){
    right_hexes = ({"D", "M", "V", "e", "n", "w"});
  }
  if (string_len<48){
    right_hexes = ({"H", "Q", "Z", "i", "r"});
  }
  if (string_len<40){
    right_hexes = ({"C", "L", "U", "d", "m", "v"});
  }
  if (string_len<32){
    right_hexes = ({"G", "P", "Y", "h", "q"});
  }
  return right_hexes;
}


string * query_bottom_hexes(){
  string * bottom_hexes;
  int lines;
  lines = sizeof(seal_pic);
  if (lines < 68){
    bottom_hexes = ({"p", "q", "r", "s"});
  }
  if (lines <61 ){
    bottom_hexes = ({"k", "l", "m", "n", "o"});
  }
  if (lines < 54){
    bottom_hexes = ({"g", "h", "i", "j"});
  }
  if (lines < 47){
    bottom_hexes= ({"b", "c", "d", "e", "f"});
  }
  if (lines < 40){
    bottom_hexes = ({"X", "Y", "Z", "a"});
  }
  if (lines < 33){
    bottom_hexes = ({"S", "T", "U", "V", "W"});
  }
  return bottom_hexes;
}
void randomise_hexes(){
  string * ks, temp_value,* match_ks, pos_code1, pos_code2, * available_ks, * hex1, *hex2, * left_removals, * right_removals, *top_removals, * bottom_removals, *left_hexes, * right_hexes, *top_hexes, * bottom_hexes, * removals;
  int string_len, lines, i, r,j, count, count2;
  ks = keys(__hex_positions);
  lines = sizeof(seal_pic);
  string_len = strlen(seal_pic[0]);
  right_hexes = ({"E","N", "W", "f", "o", "x"});
  left_hexes = ({"A","J","S", "b", "k", "t"});
  top_hexes = ({"A", "B", "C", "D", "E"});
  bottom_hexes = ({"t", "u", "v", "w", "x"});
  top_removals = right_hexes + left_hexes;  
  bottom_removals = right_hexes + left_hexes;
  right_removals = top_hexes + bottom_hexes;
  left_removals = top_hexes + bottom_hexes;  
  if (string_len< 64){
    right_hexes = ({"I", "R", "a", "j", "s"});
    ks -= right_hexes;
    bottom_removals += right_hexes;
    top_removals += right_hexes;
  }
  if (string_len< 56){
    right_hexes = ({"D", "M", "V", "e", "n", "w"});
    ks -= right_hexes;
    bottom_removals += right_hexes;
    top_removals += right_hexes;
  }
  if (string_len<48){
    right_hexes = ({"H", "Q", "Z", "i", "r"});
    ks -= right_hexes;
    bottom_removals += right_hexes;
    top_removals += right_hexes;
  }
  if (string_len<40){
    right_hexes = ({"C", "L", "U", "d", "m", "v"});
    ks -= right_hexes;
    bottom_removals += right_hexes;
    top_removals += right_hexes;
  }
  if (string_len<32){
    right_hexes = ({"G", "P", "Y", "h", "q"});
    ks -= right_hexes;
  }

  if (lines < 68){
    bottom_hexes = ({"p", "q", "r", "s"});
    ks -= bottom_hexes;
    left_removals += bottom_hexes;
    right_removals += bottom_hexes;
  }
  if (lines <61 ){
    bottom_hexes = ({"k", "l", "m", "n", "o"});
    ks -= bottom_hexes;
    left_removals += bottom_hexes;
    right_removals += bottom_hexes;
  }
  if (lines < 54){
    bottom_hexes = ({"g", "h", "i", "j"});
    ks -= bottom_hexes;
    left_removals += bottom_hexes;
    right_removals += bottom_hexes;
  }
  if (lines < 47){
    bottom_hexes= ({"b", "c", "d", "e", "f"});
    ks -= bottom_hexes;
    left_removals += bottom_hexes;
    right_removals += bottom_hexes;
  }
  if (lines < 40){
    bottom_hexes = ({"X", "Y", "Z", "a"});
    ks -= bottom_hexes;
    left_removals += bottom_hexes;
    right_removals += bottom_hexes;
  }
  if (lines < 33){
    bottom_hexes = ({"S", "T", "U", "V", "W"});
    ks -= bottom_hexes;
    left_removals += bottom_hexes;
    right_removals += bottom_hexes;
  }
  top_hexes -= top_removals;
  bottom_hexes -= bottom_removals;
  right_hexes -= right_removals;
  left_hexes -= left_removals;  
  removals = ({"A","B", "C", "D", "E","J","N","S", "W", "b","f", "k","o", "t", "u", "v", "w", "x"});
  for (i=0;i<sizeof(removals);i++){
    if (member_array(removals[i], ks)!=-1){
      ks -= ({removals[i]});
    }
  }
//  tell_room(find_object_or_load("/realms/lujke/workroom"), "Randomising main positions");
  randomise_hex_positions(ks);
//  tell_room(find_object_or_load("/realms/lujke/workroom"), "Randomising LEFT positions");
  randomise_hex_positions(left_hexes);
//  tell_room(find_object_or_load("/realms/lujke/workroom"), "Randomising RIGHT positions");
  randomise_hex_positions(right_hexes);
//  tell_room(find_object_or_load("/realms/lujke/workroom"), "Randomising TOP positions");
  randomise_hex_positions(top_hexes);
//  tell_room(find_object_or_load("/realms/lujke/workroom"), "Randomising BOTTOM positions");
  randomise_hex_positions(bottom_hexes);
}
void randomise_hex_positions(string * ks){
  string * available_ks, report;
  int i, count, r;
  report = "Randomised hexes:";
  count = sizeof(ks);
  available_ks = ks;
//  tell_room(find_object_or_load("/realms/lujke/workroom"), "Number of positions randomised: " + count);
  for (i=0; i<count;i++){
    report += ks[i] + " ";
    r = random(sizeof(available_ks));
    __hex_positions[ks[i]]=available_ks[r];
    available_ks -= ({available_ks[r]});
  }
//  tell_room(find_object_or_load("/realms/lujke/workroom"), report);
}

mapping query_hex_x(){
  return __hex_x;
}

mapping query_hex_y(){
  return __hex_y;
}

int query_x_position(string hex_code){
  return __hex_x[hex_code];
}

int query_y_position(string hex_code){
  return __hex_y[hex_code];
}

setup_hex_blocks(){
  int x, y, y_count, x_count, flag, hex_x, hex_y;
  string pic_line, colour_line, colour_map_line, * colour_hex, colour_code, letter, hex_line, code_line, index_code, prev_code, * hex, * ks, x_ks, y_ks;
  y_count = sizeof(seal_pic);
  x_count = strlen(seal_pic[0]);
//  tell_room(find_object_or_load("/realms/lujke/workroom"), "Pic num: " + pic_num + " y_count: "+ y_count+ " x_count: " + x_count );
  hex = ({});
  colour_hex = ({});
  __hex_x = ([]);
  __hex_y = ([]);
  __hex_blocks = ([]);
  __colour_blocks= ([]);
  for (y=0;y<y_count;y++){
    pic_line = seal_pic[y];
    colour_map_line = colour_map[y];
    code_line = hex_pattern[y];
    if (objectp(find_object_or_load("/realms/lujke/workroom"))){
//      tell_room(find_object_or_load("/realms/lujke/workroom"), "Code line is: " + code_line);
//      tell_room(find_object_or_load("/realms/lujke/workroom"), "Colour map line is: " + colour_map_line);
    }
    index_code = code_line[0..0];
    y_ks = keys(__hex_y);
    if (sizeof(y_ks) <1 || member_array(index_code, y_ks)==-1){
//      tell_room(find_object_or_load("/realms/lujke/workroom"), "Hex_y" + index_code + " set to "+y+" as a first line action");
      __hex_y[index_code] = y;
    }
    __hex_x[index_code] = 0;
    if (objectp(find_object_or_load("/realms/lujke/workroom"))){
//      tell_room(find_object_or_load("/realms/lujke/workroom"), "Hex_x" + index_code + " set to 0 as a first line action");
    }
    hex_line = "";
    colour_line = "";
    for (x = 0; x<x_count; x++){
      flag = 0;
      index_code = code_line[x..x];
      if (x>0){
        prev_code = code_line[x-1..x-1];
      } else {
        prev_code = "X";
      }
      x_ks = keys(__hex_x);
      y_ks = keys(__hex_y);
      if (sizeof(y_ks)<1 || member_array(index_code, y_ks)==-1 ){
        __hex_y[index_code] = y;
      }
      if (x ==0 ||index_code == prev_code){  //If this is the left of the picture, or if the code is the same as the previous pixel, just add the new pixel
        if (x == 0){
          hex_line += pic_line[x..x];
        } else {
          hex_line += pic_line[x..x];
        }
//        hex_line += pic_line[x..x];
        colour_line+=colour_map_line[x..x];
        x_ks = keys(__hex_x);
        if (sizeof(x_ks)<1 || member_array(index_code, x_ks)==-1 ||x < __hex_x[index_code]){
          __hex_x[index_code] = x;
        }
      } else{ // If this is not the left of the picture, and the code is different from the previous pixel - this means it is a different hex. So, add the hex line to the previous hex block, and start a new hex line
        flag = 1;
        ks = keys(__hex_blocks);
        if (member_array(prev_code, ks)!= -1){ //if there is already a hex for this code. Add the new line to it later
          hex = __hex_blocks[prev_code];
          colour_hex = __colour_blocks[prev_code];
        } else {  // if there is not already a hex for this code, start a new one. Add the new line to it later. 
          hex = ({});
          colour_hex = ({});
          __hex_y[prev_code] = y;
          __hex_x[prev_code] = x - strlen(hex_line);        
        }
        hex += ({hex_line});
        colour_hex += ({colour_line});
        // tell_room(find_object_or_load("/realms/lujke/workroom"), "Hex block " + prev_code + " loaded, because we have reached a new hex. y = " + y );
        __hex_blocks[prev_code] = hex;  
        __colour_blocks[prev_code] = colour_hex;
        // Now start a new hex line and colour line
//        hex_line = pic_line[x..x];
        hex_line = pic_line[x..x];
//        hex_line = "#";
        colour_line = colour_map_line[x..x];
        x_ks = keys(__hex_x);
        if (sizeof(x_ks)<1 || member_array(index_code, x_ks)==-1 ||x < __hex_x[index_code]){
          __hex_x[index_code] = x;
        } 
      } 
    }
//    if (flag ==0){  //If the last hex line has not already been added to __hex_blocks
 
      ks = keys(__hex_blocks);
      if (member_array(index_code, ks)!= -1){
        hex = __hex_blocks[index_code];
        colour_hex = __colour_blocks[index_code];
      } else {
        __hex_y[index_code] = y;
        __hex_x[index_code] = x; 
        hex = ({});
        colour_hex = ({});
      }
      hex += ({hex_line});
      colour_hex += ({colour_line});
      // tell_room(find_object_or_load("/realms/lujke/workroom"), "Hex block " + index_code + " loaded, because we have reached a new line without saving the last hex. y = " + y );
      __hex_blocks[index_code] = hex;
      __colour_blocks[index_code] = colour_hex;
//    }
  }
}

int query_width(string * hex){
  int i, width;
  width = 0;
  for (i = 0;i<sizeof(hex);i++){
    if (strlen(hex[i])>width){
      width = strlen(hex[i]);
    }
  }
  return width;
}

int query_height(string * hex){
  return sizeof(hex);
}

mapping query_hex_blocks(){
  return __hex_blocks;
}

mapping query_colour_blocks(){
  return __colour_blocks;
}

string * query_hex(string index_code){
  return __hex_blocks[index_code];
}

string * query_colour_hex(string index_code){
  return __colour_blocks[index_code];
}

varargs string query_colour_code(string str, int bright){
  string * ks, result;
  mapping cols = ([ "B" : "%^BOLD%^%^BLUE%^", "b" : "%^RESET%^%^BLUE%^",
                        "O" : "%^BOLD%^%^ORANGE%^","o" : "%^RESET%^%^ORANGE%^",
                        "C" : "%^BOLD%^%^CYAN%^",  "c" : "%^RESET%^%^CYAN%^",
                        "D" : "%^BOLD%^%^BLACK%^", "d" : "%^RESET%^%^BLACK%^",
                        "G" : "%^BOLD%^%^GREEN%^", "g" : "%^RESET%^%^GREEN%^",
                        "R" : "%^BOLD%^%^RED%^", "r" : "%^RESET%^%^RED%^",
                        "M" : "%^BOLD%^%^MAGENTA%^", "m" : "%^RESET%^%^MAGENTA%^",
                        "W" : "%^BOLD%^%^WHITE%^", "w" : "%^RESET%^",
                        " " : "",
                        "1" : "%^B_ORANGE%^",
                        "2" : "%^B_CYAN%^",
                        "3" : "%^B_BLACK%^",
                        "4" : "%^B_GREEN%^",
                        "5" : "%^B_RED%^",
                        "6" : "%^B_MAGENTA%^",
                        "7" : "%^B_WHITE%^",
                        "8" : "%^B_BLUE%^",
                        "9" : "%^RESET%^" ]);
  ks = keys(cols);
  if (member_array(str, ks)== -1){
    return "";
  }
  result = cols[str];
  if (bright ==1){
    result +="%^B_RED%^";
  }
  return result; 
} 

varargs string get_adjusted_line(int line_no, int show_hexes){
  string result, index_code, pic_line, code_line, hex_index, * hex, colour_code, pixel, grid_colour;
  int x, count, hex_line, hex_x, hex_y, x_within_hex, y_within_hex, i, * y_ks, hex_midpoint, line_start_x, p;
  if (line_no > sizeof(seal_pic)-1){
    return "Error loading line - line number too big";
  }
  if (line_no > sizeof(hex_pattern)-1){
    return "Error loading line - picture too big";
  }
  pic_line = seal_pic[line_no];
  code_line = hex_pattern[line_no];
  result = "";
  count = strlen(pic_line); 
  for (x = 0;x<count;x++){
    index_code = code_line[x..x];
    hex_index = __hex_positions[index_code];
    hex_y = __hex_y[index_code];
    hex_x = __hex_x[index_code];
    y_within_hex = line_no - hex_y;
    hex = __hex_blocks[hex_index];
    
//    tell_room(find_object_or_load("/realms/lujke/workroom"),"Loading line " + y_within_hex + "of the hex.");
    hex_line = hex[y_within_hex];
    if (hex_x == 0){
      if (query_width(hex)<16){
        x_within_hex = x;
      } else {
        x_within_hex = x - ((query_width(hex)-strlen(hex_line))/2);
      }
    } else {  // The following if statement is true if this line of the hex hits the right edge of the picture before the full width of the hex
      if (hex_x + strlen((hex_line) == strlen(pic_line))&& query_width(hex)<16){ 
        line_start_x = strlen(seal_pic[0])-strlen(hex_line);
        x_within_hex = x - line_start_x;
      } else {
        x_within_hex= x  - hex_x  - (query_width(hex)-strlen(hex_line))/2;
      }
    }
    if (y_within_hex>sizeof(hex)-1){
      colour_code = "Colour code error - line_no: " + line_no + " index code: " + index_code + " y_within_hex: " + y_within_hex;
    } else {
      colour_code = __colour_blocks[hex_index][y_within_hex][x_within_hex..x_within_hex];
    }
    if (x_within_hex>strlen(hex_line)-1){
      if (strlen(hex_line)<1){
        pixel = "@";
      } else {
        p = strlen(hex_line)-1;
        pixel = hex_line[p..p];// index_code + x_within_hex + " " + y_within_hex;
      }
    } else {
      pixel = hex_line[x_within_hex..x_within_hex];
    }
    if (show_hexes == 1){
      switch(index_code){
        
      case "F":
      case "H":
      case "O":
      case "Q":
      case "X":
      case "Z":
      case "g":
      case "i":
      case "p":
      case "r":
        grid_colour = "%^BOLD%^%^BLACK%^";
        break;

      case "A":
      case "C":
      case "E":
      case "J":
      case "L":
      case "N":
      case "S":
      case "U":
      case "W":
      case "b":
      case "d":  
      case "f":
      case "k":
      case "m":
      case "o":
      case "t":
      case "v":
      case "x":
        grid_colour = "%^BOLD%^%^WHITE%^";
        break;

      case "G":
      case "I":
      case "P":
      case "R":
      case "Y":
      case "a":
      case "h":
      case "j":
      case "q":
      case "s":
        grid_colour = "%^ORANGE%^";
        break;

      case "B":
      case "D":
      case "K":
      case "M":
      case "T":
      case "V":
      case "c":
      case "e":
      case "l":
      case "n":
      case "u":
      case "w":
        grid_colour = "%^CYAN%^";
        break;


/*    case "A":
      case "G":
      case "M":
      case "S":
      case "X":
      case "d":
      case "j":
      case "p":
      case "v":
        grid_colour = "%^BOLD%^%^RED%^";
        break;
      case "B":
      case "H":
      case "N":
      case "T":
      case "Y":
      case "e":
      case "k":
      case "q":
      case "w":
        grid_colour = "%^BOLD%^%^GREEN%^";
        break;
      case "C":
      case "I":
      case "O":
      case "U":
      case "Z":
      case "f":
      case "l":
      case "r":
      case "x":
        grid_colour = "%^BOLD%^%^WHITE%^";
        break;
      case "D":
      case "J":
      case "P":
      case "V":
      case "a":
      case "g":
      case "m":
      case "s":
      case "y":
        grid_colour = "%^BOLD%^%^RED%^";
        break;
      case "E":
      case "K":
      case "Q":
      case "W":
      case "b":
      case "h":
      case "n":
      case "t":
      case "z":
        grid_colour = "%^BOLD%^%^YELLOW%^";
        break;
      case "F":
      case "L":
      case "R":
      case "X":
      case "c":
      case "i":
      case "o":
      case "u":
       grid_colour = "%^BOLD%^%^MAGENTA%^";
        break; */
      
      }
//      tell_room(find_object_or_load("/realms/lujke/workroom"), "Showing this hex");
      if (y_within_hex==0 ||y_within_hex==sizeof(hex)-1){
        pixel = "%^RESET%^"+ grid_colour + index_code + "%^RESET%^";
      }
      if (x_within_hex == 0 ||x_within_hex == strlen(hex_line)-1){
        pixel = "%^RESET%^"+ grid_colour+ index_code + "%^RESET%^";
      }
    }


    if (index_code == highlight){
      result += query_colour_code(colour_code, 1);
    } else {
      result += query_colour_code(colour_code);
    }

    result += pixel;
//    tell_object(TP, result);
  }
  if (strlen(result)<strlen(seal_pic[0])){
//  result += "line no: " + line_no;
  }
  if (count<strlen(seal_pic[0])){
//  result += " The pic line was too short to start with!";
  }
  return result;
}

int compare_hex_shapes( string * hex1, string *hex2){  //returns 1 if they are the same shape, otherwise returns -1
  int i, count;
  count = sizeof(hex1);
  if (sizeof(hex2)!=count){
    return -1;
  }
  for (i=0;i<count;i++){
    if (strlen(hex1[i])!=strlen(hex2[i])){
      return -1;
    }
  }
  return 1;
}

void simple_show_pic(object ob){
  int i, count;
  if (!objectp(ob)){
    return;
  }
  count = sizeof(seal_pic);
  for (i=0;i<count;i++){
    tell_object(ob, seal_pic[i]);
  }
}

varargs void show_pic(object ob, show_hexes){
  int i, count;
  if (!objectp(ob)){
    return;
  }
  count = sizeof(seal_pic);
  for (i=0;i<count;i++){
    tell_object(ob, get_adjusted_line(i, show_hexes));
  }
}

void highlight_hex(string hex_code){
  highlight = hex_code;
}

void swap_hexes(string hex1, string hex2){
  string temp_pos;
  temp_pos = __hex_positions[hex1];
  __hex_positions[hex1] = __hex_positions[hex2];
  __hex_positions[hex2] = temp_pos;
}

int is_a_hex(string hex_code){
  string * ks;
  ks = keys(__hex_positions);
  if (member_array(hex_code, ks)==-1){
    return -1;
  } else {
    return 1;
  }
}

int is_moveable_hex(string hex_code){
  string * ks;
  ks = keys(__hex_positions);
  if (member_array(hex_code, ks)==-1){
    return 1;
  } else {
    return -1;
  }
}

string query_highlight(){
  return highlight;
}

void set_pic(int num){
  pic_num = num;
  seal_pic = all_pics[pic_num];
  colour_map = colour_maps[pic_num];
  setup_hex_blocks();
}

mapping query_hex_positions(){
  return __hex_positions;
}

int can_swap(string hex_code1, hex_code2){
  string * hex1, * hex2, adj_code1, adj_code2, * ks, * left_side;
  ks = keys(__hex_positions);
  left_side = ({"A", "J", "S", "b", "k", "t"});
  if (member_array(hex_code1, left_side)!= -1 && member_array(hex_code2, left_side)== -1){
    return -1;
  } 
  if (member_array(hex_code2, left_side)!= -1 && member_array(hex_code1, left_side)== -1){
    return -1;
  } 
  if (member_array(hex_code1, ks)==-1 || member_array(hex_code2, ks)==-1){
    return -1;
  }
  adj_code1 = __hex_positions[hex_code1];
  adj_code2 = __hex_positions[hex_code2];
  ks = keys(__hex_blocks);
  if (member_array(adj_code1, ks)==-1 || member_array(adj_code2, ks)==-1){
    return -1;
  }
  hex1 = __hex_blocks[adj_code1];
  hex2 = __hex_blocks[adj_code2];
  if (compare_hex_shapes(hex1, hex2)==-1){
    return -1;
  }
  return 1;
}

void set_new_pic(){
  int r, pn;
  pn = pic_num;
  reset_pics();
  pic_num = pn;
  r = random(sizeof(all_pics));
  if (r==pic_num){
    r ++;
    if (r > sizeof(all_pics)-1){
      r = 0;
    }
  }
  pic_num = r;
  
  seal_pic = all_pics[pic_num];
  colour_map = colour_maps[pic_num];
  highlight = "none";
  setup_hex_blocks();
  setup_hex_positions();
  randomise_hexes();
}


int check_completed(){
  string * ks, index_code, * hex1, * hex2;
  int i, count;
  ks = keys(__hex_blocks);
  count = sizeof(ks);
  for (i=0;i<count;i++){
    index_code = __hex_positions[ks[i]];
    hex1 = __hex_blocks[ks[i]];
    hex2 = __hex_blocks[index_code];
//    tell_object(find_player("lujke"), "Comparing block " + ks[i] + " with block " + index_code); 
    if (arrays_equal(hex1, hex2)==0){
      return -1;
    }
  }
  return 1;
}

void set_helm_pic(){
  all_pics = ({ 
({
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@ /#&&@@@@@@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@(@@%(,*%&@, %@*@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@%@@@%,,/%@@/ /@@%@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@*@@@&( ,/(@@# *#@@ /,@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@% (#/  ,,,*., *(@@%,&@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@*@@@@/, **&@&/    @%.#/@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@&(/@@@ ((#/ . */%(., //@/  /*@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@#(..,@*@@(*#/,,/. ,&( ////. .*@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@%**% &..(%(/(* ,##@@#.. ,(.*  /@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@#/*/%  @,//%( ,, &.#.,*,/.%(* .,.@@@@@@@@@@@@@",
"@@@@@@@@@@@.,,/*((*   %// .%#.(..&,% @@/.*/ ,*(@@@@@@@@@@@@@",
"@@@@@@@@@@.#(,*/(%   .(%//(, .(**(/(.#** /,% @@@@@@@@@@@@@@@",
"@@@@@@@@@**.,*/   , ,.  ..  ... ., ,%#,* (*&. @@@@@@@@@@@@@@",
"@@@@@@@@@@#***,     .,,,*,*(##@&&##/,.*,   ..@@@@@@@@@@@@@@@",
"@@@@@@@@@&*....,(/ ,.*/*/%&@@@@@&@%(#(//(//**##@@@@@@@@@@@@@",
"@@@@@@@@@#/,.,,,.  ,*(((%@@@@&@@&&%(#/ (# .(/(/ @@@@@@@@@@@@",
"@@@@@@@@@//**,.  */#.#%@@/,.##/#/#(, #(#,#(((*@@@@@@@@@@@@@@",
"@@@@@@@@@,#///,*, *//#,(##(@&*###,@.%(*  #/(##((@@@@@@@@@@@@",
"@@@@@@@@@*#(///,. */%(&../,@@,(#%@@@*#%.//(/##(((@@@@@@@@@@@",
"@@@@@@@@@@#/** ( */((/ @@@@ #%&%%%( ###((((##%%/%@@@@@@@@@@@",
"@@@@@@@@@@,/,**,.*/#(/*@@ ,.@&@@&%%(/(%((((####%@@@@@@@@@@@@",
"@@@@@@@@@@@ (,*.*((/##,(....@#&%%(//###((((/(/(*@@@@@@@@@@@@",
"@@@@@@@@@@@#*#, *#(#%#&@@@@%,. *,*((((#(#((#(((@@@@@@@@@@@@@",
"@@@@@@@@@@@/*.  ,,*////**,..,/%%(*.,(//(####(#@@@@@@@@@@@@@@",
"@@@@@@@@@@@@#.@@ ,,... .***##%@@(,( .,//(%###&@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@ (//.        @##@   ,..,#*/(*@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@%   .,, ((/.,&@@// ,*  * ,/(@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@ ,**,. ,((*..@&%%@ .,* , /./@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@ ,/(*.,,*/(*,&@@@@@#.*//   .#@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@.*//*..,*(#(* %@@@@@& *(((,*#&@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@(*((/* **(#(*.(@@@@@@& ,/(/ .#%@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@%*/((*.,,*((/,*&&@@@@@@..*(##./#@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@.,//(**,**/(#(,.%&@@@@@@,.*(##(,(/@@@@@@@@@@@@@@@",
"@@@@@@@@@%,,*(//*,***(#(/,.%@@@@@@@/.*(#%# (&@@@@@@@@@@@@@@@",
"@@@@@@@*((&@.,,, ,,,//##/,/&@@@@@@@&.,(%%%/*%*@@@@@@@@@@@@@@",
"@@@@@@@/((#@@@. .,*//#((( #&&@@@@&@@ ,/#%%# (@@@@@@@@@@@@@@@",
"@@@@@@ *,(*,*&/%@ ,,/////,(##@@@@&@@ *(#%%%**%,@@@@@@@@@@@@@",
"@@@@@@.(.,,/.**#%%@@ ,*,,//#%&%@@@&@/,*(#%&%,* &@@@@@@@@@@@@",
"@@@@@@@@@./ ..**##(%..*  **(((%%%%@@@,//(#/( ,@@./@@@@@@@@@@",
"@@@@@@@@@@@@&,/ ,*, *//@@% /*(#(%%#@@,**(*/(@@&&%#@@@@@@@@@@",
"@@@@@@@@@@@@@@@@.*.,,/(&&@@@/*/##((#/ *, @@@,&(//,(,@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@.* ,/#%%&@@@,/#//. @@@&&(. ,* ((@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@//,./#,@@/@@%@@@@@%&%&%#(.(*@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@&/ ***.,(#&&/ /# (//( (,@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@,./(###(%#/**/( (((@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@%.,*//**, /(.@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@*&@@@@@%*@@@@@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",

}) });
  colour_maps = 
({ ({
"3W@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
"3W@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
"3W@@@@@@@@@@@@@@@@@@@@@@@@93&@@ /#&&W@@@@@@@@@@@@@@@@@@@@@@@",
"3W@@@@@@@@@@@@@@@@@@@@@@@93@@%(,*%&@, %@*W@@@@@@@@@@@@@@@@@@",
"3W@@@@@@@@@@@@@@@@@@@@@@93@@@%,,/%@@/ /@@%W@@@@@@@@@@@@@@@@@",
"3W@@@@@@@@@@@@@@@@@@@@@93@@@&( ,/(@@# *#@@ /,W@@@@@@@@@@@@@@",
"3W@@@@@@@@@@@@@@@@@@@@@93 (#/  ,,,*., *(@@%,&W@@@@@@@@@@@@@@",
"3W@@@@@@@@@@@@@@@@@@@@93@@@@/, **&@&/    @%.#/W@@@@@@@@@@@@@",
"3W@@@@@@@@@@@@@@933/W@93((#/ . */%(., //@/  /*W@@@@@@@@@@@@@",
"3W@@@@@@@@@@@@@933..,@*@@(*#/,,/. ,&( ////. .*W@@@@@@@@@@@@@",
"3W@@@@@@@@@@@@933*% &..(%(/(* ,##@@#.. ,(.*  /W@@@@@@@@@@@@@",
"3W@@@@@@@@@@@93/*/%  @,//%( ,, &.#.,*,/.%(* .,.W@@@@@@@@@@@@",
"3W@@@@@@@@93,,/*((*   %// .%#.(..&,% @@/.*/ ,*(W@@@@@@@@@@@@",
"3W@@@@@@@93#(,*/(%   .(%//(, .    /(.#** /,% W@@@@@@@@@@@@@@",
"3W@@@@@@93*.,*/   , ,.  ..  ... ., ,%#,* (*&. W@@@@@@@@@@@@@",
"3W@@@@@@@93***,     .,,,*,*(##@&&##/,.*,   ..W@@@@@@@@@@@@@@",
"3W@@@@@@93*....,(/ ,.*/*/%&@@@@@&@%(#(//(//**##W@@@@@@@@@@@@",
"3W@@@@@@93/,.,,,.  ,*(((%cccccccccccccc93 .(/(/ W@@@@@@@@@@@",
"3W@@@@@@93/**,.  */#.#%cccWWWWBBBWWWW#cc93(((*W@@@@@@@@@@@@@",
"3W@@@@@@93#///,*, *//#,(cccccWWWWWccccc93#/(##((W@@@@@@@@@@@",
"3W@@@@@@93#(///,. */%(&../,ccccccccc93%.//(/##(((W@@@@@@@@@@",
"3W@@@@@@@93/** ( */((/ @@@@ #%&%%%( ###((((##%%/%W@@@@@@@@@@",
"3W@@@@@@@93/,**,.*/#(/*@@ ,.@&@@&%%(/(%((((####%W@@@@@@@@@@@",
"3W@@@@@@@@93(,*.*((/##,(....@#&%%(//###((((/(/(*W@@@@@@@@@@@",
"3W@@@@@@@@93*#, *#(#%#&@@@@%,. *,*((((#(#((#(((W@@@@@@@@@@@@",
"3W@@@@@@@@93*.  ,,*////**,..,/%%(*.,(//(####(#W@@@@@@@@@@@@@",
"3W@@@@@@@@@93.W93,,... .c3*##%C@c,(93,//(%###&W@@@@@@@@@@@@@",
"3W@@@@@@@@@@@@@c3(//.        CB.Cc3 ,..,#*/(*W@@@@@@@@@@@@@@",
"3W@@@@@@@@@@@@@93   .,, ((/DW C.W/ D*  * ,/(W@@@@@@@@@@@@@@@",
"3W@@@@@@@@@@@@@93   D,, 93/D WWWWW DD93* D93W@@@@@@@@@@@@@@@",
"3W@@@@@@@@@@@@@93,**D. ,93*DDWWWWW DD93, D93W@@@@@@@@@@@@@@@",
"3W@@@@@@@@@@@@93,/(*D,,93(DDWWWWWWWDD93  D93W@@@@@@@@@@@@@@@",
"3W@@@@@@@@@@@93*//*D.,93#(DDWWWWWWWDD93(,D93W@@@@@@@@@@@@@@@",
"3W@@@@@@@@@@93*((/*D**93(DDWWWWWWWWDD93/ D93W@@@@@@@@@@@@@@@",
"3W@@@@@@@@@@93/((*D,,*93/DDWWWWWWWWDDD93#D93W@@@@@@@@@@@@@@@",
"3W@@@@@@@@93,//(**D**93#(DDWWWWWWWWDDD93#D93/W@@@@@@@@@@@@@@",
"3W@@@@@@@c333(//*D***93(/DDWWWWWWWWDDD93%#D93W@@@@@@@@@@@@@@",
"3W@@@@93WWWWc333333393##/DDWWWWWWWWWDD93%%D93*W@@@@@@@@@@@@@",
"3W@@@@93WWWWWWc3333393((DDWWWWWWWWWWDD93%%#D93W@@@@@@@@@@@@@",
"3W@@@93*,(*WWWWWWc333333DDWWWWWWWWWWDD93%%%Dc3,W@@@@@@@@@@@@",
"3W@@@@@@93/ ..**WWWWWWc3333WWWWWWWWWWDDD93Dc3WWWWWW@@@@@@@@@",
"3W@@@@@@@@@93,/ ,*, WWWWWWc33WWWWWWWWDDDc3/WWWWWW#W@@@@@@@@@",
"3W@@@@@@@@@@@@@93*.,,/WWWWWWc33WWWWWWDc33WWWWWWWW93,W@@@@@@@",
"3W@@@@@@@@@@@@@@@@93* ,/WWWWWWc3333333WWWWWWWW93 ((W@@@@@@@@",
"3W@@@@@@@@@@@@@@@@@@93/,./WWWWWWW%@@@@@%&%&%#93(*W@@@@@@@@@@",
"3W@@@@@@@@@@@@@@@@@@@@93/ ***WWWWWWWWWWWWW93 (,W@@@@@@@@@@@@",
"3W@@@@@@@@@@@@@@@@@@@@@@@93./(WWWWWWWWW93 (((W@@@@@@@@@@@@@@",
"3W@@@@@@@@@@@@@@@@@@@@@@@@@93.,*//**, /(.W@@@@@@@@@@@@@@@@@@",
"3W@@@@@@@@@@@@@@@@@@@@@@@@@93&@@@@@%*W@@@@@@@@@@@@@@@@@@@@@@",
"3W@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
}) });
  seal_pic = all_pics[0];
  colour_map = colour_maps[0];
  pic_num = 0;
  setup_hex_blocks();
  setup_hex_positions();
}

void reset_pics(){
  all_pics = ({ PICS1, 
                PICS2,
                PICS3,
                PICS4,
                PICS5,
                PICS6
});



  colour_maps = ({
({//      1         2         3         4         5         6
//234567890123456789012345678901234567890123456789012345678901234
"8888888888888888888888888888888888888888888888888888888888888888", //1
"888888888888888888888888888888888888G8888888888o8888888888888888", //2
"88888888888888888888888G8,8#og8.8G88oG88o88G#g8GGGo8888888888888", //3
"8888888888888888888888GG%@&g8G8og8G8o8G%8G//8G g8Go8888888888888", //4
"8888GGGGGo8G8888888888G(g8GGg88og8G%#og8%%8#%*8og88GGGG888888888", //5
"g8Go88GGGGGog8Gg88g8#o8og8G&%%og8Gog8%GGGG888og8GG8GGGG888888888", //6
"88GG88G888G88og888G%%g8%%Gg80g8GGGogog8Ggog8G%#8%g8.888888888888", //7
"88888G88Gg8888G888og8*#G%%%%g8G#%%og8G%%og8GogG##g8#G#..88888888", //8
"88888888Gog8oggGggGgg%%G%gGgggGgGgoGgG&%ggG#&@@gggGG8oG888888888", //9
"888888888ogG8#oggoggGg&ggG&G#Ggg#Gg%#gg@&&G@gGggg%%##og8##g88G88", //10
"88Gog8##GogogG%ggG%&%%og#%ggGgggoggG%ggGggGgggG%%&og8G%@88%%g8G.", //11
"gg&&G#%gg#%#&%&ogG%%ggG%0gooooG%%#%%GoooG##(&@&%#%%%&%%%%(##(%/8", //12
"g88.##ogG%#oggG&%&oggG#% GGGGGgg%&G3GGGGgg##G%%oGg#oGg/#g8G#%#(#", //13
"8G.o888ogG*,ogg%G#(oggG%,%&ooo%#ogGggoooog%G%%%g&&G%g&oGo8888G##", //14
"88888888o8 G#%ggG%&%%%oGg%g&&G%%%%gG%&g##G&&%%gG%%gg.,G&8.og8888", //15
"888888888og8G.oggGogg%oggG&&%oggG#%goGg&oGg&%%%ogg##G,8#og8og888", //16
"88888888G,8ogggG&%ggG&&&&&&oggG#&(#&&&&&&oggG%#oggG%##%*#og88888", //17
"88888888888G&@%%*88oggg&%%G&&%%%%%ggG&&&%*88.*%gg,oGggg#%&G8##88", //18
"88888888og8%##88888&&&#88g@ogG@gG&%gogG#88G8888ggo8G8og,,G8#.888", //19
"88888888G8%og888888888888Gg8ggg&%G&**ogG(*.8#88ggog8G888o8888888", //20
"888888888888G%ggo88888888oGg&%gGgGGgggGGo/g88888og8G.88G.g8.8888", //21
"8888888888888G%#o8888888gg#%G&&%&%%%gGgg#ogg888ggogo888888888888", //22
"8888888888ggogG88G888ggG%%ogG&&%%gg&&GoG&gG888888G%o8Go888888888", //23
"8888888888888G88888o8oGg&%&Go&&&%%%(go((((88888(8g88888888888888", //24
"88888888888888oGoogo%&&.8 o&&%ggo%Go&%#o8o&%%#G88gG8888888888888", //25
"88888888888888o%go&&8888888o&%&%&%%%888888o%##%G8888888888888888", //26
"8888888888888o#%%&888888888o%&%%%%%%%&88888888o%#g88888888888888", //27
"888888888888ogo&&8888888888o%&%go%%%&%&.8888888o%%(,888888888888", //28
"888888888888o&%&88888888888o%%%%&%%&&&*(88888888o&%g888888888888", //29
"8888888888og#o88888888888o@%Go&&&&&%g#88888888o&&&%&888888888888", //30
"888888888o#%#%%8888888888o%%&%%%&%&&&&.88888888o%%g#888888888888", //31
"88888888o#%&8&&8888888888o&%%g%%o%go%&&&888888888o&%&&(888888888", //32
"888888888ogo8go888888888o&&%%&%.&&&&%&&&888888888o%8&&8888888888", //33
"888888888o%&%go88888888o%&&&%%8888o&%&&88888888o%#88888888888888", //34
"8888888888888888888888o&&go&&%8888o&&&&&%%8888888o#*888888888888", //35
"88888888888888888888o@&&&&&&&88888o&&&@&&&&888888888888888888888", //36
"44444444444444444o&ooooogo&&&44444o%ogo&%&&&&%*44444444444444444", //37
"444444444444444444o&ooooooo&%&%44o&&&&&&&ogo&.444444444444444444", //38
"4444444444444444o4o&44o4o4o4o&%%4o&&44o&&&44o&&44444444444444444", //39
"444444444444444o4o4444o4%4&o4o&44o&44o&4&&&444o&4444444444444444", //40
"44444444444444o&44444o&&4o4o&%%4o&&44o&&444o&&44o&&4444444444444",
"444444444444o&44444o&&4444o44o444o444o44o&4444o4.44o444444444444",
"444444444444444444444o44444444o4444444444o444444o444444444444444",
"                                                                "
}),
({
"888888888888888888888888888888888g888888888888888888888888888888",
"88888888888888888888888888888888OR888888888888888888888888888888",
"8888888888888888888888888888888ORO888888888888888888888888888888",
"888888888888888888888888888888OOO8888888888888888888888888888888",
"8888888888888888888888o888888OOOO8888888888888888888888888888888",
"888888888888OOO8888888O888888OOO888888OO888888888888O88888888888",
"8888888888888OOR888888OO88888rOOO8888Or88888888OOOOO888888888888",
"88888888888888OOO888888OrO888OOO88OrO8888OOrOrOO8888888888888888",
"88888888888888OOO888888OrOO8OOOOR8ROO88OOOOr88888888888888888888",
"888888888888888rOOROOOOOO88OOOOoOOr8OOO88OOrr8888888888888888888",
"888888888888888888Oo8OrORROOo8OoOOoRo8oROROo88888OrO888888888888",
"88888888888Oo888888Ro8o8OOOOo8ORRRr8OROo8OOO88OOo888888888888888",
"8888888888888OOOOOOOOOOOROORo8r8Or8OOOOOr8R8Or888888888888888888",
"88888888888888888888o8OROR555RrrRRr8555ROOR888888888888888888888",
"888ROOo8O888888Oo8OROROROo858RORRr8r858O8oO8OORo88O8o8R888888888",
"888r88OOo8OOROOOORo8OOOOOOOR8555558Or8OOOOOOOOORROoO8OrOoO88R888",
"888888888ORoO8ORR88OOOo8OOo8OOO558OoO8ROOOOo8O888888888OOo888888",
"88888888888888888ROOORROOOr8Ro8ORRROOROOO8o8rOoR8888888888888888",
"8888888888888888OrO8oO8OOOORr88OOROOOOOOOOR888Or8888888888888888",
"88888888888888OOO88Ro8ORoOOOOOORORo8ROORo88888888888888888888888",
"8888888888888888888OOOOo8RROOOORo88OOOoROOrRO8888888888888888888",
"888888888888888888OOOO88r8O8OOOOO8OORO888ROOr8o88888888888888888",
"8888888888888888r8OOO8888Or88OOo8R88ROOO88888ROOO888888888888888",
"888888888888r8OOOOR888888o8888Rr8OO8888RO88888r8o888888888888888",
"88888888888OO88888888888Oo88888r8OO88888O888888OORR8888888888888",
"8888888888O888888888888OO888888ORoO88888O888888888RO888888888888",
"888888888888888888888888888888OOOR88888888888888888O888888888888",
"88888888888888888888888888888OOR88888888888888888888888888888888",
"88888888888888888888888888888o8888888888888888888888888888888888",
"888888888888888888888888888888OO88888888888888888888888888888888"}),
({
"BB333333BB33B33333333333BB33B33333333333BB33B333",// 1
"BB33B333BB33B33333333333BB33B33333333333BB33B333",// 2
"BB33BB33BB33BB33333333BB33BB3333333333BB33BB3333",// 3
"BB33BB333333BB333333BB333333BB333333BB333333BB33",// 4
"BB33B333333333BB33BB3333333333BB33BB3333333333B3",// 5
"BB33333333333333BB33333333333333BB33333333333333",// 6
"BB33333333333333BB33333333333333BB33333333333333",// 7
"BB33333333333333BB33333333333333BB33333333333333",// 8
"BB33333333333333BB33333333333333BB33333333333333",// 9
"BB33B333333333BB33BB3333333333BB33BB33333333333B",// 10
"BB33BB333333BB333333BB333333BB333333BB3333333B3B",// 11
"BB3333BB33BB3333333333BB33BB3333333333BB333BB333",// 12
"BB333333BB33333333333333BB33333333333333BB333333",// 13
"BB333333BB33333333333333BB33333333333333BB333333",// 14
"BB333333BB33333333333333BB33333333333333BB333333",// 15
"BB333333BB33333333333333BB33333333333333BB333333",// 16
"BB3333BB33BB3333333333BB33BB3333333333BB33BB3333",// 17
"BB33BB333333BB333333BB333333BB333333BB333333BB33",// 18
"BB33B333333333BB33BB3333333333BB333BB333333333B3",// 19
"BB33333333333333BB33333333333333BB33333333333333",// 20
"BB33333333333333BB33333333333333BB33333333333333",// 21
"BB33333333333333BB33333333333333BB33333333333333",// 22
"BB33333333333333BB33333333333333BB33333333333333",// 23
"BB33B333333333BB33BB3333333333BB33BB3333333333B3",// 24
"BB33BB333333BB333333BB333333BB333333BB333333BB33",// 25
"BB3333BB33BB3333333333BB33BB3333333333BB33BB3333",// 26
"BB333333BB33333333333333BB33333333333333BB333333",// 27
"BB333333BB33333333333333BB33333333333333BB333333",// 28
"BB333333BB33333333333333BB33333333333333BB333333",// 29
"BB333333BB33333333333333BB33333333333333BB333333",// 30
"BB3333BB33BB3333333333BB33BB3333333333BB33BB3333",// 31
"BB33BB333333BB333333BB333333BB333333BB333333BB33",// 32
"BB33B333333333BB33BB3333333333BB33BB3333333333B3",// 33STUVW
"BB33333333333333BB33333333333333BB33333333333333",// 34
"BB33333333333333BB33333333333333BB33333333333333",// 35
"BB33333333333333BB33333333333333BB33333333333333",// 36
"BB33333333333333BB33333333333333BB33333333333333",// 37
"BB33B333333333BB33BB3333333333BB33BB3333BB3333B3",// 38
"BB33BB333333BB333333BB333333BB333333BB333333BB33",// 39
"BB3333BB33BB3333333333BB33BB3333333333BOB3BB3333",// 40XYZa
"BB333333BB33333333333333BB33333333333333BB33B3B3",// 41
"BB333333BB33333333333333BB33333333333333BB33WWB3",// 42
"BB333333BB33333333333333BB33333333333333BB33BWB3",// 43
"BB333333BB33333333333333BB33333333333333BB33B3BB",// 44
"BB3333BB33BB3333333333BB33BB3333333333BB33B3WWB3",// 45
"BB33BB333333BB333333BB333333BB333333BB33333BWBB3",// 46
"BB33B333333333BB33BB3333333333BB33BB33333333BBB3",// 47bcdef
"BB33333333333333BB33333333333333BB33333333333333",// 48
"BB33333333333333BB33333333333333BB33333333333333",// 49
"BB33333333333333BB33333333333333BB33333333333333",// 50
"BB33333333333333BB33333333333333BB33333333333333",// 51
"BB33B333333333BB33BB3333333333BB33BB3333333333B3",// 52
"BB33BB333333BB333333BB333333BB333333BB333333BB33",// 53
"BB3333BB33BB3333333333BB33BB3333333333BB33BB3333",// 54ghij
"BB333333BB33333333333333BB33333333333333BB333333",// 55
"BB333333BB33333333333333BB33333333333333BB333333",// 56
"BB333333BB33333333333333BB33333333333333BB333333",// 57
"BB333333BB33333333333333BB33333333333333BB333333",// 58
"BB3333BB33BB3333333333BB33BB3333333333BB33BB3333",// 59
"BB33BB333333BB333333BB333333BB333333BB333333BB33",// 60
"BB33B333333333BB33BB3333333333BB33BB3333333333B3",//  61klmno
"BB33333333333333BB33333333333333BB33333333333333",// 62
"BB33333333333333BB33333333333333BB33333333333333",// 63
"BB33333333333333BB33333333333333BB33333333333333",// 64
"BB33333333333333BB33333333333333BB33333333333333"// 65
}), 

({

"33333333333333333333333WW33W33WW3WW33333333333333333333333333333",
"33333333333333333333333WWWWWW3WWWWW3333WWW3333333333333333333333",
"3333333333333333333WWW333W3WW3W33W33WWWWW33333333333333333333333",
"3333333333333333WWW3.WW33GGGGGGGG33WWWWW3333WWWWWWW3333333333333",
"333333333333333333WW3WW3GGGGGGGGGGgg3333*WWWWWWWW333333333333333",
"3333333333333333rrrrrrrrrr3GGGGGgggGGGGGGggGG3333333333333333333",
"333333333333333rrrrrrrrrrrGGGGggGGGGGGgGggGGG3333333333333333333",
"33333333333333rrr3BBBB3rrr.GGGGGggGGGGggGGGGGGGGWWWWWW3333333333",
"3333333333333rrrrrrrrrrrrrrr33W3333W3GGGggGGgGGGGWWWWWWWWW333333",
"333333333333rrrrRrrrrrrrrrrr33WWW3333333W3GdGGGGGgW3333333333333",
"3333333333333rrRrrrr333rrrr333WWWW333333333GGGGg3333333333333333",
"33333333333333R33rr3333333333333WWW33333333GGgggGG&WWWWW33333333",
"3333333333333333333333333333333333W3333333ggGGGgggG33WWWWW333333",
"33333333333333333333333333333333333333333GGGG3GGGgg333WWWWWW3333",
"33333333333333333333333GgggGGGGGggGGGggGGGGGGgGG3333333333333333",
"3333333333333333333333GGgGgggGGGGGGGGGgggGGgggGgWWW3333333333333",
"333333333333333333GgGGGgGgGGggGGgGGGGgGggGGGGGg33WWW333333333333",
"3333333333WW3333gGGGGGGGGggGGg3GgGg3GggGgG3333333WWWW33333333333",
"3333333333WWW333GGGggGgGG33333333GGGg3333333333333WWWW3333333333",
"3333333333WW3333GGggGgg333333GGgGggggG3Ggg333333333WWW3333333333",
"3333WW3333WWGGGGgggGGGg33333GGGGGGGgGGGgGGG333333333333333333333",
"3333WWW3GGGgGGGGGGGGGGG333@&@%3*33333GggGG33GGWW3333333333333333",
"333333WgggGGG333G333WWWGggGGGgg33333333GGGgGGg3WWWW3333333333333",
"3WWW333GGG3333333WWWWWWGggggGg333333333GGgggGg333WW3333333333333",
"33WWWWWGGGG3333333WWWWWg3GGgg3333333333ggGGgg3333333333333333333",
"333333333GGG3333333WWW3gggGGg3GGggGGggGgGGGG@WWW3333333333333333",
"3333333WWGGggGGGgGGG.3ggGgGgGgGGGggGgGgGGgGG33WWW333333333333333",
"3333WWWW3GgGGGGggGGGGGg33Ggg3GGggGggGGggG333333WW333333333333333",
"333333W33333GGGG3333WWW3gggg.3GGGggGGGgg3W3333333333333333333333",
"333333333333WWWW3333WWW3Ggggg33333333333WWW333333333333333333333",
"33333333333WWW33333333333GggGg3333WWW333W33333333333333333333333",
"33333333333333333333333333ggGGgg3ggG3333WW3333333333333333333333",
"33333333333333333333333WWW333GgG3gGGgWWWW33333333333333333333333",
"33333333333333333333333333333WW&333GggG3333333333333333333333333",
"333333333333333333333333333333333333gGGW333333333333333333333333",
"3333333333333333333333333333333333WWW333W33333333333333333333333",
"3333333333333333333333333333333333WWW333333333333333333333333333"
}),

({
"   DDD3                              WD                     WW ",
" WWWWWD3                        WD  WWD   WD              DWWWW",
" WWWWWWWD3                   WDWWWDWWWDWWWWD            DDWWWWW",
" WWWWWWWWDDD3          D  D  WWDWWWDWWDWWWWD          DWWWWWWWW",
"  WWWWWWWWWWDDDD3    DWW   DWWWWDWWDWWWDWWDD    DDDDDDWWWWWWWW ",
" WWWWWWWWWWWWWWWDDg DWWW    D(WWWDgggDWWDD   DDDWWWWWWWWWWWW   ",
" WWWWWWWWWWWWWWWDggDWWW   W    WWWDGGGGG***DDWWWWWW            ",
"  WWWWWWWWWWWWWWDggDWWWDGggGGGGGGGGgGGGGGGWWWWWWWWWW           ",
"  WWWWWWWWWWWWWWWDg ggggggggDDGgGGGGOOGGGGWWWW                 ",
"  WWWWWWWWWWWWWWWWDgggGgggDDWDDGGGGGGOGGGgGGGg                 ",
"    WWWWWWWWWWWWWWWWDggg ggDWWDGGgGGGGGGGGGGG                  ",
"    WWWWWWWWWWWWWWWWWWD3gGDWWWWWDGGGGGG  WGGG                  ",
"      WWWWWWWWWWWWWWWWWWDDggDWWWWDGGGGWW         m   mmm  m    ",
"       WWWWWWWWWWWWWWWWWWWD3 DDWWDGG GRRRRr3       mmmmm   DDWW",
"        WWWWWWWWWWWWWWWWWWD3   DWWDG     RRRR R  m         DWWW",
"                  WmmmWWWWDoooooo    mmmm   R R m         DWWWW",
"                mmmgggmmmmDoooooooommmmmmmmR  mm        DWWWW  ",
"                mm   ggggggggoooooooo      mm     DDDWWWWWWW   ",
"            mmmmmmm   ggGggggggooooooooo           DDWWWWWW    ",
"           mmm    gggggggggGggggoooooooooo,       DWWWWWWW     ",
"      mmmmmmm         ggggggggggggooooooooooo    DWWWWWWW      ",
"    mmm      DDDDD DDDgggggggggGggggoooooooooooDDWWWW          ",
"   mmm    ggGgggGGDDggDDDDDgDgggggggggoooooooooWWWWWW          ",
"   mmggGggGGggGgGGgGgDWWWWWWWDDggggGgggoooooooooWW             ",
"    gggGggGggGggGggggGgDDWWWWWWDDggggggooooooooooo             ",
"  gggGgGgGggGgggGGgg.    DDDWWWWWDDgggggoooooooooo             ",
" gGGggGggGggGgg             DDDWWWWggggggoooooooo DDDWW        ",
"gggGggggGggg                   DDggg  ggggoooo DDDWWWWW        ",
"gGgggGggGgg                   WWWDgg  ggggooooDWWWWWWW         ",
"gggGggGgGgg                    WW WWWDDggggo  DDWWWWWW         ",
"gGgggggGggg                     WWWWWWWWDgggoooWWWW            ",
"gggGggGggGg                        WWWWWDggo   W               ",
"ggGggggGgggg                      ggggGggggoo   oogGGG         ",
"gGgggGggggGggg                 gggggggggGoo  ooooGggGGG.       ",
" gggggggGggggggg            ggGggggGggggoooooooogGGGgGGg       ",
" gggGggggGgggggggggggggggggggggggggggggoooooo GGgGGGGgGGggGG   ",
"   gggggGggggGgggggggGgggggggggGgggggggooooooo      GGGgGGgGGg ",
"     ggggGgggggggggggggggGggggggggggggoooooo            WWWWWWW",
"       ggggGgggggGgggggggggggggGggggoooooo            WWWWWWWWW",
"          gggggGggggggggggGggggggooo               WWWWWWWWWWWW",
"              gggggggGggggggggGgg                       WWWW   ",
"                                                         WWWWW "
}),
//2345678901234567890123456789012345678901234567890123456789012345678901234567890
({
"8888888888888R7.8888888O2\\2888888R777888888O2/  888888R77888888", // 1
"888888888888888R7.888888O2\2288888R77788888O2/ 888888R7788888888", // 2
"88888888888888888R7.88888O2\\28888R7778888O2/ 88888R778888888888", // 3
"8888888888888888888R7.8888O2\\2888R777888O2/ 8888R77888888888888", // 4
"888888888888888888888R7.888O2\\288R77788O2/ 888R7788888888888888", // 5
"88888888888888888888888R7.88O2\\28R7778O2/ 88R778888888888888888", // 6
"8888888888888888888888888R7.8O2\\2R777O2/ 8R77888888888888888888", // 7
"888888888888888888888888888R7.O2\2R77O2/ R7788888888888888888888", // 8
"88888888888888888888888888888R7.O\\RO//R778888888888888888888888", // 9
"7O7O7O7O7O7O7O7O7O7O7O7O7O7O7O7O7O7RO7O7O7O7O7O7O7O7O7O7O7O7O7O7", // 10
"8888888888888888888888888888R77//o---O7RR88888888888888888888888", // 11
"88888888888888888888888888R77O//o(D.o 7OR77888888888888888888888", // 12
"888888888888888888888888R778O7/8  oo8 O778R778888888888888888888", // 13
"8888888888888888888888R778 O7/8   oo8  O778 R7788888888888888888", // 14
"88888888888888888888R778D3D3D3D3D3D3D3D3D3D3D8R77888888888888888", // 15
"888888888888888888R7788D3D3D3D3D3D3D3D3D3D3D3888R778888888888888", // 16
"888888888888888R778888D3D3D3D3D3D3D3D3D3D3D3D88888R7788888888888", // 17
"8888888888888R77D8888D33D3D3D3o   D3D3D3D3D3D8888888R77888888888", // 18
"88888888888R778888D3D3D3D3D3Do   3D3D3D3Do  D3D8888888R778888888", // 19
"888888888R778888D3D3D3D3D3D3o    3D3D3D3D3o  DD3D8888888R7788888", // 20
"8888888R7788D3D3D3D3D3D3D33o    D3D3D3D3D3Do--D3D3D3888888R77888", // 21
"88888R778888D3D3D3D3D3D3Doo,.,/D3D3D3D3D3D3D   D3D3D3D888888R778", // 22
"888R7788D3D3D3D3D3D3D3Do,--,./D3D3D3D3DD3D3D3o--D3D3D3D3D88888R7", // 23
"8R7788D3D3D3D3D3D3D3Do,,..../D3D3D3D3D3D3D3D3D    D3D3D3D3D88888", // 24
"7788D3D3D3D3D3D3D3Do...--../D3D3D3D3D3D3D3D3D3Do---D3D3D3D3D3888", // 25
"8D3D3D3D3D3D3D3D3Do,,.,.../D3D3D3D3D3D3D3D3D3D3D    D3D3D3D3D3D8", // 26
"D3D3D3D3D3D3D3D3Do..--.../D3D3D3D3D3D3D3D3D3D3D3Do---D3D3D3D3D38", // 27
"D3D3D3D3D3D3D3Do*.....,./D3D3D3D3D3D3D3D3D3D3D3D3D     D3D3D3D3D", // 28
"D3D3D3D3D3D3D3o..---.../D3D3D3D3D3D3D3D3D3D3D3D3D3Do---D3D3D3D3D", // 29
"D3D3D3D3D3D3Do.. ..,,,&D3D3D3D3D3D3D3D3D3D3D3D3D3D3D      D3D3D3", // 30

})


}); 
  hex_height = 10;
  hex_width = 16;
  pic_num = random(sizeof(all_pics));
  seal_pic = all_pics[pic_num];
  colour_map = colour_maps[pic_num];
  highlight = "none";
  setup_hex_blocks();
  setup_hex_positions();
  randomise_hexes();

}



