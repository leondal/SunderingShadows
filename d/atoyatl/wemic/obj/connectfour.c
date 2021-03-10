#include <std.h>

inherit OBJECT;

int * stacks, * last_move, winner, next_turn;


string display_stacks(object ob);
string showsmall();
string showlarge();
void setup();

void create(){
  int i;
  ::create();
  next_turn = 1;
  stacks = allocate(48);
  for(i=0;i<48;i++) stacks[i] = 0;
  last_move = allocate(48);
  set_id(({"stacks","blocks", "stacks of blocks"}));
  setup();
}

string display_stacks(object ob){
  string result;
  if (ob->query_property("showsmall")){
    return showsmall();
  }
  result = showlarge();
  switch (winner){
  case -1:
    result = "%^BOLD%^%^YELLOW%^Winner:  %^RESET%^%^ORANGE%^Orange%^RESET%^\n" + result; 
    break;
  case 1:
    result = "%^BOLD%^%^YELLOW%^Winner:  %^RESET%^%^GREEN%^Green%^RESET%^\n" + result;
    break;
  default:
    switch(next_turn)
    {
    case -1: 
      result = "Next turn:  %^RESET%^%^ORANGE%^Orange\n%^RESET%^" + result; 
      break;
    case 1:
      result = "Next turn:  %^RESET%^%^GREEN%^Green\n%^RESET%^" + result;
      break;
    }
  }
  return result; 
}

void setup(){
  int i;
  for (i=0;i<48;i++){
    stacks[i] = 0;
  }
  for (i=0;i<48;i++){
    last_move[i] =0;
  }
  winner = 0;
  if (random(2)) next_turn = 1;
  else next_turn = -1;
}

string showlarge(){
  int i, j, k, pos;
  string desc;
  desc = "| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |\n";
  for (i=5;i>=0;i--){
    for (k=0;k<2;k++){
      for (j=0;j<8;j++){
        pos = i*8+j;
        desc += "%^B_BLACK%^|";
        if (stacks[pos]==-1 && k %2 ==0) desc += "%^B_ORANGE%^   ";
        if (stacks[pos]==-1 && k %2 ==1) desc += "%^B_ORANGE%^___";
        if (stacks[pos]==1 && k %2 ==0) desc += "%^B_GREEN%^   ";
        if (stacks[pos]==1 && k %2 ==1) desc += "%^B_GREEN%^___";
        if (stacks[pos]==0) desc += "   ";
      }
      desc += "%^B_BLACK%^|\n";
    } 
  }
  return desc;
}

string showsmall(){
  int i, j, pos;
  string desc;
  desc = "|1 |2 |3 |4 |5 |6 |7 |8 |\n";
  for (i=5;i>=0;i--){
    for (j=0;j<8;j++){
      pos = i*8+j;
      desc += "%^B_BLACK%^|";
      if (stacks[pos]==-1) desc += "%^B_ORANGE%^  ";
      if (stacks[pos]==1) desc += "%^B_GREEN%^  ";
      if (stacks[pos]==0) desc += "  ";
    }
    desc += "%^B_BLACK%^|\n";
  }
  return desc;
}

int query_winner(){
  return winner;
}

int set_winner(int i){
  winner = i;
}

int stack_block(int row, int colour){
  int i;
  if (winner) 
  {
    return -2;
  }
  if (next_turn != colour)
  {
    switch(next_turn)
    {
    case 1:
      tell_object(TP, "It is %^GREEN%^green's %^RESET%^turn next!");
      break;
    case -1:
      tell_object(TP, "It is %^ORANGE%^orange's %^RESET%^turn next!");
      break;
    }
    return -3;
  }  
  for (i=0;i<6;i++){
    if (stacks[(i*8)+row-1]==0){
      stacks[(i*8)+row-1]= colour;
      report("Adding stack to location: " + ((i*8)+row-1));
      if (check_for_lines((i*8)+row-1)==1)
      {
        return 2;
      }
      next_turn = next_turn * -1;
      return 1;
    }
  } 
  return -1;
}


int check_for_lines(int loc){
  if (check_for_line(loc, 1) == 1) return 1;
  if (check_for_line(loc, 7) == 1) return 1;
  if (check_for_line(loc, 8) == 1) return 1;
  if (check_for_line(loc, 9) == 1) return 1;
  if (check_for_line(loc, -1) == 1) return 1;
  if (check_for_line(loc, -7) == 1) return 1;
  if (check_for_line(loc, -8) == 1) return 1;
  if (check_for_line(loc, -9) == 1) return 1;
  return 0;
}

int query_stack_contents(int column, int row){
  int loc;
  loc = column * 8 + row;
  if (loc<0) return -100000;
  if (loc > 47) return 100000;
  return stacks[loc];
}

int do_points_cross_line (int start_point, int end_point, int dir){
  if (end_point >47|| end_point < 0) return 1;
  switch(dir){
  case 1:
  case -1:
    if (start_point/8 != end_point/8) return 1; 
    break;
  case 7:
    if (start_point % 8 == 0) return 1;
    break;
  case -7:
    if (start_point % 8 == 7) return 1;
    break;
  case 9:
    if (start_point % 8 == 7) return 1;
    break;
  case -9:
    if (start_point % 8 == 0) return 1;
    break;
  }
}

int check_for_line(int loc, int adjust){
  int * points, colour, nextloc, nextcol, point;
  points = ({loc});
  colour = stacks[loc];
  if (colour ==0) return 0;
  nextcol = colour;
  nextloc = loc;
  while (nextcol == colour && nextloc>=0 && nextloc <= 47 )
  {
    report("Checking whether line continues from position " +nextloc + " in direction " + adjust); 
    if (member_array(nextloc, points) == -1) { report ("Colours match"); points += ({nextloc}); }
    if (do_points_cross_line(nextloc, nextloc + adjust, adjust))
    { 
      report ("line crossed at nextloc: " + nextloc + " adjust: " + adjust);
      break;
    }
    nextloc += adjust;
    if (nextloc <0 || nextloc >47) { report("nextloc (" + nextloc + ") is outside of stacks"); nextcol = 5;}
    if (nextloc >=0 && nextloc <sizeof(stacks)) nextcol = stacks[nextloc];
  }
  if (sizeof(points)>=4){
    return 1;
  }
  nextloc = loc;
  if (nextloc >63 || nextloc <0) return -1;
  nextcol = stacks[loc];
  while (nextcol == colour && nextloc>=0 && nextloc <= 47)
  {
    if (do_points_cross_line(nextloc, nextloc - adjust, (adjust * -1))) break;
    if (member_array(nextloc, points) == -1) points += ({nextloc});
    nextloc -= adjust;
    if (nextloc <0 || nextloc >47) { report("nextloc (" + nextloc + ") is outside of stacks"); nextcol = 5;}
    else nextcol = stacks[nextloc];
    report("Number of points: " + sizeof(points));
  }
  report ("Points in line from " + nextloc + " in direction: "+ adjust + ": ");
  foreach(point in points) { report ("" + point);}
  if (sizeof(points)>=4){
    return 1;
  }
  return 0;
}

void report(string str){
  "/daemon/reporter_d"->report("lujke", str);
}
