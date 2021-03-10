#include <std.h>
#include <daemons.h>
#include "/realms/lujke/tecqumin/tecqumin.h"
#include "/realms/lujke/tecqumin/seal_pics.h"
inherit DAEMON;

string * seal_pic, * all_pics;
mapping __pic_blocks, __block_positions;
int block_width;
int block_height;

void setup_block_positions();

void create(){
  object room;
  int block_x, block_y, line_no, startx, endx, first_line, line_count, string_length, start_x, end_x, block_row_count; 
  string line, * block, entry;
  mapping m;
  __block_positions = ([]);
  room = find_object_or_load("/realms/lujke/workroom");
  __pic_blocks = ([]);
  block_width = 12;
  block_height = 10;
  all_pics = ({ ({
"                                                            ",
"                              #&                            ",
"                             @/%                            ",
"                            @##                             ",
"                    ,      %%#/                             ",
"          #(/       /      ##/      //            #         ",
"           @@&      //     *((@    /*        %%(/(          ",
"            %##      /*(   //@  #*/    (/*/*(%              ",
"            %(%      /*/( /(@%& .//  ////*                  ",
"             *#%&%(///#  ((/#,@#* (/(  /#**                 ",
"                #(#(*@&&//((#(@%(&(((&/&@,     .*.          ",
"         /,      ., ((@@@#,@&&&&*#@&/(@@/%  //(             ",
"           //////////#&%@&((*#/*/#%@@@*.  /*/               ",
"                  (%%&((   )**&&*(   )//*                   ",
" .@#(%.      %,#%&%&%&%((*/##&&**,***/&(#@/#&,,,//((&       ",
"*   @#((##&%%@@&(#@%/@%//**     */,*/@@@@@@@@&*/(#//*/(@  & ",
"       ,&(//(&.  ///((@#((/#/  ,#(/%&@/#/(*#         #%,    ",
"               .///,&%%@***,,,***#%(/(# ,(*/(.              ",
"              /*/ ,#%@@@%&(**%%&%@@/////.   /**             ",
"            ///  .((@&(/#%@@%(/&((&@#.(                     ",
"                 /#@#((.(@@/%&(( %%%(&@%*.#                 ",
"                #%@/  *(/ %@%%/ //(/   .@#**,,              ",
"              (*###,   #*  #/@,&  .///     ,///             ",
"          (%%###&      (/   &*%*/    */     ,**(            ",
"         ##           #(     *((%     /      #/*.           ",
"        @            #/      /(#(     /         &(%         ",
"                            #/#*                            ",
"                           //&                              ",
"                           ,(,                              ",
"                            %#                              "}),
({
"                                                ", 
"                                                ", 
"                                    _/          ", 
"                   ____________   _/@/          ", 
"                  /^__^^^^^^^^\\_/@@|\\           ", 
"                 /vvvv/v\\&\\&\\&\\&\\@@@/___        ", 
"                /vvvv/vvv\\&\\&\\&\\&\\@/  o \\__/    ", 
"               /vvvv/vvv/\\/_____________/  \\    ", 
"               \\vvv/\\vv/ \\v/@@@@/ |             ", 
"             ______________/@@@@/ /             ", 
"            /^_\\_^^^^^^^^\\_______/              ", 
"           /vvvv/v\\&\\&\\&\\&\\@@@/ |               ", 
"          /vvvv/vvv\\&\\&\\&\\&\\@/  /               ", 
"         /vvvv/vvv/\\/__________/                ", 
"         \\vvv/\\vv/  \\v/@@@@/ |                  ", 
"        _____________/@@@@/  /                  ", 
"       /^_\\_^^^^^^^^\\_______/                   ", 
"      /vvvv/v\\&\\&\\&\\&\\@@@/ |                    ", 
"     /vvvv/vvv\\&\\&\\&\\&\\@/  /                    ", 
"    /vvvv/vvv/\\/__________/                     ", 
"    \\vvv/\\vv/  \\v/@@@@/ |                       ", 
"            ___/@@@@/  /                        ", 
"           /__________/                         ", 
"             /@@@@/                             ", 
"            /@@@@/                              ", 
"           /@@@@/                               ",
"          /@@@@/                                ",
"         /@@@@/                                 ",
"        /@@@@/                                  ",
"       /@@@@/                                   "
}),
({
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@%##&@@@@@@@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@%. *%@@@@@@@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@&(./%&%(,.. ,/%@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@&(..,..,(##%*,*#@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@&%##%&@@@@@#,./&@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@@&. ,#@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@,./%@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@(. ,&@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@# ./%@@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@&(.,(@@@@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@&/ .&@@@@@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@&(../@@@@@@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@#, *&@@@@@@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@, *%@@@@@@@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@&..(&%,..*@@@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@&%(  ..     *&@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@@@&/,.           .(@@@@@@@@@@@@@@@@@@",
"@@@@@@@@@@@&(.          .    ,##//%@@@@@@@@@@@@@",
"@@@@@@@@@@%*     ,,     .,.   */. *%@@@@@@@@@@@@",
"@@@@@@@@@%*     .*,      ,*.. ,*, ,#@@@@@@@@@@@@",
"@@@@@@@.      ,/.       ,,,,,*, .(@@@@@@@@@@@@@@",
"@@@@@@@%/.      **.       .,,*,**.,(@@@@@@@@@@@@",
"@@@@@@&%/  ..   */.       ..,/,**,,(&@@@@@@@@@@@",
"@@@@@@@(. .,.   ,/*        .//,,,*.,%@@@@@@@@@@@",
"@@@@@@@%,,*.    .**         /, ../. *%@@@@@@@@@@",
"@@@@@@@@&. ,,.   .,    .   ,,   .*.  *@@@@@@@@@@",
"@@@@@@@&/ ,*.          .. ./.  .*,   ,@@@@@@@@@@",
"@@@@@@&(.**.            ,,*(/*/##,*//(@@@@@@@@@@",
"@@@%(((*,*                *%@@@@@@@@@@@@@@@@@@@@",
"@@#,/##/**         .,,     *@@@@@@@@@@@@@@@@@@@@",
"@@@//##(**.         .(/.    &@@@@@@@@@@@@@@@@@@@",
"@@&//*/((/.          ,((    &@@@@@@@@@@@@@@@@@@@",
"@&/   .,***/,          ,/,  %@@@@@@@@@@@@@@@@@@@",
"@%,      *,,/(*,,.      /##(#&@#&%%%%%&&&@@@@@@@",
"&(.          .,,*/(*.     ..*#&,. .,*,..,&&&&@@@",
"#. .,.             ..      .. .,,   . (*),   .,(",
"(.  ,/,               ......,,,*.     *.      ,#",
"#,   *(*                        *,    . ./%#&,%@",
"@%*  ./(*                      ./    .,*#%%@@&@@",
"@@&,   *#/*,.               ,, .*     .,//(@@@@@",
"@@@@#, .*   ..        .. ....**.        ./&@&^@@",
"@@@@@#, .*.        .,,.      .,/(/////,.  ,.#&@@",
"@@@@&(.   .,*/%%%%#.        **/%@@@@@@@%*  *#@@@",
"@@@@#*. .,.  .#@@@&/*,....**, ./&@@@@@@@&%#&@@@@",
"@@@@&%#(*/*,,*,(&@@@@@@%*,..,**(&@@@@@@@@@@@@@@@",
"@@@@@@@@@&&%%%%&@@@@@@@#         (&@@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@#         ./&@@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@%/. //,    *%@@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@#, ,//,   /&@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@@%   ,*   .(@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@%/.      .&@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*     /&@@@@@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#,    .*%@@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%*     .*&@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#,      ./%@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/(*.,**/%&@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@###%&@@@@@",
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" }) ,
({
"                                                ",
"                        #                       ",  
"               #&&&&&%###/ (%%%#( /             ", 
"   ##%(.      ,&%&#@##(%%&%%,#.##%#,,           ",
"   .%&## %&#%%@%%#%%&%/%% %&. (#% #.%*          ",
"     ##%( /%&%.%%&%%%%%#%#%%#%%#(.%,%,          ",
"   (%#%%#*%#%%%@#&%%%%####%%%&@&&,(##/.         ",
"   ( #(#&%#&&&%(,,,,%&#%&,,,,#%&%##&##&%#%#%%%#(",
"&%##%&##%&%%#,/(( ))##&%(( ))#%#&%##%#%%(%##%##(",
"  (/ (#(&#%#%##'''',%%&%&````%%%%%#%##(#**(%(  &",
"  / .  ##&#%&%#(&#&&@&/&%&%&@&%%%%%( % #%  #    ",
"      #/#&&&#&&&%&% &##&%&&% &%%%%&&##%##.      ",
"     . #@%(  &&&%&&%%##%&&&#.  %  &##&%% %      ",
"     (@&#   *%   %/&####&%  (## ( .  . ,,./     ",
"       , *(     %%&&&%&%&%%#  .  (%  (  .       ",
"      ,### /  (####%&%&%&####  / .%*            ",
"         (  (##%@/%#%&&&%# &%#(   (             ",
"          %#%&    %&%&%&%&   %##%&              ",
"         %%&      ,&&&&&&#     %%#              ",
"        %%&       &%&&%&&%*     &&%             ",
"       #%%,       %%%&&&%&%     %%%#            ",
"      %&*&       @&&%%&&&&&      &&&%           ",
"      &% &      &&&&%##&&&&      % @            ",
"        %*     &%&&&   %&%%%    /###            ",
"             %@&@&&    &&&@&&                   ",
"          %%&&&&&&&&   &&&&&&&&%*               ",
"         %%&  &&& &&& &&&  &&  &&&&             ",
"         %&& &&    && &&   && &&  &&&&&         ",
"        &&&   &&    &  &&  &&  &&&    &&        ",
"      &&&      &       &   &     &&             "
})  });
  seal_pic = all_pics[random(sizeof(all_pics))];   
  line_count = sizeof(seal_pic);
  string_length = strlen(seal_pic[0]);
  tell_room(room, "Setting up pic blocks");
  for (block_x=0;block_x<(string_length/block_width);block_x++){
    tell_room(room, "block_x: " + block_x);
    start_x = block_x * block_width;
    tell_room(room, "start_x: " + start_x);
    end_x = start_x + block_width-1; 
    tell_room(room, "end_x: " + end_x);
    m = ([]);
    block_row_count = line_count/block_height;
    for(block_y = 0;block_y<block_row_count;block_y ++){
      block = ({});
      for (line_no = (block_y*block_height); line_no < (block_y*block_height) + block_height; line_no ++){
        line = seal_pic[line_no];
        entry = line[start_x .. end_x];
        block += ({entry});
      }
      m[block_y] = block;
    }
    __pic_blocks[block_x] = m;   
  }  
  setup_block_positions();
  make_empty_space();
  randomise_blocks();
}

string * get_adjusted_block(int x, int y){
  int i, adj_i, adj_x, adj_y, *ks;
  mapping blocks;
  object room;
  room = find_object_or_load("/realms/lujke/workshop");
  i = x*10 + y;
  adj_i = __block_positions[i];
  adj_x = (int)adj_i/10;
  adj_y = adj_i%10;
  tell_room(room, "Returning __pic_block" + adj_x + " " + adj_y);
  return __pic_blocks[adj_x][adj_y];
}

void make_empty_space(){
  string * sp, line;
  int i;
  line = "";
  for (i=0;i<block_width;i++){
    line += " ";
  }
  sp = ({});
  for (i = 0; i<block_height;i++){
    sp += ({line});
  }
  __pic_blocks[0][0] = sp;
}

void setup_block_positions(){
  int i, x, y, string_length, rows, columns;
  object room;
  __block_positions = ([]);
  room = find_object_or_load("/realms/lujke/workroom");
  string_length = strlen(seal_pic[0]);
  columns = string_length/block_width;
  rows = sizeof(seal_pic)/block_height;
  for (x=0; x< columns; x++){
    for (y=0;y< rows ;y++){
      i = x*10 + y; 
      tell_room(room, "x: " + x + "   y: " + y + "  i: " + i + " string_length: " + string_length + "  block_width: " + block_width);
      tell_room(room, "setting position " + i + " to " + i);
      __block_positions[i] = i;
    }
  }
}


varargs string * show_panther(int show_grid){
  int block_x, block_y, line_no, count, count2, block_line, string_length, i, column, row;
  string entry, * block, * picture, line;
  object room;
  room = find_object_or_load("/realms/lujke/workroom");
  count = sizeof(seal_pic);
//  tell_room(room, "Total lines in picture: " + count);
  
  if ( count<1 ){
    return;  
  }
  picture = ({});
  string_length = strlen(seal_pic[0]);
  count = sizeof(__pic_blocks[0]);
  entry = "";


  for (block_y = 0;block_y < count;block_y++){
    if(block_y%2==1){
      line = "%^B_BLACK%^%^BOLD%^%^WHITE%^";
      for (i=0;i<string_length;i++){
        if ( i%block_width == block_width/2){
          column = (i/block_width)+1;
          line += "%^B_BLUE%^%^BOLD%^%^WHITE%^" + column + "%^B_BLACK%^%^BOLD%^%^WHITE%^";
        } 
        line += "-";
      }  
//      line = "------1-------------2------------3------------4------------5-------";

//        line = "-------------------------------------------------------------------";

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
        line += "%^B_BLACK%^%^BOLD%^%^WHITE%^";
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
  return ({"a", "b"});
//  return picture;
}

void simple_show_panther(){
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
  temp_block = __block_positions[block1];
  __block_positions[block1] = __block_positions[block2];
  __block_positions[block2] = temp_block;
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
      swap_blocks(x*10+ below_y, x*10 +y, toucher, "below it.");
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

mapping query_block_positions(){
  return __block_positions;
}

mapping query_pic_blocks(){
  return __pic_blocks;
}
