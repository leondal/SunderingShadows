#include <std.h>
#include <security.h>
#include <terrain.h>

private string terrain;
private string travel;
private int travel_penalty;
private int travel_penalty_multiplier;
private int stamina_penalty;

private string get_default_travel();
private string get_default_terrain();

private int get_default_travel_penalty();
private int get_default_travel_penalty_multiplier();
private int get_default_stamina_penalty();

void set_terrain(string t){
    if(!isTerrain(t)) {
        error("Invalid Terrain type");
    }
    terrain = t;
}

void set_travel(string t){
    if(!isTravel(t)) {
        error("Invalid Terrain type");
    }
    travel = t;
}

// Pator@ShadowGate 29/7/03
void set_travel_penalty(string t){
	t = lower_case(t);
	if(!isTerrainPenalty(t)) {
		error("Invalid Terrain Penalty type");
    }
    travel_penalty = (int)TRAVEL_PENALTY[t];
}

// Pator@ShadowGate 29/7/03
void set_travel_penalty_multiplier(string t){
	t = lower_case(t);
	if(!isTerrainPenaltyMultiplier(t)) {
		error("Invalid Terrain Penalty Multiplier type");
    }
    travel_penalty_multiplier = (int)TRAVEL_PENALTY_MULTIPLIER[t];
}

// Pator@ShadowGate 29/7/03
void set_stamina_penalty(){
	if(!DEFAULT_STAMINA_PENALTY) {
		error("Invalid Stamina Penalty type");
    }
    travel_penalty = DEFAULT_STAMINA_PENALTY;
}

string get_terrain(){
    if(TO->query_property("indoors")) {
        if(!isInside(terrain)) {
            error("Terrain does not match indoor property");
        }
    } else {
        if(!isOutside(terrain)){
            error("Terrain does not match indoor property");
        }
    }
    return terrain;
}

string get_travel(){
    if(!travel) return get_default_travel();
    return travel;
}

// Pator@ShadowGate 29/7/03
int get_travel_penalty(){
	if(!travel_penalty) return get_default_travel_penalty();
    return travel_penalty;
}

// Pator@ShadowGate 29/7/03
int get_travel_penalty_multiplier(){
	if(!travel_penalty) return get_default_travel_penalty_multiplier();
    return travel_penalty_multiplier;
}

// Pator@ShadowGate 29/7/03
int get_stamina_penalty(){
	if(!stamina_penalty) return get_default_stamina_penalty();
    return stamina_penalty;
}

private string get_default_travel(){
    return FOOT_PATH;
}

private string get_default_terrain(){
    return "unknown";
}

// Pator@ShadowGate 29/7/03
private int get_default_travel_penalty(){
    return 50;
}

// Pator@ShadowGate 29/7/03
private int get_default_travel_penalty_multiplier(){
    return TRAVEL_PENALTY_MULTIPLIER[DEFAULT_PENALTY_MULTIPLIER];
}

// Pator@ShadowGate 29/7/03
private int get_default_stamina_penalty(){
    return 2;
}

string query_terrain(){
  string * elements, who;
  if(TO->query_property("indoors")) {
    if(!isInside(terrain)) {
      elements = explode(base_name(TO), "/");
      if(elements[0] == "realms") who = elements[1];    
      else if(elements[0] == "d") who = elements[1];
      else who = 0;
      seteuid(UID_LOG);
      log_file("errors/terrain", "Terrain error in: "+base_name(TO)+" "+ctime(time())+
	       " Mismatch: Outdoor terrain, but indoor property set.\n");
      if(who) log_file("reports/"+who, "Travel error in "+ base_name(TO)+"\n");
      seteuid(getuid());
      return get_default_terrain();
      //error("Terrain does not match indoor property");
    }
  } else {
    if(!isOutside(terrain)){
      elements = explode(base_name(TO), "/");
      if(elements[0] == "realms") who = elements[1];    
      else if(elements[0] == "d") who = elements[1];
      else who = 0;
      seteuid(UID_LOG);
      log_file("errors/terrain", "Terrain error in: "+base_name(TO)+" "+ctime(time())+
	       " Mismatch: Indoor terrain, but outdoor room property.\n");
      if(who) log_file("reports/"+who, "Terrain error in "+base_name(TO)+
		       " Mismatch: Outdoor terrain, but indoor property.\n");
      seteuid(getuid());
      return get_default_terrain();
      // error("Terrain does not match indoor property");
    }
  }
  return terrain;
}


string query_travel(){
  string who, *elements;
  if(!travel) {
    elements = explode(base_name(TO), "/");
    if(elements[0] == "realms") who = elements[1];    
    else if(elements[0] == "d") who = elements[1];
    else who = 0;
    seteuid(UID_LOG);
    log_file("errors/travel", "Terrain error in: "+base_name(TO)+" "+ctime(time())+"\n");
    if(who) log_file("reports/"+who, "Travel error in "+ base_name(TO)+"\n");
    seteuid(getuid());
    return get_default_travel();
    }
  return travel;
}

// Pator@ShadowGate 29/7/03
string query_travel_penalty(){
  string who, *elements;
  if(!travel) {
    elements = explode(base_name(TO), "/");
    if(elements[0] == "realms") who = elements[1];    
    else if(elements[0] == "d") who = elements[1];
    else who = 0;
    seteuid(UID_LOG);
    log_file("errors/travel", "Terrain error in: "+base_name(TO)+" "+ctime(time())+"\n");
    if(who) log_file("reports/"+who, "Travel Penalty error in "+ base_name(TO)+"\n");
    seteuid(getuid());
    return get_default_travel_penalty();
    }
  return travel_penalty;
}

// Pator@ShadowGate 29/7/03
string query_travel_penalty_multiplier(){
  string who, *elements;
  if(!travel) {
    elements = explode(base_name(TO), "/");
    if(elements[0] == "realms") who = elements[1];    
    else if(elements[0] == "d") who = elements[1];
    else who = 0;
    seteuid(UID_LOG);
    log_file("errors/travel", "Terrain error in: "+base_name(TO)+" "+ctime(time())+"\n");
    if(who) log_file("reports/"+who, "Travel Penalty error in "+ base_name(TO)+"\n");
    seteuid(getuid());
    return get_default_travel_penalty();
    }
  return travel_penalty_multiplier;
}

// Pator@ShadowGate 29/7/03
int query_stamina_usage(){
	int penalty, multiplier, staminap;
	
return 1;
/*
	penalty 	= 	get_travel_penalty();
	multiplier	=	get_travel_penalty_multiplier();
	staminap	=	get_stamina_penalty();
	
	// Generate a random penalty 
	return (to_int( to_float(random((100+penalty) * multiplier)/ 100) ) * staminap) + 1;
*/
}
