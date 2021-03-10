#include <std.h>
#include <daemons.h>
#include "/realms/lujke/tecqumin/tecqumin.h"
#include "/realms/lujke/tecqumin/seal_pics.h"
inherit DAEMON;

string * seal_pic, * all_pics, *colour_maps, * colour_map, pic_num;
mapping __pic_blocks, __block_positions, __colour_blocks;
int block_width;
int block_height;

void setup_block_positions();

void create(){
  object room;
  int block_x, block_y, line_no, startx, endx, first_line, line_count, string_length, start_x, end_x, block_row_count; 
  string line, * block, entry, cline, *cblock, centry;
  mapping m, c;
  __block_positions = ([]);
  __colour_blocks = ([]);
  //  room = find_object_or_load("/realms/lujke/workroom");
  __pic_blocks = ([]);
  block_width = 12;
  block_height = 10;
  all_pics = ({ PICS1, 
                PICS2,
                PICS3,
                PICS4
  });
  colour_maps = ({
({
//23456789012345678901234567890123456789012345678
"8          88          88         888           ",
"8          88          8g8        888           ", 
"8          88 o#G&&&Ggggo/8G%%go(8o88           ", 
"8  g#o(.8  88o,G%&gGg#oggGg%ogGg#Ggg,8          ", 
"8 og%G##oGgggo@%Gg%%&oGGG go. gG%ggGG*8         ", 
"8   g##%o /gGgGg%Gg%%%%GgGg%Gg%Go.gogo8         ", 
"8  ogGg%G*ggG%%g#&G%%%ggg#G%%g@&&ooggo.8        ", 
"8  o gogG%gGG&%o,,,,g&#Ggo,,,Gg&GggGgGg%GgGg%%G(", 
"8%g#G&g#G&%Ggo/G(13)g#&gG(13)g%#G%gGGgG%oGg#Gg#(", 
"8 o/8(goGgGgGg#o'''gG%gGgo```G%%%%gGg#ogG*oGo8 g", 
"8 o8G8 g#GgGG%goGgG&@&oGG&%&gG%%%%Go8G8gG8 g8   ", 
"8     gogG&GgG&&gGg Gg#GGg&G gG%%%GGg#Gg#G8     ", 
"8    G8gG%o88gG&%&&%%g#GG&&gG8 %8 GggG%%8%8     ", 
"8    oG&g8 8G%8  %oGg##ggG8 og#8o8G88.8o,Go8    ",  
"8      o8Go88   G%g&&GgGgG%g8 G8 oG88o8 G8      ", 
"8     og##8o8 og###G&%&GGg###8 o8GgG8           ", 
"8        o88og#G@oGgGg&gGg8G%go8  o88           ", 
"8         GgG&8   oooooooo8  GggGG888           ", 
"8        gog8     oooogoog8    gog888           ", 
"8       oog88     goooogoog8    oog88           ", 
"8      gooo88     ogooooogo8    ooog8           ", 
"8     gooo888    ogoooooogo8     oogo8          ", 
"8     oo8o888   oooooggoooo8     g8o8           ", 
"4       og444  ooooo4  ooooo4   oggg4           ", 
"4          44oogooo4   ooogoo4    444           ", 
"4         ggooooooog4  gooooooogo4444           ",
"4        ooo4 ooo4ooo4ooo4 oo4 oooo44           ",
"4        ooo4oo4   oo4oo4  oo4oo4 ooooo4        ",
"4       ooo44 oo4   o4 oo4 oo4 ooo444 oo4       ",
"4     ooo4 44  o4      o4  o4    oo44           "

}),
({
"888888888888888888888888888888888888888888888888888888888888",
"888888888888888888888888888888OR8888888888888888888888888888",
"88888888888888888888888888888ORO8888888888888888888888888888",
"8888888888888888888888888888OOO88888888888888888888888888888",
"88888888888888888888o888888OOOO88888888888888888888888888888",
"8888888888OOO8888888O888888OOO888888OO888888888888O888888888",
"88888888888OOR888888OO88888rOOO8888Or88888888OOOOO8888888888",
"888888888888OOO888888OrO888OOO88OrO8888OOrOrOO88888888888888",
"888888888888OOO888888OrOO8OOOOR8ROO88OOOOr888888888888888888",
"8888888888888rOOROOOOOO88OOOOoOOr8OOO88OOrr88888888888888888",
"8888888888888888Oo8OrORROOo8OoOOoRo8oROROo88888OrO8888888888",
"888888888Oo888888Ro8o8OOOOo8ORRRr8OROo8OOO88OOo8888888888888",
"88888888888OOOOOOOOOOOROORo8r8Or8OOOOOr8R8Or8888888888888888",
"888888888888888888o8OROR555RrrRRr8555ROOr8888888888888888888",
"8ROOo8O888888Oo8OROROROo858RORRr8r858O8oO8OORo88O8o8R8888888",
"8r88OOo8OOROOOORo8OOOOOOOR8555558Or8OOOOOOOOORROoO8OrOoO88R8",
"8888888ORoO8ORR88OOOo8OOo8OOO558OoO8ROOOOo8O888888888OOo8888",
"888888888888888ROOORROOOr8Ro8ORRROOROOO8o8rOoR88888888888888",
"88888888888888OrO8oO8OOOORr88OOROOOOOOOOR888Or88888888888888",
"888888888888OOO88Ro8ORoOOOOOORORo8ROORo888888888888888888888",
"88888888888888888OOOOo8RROOOORo88OOOoROOrRO88888888888888888",
"8888888888888888OOOO88r8O8OOOOO8OORO888ROOr8o888888888888888",
"88888888888888r8OOO8888Or88OOo8R88ROOO88888ROOO8888888888888",
"8888888888r8OOOOR888888o8888Rr8OO8888RO88888r8o8888888888888",
"888888888OO88888888888Oo88888r8OO88888O888888OORR88888888888",
"88888888O888888888888OO888888OROo88888O888888888Ro8888888888",
"8888888888888888888888888888OOOr88888888888888888O8888888888",
"888888888888888888888888888OOR888888888888888888888888888888",
"888888888888888888888888888o88888888888888888888888888888888",
"8888888888888888888888888888OO888888888888888888888888888888"}),

({
"B33333333333B33333333333B33333333333B33333333333",
"B33333333333B33333333333B33333333333B33333333333",
"B33333333333B333333%##&3B33333333333B33333333333",
"B33333333333B33333%. *%3B33333333333B33333333333",
"B33333333333B333&(./%&%3B.. ,/%33333B33333333333",
"B33333333333B333&(..,..3B##%*,*#3333B33333333333",
"B33333333333B3333&%##%&3B333#,./&333B33333333333",
"B33333333333B33333333333B33&. ,#3333B33333333333",
"B33333333333B33333333333B,./%3333333B33333333333",
"B33333333333B33333333333B. ,&3333333B33333333333",
"B33333333333B33333333333B./%33333333B33333333333",
"B33333333333B33333333&(3B(3333333333B33333333333",
"B33333333333B3333333&/ 3B33333333333B33333333333",
"B33333333333B333333&(..3B33333333333B33333333333",
"B33333333333B333333#, *3B33333333333B33333333333",
"B33333333333B333333, *%3B33333333333B33333333333",
"B33333333333B33333&..(&3B..*33333333B33333333333",
"B33333333333B333&%(  ..3B   *&333333B33333333333",
"B33333333333B&/,.      3B   .(333333B33333333333",
"B33333333333B.         3B    ,##//%3B33333333333",
"B333333333%3B    ,,    3B,.   */. *3B33333333333",
"B33333333%*3B   .*,    3B,*.. ,*, ,3B33333333333",
"B333333.   3B ,/.      3B,,,,*, .(33B33333333333",
"B333333%/. 3B   **.    3B .,,*,**.,3B33333333333",
"B33333&%/  3B   */.    3B ..,/,**,,3B33333333333",
"B333333(. .3B   ,/*    3B  .//,,,*.3B33333333333",
"B333333%,,*3B   .**    3B   /, ../.3B%3333333333",
"B3333333&. 3B.   .,    3B  ,,   .*.3B*3333333333",
"B333333&/ ,3B          3B ./.  .*, 3B,3333333333",
"B33333&(.**3B          3B,*(/*/##,*3B(3333333333",
"B33%(((*,* 3B          3B *%33333333B33333333333",
"B3#,/##/** 3B      .,, 3B  *33333333B33333333333",
"B33//##(**.3B       .(/3B   &3333333B33333333333",
"B3&//*/((/.3B        ,(3B   &3333333B33333333333",
"B3/   .,***3B          3B,  %3333333B33333333333",
"B3,      *,3B(*,,.     3B##(#&3#&%%3B%&&&3333333",
"B3.        3B.,,*/(*.  3B ..*#&,. .3B,..,&&&&333",
"B3 .,.     3B      ..  3B  .. .,,  3B (OB,   .,(",
"B3  ,/,    3B         .3B...,,,*.  3B *.      ,#",
"B3   *(*   3B          3B       *, 3B . ./%#WWB3",
"B3*  ./(*  3B          3B      ./  3B.,*#%%33WB3",
"B3&,   *#/*3B          3B   ,, .*  3B .,//(33333",
"B333#, .*  3B.        .3B....**.   3B   ./&3WWB3",
"B3333#, .*.3B      .,,.3B    .,/(//3B/,.  ,.#WB3",
"B333&(.   .3B/%%%%#.   3B   **/%3333B33%*  *#333",
"B333#*. .,.3B.#333&/*,.3B.**, ./&333B333&%#&3333",
"B333&%#(*/*3B*,(&3333333B,..,**(&333B33333333333",
"B33333333&&3B%%&33333333B        (&3B33333333333",
"B33333333333B33333333333B        ./3B33333333333",
"B33333333333B33333333333B/. //,    3B33333333333",
"B33333333333B33333333333B3#, ,//,  3B&3333333333",
"B33333333333B33333333333B33%   ,*  3B(3333333333",
"B33333333333B33333333333B333%/.    3B.&333333333",
"B33333333333B33333333333B33333*    3B&3333333333",
"B33333333333B33333333333B33333333#,3B  .*%333333",
"B33333333333B33333333333B333333333%3B    .*&3333",
"B33333333333B33333333333B33333333333B      ./%33",
"B33333333333B33333333333B33333333333B*.,**/%&333",
"B33333333333B33333333333B33333333333B3###%&33333",
"B33333333333B33333333333B33333333333B33333333333" }),
({
"888888888888888888888888888888888888888888888888",
"888888888888888888888888888888888888888888888888",
"888888888888888888888888888888888888oo8888888888",
"8888888888888888888WWWWWWWWWWWW88ooooo8888888888",
"888888888888888888WWWWWWWWWWWWWWooooo88888888888",
"88888888888888888WWWWWWWWWWWWWWWWooooG8G88888888",
"8888888888888888WWWWWWWWWWWWWWWWWWoo4GR4G8GG8888",
"888888888888888WWWWWWWWWWWW4G4G4G4G4G4G4G88G8888",
"888888888888888WWWWWWWWWWWWWoooooo4G888888888888",
"8888888888888WWWWWWWWWWWWWWoooooo4G8888888888888",
"888888888888WWWWWWWWWWWWWW4G4G4GG888888888888888",
"88888888888WWWWWWWWWWWWWWWWoooo4G888888888888888",
"8888888888WWWWWWWWWWWWWWWWWWoo4G8888888888888888",
"888888888WWWWWWWWWWW4G4G4G4G4GG88888888888888888",
"888888888WWWWWWWWW88WWoooooo4G888888888888888888",
"88888888WWWWWWWWWWWWWoooooG4G4888888888888888888",
"8888888WWWWWWWWWWWWWG4G4G4G4G8888888888888888888",
"888888WWWWWWWWWWWWWWWWoooo4G88888888888888888888",
"88888WWWWWWWWWWWWWWWWWWoo44G88888888888888888888",
"8888WWWWWWWWWWW4G4G4G4G4GG8888888888888888888888",
"8888WWWWWWWWW88Wvooooo4G888888888888888888888888",
"888888888888GGGoooooo4G8888888888888888888888888",
"88888888888G4G4G4G4G4G88888888888888888888888888",
"8888888888888oooooo88888888888888888888888888888",
"888888888888oooooo888888888888888888888888888888",
"88888888888oooooo8888888888888888888888888888888",
"8888888888oooooo88888888888888888888888888888888",
"888888888oooooo888888888888888888888888888888888",
"88888888oooooo8888888888888888888888888888888888",
"8888888oooooo88888888888888888888888888888888888"}) 
}); 
 
  pic_num = random(sizeof(all_pics));
  setup_pic_blocks();
}

void setup_pic_blocks(){
  int block_x, block_y, line_no, startx, endx, first_line, line_count, string_length, start_x, end_x, block_row_count; 
  string line, * block, entry, cline, *cblock, centry;
  mapping m, c;
  __block_positions = ([]);
  __colour_blocks = ([]);
  __pic_blocks = ([]);
  seal_pic = all_pics[pic_num];  
  colour_map = colour_maps[pic_num];
  string_length = strlen(seal_pic[0]);
  line_count = sizeof(seal_pic);
  for (block_x = 0;block_x<(string_length/block_width); block_x ++){
    start_x = block_x * block_width;
    end_x = start_x + block_width-1; 
    c = ([]);
    m = ([]);
    block_row_count = line_count/block_height;
    for(block_y = 0;block_y<block_row_count;block_y ++){
      cblock = ({});
      block = ({});
      for (line_no = (block_y*block_height); line_no < (block_y*block_height) + block_height; line_no ++){
        line = seal_pic[line_no];
        cline = colour_map[line_no];
        entry = line[start_x .. end_x];
        centry = cline[start_x .. end_x];
        block += ({entry});
        cblock += ({centry});
      }
      m[block_y] = block;
      c[block_y] = cblock;
    }
    __colour_blocks[block_x] = c;
    __pic_blocks[block_x] = m;   
  }
  setup_block_positions();
  make_empty_space();
  randomise_blocks();
}

void clean_up() { 
  // This function added to prevent data being removed by the inherited
  // clean_up function.
  return; 
} 

int get_adjusted_x(int x, int y){
  int i, adj_i, adj_x, adj_y;
  i = x*10 + y;
  adj_i = __block_positions[i];
  adj_x = (int)adj_i/10;
  adj_y = adj_i%10;
  return adj_x;
}

int get_adjusted_y(int x, int y){
  int i, adj_i, adj_x, adj_y;
  i = x*10 + y;
  adj_i = __block_positions[i];
  adj_x = (int)adj_i/10;
  adj_y = adj_i%10;
  return adj_y;
}

int check_match(){
  int i, x, y, adj_x, adj_y, string_length, rows, columns;
  string * block, * adjusted_block, *empty_block;
  object room;
  //  room = find_object_or_load("/realms/lujke/workroom");
  string_length = sizeof(seal_pic[0]);
  columns = string_length / block_width;
  rows = sizeof(seal_pic)/block_height;
  for(x = 0; x < columns; x ++){
    for(y=0;y <rows;y++){
      //  tell_room(room, "Checking match, block: " + x + ", " + y); 
      block = __pic_blocks[x][y];
      adjusted_block = get_adjusted_block(x,y);
      if (!arrays_equal(block, adjusted_block)){
        //  tell_room(room, "Initial match failed. Checking secondary match...)");
        empty_block = __pic_blocks[0][0];
        if (arrays_equal(adjusted_block, empty_block)){  //doing this allows the empty block to be in any blank space - in theory any space that has a
           //  tell_room(room, "Secondary match made");      //duplicate, but in practice, this will only mean a blank space
           continue;
        }
        //  tell_room (room, "Secondary match failed. Checking tertiary...");
        if (x == 0 && y ==0 ){
          //  tell_room(room, "Tertiary match made"); 
          continue;
        }
        //  tell_room(room, "Match failed!");
        return -1;
      }
      //  tell_room(room, "Match!");
    }
  }
  return 1;
}


string * get_adjusted_block(int x, int y){
  int i, adj_i, adj_x, adj_y, *ks;
  mapping blocks;
  object room;
  //  room = find_object_or_load("/realms/lujke/workshop");
  i = x*10 + y;
  adj_i = __block_positions[i];
  adj_x = (int)adj_i/10;
  adj_y = adj_i%10;
  //  tell_room(room, "Returning __pic_block" + adj_x + " " + adj_y);
  return __pic_blocks[adj_x][adj_y];
}

string * get_adjusted_colour_block(int x, int y){
  int i, adj_i, adj_x, adj_y, *ks;
  mapping blocks;
  object room;
  //  room = find_object_or_load("/realms/lujke/workshop");
  i = x*10 + y;
  adj_i = __block_positions[i];
  adj_x = (int)adj_i/10;
  adj_y = adj_i%10;
  //  tell_room(room, "Returning __pic_block" + adj_x + " " + adj_y);
  return __colour_blocks[adj_x][adj_y];
}

string query_colour_code(string str){
  string * ks;
  mapping cols = ([ "B" : "%^BOLD%^%^BLUE%^", "b" : "%^RESET%^%^BLUE%^",
                        "O" : "%^BOLD%^%^ORANGE%^","o" : "%^RESET%^%^ORANGE%^",
                        "C" : "%^BOLD%^%^CYAN%^",  "c" : "%^RESET%^%^CYAN%^",
                        "D" : "%^BOLD%^%^BLACK%^", "d" : "%^RESET%^%^BLACK%^",
                        "G" : "%^BOLD%^%^GREEN%^", "g" : "%^RESET%^%^GREEN%^",
                        "R" : "%^BOLD%^%^RED%^", "r" : "%^RESET%^%^RED%^",
                        "M" : "%^BOLD%^%^MAGENTA", "m" : "%^RESET%^%^MAGENTA%^",
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
  return cols[str]; 
} 


void make_empty_space(){
  string * sp, line, cline;
  object room; 
  int i;
  //  room = find_object_or_load("/realms/lujke/workroom");
  line = "";
  cline = "";
  for (i=0;i<block_width;i++){
    //  tell_room(room, "Adding an extra space to the blank line");
    line = line + " ";
    cline +="9";
  }
  //  tell_room(room, "Blank line: '" + line + "'");
  sp = ({});
  for (i = 0; i<block_height;i++){
    //  tell_room(room, "Adding an extra line to the blank block");
    sp += ({line});
  }
  //  tell_room(room, "Blank block now looks like this:");
  for (i=0;i<sizeof(sp);i++){
    //  tell_room(room, "'" + sp[i] + "'");
  }
  __pic_blocks[0][0] = sp;
  sp = ({});
  for (i = 0; i<block_height;i++){
    sp += ({cline});
  }
  __colour_blocks[0][0] = sp;
}

void setup_block_positions(){
  int i, x, y, string_length, rows, columns;
  object room;
  __block_positions = ([]);
  //  room = find_object_or_load("/realms/lujke/workroom");
  string_length = strlen(seal_pic[0]);
  columns = string_length/block_width;
  rows = sizeof(seal_pic)/block_height;
  for (x=0; x< columns; x++){
    for (y=0;y< rows ;y++){
      i = x*10 + y; 
//      tell_room(room, "x: " + x + "   y: " + y + "  i: " + i + " string_length: " + string_length + "  block_width: " + block_width);
//      tell_room(room, "setting position " + i + " to " + i);
      __block_positions[i] = i;
    }
  }
}

string add_colour(string str, int block_x, int block_y, int line_no){
  int i, l, char_no;
  object room;
  string  result, colour_insert, code_line, code_char;
  //  room = find_object_or_load("/realms/lujke/workroom");
  l = block_y* block_height;
  l += line_no;
  //  tell_room(room, "Size of colour map: " + sizeof(colour_map));
  //  tell_room(room, "Trying to find line: " + l);
  code_line = colour_map[l];
  result = "";
  char_no = block_x*block_width;
  for (i=0;i<block_width;i++){
    if (stringp(code_line)){
      code_char = code_line[char_no+i..char_no+i];
      colour_insert = query_colour_code(code_char);
      result += colour_insert;
    }
    result += str[i..i];
  }
  return result;
} 

string * query_colour_map(){
  return colour_map;
}


string interlace_string(string str1, string str2){
  int i, len1, len2;
  string result, code_char;
  len1 = strlen(str1);
  len2 = strlen(str2);
  result = "";
  for (i = 0; i<len1, i<len2; i++){
    result += query_colour_code(str2[i..i]);
    result += str1[i..i];
  }
  return result;
}

varargs string * show_pic(int show_grid, int show_colour){
  int block_x, block_y, line_no, count, count2, block_line, string_length, i, column, row;
  string entry, * block, * picture, line, centry, *cblock, *cpicture, cline;
  object room;
  //  room = find_object_or_load("/realms/lujke/workroom");
  count = sizeof(seal_pic);
//  tell_room(room, "Total lines in picture: " + count);
  
  if ( count<1 ){
    return;  
  }
  picture = ({});
  string_length = strlen(seal_pic[0]);
  count = sizeof(seal_pic);
  entry = "";


  for (block_y = 0;block_y < count/block_height;block_y++){
    if(block_y%2==1){
      line = "%^B_BLACK%^%^BOLD%^%^WHITE%^";
      for (i=0;i<string_length;i++){
        if ( i%block_width == block_width/2){
          column = (i/block_width)+1;
          line += "%^B_BLUE%^%^BOLD%^%^WHITE%^" + column + "%^B_BLACK%^%^BOLD%^%^WHITE%^";
        } 
        line += "-";
      }  
    } else {
      line = "%^B_BLACK%^%^BOLD%^%^WHITE%^";
      for (i=0;i<string_length;i++){
        if ( i%block_width == block_width/2){
          column = (i/block_width)+1;
          line += "%^B_BLUE%^%^BOLD%^%^WHITE%^" + column + "%^B_BLACK%^%^BOLD%^%^WHITE%^";
        } 
        line += "-";
      }  
    }
    if (show_grid ==1){
      picture += ({line});
    }
    for (line_no = 0; line_no< block_height; line_no ++){
      line = "";
      for (block_x = 0; block_x < (string_length/block_width); block_x ++){
        block = get_adjusted_block(block_x, block_y); 
        if (line_no > sizeof(block)-1){
          continue;
        }
        entry = block[line_no];
        cblock = get_adjusted_colour_block(block_x, block_y);
        centry = cblock[line_no];
        entry = interlace_string(entry, centry);
        line += entry;
        if (line_no%block_height == block_height/2 && show_grid ==1){
          row = block_y+1;
          line += "%^B_BLUE%^%^BOLD%^%^WHITE%^" + row + "%^B_BLACK%^%^BOLD%^%^WHITE%^";
        } else {
          if (show_grid==1){
            line += "|";
          }
        }
      }
      picture += ({line});
    }   
  }
  count = sizeof(picture);
  for (i=0;i<count;i++){
    tell_object(TP, picture[i]);
  }
}

void set_pic(int pic_no){
  pic_num = pic_no;
  setup_pic_blocks();
}

void simple_show_pic(){
  int i, count;
  count = sizeof(seal_pic);
  for (i=0;i<count;i++){
    tell_object(TP, seal_pic[i]);
  }
  tell_object(TP, "Lines in pic: " + sizeof(seal_pic));
}

void swap_blocks(int block1, int block2, object toucher, string dir){
  int temp_block;
  tell_object(toucher, "Swapping block " + block1 + " with " + block2);
  tell_object(toucher, "Starting values: " + block1 + ": " + __block_positions[block1] + " | " +  block2 + ": " + __block_positions[block2]);
  temp_block = __block_positions[block1];
  __block_positions[block1] = __block_positions[block2];
  __block_positions[block2] = temp_block;
  tell_object(toucher, "Ending values: " + block1 + ": " + __block_positions[block1] + " | " +  block2 + ": " + __block_positions[block2]);

  if (objectp(toucher)){
    tell_object(toucher, "As you touch the basalt block, the image on its surface slides into the empty space " + dir);
  }
}

void touch_block(int x, int y, object toucher){
  int block_number, above_y, below_y,left_x, right_x, row_count, column_count, temp_block_no, position;
  row_count = sizeof(__pic_blocks[0]);
  column_count = sizeof(__pic_blocks);
  left_x = x-1;
  right_x = x+1;
  above_y = y-1;
  below_y = y + 1;
  position = x*10+y;
  tell_object(toucher, "block touched is: " + position);
  if (left_x>= 0){
    position = left_x*10+ y;
    tell_object(toucher, "Checking left. Position is: " + position);   
    block_number = __block_positions[position];
    tell_object(toucher, "Block number: " + block_number);
    if (block_number==0){
      tell_object(toucher, "Found blank space! Trying to swap blocks");
      swap_blocks(x*10+y, left_x*10 +y, toucher, "to its left.");
      return;
    }
  }
  if (right_x<column_count){
    position = right_x*10 + y;
    tell_object(toucher, "Checking right. Position is: " + position);   
    block_number = __block_positions[position];
    tell_object(toucher, "Block number: " + block_number);
    if (block_number==0){
      tell_object(toucher, "Found blank space! Trying to swap blocks");
      swap_blocks(x*10+y, right_x*10 +y, toucher, "to its right.");
      return;
    }
  }
  if (below_y< row_count){
    position = x*10+ below_y;
    tell_object(toucher, "Checking below. Position is: " + position);   
    block_number = __block_positions[position];
    tell_object(toucher, "Block number: " + block_number);
    if (block_number==0){
      tell_object(toucher, "Found blank space! Trying to swap blocks");
      swap_blocks(x*10+ below_y, x*10 + y, toucher, "below it.");
      return;
    }
  }
  if (above_y > -1){
    position = x*10 + above_y;
    tell_object(toucher, "Checking above. Position is: " + position);   
    block_number = __block_positions[position];
    tell_object(toucher, "Block number: " + block_number);
    if (block_number==0){
      tell_object(toucher, "Found blank space! Trying to swap blocks");
      swap_blocks(x*10+ above_y, x*10 +y, toucher, "above it.");
      return;
    }
  }
}

void randomise_blocks(){
  int i, r, * ks, * vs, val;
  ks = keys(__block_positions);
  vs = values (__block_positions);
  for (i=0;i<sizeof(ks);i++){
    r = random(sizeof(vs));
    val  = vs[r];
    __block_positions[ks[i]] = val;
    vs -= ({val});
  }
}

void show_colour_map(){
  int i;
  for (i=0;i <sizeof(colour_map); i++){
    tell_object(TP, "" + i + colour_map[i]);
  }
}

mapping query_block_positions(){
  return __block_positions;
}

string * query_pic(){
  return seal_pic;
}

mapping query_pic_blocks(){
  return __pic_blocks;
}
