// Nienne's area keeper! Let's track area data through resets/reboots! May 2017.
// Currently experimental, to see what interesting things can be done. Potential (hopefully)
// for longterm area settings & allowing players to shift things in-game without imm help;
// longterm/timed spawns, etc.

// For now, setting this up to specify a particular area/header/setting (eg/ areaname)
// and then allow any variables to be set up for that. Area/header/setting will be the
// resulting stored filename.

// Thoughts: for now using mixed to allow for any variable type. Not sure if this opens us
// up to problems in any cases?

#include <security.h>
#include <dirs.h>

mapping area_vars;
nosave string current;

void create() {
    seteuid(getuid());
    current = 0;
    area_vars = ([]);
}

int area_exists(string where) {
    if(file_size(DIR_AREA_VARS+"/"+where+".o") > -1) return 1;
    return 0;
}

mapping query_area(string where) { // pick up all current variables for an area
    object theplayer;
    string *myfactions;

    if(!where) return 0;
    if(current != where) {
	current = where;
	if(area_exists(current)) restore_object(DIR_AREA_VARS+"/"+current);
      else area_vars = ([]);
    }
    if(!area_vars) area_vars = ([]);
    return area_vars;
}

void query_area_variable(string where,string varname) { // pick up a single variable for the area
    string *existingvars;
    if(!where || !varname) return 0;
    if(current != where) {
	current = where;
	if(area_exists(current)) restore_object(DIR_AREA_VARS+"/"+current);
      else area_vars = ([]);
    }
    if(!area_vars) area_vars = ([]);
    if(!area_vars[varname]) return 0;
    return area_vars[varname];
}

void reset_area(string where) { // wipes all variables. Probably not used much.
    if(!where) return 0;
    if(current != where) {
	current = where;
	if(area_exists(current)) restore_object(DIR_AREA_VARS+"/"+current);
      else area_vars = ([]);
    }
    area_vars = ([]);
    save_object(DIR_AREA_VARS+"/"+current);
}

void reset_area_variable(string where,string varname) {
    string *existingvars;
    if(!where || !varname) return 0;
    if(current != where) {
	current = where;
	if(area_exists(current)) restore_object(DIR_AREA_VARS+"/"+current);
      else area_vars = ([]);
    }
    if(!area_vars) area_vars = ([]);
    existingvars = keys(area_vars);
    if(member_array(existingvars,varname) == -1) return;
    map_delete(area_vars,varname);
    save_object(DIR_AREA_VARS+"/"+current);
}

int set_area_variable(string where,string varname,mixed value) { // sets the variable to a specified value of any type
    if(!where || !varname || !value) return 0;
    if(current != where) {
	current = where;
	if(area_exists(current)) restore_object(DIR_AREA_VARS+"/"+current);
      else area_vars = ([]);
    }
    if(!area_vars) area_vars = ([]);
    area_vars[varname] = value;
    save_object(DIR_AREA_VARS+"/"+current);
    return 1;
}
