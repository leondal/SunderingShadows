#include <std.h>
#include "/daemon/climbing/climb_pics.h"
#define L_HAND 0
#define R_HAND 1
#define L_LEG 2
#define R_LEG 3
#define BODY 4
#define RELEASED -1
inherit DAEMON;

string * wall;
string * handholds;
string * base_handholds;
string * handhold_challenge;
string * handhold_strength;
string * wall_colours;
string * bg_colours;
string * temp_colours;
string * temp_bg;
string * hangers;
string reportee;
int * report_nums, unreport;
mixed * swings;
mapping climbers; // ([ string name: ({int l_hand, r_hand, l_foot, r_foot, body}) ]);
mapping climb_grips; // ([ string name: ({int lh_grip, rh_grip, lf_grip, rf_grip}) ])
int ground_level;
object current_room;


void create(){
  ::create();
  unreport = 0;
  wall = ({

" oooooooooooooooooo",
" oooooooooooooooooo",
" oooooooooooooooooo",
" oooooooooooooooooo",
" oooooooooooooooooo",
" oooooooooooooooooo",
" oooooooooooooooooo",
" oooooooooooooooooo",
" oooooooooooooooooo",
" oooooooooooooooooo",
" oooooooooooooooooo",
" oooooooooooooooooo" 
});
  wall_colours = wall;
  bg_colours = wall;
  handholds = ({
" __________________",
" __________________",
" __________________",
" __________________",
" __________________",
" __________________",
" __________________",
" __________________",
" __________________",
" __________________",
" __________________",
" __________________" 
});
  handhold_challenge = handholds;
  handhold_strength = handholds;
  ground_level = sizeof(wall)-1;
  hangers = ({});
  report_nums = ({});
}

void set_unreport(int u){
  unreport = u;
}

int query_unreport(){
  return unreport;
}

object query_current_room(){
  return current_room;
}

void set_current_room(object r){
  current_room = r;
}

int move_me(string name, int x_dist, int y_dist){
  int * limbs, limb, * newpos, i;
  newpos = ({});
  limbs = query_positions(name);
  if (sizeof(limbs)<1) return -1;
  for(i=0;i<sizeof(limbs);i++)
  {
    newpos += ({limbs[i]+ y_dist * 10000 + x_dist});
  }
  climbers[name] = newpos;
}

mixed * query_swings(){
  return swings;
}

void set_swings(mixed * s){
  swings = s;
}

int get_nearest_hand(string name, int loc){
  int * limbs, x, l_dist, r_dist, l_pos, r_pos;
  limbs = query_positions(name);
  l_pos = limbs[BODY];
  r_pos = l_pos + 4;
  x = loc % 10000;
  report("loc: " + loc + " left hand position: " + limbs[L_HAND] + " right hand position: " + limbs[R_HAND], 7);
  l_dist = x - l_pos % 10000;
  if (l_dist < 0) l_dist = l_dist * -1;
  r_dist = x - r_pos % 10000;
  if (r_dist < 0) r_dist = r_dist * -1;
  report("Get nearest hand. l_dist: " + l_dist + " r_dist: " + r_dist, 7);
  if (r_dist<l_dist) return R_HAND;
  return L_HAND;
}




int jump_me(object ob, string direction){
  int handhold_location, x, y, * limbs, bod_x, bod_y, distance, y_dist, x_dist, limb, grip_strength, hold_type, bod_location;
  string side, hold_descrip;
  object room;
  if (!objectp(ob)) return -1;
  room = environment(ob);
  if (!objectp(room)) return -2;
  handhold_location = get_jumpable_handhold(ob->query_name(), direction);
  report("Trying to jump to location: " + handhold_location + " Handhold type = " + query_handhold(handhold_location));
  if (handhold_location <1) 
  {
    return -3;
  } 
  x = handhold_location % 10000;
  y = handhold_location / 10000;
  limbs = query_positions(ob->query_name());
  if (limbs[L_LEG]==-1 && limbs[R_LEG] ==-1 && direction != "down") return -4;
  bod_x = limbs[BODY] % 10000;
  bod_y = limbs[BODY] / 10000;
  x_dist = bod_x - x;
  if (x_dist<0) x_dist = x_dist *-1;
  y_dist = bod_y - y;
  if (y_dist<0) y_dist = y_dist *-1;
  distance = x_dist;
  if (distance< y_dist) distance = y_dist;
  distance -= 4;
  if (distance < 1) distance = 1;
  report ("Jump distance: " + distance);
  hold_type = query_handhold(handhold_location);
  if (!intp(hold_type)) hold_type = atoi(hold_type);
  report("%^BOLD%^%^CYAN%^Hold type: " + hold_type);
  if (bod_y > y -1)
  {
    report("Target handhold too high to jump to with a leg");
    if (direction == "right"){
      limb = R_HAND;
      bod_location = handhold_location -1;
      report ("%^BOLD%^%^MAGENTA%^Attempting to grab with right hand. Bod_location: " + bod_location);
    }
    else
    {
      report("Direction is not 'right'", 7);
      if (direction == "up")
      {
        report("Direction is up. Checking for nearest hand. Name: " + ob->query_name() + " handhold_location: " + handhold_location, 7);
        limb = get_nearest_hand(ob->query_name(), handhold_location);
      }
      else limb = L_HAND;
      report("imb: " + limb , 7);
      bod_location = handhold_location;
      report ("%^BOLD%^%^YELLOW%^Attempting to grab with a hand. Bod_location: " + bod_location + " limb: " + limb);
    }
    hold_descrip = get_handhold_name(handhold_location);
    hold_descrip += " " + get_handhold_description(handhold_location);
    report ("Hold description: " + hold_descrip);
  } else 
  {
    if (hold_type == LEDGE)  
    {
      report ("Trying to jump to a ledge with a leg Hold type: " + hold_type);
      if (direction == "right")
      {
        limb = R_LEG;
        bod_location = handhold_location +20001;
        report ("%^BOLD%^%^CYAN%^Attempting to land with right leg. Bod_location: " + bod_location);
      }
      else
      {
        limb = L_LEG;
        bod_location = handhold_location +19999;
        report ("%^BOLD%^%^CYAN%^Attempting to land with left leg. Bod_location: " + bod_location);
      }   
      hold_descrip = get_foothold_name(handhold_location);
      report("Foothold hold_descrip, attempt 1:" + hold_descrip);
      hold_descrip += " " + get_foothold_description(handhold_location);
      report("Foothold hold_descrip, attempt 2:" + hold_descrip);
    } else 
    {
      report ("Trying to grab a non ledge with a hand. Hold type: " + hold_type);
      if (direction == "right")
      {
        bod_location = handhold_location -4;
        limb = R_HAND;
        report ("%^BOLD%^%^MAGENTA%^Attempting to grab with right hand. Bod_location: " + bod_location);
      }  else
      {
        limb = L_HAND;
        bod_location = handhold_location +2;
        report ("%^BOLD%^%^MAGENTA%^Attempting to grab with left hand. Bod_location: " + bod_location);

      }
      hold_descrip = get_handhold_name(handhold_location);
      report("First attempt at hold description: " + hold_descrip);
      hold_descrip += " " + get_handhold_description(handhold_location);
      report("Second attempt at hold description: " + hold_descrip);
    }
  }
  grip_strength = do_grip_strength(ob->query_name(), limb, handhold_location, room , distance * distance/2);
  report ("Grip strength acheived: " + grip_strength );
  if (direction == "right" || direction == "left") direction = "to the " + direction;
  tell_object (ob, "You leap " + direction );
  limbs[BODY] = bod_location;
  if (!ob->query_true_invis()) tell_room(room, ob->QCN + " jumps " + direction, ob);
  if (grip_strength < 2)
  {
    //do fall
    tell_object (ob, "As you sail through the air, you aim for " + hold_descrip + ", but you miss it completely and fall off the wall!");
    if (!ob->query_true_invis()) tell_room(room, "As " + ob->QCN + " sails through the air, " + ob->QS + " passes by " + hold_descrip + ", missing it completely. " + capitalize(ob->QS) + " falls off the wall!", TP);
    return 0;
  } else 
  { 
    if (grip_strength>5 && (direction == "left" || direction == "right")) //If they made the jump easily, allow them to make the landing with their rear leg rather than the front one.
    {                    //In many cases, this will make it easier to land the other foot on a ledge, for example.
      
      switch(limb)
      {
      case L_LEG:
        limb = R_LEG;
        break;
      case R_LEG:
        limb = L_LEG;
        break;
      }
    }
   
    tell_object (ob, "As you sail through the air, you aim for " + hold_descrip + ".");
    limbs[BODY]=bod_location;
    if (!ob->query_true_invis()) tell_room(room, "As " + ob->QCN + " sails through the air, " + ob->QS + " aims for " + hold_descrip + ".", ob);
    switch(limb)
    {
    case L_HAND:
      tell_object(ob, "\nYou manage to lock onto the handhold with one hand, establishing a " + query_grip_strength_adjective(grip_strength) + " grip!");
      if (!ob->query_true_invis())tell_room(ob->QCN + "manages to lock onto the handhold with one hand, arresting " + ob->QP + " fall");
      limbs = ({-1,-1,-1,-1,handhold_location + 2});
      limbs [limb] = handhold_location;
      climbers[ob->query_name()] = limbs; 
      shift_body(ob->query_name(), 4);
      shift_body(ob->query_name(), 4);
      shift_body(ob->query_name(), 4);
      break;
    case R_HAND: 
      tell_object(ob, "\nYou manage to lock onto the handhold with one hand, establishing a " + query_grip_strength_adjective(grip_strength) + " grip!");
      if (!ob->query_true_invis())tell_room(ob->QCN + "manages to lock onto the handhold with one hand, arresting " + ob->QP + " fall");
      limbs = ({-1,-1,-1,-1,handhold_location -4});
      limbs [limb] = handhold_location;
      climbers[ob->query_name()] = limbs; 
      shift_body(ob->query_name(), 4);
      shift_body(ob->query_name(), 4);
      shift_body(ob->query_name(), 4);
      //blah
      break;
    case L_LEG:
      tell_object(ob, "\nYou manage to land on the ledge with one foot, establishing a " + query_grip_strength_adjective(grip_strength) + " foothold!");
      if (!ob->query_true_invis())tell_room(ob->QCN + "manages to land one foot on a ledge, balancing there " );
      limbs = ({-1,-1,-1,-1,handhold_location -20000 +2});
      limbs [limb] = handhold_location;
      while(limbs[BODY]<0) limbs[BODY] = limbs[BODY] + 10000;
      climbers[ob->query_name()] = limbs;
      shift_body(ob->query_name(), 0);
      shift_body(ob->query_name(), 0);
      shift_body(ob->query_name(), 0);
      break;
    case R_LEG:
      tell_object(ob, "\nYou manage to land on the ledge with one foot, establishing a " + query_grip_strength_adjective(grip_strength) + " foothold!");
      if (!ob->query_true_invis())tell_room(ob->QCN + "manages to land one foot on a ledge, balancing there " );
      limbs = ({-1,-1,-1,-1,handhold_location -20000 -3});
      limbs [limb] = handhold_location;
      while(limbs[BODY]<0) limbs[BODY] = limbs[BODY] + 10000;
      climbers[ob->query_name()] = limbs;
      shift_body(ob->query_name(), 0);
      shift_body(ob->query_name(), 0);
      shift_body(ob->query_name(), 0);
      break;
    }
    if (grip_strength>2 ) //If they made the jump easily, allow them to make the landing with their rear leg rather than the front one.
    {                    //In many cases, this will make it easier to land the other foot on a ledge, for example.
      report("Second limb catching opportunity", 7);
      if (catch_second_limb(ob->query_name())) report ("Second limb caught", 7);
      else report("Second limb not caught", 7);
    } else report ("Grip not strong enough to catch a secnod limb. Grip strength: " + grip_strength, 7);
  }  
  return 1;
}

int catch_second_limb(string name){
  string line, ch;
  int * limbs, limb, x, y, top, bottom, left, right, loc, count;
  count = 0;
  report ("second limb 1", 8);
  limbs = query_positions(name);
  foreach(limb in limbs)
  {
    if (limb>-1) count ++;
    report ("second limb 2. Count: " + count, 8);
    if (count >2) return 0;
  }
  loc = limbs[BODY];
  report ("second limb 3. loc:" + loc);
  if(limbs[L_HAND]>=0)
  {
    report ("second limb 3. Checking left hand", 8);
    //bleh
    limb = R_HAND;
    top = loc / 10000 -4;
    left = loc % 10000;
    right = left + 8;
    bottom = top + 5;
    for (y = top; y<= bottom; y++)
    {
      report ("second limb 4. y: " + y);
      if (y<0 || y > sizeof(handholds)-1) continue;
      line = handholds[y];
      for( x = left; x <= right; x ++)
      {
        if (x>= strlen(line)) continue;
        ch = line[x..x];
        if (ch != " " && is_valid_limb_position(name, limb, x,y)>0 )
        { 
          return finish_catching(name, limb, y * 10000 + x);
        }
      }
    }
  }
  if(limbs[R_HAND]>=0)
  {
    report ("second limb 5. Checking left hand", 8);
    //bleh
    limb = L_HAND;
    top = loc / 10000 -4;
    left = loc % 10000 -6;
    right = left + 8;
    bottom = top + 5;
    for (y = top; y<= bottom; y++)
    {
      report ("second limb 6. y: " + y);
      if (y<0 || y > sizeof(handholds)-1) continue;
      line = handholds[y];
      for( x = left; x <= right; x ++)
      {
        if (x>= strlen(line)) continue;
        ch = line[x..x];
        if (ch != " " && is_valid_limb_position(name, limb, x,y)>0 )
        { 
          return finish_catching(name, limb, y * 10000 + x);
        }
      }
    }
  }
}

int finish_catching(string name, int limb, int loc ){
  int * limbs;
  limbs = query_positions(name);
  limbs[limb] = loc;
  climbers[name] = limbs;
  return 1;
}

string describe_location_height(int loc){
  string result;
  int y, feet;
  y =loc /10000;
  feet = sizeof(wall) - y;
  switch (feet)
  {
  case 0:
    result = "at ground level";
    break;
  case 1:
    result = "" + feet + " foot above the ground";
    break;
  default:
    result = "" + feet + " feet above the ground";
    break;
  }
  return result;
}

int query_base_handhold(int loc){
  string line, ch;
  int x, y;
  x = loc %10000;
  y = loc / 10000;
  line = base_handholds[y];
  ch = line[x..x];
  return atoi(ch);
}

string describe_location_lattitude(int loc){
  string result;
  int feet, right_end, half;
  half = loc % 10000%2;
  feet =loc % 10000/2;
  right_end = strlen(wall[0]);
  report ("RIght end: " + right_end);
  result = "nowhere";
  if (feet ==0) result = "at the left end of the wall";
  if (feet == right_end) result = "at the right end of the wall";    
  if (feet ==1 && !half) return "one foot from the left end of the wall";
  if (result == "nowhere")
  {
    if (feet*2 <= right_end/2)
    {
      result = "" + feet;
      if (half) result += " and a half";
      result += " feet from the left end of the wall";
    } else
    {
      if (half)
      {
        result = "" + (feet-1) + " and a half";
      } else result = "" + feet;
      result += " feet from the right end of the wall";
    }
  }
  return result;
}

mapping get_handhold_descriptions(string name){
  int * limbs, limb, i;
  mapping m;
  string desc, limb_name;
  limbs = query_positions(name);
  m = ([]);
  for(i=0;i<sizeof(limbs);i++)
  {
    switch(i)
    {
    case L_LEG:
      limb_name = "left leg";
      break;
    case R_LEG:
      limb_name = "right leg";
      break;
    case L_HAND:
      limb_name = "left hand";
      break;
    case R_HAND:
      limb_name = "right leg";
      break;
    }
    if (limbs[i] <0)
    {
      switch(i)
      {
      case L_LEG:
      case R_LEG:
        desc = " does not have a foothold";
        break;
      case L_HAND:
      case R_HAND:
        desc = " is not holding anything";
        break;
      }
    } else desc = get_handhold_and_location_description(limbs[limb], i);
    if (limbs[i] / 10000 >= sizeof(wall)-1) desc = " is on the ground";
    m[limb_name] = desc;  
  }
}

string describe_all_handholds(object who){
  string name, limb, * limbs;
  if (!objectp(who)) return "error with 'who' in describe_all_handholds in vis_climb_d - please use the game command to make a bug report stating this";
    
}

string get_handhold_and_location_description(int loc, int limb){
  string handhold_name, handhold_description, height_description, lattitude_description;
  switch(limb)
  {
  case L_LEG:
  case R_LEG:
    handhold_name = get_foothold_name(loc);
    handhold_description = get_foothold_description(loc);
    break;
  case R_HAND:
  case L_HAND:
    handhold_name = get_handhold_name(loc);
    handhold_description = get_handhold_description(loc);
    break;
  }
  height_description = describe_location_height(loc);
  lattitude_description = describe_location_lattitude(loc);
  return handhold_name + " " + handhold_description + ", which is " + height_description + " and " + lattitude_description;
}

void set_grip(string name, int limb, int grip){
  string * cs;
  int * grips;
  if (!mapp(climb_grips) || sizeof(climb_grips)<1)
  {
    climb_grips = ([]);
    grips = ({-1, -1, -1, -1, -1});
  }  else 
  {
    cs = keys(climb_grips);
    if (member_array(name, cs) == -1) grips = ({-1, -1, -1, -1, -1});
    else grips = climb_grips[name];
  }
  grips[limb] = grip;
  climb_grips[name] = grips;
}

int release(string name, int limb){
  int * positions;
  string * cs;
  if (!mapp(climbers) || sizeof(climbers)<1) return 0;
  cs = keys(climbers);
  if (member_array(name, cs) ==-1) return -1;
  positions = climbers[name];
  positions[limb] = -1;
}

int set_climbers(mapping cs){
  climbers = cs;
  return 1;
}

string * query_handholds(){
  return handholds;
}

void set_handholds(string * h){
  handholds = h;
}

string * query_handhold_challenge(){
  return handhold_challenge;
}

void set_handhold_challenge(string * h){
  handhold_challenge = h;
}

string * query_handhold_strength(){
  return handhold_strength;
}

void set_handhold_strength(string * h){
  handhold_strength = h;
}

string * query_wall_colours(){
  return wall_colours;
}

mapping query_climb_grips(){
  return climb_grips;
}

void set_climb_grips(mapping cg){
  climb_grips = cg;
}

void set_wall_colours(string * cols){
  string line;
  wall_colours = ({});
  if (sizeof(cols)<1) return;
  foreach(line in cols)
  {
    wall_colours += ({line});
  }
  report ("Wall colours set. Number of lines: " + sizeof(wall_colours));
}

void set_bg_colours(string * bg_cols){
  string line;
  bg_colours = ({});
  if (sizeof(bg_cols)<1) return;
  foreach(line in bg_cols)
  {
    bg_colours += ({line});
  }
}

int query_grip (string name, int limb){
  string * cs;
  int * grips, grip_count;
  if (!mapp(climb_grips)  || sizeof(climb_grips)<1)
  {
    report("There are no climb grips avaialable to return when querying a " + name + "'s grip on limb no " + limb);
    return -2;
  }
  cs = keys(climb_grips);
  if (member_array(name, cs)==-1)
  {
    report("There are no climb grips recorded for " + name + " when querying their grip on limb no " + limb);
    return -3;
  }
  grips = climb_grips[name];
  grip_count = sizeof(grips);
  if (grip_count<= limb)
  {
    report ("Trying to query grip for climber " + name + " on limb number " + limb + ". Only " + grip_count + " grips are recorded.");
    return -4;
  }
  return grips[limb];
}

string query_grip_strength_adjective(int grip_strength){
  switch(grip_strength)
  {
  case 0:
    return "no";
    break;
  case 1:
    return "precarious";
    break;
  case 2: 
    return "unsteady";
    break;
  case 3:
    return "slightly insecure";
    break;
  case 4:
    return "reasonably steady";
    break;
  case 5: 
    return "firm";
    break;
  case 6:
    return "very steady";
    break;
  case 7:
    return "completely reliable";
    break;
  }
}

string query_grip_description(string name, int limb){
  //a good/bad/indifferent grip on a ledge/crimp/jug/etc hand/foothold
  string quality, hold_type, limb_type, side, *cs, hold_char, result;
  int hold_strength, * grips, * limbs, x, y, hold_no;
  switch(limb)
  {
  case 0: 
    limb_type = "hand";
    side = "left";
    break;
  case 1:
    limb_type = "hand";
    side = "right";
    break;
  case 2:
    limb_type = "foot";
    side = "left";
    break; 
  case 3:
    limb_type = "foot";
    side = "right";
    break;
  }  
  if (!mapp(climb_grips) || sizeof(climb_grips)< 1) return "There has been an error deriving your climbing grip description. Throw something at Lujke";
  cs = keys(climb_grips);
  if (member_array(name, cs == -1)) return "There has been an error deriving your climbing grip description. Throw something pointy at Lujke";
  grips = climb_grips[name];
  hold_strength = limbs[limb];
  if (!mapp(climbers) || sizeof(climbers)< 1) return "There has been an error deriving your climbing grip description. Throw something blunt and heavy at Lujke";
  cs = keys(climbers);
  if (member_array(name, cs == -1)) return "There has been an error deriving your climbing grip description. Throw something with floral scenting at Lujke";
  limbs = climbers[name];
  hold_char = query_handhold(limbs[limb]);
  hold_type =  query_hold_descrip(hold_char);
  quality = query_grip_strength_adjective(hold_strength);
  switch(limb_type)
  {
  case "hand":
    result = "a " + quality + " grip on a " + hold_type + " " + limb_type + "hold with their " + side + " " + limb_type;  
    break;
  case "foot":
    result = "a " + quality + " footrest on a " + hold_type + " with their " + side + " " + limb_type;  
    break;
  }
}


int is_handhold_free(int handhold){
  string * cs, climber;
  int * limbs;
  if (!mapp(climbers) || sizeof(climbers)<1 ) return 1;
  cs = keys(climbers);
  foreach(climber in cs)
  {
    limbs = climbers[climber];
    if (member_array(handhold, limbs)!= -1) return 0;
  }
  return 1;
}

string * query_wall(){
  return wall;
}

int set_wall(string * w){
  string line;
  wall = ({});
  foreach(line in w)
  {
    wall += ({line});
  }  
  ground_level = sizeof(wall)-1;
  return 1;
}

string query_handhold(int location){
  int x, y;
  string line, result;
  result = "error";
  if (!intp(location)) location = atoi(location);
  x = location % 10000;
  y = location  / 10000;
  if (y>-1 && y<sizeof(handholds))
  {
    line = handholds[y];
    if (x<strlen(line))
    {
      result = line [x..x];
    }
  }
  return result;
}

object get_player(string name){
  object * obs, ob;
  obs = children("/std/user.c");
  if (sizeof(obs)<1) return;
  foreach(ob in obs)
  {
    if (objectp(ob) && ob->query_name() == lower_case(name)) break;
  }
  if (!objectp(ob)) return 0;
  return ob;
}

void show_wall_to_name(string name){
  object ob;
  report("%^B_CYAN%^Showing wall to name: " + name);
  if (unreport ==1) return;
  ob = get_player(name);
  if (!objectp(ob)){
    report ("%^BOLD%^%^YELLOW%^Couldn't find player!");
    return 0;  
  }
  report ("About to show_wall");
  show_wall(ob);
}

int * query_positions(string climber){
  string * cs;
  int * positions;
  cs = keys(climbers);
  if (member_array(climber, cs) ==-1) return -1;
  positions = climbers[climber];
  return positions;
}

string * add_climber_to_wall(string name, string * wall){
  string * climber_pic, * names, * mywall, line;
  int position, * positions, x, y, i, * limbs;
  object ob;
  mywall = wall;
  if (sizeof(climbers)<1) return mywall;
  names = keys(climbers);
  if (member_array(name, names)==-1) return mywall;
  ob = get_player(name);
  if (!objectp(ob))  return mywall;
  report("%^BOLD%^%^CYAN%^add_climber_to_wall 1. Name: " + name);
  report_limb_positions();
  climber_pic = get_medium_climber_pic(ob);
  positions = query_positions(ob->query_name());
  report("%^BOLD%^%^CYAN%^add_climber_to_wall 2. Name: " + name);
  report_limb_positions();
//  report ("Positions found: " + positions);
  position = positions[4];
  x = position % 10000;
  x -=4;
  y = position / 10000;
  y -=3;
  if (ob->query_property("swinging")==2) x+= 3;
  report("%^BOLD%^%^CYAN%^add_climber_to_wall 3. Name: " + name);
  report_limb_positions();
  if (is_dangling(name))
  {
    report("%^BOLD%^%^GREEN%^IS DANGLING");
    limbs = query_positions(name);
    if (sizeof(limbs)>0)
    {
      if (limbs[L_HAND]==-1) x+= 2;
//      else report("%^BOLD%^%^RED%^Limbs[R_HAND] != -1");
    }
//    else x += 4; //report("%^BOLD%^%^BLUE%^NOT POINTERP LIMBS");
  } else report("%^BOLD%^%^RED%^NOT DANGLING");
  mywall = add_pic_to_wall(climber_pic, mywall, x, y);
  report("Climber added. New size of wall: " + sizeof(mywall));
  report("%^BOLD%^%^CYAN%^add_climber_to_wall 4. Name: " + name);
  report_limb_positions();
  return mywall;
}

void report_limb_positions(){
  int * limbs;
  string * cs;
  cs = ({});
  if (mapp(climbers) && sizeof(climbers)>0) cs = keys(climbers);
  if (sizeof (cs)>0 && member_array("lujke", cs)!=-1)
  {
    limbs = climbers["lujke"];
    report("l hand pos: " + limbs[0] + " r hand pos: " + limbs[1] + " l leg: " + limbs[2] + " r leg: " + limbs[3] + " body: " + limbs[4]); 
  }
}


int is_handhold(int x, int y){
  string current_handhold, handhold_above, line;
  int i;
  if (y==ground_level)
  {
    report ("Handhold checked is at ground level. Automatically works");
    return 1;
  }
  if (sizeof(handholds)> y)
  {
    line = handholds[y];
    report ("line examined: '" + line + "'");
  } else 
  {
    report ("y (" + y + ") is larger than size of handholds (" + sizeof(handholds) + ")");
    return -1;
  }
  if (strlen(line) > x){
    current_handhold = line[x..x];
    handhold_above = " ";
    if(y>0) handhold_above = handholds[y-1][x..x];
    report ("Character examined at x=" + x + ", y=" + y + " : '" + current_handhold + "'"); 
  } else 
  {
    report ("x (" + x + ") is larger than length of line (" + strlen(line) + ")");
    return 0;
  }
  if (atoi(current_handhold)<1 ||atoi(current_handhold)>9)return 0;

  return 1;
}

varargs int do_grip_strength(int name, int limb, int location, object room, penalty){
  int grip_strength, * grips;
  string * cs;
  cs = keys(climb_grips);
  if (member_array(name, cs)==-1)
  {
    grips = ({0,0,0,0});
  } else
  {
    grips = climb_grips[name];
  }
  grip_strength = calculate_grip_strength(name, location, room, penalty);
  grips[limb] = grip_strength;
  climb_grips[name] = grips;
  return grip_strength; // 
}

string query_line(int line_no){
  line_no = line_no /10000;
  report ("Size of wall: " + sizeof(wall));
  report ("Line number sought: " + line_no);
  if (line_no<sizeof(wall)) return wall[line_no];
  return "error";  
}

int move_right_hand_up(string name){
  return move_limb_up(name, R_HAND);
}

int move_right_hand_down(string name){
  return move_limb_down(name, R_HAND);
}

int move_right_hand_right(string name){
  return move_limb_right(name, R_HAND);
}

int move_right_hand_left(string name){
  return move_limb_left(name, R_HAND);
}


int move_left_hand_up(string name){
  return move_limb_up(name, L_HAND);
}
int move_left_hand_down(string name){
  return move_limb_down(name, L_HAND);
}
int move_left_hand_right(string name){
  return move_limb_right(name, L_HAND);
}
int move_left_hand_left(string name){
  return move_limb_left(name, L_HAND);
}

int move_left_leg_up(string name){
  return move_limb_up(name, L_LEG);
}
int move_left_leg_down(string name){
  return move_limb_down(name, L_LEG);
}
int move_left_leg_right(string name){
  return move_limb_right(name, L_LEG);
}
int move_left_leg_left(string name){
  return move_limb_left(name, L_LEG);
}

int move_right_leg_up(string name){
  return move_limb_up(name, R_LEG);
}
int move_right_leg_down(string name){
  return move_limb_down(name, R_LEG);
}
int move_right_leg_right(string name){
  return move_limb_right(name, R_LEG);
}
int move_right_leg_left(string name){
  return move_limb_left(name, R_LEG);
}


int is_hanging(string name){
  string * cs;
  int * limbs;
  if (!mapp(climbers)|| sizeof(climbers)<1) return 0;
  cs = keys(climbers);
  if (member_array(name, cs) ==-1) return 0;
  limbs = climbers[name];
  if (sizeof(limbs)<4) return 0;
  if (limbs[L_LEG] == -1 && limbs[R_LEG]==-1) return 1;
  return 0;
}

int is_balancing(string name){
  string * cs;
  int * limbs;
  if (!mapp(climbers)|| sizeof(climbers)<1) return 0;
  cs = keys(climbers);
  if (member_array(name, cs) ==-1) return 0;
  limbs = climbers[name];
  if (sizeof(limbs)<4) return 0;
  if (limbs[L_HAND] == -1 && limbs[R_HAND]==-1) return 1;
  return 0;
}

int is_dangling(string name){
  string * cs;
  int * limbs;
  if (!mapp(climbers)|| sizeof(climbers)<1) return 0;
  cs = keys(climbers);
  if (member_array(name, cs) ==-1) return 0;
  limbs = climbers[name];
  if (sizeof(limbs)<4) return 0;
  if (limbs[L_LEG] == -1 && limbs[R_LEG]==-1)
  {
    if (limbs[R_HAND] == -1) 
    {
      if (limbs[L_HAND] !=-1)
      limbs[BODY] = limbs[L_HAND] + 30000 ;
      return 1;
    }
    if (limbs[L_HAND] ==-1)
    {
      if (limbs[R_HAND] !=-1)
      limbs[BODY] = limbs[R_HAND] + 30000 -4;
      return 1;
    }
  }
  return 0;
}


int shift_body_down(string name){
  string * cs;
  int * limbs, bod_pos, lh_pos, rh_pos, flag, i;
  if (!mapp(climbers)|| sizeof(climbers)<1) return;
  cs = keys(climbers); 
  if (member_array(name, cs) ==-1) return 0;
  limbs = climbers[name];
  if (sizeof(limbs)<5) return 0;
  bod_pos = limbs[BODY];
  lh_pos = limbs[L_HAND];
  rh_pos = limbs[R_HAND];
 
  limbs[BODY] = limbs[BODY] +10000;
  climbers[name] = limbs;
  flag = 0;
  for (i=0; i<4;i++)
  {
    report ("%^BOLD%^%^CYAN%^shift body down, iteration " + i + " checking whether limbs are valid", 4);
    if (is_valid_limb_position(name, L_HAND, lh_pos % 10000, lh_pos/10000)>0 && is_valid_limb_position(name, R_HAND, rh_pos % 10000, rh_pos/10000)>0 ) 
    {
      report ("%^BOLD%^%^GREEN%^limbs are valid!", 4);
      flag ++;
    } else
    {
      report ("%^RED%^limbs are NOT valid!", 4);
      break;
    }
  }
  if (flag ==0) 
  {
    limbs[BODY] = limbs[BODY]-10000;
    climbers[name] = limbs;
    return 0;
  }
  if (flag < 4)
  {
    limbs[BODY] = limbs[BODY]-10000;
    climbers[name] = limbs;
    return 1;
  }
  return 1;
}

int can_reach_location(string name, int loc){
  int i, * limbs, * orig_pos, limb, x, y, direction;
  limbs = query_positions(name);
  x = loc % 10000;
  y = loc / 10000;
  orig_pos = ({});
  for (i=0;i<sizeof(limbs);i++)
  {
    orig_pos += ({limbs[i]});
  }  
  report ("Can reach location 1");
  for (limb =0; limb<4; limb ++)
  {
    if (is_valid_limb_position(name, limb,x , y)>0)
    {
      limbs = ({}); //restore limbs to original_position
      for (i=0;i<sizeof(orig_pos);i++)
      {
        limbs += ({orig_pos[i]});
      }  
      climbers[name] = limbs;
      return 1;
    }
  }

  for (direction = 0; direction < 8; direction ++)
  {
    report ("Can reach location 2. Testing direction " + direction);
    limbs = ({}); //restore limbs to original_position
    for(i=0;i<sizeof(orig_pos);i++)
    {
      limbs += ({orig_pos[i]});
    }  

    for(i=0;i<5;i++)
    {
      if (!shift_body(name, direction)) break;  
    }
    for (limb =0; limb<4; limb ++)
    {
      if (is_valid_limb_position(name, limb,x , y)>0)
      {
        report("Found a valid limb position. X: " + x + " Y: " + y + " Limb: " + limb);
        limbs = ({}); //restore limbs to original_position
        for (i=0;i<sizeof(orig_pos);i++)
        {
          limbs += ({orig_pos[i]});
        }
        climbers[name] = limbs;  
        return 1;
      }
    }
  }

 //bleh

  limbs = ({}); //restore limbs to original_position
  for (i=0;i<sizeof(orig_pos);i++)
  {
    limbs += ({orig_pos[i]});
  }  
  climbers[name] = limbs;
  return 0;
}

varargs int move_limb_up(string name, int limb, is_repeat, object room){
  int pos, temp_pos, poss_pos, * positions, x,y, * possible_handholds, i,j, topmost, rightmost, leftmost, midmost, * removed_handholds, distance, bottommost, horiz_mid, vert_mid, result, flag, count, grip_strength;
  string current_handhold, new_handhold;
  positions = query_positions(name);
  result = 1;
  if (sizeof(positions)<1)
  {
    report ("No positions found for " + name + ". Aborting");
    return -1;
  }
  if (positions[limb] !=-1 && count_grips(name)<2)
  {
    report("They are trying to move the only limb they are holding on with");
    tell_object(TP, "You need to have at least one other hand or foothold before you can move this one");
    return -1;
  }
  pos = positions[BODY];
  x = pos % 10000;
  y = pos /10000;
  switch(limb)
  {
  case R_HAND:
    topmost = y -3;
    rightmost = x + 6;
    leftmost = x + 2;
    midmost = x +4;
    if (positions[R_HAND]==-1) bottommost = y-1;
    else bottommost = positions[R_HAND]/10000 -1;
    break;
  case L_HAND:
    topmost = y -3;
    rightmost = x + 2;
    leftmost = x -1;
    midmost = x;
    if (positions[L_HAND]==-1) bottommost = y-1;
    else bottommost = positions[L_HAND]/10000 -1;
    break;
  case R_LEG:
    topmost = y ;
    if (positions[R_LEG]==-1) bottommost = y+3;
    else bottommost = positions[R_LEG]/10000 -1;
    rightmost = x + 6;
    leftmost = x + 2;
    horiz_mid = x +3;
    vert_mid = y +4;
    break;
  case L_LEG:
    topmost = y;
    if (positions[L_LEG]==-1) bottommost = y+3;
    else bottommost = positions[L_LEG]/10000 -1;
    rightmost = x +2;
    leftmost = x - 2;
    horiz_mid = x +1;
    vert_mid = y +4;
    break;
  }
  pos = positions[limb];
  x = pos % 10000;
  y = pos /10000;
  current_handhold = " ";
  if (pos <0 || is_handhold (x,y)<1)
  { 
    report("Position " + (y*10000 + x) + " is not a handhold.");
    pos = positions[BODY];
    pos += 10001;
    x = pos % 10000;
    y = pos /10000;
    switch(limb)
    {
    case L_HAND:
      x --;
      break;
    case R_HAND:
      x++; 
      break;
    case L_LEG:
      x --;
      y+=2;
      break;
    case R_LEG:
      x ++;
      y+=2;
      break;
    }
    report("Resetting position to " + (y*10000 + x));
  }     
  possible_handholds = ({});
  if (topmost>=y){
    report ("y (" + y + ") is higher than topmmost (" + topmost + ")");
    result = -1;
  } else 
  {
    report ("Leftmost: " + leftmost +" Rightmost: "+ rightmost + " Topmost: " + topmost + " Bottommost " + bottommost);
    for (i=topmost;i<y;i++)
    {
      report ("%^BOLD%^%^CYAN%^Checking line %^RESET%^" + i);
      for (j= leftmost;j<=rightmost;j++)
      {
        report ("Checking character " + j);
        if (is_valid_limb_position(name, limb, j, i) <1 )
        {
          report("%^BOLD%^%^YELLOW%^i (" + i +"), j (" +j+ ") is not a valid limb position for limb: " + limb + ". Continuing");
          continue;
        }
        if ( is_a_rope_I_am_carrying(i*10000 +j, name, room))
        {
          if (query_base_handhold(i*10000 +j)<1)
          {
            report("I can't stand on a rope I am carrying");
            continue;
          }
        }
        temp_pos = i*10000 + j;
        possible_handholds += ({temp_pos});
      }
    }
    report ("Found " + sizeof(possible_handholds) + " possible handholds");
    if (sizeof(possible_handholds)<1)
    {    
      report("There are no possible handholds!");
      result = -1;
    } else
    {
      removed_handholds =({});
      foreach(temp_pos in possible_handholds)
      {
        if (is_handhold(temp_pos % 10000, temp_pos/10000)<1)
        {
          report ("Position " + temp_pos + " is not a handhold and needs to be removed");
          removed_handholds += ({temp_pos});
        }
      }  
      report ("Removing " + sizeof(removed_handholds) + " non-handholds");
      if (sizeof(removed_handholds)>0)
      {
        foreach(temp_pos in removed_handholds)
        {
          report ("Removing position " + temp_pos + "from possible handholds");
          possible_handholds -= ({temp_pos}); 
        }
      } 
    }
    if (sizeof(possible_handholds)<1) result = -2;
    else 
    {
      temp_pos = possible_handholds[0];
      distance = calculate_distance(temp_pos, pos);
      report ("First position being checked: " + temp_pos + " Distance from initial position: " + distance);
      //of the remaining possible handholds, choose the one that is closest to the previous handhold
      foreach(poss_pos in possible_handholds)
      {
        if (((limb == L_HAND || limb == L_LEG)&& poss_pos % 10000==rightmost ) || ((limb == R_HAND || limb == R_LEG)&& poss_pos % 10000==leftmost ))
        {
          continue;
        } 
        report ("Next position being checked: " + poss_pos + " Distance from initial position: " + calculate_distance(poss_pos, pos));
        if (calculate_distance(poss_pos, pos)<distance)
        {
          temp_pos = poss_pos;
          distance = calculate_distance(temp_pos, pos);
        }
      }
      report("%^BOLD%^%^YELLOW%^About to do grip strength");
      grip_strength = do_grip_strength(name, limb, temp_pos);
      if (grip_strength<1)
      {
        report("About to report grip failure");
        report_grip_failure(name, limb, temp_pos, room);
        check_grip_failure_on_limb_move(name, limb, room);
        return -10;
      }
      report("%^BOLD%^%^YELLOW%^grip strength done");
      positions[limb] = temp_pos;
    }
  }
  if (result <1 && is_repeat != 1)
  {
    count = 0;
    while(count < 4)
    {
      count ++;
      shift_body(name, 0);
    }
    count = 0;
    while(count < 4)
    {
      count ++;
      shift_body(name, 1);
    }
    count = 0;
    while(count < 4)
    {
      count ++;
      shift_body(name, 7);
    }
    return  move_limb_up(name, limb, 1);
  }
  temp_pos = positions[limb];
//  positions[limb] = -1;
  check_grip_failure_on_limb_move(name, limb, room);
//  positions[limb] = temp_pos;
  if (result >0)
  {
    if (is_hanging(name))
    {
      shift_body_down(name);
    }
    show_wall_to_name(name);
    report_grip_success(name, limb, temp_pos, grip_strength, "up", room);
  }
  return result;
}

varargs int is_a_rope_I_am_carrying(int loc, string name, object room){
  object * ropes, rope, critter;
  int pos, * path, flag;
  flag = 0;
  report("is_a_rope_I_am_carrying 1");
  if (!objectp(room))
  {
    room = new("/realms/lujke/special_rooms/climb_room.c");
    room->download();
    flag = 1;
  }
  if (!objectp(room))
  {
    report("I can't find a valid room");
    return 0;
  }
  if (atoi(query_handhold(loc))!= ROPE){
   report ("Handhold at " + loc + " is not a rope");
   return 0;
  }
  report("is_a_rope_I_am_carrying 2");
  critter = find_player(name);
  if (!objectp(critter) && objectp(room)) critter = present(name, room);
  if (!objectp(critter))
  {
    report("I can't find a critter named " + name);
    return 0;
  }
  ropes = all_present("attached_rope", critter);
  if (sizeof(ropes)<1)
  {
    report ("The critter is not carrying any attached ropes");
    return 0;
  }
  report("is_a_rope_I_am_carrying 3");

  foreach(rope in ropes)
  {
    report("is_a_rope_I_am_carrying 4");
    pos = rope->query_my_pos();
    path = room->find_rope_path(pos);
    if (sizeof(path)>0 && member_array(loc, path)!=-1) return 1;
    report ("Found a rope that it not an attached rope");
  }
  if (flag) room->remove();
  report("is_a_rope_I_am_carrying 5");

  return 0;
}

/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////


int get_post_swing_handhold(int name, string dir){
  int * limbs, top, bottom, left, right, bod_pos, i, j, target, distance, result, loc, y_dist, x_dist;
  limbs = query_positions(name);
  bod_pos = limbs[BODY];
  if (dir == "left")
  {
    right = bod_pos % 10000;
    left = right - 4;
  } else 
  {
    left = bod_pos % 10000 + 1;
    right = left + 3;
  }
  report("Getting post swing handhold. left: "+ left +" right: "+ right +" top: "+ top+" bottom: " + bottom, 10);  
  top = bod_pos/10000 - 3;
  bottom = top + 6;
  target = bod_pos + 4;
  distance = 10000;
  result = 10000000;
  for(i=top;i<bottom+1;i++)
  {
    x_dist = target % 10000 - i;
    if (x_dist < 0) x_dist = x_dist * -1;
    for (j=left;j<right +1;j++)
    {
      loc = i * 10000 + j;
      y_dist = target/10000 - j;
      if (y_dist <0) y_dist = y_dist * -1;
      if (distance <= x_dist + y_dist) continue;
      if (atoi(query_handhold(loc)) == ROPE) continue;
      if (query_handhold(loc) == " ") continue;
      result = loc;
      distance = x_dist + y_dist;
    }
  }
  return result;
}



varargs int move_limb_down(string name, int limb, is_repeat, room){
  int pos, temp_pos, poss_pos, * positions, x,y, * possible_handholds, i,j,topmost, bottommost, rightmost, leftmost, midmost, * removed_handholds, distance, horiz_mid, vert_mid, result, flag, count, grip_strength;
  string current_handhold, new_handhold;
  positions = query_positions(name);
  result = 1;
  if (sizeof(positions)<1)
  {
    report ("No positions found for " + name + ". Aborting");
    return -1;
  }
  if (positions[limb] !=-1 && count_grips(name)<2)
  {
    report("They are trying to move the only limb they are holding on with");
    tell_object(TP, "You need to have at least one other hand or foothold before you can move this one");
    return -1;
  }
  pos = positions[BODY];
  x = pos % 10000;
  y = pos /10000;
  switch(limb)
  {
  case R_HAND:
    if (positions[R_HAND]==-1) topmost = y+1;
    else topmost = positions[R_HAND]/10000 +1;
    topmost = y-3;
    bottommost = y +2;
    rightmost = x + 6;
    leftmost = x + 2;
    midmost = x +4;
    break;
  case L_HAND:
    if (positions[L_HAND]==-1) topmost = y+1;
    else topmost = positions[L_HAND]/10000 +1;
    bottommost = y +2;
    rightmost = x + 2;
    leftmost = x -1;
    midmost = x;
    break;
  case R_LEG:
    if (positions[R_LEG]==-1) topmost = y+2;
    else topmost = positions[R_LEG]/10000 +1;
    bottommost = y+6;
    rightmost = x + 6;
    leftmost = x + 2;
    horiz_mid = x +3;
    vert_mid = y +4;
    break;
  case L_LEG:
    if (positions[L_LEG]==-1) topmost = y+2;
    else topmost = positions[L_LEG]/10000 +1;
    bottommost = y+6;
    rightmost = x +2;
    leftmost = x - 2;
    horiz_mid = x +1;
    vert_mid = y +4;
    break;
  }
  pos = positions[limb];
  x = pos % 10000;
  y = pos /10000;
  current_handhold = " ";
  if (is_handhold (x,y)<1)
  { 
    report("Position " + (y*10000 + x) + " is not a handhold.");
    pos = positions[BODY];
    pos += 10001;
    x = pos % 10000;
    y = pos /10000;
    report("Resetting position to " + (y*10000 + x));
  }     
  possible_handholds = ({});
  if (bottommost<=y){
    report ("y (" + y + ") is lower then bottommost (" + bottommost + ")");
    result = -1;
  } else 
  {
    for (i=y+1;i<=bottommost;i++)
    {
      for (j= leftmost;j<=rightmost;j++)  
      {
//        if (i<topmost +2 && j> rightmost-2) 
        if (is_valid_limb_position(name, limb, j, i) <1)
        {
          report("%^BOLD%^%^YELLOW%^i (" + i +"), j (" +j+ ") is not a valid limb position for limb: " + limb + ". Continuing");
          continue;
        }

        temp_pos = i*10000 + j;
        possible_handholds += ({temp_pos});
      }
    }
    report ("Found " + sizeof(possible_handholds) + " possible handholds");
    if (sizeof(possible_handholds)<1)
    {
      report("There are no possible handholds!");
      result = -1;
    } else 
    {
      removed_handholds =({});
      foreach(temp_pos in possible_handholds)
      {
        if (is_handhold(temp_pos % 10000, temp_pos/10000)<1)
        {
          report ("Position " + temp_pos + " is not a handhold and needs to be removed");
          removed_handholds += ({temp_pos});
        }
      }  
      report ("Removing " + sizeof(removed_handholds) + " non-handholds");
      if (sizeof(removed_handholds)>0)
      {
        foreach(temp_pos in removed_handholds)
        {
          report ("Removing position " + temp_pos + "from possible handholds");
          possible_handholds -= ({temp_pos}); 
        }
      } 
      if (sizeof(possible_handholds)<1) result = -2;
      else
      {
        temp_pos = possible_handholds[0];  
        distance = calculate_distance(temp_pos, pos);
        report ("First position being checked: " + temp_pos + " Distance from initial position: " + distance);
        //of the remaining possible handholds, choose the one that is closest to the previous handhold
        foreach(poss_pos in possible_handholds)
        {
          report ("Next position being checked: " + poss_pos + " Distance from initial position: " + calculate_distance(poss_pos, pos));
          if (calculate_distance(poss_pos, pos)<distance)
          {
            temp_pos = poss_pos;
            distance = calculate_distance(temp_pos, pos);
          }
        }
        report("%^BOLD%^%^YELLOW%^About to do grip strength");
        grip_strength = do_grip_strength(name, limb, temp_pos);
        if (grip_strength<1)
        {
          report("About to report grip failure");
          report_grip_failure(name, limb, temp_pos, room);
          return -11;
        }
        report("%^BOLD%^%^YELLOW%^grip strength done");
        positions[limb] = temp_pos;
      }
    }
  }
  if (result <1 && is_repeat != 1)
  {
    count = 0;
    while(count < 4)
    {
      count ++;
      shift_body(name, 4);
      if (move_limb_down(name, limb, 1) >0) return 1;

    }
    count = 0;
    while(count < 4)
    {
      count ++;
      shift_body(name, 3);
      if (move_limb_down(name, limb, 1) >0) return 1;
    }
    count = 0;
    while(count < 4)
    {
      count ++;
      shift_body(name, 5);
      if (move_limb_down(name, limb, 1) >0) return 1;
    }
    return  move_limb_down(name, limb, 1);
  }
  if (result >0)
  {
    if (is_hanging(name))
    {
      shift_body_down(name);
    }
    show_wall_to_name(name);
    report_grip_success(name, limb, temp_pos, grip_strength, "down", room);
  }

  return result;
}

varargs int move_limb_right(string name, int limb, is_repeat, room){
  int pos, temp_pos, poss_pos, * positions, x,y, * possible_handholds, i,j,topmost, bottommost, rightmost, leftmost, vert_mid, horiz_mid, * removed_handholds, distance, result, flag, count, grip_strength;
  string current_handhold, new_handhold;
  positions = query_positions(name);
  if (sizeof(positions)<1)
  {
    report ("No positions found for " + name + ". Aborting");
    return -1;
  }
  if (positions[limb] !=-1 && count_grips(name)<2)
  {
    report("They are trying to move the only limb they are holding on with");
    tell_object(TP, "You need to have at least one other hand or foothold before you can move this one");
    return -1;
  }
  result = 1;
  pos = positions[BODY];
  x = pos % 10000;
  y = pos /10000;
  switch(limb)
  {
  case R_HAND:
    topmost = y-3;
    bottommost = y +3;
    rightmost = x + 7;
    if (positions[R_HAND]==-1) leftmost = x+3;
    else leftmost = positions[R_HAND]%10000 +1;
    vert_mid = y;
    horiz_mid = x+4;
    break;
  case L_HAND:
    topmost = y -3;
    bottommost = y +3;
    rightmost = x + 2;
    if (positions[L_HAND]==-1) leftmost = x-3;
    else leftmost = positions[R_HAND]%10000 +1;
    vert_mid = y;
    horiz_mid = x-5;
    break;
  case R_LEG:
    topmost = y ;
    bottommost = y+6;
    rightmost = x + 6;
    if (positions[R_LEG]==-1) leftmost = x+3;
    else leftmost = positions[R_LEG]%10000 +1;
    horiz_mid = x +3;
    vert_mid = y +4;
    break;
  case L_LEG:
    topmost = y ;
    bottommost = y+6;
    rightmost = x +2;
    if (positions[L_LEG]==-1) leftmost = x-3;
    else leftmost = positions[L_LEG]%10000 +1;
    horiz_mid = x +1;
    vert_mid = y +4;
    break;
  }
  report ("Horiz_mid: " + horiz_mid + " Vert_mid: " + vert_mid + " Topmost: " + topmost + " Bottommost: " + bottommost + " Leftmost: " + leftmost + " Rightmost " + rightmost);
  pos = positions[limb];
  x = pos % 10000;
  y = pos /10000;
  current_handhold = " ";
  if (is_handhold (x,y)<1)
  { 
    report("Position " + (y*10000 + x) + " is not a handhold.");
    pos = positions[BODY];
    pos += 10001;
    x = pos % 10000;
    y = pos /10000;
    report("Resetting position to " + (y*10000 + x));
  }     
  possible_handholds = ({});
  if (rightmost<=x){
    report ("y (" + y + ") is lower then bottommost (" + bottommost + ")");
    result = -1;
  } else
  {
    for (i=topmost;i<=bottommost;i++)
    {
      for (j= x+1;j<=rightmost;j++)
      { 
        if (is_valid_limb_position(name, limb, j, i) <1)
        {
          report("%^BOLD%^%^YELLOW%^i (" + i +"), j (" +j+ ") is not a valid limb position for limb: " + limb + ". Continuing");
          continue;
        }
        temp_pos = i*10000 + j;
        possible_handholds += ({temp_pos});
      }
    }
    report ("Found " + sizeof(possible_handholds) + " possible handholds");
    if (sizeof(possible_handholds)<1)
    {
      report("There are no possible handholds!");
      result = -1;
    } else 
    {
      removed_handholds =({});
      foreach(temp_pos in possible_handholds)
      {
        if (is_handhold(temp_pos % 10000, temp_pos/10000)<1)
        {
          report ("Position " + temp_pos + " is not a handhold and needs to be removed");
          removed_handholds += ({temp_pos});
        }
      }  
      report ("Removing " + sizeof(removed_handholds) + " non-handholds");
      if (sizeof(removed_handholds)>0)
      {
        foreach(temp_pos in removed_handholds)
        {
          report ("Removing position " + temp_pos + "from possible handholds");
          possible_handholds -= ({temp_pos}); 
        }
      } 
      if (sizeof(possible_handholds)<1) result = -2;
      else 
      {
        temp_pos = possible_handholds[0];
        distance = calculate_distance(temp_pos, pos);
        report ("First position being checked: " + temp_pos + " Distance from initial position: " + distance);
        //of the remaining possible handholds, choose the one that is closest to the previous handhold
        foreach(poss_pos in possible_handholds)
        {
          report ("Next position being checked: " + poss_pos + " Distance from initial position: " + calculate_distance(poss_pos, pos));
          if (calculate_distance(poss_pos, pos)<distance)
          {
            temp_pos = poss_pos;
            distance = calculate_distance(temp_pos, pos);
          }
        }
        report("%^BOLD%^%^YELLOW%^About to do grip strength");
        grip_strength = do_grip_strength(name, limb, temp_pos);
        if (grip_strength<1)
        {
          report("About to report grip failure");
          report_grip_failure(name, limb, temp_pos, room);
          return -12;
        }
        report("%^BOLD%^%^YELLOW%^About to do grip strength");
        positions[limb] = temp_pos;
      }
    }
  }
  if (result <1 && is_repeat != 1)
  {
    count = 0;
    while(count < 4)
    {
      count ++;
      shift_body(name, 2);
      if (move_limb_right(name, limb, 1) >0) return 1;
    }
    count = 0;
    while(count < 4)
    {
      count ++;
      shift_body(name, 1);
      if (move_limb_right(name, limb, 1) >0) return 1;
    }
    count = 0;
    while(count < 4)
    {
      count ++;
      shift_body(name, 3);
      if (move_limb_right(name, limb, 1) >0) return 1;
    }
    return  move_limb_right(name, limb, 1);
  }
  if (result >0)
  {
    if (is_hanging(name))
    {
      shift_body_down(name);
    }
    show_wall_to_name(name);
    report_grip_success(name, limb, temp_pos, grip_strength, "right", room);
  }
  return result;
}

varargs int move_limb_left(string name, int limb, is_repeat, room){
  int pos, temp_pos, poss_pos, * positions, x,y, * possible_handholds, i,j,topmost, bottommost, rightmost, leftmost, vert_mid, horiz_mid, * removed_handholds, distance, result, flag, count, grip_strength;
  string current_handhold, new_handhold;
  positions = query_positions(name);
  
  if (sizeof(positions)<1)
  {
    report ("No positions found for " + name + ". Aborting");
    return -1;
  }
  if (positions[limb] !=-1 && count_grips(name)<2)
  {
    report("They are trying to move the only limb they are holding on with");
    tell_object(TP, "You need to have at least one other hand or foothold before you can move this one");
    return -1;
  }
  pos = positions[BODY];
  x = pos % 10000;
  y = pos /10000;
  switch(limb)
  {
  case R_HAND:
    topmost = y-3;
    bottommost = y +3;
    if (positions[R_HAND]==-1) rightmost = x+4;
    else rightmost = positions[R_HAND]%10000;
    leftmost = x+1;
    vert_mid = y;
    horiz_mid = x+4;
    break;
  case L_HAND:
    topmost = y -3;
    bottommost = y +3;
    if (positions[L_HAND]==-1) rightmost = x+1;
    else rightmost = positions[L_HAND]%10000 -1;
    leftmost = x-4;
    vert_mid = y;
    horiz_mid = x-2;
    report ("Moving left hand left. Current position: " + pos + " Leftmost: " + leftmost + " Rightmost: " + rightmost + " Topmost: " + topmost + " Bottommost: " + bottommost); 
    break;
  case R_LEG:
    topmost = y +1;
    bottommost = y+6;
    if (positions[R_LEG]==-1) rightmost = x+3;
    else rightmost = positions[R_LEG]%10000;
    leftmost = x + 2;
    horiz_mid = x +3;
    vert_mid = y +4;
    break;
  case L_LEG:
    topmost = y +1;
    bottommost = y+6;
    if (positions[L_LEG]==-1) rightmost = x-1;
    else rightmost = positions[L_LEG]%10000 -1;
    leftmost = x - 2;
    horiz_mid = x +1;
    vert_mid = y +4;
    break;
  }
  report ("Topmost: " + topmost + " Bottommost: " + bottommost + " Leftmost: " + leftmost + " Rightmost " + rightmost);
  result = 1;
  pos = positions[limb];
  x = pos % 10000;
  y = pos /10000;
  current_handhold = " ";
  if (is_handhold (x,y)<1)
  { 
    report("Position " + (y*10000 + x) + " is not a handhold.");
    pos = positions[BODY];
    pos += 10001;
    x = pos % 10000;
    y = pos /10000;
    report("Resetting position to " + (y*10000 + x));
  }     
  possible_handholds = ({});
  if (leftmost>=x){
    report ("x (" + x + ") is lefter then leftmost (" + leftmost + ")");
    result = -1;
  } else 
  {
    for (i=topmost;i<=bottommost;i++)

    {
     for (j= leftmost;j<rightmost;j++)
       {  
        if (is_valid_limb_position(name, limb, j, i) <1)
        {
          report("%^BOLD%^%^YELLOW%^i (" + i +"), j (" +j+ ") is not a valid limb position for limb: " + limb + ". Continuing");
          continue;
        }      
        temp_pos = i*10000 + j;
        possible_handholds += ({temp_pos});
      }
    }
    report ("Found " + sizeof(possible_handholds) + " possible handholds");
    if (sizeof(possible_handholds)<1)
    {
      report("There are no possible handholds!");
      result = -1;
    } else
    {
      removed_handholds =({});
      foreach(temp_pos in possible_handholds)
      {
        if (is_handhold(temp_pos % 10000, temp_pos/10000)<1)
        {
          report ("Position " + temp_pos + " is not a handhold and needs to be removed");
          removed_handholds += ({temp_pos});
        }
      }   
      report ("Removing " + sizeof(removed_handholds) + " non-handholds");
      if (sizeof(removed_handholds)>0)
      {
        foreach(temp_pos in removed_handholds)
        {
          report ("Removing position " + temp_pos + "from possible handholds");
          possible_handholds -= ({temp_pos}); 
        }
      } 
      if (sizeof(possible_handholds)<1) result = -2;
      else
      {
        temp_pos = possible_handholds[0];
        distance = calculate_distance(temp_pos, pos);
        report ("First position being checked: " + temp_pos + " Distance from initial position: " + distance);
        //of the remaining possible handholds, choose the one that is closest to the previous handhold
        foreach(poss_pos in possible_handholds)
        {
          report ("Next position being checked: " + poss_pos + " Distance from initial position: " + calculate_distance(poss_pos, pos));
          if (distance == 0 || (calculate_distance(poss_pos, pos)<distance && calculate_distance(poss_pos, pos)>0) )
          {
            temp_pos = poss_pos;
            distance = calculate_distance(temp_pos, pos);
          }
        }
        report ("About to move limb. Original position: " + pos + " New position: " + temp_pos);
        report("%^BOLD%^%^YELLOW%^About to do grip strength");
        grip_strength = do_grip_strength(name, limb, temp_pos);
        if (grip_strength<1)
        {
          report("About to report grip failure");
          report_grip_failure(name, limb, temp_pos, room);
          return -13;
        }
        report("%^BOLD%^%^YELLOW%^grip strength done");
        positions[limb] = temp_pos;
      }
    }
  }
  if (result <1 && is_repeat != 1)
  {
    count = 0;
    while(count < 4)
    {
      count ++;
      shift_body(name, 6);
      if (move_limb_left(name, limb, 1) >0) return 1;
    }
    count = 0;
    while(count < 4)
    {
      count ++;
      shift_body(name, 5);
      if (move_limb_left(name, limb, 1) >0) return 1;
    }
    count = 0;
    while(count < 4)
    {
      count ++;
      shift_body(name, 7);
      if (move_limb_left(name, limb, 1) >0) return 1;
    }
    return  move_limb_left(name, limb, 1);
  }
  if (result >0)
  {
    if (is_hanging(name))
    {
      shift_body_down(name);
    }
    show_wall_to_name(name);
    report_grip_success(name, limb, temp_pos, grip_strength, "left", room);
  }
  return result;
}

int get_handhold_challenge(int location){
  int x, y, challenge;
  string line, ch;
  x = location % 10000;
  y = location / 10000;
  if (y>= sizeof(handhold_challenge)) return -1;
  line = handhold_challenge[y];
  if (x>= strlen(line)) return -2;
  ch = line [x..x];
  challenge = atoi(ch);
  return challenge;
}

varargs object get_climber(string name, object room){
  int flag;
  object * critters, climber;
  critters = children("/std/user.c");
  foreach(climber in critters)
  {
    if (climber->query_name()==name)
    {
      flag = 1;
      break;
    }
  }
  if (flag == 0)  climber = 0;
  if (!objectp(climber))
  {
    if (objectp(room))
    {
      climber = present(name, room);
    }
  }
  return climber;
}

varargs void report_grip_failure(string name, int limb, int pos, object room){
  int hold;
  object climber, * critters;
  string hand_name, foot_name, limb_name, * cs, result;
  if (!objectp(room)) room = current_room;
  if (objectp(room) && room->query_property("silent")==1)
  {
    tell_room(room, "%^BOLD%^%^MAGENTA%^Grip failure reporting blocked");
    return;
  }
  cs = keys(climbers);
  climber = get_climber(name, room);
  if (unreport ==1) return;
  if (!objectp(climber))
  {
    report ("%^B_MAGENTA%^%^BOLD%^%^WHITE%^report_grip_failure: unable to get valid climber object");
    return;
  }
  if (climber->query_property("swinging")==1) return;
  limb_name = get_limb_name(limb);
  hand_name = get_handhold_name(pos);
  foot_name = get_foothold_name(pos);
  switch(limb_name)
  {
  case "left hand":
  case "right hand": //deliberately falling through
    result = "You reach for " + hand_name + " with your " + limb_name + ", but you fail to get a grip";
    tell_object(climber, result);
    if(objectp(room))
    {
      tell_room(room, climber->QCN + " reaches for " + hand_name + ", but can't get a grip", TP); 
    }
    break;
  case "left leg":
  case "right leg": //deliberately falling through
    result = "You try to move your " + limb_name + " to "+ foot_name + ", but it slips";
    tell_object(climber, result);
    if(objectp(room))
    {
      tell_room(room, climber->QCN + " fails isn't able to secure a foothold on " + foot_name, TP); 
    }
    break;
  }  
}

varargs void report_grip_success(string name, int limb, int pos, int grip_strength, string dir, object room){
  int hold;
  object climber, * critters;
  string hand_name, foot_name, limb_name, * cs, result, grip_name;
  if (unreport ==1) return;
  if (!objectp(room)) room = current_room;
  cs = keys(climbers);
  if (objectp(room) && room->query_property("silent")==1)
  {
    return;
  } else 
  {
    if (!objectp(room)) report( "%^BOLD%^%^RED%^room not a valid object", 9);
  }
  climber = get_climber(name, room);
  if (!objectp(climber))
  {
    report ("report_grip_failure: unable to get valid climber object");
    return;
  }
  if (climber->query_property("swinging")==1) return;
  limb_name = get_limb_name(limb);
  hand_name = get_handhold_name(pos);
  foot_name = get_foothold_name(pos);
  grip_name = get_grip_name(grip_strength);
  switch(limb_name)
  {
  case "left hand":
  case "right hand": //deliberately falling through
    
    result = "You move your " + limb_name + " " + dir + " and establish a " + grip_name + " grip on " + hand_name;
    tell_object(climber, result);
    if(objectp(room))
    {
      tell_room(room, climber->QCN + " moves " + climber->QP + " " + limb_name + " " + dir + " and establishes a " + grip_name + " grip on " + hand_name, TP); 
    }
    break;
  case "left leg":
  case "right leg": //deliberately falling through
    result = "You move your " + limb_name + " " + dir + " and establish a " + grip_name + " foothold on " + hand_name;
    tell_object(climber, result);
    if(objectp(room))
    {
      tell_room(room, climber->QCN + " moves " + climber->QP + " " + limb_name + " " + dir + " and establishes a " + grip_name + " foothold on " + hand_name, TP); 
    }
    break;
  }  
}

int query_grip_strength(string name, int limb){
  string * cs;
  int * grips;
  if (mapp(climb_grips) || sizeof(climb_grips)<1) return -1;
  cs = keys(climb_grips);
  if (member_array(name, cs) == -1) return -2;
  grips = climb_grips[name];
  if (sizeof(grips)<= limb) return -3;
  return grips[limb];
}

string get_grip_name(int grip_strength){
  string grip_name;
  switch(grip_strength)
  {
  case 0:
    grip_name = "none";
    break;
  case 1:
    grip_name = "precarious";
    break;
  case 2:
    grip_name = "poor";
    break;
  case 3:
    grip_name = "fair";
    break;
  case 4:
    grip_name = "reasonable";
    break;
  case 5:
    grip_name = "firm";
    break;
  case 6:
    grip_name = "very good";
    break;
  case 7:
    grip_name = "rock solid";
    break;
  default:
    grip_name = "fracking incredible";
  }
  return grip_name;
}

string get_handhold_description(int pos){
  int hold;
  string hand_name;
  if (is_a_rope_I_am_carrying(pos, TPQN, ETP)) hold = query_base_handhold(pos);
  else hold = atoi(query_handhold(pos));
  switch (hold)
  {
  case JUG:
    hand_name = "that makes a good handhold";
    break;
  case LEDGE:
    hand_name = "that offers a reasonable handhold";
    break;
  case CRIMP:
    hand_name = "that only offers fingertip grips";
    break;
  case PINCH:
    hand_name = "that can be gripped between fingers and thumbs";
    break;
  case FLAKE:
    hand_name = "that fingers can hook over";
    break;
  case POCKET:
    hand_name = "that provides purchase for one or two fingers";
    break;
  case SLOPER:
    hand_name = "that does not allow a finger grip, but allows a challenging but tenable hold with the whole hand";
    break;
  case HORN:
    hand_name = "that makes a great and easy handhold";
    break;
  case ROPE:
    hand_name = "that is perfect for climbing";
  default:
    hand_name = "";
  }
  return hand_name;
}


string get_handhold_name(int pos){
  int hold;
  string hand_name;
  if (is_a_rope_I_am_carrying(pos, TPQN, ETP)) hold = query_base_handhold(pos);
  else hold = atoi(query_handhold(pos));
  report ("Getting handhold name. hold: " + hold);
  switch (hold)
  {
  case JUG:
    hand_name = "a depression with a lip";
    break;
  case LEDGE:
    hand_name = "a decent ledge";
    break;
  case CRIMP:
    hand_name = "a very small edge";
    break;
  case PINCH:
    hand_name = "a vertical edge";
    break;
  case FLAKE:
    hand_name = "a crack";
    break;
  case POCKET:
    hand_name = "a crevice";
    break;
  case SLOPER:
    hand_name = "a sloping area";
    break;
  case HORN:
    hand_name = "a projection";
    break;
  case ROPE:
    hand_name = "a rope";
    break;
  default: 
    hand_name = "the ground";
  }
  return hand_name;
}


int get_jumpable_handhold(string name, string direction){
  int * limbs, x, y, * original_positions, loc, top, bottom, left, right, i, j, * potential_locations, result, hold, bod_x, bod_y, dir, start_x, start_y, flag, k, dist_mod;
  object climber;
  limbs = query_positions(name);
  if (sizeof(limbs)<5) return -1;
  original_positions = ({});
  report("Jumpable handholds 1", 2);
  foreach(loc in limbs)
  {
    original_positions += ({loc});
  }
  climber = get_climber(name);
  dist_mod = 0;
  if (objectp(climber)) dist_mod = climber->query_skill("athletics")/10; //athletics skill lets you jump further
  switch(direction)
  { 
  case "left": 
    dir = 2;
    break;
  case "right":
    dir = 6;
    break;
  case "up":
    dir = 0;
    break;
  case "down":
    dir = 4;
    break;
  default:
    return -1;
  }
  for (i=0;i<5;i++) shift_body(name, dir);
  report("Jumpable handholds 2", 2);
  limbs = query_positions(name);
  loc = limbs[BODY];
  x = loc % 10000;
  y = loc / 10000;
  start_x = x++;
  start_y = y++;
  top = y-8;
  bottom = y+8;
  if (bottom>sizeof(wall)-8)
  {
    if ( bottom < y+1) 
    {
      if (y>sizeof(wall)-7) bottom = sizeof(wall) -2;
      else bottom = sizeof(wall) -8;
    } 
  }
  left = x - 8;
  right = x + 9;
  potential_locations = ({});
  for(i=left;i<=right+ dist_mod;i++)
  {
    for (j = top; j<= bottom + dist_mod/2; j++)
    {
      flag = 0;
      for (k=0;k<4;k++)
      {
        if (is_valid_limb_position(name, k, i, j)>0) flag = 1;
      }
      if (flag == 1) continue;
      switch(direction)
      {
      case "left":
        if (i>start_x) continue;
        if (j > start_y + (start_x-i)/2) continue;
        if (j < start_y - (start_x-i)/2) continue;
        break;
      case "right":
        if (i<start_x) continue;
        if (j > start_y + (i - start_x)/2) continue;
        if (j < start_y - (i - start_x)/2) continue;
        break;
      case "up":
        if (j>start_y) continue;
        if (i > start_x + (start_y-j)*2) continue;
        if (i < start_y - (start_y-j)*2) continue;
        break;
      case "down":
        if (j<start_y) continue;
        if (i > start_x + (j-start_y)*2) continue;
        if (i < start_y - (j-start_y)*2) continue;
        break;
      }
      loc = j*10000 + i;

      report("Adding location " + loc + "to potential locations");
      potential_locations += ({loc});
    }
  }
  report("Jumpable handholds 4. Sizeof potential handholds: " + sizeof(potential_locations), 2);
  result = 0;
  bod_x = original_positions[BODY] % 10000;
  bod_y = original_positions[BODY] / 10000;
  potential_locations = order_locations(potential_locations, direction, bod_x);
  foreach(loc in potential_locations)
  {
    x = loc % 10000;
    y = loc / 10000;
    hold = atoi(query_handhold(loc));
    report("Checking potential handhold at location " + loc + " Hold type: " + hold, 2);
    if (hold != LEDGE)
    {
      report("Hold is not a ledge", 2);
      if (hold == ROPE || hold == HORN)
      {
        report("Hold is a rope or a horn ", 2);
        if (y>bod_y+2 || y> sizeof(wall)-9)
        {
          report("Handhold is too low to jump to", 2);
          continue;
        } else
        {
          switch(direction)
          {
          case "left":
            if (x > bod_x-2)
            {
              report("%^BOLD%^%^MAGENTA%^x (" + x + ") > bod_x ("+bod_x + ") -2. Continuing");
              continue;
            }
            if (result <1 || x > result % 10000) result = loc; 
            else report("%^BOLD%^%^CYAN%^x is not greater than result % 1000");
            break;
          case "right":
            if (x < bod_x+3)
            {
              report("%^BOLD%^%^MAGENTA%^x (" + x + ") < bod_x ("+bod_x + ") +3. Continuing");
              continue;
            }
            if (result <1 || x < result % 10000)
            {
              report("%^BOLD%^%^CYAN%^Setting x to loc: " + loc );
              result = loc;
            } 
            else report("%^BOLD%^%^CYAN%^x is not less than result % 1000");
            break;
          case "up":
            if (y>result / 10000) result = loc;
            break;
          case "down":
            if (y<result / 10000) result = loc;
            break;
          }
        }
      }
      continue; 
    } else 
    {
      report("Hold is a ledge. Hurrah", 2);
      if (y> sizeof(wall)-9 && y<sizeof(wall)-5)
      {
         report ("Ledge at location "+ loc + " is too high to jump to with a leg, and too high to jump to with a hand");
         continue;
      }
    } 
    if (result == 0) result = loc;
    switch(direction)
    {
    case "left":
      if (x < result % 10000) result = loc; 
      break;
    case "right":
      if (x > result % 10000) result = loc; 
      break;
    case "up":
      if (y>result / 10000) result = loc;
      break;
    case "down":
      if (y<result / 10000) result = loc;
      break;
    }
  }
  limbs = ({}); //return limbs to original positions;
  foreach(loc in original_positions)
  {
    limbs += ({loc});
  }
  climbers[name] = limbs;
  report ("Finishing get_jumpable_handhold()   Result: " + result);
  return result;
}


int * order_locations(int * locs, string direction, int bod_x){
  mixed * rows, new_rows;
  int * row, i, count, loc, j, removals, x, y, count2, new_row, left_hand_x, right_hand_x, dist, target_row, top, * result, * my_row;
  count = sizeof(locs);
  rows = ({});
  report("%^GREEN%^About to order " + count + " locations");
  for (i=0;i<count;i++)
  {
    if (i >= sizeof(locs)) break;
    row = ({});
    loc = locs[i];
    y = loc / 10000;
    foreach(loc in locs)
    {
      if (loc /10000 == y)
      {
        row += ({loc});
      }
    }
    rows += ({row});
    locs -= row;
  }
  count = sizeof(rows);
  report("%^CYAN%^Identified " + count + " rows");
  new_rows = ({});
  for(i = 0;i<count;i++)   //Next, put each row into desired horizontal direction
  {
    report("Sorting out horizontal order of row " + i );
    new_row = ({});
    row = rows[i];
    report("Number of locations in row: " + sizeof(row) );
    report("Calculating y for row. First location is  " + row[0] );
    y = row[0]/10000;
    report ("Y = " + y);
    left_hand_x = bod_x; 
    right_hand_x = bod_x + 4;
    report("Reordering row: ");
//    tell_object(TP,  row);
    for (dist = 0; dist < 6; dist ++) 
    {
      report("Calculating next loc.  Left_hand_x: " + left_hand_x + " Right hand x: " + right_hand_x + " Dist: " + dist + " y: " + y); 
      loc = (y * 10000) + left_hand_x + dist;
      report("Checking location " + loc);
      if (member_array(loc, row)!= -1)
      {
        new_row += ({loc});
        row -= ({loc});
      }
      loc = y * 10000 + left_hand_x - dist;
      if (member_array(loc, row)!= -1)
      {
        new_row += ({loc});
        row -= ({loc});
      }
      loc = y * 10000 + right_hand_x - dist;
      if (member_array(loc, row)!= -1)
      {
        new_row += ({loc});
        row -= ({loc});
      }
      loc = y * 10000 + right_hand_x + dist;
      if (member_array(loc, row)!= -1)
      {
        new_row += ({loc});
        row -= ({loc});
      } else report("%^BOLD%^%^MAGENTA%^location " + loc + " is not in the row. How did that happen?");     
    }  
    report("%^RED%^Row ordered. " + sizeof(new_row) + " locations in resulting row");
    new_rows += ({new_row});
  }
  rows = new_rows;
  new_rows = ({});
  report("%^ORANGE%^About to order rows. Number of rows to order: " + sizeof(rows));
  while(sizeof(rows)>0)    //Then, order rows by size according to direction
  { 
    top = 10000;
    count = sizeof(new_rows);
    target_row = 0;
    for (i = 0; i<count; i++)
    {
      if (sizeof(rows)<=i) break;
      my_row = rows[i];
      if (sizeof(my_row)<1) break;
      y = my_row[0]/10000;
      if ( ( direction == "up" && top > y ) || ( direction == "up" && top < y ) )  //This is the line that adjusts according to direction  
      {
        top = y;
        target_row = i;
      }
    }
    row = rows[target_row];
    new_rows += ({row});
    rows -= ({row}); 
  }
  result  = ({}); //finally, put all the rows back into a flat array
  foreach(row in new_rows)
  {
     report ("%^CYAN%^Adding locations from a row");
     foreach(loc in row)
     {
       report("Adding a location");
       result += ({loc});
     }
  }
  return result;
}

int * order_by_y(int * locs, string dir){
  int loc, * result, next, i, count;
  result = ({});
  count = sizeof(locs);
  for (i = 0; i<count;i++)
  {
    next = -1;
    foreach(loc in locs)
    {
      if (dir == "up" && (next ==-1 || loc > next)) next = loc;
      if (dir == "down" && (next ==-1 || loc < next)) next = loc;
    }
    locs -= ({next});
    result += ({next});
  }
  return result;
}

mapping get_jumpable_handholds(string name){
  mapping result;
  int loc;
  result = ([]);
  loc = get_jumpable_handhold(name, "left");
  result["left"] = loc;
  loc = get_jumpable_handhold(name, "right");
  result["right"] = loc;
  loc = get_jumpable_handhold(name, "up");
  result["up"] = loc;
  loc = get_jumpable_handhold(name, "down");
  result["down"] = loc;
  return result;
}


string get_foothold_description(int pos){
  int hold;
  string foot_name;
  if (is_a_rope_I_am_carrying(pos, TPQN, ETP)) hold = query_base_handhold(pos);
  else hold = atoi(query_handhold(pos));
  switch (hold)
  {
  case JUG:
    foot_name = "that makes a good foothold";
    break;
  case LEDGE:
    foot_name = "that offers a stable foot rest";
    break;
  case CRIMP:
    foot_name = "that only offers purchase for toes";
    break;
  case PINCH:
    foot_name = "that is only suitable as a foot purchase if pressure can be applied from the other direction";
    break;
  case FLAKE:
    foot_name = "that provides a challenging foothold";
    break;
  case POCKET:
    foot_name = "that is too small to provide purchase for a foot";
    break;
  case SLOPER:
    foot_name = "that is challenging to use, but gives some purchase to a foot";
    break;
  case HORN:
    foot_name = "that is easy to stand on";
    break;
  default: 
    foot_name = "";
  }
  return foot_name;
}


string get_foothold_name(int pos){
  int hold;
  string foot_name;
  if (is_a_rope_I_am_carrying(pos, TPQN, ETP)) hold = query_base_handhold(pos);
  else hold = atoi(query_handhold(pos));
  report ("Getting foothold name. hold: " + hold);
  switch (hold)
  {
  case JUG:
    foot_name = "a depression with a lip";
    break;
  case LEDGE:
    foot_name = "a decent ledge";
    break;
  case CRIMP:
    foot_name = "a very small edge";
    break;
  case PINCH:
    foot_name = "a vertical edge";
    break;
  case FLAKE:
    foot_name = "a lip";
    break;
  case POCKET:
    foot_name = "a crevice";
    break;
  case SLOPER:
    foot_name = "a sloping area";
    break;
  case HORN:
    foot_name = "a projection";
    break;
  default: 
    foot_name = "the ground";
  }
  return foot_name;
}

string get_limb_name(int limb){
  string limb_name;
  switch(limb)
  {
  case L_HAND:
    limb_name = "left hand";    
    break;
  case R_HAND:
    limb_name = "right hand";
    break;
  case L_LEG:
    limb_name = "left leg";
    break;
  case R_LEG:
    limb_name = "right leg";
    break;
  }
  return limb_name;
}

int get_handhold_strength(int location){
  int x, y, strength;
  string line, ch;
  x = location % 10000;
  y = location / 10000;
  if (y>= sizeof(handhold_strength)) return -1;
  line = handhold_strength[y];
  if (x>= strlen(line)) return -2;
  ch = line [x..x];
  strength = atoi(ch);
  return strength;
}

varargs int calculate_grip_strength(string name, int location, object room, int penalty){
  int x, y, grip, athletics, challenge,r,s;
  string race;
  object ob, * players;
  if (!intp(location)) location = atoi(location);
  x = location % 10000;
  y = location / 10000;
  players = children("/std/user.c");
  foreach(ob in players)
  {
    if (!objectp(ob)) continue;
    if (ob->query_name()==name) break;
  } 
  if (!objectp(ob) || ob->query_name() != name)
  {
    if (!objectp(room)) return -1;
    ob = present(name, room);
    if (!objectp(ob)) return -2;
    race = ob->query_race();
    switch (race)
    {
    case "human":
      athletics = 20;
      break;
    default:
      athletics = 10;
      break;
    }
  } else 
  {
    athletics = ob->query_skill("athletics");
  }
  challenge = get_handhold_challenge(location);
  r = random(3) + 1;
  s = random(3) + 1;
  athletics -= penalty;
  if (athletics<1) athletics = 1;
  if (challenge<1) challenge =1;
  grip = athletics * r;
  if (grip<1) grip = 1;
  grip = grip / 3;
  if (grip<1) grip = 1;
  grip = grip / challenge;
  if (grip<1) grip = 1;
  grip = grip /s;
  if (grip <1) grip = 0;
  if (grip > 7) grip = 7; 
  return grip;
}



int shift_body(string name, int direction){
  int * positions, bod_x, bod_y, bod_pos, x_adjust, y_adjust, temp_pos, flag, i;
  string * cs;
  report ("%^BOLD%^%^YELLOW%^Shift body 1");
  if (!mapp(climbers) || sizeof(climbers)<1) return -1;
  cs = keys(climbers);
  if (member_array(name, cs)==-1) return -1;
  positions = climbers[name];
  bod_pos = positions[4];
  bod_x = bod_pos % 10000;
  bod_y = bod_pos / 10000;
  switch(direction)
  {
  case 0:
    y_adjust = -1;
    x_adjust = 0;
    break;
  case 1:
    y_adjust = -1;
    x_adjust = 1;
    break;
  case 2:
    y_adjust = 0;
    x_adjust = 1;
    break;
  case 3:
    y_adjust = 1;
    x_adjust = 1;
    break;
  case 4:
    y_adjust = 1;
    x_adjust = 0;
    break;
  case 5:
    y_adjust = 1;
    x_adjust = -1;
    break;
  case 6:
    y_adjust = 0;
    x_adjust = -1;
    break;
  case 7:
    y_adjust = 1;
    x_adjust = -1;
    break;
  }
  temp_pos = ((bod_y + y_adjust) * 10000) + (bod_x + x_adjust);
  positions[4] = temp_pos;
  climbers[name] = positions;
  flag = 0;
  report ("Shift body 2");
  for (i = 0;i<4;i++)
  {
     if (positions[i] < 0)
    {
      positions[i] = RELEASED;
      continue;
    }
   if (is_valid_limb_position(name, i, positions[i]%10000, positions[i]/ 10000)<1)
    {
      flag = 1;
      break;
    }
  report ("%^BOLD%^%^MAGENTA%^position " + positions[i] + " Is valid for limb no: " + i +", relative to body position: " + positions[BODY] );
  }
  report ("Shift body 3 ");
  if (flag ==1)
  {
    positions[4] = bod_pos;
    climbers[name] = positions;
    return -1;
  }
  return 1;
}


///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


int calculate_distance(int pos1, int pos2){
  int x1, x2, y1, y2, difference, result;
  x1 = pos1 %10000;
  x2 = pos2 %10000;
  y1 = pos1 / 10000;
  y2 = pos2 / 10000;
  difference = x1 - x2; 
  if (difference < 0 ) difference = difference *-1;
  result = difference;
  difference = y1 - y2; 
  if (difference < 0 ) difference = difference *-1;
  result += difference;
  return result;
}


varargs int is_valid_limb_position(string climber, int limb, int x, int y){
  string * cs;
  int * limbs, vert_mid, horiz_mid, leftmost, rightmost, bod_x, bod_y, topmost, bottommost;
  if (!mapp(climbers) || sizeof(climbers)<1) return -1;
  cs = keys(climbers);
  if (member_array(climber, cs)==-1) return -2;
  if (!intp(y))
  {
    y = x / 10000;
    x = x % 10000;
  }
  limbs = climbers[climber];
  bod_x = limbs[4] % 10000;
  bod_y = limbs[4] / 10000;
  report ("y: " + y + " x: " + x);
  switch(limb)
  {
  case R_HAND:
    topmost = bod_y-3;
    bottommost = bod_y +2;
    rightmost = bod_x + 7;
    leftmost = bod_x +2;
    vert_mid = bod_y;
    horiz_mid = bod_x+4;
    break;
  case L_HAND:
    topmost = bod_y -3;
    bottommost = bod_y +2;
    rightmost = bod_x +2;
    leftmost = bod_x -3;
    vert_mid = bod_y;
    horiz_mid = bod_x;
    break;
  case R_LEG:
    topmost = bod_y +1;
    bottommost = bod_y+4;
    rightmost = bod_x + 6;
    leftmost = bod_x + 1;
    horiz_mid = bod_x +3;
    vert_mid = bod_y +4;
    break;
  case L_LEG:
    topmost = bod_y +1;
    bottommost = bod_y+4;
    rightmost = bod_x +2;
    leftmost = bod_x - 2;
    horiz_mid = bod_x +1;
    vert_mid = bod_y +4;
    break;
  }
  if (y<topmost)
  {
    report ("Y (" + y + ") < topmost (" + topmost + ")");
    return -1;    
  }
  if (y>bottommost)
  {
    report ("Y (" + y + ") > bottommost (" + bottommost + ")");
    return -1;    
  }
  if (x<leftmost)
  {
    report ("X (" + x + ") < leftmost (" + leftmost + ")");
    return -1;    
  }
  if (x> rightmost)
  {
    report ("X (" + x + ") > rightmost (" + rightmost + ")");
    return -1;    
  }
  if (limb == R_HAND )
  {
    report ("%^MAGENTA%^Checking position of right hand limb");
    if ( x==rightmost && y != vert_mid)
    {
      report("%^BOLD%^%^YELLOW%^x (" + x +") = rightmost (" + rightmost + ") and y (" +y+ ")!= vert_mid (" + vert_mid + "). Not a valid limb position");
      return -3;
    }
  }

  if (limb == L_HAND)
  {
    report ("%^GREEN%^Checking position of left hand limb");
    if ( x==leftmost && y != vert_mid)
    {
      report("%^BOLD%^%^YELLOW%^x (" + x +") = leftmost (" + leftmost + ") and y (" +y+ ")!= vert_mid (" + vert_mid + "). Not a valid limb position");
      return -3;
    }
  }

  if (limb == L_HAND || limb ==  R_HAND)
  {
    report ("%^ORANGE%^Checking top position of left or right hand limb");
    if  ( y==topmost && x !=horiz_mid )
    {
      report("%^BOLD%^%^YELLOW%^y (" + y +") = topmost (" + topmost + ") and x (" +x+ ")!= horiz_mid (" + horiz_mid + "). Not a valid limb position");
      return -4;
    }  
  }

  if (limb == R_LEG)
  {
    if (y== bottommost -1 && x == rightmost)
    {
      report("y (" + y + ") = bottommost-1 (" + (bottommost-1) + ") and x (" + x +") == rightmost (" + rightmost + ")");
      return -1;
    }
  }

  if (limb == L_LEG)
  {
    if (y== bottommost -1 && x == leftmost)
    {
      report("y (" + y + ") = bottommost -1 (" + (bottommost-1) + ") and x (" + x +") == leftmost (" + leftmost + ")");
      return -1;
    }
  }
  if (limb == R_LEG || limb == L_LEG)
  {
    if (y == bottommost)
    {
      report ("%^CYAN%^y(" + y + ") == bottommost (" + bottommost + ")");
      if (x != horiz_mid)
      {
        report("y (" + y + ") = bottommost (" + bottommost + ") and x (" + x +") != horiz_mid (" + horiz_mid + ")");
        return -1;
      }
      else report ("%^CYAN%^x (" + x + ") == horiz_mid (" + horiz_mid + ")");
    }
  }
  return 1;
}



string * add_pic_to_wall(string * pic, string * mywall, int x, int y){
  string line, picline, col_line, bg_line, ch, colour_code, *ks;
  int i, j ,k;
  i = y;
  if (sizeof(wall_colours)<1) report("No wall colours loaded");
  temp_colours = wall_colours;
  temp_bg = bg_colours;
  report ("Adding pic to wall. Sizeof wall: " + sizeof(wall));
  foreach(picline in pic){
    if (i>=sizeof(mywall) ) break;
    if (i<0) 
    {
      i++;
      continue;
    }
    report ("Adjusting picline number " + (i-y));
    line = mywall[i];
    col_line = temp_colours[i];
    bg_line = temp_bg[i];
    for (j = strlen(picline)-1; j>=0; j--)
    {
      report ("Working online. i: " + i + " j: " + j);
      report ("Current line: '" + line + "'"); 
      ch = picline[j..j];
      if (ch != " ") 
      { 
        if (ch == "*") ch =  "_";   
        if (ch == "~") ch =  " ";  
        line = "/daemon/str_insert_d.c"->insert_string(line,ch, j+x); 
        report("line adjusted. Character inserted: " + ch + " Size of new line: " + strlen(line) + " New line: '" + line + "'" );
        colour_code = "W";
        col_line = "/daemon/str_insert_d.c"->insert_string(col_line,colour_code, j+x);       
        if (is_last_character(j, picline)) // This section mostly fixes the colour bleed problem
        {  
          colour_code = "P";
          col_line = "/daemon/str_insert_d.c"->insert_string(col_line,colour_code, j+x+1);      
          continue; 
        }  
      }
     
    }
    temp_colours[i] = col_line;
    mywall[i] = line;
    i++;
  }
  report ("Finished adding pic to wall. New size of wall: "+ sizeof(mywall));
  return mywall;
}

int is_last_character(int p, string line){
  int i;
  string ch;
  if (i>= strlen(line)) return 0;
  for (i=p+1; i<strlen(line); i++)
  {
    ch = line [i..i];
    if (ch!= " ") return 0;
  }
  return 1;
}

mapping query_climbers(){
  return climbers;
}

string * add_climbers_to_wall(){
  string * mywall,* cs, c, line;
  int * positions;
  if (sizeof(climbers)<1) return wall;
  mywall = ({});
  foreach(line in wall)
  {
    mywall += ({line});
  }
  cs = keys(climbers);
  report("About to add climbers. Number: " + sizeof(climbers));
  report_limb_positions();
  report ("Size of wall: " + sizeof(mywall));
  foreach(c in cs)
  {

    if (!stringp(c)) continue;
    report ("Adding climber: " + c);
    mywall = add_climber_to_wall(c, mywall);
  }
  report ("Finished adding climbers");
  report_limb_positions();
  report ("Size of wall: " + sizeof(mywall));
  return mywall;
}

void show_wall(object who){
  int screen_width, screen_height, my_x, my_y, left, right, * limbs, i;
  string line, name, col_line, bg_line;
  string * mywall;
  if (unreport ==1) return;
  report ("Show wall. Size of wall: " + sizeof(wall) + " Size of wall_colours: " + sizeof(wall_colours) + " Size of bg_colours: " + sizeof(bg_colours));
  report_limb_positions();
  mywall = add_climbers_to_wall();
  temp_colours = wall_colours;
  temp_bg = bg_colours; 

  screen_width = atoi(who->getenv("SCREEN"));
  screen_height = atoi(who->getenv("LINES"));
  if (screen_width<10) screen_width = 75;
  limbs = query_positions(who->query_name());
  report("showwall 2 left hand pos: " + limbs[L_HAND] + " right hand pos: " + limbs[R_HAND] + " left leg pos: " + limbs[L_LEG] + " right leg pos: " + limbs[R_LEG] + " body pos: " + limbs[BODY], 4);
  my_x = limbs[BODY] % 10000;
  my_y = limbs[BODY] / 10000;
  if (sizeof(mywall) > screen_height)
  {
    report ("Trimming height of my_wall. my_y: " + my_y + " screen_height: " + screen_height);
    report ("my_y - screen_height/2-1: " + (my_y - screen_height/2-1) + " my_y + screen_height/2 +1: " + (my_y + screen_height/2 +1));
    mywall = mywall[my_y - screen_height/2-1..my_y + screen_height/2 +1];
    temp_colours = temp_colours[my_y - screen_height/2-1..my_y + screen_height/2 +1];
    temp_bg = temp_bg[my_y - screen_height/2-1..my_y + screen_height/2 +1]; 
  }
  i = 0;
  report("%^BOLD%^%^YELLOW%^left_x: " + (my_x-screen_width/2+1) + " right_x: " + (my_x+ screen_width/2-1));
  report_limb_positions();
  foreach(line in mywall)
  {
    if(my_x<screen_width/2+1) my_x = screen_width/2+1;
    if (my_x> strlen(line) - screen_width/2-1) my_x = strlen(line) - screen_width/2-1;
    if (strlen(line)>screen_width)
    {
      line = line[my_x-screen_width/2+1..my_x+ screen_width/2-1];
      mywall[i] = line;
    }
    i ++;
  }
  i = 0;
  foreach(line in temp_colours)
  {
    if(my_x<screen_width/2+1) my_x = screen_width/2+1;
    if (my_x> strlen(line) - screen_width/2-1) my_x = strlen(line) - screen_width/2-1;
    if (strlen(line)>screen_width)
    {
      line = line[my_x-screen_width/2+1..my_x+ screen_width/2-1];
      temp_colours[i] = line;
    }
    i ++;
  }
  i=0;
  foreach(line in temp_bg)
  {
    if(my_x<screen_width/2+1) my_x = screen_width/2+1;
    if (my_x> strlen(line) - screen_width/2-1) my_x = strlen(line) - screen_width/2-1;
    if (strlen(line)>screen_width)
    {
      line = line[my_x-screen_width/2+1..my_x+ screen_width/2-1];
      temp_bg[i] = line;
    }
    i ++;
  }
  report("showwall 3");
  report_limb_positions();
  mywall = colour_wall(mywall);
  
  foreach(line in mywall)
  {
    tell_object(who, line);
  }
  limbs = query_positions(who->query_name());
  report("left hand pos: " + limbs[L_HAND] + " right hand pos: " + limbs[R_HAND] + " left leg pos: " + limbs[L_LEG] + " right leg pos: " + limbs[R_LEG] + " body pos: " + limbs[BODY], 4);
}


varargs int start_reporting(object ob, int num){
  reportee = ob->query_name();
  if (intp(num) && num >0) report_nums += ({num});
  else report_nums = ({});
  return 1;
}

int stop_reporting(){
  reportee = "none";
  report_nums = ({});
  return 1;
}



varargs void report(string str, int num){
  if (sizeof(report_nums)>0) 
  {
    if (!intp(num) || num ==0 || member_array (num, report_nums)==-1) return;
  }
  if (!stringp(reportee) || reportee == "none") return;
  "/daemon/reporter_d"->report(reportee, str);
}

int * query_lh_pic_no(int * limbs){
  int limb_x, limb_y;
    limb_x = 3 + limbs[L_HAND]%10000 - limbs[BODY]%10000 ;
    limb_y = 3 + limbs[L_HAND]/10000 - limbs[BODY]/10000;
    report ("Limb number: " + (limb_x + limb_y *10));
    return limb_x + limb_y *10;
}

int * query_rh_pic_no(int * limbs){
  int limb_x, limb_y;
    limb_x = -2+ limbs[R_HAND]%10000 - limbs[BODY]%10000 ;
    limb_y = 3 + limbs[R_HAND]/10000 - limbs[BODY]/10000;
    report ("%^BOLD%^%^RED%^RIGHT ARM Limb number: " + (limb_x + limb_y *10));
    return limb_x + limb_y *10;
}

int * query_ll_pic_no(int * limbs){
  int limb_x, limb_y;
    limb_x = 2 + limbs[L_LEG]%10000 - limbs[BODY]%10000 ;
    limb_y = -1+ limbs[L_LEG]/10000 - limbs[BODY]/10000;
    report ("Limb number: " + (limb_x + limb_y *10));
    return limb_x + limb_y *10;
}

int * query_rl_pic_no(int * limbs){
  int limb_x, limb_y;
    limb_x =  -1 + limbs[R_LEG]%10000 - limbs[BODY]%10000 ;
    limb_y =  -1+limbs[R_LEG]/10000 - limbs[BODY]/10000;
    report ("Limb number: " + (limb_x + limb_y *10));
    return limb_x + limb_y *10;
}

string * get_medium_climber_pic(object climber){
  string * climber_names, name, * result, * limb_pic, display_name, line;
  int * limbs, l_hand_pos, r_hand_pos, l_leg_pos, r_leg_pos, limb_x, limb_y, pic_no, i,j, flag;
  report("%^BOLD%^%^MAGENTA%^get_medium_climer_pic 1");
  report_limb_positions();

  if (!objectp(climber)) return ({});
  name = climber->query_name();
  if (!mapp(climbers) || sizeof(climbers)<1) return ({});
  climber_names = keys (climbers);
  if (member_array(name, climber_names)==-1) return ({});
  limbs  = climbers[name];
  report("%^BOLD%^%^MAGENTA%^get_medium_climer_pic 2");
  report_limb_positions();

  if (climber->query_tripped())
  {
    result = add_name(climber, TRIPPED);
    return result;
  }
  report("%^BOLD%^%^MAGENTA%^get_medium_climer_pic 3");
  report_limb_positions();

  if (is_dangling(name)||is_hanging(name)) 
  {
    if (climber->query_property("swinging") == 1)
    {
      return SWING_RIGHT;
    }
    if (climber->query_property("swinging") == 2)
    {
      return SWING_LEFT;
    }
  }
  if (is_dangling(name)) 
  {
    report("%^BOLD%^%^MAGENTA%^get_medium_climer_pic 3.2");
    report_limb_positions();
    if (limbs[R_HAND] >0 )
    {
      result = DANGLING_RH;
      result = add_right_arm(result, 2, 1);
      result = add_name(climber, result);
      report("%^BOLD%^%^MAGENTA%^get_medium_climer_pic 4");
      report_limb_positions();

    }
    else
    {
      result = DANGLING_LH;
//      result = add_left_arm(result, 3, 0);
      result = add_name(climber, result);
      report("%^BOLD%^%^MAGENTA%^get_medium_climer_pic 5");
      report_limb_positions();
    }
    return result;
  }
  result = MED_BODY;
  report("%^BOLD%^%^MAGENTA%^get_medium_climer_pic 6");
  report_limb_positions();

  // Add the left arm
  if (limbs[L_HAND]==-1)
  {
    result = add_left_arm(result, 53);
  } else
  {
    pic_no = query_lh_pic_no(limbs);
    result = add_left_arm(result, pic_no);
  }
  // Add the right arm
  if (limbs[R_HAND]==-1)
  {
    result = add_right_arm(result, 52);
  } else
  {
    pic_no = query_rh_pic_no(limbs);
    result = add_right_arm(result, pic_no);
  }
  // Add the left leg
  if (limbs[L_LEG]==-1)
  {
    result = add_left_leg(result, 23);
  } else
  {
    pic_no = query_ll_pic_no(limbs);
    result = add_left_leg(result, pic_no);
  }

  // Add the right leg
  if (limbs[R_LEG]==-1)
  {
    result = add_right_leg(result, 21);
  } else
  {
    pic_no = query_rl_pic_no(limbs);
    result = add_right_leg(result, pic_no);
  }
  result = add_name(climber, result);
  return result;
}

string * add_name(object climber, string * arr)
{
  int i, j, end, flag;
  string line, name, display_name;
  if (!objectp(climber)) return arr;
  name = climber->query_name();
  if (TP->isKnown(name))
  {
    display_name = capitalize(TP->knownAs(name));
  } else 
  {
    display_name = capitalize(climber->query_race());
  }
  line = arr[0];
  flag = 0;
  end = strlen(display_name)-1;
  for (i=0;i<sizeof(arr)-1;i++)
  {
    report("Checking line " + i);
    line = arr[i+1];
    for (j=0;j<strlen(line) && j< strlen(display_name); j++)
    {
      if (line[j..j] != " ") 
      {
        report("found a non-space character at point " + j);
        flag = 1;
        if(i==0) end = j-3;
        break;
      }
    }
    if (flag==1)
    {
      line = arr[i];
      break;
    } 
  }
  if (flag == 0) i--;
  report ("About to insert string: '" + display_name + "' to line: '" + line + "'"); 
  line = "/daemon/str_insert_d"->insert_string(line, display_name[0..end], 0);
  arr[i] = line;
  return arr;
}

string * add_left_leg(string * pic, int limb_no){
  string * limb_pic;
  switch(limb_no)
  {
  case 0:
    limb_pic = L_LEG_0;
    break;
  case 1:
    limb_pic = L_LEG_1;
    break;
  case 2:
    limb_pic = L_LEG_2;
    break;
  case 3:
    limb_pic = L_LEG_3;
    break;
  case 4:
    limb_pic = L_LEG_4;
    break;
  case 10:
    limb_pic = L_LEG_10;
    break;
  case 11:
    limb_pic = L_LEG_11;
    break;
  case 12:
    limb_pic = L_LEG_12;
    break;
  case 13:
    limb_pic = L_LEG_13;
    break;
  case 14:
    limb_pic = L_LEG_14;
    break;
  case 21:
    limb_pic = L_LEG_21;
    break;
  case 22:
    limb_pic = L_LEG_22;
    break;
  case 23:
    limb_pic = L_LEG_23;
    break;
  case 24:
    limb_pic = L_LEG_24;
    break;
  case 33:
    limb_pic = L_LEG_33;
    break;
  default:
    limb_pic = ({});
    break;
  }
//  if (sizeof(limb_pic)<1) report("sizeof(limb_pic)<1"); 
  pic = add_limb(pic, limb_pic, 0,3);
  return pic;
}

void report_limb_pic_nos(string name){
  int * limbs, i;
  limbs = query_positions(name);
  if (sizeof(limbs)<5) 
  {
    tell_object(TP, name + " Does not have a full set of limbs recorded.");
    return;
  }
  tell_object(TP, "Left hand pic_no: " + query_lh_pic_no(limbs));
  tell_object(TP, "Right hand pic_no: " + query_rh_pic_no(limbs));
  tell_object(TP, "Left leg pic_no: " + query_ll_pic_no(limbs));
  tell_object(TP, "Right leg pic_no: " + query_rl_pic_no(limbs));
}


string * add_right_leg(string * pic, int limb_no){
  string * limb_pic;
  report ("limb_no: " + limb_no, 12);
  switch(limb_no)
  {
  case 0:
    report ("Adding R_LEG_0", 12);
    limb_pic = R_LEG_0;
    break;
  case 1:
    limb_pic = R_LEG_1;
    report ("Adding R_LEG_1", 12);
    break;
  case 2:
    report ("Adding R_LEG_2", 12);
    limb_pic = R_LEG_2;
    break;
  case 3:
    report ("Adding R_LEG_3", 12);
    limb_pic = R_LEG_3;
    break;
  case 4:
    report ("Adding R_LEG_4", 12);
    limb_pic = R_LEG_4;
//    limb_pic = ({"    ","  /\\,","    ","    ","    "});
    break;
  case 5: 
    report ("Adding R_LEG_5", 12);
    limb_pic = R_LEG_5;
    break;
  case 10:
    report ("Adding R_LEG_10", 12);
    limb_pic = R_LEG_10;
    break;
  case 11:
    report ("Adding R_LEG_11", 12);
    limb_pic = R_LEG_11;
    break;
  case 12:
    report ("Adding R_LEG_12", 12);
    limb_pic = R_LEG_12;
    break;
  case 13:
    report ("Adding R_LEG_13", 12);
    limb_pic = R_LEG_13;
    break;
  case 14:
    report ("Adding R_LEG_14", 12);
    limb_pic = R_LEG_14;
    break;
  case 15:
    report ("Adding R_LEG_15", 12);
    limb_pic = R_LEG_15;
    break;
  case 20:
    report ("Adding R_LEG_20", 12);
    limb_pic = R_LEG_20;
    break;
  case 21:
    report ("Adding R_LEG_21", 12);
    limb_pic = R_LEG_21;
    break;
  case 22:
    report ("Adding R_LEG_22", 12);
    limb_pic = R_LEG_22;
    break;
  case 23:
    report ("Adding R_LEG_23", 12);
    limb_pic = R_LEG_23;
    break;
  case 24:
    report ("Adding R_LEG_24", 12);
    limb_pic = R_LEG_24;
    break;
  case 31:
    report ("Adding R_LEG_31", 12);
    limb_pic = R_LEG_31;
    break;
  case 32:
    report ("Adding R_LEG_32", 12);
    limb_pic = R_LEG_32;
    break;
  default:
    limb_pic = ({});
  }
  if (sizeof(limb_pic)<1) report("sizeof(limb_pic)<1"); 
  pic = add_limb(pic, limb_pic, 3,3);
  return pic;
}

varargs string * add_left_arm(string * pic, int limb_no, int dangling){
  string * limb_pic;
  switch(limb_no)
  {
  case 3:
    limb_pic = L_ARM_3;
    break;
  case 11:
    limb_pic = L_ARM_11;
    break;
  case 12:
    limb_pic = L_ARM_12;
    break;
  case 13:
    limb_pic = L_ARM_13;
    break;
  case 14:
    limb_pic = L_ARM_14;
    break;
  case 15:
    limb_pic = L_ARM_15;
    break;
  case 21:
    limb_pic = L_ARM_21;
    break;
  case 22:
    limb_pic = L_ARM_22;
    break;
  case 23:
    limb_pic = L_ARM_23;
    break;
  case 24:
    limb_pic = L_ARM_24;
    break;
  case 25:
    limb_pic = L_ARM_25;
    break;
  case 30:
    limb_pic = L_ARM_30;
    break;
  case 31:
    limb_pic = L_ARM_31;
    break;
  case 32:
    limb_pic = L_ARM_32;
    break;
  case 33:
    limb_pic = L_ARM_33;
    break;
  case 34:
    limb_pic = L_ARM_34;
    break;
  case 35:
    limb_pic = L_ARM_35;
    break;
  case 41:
    limb_pic = L_ARM_41;
    break;
  case 42:
    limb_pic = L_ARM_42;
    break;
  case 43:
    limb_pic = L_ARM_43;
    break;
  case 44:
    limb_pic = L_ARM_44;
    break;
  case 45:
    limb_pic = L_ARM_45;
    break;
  case 51:
    limb_pic = L_ARM_51;
    break;
  case 52:
    limb_pic = L_ARM_52;
    break;
  case 53:
    limb_pic = L_ARM_53;
    break;
  case 54:
    limb_pic = L_ARM_54;
    break;
  default:
    limb_pic = ({});
  }
  if (sizeof(limb_pic)<1) report("sizeof(limb_pic)<1"); 
  if (dangling >0) pic = add_limb(pic, limb_pic, 1,0);//blah
  else pic = add_limb(pic, limb_pic, 0,0);
  return pic;
}

varargs string * add_right_arm(string * pic, int limb_no, dangling){
  string * limb_pic;
  switch(limb_no)
  {
  case 1:
    limb_pic = R_ARM_1;
    break;
  case 2: 
    limb_pic = R_ARM_2;
    break;
  case 10:
    limb_pic = R_ARM_10;
    break;
  case 11:
    limb_pic = R_ARM_11;
    break;
  case 12:
    limb_pic = R_ARM_12;
    break;
  case 13:
    limb_pic = R_ARM_13;
    break;
  case 14:
    limb_pic = R_ARM_14;
    break;
  case 20:
    limb_pic = R_ARM_20;
    break;
  case 21:
    limb_pic = R_ARM_21;
    break;
  case 22:
    limb_pic = R_ARM_22;
    break;
  case 23:
    limb_pic = R_ARM_23;
    break;
  case 24:
    limb_pic = R_ARM_24;
    break;
  case 30:
    limb_pic = R_ARM_30;
    break;
  case 31:
    limb_pic = R_ARM_31;
    break;
  case 32:
    limb_pic = R_ARM_32;
    break;
  case 33:
    limb_pic = R_ARM_33;
    break;
  case 34:
    limb_pic = R_ARM_34;
    break;
  case 35:
    limb_pic = R_ARM_35;
    break;
  case 40:
    limb_pic = R_ARM_40;
    break;
  case 41:
    limb_pic = R_ARM_41;
    break;
  case 42:
    limb_pic = R_ARM_42;
    break;
  case 43:
    limb_pic = R_ARM_43;
    break;
  case 44:
    limb_pic = R_ARM_44;
    break;
  case 50:
    limb_pic = R_ARM_50;
    break;
  case 51:
    limb_pic = R_ARM_51;
    break;
  case 52:
    limb_pic = R_ARM_52;
    break;
  case 53:
    limb_pic = R_ARM_53;
    break;
  case 54:
    limb_pic = R_ARM_54;
    break;
  default:
    limb_pic = ({});
  }
  if (sizeof(limb_pic)<1) report("sizeof(limb_pic)<1"); 
  if (dangling >0) pic = add_limb(pic, limb_pic, 2,0);//blah
  else pic = add_limb(pic, limb_pic, 4,0);
  return pic;
}


int test_handhold(string name, int limb, int penalty){
  int grip_strength, pos, * limbs, * grips;
  string * cs;
  report ("Testing " + name + "'s grip with limb no " + limb + ". Penalty: " + penalty, 2);
  limbs = query_positions(name);
  if (!mapp(climb_grips) || sizeof(climb_grips)<1) return -1;
  cs = keys(climb_grips);
  if (member_array  (name, cs)==-1) return -2;
  grips = climb_grips[name];
  grip_strength = grips[limb];
  report ("Grip strength: " + grip_strength + " Target number: " + (490 - (grip_strength * grip_strength *10) + penalty) , 2);  
  if (random(5490) +1 < 490 - (grip_strength * grip_strength *10) + penalty) return 0;
  return 1;
}

int count_grips(string name){
  int num, * limbs, i;
  limbs = query_positions(name);
  if (sizeof(limbs)<4) return -1;
  num = 0;
  for (i=0;i<4;i++)
  {
    if (limbs[i] >-1) num++;
  }
  return num;
}

int * query_grips(string name){
  int * grips;
  string * cs;
  if (!mapp(climb_grips) || sizeof(climb_grips)<1) return ({});
  cs = keys(climb_grips);
  if (member_array(name, cs )==-1) return ({});
  grips = climb_grips[name];
  return grips;
}


varargs int check_grip_failure_on_limb_move(string name, int limb, object room){
  int i, num, result, penalty, grip, * limbs, * limb_positions, flag;
  string * cs, limb_name;
  object climber, * players;
  report ("check_grip_failure_on_limb_move: name: " + name + " limb: " + limb , 1);
  if (unreport ==1) return 0;
  flag = 0;
  if (!objectp(room))
  {
    players = children("/std/user.c");
    report("About to check " + sizeof(players) + " climbers", 1);
    foreach(climber in players)
    {
      report("Checking a climber: " + climber, 1);
      if (objectp(climber) && climber->query_name()==name)
      {
        flag =1;
        break;
      }
    }
    if (flag ==0)
    {
      report("%^BOLD%^%^CYAN%^Did not find climber amongst players. Room is broken", 1);
      climber = 0;
    }
  } else
  {
    climber = get_climber(name, room);
    if (!objectp(climber)) report ("%^BOLD%^%^YELLOW%^Failed to load climber: " + name, 1);
  }
  limbs = query_grips(name);
  num = count_grips(name);
  switch(num)
  {
  case 0:
    penalty = 8;
    break;
  case 1:
    penalty = 7;
    break;
  case 2:
    penalty = 5;
    break;
  case 3:
    penalty = 1;
    break;
  case 4:
    penalty = 0;
    break;
  }
  for (i=0;i<4;i++)
  {
    report ("checking limb no: " + i);
    switch(i)
    {
    case 0:
      limb_name = "left hand";
      break;
    case 1:
      limb_name = "right hand";
      break;
    case 2:
      limb_name = "left foot";
      break;
    case 3:
      limb_name = "right foot";
      break;
    }
    if (i==limb)
    {
      report("%^CYAN%^Limb no: " + i + " is the limb that is moving. Continuing...", 1);
      continue;
    }
    grip = query_grip(name, i);
    if (grip == -1)
    {
      report ("limb no : " + i + " has no grip. Continuing", 1);
      continue;
    }
    limb_positions = query_positions(name);
    if (limb_positions[i]/ 10000 >= sizeof(wall)-1) 
    {
      report("You can't lose your grip on the ground. Continuing", 1);
      continue;
    }
    result = test_handhold(name, i, penalty);
    report ("%^BOLD%^%^GREEN%^RESULT for limb : " + i + " is : " + result, 1); 
    switch(result)
    {
    case -1:
      report("Error 1 on checking grip failure", 1);
      break;
    case -2:
      report("Error 2 on checking grip failure", 1);
      break;
    case 0:
      report ("Grip failure on limb: " + i, 1); 
      flag = 1;
      report("%^B_ORANGE%^%^BOLD%^%^WHITE%^About to check whether climber is a valid object", 1);
      if (objectp(climber))
      {
        tell_object(climber, "%^BOLD%^%^RED%^Your " + limb_name + " slips and you lose your grip!" );   
        report("%^B_MAGENTA%^%^BOLD%^%^WHITE%^Climber is a valid object", 1);
        report("Climber name: ", 1);
        report(climber->query_name(), 1);
      }
      else report ("%^BOLD%^%^MAGENTA%^Error loading climber", 1);
      if (objectp(room)) tell_room(room, "%^BOLD%^%^RED%^" + climber->QCN + "%^BOLD%^%^RED%^'s " + limb_name + " slips and " + climber->QS + " loses " + climber->QP + " grip!", climber );   
      else report ("%^BOLD%^%^MAGENTA%^Error loading room", 1);
      limbs[i] = -1;
      climb_grips[name] = limbs;
      limb_positions = query_positions(name);
      limb_positions[i] = -1;
      climbers[name] = limb_positions;
      return check_grip_failure_on_limb_move(name, limb, room);
      break;
    case 1:
      report ("Grip HELD on limb: " + i, 1); 
      continue;
      break;      
    }
  }
  num = count_grips(name);
  if (num<1){
    fall(name, room);
  }
  return flag;
}

void remove_climber(string name){
  string * cs;
  if (!mapp(climbers) || sizeof(climbers)<1) climbers = ([]);
  if (!mapp(climb_grips) || sizeof(climb_grips)<1) climb_grips = ([]);
  cs = keys(climbers);
  if (member_array(name, cs)!= -1) climbers = m_delete( climbers, name);
  cs = keys(climb_grips);
  if (member_array(name, cs)!= -1) climb_grips = m_delete( climb_grips, name);
}

void fall(string name, object room){
  object climber;
  int height, loc, * limbs, limb;
  climber= get_climber(name);
  limbs = query_positions(name);
  if (objectp(climber))
  {
    tell_object(climber, "You fall off the wall");
    if (objectp(room)) tell_room(room, climber->QCN + " falls off the wall", climber);
    loc = limbs[BODY];
    height = sizeof(wall) - loc/10000;
    climber->set_tripped(10);
    climber->cause_typed_damage(climber, climber->return_target_limb(), height * height * 10, "bludgeoning");
    limbs[L_HAND] = -1;
    limbs[R_HAND] = -1;
    limbs[BODY] = loc + (height-5) * 10000;
    limbs[L_LEG] = limbs[BODY] + 40001;
    limbs[R_LEG] = limbs[L_LEG] +2;
    climbers[name] = limbs;
  }
}

int show_pic(string * pic, object ob){
  string line;
  if (!objectp(ob)) return -1;
  if (sizeof(pic)<1) return -2;
  foreach(line in pic)
  {
    tell_object(ob, line);
  }
}




mapping get_reachable_handholds(string name){
  mapping result, limb_positions;
  string * cs;
  int * positions, * temp_pos, i, leftmost, topmost,bottommost, rightmost, body_pos, * locs, x, y;
  positions = query_positions(name);
  report("Getting reachable handholds for " + name, 1);
  result = ([]);
  unreport = 1;
  if (sizeof(positions)<1) return result;
  temp_pos = ({});
  foreach(i in positions) //copy starting positions
  {
    temp_pos += ({i});
  }
  limb_positions = ([]); // Find handholds available to left hand
  move_limb_left(name, L_HAND);
  if (positions[L_HAND] != temp_pos[L_HAND])
  {
    limb_positions["left"] = positions[L_HAND];
  }
  positions[L_HAND] = temp_pos[L_HAND];
  positions[BODY] = temp_pos[BODY];
  move_limb_right(name, L_HAND);
  if (positions[L_HAND] != temp_pos[L_HAND])
  {
    limb_positions["right"] = positions[L_HAND];
  }
  positions[L_HAND] = temp_pos[L_HAND];
  positions[BODY] = temp_pos[BODY];
  move_limb_up(name, L_HAND);
  if (positions[L_HAND] != temp_pos[L_HAND])
  {
    limb_positions["up"] = positions[L_HAND];
  }
  positions[L_HAND] = temp_pos[L_HAND];
  positions[BODY] = temp_pos[BODY];
  move_limb_down(name, L_HAND);
  if (positions[L_HAND] != temp_pos[L_HAND])
  {
    limb_positions["down"] = positions[L_HAND];
  }
  positions[L_HAND] = temp_pos[L_HAND];
  positions[BODY] = temp_pos[BODY];
  result["left hand"] = limb_positions;

  limb_positions = ([]); // Find handholds available to right hand
  move_limb_left(name, R_HAND);
  if (positions[R_HAND] != temp_pos[R_HAND])
  {
    limb_positions["left"] = positions[R_HAND];
  }
  positions[R_HAND] = temp_pos[R_HAND];
  positions[BODY] = temp_pos[BODY];
  move_limb_right(name, R_HAND);
  if (positions[R_HAND] != temp_pos[R_HAND])
  {
    limb_positions["right"] = positions[R_HAND];
  }
  positions[R_HAND] = temp_pos[R_HAND];
  positions[BODY] = temp_pos[BODY];
  move_limb_up(name, R_HAND);
  if (positions[R_HAND] != temp_pos[R_HAND])
  {
    limb_positions["up"] = positions[R_HAND];
  }
  positions[R_HAND] = temp_pos[R_HAND];
  positions[BODY] = temp_pos[BODY];
  move_limb_down(name, R_HAND);
  if (positions[R_HAND] != temp_pos[R_HAND])
  {
    limb_positions["down"] = positions[R_HAND];
  }
  positions[R_HAND] = temp_pos[R_HAND];
  positions[BODY] = temp_pos[BODY];
  result["right hand"] = limb_positions;

  limb_positions = ([]); // Find handholds available to left leg
  move_limb_left(name, L_LEG);
  if (positions[L_LEG] != temp_pos[L_LEG])
  {
    limb_positions["left"] = positions[L_LEG];
  }
  positions[L_LEG] = temp_pos[L_LEG];
  positions[BODY] = temp_pos[BODY];
  move_limb_right(name, L_LEG);
  if (positions[L_LEG] != temp_pos[L_LEG])
  {
    limb_positions["right"] = positions[L_LEG];
  }
  positions[L_LEG] = temp_pos[L_LEG];
  positions[BODY] = temp_pos[BODY];
  move_limb_up(name, L_LEG);
  if (positions[L_LEG] != temp_pos[L_LEG])
  {
    limb_positions["up"] = positions[L_LEG];
  }
  positions[L_LEG] = temp_pos[L_LEG];
  positions[BODY] = temp_pos[BODY];
  move_limb_down(name, L_LEG);
  if (positions[L_LEG] != temp_pos[L_LEG])
  {
    limb_positions["down"] = positions[L_LEG];
  }
  positions[L_LEG] = temp_pos[L_LEG];
  positions[BODY] = temp_pos[BODY];
  result["left leg"] = limb_positions;

  limb_positions = ([]); // Find handholds available to right leg
  move_limb_left(name, R_LEG);
  if (positions[R_LEG] != temp_pos[R_LEG])
  {
    limb_positions["left"] = positions[R_LEG];
  }
  positions[R_LEG] = temp_pos[R_LEG];
  positions[BODY] = temp_pos[BODY];
  move_limb_right(name, R_LEG);
  if (positions[R_LEG] != temp_pos[R_LEG])
  {
    limb_positions["right"] = positions[R_LEG];
  }
  positions[R_LEG] = temp_pos[R_LEG];
  positions[BODY] = temp_pos[BODY];
  move_limb_up(name, R_LEG);
  if (positions[R_LEG] != temp_pos[R_LEG])
  {
    limb_positions["up"] = positions[R_LEG];
  }
  positions[R_LEG] = temp_pos[R_LEG];
  positions[BODY] = temp_pos[BODY];
  move_limb_down(name, R_LEG);
  if (positions[R_LEG] != temp_pos[R_LEG])
  {
    limb_positions["down"] = positions[R_LEG];
  }
  positions[R_LEG] = temp_pos[R_LEG];
  positions[BODY] = temp_pos[BODY];
  result["right leg"] = limb_positions;

  positions = ({});   //reset positions to original state
  foreach(i in temp_pos)
  { 
    positions += ({i});

  }
  unreport = 0;
  return result;
//int is_valid_limb_position(string climber, int limb, int x, int y)  
}


int add_climber(object climber, int l_hand, int r_hand, int l_leg, int r_leg, int body){
  string name, * climber_names;
  if (!objectp(climber)) return -1;
  name = climber->query_name();
  if (!mapp(climbers) || sizeof(climbers)<1) climbers = ([]);
  climber_names = keys(climbers);
  while (sizeof(climber_names)<1 && member_array(name, climber_names) != -1)
  {
    m_delete (climbers, name);
    climber_names = keys(climbers);
  }
//  climbers[name] = ({l_hand, r_hand, l_leg, r_leg, body});
  climbers[name] = ({-1, -1, l_leg, r_leg, body});
}

string describe_jump_difficulty(string name, int loc){
  int * positions, bod_loc, athletics, x_dist, y_dist, difficulty, challenge;
  float distance;
  object climber;
  string result, number;
  climber = get_climber(name);
  if (objectp(climber)) athletics = climber->query_skill("athletics");
  else athletics = 0;
  positions = query_positions(name);
  bod_loc = positions[BODY];
  x_dist = bod_loc % 10000 - loc % 10000;
  y_dist = bod_loc / 10000 - loc / 10000;
  if (y_dist < 0) 
  {
    y_dist += 3;
    while(y_dist>0) y_dist --;
  }
  if (y_dist > 0) 
  {
    y_dist -= 3;
    while(y_dist<0) y_dist ++;
  }

  if (x_dist < 0) 
  {
    x_dist += 3;
    while(x_dist>0) x_dist --;
  }
  if (x_dist > 0) 
  {
    x_dist -= 3;
    while(x_dist<0) x_dist ++;
  }


  distance = sqrt(x_dist * x_dist + y_dist * y_dist);
  challenge = get_handhold_challenge(loc);
  report ("Describe jump difficulty. x_dist: " + x_dist +" y_dist " + y_dist + " ditance: " + distance + " challenge: " + challenge + " athletics: " + athletics, 5);  
  number = "" + (distance *distance/2 - (8-challenge) - (athletics / 15));
  difficulty = atoi(number); //bluh
  if (difficulty<0) difficulty = 0;
  report("About to describe jump difficulty. Difficulty number: " + difficulty, 5);
  switch(difficulty)
  {
  case 0..1:
    result = "an easy";
    break;
  case 2..3:
    result = " a somewhat challenging";
    break;
  case 4..5:
    result = " a difficult";
    break;
  case 6..7:
    result = " a very difficult";
    break;
  case 8..9:
    result = " an extremely difficult";
    break;
  case 10..100:
    result = "an impossibly hard";
    break;
  }
  return result;
}

string describe_reachable_handholds(string name, string arg){
  mapping handholds, locations, jumpable_handholds;
  string * limbs, limb, * directions, direction, result, handhold_name, handhold_description, * excluded_limbs, limbresult, *jumpable_directions, jump_result, difficulty_description, distance_description, my_limb;
  int loc, x_dist, y_dist, start_left, start_right, start_bottom, start_top, h_start, h_end, v_start, v_end, * positions, body_loc;
  handholds = get_reachable_handholds(name);
  jumpable_handholds = get_jumpable_handholds (name);
  excluded_limbs = ({});
  report("Describe reachable handholds 1 - result: " + result, 6);
  if (!mapp(handholds) || sizeof(handholds)<1) return "You cannot reach any new handholds from here";  
  limbs = keys(handholds);
  jumpable_directions = keys(jumpable_handholds);
  jump_result = "";
  report("%^BOLD%^%^CYAN%^Initial number of handholds identified: " + sizeof(limbs), 6);
  switch(arg)
  {
  case "above":  
  case "up":    //deliberately falling through
  case "below": //deliberately falling through
  case "down":  //deliberately falling through
  case "left":  //deliberately falling through
  case "right": //deliberately falling through
    positions = query_positions(name);
    report("Limiting by direction " + arg);
    excluded_limbs = ({});
    foreach(limb in limbs)
    {
      report("checking limb " + limb);
      locations = handholds[limb];
      directions = keys(locations);
      if (member_array(arg, directions)==-1) 
      {
        report("%^BOLD%^%^CYAN%^Removing limb " + limb + " from handholds, as it has no available handholds in the " + direction +" direction");
        m_delete(handholds, limb);
        excluded_limbs += ({limb});
      }
      else 
      {
        report("%^BOLD%^%^MAGENTA%^Removing unwanted directions for limb: " + limb);
        foreach(direction in directions)
        {
          report("   Checking direcion " + direction + " for limb " + limb);
          if (direction != arg) locations = m_delete(locations, direction);
          else report ("   Retaining direction " + direction + " for limb " + limb);
        }
      }
      handholds[limb] = locations;
    }
    if (sizeof(handholds)<1) return "You cannot reach any handholds in that direction";
    break;
  case "left hand":
  case "right hand":
  case "left leg":
  case "right leg":
    report("Limiting by limb " + arg, 6);
    foreach(limb in limbs)
    {
      report("Checking limb " + limb);
      if (limb != arg)
      {
        handholds = m_delete(handholds, limb);
      }
      else report ("Retaining limb " + limb);
    }    
    if (sizeof(handholds)<1) return "You cannot reach any handholds with your " + arg;
    break;
  }
  report("Describe reachable handholds 2 - result: " + result + " sizeof(handholds): " + sizeof(handholds) + "  %^BOLD%^%^YELLOW%^Arg: " + arg, 6);

  result = "";
  limbs = keys(handholds);
  switch(arg)
  {
  case "above":  
  case "up":    //deliberately falling through
  case "below": //deliberately falling through
  case "down":  //deliberately falling through
  case "left":  //deliberately falling through
  case "right": //deliberately falling through 
    report("%^CYAN%^arg is a direction: " + arg, 6);
    direction = arg;
    if ( member_array(arg, jumpable_directions) == -1 || jumpable_handholds[arg] ==0)
    {
      jump_result = "There is no handhold you can jump to in that direction";
    } else 
    {
      positions = query_positions(name);
      if (sizeof(positions)>=5) body_loc = positions[BODY];
      else body_loc = 0;
      if (positions[L_LEG] >0) start_left = positions[L_LEG]%10000;
      else start_left = positions[BODY]%10000;
      if (positions[R_LEG] >0) start_right = positions[R_LEG]%10000;
      else start_right = positions[BODY]%10000;
      if (start_right < jumpable_handholds[arg])
      {
        h_start =  start_right;
        h_end = jumpable_handholds[arg]%10000;
      }
      else
      {
        h_start = start_left;
        h_end = jumpable_handholds[arg]%10000;
      }
      if (positions[L_LEG]>0) v_start = positions[L_LEG]/10000;
      if (positions[R_LEG]>0 && positions[R_LEG] > positions[L_LEG]) v_start = positions[R_LEG]/10000; 
      v_end = jumpable_handholds[arg]/10000;
      if (v_end < v_start) v_start = positions[BODY]/10000 -1;
      jump_result = "There is " + get_handhold_name(jumpable_handholds[arg]) + " you could jump to in that direction. It is " 
                  + describe_h_distance(h_start, h_end) + " and " + describe_v_distance(v_start , v_end) + ".";
      difficulty_description = describe_jump_difficulty(name, jumpable_handholds[arg]);
      jump_result += " This would be " + difficulty_description + " jump.";      
    }
    break;
    //No need to calculate jump positions if they entered a limb as an argument
  }
  report("Describe reachable handholds 3 - result: " + result, 6);

  if (direction == "above" || direction == "up"|| direction == "below"|| direction == "down" || direction == "left" || direction == "right")
  {
    report("Describe reachable handholds 4 - result: " + result, 6);

    switch(direction){

    case "up":
    case "above": //deliberately falling through 
      report("Reachable directions up or above", 6);
      direction = "up";
      break;
    case "down":  
    case "below": //deliberately falling through
      report("Reachable directions down or below", 6);
      direction = "down";
      break;
    case "left":
      report("Reachable directions left", 6);
      direction = "left";
      break;  
    case "right":
      report("Reachable directions right", 6);
      direction = "right";
      break; 
    }
    result = "%^CYAN%^";
    report("%^BOLD%^%^CYAN%^Describe reachable handholdsn 4a. Direction: %^RESET%^" + direction + " size of limbs: " + sizeof(limbs), 6);
    foreach(limb in limbs)  
    { 
      report("%^BOLD%^%^CYAN%^Describe reachable handholds. Checking limb: %^RESET%^" + limb, 6);
      if (member_array(limb, excluded_limbs)!=-1) continue;
      locations = handholds[limb];
      directions = keys(locations);
      if (member_array(direction, directions)==-1) continue;
      result += "You could move your %^RESET%^" + limb + " %^ORANGE%^" + direction + "%^CYAN%^ to "; 
      loc = locations[direction];
      handhold_name = get_handhold_name(loc);
      handhold_description = get_handhold_description(loc);
      result += handhold_name + " " + handhold_description + "."  + brief_location_position(loc) +"\n";
    }   
  } else
  {
    report("Describe reachable handholds 5 - result: " + result, 6);
    result = "";
    if (direction == "left hand" || direction == "right hand" || direction == "left leg" || direction == "right leg" ) my_limb = direction;
    else my_limb = "none";
    
    foreach(limb in limbs)  
    { 
      report("%^RED%^Describe reachable handholds - checking limb:%^RESET%^ " + limb);
      if (my_limb != "none" && my_limb != limb) continue;
      limbresult = "";
      if (member_array(limb, excluded_limbs)!=-1) continue;
      locations = handholds[limb];
      directions = keys(locations);
      foreach(direction in directions)
      {
        limbresult +="\n";
        loc = locations[direction];
        report("%^B_CYAN%^Getting description for limb: " + limb + ", direction: " + direction + ",  location: " + loc);
        switch(direction)
        {
        case "up":
        case "above":
          limbresult += "%^CYAN%^Above its current position: %^RESET%^";
          break;
        case "down":
        case "below":
          limbresult += "%^CYAN%^Below its current position: %^RESET%^";
          break;
        case "left":
        case "right":
          limbresult += "%^CYAN%^To the " + direction + " of its current position: %^RESET%^";
        }
        switch(limb)
        {
        case "left hand":
        case "right hand":
          handhold_name = get_handhold_name(loc);
          handhold_description = get_handhold_description(loc);
          break;
        case "left leg":
        case "right leg":
          handhold_name = get_foothold_name(loc);
          handhold_description = get_foothold_description(loc);
          break;
        }
        limbresult += handhold_name + " " + handhold_description + " " + brief_location_position(loc);
      }    
      if (limbresult == "") continue;
      result += "%^RESET%^%^ORANGE%^With your %^RESET%^" + limb + "%^ORANGE%^, you can reach:";
      result += limbresult;
      result += "\n"; 
    }
  }
  report("Describe reachable handholds 6 - result: " + result, 6);

  if (result == "") result = "You cannot reach any new hand or footholds";
  if (jump_result != "") result += "\n" + jump_result;
  return result;
}

string describe_location_position(int loc){
  string result, vert_desc, horiz_desc;
  int x, y;
  x = loc % 10000;
  y = loc / 10000;
  y = sizeof(wall) - y -1;
  if (y==0)
  {
    vert_desc = "at ground level";
  } else
  {
    vert_desc = "";
    vert_desc += y + " feet above the ground";
  }
  if (x==0)
  {
    horiz_desc = "At the left end of the wall";
  } else 
  {
    horiz_desc = "" + (x/2);
    if (x % 2 == 1) horiz_desc += " and a half";
    horiz_desc += " feet from the left and of the wall"; 
  }
  result = vert_desc + ", " + horiz_desc;
  return result;
}

string brief_location_position(int loc){
  string result;
  int x, y;
  x = loc % 10000;
  y = loc / 10000;
  y = sizeof(wall) - y-1;
  result = "(" + (x/2);
  if (x % 2 ==1) result += ".5";
  result += ", " + y + ")";
  return result;
}


string * add_limb (string * pic, string * limb, int x, int y){
  string line, picline, ch;
  int i, j;
  i = y;
  foreach(line in limb)
  {
    report("Adding limb at line " + i);
    if (i>sizeof(pic)) return;
    picline = pic[i];
    for (j = x;j<strlen(picline);j++)
    {
      ch = line[j-x..j-x];
      if (ch != " ")
      {  
        picline = "/daemon/str_insert_d.c"->insert_string(picline, ch, j);
      }
    }
    pic[i] = picline;
    i++;
  }
  return pic;
}

string describe_h_distance(int start, int finish){
  int distance;
  string result, direction;
  report("%^B_ORANGE%^Describe_h_distance. start: " + start + " finish: " + finish);
  if (start==finish || start == finish +1 || start== finish -1) return ("in line horizontally");
  if (start>finish)
  {
    direction = "left";
    distance = start-finish;
  } else 
  {
    direction = "right";
    distance = finish-start;
  }
  result = "" + (distance/2);
  if (distance % 2 ==1) result += " and a half"; 
  result += " feet to the " + direction;
  return result;
}

string describe_v_distance(int start, int finish){
  int distance;
  string result, direction;
  report("%^B_ORANGE%^Describe_v_distance. start: " + start + " finish: " + finish);
  if (start==finish) return ("on a level with you");
  if (start>finish)
  {
    direction = "above";
    distance = start-finish;
  } else 
  {
    direction = "below";
    distance = finish-start;
  }
  result = "" + distance;
  result += " feet " + direction + " you";
  return result;
}



string replace_char(string char){
  string result, * chars;
  chars = keys(HANDHOLDS);
  if (sizeof(chars)<1 || member_array(char, chars)==-1) return char;
  return HANDHOLDS[char];
}


string * colour_wall (string * pic){
  string * result, line, bg_line, ch, bg_ch, col_line, * ks, ins;
  int i, j, len, height;
  report ("colour_wall 1. Size of pic: " + sizeof(pic) + " Size of temp_colours: " + sizeof(temp_colours));
  if (sizeof(wall_colours)<1 || sizeof(bg_colours) < sizeof(wall_colours)) return pic;
  result = ({});
  height = sizeof(wall_colours);
  report ("colour_wall 2");
  for (i=0; i<height; i++)
  {
    if (sizeof(pic)<= i){
      report ("i: " + i + " size of pic: " + sizeof(pic) + " continuing");
      continue; 
    }
    line = pic[i];
    if (sizeof(wall_colours)<= i) continue; 
    col_line = temp_colours[i];
    if (sizeof(bg_colours)<= i) continue;
    if (i>0) bg_line = temp_bg[i];
    else bg_line = temp_bg[i];
    len = strlen(line);
    for (j = len-1; j>=0; j--)
    {
      ch = col_line[j..j];
      bg_ch = bg_line[j..j];
      ks = keys(COLOURS);
      if (member_array(ch, ks) != -1)
      {
        ins = COLOURS[ch];
        line = "/daemon/str_insert_d"->brute_insert_string(line, ins, j-1);
      }
      ks = keys(BG_COLS);
      if (member_array(bg_ch, ks) != -1)
      {
        ins = BG_COLS[bg_ch];
        line = "/daemon/str_insert_d"->brute_insert_string(line, ins, j-1);
      }
    }
    report("colour_wall: adding line " + i + " to picture.");
    result += ({line});
  }
  report ("colour_wall end. Size of result: " + sizeof(result));
  return result;
}

mapping * query_handhold_info(){
  int x, y, type, challenge, strength, location;
  mapping handhold_info;  //([int location: ({int type, int quality});
  string line, challenge_line, strength_line, ch, chall_ch, str_ch;
  handhold_info = ([]);
  for (y = 0; y<sizeof(wall)-1; y++)
  {
    line = handholds[y];
    challenge_line = handhold_challenge[y];
    strength_line = handhold_strength[y];
    for (x = 0; x<strlen(line); x++)
    {
      ch = line[x..x];
      if (ch == " ") continue;
      chall_ch = challenge_line[x..x];
      str_ch = strength_line[x..x];
      type = atoi(ch);
      if (type<1) continue;
      challenge = atoi(chall_ch);
      strength = atoi(str_ch);
      location = y * 10000 + x;
      handhold_info[location] = ({type, challenge, strength});
    }
  }
  return handhold_info;
}

varargs string survey_handholds(string type, object who, int l_x, r_x, l_y, u_y ){
  mapping handhold_info, new_map, climber;
  int x, y, * locations, location, start_location, * positions, left_x, bottom_y;
  handhold_info = query_handhold_info();
  new_map = ([]);
  if (!stringp(type) || type == "") 
  {
    return "This command will give you a text description of the handholds in a section of the wall. Possible options:\n"
                      +"all:       Describes the whole wall (This will be a very large amount of text)\n"
                      +"above:     Describes the section of wall immediately above you\n"
                      +"far above: Describes the section of wall further above you\n"
                      +"left:      Describes the section of wall immediately to your left\n"
                      +"far left:  Describes the section of wall further to your left\n"
                      +"right:     Describes the section of wall immediately to your right\n"
                      +"far right: Describes the section of wall further to your right\n"
                      +"below:     Describes the section of wall immediately below you\n"
                      +"far below: Describes the section of wall further below you\n"
                      +"section:   Describes a defined section of wall. You will need to provide numbers as follows:\n"
                      +"           left limit, right limit, lower limit, upper limit\n"
                      +"           The left and right limits are defined in terms of feet from the left end of the wall\n"
                      +"           Upper and lower limits are defined in terms of feet from the bottom of the wall";
  }                                          
  if (!objectp(who)) return;
  climber = who->query_name();
  positions = query_positions(climber);
  start_location = positions[BODY];
  switch (type)
  {
  case "above":
     left_x = 5;
     report ("Case above. Size of unlimited handhold_info: " + sizeof(handhold_info));
     if (start_location  % 10000< left_x) left_x = start_location % 10000;
     handhold_info = limit_mapping(handhold_info, left_x, start_location % 10000 + 7, start_location/10000 - 2, start_location/10000 - 7 );
     report ("Case above. Size of limited handhold_info: " + sizeof(handhold_info));
     break;
  case "far above":
     left_x = 5;
     if (start_location  % 10000< left_x) left_x = start_location % 10000;
     handhold_info = limit_mapping(handhold_info, left_x, start_location % 10000 + 7, start_location/10000 - 8, start_location/10000 - 15 );
     break;
  case "left":
     left_x = 5;
     report ("Case above. Size of unlimited handhold_info: " + sizeof(handhold_info));
     if (start_location  % 10000< left_x) left_x = start_location % 10000;
     handhold_info = limit_mapping(handhold_info, left_x, start_location % 10000 - 1, start_location/10000 +4, start_location/10000 - 2 );
     report ("Case above. Size of limited handhold_info: " + sizeof(handhold_info));
     break;
  case "far left":
     left_x = 1;
     if (start_location  % 10000 -8 > left_x) left_x = start_location % 10000;
     handhold_info = limit_mapping(handhold_info, left_x, start_location % 10000 - 1, start_location/10000 +4, start_location/10000 - 2 );
     break;
  case "right":
     left_x = 5;
     report ("Case above. Size of unlimited handhold_info: " + sizeof(handhold_info));
     if (start_location  % 10000 +2> left_x ) left_x = start_location % 10000+3;
     handhold_info = limit_mapping(handhold_info, left_x, start_location % 10000 +10, start_location/10000 +4, start_location/10000 - 2 );
     report ("Case above. Size of limited handhold_info: " + sizeof(handhold_info));
     break;
  case "far left":
     left_x = 1;
     if (start_location  % 10000 +9> left_x ) left_x = start_location % 10000+9;
     handhold_info = limit_mapping(handhold_info, left_x, start_location % 10000 +20, start_location/10000 +4, start_location/10000 - 2 );
     break;
  }
  return describe_handholds(handhold_info); 
}

int * order_array (int * arr){
  int * new_array, pos, lowest, h_dir, i, j, * reverse_arr;
  new_array = ({});
  while(sizeof(arr)>0)
  {
    lowest = find_lowest_member(arr);
    new_array += ({lowest});
    pos = member_array(lowest, arr);
    if (sizeof(arr==1))
    {
      arr = ({}); 
      continue;
    }
    if (pos ==0) arr = arr[1..sizeof(arr)-1];
    else 
    {
      if (pos == sizeof(arr)-1) arr = arr[0..sizeof(arr)-2];
      else arr = arr[0..pos-1] + arr[pos +1..sizeof(arr)-1];
    }
  }
  if (new_array[0] % 10000 > new_array[sizeof(new_array)-1] % 10000)
  {
    report("%^BOLD%^%^MAGENTA%^Reversing tail end of array", 12);
    arr = ({});
    foreach(pos in new_array)
    {
      arr += ({pos});
    }
    new_array = ({});
    for (i = 0; i<sizeof(arr);i++)
    {
      if (i<2 || (i < sizeof(arr)-1 && arr[i]/10000 != arr[i+1]/10000 ) || (i == sizeof(arr)-1 && arr[i]/10000 != arr[i-1]/10000)  )
      {
        if (i>0) report("Arr[" + i + "]: " + arr[i] + " arr[" + (i-1) + "]: " + arr[i-1] + " Adding unreversed point " + arr[i] + "of array at point " + i);
        new_array += ({arr[i]});
      } else
      {
        report ("%^B_RED%^Reversing array from point " + i + "current point: " + arr[i] + " previous point: " + arr[i-1], 12);
        reverse_arr = arr[i.. sizeof(arr)-1];
        for (j=sizeof(reverse_arr)-1;j>=0;j--) new_array = new_array + ({reverse_arr[j]});
        break;   
      } 
    }
  } else report("%^BOLD%^%^BLUE%^No need to reverse tail end of array");
  return new_array;
}

int * limit_array(int * arr, int low_x, high_x, low_y, high_y){
  int x, y, val, * result;
  result = ({});
  report ("Limit_array. Size of unlimited array: " + sizeof(arr) + " low_x: " + low_x + " high_x: " + high_x + " low_y: " + low_y + " high_y: " + high_y);
  foreach(val in arr){
    if (val <0) continue;
    x = val % 10000;
    y = val / 10000;
    if (x <low_x || x > high_x || y > low_y || y<high_y) continue;
    result += ({val});
  }
  report ("Limit_array. Size of limited array: " + sizeof(result));
  return result;
}

mapping limit_mapping (mapping m, int low_x, high_x, low_y, high_y){
  mapping result;
  int * ks, k, * filtered;
  report ("Limit_mapping. Size of unlimited mapping: " + sizeof(m));
  result = ([]);
  ks = keys(m);
  filtered = limit_array(ks, low_x, high_x, low_y, high_y);
  foreach(k in ks)
  {
    if (member_array(k, filtered)!=-1) result[k] = m[k];
  } 
  report ("Limit_mapping. Size of limited mapping: " + sizeof(result));
  return result;
}


int find_lowest_member(int * arr){
  int i, n;
  i = 10000000;
  foreach(n in arr)
  {
    if (n<i) i = n;
  }
  return i;
}

string describe_handholds(mapping handhold_info){
  string result, type_name, challenge_name, strength_name, location_name;
  int * locations, location, x, y, type, challenge, strength, * info;
  if (sizeof(handhold_info)<1) return "You do not see any handholds";
  locations = keys(handhold_info);
  locations = order_array(locations);
  result = "";
  report("Survey handholds 2");
  foreach(location in locations)
  {
    y = location / 10000;
    x = location % 10000;
    info = handhold_info[location];
    type = info[0];
    challenge = info[1];
    strength = info[2];
    type_name = get_handhold_name(location);
    challenge_name = get_handhold_description(location); //bleh
    location_name = describe_location_position(location);
    result += location_name + " there is " + type_name + " " + challenge_name + "\n";
  }
  return result;
}

string * query_base_handholds(){
  return base_handholds;
}

void set_base_handholds(string * h){
  base_handholds = h;
}

